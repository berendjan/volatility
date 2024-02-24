include(GoogleTest)

add_executable(main_tests test.cpp)

find_package(GTest REQUIRED)

target_link_libraries(
    main_tests
    lib_main
    GTest::gtest_main
    )

target_include_directories(main_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/)

gtest_discover_tests(main_tests)
