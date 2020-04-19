//
// OptVal.cpp for OptVal.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 16:10:21 2014 CHAUCHET Alan
// Last update Fri Apr 25 16:28:44 2014 CHAUCHET Alan
//

#include		"OptVal.hh"

double			OptVal::_multCookTime;
int			OptVal::_cooksPerKitchen;
long			OptVal::_timePerRefill;

void			OptVal::setMultCookTime(double param)
{
  _multCookTime = param;
}

void			OptVal::setCooksPerKitchen(int param)
{
  _cooksPerKitchen = param;
}

void			OptVal::setTimePerRefill(long param)
{
  _timePerRefill = param;
}

double			OptVal::getMultCookTime(void)
{
  return (_multCookTime);
}

int			OptVal::getCooksPerKitchen(void)
{
  return (_cooksPerKitchen);
}

long			OptVal::getTimePerRefill(void)
{
  return (_timePerRefill);
}
