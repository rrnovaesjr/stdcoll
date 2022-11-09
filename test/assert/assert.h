#ifndef __ASSERT_H__
#define __ASSERT_H__

void assertd(int condition, const int line, const char *file, const char *fmt, ...);

void assert_true(int actual, int line, const char *file);

void assert_false(const int actual, int line, const char *file);

void asserti_equals(int actual, int expected, int line, const char *file);

void assert_same(void *actual, void *expected, int line, const char *file);

#define ASSERT_TRUE(actual) (assert_true(actual, __LINE__, __FILE__))

#define ASSERT_FALSE(actual) (assert_false(actual, __LINE__, __FILE__))

#define ASSERTI_EQ(actual, expected) (asserti_equals(actual, expected, __LINE__, __FILE__))

#define ASSERT_SAME(actual, expected) (assert_same(actual, expected, __LINE__, __FILE__))

#endif