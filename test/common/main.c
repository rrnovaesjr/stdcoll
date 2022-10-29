#include <stdio.h>
#include "common/assert_impl.h"
#include "common/suite.h"

int for_each_test(test_instance t) {
    if (before_each) {
        void (**b)(void) = before_each;
        while ((*b) != NULL) {
            (*b)();
            b++;
        }
    }

    fprintf(stderr, "%s:\n", t.description);
    int res = run_assertd(t.f);
    fprintf(stderr, "%s: %s\n", t.description, !res ? "PASS" : "FAIL");

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
    int i;
    int res = 0;
    
    res |= for_suite();

    fprintf(stderr, "RESULT: %s\n", !res ? "PASS" : "FAIL");

    return res;
}