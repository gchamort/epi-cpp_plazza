//
// Factory.cpp for Factory.cpp in /home/chauch_a/rendu/cpp_plazza
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Wed Apr 23 14:49:28 2014 CHAUCHET Alan
// Last update Wed Apr 23 15:28:45 2014 CHAUCHET Alan
//

#include		"Factory.hh"

static t_factoryFuncIngr	g_factoryFuncIngr[9] =
  {
    {&Factory::createChiefLove},
    {&Factory::createDoe},
    {&Factory::createEggPlant},
    {&Factory::createGoatCheese},
    {&Factory::createGruyere},
    {&Factory::createHam},
    {&Factory::createMushrooms},
    {&Factory::createSteak},
    {&Factory::createTomato}
  };

static t_factoryFuncPizza	g_factoryFuncPizza[4] =
  {
    {&Factory::createRegina},
    {&Factory::createMargarita},
    {&Factory::createAmericana},
    {&Factory::createFantasia}
  };

template<typename X>
IIngr			*Factory::createIIngr(int qtt)
{
  return (new X(qtt));
}

IIngr			*Factory::createChiefLove(int qtt)
{
  return (Factory::createIIngr<ChiefLove>(qtt));
}

IIngr			*Factory::createDoe(int qtt)
{
  return (Factory::createIIngr<Doe>(qtt));
}

IIngr			*Factory::createEggPlant(int qtt)
{
  return (Factory::createIIngr<EggPlant>(qtt));
}

IIngr			*Factory::createGoatCheese(int qtt)
{
  return (Factory::createIIngr<GoatCheese>(qtt));
}

IIngr			*Factory::createGruyere(int qtt)
{
  return (Factory::createIIngr<Gruyere>(qtt));
}

IIngr			*Factory::createHam(int qtt)
{
  return (Factory::createIIngr<Ham>(qtt));
}

IIngr			*Factory::createMushrooms(int qtt)
{
  return (Factory::createIIngr<Mushrooms>(qtt));
}

IIngr			*Factory::createSteak(int qtt)
{
  return (Factory::createIIngr<Steak>(qtt));
}

IIngr			*Factory::createTomato(int qtt)
{
  return (Factory::createIIngr<Tomato>(qtt));
}

IIngr			*Factory::createIngr(e_ingr type, int qtt)
{
  return ((g_factoryFuncIngr[(static_cast<int>(type))].func)(qtt));
}

template<typename X>
IPizza			*Factory::createIPizza(TaillePizza size)
{
  return (new X(size));
}

IPizza			*Factory::createRegina(TaillePizza size)
{
  return (Factory::createIPizza<Regina>(size));
}

IPizza			*Factory::createMargarita(TaillePizza size)
{
  return (Factory::createIPizza<Margarita>(size));
}

IPizza			*Factory::createAmericana(TaillePizza size)
{
  return (Factory::createIPizza<Americana>(size));
}

IPizza			*Factory::createFantasia(TaillePizza size)
{
  return (Factory::createIPizza<Fantasia>(size));
}

IPizza			*Factory::createPizza(TypePizza type, TaillePizza size)
{
  int			count = static_cast<int>(type) - 1;

  count = ((count == 3) ? 2 : count);
  count = ((count == 7) ? 3 : count);
  return ((g_factoryFuncPizza[count].func)(size));
}
