#include <iostream>
#include <ostream>
#include <stdexcept>
#include <list>
#include <iterator>
#include <algorithm>

constexpr int begin = 1;
constexpr int end = 20;
constexpr std::size_t maxSize = 20;

namespace detail
{
  template<class Iterator>
  void printIterators(Iterator &first, Iterator &last, std::ostream &ostream)
  {
    if (first == last) {
      return;
    }
    ostream << *first;
    first++;
    if (first == last) {
      ostream << ' ' << *last;
      return;
    }
    ostream << ' ' << *last;
    last--;
    if (first != last) {
      ostream << ' ';
      printIterators(first, last, ostream);
    }
  }
}
namespace Programs
{
  void situation2(std::istream &istream, std::ostream &ostream)
  {
    std::list<int> list;

    std::transform(std::istream_iterator<int>(istream), std::istream_iterator<int>(),
                   std::insert_iterator<std::list<int>>(list, list.begin()), [](int i)
                   {
                     if (!(i >= begin && i <= end)) {
                       throw std::invalid_argument(
                         "number must be >=" + std::to_string(begin) + " && <=" + std::to_string(end));
                     }
                     return i;
                   });
    if (!istream.eof() && (istream.bad() || istream.fail())) {
      throw std::ios_base::failure("problem at reading data");
    }
    if (list.empty()) {
      return;
    }
    if (list.size() > maxSize) {
      throw std::out_of_range("too much numbers");
    }
    std::list<int>::iterator iBegin = list.begin();
    std::list<int>::iterator iEnd = --list.end();
    detail::printIterators(iBegin, iEnd, ostream);

    if (list.size() % 2 != 0) {
      if (list.size() != 1) {
        ostream << ' ';
      }
      ostream << *iBegin;
    }
    ostream << '\n';
  }

}

