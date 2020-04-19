//
// IIngr.hh for IIngr.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:14:28 2014 CHAUCHET Alan
// Last update Wed Apr 23 13:53:06 2014 CHAUCHET Alan
//

#ifndef					IINGR_HH_
# define				IINGR_HH_

# include				<string>

typedef enum				e_ingr
  {
    CHIEFLOVE = 0,
    DOE = 1,
    EGGPLANT = 2,
    GOATCHEESE = 3,
    GRUYERE = 4,
    HAM = 5,
    MUSHROOMS = 6,
    STEAK = 7,
    TOMATO = 8
  }					e_ingr;

class					IIngr
{
public:
  virtual ~IIngr() {}
  virtual e_ingr			getType(void) const = 0;
  virtual const std::string		&getName(void) const = 0;
  virtual int				getQtt(void) const = 0;
  virtual void				incr(void) = 0;
  virtual void				decr(void) = 0;
  virtual void				operator--(int) = 0;
  virtual void				operator++(int) = 0;
};

# endif
