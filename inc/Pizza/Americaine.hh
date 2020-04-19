//
// Americaine.hh for Americaine.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:11:20 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:37:26 2014 CHAUCHET Alan
//

#ifndef			AMERICANA_HH_
# define		AMERICANA_HH_

# include		"APizza.hh"

class			Americana : public APizza
{
public:
  Americana(TaillePizza);
  virtual int		getTimeToCook(void) const;
  virtual TypePizza	getType(void) const;
};

#endif
