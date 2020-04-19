//
// Select.cpp for Select.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 17:27:10 2014 CHAUCHET Alan
// Last update Fri Apr 25 18:21:23 2014 CHAUCHET Alan
//

#include		"Fork/Select.hh"

void			Select::toZero(void)
{
  FD_ZERO(&(this->_fdR));
}

void			Select::addFd(int newFd)
{
  for (unsigned int count = 0; count < this->_listFd.size(); count++)
    if (this->_listFd[count] == newFd)
      return ;
  this->_listFd.push_back(newFd);
}

void			Select::rmFd(int toRm)
{
  unsigned int		count;
  int			pos;

  pos = -1;
  for (count = 0; count < this->_listFd.size(); count++)
    if (this->_listFd[count] == toRm)
      pos = count;
  if (pos == -1)
    return ;
  this->_listFd.erase(this->_listFd.begin() + pos);
}

void			Select::setListFd(void)
{
  for (unsigned int count = 0; count < this->_listFd.size(); count++)
    FD_SET(this->_listFd[count], &(this->_fdR));
}

int			Select::getHigherFd(void)
{
  int			ret;

  ret = 0;
  for (unsigned int count = 0; count < this->_listFd.size(); count++)
    if (this->_listFd[count] > ret)
      ret = this->_listFd[count];
  return (ret + 1);
}

int			Select::select(int time)
{
  int			higher;

  if (this->_listFd.empty())
    return (0);
  this->toZero();
  this->setListFd();
  if ((higher = this->getHigherFd()) == 1)
    return (0);
  if (time == -1)
    return (::select(higher, &(this->_fdR), NULL, NULL, NULL));
  struct timeval	tv;

  tv.tv_sec = time;
  tv.tv_usec = 0;
  return (::select(higher, &(this->_fdR), NULL, NULL, &tv));
}

bool			Select::isSet(int needle)
{
  if (FD_ISSET(needle, &(this->_fdR)))
    return (true);
  return (false);
}
