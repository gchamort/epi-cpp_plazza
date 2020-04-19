//
// Steak.cpp for Steak.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:55:06 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:21:59 2014 CHAUCHET Alan
//

#include		"Ingr/Steak.hh"

Steak::Steak(int qtt) : AIngr(STEAK, qtt, "Steak") {}

const std::string	&Steak::getName(void) const
{
  return (this->_name);
}
