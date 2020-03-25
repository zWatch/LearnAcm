cmake_minimum_required(VERSION 3.0.0)
project(LearnACM VERSION 0.1.0)

# include(CTest)
#enable_testing()

#add_executable(LearnACM main.cpp)

#add_executable(newcoder_guazi2019_1 newcoder/guazi2019/T1.cpp)
#add_executable(newcoder_guazi2019_2 newcoder/guazi2019/T2.cpp)
#add_executable(newcoder_guazi2019_3 newcoder/guazi2019/T3.cpp)

add_subdirectory(Learn)

add_executable(leetcode "ACM/leetcode/main.cpp")

#add_executable(Dec927Lua "C:/Users/NYJ/WorkSpace/LearnACM/Interesting/Dec927Lua.cpp")

add_executable(General General/main.cpp)

add_executable(TestCPP Test/cpp/main.cpp)


#add_subdirectory(Interesting)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
