//
// NamedPipe.cpp for NamedPipe.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 19:29:34 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:41:48 2014 CHAUCHET Alan
//

#include		"MyPerror.hh"
#include		"Fork/NamedPipe.hh"

NamedPipe::NamedPipe(const std::string &name, bool isLeft) : ANamedPipe(name, isLeft) {}

NamedPipe::~NamedPipe()
{
  this->close();
}

void			NamedPipe::openPipeR()
{
  if (this->_isLeft)
    this->_fdFileR = open(("namedPipe/" + this->_name + "R").c_str(), O_RDONLY);
  else
    this->_fdFileR = open(("namedPipe/" + this->_name + "W").c_str(), O_RDONLY);
}

void			NamedPipe::openPipeW()
{
  if (this->_isLeft)
    this->_fdFileW = open(("namedPipe/" + this->_name + "W").c_str(), O_WRONLY);
  else
    this->_fdFileW = open(("namedPipe/" + this->_name + "R").c_str(), O_WRONLY);
}

void			NamedPipe::createPipes()
{
  if (this->_isLeft)
    {
      this->openPipeR();
      this->openPipeW();
    }
  else
    {
      this->openPipeW();
      this->openPipeR();
    }
  if (this->_fdFileR == -1 || this->_fdFileW == -1)
    throw MyPerror("openning named pipe failed");
}

void			NamedPipe::createOpt() const
{
  mkfifo(("namedPipe/" + this->_name + "W").c_str(), 0644);
  mkfifo(("namedPipe/" + this->_name + "R").c_str(), 0644);
}

void			NamedPipe::close()
{
  if (this->_fdFileR != -1)
    ::close(this->_fdFileR);
  if (this->_fdFileW != -1)
    ::close(this->_fdFileW);
  this->_fdFileR = -1;
  this->_fdFileW = -1;
}

void			NamedPipe::del() const
{
  unlink(("namedPipe/" + this->_name + "W").c_str());
  unlink(("namedPipe/" + this->_name + "R").c_str());
}
