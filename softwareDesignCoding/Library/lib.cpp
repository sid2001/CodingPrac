#include <vector>
#include <string>
using namespace std;

struct Book {
  int pages;
  string title;
  string author;
  string issuedBy;
  bool available;
};

class Library {
  struct Collection{
    vector<Book> books;
    int count;
  }
  // vector<int> getBooks
}