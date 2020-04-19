//
// ACond.hh for ACond.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 12:55:17 2014 CHAUCHET Alan
// Last update Fri Apr 25 13:48:31 2014 CHAUCHET Alan
//

#ifndef			ACOND_HH_
# define		ACOND_HH_

class			ACond
{
protected:
  bool			_isLock;
  bool			_isInit;

public:
  ACond();
  virtual ~ACond() {}
  virtual void		create(void) = 0;
  virtual void		destroy(void) = 0;
  virtual void		wait(void) = 0;
  virtual int		waitTimer(long) = 0;
  virtual void		signal(void) = 0;
  virtual void		broadcast(void) = 0;
  virtual void		unlock(void) = 0;
  virtual bool		getIsInit(void) const;
  virtual bool		getIsLock(void) const;
};

#endif
