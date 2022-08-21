cmake_minimum_required(VERSION 3.22)
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
    MESSAGE("CCACHE support enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE "Debug")

# add_compile_definitions(DEBUG)
function(add_code name path)
    add_executable(${name} ${path})
    target_link_libraries(${name})
    target_compile_definitions(${name} PRIVATE DEBUG=1)
endfunction()

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_code(graph "src/graph/GraphTests.cpp")

add_code(kickstart_2022_E_A "src/kickstart/2022/RoundE/A.cpp")
add_code(kickstart_2022_E_B "src/kickstart/2022/RoundE/B.cpp")
add_code(kickstart_2022_E_C "src/kickstart/2022/RoundE/C.cpp")
add_code(kickstart_2022_E_D "src/kickstart/2022/RoundE/D.cpp")