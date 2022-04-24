cmake_minimum_required(VERSION 3.21)
project(Hash)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Hash main.cpp
        include/hash.h
        include/keywords_process.h
        include/hash_procress.h
        include/bi_procress.h)

add_executable(Test test.cpp)
