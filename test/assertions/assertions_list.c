#include "stdcoll/linked_list.h"
#include "assertions/assertions_list.h"
#include "log/print.h"
#include <string.h>

typedef struct assertion {
    char test[128];
    char msg[128];
} assertion;

stdllist *assertions;

void init()
{
    assertions = LinkedList();
}

int assertion_add(char *test, char *msg)
{
    assertion *assert = malloc(sizeof(assertion));
    strcpy(assert->test, test);
    strcpy(assert->msg, msg);

    LinkedListAdd(assertions, assert);
}

int log_all_assertions(FILE *output)
{
    size_t n = LinkedListSize(assertions);
    int i;
    if (n > 0) {
        LOG_INFO(output, "Failed assertions:\n");
    }
    for (i = 0; i < (int) n; i++) 
    {
        assertion *assert = LinkedListGetAtIndex(assertions, i);

        LOG_ERROR(output, "\t%s:\n\t\t%s\n", assert->test, assert->msg);
    }
}

void release()
{
    LinkedListClear(assertions);
    LinkedListDelete(assertions);
}