cmake_minimum_required(VERSION 3.31)
project(dsa)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        arrays/sub_arrays.cpp
        arrays/sub_arrays.h
        arrays/pair_sum.cpp
        arrays/pair_sum.h
        arrays/k_rotate.cpp
        arrays/k_rotate.h
        other/LRUCache.cpp
        strings/RunLengthEncoding.cpp
        2d_arrays/SpiralPrint.cpp
        2d_arrays/StaircaseSearch.cpp
        vector/Vector.cpp
        vector/FindRank.cpp
)
