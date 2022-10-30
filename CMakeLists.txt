cmake_minimum_required(VERSION 3.22)

project(StdCollection LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header
                    ${CMAKE_CURRENT_SOURCE_DIR}/impl)

file(GLOB STDCOLL ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection.h
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/collection_impl.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/collection.c)

file(GLOB STDCOLL_LIST ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/list.h
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/list_impl.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/list.c)

file(GLOB STDCOLL_LINKED_LIST
     ${CMAKE_CURRENT_SOURCE_DIR}/header/stdcoll/linked_list.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stdcoll/linked_list.c)

add_library(stdcoll_st STATIC ${STDCOLL})
add_library(stdcoll_sh SHARED ${STDCOLL})

add_library(stdcoll_list_st STATIC ${STDCOLL_LIST})
add_library(stdcoll_list_sh SHARED ${STDCOLL_LIST})

add_library(stdcoll_linked_list_st STATIC ${STDCOLL_LINKED_LIST})
add_library(stdcoll_linked_list_sh SHARED ${STDCOLL_LINKED_LIST})

target_link_libraries(stdcoll_list_st PUBLIC stdcoll_st)
target_link_libraries(stdcoll_list_sh PUBLIC stdcoll_sh)
target_link_libraries(stdcoll_linked_list_st PUBLIC stdcoll_list_st)
target_link_libraries(stdcoll_linked_list_sh PUBLIC stdcoll_list_sh)

enable_testing()
include(CTest)

file(GLOB TEST_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/test/common/*)

add_executable(
  linked_list_test ${TEST_IMPL}
                   ${CMAKE_CURRENT_SOURCE_DIR}/test/stdcoll/linked_list_test.c)

target_link_libraries(linked_list_test PUBLIC stdcoll_linked_list_st)

target_include_directories(linked_list_test
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_test(NAME linked_list_test COMMAND linked_list_test)
