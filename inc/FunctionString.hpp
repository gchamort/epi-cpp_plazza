//
// FunctionString.hh for FunctionString.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 25 16:50:21 2014 CHAUCHET Alan
// Last update Sat Apr 26 16:19:59 2014 CHAUCHET Alan
//

#ifndef					FUNCTIONSTRING_HH_
# define				FUNCTIONSTRING_HH_

# include	                        <iostream>
# include		                <vector>
# include			        <sstream>

class					FunctionString
{
public:
  static std::vector<std::string>	stringToVector(const std::string &str)
  {
    std::vector<std::string>		wordTab;
    std::string				word;
    std::stringstream			ssin(str);

    while (ssin.good())
      {
	ssin >> word;
	wordTab.push_back(word);
      }
    return (wordTab);
  }

  template<typename X>
  static X				stringToVar(const std::string &str)
  {
    std::istringstream    iss(str);
    X                     val;

    iss >> val;
    return (val);
  }

  template<typename X>
  static std::string			varToString(X var)
  {
    std::ostringstream		oss;

    oss << var;
    return (oss.str());
  }
};

#endif
