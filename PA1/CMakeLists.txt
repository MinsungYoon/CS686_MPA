cmake_minimum_required(VERSION 3.1)
project(MyOMPLProject)

find_package(Eigen3 REQUIRED)
find_package(ompl REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(
    ${OMPL_INCLUDE_DIRS} 
    ${EIGEN3_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)

add_executable(pa1_solution pa1_solution.cpp)
target_link_libraries(pa1_solution 
    ${OMPL_LIBRARIES} 
    ${EIGEN3_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
)
