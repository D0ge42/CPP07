#include "Array.hpp"
#include <iostream>
#include <ostream>

int main()
{

  //################################################################################################//

  std::cout << "\n\033[1;92mCreating a template class that takes int type and creates an array of 5 items\033[0m ✅" << std::endl;
  Array<int > item(5);

  for (unsigned int i = 0; i < item.size(); i++)
  {
    item[i] = i;
    std::cout << item[i];
  }

  std::cout << std::endl;

  //################################################################################################//

  std::cout << "\n\033[1;92mCreating a template class that takes char type and creates an array of 5 items\033[0m ✅" << std::endl;

  Array<char> item2(5);

  for (unsigned int i = 0; i < item.size(); i++)
  {
    item2[i] = item[i] + 48;
    std::cout << "'" << item2[i] << "'";
      if (i < item.size() - 1)
        std::cout << ",";
  }


  //################################################################################################//
  std::cout << "\n\n\033[1;93mTrying to access -1 index of the array⛔ \033[0m" << std::endl;
  try
  {
    std::cout << item[-42] << std::endl;
  }
  catch (const Array<int>::OutOfBoundsException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //################################################################################################//
  std::cout << "\n\033[1;94mCopy assignment test ⚙️ \033[0m" << std::endl;

  Array<int> test(5);
  test = item;

  for (unsigned int i = 0; i < test.size(); i++)
  {
    std::cout << test[i];
  }
  std::cout << "\n\n";

  //################################################################################################//

  std::cout << "\n\033[1;94mCopy constructor  test ⚙️ \033[0m" << std::endl;

  Array<int>test3(test);

  for (unsigned int i = 0; i < test3.size(); i++)
  {
    test3[i] = i;
    std::cout << test3[i];
  }
  std::cout << std::endl;
}
