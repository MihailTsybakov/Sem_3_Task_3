cmake_minimum_required(VERSION 3.1)

project(Task_3_Sem_3)

include_directories(${PROJECT_SOURCE_DIR})

set(TASK_3_SRC main.cpp Test.cpp SlideWdw.cpp)
set(TASK_3_HDR SlideWdw.h Test.h)

add_executable(${PROJECT_NAME} ${TASK_3_SRC} ${TASK_3_HDR})