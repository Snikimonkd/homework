#include "gtest/gtest.h"

extern "C" {
#include "resource_sheet.h"
}

void resource_is_eq(resource *left, resource *right) {
    EXPECT_STREQ(left->amount, right->amount);
    EXPECT_STREQ(left->chiper, right->chiper);
    EXPECT_STREQ(left->materials, right->materials);
    EXPECT_STREQ(left->name, right->name);
    EXPECT_STREQ(left->units, right->units);
}