cmake_minimum_required(VERSION 3.1)
project(PA1_Problem)

# Find required packages
find_package(Eigen3 REQUIRED)        # Find the Eigen3 library
find_package(ompl REQUIRED)          # Find the OMPL library
find_package(OpenGL REQUIRED)        # Find the OpenGL library
find_package(GLUT REQUIRED)          # Find the GLUT library

# Include directories for header files
include_directories(
    ${OMPL_INCLUDE_DIRS}              # Include directories for OMPL headers
    ${EIGEN3_INCLUDE_DIR}             # Include directories for Eigen3 headers
    ${OPENGL_INCLUDE_DIRS}            # Include directories for OpenGL headers
    ${GLUT_INCLUDE_DIRS}              # Include directories for GLUT headers
)

# Create an executable named 'pa1_problem' from the source file 'pa1_problem.cpp'
add_executable(pa1_problem pa1_problem.cpp)

# Link required libraries to the executable
target_link_libraries(pa1_problem 
    ${OMPL_LIBRARIES}                 # Link the OMPL library
    ${EIGEN3_LIBRARIES}               # Link the Eigen3 library
    ${OPENGL_LIBRARIES}               # Link the OpenGL library
    ${GLUT_LIBRARY}                   # Link the GLUT library
)
