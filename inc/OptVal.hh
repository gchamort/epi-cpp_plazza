//
// OptVal.hh for OptVal.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 16:05:52 2014 CHAUCHET Alan
// Last update Fri Apr 25 16:30:30 2014 CHAUCHET Alan
//

#ifndef			OPTVAL_HH_
# define		OPTVAL_HH_

class			OptVal
{
  static double		_multCookTime;
  static int		_cooksPerKitchen;
  static long		_timePerRefill;

public:
  static void		setMultCookTime(double);
  static void		setCooksPerKitchen(int);
  static void		setTimePerRefill(long);
  static double		getMultCookTime(void);
  static int		getCooksPerKitchen(void);
  static long		getTimePerRefill(void);
};

#endif
