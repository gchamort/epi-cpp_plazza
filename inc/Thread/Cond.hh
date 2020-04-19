//
// Cond.hh for Cond.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 13:15:05 2014 CHAUCHET Alan
// Last update Fri Apr 25 13:49:36 2014 CHAUCHET Alan
//

#ifndef			COND_HH_
# define		COND_HH_

# include		<pthread.h>
# include		<sys/time.h>
# include		"ACond.hh"

class			Cond : public ACond
{
  pthread_cond_t	_cond;
  pthread_mutex_t	_mutex;

public:
  virtual ~Cond();
  virtual void		create(void);
  virtual void		destroy(void);
  virtual void		wait(void);
  virtual int		waitTimer(long);
  virtual void		signal(void);
  virtual void		broadcast(void);
  virtual void		unlock(void);
};

#endif
