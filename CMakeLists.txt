cmake_minimum_required (VERSION 3.8)

project ("UczPraktyka_3-v-4")

add_executable (CMakeProject1 "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 17)
endif()

file(COPY "input.txt" DESTINATION "/")