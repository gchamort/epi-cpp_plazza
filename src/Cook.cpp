//
// Cook.cpp for Cook.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Sun Apr 27 11:15:49 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:33:29 2014 CHAUCHET Alan
//

#include		<cerrno>
#include		"Cook.hh"
#include		"Kitchen.hh"

Cook::Cook(Kitchen *kitchen) : _kitchen(kitchen)
{
  this->_thread = new Thread();
  this->_mutex = new Mutex();
  this->_mutex->create();
  this->_stop = false;
  this->_isWorking = true;
  this->_pizza = NULL;
  this->_isCooking = false;
  this->_tabIngr[0] = CHIEFLOVE;
  this->_tabIngr[1] = DOE;
  this->_tabIngr[2] = EGGPLANT;
  this->_tabIngr[3] = GOATCHEESE;
  this->_tabIngr[4] = GRUYERE;
  this->_tabIngr[5] = HAM;
  this->_tabIngr[6] = MUSHROOMS;
  this->_tabIngr[7] = STEAK;
  this->_tabIngr[8] = TOMATO;
  this->_time = OptVal::getMultCookTime();
}

Cook::~Cook()
{
  delete(this->_thread);
  delete(this->_mutex);
}

void			Cook::stopCook(void)
{
  this->_stop = true;
}

void			Cook::stopWorking(void)
{
  this->_isWorking = false;
}

void			Cook::launch_thread(void)
{
  this->_thread->create(&callStartCooking, this);
}

void			*callStartCooking(void *param)
{
  Cook			*cook;

  cook = static_cast<Cook *>(param);
  cook->startCooking();
  return (NULL);
}

void			Cook::startCooking(void)
{
  while (!this->_stop && !this->_kitchen->getStop())
    {
      if (this->_pizza == NULL)
	this->takePizza();
      else
	this->cookPizza();
    }
  this->_thread->quit(NULL);
}

void			Cook::takePizza(void)
{
  int			ret;
  bool			stop;

  while (!this->_stop && !this->_kitchen->getStop() && !this->_kitchen->takePizza(this->_pizza))
    {
      stop = false;
      if ((ret = this->_kitchen->getCond()->waitTimer(5)) == ETIMEDOUT)
      	{
      	  this->_mutex->lock();
      	  this->_isWorking = false;
      	  this->_mutex->unlock();
      	  while (!this->_stop && !this->_kitchen->getStop() && !stop)
      	    if (this->_kitchen->waitNewPizza(1) != ETIMEDOUT)
      	      stop = true;
      	}
    }
  if (!this->_stop && !this->_kitchen->getStop())
    this->_isWorking = true;
}

void			Cook::cookPizza(void)
{
  this->_mutex->lock();
  this->_isCooking = true;
  this->_mutex->unlock();
  while (!this->_stop && !this->_kitchen->getStop() && !this->_pizza->isReady())
    {
      for (unsigned int count = 0; count < 9; count++)
	{
	  if (this->_pizza->getQtt(this->_tabIngr[count]) &&
	      this->_kitchen->getBox().getQtt(this->_tabIngr[count]))
	    {
	      if (this->_kitchen->getBox().takeIngr(this->_tabIngr[count]))
		this->_pizza->useIngr(this->_tabIngr[count]);
	    }
	}
    }
  this->_mutex->lock();
  this->_mutex->unlock();
  usleep(static_cast<int>(this->_time * this->_pizza->getTimeToCook()) * 1000000);
  this->_kitchen->affPizza(this->_pizza);
  this->_pizza = NULL;
  this->_isCooking = false;
}

bool			Cook::getIsWorking(void) const
{
  return (this->_isWorking);
}

bool			Cook::getIsCooking(void) const
{
  return (this->_isCooking);
}

bool			Cook::getIsStop(void) const
{
  return (this->_stop);
}

void			Cook::lock(void) const
{
  this->_mutex->lock();
}

void			Cook::unlock(void) const
{
  this->_mutex->unlock();
}
