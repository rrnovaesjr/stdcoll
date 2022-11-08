#include <stdio.h>
#include "common/assert_impl.h"
#include "common/suite.h"
#include "common/print.h"

int for_each_test(test_instance t) {
    if (before_each) {
        void (**b)(void) = before_each;
        while ((*b) != NULL) {
            (*b)();
            b++;
        }
    }

    LOG_INFO(stdout, "[ RUN      ] %s\n", t.description);
    int res = run_assertd(t.f);
    if (!res) {LOG_OK(stdout, "[       OK ] %s\n", t.description);}
    else {LOG_ERROR(stdout, "[     FAIL ] %s\n", t.description);}

    if (after_each) {
        void (**a)(void) = after_each;
        while ((*a )!= NULL) {
            (*a)();
            a++;
        }
    }

    return res;
}

int for_suite() {
    if (before_all) before_all();

    int i = 0;
    test_instance t = tests[i];

    int res = 0;

    while (tests[i].f != NULL) {
        res |= for_each_test(tests[i]);
        i++;
    }

    if (after_all) after_all();

    return res;
}

int main() {
    int res = for_suite();
    if (!res) { LOG_OK(stdout, "\nTEST RESULTS: PASS\n"); }
    else LOG_ERROR(stdout, "\nTEST RESULTS: FAIL\n");
    return res;
}