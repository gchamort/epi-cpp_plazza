//
// Thread.hh for Thread.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 12:18:25 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:46:31 2014 CHAUCHET Alan
//

#ifndef			THREAD_HH_
# define		THREAD_HH_

# include		<pthread.h>
# include		"AThread.hh"

class			Thread : public AThread
{
  pthread_t		_thread;

  public:
  virtual ~Thread() {}
  virtual void		create(threadFunc, void *);
  virtual void		quit(void *) const;
  virtual void		*wait(void) const;
};

#endif
