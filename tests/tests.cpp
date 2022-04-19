#define SIMPLE_STRINGS_IMPL
#include "../simple_strings/simple_strings.h"

#include <stdio.h>
#include <string.h>

#include <gtest/gtest.h>

TEST(Strings, StringCreation) {
    // Define strings easily from old school char arrays
    string my_string = STR("Hello");

    EXPECT_STREQ(my_string, "Hello");
    EXPECT_EQ(spls_len(my_string), 5);

    spls_free_string(my_string);
}

TEST(Strings, StringCloning) {
    string my_string = STR("Hello");
    string copy = CLONE(my_string);

    EXPECT_STREQ(my_string, copy);
    EXPECT_NE(my_string, copy);

    EXPECT_EQ(spls_len(my_string), 5);
    EXPECT_EQ(spls_len(copy), 5);

    spls_free_string(my_string);
    spls_free_string(copy);
}

TEST(Strings, StringAppend) {
    string my_string = STR("Hello");

    EXPECT_STREQ(my_string, "Hello");
    EXPECT_EQ(spls_len(my_string), 5);

    APPEND_ARR(my_string, " World!");

    EXPECT_STREQ(my_string, "Hello World!");
    EXPECT_EQ(spls_len(my_string), 12);

    spls_free_string(my_string);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
