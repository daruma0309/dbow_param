cmake_minimum_required(VERSION 3.0.2)
project(dbow3_param CXX)
add_compile_options(-std=c++11)

add_executable(dbow3_param src/main.cpp)

find_package(OpenCV REQUIRED)
find_package(DBoW3 REQUIRED)
#find_package(Eigen3 REQUIRED)

message(STATUS ${OpenCV_INCLUDE_DIRS})

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${DBoW3_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBRARIES}
  ${DBoW3_LIBS}
)
