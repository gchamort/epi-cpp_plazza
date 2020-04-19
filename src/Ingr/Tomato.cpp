//
// Tomato.cpp for Tomato.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:54:05 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:21:53 2014 CHAUCHET Alan
//

#include		"Ingr/Tomato.hh"

Tomato::Tomato(int qtt) : AIngr(TOMATO, qtt, "Tomato") {}

const std::string	&Tomato::getName(void) const
{
  return (this->_name);
}
