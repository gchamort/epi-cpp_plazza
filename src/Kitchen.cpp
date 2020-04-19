//
// Kitchen.cpp for Kitchen.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 20:29:31 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:29:12 2014 CHAUCHET Alan
//

#include			"Kitchen.hh"

static t_funcKitchen		g_funcKitchen[4] =
  {
    {PIZZA_CMD, &Kitchen::addPizza},
    {IS_FULL, &Kitchen::cmdIsFull},
    {ASK_QUIT, &Kitchen::stopKitchen},
    {ASK_INFO, &Kitchen::affInfo}
  };

Kitchen::Kitchen(const std::string &name, AMutex *mutexCout): _name(name), _stop(false), _reception(new NamedPipe(name, false))
{
  this->_cond = new Cond();
  this->_cond->create();
  this->_mutex = new Mutex();
  this->_mutex->create();
  this->_nbCooks = OptVal::getCooksPerKitchen();
  for (unsigned int count = 0; count < static_cast<unsigned int>(this->_nbCooks); count++)
    this->_cooks.push_back(new Cook(this));
  this->_cout = mutexCout;
  this->_cout->lock();
  std::cout << "Kitchen [" << name << "] just opened" << std::endl;
  this->_cout->unlock();
}

Kitchen::~Kitchen()
{
  while (this->_listPizza.size())
    delete(this->_listPizza[this->_listPizza.size() - 1]);
  delete(this->_cond);
  delete(this->_mutex);
  delete(this->_reception);
  while (this->_cooks.size())
    delete(this->_cooks[this->_cooks.size() - 1]);
}

const std::string		Kitchen::getTextMsg(e_kitchen_type type) const
{
  return (FunctionString::varToString<int>(static_cast<int>(type)));
}

void				Kitchen::addPizza(const std::string &pizza)
{
  std::vector<std::string>	info = FunctionString::stringToVector(pizza);
  TypePizza			type;
  TaillePizza			size;

  if (info.size() != 3)
    return ;
  type = static_cast<TypePizza>(FunctionString::stringToVar<int>(info[1]));
  size = static_cast<TaillePizza>(FunctionString::stringToVar<int>(info[2]));
  this->_mutex->lock();
  this->_listPizza.push_back(Factory::createPizza(type, size));
  this->_mutex->unlock();
  this->_cond->signal();
  this->_cout->lock();
  std::cout << "Kitchen [" << this->_name << "] received a new Pizza to do" << std::endl;
  this->_cout->unlock();
}

void				Kitchen::cmdIsFull(const std::string &line)
{
  static_cast<void>(line);
  if (this->isFull())
    (*(this->_reception)) << this->getTextMsg(YES);
  else
    (*(this->_reception)) << this->getTextMsg(NO);
}


void				Kitchen::stopKitchen(const std::string &line)
{
  static_cast<void>(line);
  this->_stop = true;
  (*(this->_reception)) << this->getTextMsg(KITCHEN_EXIT);
}

void				Kitchen::affInfo(const std::string &line)
{
  static_cast<void>(line);
  this->_cout->lock();
  this->_mutex->lock();
  std::cout << "Kitchen nb° [" << this->_name << "] :" << std::endl;
  std::cout << "There are [" << this->_listPizza.size() << "] currently waiting to be done" << std::endl;
  std::cout << this->getCooksWorking() << " cooks are currently working" << std::endl;
  this->_mutex->unlock();
  std::cout << "IngrBox =" << std::endl;
  this->_box.info();
  this->_cout->unlock();
}

bool				Kitchen::takePizza(IPizza *&pizza)
{
  this->_mutex->lock();
  if (!this->_listPizza.size())
    {
      this->_mutex->unlock();
      return (false);
    }
  pizza = this->_listPizza[0];
  this->_listPizza.erase(this->_listPizza.begin());
  this->_mutex->unlock();
  return (true);
}

