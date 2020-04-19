//
// IngrBox.hh for IngrBox.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 14:54:35 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:35:41 2014 CHAUCHET Alan
//

#ifndef			INGRBOX_HH_
# define		INGRBOX_HH_

# include		<unistd.h>
# include		<vector>
# include		"Ingr/IIngr.hh"
# include		"Thread/AThread.hh"
# include		"Thread/AMutex.hh"

# define		NB_INGR_START	5

class			IngrBox
{
  std::vector<IIngr *>	_box;
  AThread		*_thread;
  AMutex		*_mutex;
  bool			_stop;

public:
  IngrBox();
  ~IngrBox();
  int			getQtt(e_ingr) const;
  bool			takeIngr(e_ingr);
  void			putIngr(e_ingr) const;
  void			launch_thread(void);
  void			refillBox(void) const;
  void			stopProg(void);
  void			info(void) const;
};

void			*callRefillBox(void *);

#endif
