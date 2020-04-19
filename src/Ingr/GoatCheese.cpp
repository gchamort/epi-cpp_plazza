//
// GoatCheese.cpp for GoatCheese.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 17:56:53 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:22:27 2014 CHAUCHET Alan
//

#include		"Ingr/GoatCheese.hh"

GoatCheese::GoatCheese(int qtt) : AIngr(GOATCHEESE, qtt, "Goat cheese") {}

const std::string	&GoatCheese::getName(void) const
{
  return (this->_name);
}