void				Kitchen::runKitchen(void)
{
  try
    {
      this->_reception->createOpt();
      this->_reception->createPipes();
    }
  catch (const std::runtime_error &err)
    {
      std::cerr << err.what() << std::endl;
      this->_stop = true;
    }
  this->_select.addFd(this->_reception->getFdFileR());
  try
    {
      this->_box.launch_thread();
      for (unsigned int count = 0; static_cast<int>(count) < this->_nbCooks; count++)
	this->_cooks[count]->launch_thread();
    }
  catch (const std::runtime_error &err)
    {
      std::cerr << err.what() << std::endl;
      this->_stop = true;
    }
  while (!this->_stop && !this->isStop())
    {
      if (this->_select.select(5) == -1)
	{
	  std::cerr << "Kitchen: Select failed" << std::endl;
	  perror(NULL);
	  this->_stop = true;
	}
      if (this->_select.isSet(this->_reception->getFdFileR()))
	{
	  (*(this->_reception)) >> this->_text;
	  this->handleCmd(FunctionString::stringToVector(this->_text));
	}
    }
  this->stopCooks();
  this->_box.stopProg();
  this->stopKitchen("");
  this->_cout->lock();
  std::cout << "Kitchen nb° [" << this->_name << "] is now closed" << std::endl;
  this->_cout->unlock();
}

void				Kitchen::handleCmd(const std::vector<std::string> &words)
{
  if (!words.size())
    return ;
  for (unsigned int count = 0; count < 4; count++)
    if (FunctionString::varToString<int>(static_cast<int>(g_funcKitchen[count].type)) == words[0])
      {
	(this->*(g_funcKitchen[count].func))(this->_text);
	return ;
      }
}

int				Kitchen::waitNewPizza(int sec) const
{
  return (this->_cond->waitTimer(sec));
}

IngrBox				&Kitchen::getBox(void)
{
  return (this->_box);
}

bool				Kitchen::isFull(void) const
{
  int				nbAtWork = 0;

  for (unsigned int count = 0; static_cast<int>(count) < this->_nbCooks; count++)
    {
      this->_cooks[count]->lock();
      if (this->_cooks[count]->getIsCooking())
	nbAtWork++;
      this->_cooks[count]->unlock();
    }
  if (nbAtWork + this->_listPizza.size() >= (static_cast<unsigned int>(2 * this->_nbCooks)))
    return (true);
  return (false);
}

bool				Kitchen::isStop(void)
{
  for (unsigned int count = 0; static_cast<int>(count) < this->_nbCooks; count++)
    {
      this->_cooks[count]->lock();
      if (this->_cooks[count]->getIsWorking())
	{
	  this->_cooks[count]->unlock();
	  return (false);
	}
      this->_cooks[count]->unlock();
    }
  this->_stop = true;
  return (true);
}

void				Kitchen::stopCooks(void) const
{
  for (unsigned int count = 0; static_cast<int>(count) < this->_nbCooks; count++)
    {
      this->_cooks[count]->lock();
      this->_cooks[count]->stopCook();
      this->_cooks[count]->unlock();
    }
}

int				Kitchen::getCooksWorking(void) const
{
  int				nbAtWork = 0;

  for (unsigned int count = 0; static_cast<int>(count) < this->_nbCooks; count++)
    {
      this->_cooks[count]->lock();
      if (this->_cooks[count]->getIsCooking())
	nbAtWork++;
      this->_cooks[count]->unlock();
    }
  return (nbAtWork);
}

const std::string		Kitchen::getSize(TaillePizza size) const
{
  if (size == S)
    return ("S");
  if (size == M)
    return ("M");
  if (size == L)
    return ("L");
  if (size == XL)
    return ("XL");
  if (size == XXL)
    return ("XXL");
  return ("");
}

void				Kitchen::affPizza(IPizza *pizza) const
{
  TaillePizza			size = pizza->getSize();

  this->_cout->lock();
  std::cout << "Pizza: [" << pizza->getName() << "] [" << this->getSize(size) << "] prepared." << std::endl;
  this->_cout->unlock();
}

bool				Kitchen::getStop(void) const
{
  return (this->_stop);
}

ACond				*Kitchen::getCond(void)
{
  return (this->_cond);
}
