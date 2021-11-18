/* Definition of Class Library */
#include "Library.h"
Library::Library() {}
Library::~Library() {}
Library library;

/* get_data() reads data from the file and stores to the vector of book */
void Library::get_data(void) {
  system("cls");
  fstream fileStream;
  fileStream.open("./book_data.txt", ios::in);

  if (!fileStream) {
    cout << "No such file " << endl;
  }
  else {
    string book_details;
    char details_of_book[40];
    while (getline(fileStream, book_details)){
      
      strcpy_s(details_of_book, book_details.c_str());
      char* book_info_segment=strtok(details_of_book, " ");

      int loop_count = 1;  
      Book book_object;
      while (book_info_segment) {     
        if(loop_count==1) book_object.book_id = book_info_segment;
        if (loop_count == 2) book_object.book_name = book_info_segment;
        if (loop_count == 3) book_object.book_author = book_info_segment;
        if (loop_count == 4) {
          book_object.is_available = book_info_segment;
          vector_books.push_back(book_object);
        }
        book_info_segment = strtok(NULL, " ");
        loop_count++;
      }     
    }
  }
  fileStream.close();
}

/* list_boooks() list out all the books from the vector of book */
void Library::list_books(void) {
  system("cls");
  for (auto vector_iterator : vector_books) {
    cout << " " << vector_iterator.book_id << " " << vector_iterator.book_name << " " 
      << vector_iterator.book_author << " " << vector_iterator.is_available << endl;
  }
}

/* search_book() searches for a particular book by providing
book name or book id */
void Library::search_book(void) {
  system("cls");
  cout << "Enter the name or ID of the book : ";
  string search_book;
  bool isbook_available = false;
  cin >> search_book;
  for (auto vector_iterator : vector_books) {
    if ((vector_iterator.book_id == search_book) || (vector_iterator.book_name == search_book)) {
      isbook_available = true;
    }
  }
  if (isbook_available)  cout << "Book found" << endl;
  else cout << "Book not found" << endl;
}

/* add_book() adds a book to the vector of book by providing the 
book id, book name, book auhtor */
void Library::add_book(void) {
  Book book;
  system("cls");
  cout << "Enter book id: ";
  cin >> book.book_id;
  cout << "Enter book name: ";
  cin >> book.book_name;
  cout << "Enter author name: ";
  cin >> book.book_author;
  book.is_available = false;
  vector_books.push_back(book);
  write_to_file();
  cout << "Book added successfully " << endl;
}

/* borrow_boook() allows to borow a book from the vector of book and 
update the availability of book to borrow */
void Library::borrow_book(string borrow_book_name) {
  system("cls");
  bool availableTo_borrow = false;
  for (unsigned vector_index = 0; vector_index < vector_books.size(); vector_index++) {
    if (vector_books[vector_index].book_name == borrow_book_name) {
      cout << "is available : " << vector_books[vector_index].is_available << endl;
      if (vector_books[vector_index].is_available == false) {
        vector_books[vector_index].is_available = true;
        availableTo_borrow = true;
      }
      else cout << "Book not available for borrow " << endl;
    }
  }
  if (availableTo_borrow) {
    write_to_file();
    cout << "Book borrowed successfully " << endl;
  }
}

/* write_to_file() write the datas in the vector of book to the file */
void Library::write_to_file(void) {
  fstream fileStream;
  fileStream.open("./book_data.txt", ios::out);
  if (!fileStream) {
    cout << "No such file " << endl;
  }
  else {
    for (auto vector_iterator : vector_books) {
      fileStream << " " << vector_iterator.book_id << " ";
      fileStream << vector_iterator.book_name << " ";
      fileStream << vector_iterator.book_author << " ";
      fileStream << vector_iterator.is_available << " ";
      fileStream << "\n";
    }
    fileStream.close();
  }
}
