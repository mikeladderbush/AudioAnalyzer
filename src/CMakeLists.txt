# src/CMakeLists.txt
add_executable(Analyzer main.cpp)
target_include_directories(Analyzer PRIVATE ${CMAKE_SOURCE_DIR}/include)
