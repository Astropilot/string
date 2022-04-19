#include "../simple_strings/simple_strings.h"

#include <stdio.h>
#include <string.h>

#include <gtest/gtest.h>

TEST(Strings, StringCreation) {
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

TEST(Strings, StringAppendArray) {
    string my_string = STR("Hello");

    EXPECT_STREQ(my_string, "Hello");
    EXPECT_EQ(spls_len(my_string), 5);

    APPEND_ARR(my_string, " World!");

    EXPECT_STREQ(my_string, "Hello World!");
    EXPECT_EQ(spls_len(my_string), 12);

    spls_free_string(my_string);
}

TEST(Strings, StringAppendString) {
    string my_string = STR("Hello");
    string my_string2 = STR(" World!");

    EXPECT_STREQ(my_string, "Hello");
    EXPECT_EQ(spls_len(my_string), 5);
    EXPECT_STREQ(my_string2, " World!");
    EXPECT_EQ(spls_len(my_string2), 7);

    APPEND_STR(my_string, my_string2);

    EXPECT_STREQ(my_string, "Hello World!");
    EXPECT_EQ(spls_len(my_string), 12);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringCapitalize) {
    string my_string = STR("heLlo wOrld!");

    EXPECT_STREQ(my_string, "heLlo wOrld!");
    EXPECT_EQ(spls_len(my_string), 12);

    string capitalized = spls_capitalize(my_string);

    EXPECT_STREQ(capitalized, "HeLlo wOrld!");
    EXPECT_EQ(spls_len(capitalized), 12);

    spls_free_string(my_string);
    spls_free_string(capitalized);
}

TEST(Strings, StringCapitalizeNonAlpha) {
    string my_string = STR("123456");

    EXPECT_STREQ(my_string, "123456");
    EXPECT_EQ(spls_len(my_string), 6);

    string capitalized = spls_capitalize(my_string);

    EXPECT_STREQ(capitalized, "123456");
    EXPECT_EQ(spls_len(capitalized), 6);

    spls_free_string(my_string);
    spls_free_string(capitalized);
}

TEST(Strings, StringToLower) {
    string my_string = STR("heLlo WOrlD!");

    EXPECT_STREQ(my_string, "heLlo WOrlD!");
    EXPECT_EQ(spls_len(my_string), 12);

    string lowered = spls_tolower(my_string);

    EXPECT_STREQ(lowered, "hello world!");
    EXPECT_EQ(spls_len(lowered), 12);

    spls_free_string(my_string);
    spls_free_string(lowered);
}

TEST(Strings, StringToUpper) {
    string my_string = STR("heLlo WOrlD!");

    EXPECT_STREQ(my_string, "heLlo WOrlD!");
    EXPECT_EQ(spls_len(my_string), 12);

    string uppered = spls_toupper(my_string);

    EXPECT_STREQ(uppered, "HELLO WORLD!");
    EXPECT_EQ(spls_len(uppered), 12);

    spls_free_string(my_string);
    spls_free_string(uppered);
}

TEST(Strings, StringStartsWith) {
    string my_string = STR("hello world!");
    string search = STR("hello");
    string search_invalid = STR("world");

    EXPECT_STREQ(my_string, "hello world!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(search, "hello");
    EXPECT_EQ(spls_len(search), 5);

    EXPECT_STREQ(search_invalid, "world");
    EXPECT_EQ(spls_len(search_invalid), 5);

    EXPECT_EQ(spls_startswith(my_string, search), true);
    EXPECT_EQ(spls_startswith(my_string, search_invalid), false);

    spls_free_string(my_string);
    spls_free_string(search);
    spls_free_string(search_invalid);
}

TEST(Strings, StringEndsWith) {
    string my_string = STR("hello world!");
    string search = STR("world!");
    string search_invalid = STR("hello");

    EXPECT_STREQ(my_string, "hello world!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(search, "world!");
    EXPECT_EQ(spls_len(search), 6);

    EXPECT_STREQ(search_invalid, "hello");
    EXPECT_EQ(spls_len(search_invalid), 5);

    EXPECT_EQ(spls_endswith(my_string, search), true);
    EXPECT_EQ(spls_endswith(my_string, search_invalid), false);

    spls_free_string(my_string);
    spls_free_string(search);
    spls_free_string(search_invalid);
}

TEST(Strings, StringIsAlphaNum) {
    string my_string = STR("hello world!");
    string my_string2 = STR("123abc456");

    EXPECT_STREQ(my_string, "hello world!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(my_string2, "123abc456");
    EXPECT_EQ(spls_len(my_string2), 9);

    EXPECT_EQ(spls_isalnum(my_string), false);
    EXPECT_EQ(spls_isalnum(my_string2), true);

    spls_free_string(my_string);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
