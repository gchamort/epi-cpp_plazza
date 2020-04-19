//
// ACond.cpp for ACond.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 13:14:31 2014 CHAUCHET Alan
// Last update Fri Apr 25 13:35:13 2014 CHAUCHET Alan
//

#include		"Thread/ACond.hh"

ACond::ACond()
{
  this->_isInit = false;
  this->_isLock = false;
}

bool			ACond::getIsInit(void) const
{
  return (this->_isInit);
}

bool			ACond::getIsLock(void) const
{
  return (this->_isLock);
}
