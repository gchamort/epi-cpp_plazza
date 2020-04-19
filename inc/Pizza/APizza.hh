//
// APizza.hh for APizza.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 13:11:48 2014 CHAUCHET Alan
// Last update Fri Apr 25 15:15:55 2014 CHAUCHET Alan
//

#ifndef			APIZZA_HH_
# define		APIZZA_HH_

# include		"IPizza.hh"

class			APizza : public IPizza
{
protected:
  const std::string	_name;
  std::vector<IIngr *>	_listIngr;
  TaillePizza		_size;

public:
  virtual ~APizza();
  APizza(const std::string &);
  virtual int				getIngr(e_ingr) const;
  virtual int				getQtt(e_ingr) const;
  virtual bool				useIngr(e_ingr);
  virtual bool				isReady(void) const;
  virtual const std::string		&getName(void) const;
  virtual void				pushIngr(IIngr *);
  virtual TaillePizza			getSize(void) const;
};

#endif
