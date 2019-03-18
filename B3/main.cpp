#include <iostream>
#include <stdexcept>
#include "impl.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "must be only one parametr {1|2}\n";
    return 1;
  }
  int i = std::stoi(argv[1]);
  try {
    switch (i) {
      case 1:
        Programs::situation1(std::cin, std::cout);
        break;
      case 2:
        Programs::situation2(std::cin, std::cout);
        break;
      default:
        std::cerr << "parametr must be {1|2}\n";
        return 1;
    }

  } catch (const std::invalid_argument &err) {
    std::cerr << err.what() << '\n';
    return 1;
  } catch (const std::exception &err) {
    std::cerr << err.what() << '\n';
    return 2;
  }


  return 0;
}

