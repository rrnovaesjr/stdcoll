#include "stdcoll/linked_list.h"
#include "assertions/assertions.h"
#include "log/print.h"
#include <string.h>
#include <stdlib.h>

typedef struct assertion
{
    char m_file[512];
    int line;
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

int AssertionFail(const char *file, const int line, char *msg)
{
    strcpy(assert_context->m_file, file);
    assert_context->line = line;
    strcpy(assert_context->m_assertion_message, msg);

    LinkedListAdd(assertions, assert_context);
}

void AssertionsLogAll(FILE *output)
{
    size_t n = LinkedListSize(assertions);
    int i;
    if (n > 0)
    {
        LOG_INFO(output, "\nFailed assertions:\n");
    }
    for (i = 0; i < (int)n; i++)
    {
        assertion *assert = LinkedListGetAtIndex(assertions, i);

        LOG_ERROR(output, "\n\t%s:\n\t  At %s:%d:\n\t    %s\n", assert->m_test_description,
                  assert->m_file,
                  assert->line,
                  assert->m_assertion_message);
    }
}

void AssertionsFinalize()
{
    LinkedListClear(assertions);
    LinkedListDelete(assertions);
}