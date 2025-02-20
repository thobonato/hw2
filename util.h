#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> st;
    std::set<int>::iterator it;
    std::set<int>::iterator it2;

    // iterate through s1
    for(it = s1.begin(); it != s1.end(); ++it){
        // look for it in s2, if there, add it in.
        it2 = s2.find(*it);
        if(it2 != s2.end()){
            // found it, so add to st
            st.insert(*it);
        }    
    }
    // iterate through s2
    for(it = s2.begin(); it != s2.end(); ++it){
        // look for it in s1, if there, add it in.
        it2 = s1.find(*it);
        if(it2 != s1.end()){
            // found it, so add to st
            st.insert(*it);
        }    
    }

    return st;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T> st;
    typename std::set<T>::iterator it;

     // iterate through s1
     for(it = s1.begin(); it != s1.end(); ++it){
        // try adding it in
        st.insert(*it);
    }

    // iterate through s2
    for(it = s2.begin(); it != s2.end(); ++it){
        // try adding it in
        st.insert(*it);
    }
    return st; 
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
