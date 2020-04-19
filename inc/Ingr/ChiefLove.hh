//
// ChiefLove.hh for ChiefLove.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:40:45 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:09:18 2014 CHAUCHET Alan
//

#ifndef					CHIEFLOVE_HH_
# define				CHIEFLOVE_HH_

# include				"AIngr.hh"

class					ChiefLove : public AIngr
{
public:
  ChiefLove(int);
  virtual ~ChiefLove() {}
  virtual const std::string		&getName(void) const;
};

#endif
