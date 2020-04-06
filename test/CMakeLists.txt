add_executable(
    unit_tests
    alis_tests.cpp
    alis_mocks.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    gmock_main
    alis_lib
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
