#include <iostream>
#include <gtest/gtest.h>
#include "Arry.h"

TEST(Arry, DefaultConstructor) {
    Arry<int> a;
    EXPECT_EQ(a.getSize(), 0);
}   
TEST(Arry, AddElement) {
    Arry<int> a;
    a.addElement(1);
    EXPECT_EQ(a.getSize(), 1);
}
TEST(Arry, AddElements) {
    Arry<int> a(5);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    EXPECT_EQ(a.getSize(), 10);
}
TEST(Arry, AddMoreThenCapaticity) {
    Arry<int> a(5);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.addElement(6);
    EXPECT_EQ(a.getSize(), 11);
}

TEST(Arry, BigCountOfData) {
    Arry<int> a(5);
    for (int i = 0; i < 10000; i++) {
        a.addElement(i);
    }
    EXPECT_EQ(a.getSize(), 10005);
}

TEST(Arry, RemoveOneElementFromStart) {
    Arry<int> a;
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.removeElement(0);
    EXPECT_EQ(a.getElement(0), 2);
}
TEST(Arry, RemoveOneElementFromMiddle) {
    Arry<int> a;
    for (int i = 0; i < 1000; i++) {
        a.addElement(i);
    }
    a.removeElement(500);
    EXPECT_EQ(a.getElement(500), 501);
}

TEST(Arry, InsertToBegin){
    Arry<int> a;
    a.addElement(20);
    a.insert(a.begin(),10);
    EXPECT_EQ(a.getElement(0),10);
}

TEST(Arry,InsertToEnd){
    Arry<int> a;
    a.addElement(10);
    a.insert(a.end(),20);
    EXPECT_EQ(a.getElement(a.getSize()-1),20);
}

TEST(Arry,InsertToMiddle){
    Arry<int> a;
    a.addElement(10);
    a.addElement(30);
    a.insert(++a.begin(),20);
    EXPECT_EQ(a.getElement(1),20);
}

TEST(Arry,InsertWithOne){
    Arry<int> a;
    a.addElement(10);
    a.insert(a.begin(),20);
    EXPECT_EQ(a.getElement(0),20);
    EXPECT_EQ(a.getElement(1),10);
}

TEST(Arry,InsertToEmpty){
    Arry<int> a;
    a.insert(a.begin(),10);
    EXPECT_EQ(a.getElement(0),10);
}