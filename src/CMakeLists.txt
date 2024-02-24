

add_executable(
    Main
    main.cpp
    )

target_link_libraries(
    Main
    lib_main
    )

target_include_directories(Main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/)

set_target_properties(
    Main

    PROPERTIES LINKER_LANGUAGE CXX
    )

