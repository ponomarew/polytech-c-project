#include "actions.h"
#include "iterators.h"
#include "phonebooks.h"
#include "phoneactions.h"

void actions(const int choice)
{
  switch (choice)
  {
  case 1:
  {
    FirstAct();
    break;
  }
  case 2:
  {
    SecondAct();
    break;
  }
  default:
  {
    throw std::invalid_argument("Wrong choice must be 1 or 2");
    break;
  }
  }
}


void FirstAct()
{
  PhoneBook book;
  std::string buffer;
  while (std::getline(std::cin, buffer))
  {
    chooseAction(buffer, book);
  }
}

void SecondAct()
{
  FactorialContainer arr;

  std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
