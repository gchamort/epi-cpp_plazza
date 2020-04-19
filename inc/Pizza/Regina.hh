//
// Regina.hh for Regina.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:05:51 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:37:29 2014 CHAUCHET Alan
//

#ifndef			REGINA_HH_
# define		REGINA_HH_

# include		"APizza.hh"

class			Regina : public APizza
{
public:
  Regina(TaillePizza);
  virtual int		getTimeToCook(void) const;
  virtual TypePizza	getType(void) const;
};

#endif
