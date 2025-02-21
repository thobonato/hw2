#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{   
    set<string> words;
    std::string word = "";

    std::string rawIn = trim(rawWords);
    std::string::iterator it;
    
    // iterate through rawWords char's
    for(it = rawIn.begin(); it != rawIn.end(); ++it){
        // has punctuation or is space, must start new word
        if((std::ispunct(*it) && *it != '-') || std::isspace(*it)){
            // if word len > 1, then add to set
            if(word.length() > 1){
                words.insert(word);
                word = "";
            }
            word = "";
        } else {
            word.push_back(*it);
        }
    }

    // final word check
    if(word.length() > 1){
        words.insert(word);
        word = "";
    }

    return words;
}

// For the product name, book author, and clothing brand we define a keyword to be any string of 2 or more characters. If such a word has punctuation it should be split at each punctuation character and the resulting substrings (of 2 or more characters) should be used as keywords. Here are some examples:
// Men's should yield just a keyword of Men
// J. would not yield any keyword since the remaining substring J is only 1 character
// I'll would yield just ll since that substring is 2 or more characters (this is obviously a poor keyword but we’ll follow this rule for simplicity)

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
