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

    return LinkedListAdd(assertions, assert_context);
}

void AssertionsLogAll(FILE *output)
{
    stditr *t = LinkedListIterator(assertions);
    if (IteratorHasNext(t))
    {
        LOG_INFO(output, "\nFailed assertions:\n");
    }
    for (; IteratorHasNext(t); t = IteratorNext(t))
    {
        assertion *assert = IteratorGet(t);

        LOG_ERROR(output, "\n\t%s:\n\t  At %s:%d:\n\t    %s\n", assert->m_test_description,
                  assert->m_file,
                  assert->line,
                  assert->m_assertion_message);
    }

    IteratorDelete(t);
}

void AssertionsFinalize()
{
    LinkedListClear(assertions);
    LinkedListDelete(assertions);
}