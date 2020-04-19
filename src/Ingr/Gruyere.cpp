//
// Gruyere.cpp for Gruyere.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:56:32 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:22:20 2014 CHAUCHET Alan
//

#include		"Ingr/Gruyere.hh"

Gruyere::Gruyere(int qtt) : AIngr(GRUYERE, qtt, "Gruyere") {}

const std::string	&Gruyere::getName(void) const
{
  return (this->_name);
}
