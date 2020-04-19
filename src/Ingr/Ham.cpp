//
// Ham.cpp for Ham.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:56:11 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:22:13 2014 CHAUCHET Alan
//

#include		"Ingr/Ham.hh"

Ham::Ham(int qtt) : AIngr(HAM, qtt, "Ham") {}

const std::string	&Ham::getName(void) const
{
  return (this->_name);
}
