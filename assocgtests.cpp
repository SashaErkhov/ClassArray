#include <gtest/gtest.h>

#include "Assoc.h"
#include "Containers.h"
#include "Arry.h"

// -------------------------------------------------- BinarySearch tests

// Test searching for an existing element
TEST(BinarySearchTest, FindsExistingElement) {
    Arry<int> arr;
    int values[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    for (int value : values) {
        arr.addElement(value);
    }
    auto it = binarySearch(30, arr.begin(), arr.end());
    EXPECT_NE(it, arr.end());
    EXPECT_EQ(*it, 30);
}

// Test searching for a non-existing element
TEST(BinarySearchTest, DoesNotFindNonExistingElement) {
    Arry<int> arr;
    int values[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    for (int value : values) {
        arr.addElement(value);
    }
    auto it = binarySearch(25, arr.begin(), arr.end());
    EXPECT_EQ(it, arr.end());
}

// Test searching in an empty array
TEST(BinarySearchTest, HandlesEmptyArray) {
    Arry<int> empty;
    auto it = binarySearch(10, empty.begin(), empty.end());
    EXPECT_EQ(it, empty.end());
}

// Test searching in a single-element array
TEST(BinarySearchTest, HandlesSingleElementArray) {
    Arry<int> single;
    single.addElement(40);

    auto it = binarySearch(40, single.begin(), single.end());
    EXPECT_NE(it, single.end());
    EXPECT_EQ(*it, 40);

    it = binarySearch(10, single.begin(), single.end());
    EXPECT_EQ(it, single.end());
}

// Test the boundaries
TEST(BinarySearchTest, TestBoundaries) {
    Arry<int> arr;
    int values[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    for (int value : values) {
        arr.addElement(value);
    }
    auto it = binarySearch(10, arr.begin(), arr.end());
    EXPECT_NE(it, arr.end());
    EXPECT_EQ(*it, 10);

    it = binarySearch(100, arr.begin(), arr.end());
    EXPECT_NE(it, arr.end());
    EXPECT_EQ(*it, 100);
}

// ----------------------------------------------------- Assoc tests

// ...