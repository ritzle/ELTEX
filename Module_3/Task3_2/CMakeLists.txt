cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_C_STANDARD 99)

add_executable(sum sum.c)
add_executable(div div.c)
add_executable(mul mul.c)
add_executable(sub sub.c)

add_executable(main task3_2.c)
