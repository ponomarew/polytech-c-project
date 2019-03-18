#include "task.hpp"

int task()
{
  Functor functor;
  std::for_each(std::istream_iterator<long long int>(std::cin),
                std::istream_iterator<long long int>(), std::ref(functor));

  if (!std::cin.eof())
  {
    std::cerr <<"Invalid input data" << "\n";
    return 1;
  }

  if (functor.isEmpty()){
    std::cout << "No Data\n";
    return 0;
  }

  std::cout.precision(1);

  std::cout << "Max: " << functor.getMaxNumber() << "\n";
  std::cout << "Min: " << functor.getMinNumber() << "\n";
  std::cout << "Mean: " << std::fixed << functor.getAverageNumber() << "\n";
  std::cout << "Positive: " << functor.getNumOfPositive() << "\n";
  std::cout << "Negative: " << functor.getNumOfNegative() << "\n";
  std::cout << "Odd Sum: " << functor.getOddSum() << "\n";
  std::cout << "Even Sum: " << functor.getEvenSum() << "\n";
  std::cout << "First/Last Equal: ";

  if (functor.isFirstEqLast()){
    std::cout << "yes\n";
  } else {
    std::cout << "no\n";
  }

  return 0;
};
