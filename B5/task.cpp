#include "task.hpp"

int readKey(std::istringstream & iss)
{
  int intKey = 0;
  iss >> intKey;

  if ((intKey < -5) || (intKey > 5))
  {
    throw std::invalid_argument("Invalid key data;\n");
  }
  return intKey;
}

std::string readString(std::istringstream & iss)
{
  iss >> std::ws;
  std::string string;
  std::getline(iss, string);

  if (string.empty())
  {
    throw std::invalid_argument("Invalid string data;\n");
  }

  return string;
}

std::vector<DataStruct> readVector()
{
  std::vector<DataStruct> vector;

  std::string currentLine;
  while (std::getline(std::cin, currentLine))
  {
    std::istringstream iss(currentLine);

    const int key1 = readKey(iss);
    iss.ignore(currentLine.length(), ',');
    const int key2 = readKey(iss);
    iss.ignore(currentLine.length(), ',');

    std::string string = readString(iss);

    vector.push_back({key1, key2, string});
  }
  return vector;
}

bool myCmp(const DataStruct & struct1, const DataStruct & struct2)
{
  if (struct1.key1 != struct2.key1)
  {
    return struct1.key1 < struct2.key1;
  } 
  else if (struct1.key2 != struct2.key2)
  {
    return struct1.key2 < struct2.key2;
  } 
  else 
  {
    return struct1.str.size() < struct2.str.size();
  }
}

void task()
{
  std::vector<DataStruct> vector = readVector();
  std::sort(vector.begin(), vector.end(), myCmp);

  for (auto &it : vector) 
  {
    std::cout << it.key1 << "," << it.key2 << "," << it.str << "\n";
  }
}
