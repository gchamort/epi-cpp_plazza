//
// Mushrooms.cpp for Mushrooms.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:55:28 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:22:06 2014 CHAUCHET Alan
//

#include		"Ingr/Mushrooms.hh"

Mushrooms::Mushrooms(int qtt) : AIngr(MUSHROOMS, qtt, "Mushrooms") {}

const std::string	&Mushrooms::getName(void) const
{
  return (this->_name);
}
