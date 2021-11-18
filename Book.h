#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Book
{
public:
  string book_name;
  string book_author;
  string book_id;
  bool is_available;
  Book();
  ~Book();
};

