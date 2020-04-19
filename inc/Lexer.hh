//
// Lexer.hh for Lexer.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 11:44:22 2014 CHAUCHET Alan
// Last update Sat Apr 26 15:37:29 2014 CHAUCHET Alan
//

#ifndef				LEXER_HH_
# define			LEXER_HH_

# include			<string>
# include			<vector>
# include			<stdexcept>
# include			<sstream>

class				Lexer
{
  std::string			_line;
  std::vector<std::string>	_grammar;

public:
  Lexer();
  void				setLine(const std::string &);
  const std::string		&getLine(void) const;
  void				cleanLine(void);
  bool				isNb(const std::string &) const;
  bool				isCorrect(const std::string &) const;
  bool				checkGrammar(void) const;
  bool				checkLine(const std::string &);
};

class				LexerError : public std::invalid_argument
{
  std::string           _msg;

public:
  LexerError(const std::string &);
  virtual ~LexerError() throw();
  virtual const char    *what() const throw();
};

#endif
