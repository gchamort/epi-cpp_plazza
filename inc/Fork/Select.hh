//
// Select.hh for Select.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 17:27:10 2014 CHAUCHET Alan
// Last update Fri Apr 25 17:48:09 2014 CHAUCHET Alan
//

#ifndef			SELECT_HH_
# define		SELECT_HH_

# include		<sys/select.h>
# include		<sys/time.h>
# include		<sys/types.h>
# include		<unistd.h>
# include		<vector>

class			Select
{
  std::vector<int>	_listFd;
  fd_set		_fdR;

  void			setListFd(void);
  int			getHigherFd(void);

public:
  void			toZero(void);
  void			addFd(int);
  void			rmFd(int);
  int			select(int time = -1);
  bool			isSet(int);
};

#endif
