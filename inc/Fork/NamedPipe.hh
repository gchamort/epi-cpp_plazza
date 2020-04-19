//
// NamedPipe.hh for NamedPipe.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 19:27:11 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:41:26 2014 CHAUCHET Alan
//

#ifndef			NAMEDPIPE_HH_
# define		NAMEDPIPE_HH_

# include		<unistd.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		<stdio.h>
# include		"ANamedPipe.hh"

class			NamedPipe : public ANamedPipe
{
public:
  NamedPipe(const std::string &, bool);
  virtual ~NamedPipe();
  virtual void		openPipeR(void);
  virtual void		openPipeW(void);
  virtual void		createPipes(void);
  virtual void		createOpt(void) const;
  virtual void		close(void);
  virtual void		del() const;
};

#endif
