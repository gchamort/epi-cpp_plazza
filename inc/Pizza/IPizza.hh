//
// IPizza.hh for IPizza.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 13:04:36 2014 CHAUCHET Alan
// Last update Fri Apr 25 15:16:21 2014 CHAUCHET Alan
//

#ifndef					IPIZZA_HH_
# define				IPIZZA_HH_

# include				<vector>
# include				"../Ingr/IIngr.hh"

enum TypePizza
  {
    REGINA = 1,
    MARGARITA = 2,
    AMERICAINE = 4,
    FANTASIA = 8
  };

enum TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

class					IPizza
{
public:
  virtual ~IPizza() {}
  virtual int				getIngr(e_ingr) const = 0;
  virtual int				getQtt(e_ingr) const = 0;
  virtual bool				useIngr(e_ingr) = 0;
  virtual bool				isReady(void) const = 0;
  virtual const std::string		&getName(void) const = 0;
  virtual int				getTimeToCook(void) const = 0;
  virtual void				pushIngr(IIngr *) = 0;
  virtual TypePizza			getType(void) const = 0;
  virtual TaillePizza			getSize(void) const = 0;
};

#endif
