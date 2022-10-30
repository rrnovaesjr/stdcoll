#include <stdio.h>
#include <stdlib.h>
#include "common/assert.h"
#include "common/suite.h"
#include "stdcoll/linked_list.h"

const char description[] = "linked_list_test";

void should_initialize_linked_list() {
    std_list *linked_list = LinkedListToList(NewLinkedList());

    assertd(Size(ListToCollection(linked_list)) == 0UL, "Should initialize with size 0");

    free(linked_list);
}

void should_update_linked_list_and_query_elements() {
    std_list *linked_list = LinkedListToList(NewLinkedList());

    assertd(Size(ListToCollection(linked_list)) == 0UL, "Should initialize with size 0");
    assertd(Add(ListToCollection(linked_list), 1) == 1, "Should modify linked list when adding 1");
    assertd(Add(ListToCollection(linked_list), 2) == 1, "Should modify linked list when adding 2");
    assertd(Add(ListToCollection(linked_list), 3) == 1, "Should modify linked list when adding 3");
    assertd(Add(ListToCollection(linked_list), 4) == 1, "Should modify linked list when adding 4");
    assertd(GetAtIndex(linked_list, 0) == 1, "Should return 1 at index 0");
    assertd(GetAtIndex(linked_list, 1) == 2, "Should return 2 at index 1");
    assertd(GetAtIndex(linked_list, 2) == 3, "Should return 3 at index 2");
    assertd(GetAtIndex(linked_list, 3) == 4, "Should return 4 at index 3");
    Clear(ListToCollection(linked_list));
    assertd(Size(ListToCollection(linked_list)) == 0UL, "Should clear the linked list");
    free(linked_list);
}

void should_write_elements_to_array() {
    int expected_arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int expected_size = sizeof(expected_arr)/sizeof(int);
    std_list *linked_list = LinkedListToList(NewLinkedListFromArray(expected_arr, expected_size, sizeof(int)));
    int actual_arr[expected_size];

    assertd(Size(ListToCollection(linked_list)) == (unsigned long) expected_size, "Should have 10 elements from the original array");
    ToArray(ListToCollection(linked_list), actual_arr);
    for (int i = 0; i < expected_size; i++) { 
        assertd(expected_arr[i] == actual_arr[i], "Actual array should be equal to expected array"); 
    }
    for (int i = 0; i < expected_size; i++) { 
        assertd(expected_arr[i] == GetAtIndex(linked_list, i), "Linked list should be equal to expected array"); 
    }

    Clear(ListToCollection(linked_list));
    free(linked_list);
}

test_instance tests[] = {
    { should_initialize_linked_list, "should_initialize_linked_list" },
    { should_update_linked_list_and_query_elements, "should_update_linked_list_and_query_elements" },
    { should_write_elements_to_array, "should_write_elements_to_array" },
    { NULL, NULL }
};

void (*before_all)(void) = NULL;

void (*after_all)(void) = NULL;

void (*before_each[])(void) = {NULL};

void (*after_each[])(void) = {NULL};