#include <gtest/gtest.h>
#include "List.h"

TEST(ListTest, DefaultConstructor) {
    List<int> a;
    EXPECT_EQ(0, a.getSize());
}
TEST(ListTest, AddElement) {
    List<int> intList;
    intList.addElement(5);
    EXPECT_EQ(1, intList.getSize());
    EXPECT_EQ(5, intList.getElement(0));
}
TEST(ListTest, AddMoreThenCapaticity) {
    List<int> a(5);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.addElement(6);
    EXPECT_EQ(a.getSize(), 6);
}
TEST(ListTest, BigCountOfData) {
    List<int> a(5);
    for (int i = 0; i < 10000; i++) {
        a.addElement(i);
    }
    EXPECT_EQ(a.getSize(), 10000);
}

TEST(ListTest, RemoveElement) {
    List<int> a;
    a.addElement(5);
    a.removeElement(0);
    EXPECT_EQ(0, intList.getSize());
}

TEST(ListTest, RemoveOneElementFromStart) {
    List<int> a(5);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.removeElement(0);
    EXPECT_EQ(a.getElement(0), 2);
}
TEST(Arry, RemoveOneElementFromMiddle) {
    List<int> a(5);
    for (int i = 0; i < 1000; i++) {
        a.addElement(i);
    }
    a.removeElement(500);
    EXPECT_EQ(a.getElement(500), 501);
}
