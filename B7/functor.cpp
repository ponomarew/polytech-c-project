#include "functor.hpp"


void Functor::operator()(const int &number)
{
  numbers_.push_back(number);
}

int Functor::getMaxNumber() const
{
  return (*std::max_element(numbers_.begin(), numbers_.end()));
}

int Functor::getMinNumber() const
{
  return (*std::min_element(numbers_.begin(), numbers_.end()));
}

double Functor::getAverageNumber() const
{
  double averageNumber = 0;
  const size_t vectorSize = numbers_.size();

  for (int number : numbers_) {
    averageNumber += 1.0 * number / vectorSize;
  }
  return averageNumber;
}

int Functor::getNumOfPositive() const
{
  return static_cast<int>(std::count_if(numbers_.begin(), numbers_.end(), isPositive));
}

int Functor::getNumOfNegative() const
{
  return static_cast<int>(std::count_if(numbers_.begin(), numbers_.end(), isNegative));
}

long long int Functor::getEvenSum() const
{
  long long int evenSum = 0;
  for (int number : numbers_) {
    if (number % 2 == 0){
      evenSum += number;
    }
  }
  return evenSum;
}

long long int Functor::getOddSum() const
{
  long long int oddSum = 0;
  for (int number : numbers_) {
    if (number % 2 != 0){
      oddSum += number;
    }
  }
  return oddSum;
}

bool Functor::isFirstEqLast() const
{
  return numbers_.front() == numbers_.back();
}

bool Functor::isEmpty() const
{
  return numbers_.empty();
}

bool isPositive(const int &x)
{
  return x > 0;
}

bool isNegative(const int &x)
{
  return x < 0;
}
