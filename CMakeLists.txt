cmake_minimum_required(VERSION 3.0)

project (crystal_swirl)

file(GLOB_RECURSE Foo_SOURCES "source/*.cpp")
file(GLOB_RECURSE Foo_HEADERS "source/*.hpp")

set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable (FooExe ${Foo_SOURCES})
target_include_directories(FooExe PRIVATE ${Foo_INCLUDE_DIRS})