//
// Process.hh for Process.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 10:55:26 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:42:56 2014 CHAUCHET Alan
//

#ifndef			PROCESS_HH_
# define		PROCESS_HH_

# include		<unistd.h>
# include		<sys/types.h>
# include		<sys/wait.h>
# include		<stdlib.h>
# include		"AProcess.hh"

class			Process : public AProcess
{
public:
  virtual ~Process() {}
  virtual int		createProcess(void);
  virtual int		waitProcess(void) const;
  virtual void		exitProcess(int) const;
};

#endif
