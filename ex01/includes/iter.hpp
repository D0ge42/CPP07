#pragma once

template<typename T>
void iter(T *x, int y, void (foo)(T))
{
  for (int i = 0; i < y; i ++)
  {
    foo(*x);
    x++;
  }
}

