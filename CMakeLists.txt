cmake_minimum_required(VERSION 3.20)
project(make-symlink-win32 LANGUAGES CXX)

add_executable(make-symlink-win32 WIN32 src/main.cpp)

set_target_properties(make-symlink-win32 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(make-symlink-win32 PRIVATE cxx_std_20)

target_compile_options(make-symlink-win32 PRIVATE -municode)
target_link_options(make-symlink-win32 PRIVATE -municode)

target_link_libraries(make-symlink-win32 PRIVATE user32)

