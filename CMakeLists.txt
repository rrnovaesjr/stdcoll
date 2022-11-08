cmake_minimum_required(VERSION 3.22)

project(StdCollection LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header
                    ${CMAKE_CURRENT_SOURCE_DIR}/impl)

file(GLOB STDCOLL ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection.h
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection_impl.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/collection.c)

file(GLOB STDCOLL_INTERFACE ${STDCOLL}
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collections.h)

file(GLOB STDCOLL_LIST ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/list.h
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/list_impl.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/list.c)

file(GLOB STDCOLL_LINKED_LIST
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/linked_list.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/linked_list.c)

file(GLOB STDCOLL_INTERFACE_LINKED_LIST_IMPL ${STDCOLL_INTERFACE}
     ${STDCOLL_LINKED_LIST}
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/linked_list_collections.c)

file(GLOB STDCOLL_OPERATORS
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/operators.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/operators.c)

add_library(stdcoll STATIC ${STDCOLL})
add_library(stdcoll_interface STATIC ${STDCOLL_INTERFACE})

add_library(stdcoll_list STATIC ${STDCOLL_LIST})

add_library(stdcoll_linked_list STATIC ${STDCOLL_LINKED_LIST})
add_library(stdcoll_linked_list_st STATIC ${STDCOLL_INTERFACE_LINKED_LIST_IMPL})

add_library(stdcoll_operators_st STATIC ${STDCOLL_OPERATORS})

target_link_libraries(stdcoll_list PUBLIC stdcoll)
target_link_libraries(
  stdcoll_linked_list
  PUBLIC stdcoll_list
  PUBLIC stdcoll_operators_st)
target_link_libraries(
  stdcoll_linked_list_st
  PUBLIC stdcoll_interface
  PRIVATE stdcoll_list
  PRIVATE stdcoll_operators_st)

enable_testing()
include(CTest)

file(GLOB TEST_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/test/common/*)

add_executable(
  linked_list_test ${TEST_IMPL}
                   ${CMAKE_CURRENT_SOURCE_DIR}/test/stdcoll/linked_list_test.c)

add_executable(
  linked_list_st_test
  ${TEST_IMPL}
  ${CMAKE_CURRENT_SOURCE_DIR}/test/stdcoll/linked_list_test_as_coll_st.c)

target_link_libraries(
  linked_list_test
  PUBLIC stdcoll
  PUBLIC stdcoll_linked_list)

target_link_libraries(
  linked_list_st_test
  PUBLIC stdcoll_linked_list_st)

target_include_directories(linked_list_test
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test)

target_include_directories(linked_list_st_test
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_test(NAME linked_list_test COMMAND linked_list_test)
add_test(NAME linked_list_st_test COMMAND linked_list_st_test)
