cmake_minimum_required(VERSION 3.0)

project(evolution-sim VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(evolution-sim
    main.cpp
    utils.cpp
    utils.h
    program.cpp
    program.h
    txtfileparser.cpp
    txtfileparser.h
    instruction.cpp
    instruction.h
    instructions/multiply.cpp
    instructions/multiply.h
    instructions/add.cpp
    instructions/add.h
    instructions/subtract.cpp
    instructions/subtract.h
    instructions/divide.cpp
    instructions/divide.h
    instructions/copy.cpp
    instructions/copy.h
    instructions/nop.cpp
    instructions/nop.h
    instructions/init.cpp
    instructions/init.h
    instructions/increase.cpp
    instructions/increase.h
    instructions/decrease.cpp
    instructions/decrease.h
    instructions/negate.cpp
    instructions/negate.h
    instructions/equal.cpp
    instructions/equal.h
    instructions/not.cpp
    instructions/not.h
    instructions/greater.cpp
    instructions/greater.h
    instructions/smaller.cpp
    instructions/smaller.h
    instructions/and.cpp
    instructions/and.h
    instructions/or_.cpp
    instructions/or_.h
    instructions/loop.cpp
    instructions/loop.h
    instructions/condition.cpp
    instructions/condition.h
    instructions/return.cpp
    instructions/return.h
)

target_include_directories(evolution-sim PRIVATE
    instructions
)
