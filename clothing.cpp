#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
    Product::Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::string Clothing::getSize() const
{
    return size_;
}

std::string Clothing::getBrand() const
{
    return brand_;
}

std::set<std::string> Clothing::keywords() const
{
    return parseStringToWords(displayString());
}

std::string Clothing::displayString() const
{
    std::string st = getName() + "\nSize: " + getSize() + " Brand: " 
        + getBrand() + " \n" + to_string(getPrice()) 
        + " " + to_string(getQty()) + " left.";
    return st;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */

void Clothing::dump(std::ostream& os) const
{
    Product::dump(os);
    os << size_ << "\n" << brand_ << endl;
}



