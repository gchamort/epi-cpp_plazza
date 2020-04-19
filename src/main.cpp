//
// main.cpp for main.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr 22 18:35:39 2014 CHAUCHET Alan
// Last update Sat Apr 26 18:47:23 2014 CHAUCHET Alan
//

#include		<iostream>
#include		<vector>
#include		"Reception.hh"
#include		"OptVal.hh"

bool			isNum(const std::string &str, bool isDouble)
{
  for (unsigned int count = 0; count < str.size(); count++)
    if (!(str[count] >= '0' && str[count] <= '9') && (isDouble == false || str[count] != '.'))
      return (false);
  if (isDouble)
    {
      if (FunctionString::stringToVar<double>(str) < 0.01)
	return (false);
    }
  else
    if (FunctionString::stringToVar<long>(str) < 1)
      return (false);
  return (true);
}

int			main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cerr << "ERROR: bad usage: use ./plazza <multCookTime> <cooksPerKitchen> <refillTime>" << std::endl;
      return (1);
    }
  if (!isNum(av[1], true))
    {
      std::cerr << "ERROR: bad multCookTime." << std::endl;
      return (1);
    }
  if (!isNum(av[2], false))
    {
      std::cerr << "ERROR: bad cooksPerKitchen." << std::endl;
      return (1);
    }
    if (!isNum(av[3], false))
    {
      std::cerr << "ERROR: bad refillTime." << std::endl;
      return (1);
    }
  OptVal::setMultCookTime(FunctionString::stringToVar<double>(av[1]));
  OptVal::setCooksPerKitchen(FunctionString::stringToVar<int>(av[2]));
  OptVal::setTimePerRefill(FunctionString::stringToVar<long>(av[3]));

  Reception		reception;

  reception.openReception();
  return (0);
}
