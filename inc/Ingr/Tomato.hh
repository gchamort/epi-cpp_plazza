//
// Tomato.hh for Tomato.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:53:28 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:21:12 2014 CHAUCHET Alan
//

#ifndef					TOMATO_HH_
# define				TOMATO_HH_

# include				"AIngr.hh"

class					Tomato : public AIngr
{
public:
  Tomato(int);
  virtual ~Tomato() {}
  virtual const std::string		&getName(void) const;
};

#endif
