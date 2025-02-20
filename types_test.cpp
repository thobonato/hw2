#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include "movie.h"
#include "book.h"
#include "product.h"
#include "clothing.h"

using namespace std;

int main(int argc, char* argv[])
{
    Clothing bk = Clothing("movie", "Data Abstraction & Problem Solving with C++", 79.99, 20, "978-013292372-9", "Carrano and Henry");
    cout << bk.displayString();
    std::cout << "\n\n\n" << endl;
    std::set<std::string> st = bk.keywords();
    for (std::set<std::string>::iterator it = st.begin();
        it != st.end();
        ++it)
        std::cout << *it << ", ";

    return 0;
}
