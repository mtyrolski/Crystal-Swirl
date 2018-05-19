#include <iostream>
#include <SDL.h>
int main(int argc, char **argv)
{
  if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
  { 
    std::cerr << "STD FAILED TO INIT";
  }
  else
  {
    std::cout << "SUCCES" << std::endl;
  }
  return 0;
}