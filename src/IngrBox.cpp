//
// IngrBox.cpp for IngrBox.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 14:54:35 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:35:38 2014 CHAUCHET Alan
//

#include		<iostream>
#include		"IngrBox.hh"
#include		"Factory.hh"
#include		"Thread/Thread.hh"
#include		"Thread/Mutex.hh"
#include		"OptVal.hh"

IngrBox::IngrBox()
{
  this->_stop = false;
  this->_thread = new Thread();
  this->_mutex = new Mutex();
  this->_mutex->create();
  this->_box.push_back(Factory::createIngr(CHIEFLOVE, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(DOE, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(EGGPLANT, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(GOATCHEESE, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(GRUYERE, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(HAM, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(MUSHROOMS, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(STEAK, NB_INGR_START));
  this->_box.push_back(Factory::createIngr(TOMATO, NB_INGR_START));
}

IngrBox::~IngrBox()
{
  while (this->_box.size() > 0)
    {
      delete(this->_box[this->_box.size() - 1]);
      this->_box.pop_back();
    }
  delete(this->_thread);
  delete(this->_mutex);
}

int			IngrBox::getQtt(e_ingr type) const
{
  this->_mutex->lock();
  for (unsigned int count = 0; count < this->_box.size(); count++)
    if (this->_box[count]->getType() == type)
      {
	this->_mutex->unlock();
	return (this->_box[count]->getQtt());
      }
  this->_mutex->unlock();
  return (0);
}

bool			IngrBox::takeIngr(e_ingr type)
{
  this->_mutex->lock();
  for (unsigned int count = 0; count < this->_box.size(); count++)
    if (this->_box[count]->getType() == type)
      {
	if (this->_box[count]->getQtt() < 1)
	  {
	    this->_mutex->unlock();
	    return (false);
	  }
	(*(this->_box[count]))--;
	this->_mutex->unlock();
	return (true);
      }
  this->_mutex->unlock();
  return (false);
}

void			IngrBox::putIngr(e_ingr type) const
{
  this->_mutex->lock();
  for (unsigned int count = 0; count < this->_box.size(); count++)
    if (this->_box[count]->getType() == type)
      {
	(*(this->_box[count]))++;
	this->_mutex->unlock();
	return ;
      }
  this->_mutex->unlock();
}

void			IngrBox::launch_thread(void)
{
  this->_thread->create(&callRefillBox, this);
}

void			IngrBox::refillBox(void) const
{
  unsigned int		count;

  while (this->_stop == false)
    {
      usleep(OptVal::getTimePerRefill() * 1000);
      for (count = 0; count < this->_box.size(); count++)
	this->putIngr(this->_box[count]->getType());
    }
  this->_thread->quit(NULL);
}

void			IngrBox::stopProg(void)
{
  this->_stop = true;
}

void			*callRefillBox(void *param)
{
  IngrBox		*box;

  box = static_cast<IngrBox *>(param);
  box->refillBox();
  return (NULL);
}

void			IngrBox::info(void) const
{
  for (unsigned int count = 0; count < this->_box.size(); count++)
    std::cout << this->_box[count]->getName() << ": " << this->_box[count]->getQtt() << std::endl;
}
