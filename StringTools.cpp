//----------------------------------------------------------------------------------------------------------------------
//                                                   String Tools
//----------------------------------------------------------------------------------------------------------------------
#include "StringTools.h"
#include <stdlib.h>
#include <set>
#include <iostream>

namespace string_tools {
    // TODO: PICK UP HERE: Move Google tests to this folder

    // This function is more or less copied from: https://www.delftstack.com/howto/cpp/cpp-split-string-by-space/
    std::vector<std::string> split_on_whitespace(std::string text) {
        std::string delimiter = " ";
        std::vector<std::string> words{};
        size_t pos = 0;
        while ((pos = text.find(delimiter)) != std::string::npos) {
            words.push_back(text.substr(0, pos));
            text.erase(0, pos + delimiter.length());
        }

        if (text.size() > 0) {
            words.push_back(text.substr(0, text.size()));
        }
        return words;
    }

    bool str_in_set(std::set<std::string> set_to_search, std::string string_to_find) {
        return (set_to_search.find(string_to_find) != set_to_search.end());
    }

    bool is_integer(const std::string s) {
        if (s.size() == 0) {
            return false;
        } else if ((s == "+") || (s == "-")) {
            return false;
        }
        std::string first_digit = s.substr(0, 1);
        std::string rest;
        if (s.size() > 1) {
            rest = s.substr(1, s.npos);
        } else {
            rest = "";
        }
        bool first_digit_good = (first_digit.find_first_not_of("0123456789+-") == first_digit.npos);
        bool other_digits_good = (rest.find_first_not_of("0123456789") == rest.npos);
        if (s.size() == 1) {
            return first_digit_good;
        }
        return (first_digit_good && other_digits_good);
    }


    //------------------------------------------------------------------------------------------------------------------
    //                                              Convert String to Char*
    //
    // Converts an instance of std::string to a zero-terminated string and returns a pointer to that string.
    //
    // Pros: Memory allocated is guaranteed to be large enough to store your string. You can pass in a pointer, but then
    // this function would have no way to know whether it is bulldozing over something else. You can check the size of
    // the string before calling this function, but then you would have to write the same code in multiple places.
    //
    // Cons: This function uses malloc, so you have to free the result when you're done using it.
    //
    //------------------------------------------------------------------------------------------------------------------
    char* string2CharArray(std::string s) {
        char *charArray = (char*) malloc(sizeof(char)*(s.size()+1));
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size()) {
                charArray[i] = s.at(i);
            } else {
                charArray[i] = (char) 0;
            }
        }
        return charArray;
    }
}
