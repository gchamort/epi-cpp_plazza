//
// Mutex.hh for Mutex.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 18:43:51 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:49:13 2014 CHAUCHET Alan
//

#ifndef			MUTEX_HH_
# define		MUTEX_HH_

# include		<pthread.h>
# include		"AMutex.hh"

class			Mutex : public AMutex
{
  pthread_mutex_t	_mutex;

public:
  virtual ~Mutex();
  virtual void		create(void);
  virtual void		lock(void);
  virtual int		trylock(void);
  virtual void		unlock(void);
  virtual void		destroy(void);
};

#endif
