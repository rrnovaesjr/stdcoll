cmake_minimum_required(VERSION 3.22)

project(StdCollection LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header
                    ${CMAKE_CURRENT_SOURCE_DIR}/impl)

file(GLOB STDCOLL_HEADERS
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection.h
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection_impl.h)

file(GLOB STDCOLL_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/collection.c)

file(GLOB STDCOLL_ALL ${STDCOLL_HEADERS} ${STDCOLL_IMPL})

add_library(stdcoll_st STATIC ${STDCOLL_ALL})
add_library(stdcoll_sh SHARED ${STDCOLL_ALL})

enable_testing()
include(CTest)

file(GLOB TEST_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/test/common/*)

file(GLOB LINKED_LIST_TEST ${TEST_IMPL}
     ${CMAKE_CURRENT_SOURCE_DIR}/test/stdcoll/linked_list_test.c)

add_executable(linked_list_test ${LINKED_LIST_TEST})

target_include_directories(linked_list_test
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_test(NAME linked_list_test COMMAND linked_list_test)
