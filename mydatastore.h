#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore: public DataStore {
public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

    std::string addToCart(std::string username, Product* prod);
    
    std::string viewCart(std::string username);

    std::string buyCart(std::string username);

protected:
    std::vector<User*> users_;
    std::vector<Product*> products_;
    std::map<User*, std::vector<Product*>> cart_;
};


#endif