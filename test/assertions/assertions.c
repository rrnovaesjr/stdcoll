#include "stdcoll/linked_list.h"
#include "assertions/assertions.h"
#include "log/print.h"
#include <string.h>
#include <stdlib.h>

typedef struct assertion {
    char m_test_description[128];
    char m_assertion_message[128];
} assertion;

assertion *assert_context;

stdllist *assertions;

void AssertionsInit()
{
    assertions = LinkedList();
}

void AssertionAdd(const char *t_test_description)
{
    assert_context = malloc(sizeof(assertion));
    strcpy(assert_context->m_test_description, t_test_description);
}

void AssertionSuccess()
{
    free(assert_context);
}

int AssertionFail(char *test, char *msg)
{
    strcpy(assert_context->m_test_description, test);
    strcpy(assert_context->m_assertion_message, msg);

    LinkedListAdd(assertions, assert_context);
}

int AssertionsLogAll(FILE *output)
{
    size_t n = LinkedListSize(assertions);
    int i;
    if (n > 0) {
        LOG_INFO(output, "Failed assertions:\n");
    }
    for (i = 0; i < (int) n; i++) 
    {
        assertion *assert = LinkedListGetAtIndex(assertions, i);

        LOG_ERROR(output, "\t%s:\n\t\t%s\n", assert->m_test_description, assert->m_assertion_message);
    }
}

void AssertionsFinalize()
{
    LinkedListClear(assertions);
    LinkedListDelete(assertions);
}