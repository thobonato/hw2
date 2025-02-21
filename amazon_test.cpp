#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"
#include "clothing.h"
#include "movie.h"
#include "book.h"

using namespace std;

int main() {
    // create datastore
    MyDataStore ds;

    // create products
    Product* book1 = new Book("book", "Harry Potter", 29.99, 10, "123-456-789", "J.K. Rowling");
    Product* book2 = new Book("book", "The Hobbit", 19.99, 5, "987-654-321", "J.R.R. Tolkien");
    Product* clothing1 = new Clothing("clothing", "T-Shirt", 14.99, 20, "M", "Nike");
    Product* movie1 = new Movie("movie", "Inception", 24.99, 15, "Sci-Fi", "PG-13");

    // create users
    User* user1 = new User("john_doe", 100.0, 0);
    User* user2 = new User("jane_smith", 50.0, 1);

    // add products to datastore
    ds.addProduct(book1);
    ds.addProduct(book2);
    ds.addProduct(clothing1);
    ds.addProduct(movie1);

    // add users to datastore
    ds.addUser(user1);
    ds.addUser(user2);

    // test adding to cart
    ds.addToCart("john_doe", book1);
    ds.addToCart("john_doe", clothing1);
    ds.addToCart("jane_smith", movie1);

    // view carts
    cout << "John's cart:" << endl;
    cout << ds.viewCart("john_doe");
    cout << endl;

    cout << "Jane's cart:" << endl;
    cout << ds.viewCart("jane_smith");
    cout << endl;

    // test buying carts
    cout << "John buying cart:" << endl;
    cout << ds.buyCart("john_doe");
    cout << endl;

    cout << "Jane buying cart:" << endl;
    cout << ds.buyCart("jane_smith");
    cout << endl;

    // // clean up
    // delete book1;
    // delete book2;
    // delete clothing1;
    // delete movie1;
    // delete user1;
    // delete user2;

    return 0;
}