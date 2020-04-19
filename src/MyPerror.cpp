//
// MyPerror.cpp for MyPerror.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sun Apr 27 20:37:01 2014 CHAUCHET Alan
// Last update Sun Apr 27 20:37:47 2014 CHAUCHET Alan
//

#include		"MyPerror.hh"

MyPerror::MyPerror(const std::string &msg) : std::runtime_error(msg)
{
  std::ostringstream	oss;

  oss << "ERROR: " << msg;
  this->_msg = oss.str();
}

MyPerror::~MyPerror() throw() {}

const char			*MyPerror::what() const throw()
{
  return (this->_msg.c_str());
}
