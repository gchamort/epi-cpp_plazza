//
// AProcess.hh for AProcess.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Thu Apr 24 10:47:42 2014 CHAUCHET Alan
// Last update Sun Apr 27 22:42:30 2014 CHAUCHET Alan
//

#ifndef			APROCESS_HH_
# define		APROCESS_HH_

class			AProcess
{
protected:
  int			_id;
  int			_status;

public:
  AProcess();
  virtual ~AProcess() {}
  virtual int		getId(void) const;
  virtual int		getStatus(void) const;
  virtual int		createProcess(void) = 0;
  virtual int		waitProcess(void) const = 0;
  virtual void		exitProcess(int) const = 0;
};

#endif
