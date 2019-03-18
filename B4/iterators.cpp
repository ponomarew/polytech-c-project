#include "iterators.h"

FactorialContainer::Iterator::Iterator() :Iterator(1, 1)
{
}

FactorialContainer::Iterator::Iterator(size_t pos, size_t value) : pos_(pos), val_(value)
{
}

const size_t * FactorialContainer::Iterator::operator->() const noexcept
{
  return &val_;
}

const size_t & FactorialContainer::Iterator::operator*() const noexcept
{
  return val_;
}

FactorialContainer::Iterator & FactorialContainer::Iterator::operator++() noexcept
{
  if (pos_ < 11)
  {
    ++pos_;
    val_ *= pos_;
  }
  return *this;
}

FactorialContainer::Iterator FactorialContainer::Iterator::operator++(int) noexcept
{
  FactorialContainer::Iterator temp = *this;
  ++(*this);
  return temp;
}

FactorialContainer::Iterator & FactorialContainer::Iterator::operator--() noexcept
{
  if (pos_ > 1)
  {
    val_ /= pos_;
    --pos_;
  }
  return *this;
}

FactorialContainer::Iterator FactorialContainer::Iterator::operator--(int) noexcept
{
  FactorialContainer::Iterator temp = *this;
  --(*this);
  return temp;
}

bool FactorialContainer::Iterator::operator==(const Iterator & rhs) const noexcept
{
  return (pos_ == rhs.pos_);
}

bool FactorialContainer::Iterator::operator!=(const Iterator & rhs) const noexcept
{
  return (!(rhs == *this));
}

FactorialContainer::Iterator FactorialContainer::begin() noexcept
{
  return FactorialContainer::Iterator(1, 1);
}

FactorialContainer::Iterator FactorialContainer::end() noexcept
{
  return FactorialContainer::Iterator(11, 39916800);
}
