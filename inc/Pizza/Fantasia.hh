//
// Fantasia.hh for Fantasia.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:12:59 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:37:22 2014 CHAUCHET Alan
//

#ifndef			FANTASIA_HH_
# define		FANTASIA_HH_

# include		"APizza.hh"

class			Fantasia : public APizza
{
public:
  Fantasia(TaillePizza);
  virtual int		getTimeToCook(void) const;
  virtual TypePizza	getType(void) const;
};

#endif
