#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
    Product::Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}

std::string Movie::getGenre() const
{
    return genre_;
}

std::string Movie::getRating() const
{
    return rating_;
}

std::set<std::string> Movie::keywords() const
{
    return parseStringToWords(displayString());
}

std::string Movie::displayString() const
{
    std::string st = getName() + "\nGenre: " + getGenre() + " Rating: " 
        + getRating() + " \n" + to_string(getPrice()) 
        + " " + to_string(getQty()) + " left.";
    return st;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */

void Movie::dump(std::ostream& os) const
{
    Product::dump(os);
    os << genre_ << "\n" << rating_ << endl;
}



