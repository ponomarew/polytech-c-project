#ifndef QUEUEWITHPRIORITY_HPP
#define QUEUEWITHPRIORITY_HPP

#include <list>
#include <array>
#include <stdexcept>
#include <algorithm>

template<class T>
class QueueWithPriority
{
public:
  enum Priority
  {
    LOW,
    NORMAL,
    HIGH
  };

  void put(const T &element, const Priority priority = Priority::LOW);

  void accelerate();

  bool empty() const;

  void clear();

  template<class Functor>
  bool process(Functor functor);

  void pop();

private:
  std::array<std::list<T>, 3> arrayOfElements_;

  template<class Functor>
  void workWithElement(const Priority priority, Functor &functor);
};


template<class T>
void QueueWithPriority<T>::put(const T &element, const Priority priority)
{
  arrayOfElements_[priority].push_back(element);
}

template<class T>
void QueueWithPriority<T>::accelerate()
{
  arrayOfElements_[Priority::HIGH].splice(arrayOfElements_[Priority::HIGH].end(), arrayOfElements_[Priority::LOW]);
}

template<class T>
bool QueueWithPriority<T>::empty() const
{
  for (std::size_t i = 0; i < arrayOfElements_.size(); ++i) {
    if (!arrayOfElements_[i].empty()) {
      return false;
    }
  }
  return true;
}

template<class T>
template<class Functor>
bool QueueWithPriority<T>::process(Functor functor)
{
  if (empty()) {
    return false;
  }
  Priority priority = Priority::LOW;
  if (!arrayOfElements_[Priority::HIGH].empty()) {
    priority = Priority::HIGH;
  } else if (!arrayOfElements_[Priority::NORMAL].empty()) {
    priority = Priority::NORMAL;
  }
  workWithElement(priority, functor);
  return true;
}

template<class T>
void QueueWithPriority<T>::clear()
{
  for (unsigned int i = 0; i < arrayOfElements_.size(); i++) {
    arrayOfElements_[i].clear();
  }
}

template<class T>
void QueueWithPriority<T>::pop()
{
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  Priority priority = Priority::LOW;
  if (!arrayOfElements_[Priority::HIGH].empty()) {
    priority = Priority::HIGH;
  } else if (!arrayOfElements_[Priority::NORMAL].empty()) {
    priority = Priority::HIGH;
  }
  arrayOfElements_[priority].pop_front();
}

template<class T>
template<class Functor>
void QueueWithPriority<T>::workWithElement(const Priority priority, Functor &functor)
{
  T t = arrayOfElements_[priority].front();
  arrayOfElements_[priority].pop_front();
  functor(t);
}


#endif

