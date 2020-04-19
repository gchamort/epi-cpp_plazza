//
// Factory.hh for Factory.hh in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:41:18 2014 CHAUCHET Alan
// Last update Wed Apr 23 15:18:30 2014 CHAUCHET Alan
//

#ifndef			FACTORY_HH_
# define		FACTORY_HH_

# include		"Ingr/ChiefLove.hh"
# include		"Ingr/Doe.hh"
# include		"Ingr/EggPlant.hh"
# include		"Ingr/GoatCheese.hh"
# include		"Ingr/Gruyere.hh"
# include		"Ingr/Ham.hh"
# include		"Ingr/Mushrooms.hh"
# include		"Ingr/Steak.hh"
# include		"Ingr/Tomato.hh"
# include		"Pizza/Americaine.hh"
# include		"Pizza/Fantasia.hh"
# include		"Pizza/Margarita.hh"
# include		"Pizza/Regina.hh"

class			Factory
{
public:
  template<typename X>
  static IIngr		*createIIngr(int);
  static IIngr		*createChiefLove(int);
  static IIngr		*createDoe(int);
  static IIngr		*createEggPlant(int);
  static IIngr		*createGoatCheese(int);
  static IIngr		*createGruyere(int);
  static IIngr		*createHam(int);
  static IIngr		*createMushrooms(int);
  static IIngr		*createSteak(int);
  static IIngr		*createTomato(int);
  static IIngr		*createIngr(e_ingr, int);
  template<typename X>
  static IPizza		*createIPizza(TaillePizza);
  static IPizza		*createRegina(TaillePizza);
  static IPizza		*createMargarita(TaillePizza);
  static IPizza		*createAmericana(TaillePizza);
  static IPizza		*createFantasia(TaillePizza);
  static IPizza		*createPizza(TypePizza, TaillePizza);
};

typedef IIngr		*(*funcCreateIngr)(int);

typedef struct		s_factoryFuncIngr
{
  funcCreateIngr	func;
}			t_factoryFuncIngr;

typedef IPizza  	*(*funcCreatePizza)(TaillePizza);

typedef struct		s_factoryFuncPizza
{
  funcCreatePizza	func;
}			t_factoryFuncPizza;

#endif
