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
    spls_free_string(my_string2);
}

TEST(Strings, StringIsAlpha) {
    string my_string = STR("helloworld");
    string my_string2 = STR("123abc456");

    EXPECT_STREQ(my_string, "helloworld");
    EXPECT_EQ(spls_len(my_string), 10);

    EXPECT_STREQ(my_string2, "123abc456");
    EXPECT_EQ(spls_len(my_string2), 9);

    EXPECT_EQ(spls_isalpha(my_string), true);
    EXPECT_EQ(spls_isalpha(my_string2), false);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringIsDigit) {
    string my_string = STR("123456");
    string my_string2 = STR("123abc456");

    EXPECT_STREQ(my_string, "123456");
    EXPECT_EQ(spls_len(my_string), 6);

    EXPECT_STREQ(my_string2, "123abc456");
    EXPECT_EQ(spls_len(my_string2), 9);

    EXPECT_EQ(spls_isdigit(my_string), true);
    EXPECT_EQ(spls_isdigit(my_string2), false);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringIsLower) {
    string my_string = STR("hello world!");
    string my_string2 = STR("Hello World!");

    EXPECT_STREQ(my_string, "hello world!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(my_string2, "Hello World!");
    EXPECT_EQ(spls_len(my_string2), 12);

    EXPECT_EQ(spls_islower(my_string), true);
    EXPECT_EQ(spls_islower(my_string2), false);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringIsUpper) {
    string my_string = STR("HELLO WORLD!");
    string my_string2 = STR("Hello World!");

    EXPECT_STREQ(my_string, "HELLO WORLD!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(my_string2, "Hello World!");
    EXPECT_EQ(spls_len(my_string2), 12);

    EXPECT_EQ(spls_isupper(my_string), true);
    EXPECT_EQ(spls_isupper(my_string2), false);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringIsPrintable) {
    string my_string = STR("Hello World!");
    string my_string2 = STR("Hello World!\n");

    EXPECT_STREQ(my_string, "Hello World!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(my_string2, "Hello World!\n");
    EXPECT_EQ(spls_len(my_string2), 13);

    EXPECT_EQ(spls_isprintable(my_string), true);
    EXPECT_EQ(spls_isprintable(my_string2), false);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, StringIsSpace) {
    string my_string = STR("Hello World!");
    string my_string2 = STR("   ");

    EXPECT_STREQ(my_string, "Hello World!");
    EXPECT_EQ(spls_len(my_string), 12);

    EXPECT_STREQ(my_string2, "   ");
    EXPECT_EQ(spls_len(my_string2), 3);

    EXPECT_EQ(spls_isspace(my_string), false);
    EXPECT_EQ(spls_isspace(my_string2), true);

    spls_free_string(my_string);
    spls_free_string(my_string2);
}

TEST(Strings, SubString) {
    string my_string = STR("a yellow submarine");

    string sub1 = spls_substring(my_string, 0, spls_len(my_string));
    string sub2 = spls_substring(my_string, 2, 8);
    string sub3 = spls_substring(my_string, 9, spls_len(my_string));

    EXPECT_STREQ(my_string, sub1);
    EXPECT_STREQ(sub2, "yellow");
    EXPECT_STREQ(sub3, "submarine");

    spls_free_string(my_string);
    spls_free_string(sub1);
    spls_free_string(sub2);
    spls_free_string(sub3);
}

TEST(Strings, FindStrings) {
    string my_string = STR("a yellow submarine");
    string search1 = STR("yellow");
    string search2 = STR("sub");
    string search3 = STR("bob");

    EXPECT_EQ(spls_find(my_string, search1, 0, spls_len(my_string) - 1), 2);
    EXPECT_EQ(spls_find(my_string, search1, 5, spls_len(my_string) - 1), -1);
    EXPECT_EQ(spls_find(my_string, search2, 0, spls_len(my_string) - 1), 9);
    EXPECT_EQ(spls_find(my_string, search2, 0, 9), -1);
    EXPECT_EQ(spls_find(my_string, search3, 0, spls_len(my_string) - 1), -1);

    spls_free_string(my_string);
    spls_free_string(search1);
    spls_free_string(search2);
    spls_free_string(search3);
}

TEST(Strings, ReplaceStrings) {
    string my_string = STR("one one was a race horse, two two was one too.");
    string old = STR("one");
    string new_ = STR("three");
    string old_not_found = STR("toto");

    string one_to_three = spls_replace(my_string, old, new_, -1);

    EXPECT_STREQ(one_to_three, "three three was a race horse, two two was three too.");

    spls_free_string(one_to_three);

    one_to_three = spls_replace(my_string, old, new_, 2);

    EXPECT_STREQ(one_to_three, "three three was a race horse, two two was one too.");

    string one_to_toto = spls_replace(my_string, old_not_found, new_, -1);

    EXPECT_STREQ(one_to_toto, my_string);

    spls_free_string(my_string);
    spls_free_string(old);
    spls_free_string(new_);
    spls_free_string(old_not_found);
    spls_free_string(one_to_three);
    spls_free_string(one_to_toto);
}

TEST(Strings, StringsCount) {
    string my_string = STR("one one was a race horse, two two was one too.");
    string one = STR("one");
    string toto = STR("toto");

    EXPECT_EQ(spls_count(my_string, one, 0, spls_len(my_string) - 1), 3);
    EXPECT_EQ(spls_count(my_string, one, 10, spls_len(my_string) - 1), 1);
    EXPECT_EQ(spls_count(my_string, one, 10, 15), 0);
    EXPECT_EQ(spls_count(my_string, toto, 0, spls_len(my_string) - 1), 0);

    spls_free_string(my_string);
    spls_free_string(one);
    spls_free_string(toto);
}

TEST(Strings, StringStrip) {
    string my_string = STR("123hello123");
    string my_string2 = STR("123");
    string my_string3 = STR("    Little test  ");
    string strip_space = STR(" ");

    string my_string_stripped = spls_strip(my_string, my_string2);
    string my_string2_stripped = spls_strip(my_string2, my_string2);
    string my_string3_stripped = spls_strip(my_string3, strip_space);

    EXPECT_STREQ(my_string_stripped, "hello");
    EXPECT_EQ(spls_len(my_string_stripped), 5);

    EXPECT_STREQ(my_string2_stripped, "");
    EXPECT_EQ(spls_len(my_string2_stripped), 0);

    EXPECT_STREQ(my_string3_stripped, "Little test");
    EXPECT_EQ(spls_len(my_string3_stripped), 11);

    spls_free_string(my_string);
    spls_free_string(my_string2);
    spls_free_string(my_string3);
    spls_free_string(my_string_stripped);
    spls_free_string(my_string2_stripped);
    spls_free_string(my_string3_stripped);
    spls_free_string(strip_space);
}

TEST(Strings, StringLStrip) {
    string my_string = STR("123hello123");
    string my_string2 = STR("    Little test  ");
    string strip_123 = STR("123");
    string strip_space = STR(" ");

    string my_string_stripped = spls_lstrip(my_string, strip_123);
    string my_string2_stripped = spls_lstrip(my_string2, strip_space);

    EXPECT_STREQ(my_string_stripped, "hello123");
    EXPECT_EQ(spls_len(my_string_stripped), 8);

    EXPECT_STREQ(my_string2_stripped, "Little test  ");
    EXPECT_EQ(spls_len(my_string2_stripped), 13);

    spls_free_string(my_string);
    spls_free_string(my_string2);
    spls_free_string(my_string_stripped);
    spls_free_string(my_string2_stripped);
    spls_free_string(strip_123);
    spls_free_string(strip_space);
}

TEST(Strings, StringRStrip) {
    string my_string = STR("123hello123");
    string my_string2 = STR("    Little test  ");
    string strip_123 = STR("123");
    string strip_space = STR(" ");

    string my_string_stripped = spls_rstrip(my_string, strip_123);
    string my_string2_stripped = spls_rstrip(my_string2, strip_space);

    EXPECT_STREQ(my_string_stripped, "123hello");
    EXPECT_EQ(spls_len(my_string_stripped), 8);

    EXPECT_STREQ(my_string2_stripped, "    Little test");
    EXPECT_EQ(spls_len(my_string2_stripped), 15);

    spls_free_string(my_string);
    spls_free_string(my_string2);
    spls_free_string(my_string_stripped);
    spls_free_string(my_string2_stripped);
    spls_free_string(strip_123);
    spls_free_string(strip_space);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
