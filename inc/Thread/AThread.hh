//
// AThread.hh for AThread.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 12:04:39 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:46:36 2014 CHAUCHET Alan
//

#ifndef			ATHREAD_HH_
# define		ATHREAD_HH_

# include		<stdlib.h>

typedef void		*(*threadFunc)(void*);

class			AThread
{
protected:
  threadFunc		_func;
  void			*_param;

public:
  AThread();
  virtual ~AThread() {}
  virtual void		create(threadFunc, void *) = 0;
  virtual void		quit(void *) const = 0;
  virtual void		*wait(void) const = 0;
};

#endif
