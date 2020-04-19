//
// ANamedPipe.hh for ANamedPipe.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 17:51:50 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:41:31 2014 CHAUCHET Alan
//

#ifndef				ANAMEDPIPE_HH_
# define			ANAMEDPIPE_HH_

# include			<iostream>
# include			<fstream>
# include			<vector>
# include			<unistd.h>

class				ANamedPipe
{
protected:
  std::string			_name;
  bool				_isLeft;
  int				_fdFileR;
  int				_fdFileW;
  std::string			_txt;

public:
  ANamedPipe(const std::string &, bool);
  virtual ~ANamedPipe();
  virtual void				openPipeR(void) = 0;
  virtual void				openPipeW(void) = 0;
  virtual void				createPipes(void) = 0;
  virtual void				createOpt(void) const = 0;
  virtual void				close(void) = 0;
  virtual void				writeInPipe(const std::string &) const;
  virtual const std::string		&readOnPipe();
  virtual std::string			&operator>>(std::string &);
  virtual void				operator<<(const std::string &) const;
  virtual int				getFdFileR(void) const;
  virtual int				getFdFileW(void) const;
  virtual void				del() const = 0;
};

#endif
