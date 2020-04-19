//
// AIngr.hh for AIngr.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:22:23 2014 CHAUCHET Alan
// Last update Wed Apr 23 13:52:57 2014 CHAUCHET Alan
//

#ifndef					AINGR_HH_
# define				AINGR_HH_

# include				"IIngr.hh"

class					AIngr : public IIngr
{
protected:
  e_ingr				_type;
  int					_qtt;
  const std::string			_name;

public:
  AIngr(e_ingr, int, const std::string &);
  virtual ~AIngr() {}
  virtual e_ingr			getType(void) const;
  virtual int				getQtt(void) const;
  virtual void				incr(void);
  virtual void				decr(void);
  virtual void                          operator--(int);
  virtual void                          operator++(int);
};

#endif
