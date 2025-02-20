#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include "util.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::set<int> vec = {1, 2, 3};
    std::set<int> vec2 = {3, 4, 5};
    
    std::set<int> out = setUnion<int>(vec, vec2);

    for (std::set<int>::iterator it = out.begin();
        it != out.end();
        ++it)
        std::cout << *it << ", ";

    std::cout << std::endl;
    out = setIntersection<int>(vec, vec2);

    for (std::set<int>::iterator it = out.begin();
        it != out.end();
        ++it)
        std::cout << *it << ", ";

    std::cout << std::endl;
    return 0;
}
