cmake_minimum_required(VERSION 3.28)
project(LearningMultiThreading)

set(CMAKE_CXX_STANDARD 23)

# Executables for Modern CPP Crash Course
#add_executable(LearningMultiThreading main.cpp)
#add_executable(InitExample "ModernCPP/initalizersExample.cpp")
#add_executable(NullExample "ModernCPP/exampleOfNull.cpp")
#add_executable(ChronoExample "ModernCPP/exampleOfChrono.cpp")
#add_executable(AutoExample "ModernCPP/autoTypeExample.cpp")
#add_executable(LambdaExample "ModernCPP/lambdaExamples.cpp")
#add_executable(MoveSemanticsEx "ModernCPP/moveSemanticsExample.cpp")
#add_executable(Overload "ModernCPP/overloadingOnValueType.cpp")
#add_executable(Operators "ModernCPP/defaultAndDeleteExample.cpp")
#add_executable(LambdaLocal "ModernCPP/lambdaLoaclVar.cpp")
#add_executable(CaptureByMove "ModernCPP/lambdaCaptureByMove.cpp")
#add_executable(RandomGen "ModernCPP/randomGenerator.cpp")
#add_executable(UniqPtr "ModernCPP/uniquePtrsExample.cpp")

# Executables for Introduction to Concurrency Dir
#add_executable(HelloThread "Intro_to_Concurrency/helloThread.cpp")
#add_executable(HelloFunctor "Intro_to_Concurrency/helloFunctor.cpp")
#add_executable(HelloLambda "Intro_to_Concurrency/helloLambda.cpp")
#add_executable(ArgsInThread "Intro_to_Concurrency/argsWithThreads.cpp")
#add_executable(PassByMove "Intro_to_Concurrency/passByMove.cpp")
#add_executable(PassByRef "Intro_to_Concurrency/passByRef.cpp")
#add_executable(PassByMember "Intro_to_Concurrency/passMemberFunc.cpp")
#add_executable(PassByLambdaRef "Intro_to_Concurrency/passByLambdaRef.cpp")
#add_executable(PassByLambdaArg "Intro_to_Concurrency/passByLambdaArgs.cpp")

# System Thread Interface Dir Executables
#add_executable(NativeHandle "Starting_With_Threads/System_Thead_Interface/nativeHandle.cpp")
#add_executable(HelloID "Starting_With_Threads/System_Thead_Interface/helloThreadId.cpp")
#add_executable(HelloSleep "Starting_With_Threads/System_Thead_Interface/helloSleep.cpp")

# C++ Thread Classes Dir Executables
#add_executable(MoveThread "Starting_With_Threads/CPP_Thead_Class/moveThread.cpp")
#add_executable(ReturnThread "Starting_With_Threads/CPP_Thead_Class/returningThread.cpp")
#add_executable(ThrowExecpt "Starting_With_Threads/CPP_Thead_Class/throwExceptThread.cpp")

# Managing a Thread Dir Executables
#add_executable(Detach "Starting_With_Threads/Manage_A_Thread/detach.cpp")
#add_executable(UnsafeThrow "Starting_With_Threads/Manage_A_Thread/threadExceptUnsafe.cpp")
#add_executable(SafeThrow "Starting_With_Threads/Manage_A_Thread/threadExceptionSafe.cpp")
#add_executable(ThreadGuard "Starting_With_Threads/Manage_A_Thread/threadGuard.cpp")

# Multiple Thread Dir Executables
add_executable(MultiThreads "Starting_With_Threads/Multiple_Threads/multipleThreads.cpp")