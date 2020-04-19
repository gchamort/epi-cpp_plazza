//
// Mushrooms.hh for Mushrooms.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:52:42 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:21:07 2014 CHAUCHET Alan
//

#ifndef					MUSHROOMS_HH_
# define				MUSHROOMS_HH_

# include				"AIngr.hh"

class					Mushrooms : public AIngr
{
public:
  Mushrooms(int);
  virtual ~Mushrooms() {}
  virtual const std::string		&getName(void) const;
};

#endif
