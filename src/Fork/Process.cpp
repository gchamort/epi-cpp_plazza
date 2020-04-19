//
// Process.cpp for Process.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 10:57:50 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:43:45 2014 CHAUCHET Alan
//

#include		"Fork/Process.hh"
#include		"MyPerror.hh"

int			Process::createProcess()
{
  this->_id = fork();
  if (this->_id == -1)
    throw MyPerror("creating process failed");
  return (this->_id);
}

int			Process::waitProcess() const
{
  int			status;

  if (this->_id != 0)
    waitpid(this->_id, &(status), 0);
  return (status);
}

void			Process::exitProcess(int ret) const
{
  if (this->_id == 0)
    exit(ret);
}
