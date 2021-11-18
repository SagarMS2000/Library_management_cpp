#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Book.h"

using namespace std;
class Library
{
private:
	vector<Book>vector_books;
public:
	Library();
	~Library();
	void get_data(void);
	void write_to_file(void);
	void list_books(void);
	void add_book(void);
	void search_book(void);
	void borrow_book(string);
};

