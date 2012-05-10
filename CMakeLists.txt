project(project_name)
cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_CXX_FLAGS "--std=c++0x")          

include_directories(include)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) 

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(project_name src/main.cpp
              )

target_link_libraries(project_name ${Boost_PROGRAM_OPTIONS_LIBRARY})

# Testing
find_package(CppUnit REQUIRED)
add_executable(UnitTester test/main.cpp
              )

target_link_libraries(UnitTester ${CPPUNIT_LIBRARIES})

