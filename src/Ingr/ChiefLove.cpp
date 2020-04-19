//
// ChiefLove.cpp for ChiefLove.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:45:54 2014 CHAUCHET Alan
// Last update Tue Apr 22 18:17:20 2014 CHAUCHET Alan
//

#include		"Ingr/ChiefLove.hh"

ChiefLove::ChiefLove(int qtt) : AIngr(CHIEFLOVE, qtt, "Chief love") {}

const std::string	&ChiefLove::getName(void) const
{
  return (this->_name);
}
