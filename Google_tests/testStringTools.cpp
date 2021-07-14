//----------------------------------------------------------------------------------------------------------------------
//                                                 Test String Tools
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../StringTools.h"


//----------------------------------------------------------------------------------------------------------------------
//                                             Test splitOnWhitespace()
//----------------------------------------------------------------------------------------------------------------------
TEST(StringTools, TestSplitOnWhitespace01) {
    std::string input = "a b c d hi there how are you asdfgh qweruiop qwertyuiop";
    std::vector<std::string> correct_answer {"a", "b", "c", "d", "hi", "there", "how", "are", "you", "asdfgh",
                                             "qweruiop", "qwertyuiop"};
    std::vector<std::string> uut_answer = string_tools::split_on_whitespace(input);
    int points_possible = 0;
    int points_earned = 0;
    for (int i = 0; i < correct_answer.size(); ++i) {
        points_possible++;
        if (correct_answer.at(i).compare(uut_answer.at(i)) == 0) {
            points_earned++;
        }
    }
    ASSERT_EQ(points_possible, points_earned);
}


//----------------------------------------------------------------------------------------------------------------------
//                                                Test stringInSet()
//----------------------------------------------------------------------------------------------------------------------
TEST(StringTools, testStringInSet01) {
    std::set<std::string> my_set {"hi", "bye", "1", "2", "abc", "xyz"};
    ASSERT_TRUE(string_tools::str_in_set(my_set, "hi"));
    ASSERT_FALSE(string_tools::str_in_set(my_set, "def"));
    ASSERT_TRUE(string_tools::str_in_set(my_set, "2"));
    ASSERT_FALSE(string_tools::str_in_set(my_set, "q"));
    ASSERT_TRUE(string_tools::str_in_set(my_set, "xyz"));
    ASSERT_FALSE(string_tools::str_in_set(my_set, "23498273489"));
    ASSERT_TRUE(string_tools::str_in_set(my_set, "bye"));
    ASSERT_FALSE(string_tools::str_in_set(my_set, "fred"));
}


//----------------------------------------------------------------------------------------------------------------------
//                                                 Test isInteger()
//----------------------------------------------------------------------------------------------------------------------
TEST(StringTools, testIsInteger01) {
    ASSERT_TRUE(string_tools::is_integer("1234"));
    ASSERT_TRUE(string_tools::is_integer("+678"));
    ASSERT_TRUE(string_tools::is_integer("-890"));
    ASSERT_TRUE(string_tools::is_integer("1"));
    ASSERT_FALSE(string_tools::is_integer(""));
    ASSERT_FALSE(string_tools::is_integer("-"));
    ASSERT_FALSE(string_tools::is_integer("+"));
    ASSERT_FALSE(string_tools::is_integer(" "));
    ASSERT_FALSE(string_tools::is_integer(","));
    ASSERT_FALSE(string_tools::is_integer("k"));
    ASSERT_FALSE(string_tools::is_integer("|"));
    ASSERT_FALSE(string_tools::is_integer("%"));
    ASSERT_FALSE(string_tools::is_integer("<"));
    ASSERT_FALSE(string_tools::is_integer("abc"));
    ASSERT_FALSE(string_tools::is_integer("1.23"));
    ASSERT_FALSE(string_tools::is_integer("3."));
    ASSERT_FALSE(string_tools::is_integer(".8"));
    ASSERT_FALSE(string_tools::is_integer("3f"));
}


//----------------------------------------------------------------------------------------------------------------------
//                                    Helper Function for Testing String Equality
//
// This function tests that the two strings are the same length, all the characters in the strings match, and the
// last element in the char array is 0.
//
// Note that len is the number of characters in the char array, before zero termination.
//
//----------------------------------------------------------------------------------------------------------------------
bool testOneString(std::string s, char* cA, int len) {
    bool y = true;
    y = y && (s.size() == len);
    for (int i = 0; i < s.size(); ++i) {
        y = y && (s.at(i) == cA[i]);
    }

    // Verify that the last character in the char array is 0:
    y = y && (cA[len] == (char) 0);
    return y;
}


//----------------------------------------------------------------------------------------------------------------------
//                                             Test stringToCharArray()
//----------------------------------------------------------------------------------------------------------------------
TEST(StringTools, testStringToCharArray) {
    char* cA;
    std::string s;

    s = "a";
    cA = string_tools::string2CharArray(s);
    ASSERT_TRUE(testOneString(s, cA, s.size()));

    s = "abc";
    cA = string_tools::string2CharArray(s);
    ASSERT_TRUE(testOneString(s, cA, s.size()));

    s = "hello there";
    cA = string_tools::string2CharArray(s);
    ASSERT_TRUE(testOneString(s, cA, s.size()));

    s = "1234567890 a b c d efghijklmnopqrstuvwxyz";
    cA = string_tools::string2CharArray(s);
    ASSERT_TRUE(testOneString(s, cA, s.size()));

    s = "                ";
    cA = string_tools::string2CharArray(s);
    ASSERT_TRUE(testOneString(s, cA, s.size()));
}
