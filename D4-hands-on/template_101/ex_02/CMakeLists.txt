cmake_minimum_required (VERSION 2.6)
project (template_101)

include_directories ("${PROJECT_SOURCE_DIR}/la")
add_subdirectory (la)
set (EXTRA_LIBS ${EXTRA_LIBS} la)

add_executable(temp_101 main.cpp)
target_link_libraries (temp_101  ${EXTRA_LIBS})
