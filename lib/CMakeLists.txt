# lib/CMakeLists.txt
add_library(MyLibrary mylib.cpp)
target_include_directories(MyLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
