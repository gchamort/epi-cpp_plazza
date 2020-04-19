//
// ANamedPipe.cpp for ANamedPipe.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 18:03:06 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:40:13 2014 CHAUCHET Alan
//

#include				"Fork/ANamedPipe.hh"

ANamedPipe::ANamedPipe(const std::string &name, bool isLeft) : _name(name), _isLeft(isLeft)
{
  this->_fdFileR = -1;
  this->_fdFileW = -1;
}

ANamedPipe::~ANamedPipe()
{
  if (this->_fdFileR != -1)
    ::close(this->_fdFileR);
  if (this->_fdFileW != -1)
    ::close(this->_fdFileW);
}

void					ANamedPipe::writeInPipe(const std::string &text) const
{
  write(this->_fdFileW, text.c_str(), text.size());
}

const std::string			&ANamedPipe::readOnPipe()
{
  char					buffer[4096];

  for (int count = 0; count < 4096; count++)
    buffer[count] = 0;
  read(this->_fdFileR, buffer, 4096);
  this->_txt = buffer;
  return (this->_txt);
}

std::string				&ANamedPipe::operator>>(std::string &ret)
{
  ret = this->readOnPipe();
  return (ret);
}

void					ANamedPipe::operator<<(const std::string &txt) const
{
  this->writeInPipe(txt);
}

int					ANamedPipe::getFdFileR(void) const
{
  return (this->_fdFileR);
}

int					ANamedPipe::getFdFileW(void) const
{
  return (this->_fdFileW);
}
