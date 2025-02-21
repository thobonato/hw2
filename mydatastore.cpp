#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "util.h"
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() 
{
    std::vector<User*> users_;
    std::vector<Product*> products_;
    std::map<User*, std::vector<Product*>> cart_;
}

MyDataStore::~MyDataStore() 
{
    // deallocate users_
    std::vector<User*>::iterator user;
    for(user = users_.begin(); user != users_.end(); ++user){
        delete (*user);
    }
    
    // deallocate products_
    std::vector<Product*>::iterator prod;
    for(prod = products_.begin(); prod != products_.end(); ++prod){
        delete (*prod);
    }
    #ifdef DEBUG
    std::cout << "deleted all" << std::endl;
    #endif
}

void MyDataStore::addProduct(Product* p)
{
    products_.push_back(p);
}

void MyDataStore::addUser(User* u)
{
    users_.push_back(u);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<std::set<Product*>> all_sets;

    // iterate through each term
    std::vector<std::string>::iterator term;
    for(term = terms.begin(); term != terms.end(); ++term)
    {   
        // new_set for this term
        std::set<Product*> new_set;

        // iterate through all products
        std::vector<Product*>::iterator prod;
        for(prod = products_.begin(); prod != products_.end(); ++prod){
            // find intersection between the curr product's keywords and the intended key words
            std::set<std::string> kwrds = (*prod)->keywords();
            
            // if that term ins in the keywords, add it to the set
            if(kwrds.find(convToLower(*term)) != kwrds.end()){

                // adding to set:
                new_set.insert(*prod);
            }
        }

        // if set not empty, add to all_sets
        if(!new_set.empty()){
            all_sets.push_back(new_set);
        }
    }
    
    if (all_sets.empty()) {
        return std::vector<Product*>();
    }

    std::vector<std::set<Product*>>::iterator it = all_sets.begin();
    std::set<Product*> res = (*it);
    ++it;
    
    // take intersection or union of all sets
    for(; it != all_sets.end(); ++it){
        if(type == 0){
            res = setIntersection((*it), res);
        } else {
            res = setUnion((*it), res);
        }
    }

    // convert to vec
    std::vector<Product*> res_vec(res.begin(), res.end());
    return res_vec;
}

void MyDataStore::dump(std::ostream& ofile)
{
    // cout to ofile <products>
    ofile << "<products>" << endl;
    // iterate through products and dump
    std::vector<Product*>::iterator prod;
    for(prod = products_.begin(); prod != products_.end(); ++prod){
        (*prod)->dump(ofile);
    }

    // cout to ofile </products>
    ofile << "</products>" << endl;
    
    // cout to ofile <users>
    ofile << "<users>" << endl;
    // iterate through users and dump
    std::vector<User*>::iterator user;
    for(user = users_.begin(); user != users_.end(); ++user){
        (*user)->dump(ofile);
    }
    
    // cout to ofile </users>
    ofile << "</users>" << endl;
}

std::string MyDataStore::addToCart(std::string username, Product* prod){
    // if is not in users
    User* u = nullptr;
    std::vector<User*>::iterator user;
    for(user = users_.begin(); user != users_.end(); ++user){
        if((*user)->getName() == username){
            u = (*user);
            break;
        }
    }

    if(u == nullptr){
        return "Invalid username";
    }
    
    // if they don't have a cart
    if(cart_.find(u) == cart_.end()){
        // create empty cart
        cart_[u] = std::vector<Product*>();
    }
    cart_[u].push_back(prod);
    return "";
}

std::string MyDataStore::viewCart(std::string username){
    // if is not in users
    User* u = nullptr;
    std::vector<User*>::iterator user;
    for(user = users_.begin(); user != users_.end(); ++user){
        if((*user)->getName() == username){
            u = (*user);
            break;
        }
    }

    if(u == nullptr){
        return "Invalid username";
    }
    
    // if they have a cart
    std::string res;
    if(cart_.find(u) != cart_.end()){
        // iterate through empty carts and send out the dump of them
        std::vector<Product*>& userCart = cart_[u];
        std::vector<Product*>::iterator prod;
        for(prod = userCart.begin(); prod != userCart.end(); ++prod)
        {
            res += (*prod)->displayString() + "\n";
        }
    }
    return res;
}

std::string MyDataStore::buyCart(std::string username){
    // if is not in users
    User* u = nullptr;
    std::vector<User*>::iterator user;
    for(user = users_.begin(); user != users_.end(); ++user){
        if((*user)->getName() == username){
            u = (*user);
            break;
        }
    }

    if(u == nullptr){
        return "Invalid username";
    }
    
    // check their pending cart
    if(cart_.find(u) != cart_.end()){
        std::vector<Product*>& userCart = cart_[u];
        // buy it out one by one
        std::vector<Product*>::iterator prod;
        std::vector<Product*> newCart;
        for(prod = userCart.begin(); prod != userCart.end(); ++prod){
            // check for insufficient funds!!
            if (u->getBalance() > (*prod)->getPrice()){
                // decrease number of available items of that product
                (*prod)->subtractQty(1);
                // decrease the user's cash balance
                u->deductAmount((*prod)->getPrice());
            }
            else {
                // couldn't buy, add to newCart
                newCart.push_back(*prod);
            }
        }
        cart_[u] = newCart;
    }
    return "";
}

