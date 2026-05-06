
cmake_minimum_required(VERSION 3.16)
project(ecxx CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include_directories(
  ${CMAKE_SOURCE_DIR}
)


file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
add_executable(ecxx ${SOURCES})



target_compile_options(ecxx PRIVATE 
    -Wall                  # Enable all common warnings
    -Wextra                # Extra warnings
    -Wno-unused-parameter  # Suppress unused parameter warnings
    -Wunused-variable      # Warn about unused variables
    -Wreturn-type          # Warn if a function might not return a value
    -Wno-redundant-move    # Suppress LLVM redundant move warning
    -g                     # Include debug information
)

