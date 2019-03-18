

#ifndef B3_PARSER_HPP
#define B3_PARSER_HPP

#include <functional>
#include <istream>
#include <ostream>
#include "QueueWithPriority.hpp"

namespace detail
{
  namespace Commands
  {
    template<typename T>
    using command = std::function<void(QueueWithPriority<T> &, std::ostream &)>;

    command<std::string> add(std::istream &istream);

    command <std::string> get(std::istream &);

    command <std::string> accelerate(std::istream &);
  }


  namespace detail
  {
    template<typename T>
    struct comamnd
    {
      const char *name_;
      const std::function<Commands::command<T>(std::istream &)> pars_;
    };
    void invalidCommand(QueueWithPriority<std::string> &, std::ostream &ostream);
  }
}

#endif //B3_PARSER_HPP
