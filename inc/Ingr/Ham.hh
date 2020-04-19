//
// Ham.hh for Ham.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:52:12 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:21:00 2014 CHAUCHET Alan
//

#ifndef					HAM_HH_
# define				HAM_HH_

# include				"AIngr.hh"

class					Ham : public AIngr
{
public:
  Ham(int);
  virtual ~Ham() {}
  virtual const std::string		&getName(void) const;
};

#endif
