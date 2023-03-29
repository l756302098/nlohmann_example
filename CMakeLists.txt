cmake_minimum_required(VERSION 3.5)

# Set the project name
project (json_samples)

find_package(Boost REQUIRED COMPONENTS filesystem system)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

add_executable(json_samples main.cpp json.hpp)

target_link_libraries(json_samples
${Boost_LIBRARIES}
pthread)
