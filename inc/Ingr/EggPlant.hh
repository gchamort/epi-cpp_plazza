//
// EggPlant.hh for EggPlant.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:50:33 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:20:51 2014 CHAUCHET Alan
//

#ifndef					EGGPLANT_HH_
# define				EGGPLANT_HH_

# include				"AIngr.hh"

class					EggPlant : public AIngr
{
public:
  EggPlant(int);
  virtual ~EggPlant() {}
  virtual const std::string		&getName(void) const;
};

#endif
