//
// AMutex.cpp for AMutex.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 12:41:22 2014 CHAUCHET Alan
// Last update Fri Apr 25 12:44:05 2014 CHAUCHET Alan
//

#include		"Thread/AMutex.hh"

AMutex::AMutex()
{
  this->_isLock = false;
  this->_isInit = false;
}

bool			AMutex::isInit(void) const
{
  return (this->_isInit);
}

bool			AMutex::isLocked(void) const
{
  return (this->_isLock);
}
