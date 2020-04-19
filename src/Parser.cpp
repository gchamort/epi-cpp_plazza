//
// Parser.cpp for Parser.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 15:38:14 2014 CHAUCHET Alan
// Last update Sat Apr 26 20:28:42 2014 CHAUCHET Alan
//

#include		"Parser.hh"

Parser::Parser()
{
  this->_pizza.push_back("regina");
  this->_pizza.push_back("fantasia");
  this->_pizza.push_back("margarita");
  this->_pizza.push_back("americana");
  this->_pizzaNb.push_back(static_cast<int>(REGINA));
  this->_pizzaNb.push_back(static_cast<int>(FANTASIA));
  this->_pizzaNb.push_back(static_cast<int>(MARGARITA));
  this->_pizzaNb.push_back(static_cast<int>(AMERICAINE));
  this->_size.push_back("S");
  this->_size.push_back("M");
  this->_size.push_back("L");
  this->_size.push_back("XL");
  this->_size.push_back("XXL");
  this->_sizeNb.push_back(static_cast<int>(S));
  this->_sizeNb.push_back(static_cast<int>(M));
  this->_sizeNb.push_back(static_cast<int>(L));
  this->_sizeNb.push_back(static_cast<int>(XL));
  this->_sizeNb.push_back(static_cast<int>(XXL));
}

void			Parser::setLine(const std::string &line)
{
  this->_line = line;
}

const std::string	&Parser::getLine(void) const
{
  return (this->_line);
}

bool			Parser::isPizza(const std::string &word) const
{
  for (unsigned int count = 0; count < this->_pizza.size(); count++)
    if (word == this->_pizza[count])
      return (true);
  return (false);
}

bool			Parser::isSize(const std::string &word) const
{
  for (unsigned int count = 0; count < this->_size.size(); count++)
    if (word == this->_size[count])
      return (true);
  return (false);
}

bool			Parser::isNb(const std::string &word, int &nb) const
{

  if (word[0] != 'x')
    return (false);
  nb = FunctionString::stringToVar<int>(word.substr(1, word.size() - 1));
  return (true);
}

void			Parser::lineToWord(void)
{
  this->_toWord = FunctionString::stringToVector(this->_line);
}

bool			Parser::checkWords(void) const
{
  int			nb;

  for (unsigned int count = 0; count < this->_toWord.size(); count++)
    {
      if (this->isPizza(this->_toWord[count]) &&
	  ((count != 0 && count % 4 != 0) ||
	   (count == this->_toWord.size() - 1 || this->_toWord[count + 1] == ";")))
	throw ParserError("Badly placed pizza '"+this->_toWord[count]+"'");
      if (this->isSize(this->_toWord[count]) &&
	  ((count != 1 && count % 4 != 1) ||
	   (count == this->_toWord.size() - 1 || this->_toWord[count + 1] == ";")))
	throw ParserError("Badly placed size '"+this->_toWord[count]+"'");
      if (this->isNb(this->_toWord[count], nb))
	{
	  if (count != 2 && count % 4 != 2)
	    throw ParserError("Badly placed size '"+this->_toWord[count]+"'");
	  if (nb < 1)
	    throw ParserError("Bad number of pizza: '"+this->_toWord[count]+"'");
	}
      else if (this->_toWord[count] == ";" && ((count != 3 && count % 4 != 3) || count == this->_toWord.size() - 1))
	throw ParserError("Badly placed separator ';'");
    }
  return (true);
}

bool			Parser::parseLine(const std::string &line)
{
  this->setLine(line);
  this->lineToWord();
  try
    {
      this->checkWords();
    }
  catch (const std::invalid_argument &err)
    {
      std::cerr << err.what() << std::endl;
      return (false);
    }
  return (true);
}

bool			Parser::packLine(const std::string &line)
{
  std::vector<std::string>	list;

  if (!this->parseLine(line))
    return (false);
  for (unsigned int count = 0; count < this->_toWord.size(); count++)
    {
      if (this->_toWord[count] == ";")
	{
	  this->_cmdUnpacked.push_back(list);
	  list.clear();
	}
      else
	list.push_back(this->_toWord[count]);
    }
  this->_cmdUnpacked.push_back(list);
  for (unsigned int count2 = 0; count2 < this->_cmdUnpacked.size(); count2++)
    this->pack(this->_cmdUnpacked[count2]);
  return (true);
}

int				Parser::getPizzaNb(const std::string &pizza) const
{
  for (unsigned int count = 0; count < this->_pizza.size(); count++)
    if (this->_pizza[count] == pizza)
      return (this->_pizzaNb[count]);
  return (1);
}

int				Parser::getSizeNb(const std::string &size) const
{
  for (unsigned int count = 0; count < this->_size.size(); count++)
    if (this->_size[count] == size)
      return (this->_sizeNb[count]);
  return (1);
}

std::vector<std::string>	Parser::pack(const std::vector<std::string> &line)
{
  int			nb;
  std::string		str;

  this->isNb(line[2], nb);
  str += FunctionString::varToString<int>(this->getPizzaNb(line[0]));
  str += " ";
  str += FunctionString::varToString<int>(this->getSizeNb(line[1]));
  while (nb > 0)
    {
      this->_cmdPacked.push_back(str);
      nb--;
    }
  return (this->_cmdPacked);
}

std::vector<std::string>	Parser::pack(const std::string &line)
{
  this->_cmdPacked.clear();
  this->_cmdUnpacked.clear();
  this->_toWord.clear();
  this->packLine(line);
  return (this->_cmdPacked);
}

const std::string		&Parser::getPizza(const std::string &pizza) const
{
  for (unsigned int count = 0; count < this->_pizza.size(); count++)
    if (FunctionString::varToString<int>(this->_pizzaNb[count]) == pizza)
      return (this->_pizza[count]);
  return (this->_pizza[0]);
}

const std::string		&Parser::getSize(const std::string &size) const
{
  for (unsigned int count = 0; count < this->_size.size(); count++)
    if (FunctionString::varToString<int>(this->_sizeNb[count]) == size)
      return (this->_size[count]);
  return (this->_size[0]);
}

std::string			Parser::unpack(const std::string &line) const
{
  std::vector<std::string>	listW = FunctionString::stringToVector(line);

  return (this->getPizza(listW[0]) + " " + this->getSize(listW[1]));
}

ParserError::ParserError(const std::string &msg) : std::invalid_argument(msg)
{
  std::ostringstream	oss;

  oss << "Syntax error: " << msg;
  this->_msg = oss.str();
}

ParserError::~ParserError() throw() {}

const char			*ParserError::what() const throw()
{
  return (this->_msg.c_str());
}
