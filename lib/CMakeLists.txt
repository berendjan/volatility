add_library(
    lib_main
        Variance.cpp
    )

set_target_properties(
    lib_main

    PROPERTIES LINKER_LANGUAGE CXX
    )
