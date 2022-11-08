#include "stdcoll/collections.h"
#include "stdcoll/linked_list.h"

stdcoll * SupplyCollection()
{
    return ListSuper(LinkedListSuper(LinkedList()));
}