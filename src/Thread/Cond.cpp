//
// Cond.cpp for Cond.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 13:20:58 2014 CHAUCHET Alan
// Last update Sun Apr 27 21:20:15 2014 CHAUCHET Alan
//

#include		"Thread/Cond.hh"

Cond::~Cond()
{
  this->destroy();
}

void			Cond::create(void)
{
  if (this->_isInit == true)
    return ;
  pthread_cond_init(&(this->_cond), NULL);
  pthread_mutex_init(&(this->_mutex), NULL);
  this->_isInit = true;
}

void			Cond::destroy(void)
{
  if (this->_isInit == false)
    return ;
  this->unlock();
  pthread_cond_destroy(&(this->_cond));
  pthread_mutex_destroy(&(this->_mutex));
  this->_isInit = false;
}

void			Cond::wait(void)
{
  if (this->_isInit == false)
    return ;
  pthread_mutex_lock(&(this->_mutex));
  this->_isLock = true;
  pthread_cond_wait(&(this->_cond), &(this->_mutex));
  pthread_mutex_unlock(&(this->_mutex));
}

int			Cond::waitTimer(long tv_sec)
{
  int			ret;
  struct timeval	now;
  struct timespec	param;

  if (this->_isInit == false)
    return (0);
  gettimeofday(&now, NULL);
  param.tv_sec = now.tv_sec + tv_sec;
  param.tv_nsec = now.tv_usec * 1000UL;
  pthread_mutex_lock(&(this->_mutex));
  this->_isLock = true;
  ret = pthread_cond_timedwait(&(this->_cond), &(this->_mutex), &param);
  pthread_mutex_unlock(&(this->_mutex));
  return (ret);
}

void			Cond::unlock(void)
{
  if (this->_isLock == false)
    return ;
  pthread_mutex_unlock(&(this->_mutex));
  this->_isLock = false;
}

void			Cond::signal(void)
{
  if (this->_isInit == true)
    pthread_cond_signal(&(this->_cond));
}

void			Cond::broadcast(void)
{
  if (this->_isInit == true)
    pthread_cond_broadcast(&(this->_cond));
}
