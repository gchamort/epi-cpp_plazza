//
// Kitchen.hh for Kitchen.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sat Apr 26 20:29:31 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:29:09 2014 CHAUCHET Alan
//

#ifndef			KITCHEN_HH_
# define		KITCHEN_HH_

# include		<iostream>
# include		<vector>
# include		"MyPerror.hh"
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
# include		"Cook.hh"

typedef enum				e_recept_type
  {
    PIZZA_CMD = 0,
    IS_FULL = 1,
    ASK_QUIT = 2,
    ASK_INFO = 3
  }					e_recept_type;

typedef	enum				e_kitchen_type
  {
    KITCHEN_EXIT = 0,
    YES = 1,
    NO = 2
  }					e_kitchen_type;

class			Kitchen
{
  std::string		_name;
  bool			_stop;
  std::vector<IPizza *>	_listPizza;
  ACond			*_cond;
  AMutex		*_mutex;
  IngrBox		_box;
  Select		_select;
  ANamedPipe		*_reception;
  std::string		_text;
  int			_nbCooks;
  std::vector<Cook *>	_cooks;
  AMutex		*_cout;

public:
  Kitchen(const std::string &, AMutex *);
  ~Kitchen();
  void			addPizza(const std::string &);
  void			cmdIsFull(const std::string &);
  void			stopKitchen(const std::string &);
  void		        affInfo(const std::string &);
  bool			takePizza(IPizza *&);
  void			runKitchen(void);
  void			handleCmd(const std::vector<std::string> &);
  const std::string	getTextMsg(e_kitchen_type) const;
  int			waitNewPizza(int) const;
  IngrBox		&getBox(void);
  bool			isFull(void) const;
  bool			isStop(void);
  void			stopCooks(void) const;
  int			getCooksWorking(void) const;
  void			askInfo(void);
  void			affPizza(IPizza *) const;
  const std::string	getSize(TaillePizza) const;
  bool			getStop(void) const;
  ACond			*getCond(void);
};

typedef void		(Kitchen::*funcKitchen)(const std::string &);

typedef struct		s_funcKitchen
{
  e_recept_type		type;
  funcKitchen		func;
}			t_funcKitchen;

#endif
