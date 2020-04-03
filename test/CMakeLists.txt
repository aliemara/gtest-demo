add_executable(
    unit_tests
    my_tests.cpp
    my_test_fixtures.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    alis_lib
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
