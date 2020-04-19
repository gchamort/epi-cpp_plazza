//
// EggPlant.cpp for EggPlant.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:57:23 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:22:34 2014 CHAUCHET Alan
//

#include		"Ingr/EggPlant.hh"

EggPlant::EggPlant(int qtt) : AIngr(EGGPLANT, qtt, "Eggplant") {}

const std::string	&EggPlant::getName(void) const
{
  return (this->_name);
}
