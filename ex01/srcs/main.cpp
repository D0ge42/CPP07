#include "iter.hpp"
#include <iostream>

void convert(int x);

int main( void )
{
  int *array = new int[10];
  for (int i = 0; i < 10 ; i++)
    array[i] = i;
  std::cout << "\033[1;91mArray before template function\033[0m" << std::endl;
  for (int i = 0; i < 10 ; i++)
    std::cout << array[i] << std::endl;
  std::cout << "\033[1;94mArray after template function \033[0m" << std::endl;
  ::iter(array, 10, convert);
}

void convert(int x)
{
  int y = 48;
  int sum = x + static_cast<int>(y);
  std::cout << sum << std::endl;
}
