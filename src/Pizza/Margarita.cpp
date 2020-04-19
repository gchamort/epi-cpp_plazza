//
// Margarita.cpp for Margarita.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:01:35 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:35:39 2014 CHAUCHET Alan
//

#include		"Pizza/Margarita.hh"
#include		"Ingr/Doe.hh"
#include		"Ingr/Tomato.hh"
#include		"Ingr/Gruyere.hh"

Margarita::Margarita(TaillePizza size) : APizza("Margarita")
{
  this->pushIngr(new Doe(1));
  this->pushIngr(new Tomato(1));
  this->pushIngr(new Gruyere(1));
  this->_size = size;
}

int			Margarita::getTimeToCook() const
{
  return (1);
}

TypePizza		Margarita::getType() const
{
  return (MARGARITA);
}
