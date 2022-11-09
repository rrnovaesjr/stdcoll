message(STATUS "Adding test subfolder")
include(CTest)
enable_testing()

file(GLOB MAIN_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

# ------------------------- TEST FRAMEWORK DEPENDENCIES
# ------------------------- begin
file(GLOB ASSERT_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/assert/*)
file(GLOB ASSERTIONS_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/assertions/*)
file(GLOB LOG_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/log/*)
file(GLOB SUITE_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/suite/*)

add_library(assert STATIC ${ASSERT_IMPL})
add_library(assertions SHARED ${ASSERTIONS_IMPL} ${LOG_IMPL})
add_library(test_suite STATIC ${SUITE_IMPL} ${MAIN_IMPL} ${LOG_IMPL})

target_link_libraries(assertions PRIVATE stdcoll_linked_list)

target_link_libraries(
  test_suite
  PUBLIC assert
  PUBLIC assertions)

target_link_libraries(assert PUBLIC assertions)
# ------------------------- TEST FRAMEWORK DEPENDENCIES
# ------------------------- end

add_executable(linked_list_test
               ${CMAKE_CURRENT_SOURCE_DIR}/stdcoll/linked_list_test.c)

add_executable(linked_list_st_as_coll_test
               ${CMAKE_CURRENT_SOURCE_DIR}/stdcoll/collections_test.c)

add_executable(linked_list_sh_as_coll_test
               ${CMAKE_CURRENT_SOURCE_DIR}/stdcoll/collections_test.c)

target_link_libraries(
  linked_list_test
  PUBLIC test_suite
  PUBLIC stdcoll_linked_list)

target_link_libraries(
  linked_list_st_as_coll_test
  PUBLIC test_suite
  PUBLIC stdcoll_interface
  PUBLIC stdcoll_linked_list_st)

target_link_libraries(
  linked_list_sh_as_coll_test
  PUBLIC test_suite
  PUBLIC stdcoll_interface
  PUBLIC stdcoll_linked_list_sh)

add_test(NAME linked_list_test COMMAND linked_list_test)
add_test(NAME linked_list_st_as_coll_test COMMAND linked_list_st_as_coll_test)
add_test(NAME linked_list_sh_as_coll_test COMMAND linked_list_sh_as_coll_test)
