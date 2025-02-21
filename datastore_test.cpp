#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include "movie.h"
#include "book.h"
#include "product.h"
#include "clothing.h"
#include "mydatastore.h"

using namespace std;

int main(int argc, char* argv[])
{
    MyDataStore st;
    
    // add products
    st.addProduct(new Book("book", "Data Abstraction & Problem Solving with C++", 79.99, 20, "978-013292372-9", "Carrano and Henry"));
    st.addProduct(new Book("book", "Great Men and Women of Troy", 19.50, 5, "978-000000000-1", "Tommy Trojan"));
    st.addProduct(new Clothing("clothing", "Men's Fitted Shirt", 39.99, 25, "Medium", "J. Crew"));
    st.addProduct(new Movie("movie", "Hidden Figures DVD", 17.99, 1, "Drama", "PG"));
    
    // add users
    st.addUser(new User("aturing", 100.00, 0));
    st.addUser(new User("johnvn", 50.00, 1));
    st.addUser(new User("adal", 120.00, 1));

    // optional: add some output to verify
    std::cout << "Products and users added successfully." << std::endl;

    std::vector<std::string> keywords = {"Men's", "Shirt"};
    std::vector<Product*> out = st.search(keywords, 0);

    std::cout << "\n\nmatches begin" << std::endl;
    std::vector<Product*>::iterator prod;
    for(prod = out.begin(); prod != out.end(); ++prod){
        cout << "prod match: " <<  (*prod)->getName() << endl;
    }
    std::cout << "matches ended\n\n" << std::endl;

    st.dump(std::cout);

    return 0;
}