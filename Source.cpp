/* main program to run the library mangement system */
#include "Library.h"

int main()
{
  int switch_opt;
  string book_name_to_borrow;
  Library library_object;
  library_object.get_data();
  
  cout << "********************* Welcome To Library Management System ********************" << endl;
  while (1)
  {
    cout << "Enter the choice " << endl;
    cout << "1. Add Book" << endl;
    cout << "2. List Books" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Borrow Book" << endl;
    cout << "5. Exit" << endl;
    cin >> switch_opt;
    switch (switch_opt) {
    case 1: library_object.add_book();
      break;
    case 2: library_object.list_books();
      break;
    case 3: library_object.search_book();
      break;
    case 4: cout << "Enter the nam eof the book : ";
      cin >> book_name_to_borrow;
      library_object.borrow_book(book_name_to_borrow);
      break;
    case 5: exit(0);
    }
  }
  return 0;
}