#include "actions.h"

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Must be 1 argument" << std::endl;
      return 1;
    }
    actions(atoi(argv[1]));
  }
  catch (std::exception &exc)
  {
    std::cerr << exc.what() << std::endl;
    return 2;
  }
  return 0;
}
