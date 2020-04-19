//
// APizza.cpp for APizza.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 13:21:12 2014 CHAUCHET Alan
// Last update Fri Apr 25 15:15:38 2014 CHAUCHET Alan
//

#include		"Pizza/APizza.hh"

APizza::APizza(const std::string &name) : _name(name) {}

APizza::~APizza()
{
  while (this->_listIngr.size())
    {
      delete(this->_listIngr[this->_listIngr.size() - 1]);
      this->_listIngr.pop_back();
    }
}

int			APizza::getIngr(e_ingr type) const
{
  for (size_t count = 0; count < this->_listIngr.size(); count++)
    if (this->_listIngr[count]->getType() == type)
      return (count);
  return (-1);
}

int			APizza::getQtt(e_ingr type) const
{
  for (size_t count = 0; count < this->_listIngr.size(); count++)
    if (this->_listIngr[count]->getType() == type)
      return (this->_listIngr[count]->getQtt());
  return (0);
}

bool			APizza::useIngr(e_ingr type)
{
  int			count;

  if ((count = this->getIngr(type)) == -1 ||
      this->_listIngr[count]->getQtt() < 1)
    return (false);
  (*(this->_listIngr[count]))--;
  return (true);
}

bool			APizza::isReady(void) const
{
  for (size_t count = 0; count < this->_listIngr.size(); count++)
    if (this->_listIngr[count]->getQtt() > 0)
      return (false);
  return (true);
}

const std::string	&APizza::getName(void) const
{
  return (this->_name);
}

void			APizza::pushIngr(IIngr *newIngr)
{
  this->_listIngr.push_back(newIngr);
}

TaillePizza		APizza::getSize() const
{
  return (this->_size);
}
