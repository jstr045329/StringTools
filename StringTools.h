//----------------------------------------------------------------------------------------------------------------------
//                                                   String Tools
//----------------------------------------------------------------------------------------------------------------------
#ifndef FFT_MICROSERVICE_FFT_STRINGTOOLS_H
#define FFT_MICROSERVICE_FFT_STRINGTOOLS_H
#endif //FFT_MICROSERVICE_FFT_STRINGTOOLS_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <set>

namespace string_tools {
    std::vector<std::string> split_on_whitespace(std::string text);
    bool str_in_set(std::set<std::string>, std::string);
    bool is_integer(const std::string s);
    char* string2CharArray(std::string s);
}
