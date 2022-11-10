cmake_minimum_required(VERSION 3.22)

project(StdCollection LANGUAGES C)

option(BUILD_TESTING "Build tests" ON)

if(MSVC)
  add_compile_options("/permissive-" "/W4" "/w14640")
else()
  add_compile_options("-Wall" "-Wextra" "-Wshadow" "-pedantic" "-fPIC")
endif()

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

file(GLOB STDCOLL_ITR ${CMAKE_CURRENT_SOURCE_DIR}/header/stditr/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/impl/stditr/*.c)

add_library(stdcoll STATIC ${STDCOLL})
add_library(stdcoll_interface_st STATIC ${STDCOLL_INTERFACE})
add_library(stdcoll_interface STATIC ${STDCOLL_INTERFACE})

add_library(stdcoll_list STATIC ${STDCOLL_LIST})

add_library(stdcoll_linked_list STATIC ${STDCOLL_LINKED_LIST})
add_library(stdcoll_linked_list_st STATIC ${STDCOLL_INTERFACE_LINKED_LIST_IMPL})
add_library(stdcoll_linked_list_sh SHARED ${STDCOLL_INTERFACE_LINKED_LIST_IMPL})

add_library(stdcoll_operators_st STATIC ${STDCOLL_OPERATORS})

add_library(stdcoll_itr STATIC ${STDCOLL_ITR})

target_link_libraries(stdcoll PUBLIC stdcoll_itr)
target_link_libraries(
  stdcoll_list
  PUBLIC stdcoll
  PUBLIC stdcoll_itr)
target_link_libraries(
  stdcoll_linked_list
  PUBLIC stdcoll_list
  PUBLIC stdcoll_operators_st
  PUBLIC stdcoll_itr)
target_link_libraries(
  stdcoll_linked_list_st
  PUBLIC stdcoll_interface_st
  PRIVATE stdcoll_list
  PRIVATE stdcoll_operators_st
  PUBLIC stdcoll_itr)
target_link_libraries(
  stdcoll_linked_list_sh
  PUBLIC stdcoll_interface_st
  PRIVATE stdcoll
  PRIVATE stdcoll_list
  PRIVATE stdcoll_operators_st
  PUBLIC stdcoll_itr)

if(BUILD_TESTING)
  include(CTest)
  include_directories(${CMAKE_SOURCE_DIR}/test)
  add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()
