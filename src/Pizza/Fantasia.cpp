//
// Fantasia.cpp for Fantasia.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:13:33 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:36:27 2014 CHAUCHET Alan
//

#include		"Pizza/Fantasia.hh"
#include		"Ingr/Doe.hh"
#include		"Ingr/Tomato.hh"
#include		"Ingr/EggPlant.hh"
#include		"Ingr/GoatCheese.hh"
#include		"Ingr/ChiefLove.hh"

Fantasia::Fantasia(TaillePizza size) : APizza("Fantasia")
{
  this->pushIngr(new Doe(1));
  this->pushIngr(new Tomato(1));
  this->pushIngr(new EggPlant(1));
  this->pushIngr(new GoatCheese(1));
  this->pushIngr(new ChiefLove(1));
  this->_size = size;
}

int			Fantasia::getTimeToCook() const
{
  return (4);
}

TypePizza		Fantasia::getType() const
{
  return (FANTASIA);
}
