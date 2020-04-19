//
// GoatCheese.hh for GoatCheese.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:51:14 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:20:55 2014 CHAUCHET Alan
//

#ifndef					GOATCHEESE_HH_
# define				GOATCHEESE_HH_

# include				"AIngr.hh"

class					GoatCheese : public AIngr
{
public:
  GoatCheese(int);
  virtual ~GoatCheese() {}
  virtual const std::string		&getName(void) const;
};

#endif
