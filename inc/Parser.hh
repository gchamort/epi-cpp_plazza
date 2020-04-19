//
// Parser.hh for Parser.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 15:38:10 2014 CHAUCHET Alan
// Last update Sat Apr 26 17:25:29 2014 CHAUCHET Alan
//

#ifndef						PARSER_HH_
# define					PARSER_HH_

# include					<iostream>
# include					<vector>
# include					<stdexcept>
# include					<sstream>
# include					"FunctionString.hpp"
# include					"Pizza/IPizza.hh"

class						Parser
{
  std::string					_line;
  std::vector<std::string>			_toWord;
  std::vector<std::string>			_pizza;
  std::vector<std::string>			_size;
  std::vector<int>				_pizzaNb;
  std::vector<int>				_sizeNb;
  std::vector<std::vector<std::string> >	_cmdUnpacked;
  std::vector<std::string>			_cmdPacked;

public:
  Parser();
  void						setLine(const std::string &);
  const std::string				&getLine(void) const;
  bool						isPizza(const std::string &) const;
  bool						isSize(const std::string &) const;
  bool						isNb(const std::string &, int &) const;
  void						lineToWord(void);
  bool						checkWords(void) const;
  bool						parseLine(const std::string &);
  bool						packLine(const std::string &);
  std::vector<std::string>			pack(const std::string &);
  std::vector<std::string>			pack(const std::vector<std::string> &);
  int						getPizzaNb(const std::string &) const;
  int						getSizeNb(const std::string &) const;
  const std::string				&getPizza(const std::string &) const;
  const std::string				&getSize(const std::string &) const;
  std::string					unpack(const std::string &) const;
};

class						ParserError : public std::invalid_argument
{
  std::string					_msg;

public:
  ParserError(const std::string &);
  virtual ~ParserError() throw();
  virtual const char				*what() const throw();
};

#endif
