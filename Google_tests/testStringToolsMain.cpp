//
// Created by jamie on 7/13/21.
//

//----------------------------------------------------------------------------------------------------------------------
//                                                     Test Main
//
// This file defines int main for Google Test.
//
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "../StringTools.h"
#include <gtest/gtest.h>

int main(int argv, char *argc[]) {
    //TestFifo::test_01();
    //return 0;
    std::cout << "Running tests..." << std::endl;
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
