//
// AMutex.hh for AMutex.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 18:38:33 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:49:18 2014 CHAUCHET Alan
//

#ifndef			AMUTEX_HH_
# define		AMUTEX_HH_

class			AMutex
{
protected:
  bool			_isLock;
  bool			_isInit;

public:
  AMutex();
  virtual ~AMutex() {}
  virtual void		create(void) = 0;
  virtual void		lock(void) = 0;
  virtual int		trylock(void) = 0;
  virtual void		unlock(void) = 0;
  virtual void		destroy(void) = 0;
  virtual bool		isInit(void) const;
  virtual bool		isLocked(void) const;
};

#endif
