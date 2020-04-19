//
// Cook.hh for Cook.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sun Apr 27 11:15:52 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:33:31 2014 CHAUCHET Alan
//

#ifndef			COOK_HH_
# define		COOK_HH_

# include		<iostream>
# include		<vector>
# include		"IngrBox.hh"
# include		"Pizza/IPizza.hh"
# include		"Fork/NamedPipe.hh"
# include		"Fork/Select.hh"
# include		"Thread/Thread.hh"
# include		"Thread/Mutex.hh"
# include		"Thread/Cond.hh"
# include		"FunctionString.hpp"
# include		"Factory.hh"
# include		"OptVal.hh"

class			Kitchen;

class			Cook
{
  AThread		*_thread;
  AMutex		*_mutex;
  Kitchen		*_kitchen;
  bool			_stop;
  bool			_isWorking;
  bool			_isCooking;
  IPizza		*_pizza;
  e_ingr		_tabIngr[9];
  double		_time;

public:
  Cook(Kitchen *);
  ~Cook();
  void			stopCook(void);
  void			stopWorking(void);
  void			launch_thread(void);
  void			startCooking(void);
  void			takePizza(void);
  void			cookPizza(void);
  bool			getIsWorking(void) const;
  bool			getIsCooking(void) const;
  bool			getIsStop(void) const;
  void			lock(void) const;
  void			unlock(void) const;
};

void			*callStartCooking(void *);

#endif
