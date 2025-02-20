#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author) :
    Product::Product(category, name, price, qty),
    ISBN_(ISBN),
    author_(author)
{

}

Book::~Book()
{

}

std::string Book::getISBN() const
{
    return ISBN_;
}

std::string Book::getAuthor() const
{
    return author_;
}

std::set<std::string> Book::keywords() const
{
    return parseStringToWords(displayString());
}

std::string Book::displayString() const
{
    std::string st = getName() + "\nAuthor: " + getAuthor() + " ISBN: " 
        + getISBN() + " \n" + to_string(getPrice()) 
        + " " + to_string(getQty()) + " left.";
    return st;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */

void Book::dump(std::ostream& os) const
{
    Product::dump(os);
    os << ISBN_ << "\n" << author_ << endl;
}



