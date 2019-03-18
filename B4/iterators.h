#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include <iterator>

class FactorialContainer
{
public:
  class Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
  {
  public:
    Iterator();
    Iterator(size_t pos, size_t value);
    Iterator(const Iterator &obj) = default;

    const size_t* operator->() const noexcept;
    const size_t& operator*() const noexcept;

    Iterator& operator ++() noexcept;
    Iterator operator++(int) noexcept;
    Iterator& operator--() noexcept;
    Iterator operator--(int) noexcept;

    bool operator==(const Iterator& rhs) const noexcept;
    bool operator!=(const Iterator& rhs) const noexcept;

    Iterator& operator=(const Iterator &obj) = default;

  private:
    size_t pos_, val_;
  };

  FactorialContainer() = default;
  Iterator begin() noexcept;
  Iterator end() noexcept;
};

#endif // !_ITERATOR_H_
