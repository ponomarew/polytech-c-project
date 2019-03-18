#ifndef _PHONE_BOOK_H_
#define _PHONE_BOOK_H_
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

class PhoneBook
{
public:
  struct PhoneBookRecord
  {
    std::string number, name;
  };

  PhoneBook();
  PhoneBook(const PhoneBook &obj);
  PhoneBook(PhoneBook && obj) = default;

  PhoneBook& operator=(const PhoneBook& obj);
  PhoneBook& operator=(PhoneBook &&obj) = default;

  void addRecord(const PhoneBookRecord & record);
  void addBookmark(const std::string & curr_bookmark, const std::string &new_bookmark);
  void insertBefore(const std::string & bookmark, const PhoneBookRecord &record);
  void insertAfter(const std::string & bookmark, const PhoneBookRecord &record);
  void deleteRecord(const std::string &bookmark);
  void replaceRecord(const std::string &bookmark, const PhoneBookRecord &record);
  void showRecordName(const std::string &bookmark);
  void moveBookmark(const std::string &bookmark, const int pos);
  void moveBookmark(const std::string &bookmark, const std::string &pos);
  void moveToNext(const std::string &bookmark);
  void moveToPrev(const std::string &bookmark);

private:
  struct RecordElem
  {
    PhoneBookRecord rec;
    std::set<std::string> bookmarks;
  };

  using record_type = std::list<RecordElem>;
  using bookmark_type = std::map<std::string, record_type::iterator>;
  using bookmarkIter = bookmark_type::iterator;

  record_type records_;
  bookmark_type bookmarks_;
  bookmarkIter getIterator(const std::string &bookmark);
  void insert(const std::string & bookmark, const PhoneBookRecord & record, const bool is_after);
};

#endif 
