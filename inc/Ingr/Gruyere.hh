//
// Gruyere.hh for Gruyere.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:51:46 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:20:57 2014 CHAUCHET Alan
//

#ifndef					GRUYERE_HH_
# define				GRUYERE_HH_

# include				"AIngr.hh"

class					Gruyere : public AIngr
{
public:
  Gruyere(int);
  virtual ~Gruyere() {}
  virtual const std::string		&getName(void) const;
};

#endif
