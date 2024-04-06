cmake_minimum_required(VERSION 3.0)
project(HonyakuBot)

set(CMAKE_CXX_STANDARD 17)
include_directories(app)

# Add executable
add_executable(HonyakuBot app/aictl.cpp)

# Find Python
find_package(Python3 COMPONENTS Interpreter Development)

# Include Python headers
include_directories(${Python3_INCLUDE_DIRS})

# Link against Python library
target_link_libraries(HonyakuBot PRIVATE ${Python3_LIBRARIES})