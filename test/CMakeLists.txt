add_executable(
    unit_tests
    example_add.cpp
    example_subtract.cpp
    my_tests.cpp
    my_test_fixtures.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    example
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
