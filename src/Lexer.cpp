//
// Lexer.cpp for Lexer.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 11:44:22 2014 CHAUCHET Alan
// Last update Sat Apr 26 16:17:12 2014 CHAUCHET Alan
//

#include			<iostream>
#include			"Lexer.hh"
#include			"FunctionString.hpp"

Lexer::Lexer()
{
  this->_grammar.push_back("regina");
  this->_grammar.push_back("fantasia");
  this->_grammar.push_back("margarita");
  this->_grammar.push_back("americana");
  this->_grammar.push_back("S");
  this->_grammar.push_back("M");
  this->_grammar.push_back("L");
  this->_grammar.push_back("XL");
  this->_grammar.push_back("XXL");
  this->_grammar.push_back(";");
}

void				Lexer::setLine(const std::string &newLine)
{
  this->_line = newLine;
}

const std::string		&Lexer::getLine(void) const
{
  return (this->_line);
}

void				Lexer::cleanLine(void)
{
  unsigned int		count;

  for (count = 0; count < this->_line.size(); count++)
    if (this->_line[count] == '\t')
      this->_line[count] = ' ';
  while (this->_line.size() && this->_line[0] == ' ')
    this->_line.erase(0, 1);
  while (this->_line.size() && this->_line[this->_line.size() - 1] == ' ')
    this->_line.erase(this->_line.size() - 1, 1);
  count = 0;
  while (count < this->_line.size())
    {
      if (this->_line[count] == ' ' && this->_line[count + 1] == ' ')
	this->_line.erase(count + 1, 1);
      else
	count++;
    }
  count = 0;
  while (count < this->_line.size())
    {
      if (this->_line[count] == ';')
	{
	  if (count > 0 && this->_line[count - 1] != ' ')
	    {
	      this->_line.insert(count, " ");
	      count++;
	    }
	  if (count < this->_line.size() - 1 && this->_line[count + 1] != ' ')
	    this->_line.insert(count + 1, " ");
	}
      count++;
    }
}

bool				Lexer::isNb(const std::string &word) const
{
  unsigned int			count = 1;

  if (word.size() < 2 || word[0] != 'x')
    return (false);
  while (count < word.size())
    {
      if (!(word[count] >= '0' && word[count] <= '9'))
	return (false);
      count++;
    }
  return (true);
}

bool				Lexer::isCorrect(const std::string &word) const
{
  for (unsigned int count = 0; count < this->_grammar.size(); count++)
    if (this->_grammar[count] == word)
      return (true);
  return (this->isNb(word));
}

bool				Lexer::checkGrammar(void) const
{
  unsigned int			count;
  std::vector<std::string>	wordTab;

  wordTab = FunctionString::stringToVector(this->_line);
  count = 0;
  while (count < wordTab.size())
    {
      if (!this->isCorrect(wordTab[count]))
	throw LexerError("unknown word '"+wordTab[count]+"'");
      count++;
    }
  return (true);
}

bool				Lexer::checkLine(const std::string &line)
{
  this->setLine(line);
  this->cleanLine();
  try
    {
      this->checkGrammar();
    }
  catch (const std::invalid_argument &err)
    {
      std::cerr << err.what() << std::endl;
      return (false);
    }
  return (true);
}

LexerError::LexerError(const std::string &msg) : std::invalid_argument(msg)
{
  std::ostringstream	oss;

  oss << "Lexical error: " << msg;
  this->_msg = oss.str();
}

LexerError::~LexerError() throw() {}

const char			*LexerError::what() const throw()
{
  return (this->_msg.c_str());
}
