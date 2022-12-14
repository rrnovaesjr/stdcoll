#include <stdio.h>
#include "assert/assert_impl.h"
#include "suite/suite.h"
#include "log/print.h"
#include "assertions/assertions.h"

int ForEachTest(test_instance t)
{
    void (**b)(void) = before_each;
    while ((*b) != NULL)
    {
        (*b)();
        b++;
    }

    LOG_INFO(stdout, "[ RUN      ] %s\n", t.description);
    int res = RunAssertD(t.f, t.description);
    if (!res)
    {
        LOG_OK(stdout, "[       OK ] %s\n", t.description);
    }
    else
    {
        LOG_ERROR(stdout, "[     FAIL ] %s\n", t.description);
    }

    void (**a)(void) = after_each;
    while ((*a) != NULL)
    {
        (*a)();
        a++;
    }

    return res;
}

int ForSuite()
{
    LOG_INFO(stdout, "SUITE: %s\n\n", description);

    if (before_all)
        before_all();

    int i = 0;

    int res = 0;

    while (tests[i].f != NULL)
    {
        res |= ForEachTest(tests[i]);
        i++;
    }

    if (after_all)
        after_all();

    return res;
}

int main()
{
    AssertionsInit();
    int res = ForSuite();
    if (!res)
    {
        LOG_OK(stdout, "\nTEST RESULTS: PASS\n");
    }
    else
    {
        AssertionsLogAll(stderr);
        LOG_ERROR(stdout, "\nTEST RESULTS: FAIL\n");
    }
    AssertionsFinalize();
    return res;
}