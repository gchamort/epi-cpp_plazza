//
// Doe.cpp for Doe.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:57:46 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:21:34 2014 CHAUCHET Alan
//

#include		"Ingr/Doe.hh"

Doe::Doe(int qtt) : AIngr(DOE, qtt, "Doe") {}

const std::string	&Doe::getName(void) const
{
  return (this->_name);
}
