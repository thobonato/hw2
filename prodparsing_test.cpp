#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "util.h"
#include "product_parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    ProductBookParser bk;
    bool error;
    std::string errorMsg;
    int lineno;

    Product* out;

    string input = "Data Abstraction & Problem Solving with C++ \n 79.99 \n 20 \n 978-013292372-9 \n Carrano and Henry";
    istringstream iss(input);

    out = bk.parse("book", iss, error, errorMsg, lineno);
    if (error) {
        cout << "Error at line " << lineno << ": " << errorMsg << endl;
    } else {
        cout << "Parsed successfully." << endl;
    }

    cout << out->displayString() << endl;
    
    return 0;
}
