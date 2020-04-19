//
// AIngr.hh for AIngr.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:32:57 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:23:02 2014 CHAUCHET Alan
//

#include		"Ingr/AIngr.hh"

AIngr::AIngr(e_ingr type, int qtt, const std::string &name) : _name(name)
{
  this->_type = type;
  this->_qtt = qtt;
}

e_ingr			AIngr::getType(void) const
{
  return (this->_type);
}

int			AIngr::getQtt(void) const
{
  return (this->_qtt);
}

void			AIngr::incr(void)
{
  this->_qtt++;
}

void			AIngr::decr(void)
{
  this->_qtt--;
}

void			AIngr::operator--(int nb)
{
  static_cast<void>(nb);
  this->decr();
}

void			AIngr::operator++(int nb)
{
  static_cast<void>(nb);
  this->incr();
}
