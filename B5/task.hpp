#ifndef B5_TASK_HPP
#define B5_TASK_HPP

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <locale>
#include <iostream>


struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

int readKey(std::istringstream & iss);
std::string readString(std::istringstream & iss);
std::vector<DataStruct> readVector();

bool myCmp(const DataStruct & struct1, const DataStruct & struct2);

void task();

#endif //B5_TASK_HPP
