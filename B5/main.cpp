#include "task.hpp"

int main()
{
  try
  {
    task();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
