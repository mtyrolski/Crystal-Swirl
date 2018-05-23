/*
mvxxx 2018
https://github.com/mvxxx
*/
#pragma once
#include <random>

/*
 * Class which is used to compute more complex things
 */
class Math
{
public:

  /*
   * Returns random value from "from" to "to"
   */
  static int random(int from, int to)
  {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(from, to);

    return dis(gen);
  }
};