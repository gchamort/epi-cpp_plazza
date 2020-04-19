//
// Margarita.hh for Margarita.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 13:55:29 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:37:32 2014 CHAUCHET Alan
//

#ifndef			MARGARITA_HH_
# define		MARGARITA_HH_

# include		"APizza.hh"

class			Margarita : public APizza
{
public:
  Margarita(TaillePizza);
  virtual int		getTimeToCook(void) const;
  virtual TypePizza	getType(void) const;
};

#endif
