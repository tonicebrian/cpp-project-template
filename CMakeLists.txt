project(project_name)
cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_CXX_FLAGS "--std=c++0x")          

include_directories(include)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) 

find_package(Boost COMPONENTS regex REQUIRED)

add_executable(project_name src/main.cpp
              )

# Testing
find_package(CppUnit REQUIRED)
include_directories(include test)
add_executable(UnitTester test/main.cpp
                          test/SampleTest.cpp
              )

target_link_libraries(UnitTester ${CPPUNIT_LIBRARIES}
                                 ${Boost_REGEX_LIBRARY}
                                 )

