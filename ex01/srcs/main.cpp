#include "iter.hpp"
#include <iostream>

void convert(int x);

int main( void )
{
  int *array = new int[10];
  for (int i = 0; i < 10 ; i++)
    array[i] = i;
  ::iter(array, 10, convert);
}

void convert(int x)
{
  int y = 48;
  int sum = x + static_cast<int>(y);
  std::cout << sum << std::endl;
}
