
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

#### 2. Compiling with CMake (** after writing a skeleton code **) 

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
cd /path/to/your/project (e.g., PA1)
mkdir build
cd build
cmake ..
make
./pa1_problem
```

After running these commands, you should see an executable file generated in your project directory. 
Run this executable to test your implementation and see the visualization of the result.

### Assignment Tasks: Fill in 'PLACE YOUR CODE HERE' sections
1. (pa1_problem.cpp) Complete the setup of the state space, bounds, and space information in the provided code skeleton.
2. (pa1_problem.cpp) Fill in the blanks in the `isStateValid` function to implement collision checking.
3. (pa1_problem.cpp) Set and Run the following planning algorithms and visualize their paths and obstacles:
    - PRM (Probabilistic Roadmap)
    - PRMstar (Optimized version of PRM)
    - RRT (Rapidly-exploring Random Trees)
    - RRTstar (Optimized version of RRT)
4. For each planner, take a screenshot of the visualization results and attach it to the report.

### Submission Guide
You have to submit two types of materials: report and code.
- Report: Make a PDF file containing visualization results.
- Code: a pa1_problem.cpp file

Generate a zip file of your code and report, then save your zip file as cs686_yourname_studentID.zip.

Please submit the .zip file via KLMS.

---

