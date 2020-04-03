add_library(alis_lib "")

target_sources(
    alis_lib
    PRIVATE
        alis_classes.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/alis_classes.h
    )

target_include_directories(
    alis_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
