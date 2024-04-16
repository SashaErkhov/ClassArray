//
// Created by sasor on 16.04.2024.
//

#include <gtest/gtest.h>
#include "Para.h"

TEST(Para, first)
{
    Para<int,int> a;
    a.first = 1;
    a.second = 2;
    EXPECT_EQ(a.first, 1);
    EXPECT_EQ(a.second, 2);
}

TEST(Para, Operator)
{
    Para<int,int> a;
    a.first = 1;
    a.second = 2;
    Para<int, int> b=a;
    EXPECT_EQ(b.first, a.first);
    EXPECT_EQ(b.second, a.second);
    Para<int, int> c(a);
    EXPECT_EQ(c.first, a.first);
    EXPECT_EQ(c.second, a.second);
}