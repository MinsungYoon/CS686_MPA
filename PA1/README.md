# CS686: Motion Planning and Applications
## Problem Assignment 1

### Objective

Your task is to complete the provided code skeleton to implement motion planning algorithms using the Open Motion Planning Library (OMPL). Specifically, you will fill in the blanks to set up the problem and implement collision checks. You will then run the PRM, PRM*, RRT, and RRT* algorithms and visualize the results using OpenGL.

### Setup

#### 1-1. Installing OMPL

To install OMPL, you can use the package manager. On Ubuntu, run the following command:

```bash
sudo apt-get install libompl-dev
```

For more detailed installation instructions, you can refer to the [official OMPL installation guide](http://ompl.kavrakilab.org/installation.html).

#### 1-2. Installing OpenGL and Related Packages for Visualization

To install the necessary packages for OpenGL, execute the following command:

```bash
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

This will install:

- `libglu1-mesa-dev`: Development files for the OpenGL Utility Library (GLU)
- `freeglut3-dev`: Development files for the OpenGL Utility Toolkit (GLUT)
- `mesa-common-dev`: Development files for the Mesa 3D Graphics Library

#### 2. Compiling with CMake

To compile the code, you'll need to use CMake. Follow these steps:

1. install cmake
```bash
sudo apt install cmake
```
2. Navigate to the directory containing your `CMakeLists.txt` file.
3. Make build directory and move to it.
4. Run `cmake ..` to generate the Makefile.
5. Run `make` to compile the code.
6. Execute a compiled file (pa1_problem)

Here are the commands:
```bash
# Navigate to the directory of your project (e.g., PA1)
cd /path/to/your/project (e.g., PA1)

# Create a directory named 'build' for building your project
mkdir build

# Move into the 'build' directory
cd build

# Run CMake to generate build files (especially 'Makefile') in the 'build' directory
cmake ..

# Compile your project using the generated build files
make

# Run the executable of your project
./pa1_problem
```

After running these commands, you should see an executable file generated in your project directory. 
Run this executable to test your implementation and see the visualization of the result.

### Assignment Tasks
1. Try to build a cpp project using CMake and run the executable.
2. Try to run different algorithms by changing the planner in the code (i.e., pa1_problem.cpp):
    - PRM (Probabilistic Roadmap)
    - PRMstar (Optimized version of PRM)
    - RRT (Rapidly-exploring Random Trees)
    - RRTstar (Optimized version of RRT)

Note: After making modifications to the code, you need to recompile the project each time to ensure that the changes are reflected in the executable file.


3. For each planner, take a screenshot of the visualization results and attach it to the report.

### Submission Guide
You have to submit a report.
- Report: Make a PDF file containing visualization results.

Please submit the .pdf file via KLMS.

If you have any trouble, feel free to contact the TA (minsung.yoon@kaist.ac.kr).


---

