//
// Americaine.cpp for Americaine.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:12:02 2014 CHAUCHET Alan
// Last update Wed Apr 23 14:36:12 2014 CHAUCHET Alan
//

#include		"Pizza/Americaine.hh"
#include		"Ingr/Doe.hh"
#include		"Ingr/Tomato.hh"
#include		"Ingr/Gruyere.hh"
#include		"Ingr/Steak.hh"

Americana::Americana(TaillePizza size) : APizza("Americana")
{
  this->pushIngr(new Doe(1));
  this->pushIngr(new Tomato(1));
  this->pushIngr(new Gruyere(1));
  this->pushIngr(new Steak(1));
  this->_size = size;
}

int			Americana::getTimeToCook() const
{
  return (2);
}

TypePizza		Americana::getType() const
{
  return (AMERICAINE);
}
