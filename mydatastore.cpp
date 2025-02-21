#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include "util.h"
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() 
{
    std::vector<User*> users_;
    std::vector<Product*> products_;
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
    std::cout << "deleted all" << std::endl;
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
            if(kwrds.find(*term) != kwrds.end()){

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
