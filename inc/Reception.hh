//
// Reception.hh for Reception.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 17:47:14 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:30:51 2014 CHAUCHET Alan
//

#ifndef					RECEPTION_HH_
# define				RECEPTION_HH_

# include				<iostream>
# include				<vector>
# include				<unistd.h>
# include				"Fork/Process.hh"
# include				"Fork/NamedPipe.hh"
# include				"Fork/Select.hh"
# include				"Thread/Mutex.hh"
# include				"Lexer.hh"
# include				"Parser.hh"
# include				"FunctionString.hpp"
# include				"Kitchen.hh"

class					Reception
{
  std::vector<AProcess *>		_processList;
  std::vector<ANamedPipe *>		_namedPipeList;
  Select				_select;
  Lexer					_lexer;
  Parser				_parser;
  bool					_isStop;
  int					_nbKitchen;
  std::string				_line;
  std::vector<std::string>		_packCmd;
  AMutex				*_cout;

public:
  Reception();
  ~Reception();
  void					openReception(void);
  void					openKitchen(void);
  void					closeKitchen(int);
  void					recupCmd(void);
  void					checkOnKitchen(void);
  void					kitchenCmd(const std::vector<std::string> &, int);
  bool					distribPizza(const std::string &) const;
  void					askInfo(void) const;
};

#endif
