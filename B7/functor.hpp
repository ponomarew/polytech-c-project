#ifndef B7_FUNCTOR_HPP
#define B7_FUNCTOR_HPP

#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

class Functor{
public:
  void operator()(const int &number);

  int getMaxNumber() const;
  int getMinNumber() const;
  double getAverageNumber() const;

  int getNumOfPositive() const;
  int getNumOfNegative() const;

  long long int getEvenSum() const;
  long long int getOddSum() const;

  bool isFirstEqLast() const;

  bool isEmpty() const;

private:
  std::vector< int > numbers_;
};

bool isPositive(const int &x);
bool isNegative(const int &x);

#endif //B7_FUNCTOR_HPP
