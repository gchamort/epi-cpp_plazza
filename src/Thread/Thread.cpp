//
// Thread.cpp for Thread.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 12:20:34 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:46:27 2014 CHAUCHET Alan
//

#include		"Thread/Thread.hh"
#include		"MyPerror.hh"

void			Thread::create(threadFunc func, void *param)
{
  this->_param = param;
  this->_func = func;
  if (pthread_create(&(this->_thread), NULL, this->_func, this->_param))
    throw MyPerror("pthread_create failed");
}

void			Thread::quit(void *ret) const
{
  pthread_exit(ret);
}

void			*Thread::wait() const
{
  void			*ret;

  pthread_join(this->_thread, &(ret));
  return (ret);
}
