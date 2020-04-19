//
// AProcess.cpp for AProcess.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 10:47:42 2014 CHAUCHET Alan
// Last update Thu Apr 24 10:57:43 2014 CHAUCHET Alan
//

#include		"Fork/AProcess.hh"

AProcess::AProcess()
{
  this->_id = -1;
  this->_status = 0;
}

int			AProcess::getId() const
{
  return (this->_id);
}

int			AProcess::getStatus() const
{
  return (this->_status);
}
