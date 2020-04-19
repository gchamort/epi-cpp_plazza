//
// Doe.hh for Doe.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:49:57 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:20:40 2014 CHAUCHET Alan
//

#ifndef					DOE_HH_
# define				DOE_HH_

# include				"AIngr.hh"

class					Doe : public AIngr
{
public:
  Doe(int);
  virtual ~Doe() {}
  virtual const std::string		&getName(void) const;
};

#endif
