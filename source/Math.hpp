/*
mvxxx 2018
https://github.com/mvxxx
*/
#include <random>
class Math
{
public:
  static int random(int from, int to)
  {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(from, to);

    return dis(gen);
  }
};