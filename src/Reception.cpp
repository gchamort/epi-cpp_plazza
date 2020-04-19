//
// Reception.cpp for Reception.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 17:47:14 2014 CHAUCHET Alan
// Last update Sun Apr 27 23:14:20 2014 CHAUCHET Alan
//

#include			<unistd.h>
#include			"Reception.hh"

Reception::Reception()
{
  this->_isStop = false;
  this->_nbKitchen = 0;
  this->_cout = new Mutex();
  this->_cout->create();
}

Reception::~Reception()
{
  while (this->_processList.size())
    {
      delete(this->_processList[this->_processList.size() - 1]);
      this->_processList.pop_back();
    }
  while (this->_namedPipeList.size())
    {
      delete(this->_namedPipeList[this->_namedPipeList.size() - 1]);
      this->_namedPipeList.pop_back();
    }
}

void		Reception::recupCmd(void)
{
  std::getline(std::cin, this->_line);
}

void			Reception::openReception(void)
{
  std::string		line;

  this->_select.addFd(0);
  while (!this->_isStop)
    {
      if (this->_select.select() == -1)
	{
	  std::cerr << "Reception: Select failed" << std::endl;
	  perror(NULL);
	  this->_isStop = true;
	}
      if (!this->_isStop)
	this->checkOnKitchen();
      if (!this->_isStop && this->_select.isSet(0))
	{
	  this->recupCmd();
	  if (this->_line.size() == 0 || this->_line == "quit")
	    this->_isStop = true;
	  else if (this->_line == "info")
	    this->askInfo();
	  else if (this->_lexer.checkLine(this->_line))
	    {
	      this->_packCmd = this->_parser.pack(this->_lexer.getLine());
	      while (!this->_isStop && this->_packCmd.size())
		{
		  if (this->distribPizza(this->_packCmd[this->_packCmd.size() - 1]))
		    this->_packCmd.pop_back();
		  else
		    this->openKitchen();
		  usleep(500);
		}
	    }
	}
    }
  for (unsigned int count = 0; count < this->_namedPipeList.size(); count++)
    {
      (*(this->_namedPipeList[count])) << FunctionString::varToString<int>(static_cast<int>(ASK_QUIT));
      this->closeKitchen(count);
    }
  std::cout << "Closing reception" << std::endl;
}

void			Reception::askInfo(void) const
{
  for (unsigned int count = 0; count < this->_namedPipeList.size(); count++)
    (*(this->_namedPipeList[count])) << FunctionString::varToString<int>(static_cast<int>(ASK_INFO));
}

bool			Reception::distribPizza(const std::string &pizza) const
{
  std::string		answer;
  std::vector<std::string>	line;

  for (unsigned int count = 0; count < this->_namedPipeList.size(); count++)
    {
      (*(this->_namedPipeList[count])) << FunctionString::varToString<int>(static_cast<int>(IS_FULL));
      (*(this->_namedPipeList[count])) >> answer;
      line = FunctionString::stringToVector(answer);
      if (line.size() && line[0] == FunctionString::varToString<int>(static_cast<int>(NO)))
	{
	  (*(this->_namedPipeList[count])) <<
	    (FunctionString::varToString<int>(static_cast<int>(PIZZA_CMD)) + " " + pizza);
	  return (true);
	}
   }
  return (false);
}

void			Reception::kitchenCmd(const std::vector<std::string> &line, int kitchenId)
{
  if (!line.size())
    return ;
  if (line[0] == FunctionString::varToString<int>(static_cast<int>(KITCHEN_EXIT)))
    this->closeKitchen(kitchenId);
}

void			Reception::checkOnKitchen(void)
{
  std::string		textKitchen;

  for (unsigned int count = 0; count < this->_namedPipeList.size(); count++)
    if (this->_select.isSet(this->_namedPipeList[count]->getFdFileR()))
      {
	(*(this->_namedPipeList[count])) >> textKitchen;
	this->kitchenCmd(FunctionString::stringToVector(textKitchen), count);
      }
}

void			Reception::openKitchen(void)
{
  int			id;

  this->_processList.push_back(new Process());
  try
    {
      id = this->_processList[this->_processList.size() - 1]->createProcess();
    }
  catch (const std::runtime_error &err)
    {
      std::cerr << err.what() << std::endl;
      this->_isStop = true;
      return ;
    }
  if (id == 0)
    {
      Kitchen		newKitchen(FunctionString::varToString<int>(this->_nbKitchen + 1), this->_cout);
      newKitchen.runKitchen();
      this->_processList[this->_processList.size() - 1]->exitProcess(0);
    }
  else
    {
      this->_namedPipeList.push_back(new NamedPipe(FunctionString::varToString<int>(this->_nbKitchen + 1), true));
      usleep(5000);
      try
	{
	  this->_namedPipeList[this->_namedPipeList.size() - 1]->createPipes();
	}
      catch (const std::runtime_error &err)
	{
	  std::cerr << err.what() << std::endl;
	  this->_isStop = true;
	  return ;
	}
      this->_select.addFd(this->_namedPipeList[this->_namedPipeList.size() - 1]->getFdFileR());
      this->_nbKitchen++;
    }
}

void			Reception::closeKitchen(int kitchenId)
{
  this->_select.rmFd(this->_namedPipeList[kitchenId]->getFdFileR());
  this->_namedPipeList[kitchenId]->close();
  this->_namedPipeList[kitchenId]->del();
  delete(this->_namedPipeList[kitchenId]);
  this->_namedPipeList.erase(this->_namedPipeList.begin() + kitchenId);
  this->_processList[kitchenId]->waitProcess();
  delete(this->_processList[kitchenId]);
  this->_processList.erase(this->_processList.begin() + kitchenId);
  this->_nbKitchen--;
}
