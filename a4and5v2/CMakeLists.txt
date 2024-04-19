cmake_minimum_required(VERSION 3.27)
project(a4_Robust_Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a4_Robust_Data_Structures
        Assert007.c
        Assert007.h
        Assert007.o
        gtest-all.o
        LinkedList.c
        LinkedList.h
        LinkedList.o
        LinkedList_easy.h
        Main.c
        Makefile
        release-1.8.0.tar.gz
        test_linkedlist.cc
        test_linkedlist.o
        v2_test_linkedlist.cpp)
