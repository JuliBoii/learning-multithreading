cmake_minimum_required(VERSION 3.28)
project(LearningMultiThreading)

set(CMAKE_CXX_STANDARD 23)

add_executable(LearningMultiThreading main.cpp)
add_executable(InitExample "ModernCPP/initalizersExample.cpp")
add_executable(NullExample "ModernCPP/exampleOfNull.cpp")
add_executable(ChronoExample "ModernCPP/exampleOfChrono.cpp")
add_executable(AutoExample "ModernCPP/autoTypeExample.cpp")
add_executable(LambdaExample "ModernCPP/lambdaExamples.cpp")
add_executable(MoveSemanticsEx "ModernCPP/moveSemanticsExample.cpp")