#include <gtest/gtest.h>
#include "List.h"

TEST(ListTest, DefaultConstructorList) {
    List<int> a;
    EXPECT_EQ(0, a.getSize());
}
TEST(ListTest, AddElementList) {
    List<int> intList;
    intList.addElement(5);
    EXPECT_EQ(1, intList.getSize());
    EXPECT_EQ(5, intList.getElement(0));
}
TEST(ListTest, AddMoreThenCapaticityList) {
    List<int> a(5);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.addElement(6);
    EXPECT_EQ(a.getSize(), 11);
}
TEST(ListTest, BigCountOfDataList) {
    List<int> a(5);
    for (int i = 0; i < 10000; i++) {
        a.addElement(i);
    }
    EXPECT_EQ(a.getSize(), 10005);
}

TEST(ListTest, RemoveElementList) {
    List<int> a;
    a.addElement(5);
    a.removeElement(0);
    EXPECT_EQ(0, a.getSize());
}

TEST(ListTest, RemoveOneElementFromStartList) {
    List<int> a;
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.removeElement(0);
    EXPECT_EQ(a.getElement(0), 2);
}
TEST(ListTest, RemoveOneElementFromMiddleList) {
    List<int> a;
    for (int i = 0; i < 1000; i++) {
        a.addElement(i);
    }
    a.removeElement(500);
    EXPECT_EQ(a.getElement(500), 501);
}

TEST(ListTest, InsertToBegin){
    List<int> a;
    a.addElement(20);
    a.insert(a.begin(),10);
    EXPECT_EQ(a.getElement(0),10);
}

TEST(ListTest,InsertToEnd){
    List<int> a;
    a.addElement(10);
    a.insert(a.end(),20);
    EXPECT_EQ(a.getElement(a.getSize()-1),20);
}

TEST(ListTest,InsertToMiddle){
    List<int> a;
    a.addElement(10);
    a.addElement(30);
    a.insert(++a.begin(),20);
    EXPECT_EQ(a.getElement(1),20);
}

TEST(ListTest,InsertWithOne){
    List<int> a;
    a.addElement(10);
    a.insert(a.begin(),20);
    EXPECT_EQ(a.getElement(0),20);
    EXPECT_EQ(a.getElement(1),10);
}

TEST(ListTest,InsertToEmpty){
    List<int> a;
    a.insert(a.begin(),10);
    EXPECT_EQ(a.getElement(0),10);
}

TEST(ListTest,NewFeatureForAddElem)
{
    List<int> a;
    auto p1=a.addElement(10);
    auto p2=a.addElement(20);
    auto p3=a.addElement(30);
    auto p4=a.addElement(40);
    auto p5=a.addElement(50);
    EXPECT_EQ(a.getSize(),5);
    EXPECT_EQ(a.getElement(0),10);
    EXPECT_EQ(a.getElement(1),20);
    EXPECT_EQ(*p3,30);
    EXPECT_EQ(*p4,40);
    EXPECT_EQ(*p5,50);
    EXPECT_EQ(*p1,10);
    EXPECT_EQ(*p2,20);
}