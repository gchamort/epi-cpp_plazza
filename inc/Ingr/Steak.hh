//
// Steak.hh for Steak.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:53:08 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:21:10 2014 CHAUCHET Alan
//

#ifndef					STEAK_HH_
# define				STEAK_HH_

# include				"AIngr.hh"

class					Steak : public AIngr
{
public:
  Steak(int);
  virtual ~Steak() {}
  virtual const std::string		&getName(void) const;
};

#endif
