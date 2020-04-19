//
// Regina.cpp for Regina.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:06:24 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:38:24 2014 CHAUCHET Alan
//

#include		"Pizza/Regina.hh"
#include		"Ingr/Doe.hh"
#include		"Ingr/Tomato.hh"
#include		"Ingr/Gruyere.hh"
#include		"Ingr/Ham.hh"
#include		"Ingr/Mushrooms.hh"

Regina::Regina(TaillePizza size) : APizza("Regina")
{
  this->pushIngr(new Doe(1));
  this->pushIngr(new Tomato(1));
  this->pushIngr(new Gruyere(1));
  this->pushIngr(new Ham(1));
  this->pushIngr(new Mushrooms(1));
  this->_size = size;
}

int			Regina::getTimeToCook() const
{
  return (2);
}

TypePizza		Regina::getType() const
{
  return (REGINA);
}
