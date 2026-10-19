cmake_minimum_required(VERSION 3.20)
project(make-symlink-win32 LANGUAGES CXX)

add_executable(make-symlink-win32 src/main.cpp
        src/windows/Api.cpp
        src/windows/Api.h
        resources/app.rc
)

set_target_properties(make-symlink-win32 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(make-symlink-win32 PRIVATE cxx_std_20)

target_compile_options(make-symlink-win32 PRIVATE -municode)
target_link_options(make-symlink-win32 PRIVATE -municode -static)

target_link_libraries(make-symlink-win32 PRIVATE user32)
set_source_files_properties(
        resources/app.rc PROPERTIES OBJECT_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/resources/app.manifest.xml"
)
