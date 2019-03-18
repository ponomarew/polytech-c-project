#include "phoneactions.h"

std::string readName(std::stringstream &stream)
{
  stream.ignore();
  std::string name;
  std::getline(stream, name);
  if (name.empty())
  {
    return name;
  }

  if ((name.front() != '\"') || (name.back() != '\"'))
  {
    throw std::invalid_argument("");
  }
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  name.erase(0,1);
  name.pop_back();
  return name;
}

std::string readNumber(std::stringstream & stream)
{
  std::string number;
  stream >> number;
  for (auto i : number)
  {
    if (!isdigit(i))
    {
      throw std::invalid_argument("");
    }
  }
  return number;
}

std::string readMarkName(std::stringstream & stream)
{
  std::string mark_name;
  stream >> mark_name;
  for (auto i : mark_name)
  {
    if ((!isalnum(i)) && (i != '-'))
    {
      throw std::invalid_argument("");
    }
  }
  return mark_name;
}

void add(std::stringstream& stream, PhoneBook & book)
{
  std::string number = readNumber(stream);
  std::string name = readName(stream);
  book.addRecord(PhoneBook::PhoneBookRecord{ number,name });
}

void delet(std::stringstream& stream, PhoneBook & book)
{
  std::string mark_name = readMarkName(stream);
  book.deleteRecord(mark_name);
}

void show(std::stringstream& stream, PhoneBook & book)
{
  std::string mark_name = readMarkName(stream);
  book.showRecordName(mark_name);
}

void insert(std::stringstream& stream, PhoneBook & book)
{
  std::string pos;
  stream >> pos;

  if ((pos == "before") || (pos == "after"))
  {
    std::string mark_name = readMarkName(stream);
    std::string number = readNumber(stream);
    std::string name = readName(stream);
    if (pos == "after")
    {
      book.insertAfter(mark_name, PhoneBook::PhoneBookRecord{ number,name });
    }
    else
    {
      book.insertBefore(mark_name, PhoneBook::PhoneBookRecord{ number,name });
    }
  }
  else
  {
    throw std::invalid_argument("");
  }
}

void store(std::stringstream& stream, PhoneBook & book)
{
  std::string old_mark = readMarkName(stream);
  std::string new_mark = readMarkName(stream);
  book.addBookmark(old_mark, new_mark);
}

void move(std::stringstream& stream, PhoneBook & book)
{
  std::string mark_name = readMarkName(stream);
  std::string pos;
  stream >> pos;
  if (pos == "first" || pos == "last")
  {
    book.moveBookmark(mark_name, pos);
  }
  else
  {
    try {
      book.moveBookmark(mark_name, std::stoi(pos));
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID STEP>" << std::endl;
    }
  }
}

void chooseAction(const std::string& line, PhoneBook & book)
{
  try {
    std::stringstream stream(line);
    std::string command;
    stream >> command;
    if (command == "add")
    {
      add(stream, book);
    }
    else if (command == "insert")
    {
      insert(stream, book);
    }
    else if (command == "delete")
    {
      delet(stream, book);
    }
    else if (command == "store")
    {
      store(stream, book);
    }
    else if (command == "move")
    {
      move(stream, book);
    }
    else if (command == "show")
    {
      try {
        show(stream, book);
      }
      catch (std::invalid_argument &)
      {
        std::cout << "<INVALID BOOKMARK>" << std::endl;
      }
    }
    else
    {
      throw std::invalid_argument("");
    }
  }
  catch (std::invalid_argument &)
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
  }
}
