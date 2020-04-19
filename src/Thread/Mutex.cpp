//
// Mutex.cpp for Mutex.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 18:46:58 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:49:20 2014 CHAUCHET Alan
//

#include		"Thread/Mutex.hh"

Mutex::~Mutex()
{
  this->destroy();
}

void			Mutex::create(void)
{
  pthread_mutex_init(&(this->_mutex), NULL);
}

void			Mutex::lock(void)
{
  pthread_mutex_lock(&(this->_mutex));
}

int			Mutex::trylock(void)
{
  return (pthread_mutex_trylock(&(this->_mutex)));
}

void			Mutex::unlock(void)
{
  pthread_mutex_unlock(&(this->_mutex));
}

void			Mutex::destroy(void)
{
  pthread_mutex_destroy(&(this->_mutex));
}
