//
// MyPerror.hh for MyPerror.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sun Apr 27 20:34:37 2014 CHAUCHET Alan
// Last update Sun Apr 27 20:39:11 2014 CHAUCHET Alan
//

#ifndef			MYPERROR_HH_
# define		MYPERROR_HH_

# include		<string>
# include		<stdexcept>
# include		<sstream>

class			MyPerror : public std::runtime_error
{
  std::string           _msg;

public:
  MyPerror(const std::string &);
  virtual ~MyPerror() throw();
  virtual const char    *what() const throw();
};

#endif
