#ifndef __ASSERT_H__
#define __ASSERT_H__

void AssertD(int condition, const int line, const char *file, const char *fmt, ...);

void AssertTrue(int actual, int line, const char *file);

void AssertFalse(const int actual, int line, const char *file);

void AssertIEquals(int actual, int expected, int line, const char *file);

void AssertSame(void *actual, void *expected, int line, const char *file);

#define ASSERT_TRUE(actual) AssertTrue(actual, __LINE__, __FILE__)

#define ASSERT_FALSE(actual) AssertFalse(actual, __LINE__, __FILE__)

#define ASSERTI_EQ(actual, expected) AssertIEquals(actual, expected, __LINE__, __FILE__)

#define ASSERT_SAME(actual, expected) AssertSame(actual, expected, __LINE__, __FILE__)

#endif