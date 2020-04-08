cmake_minimum_required(VERSION 3.0)

project(calculator_API)

add_executable(calculator_API 
    calculator_API.cpp 
    Calculator_resource.cpp)
target_link_libraries(calculator_API restbed)
target_include_directories(calculator_API PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_property(TARGET calculator_API PROPERTY CXX_STANDARD 17)