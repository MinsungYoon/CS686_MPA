Certainly! Here's the revised assignment description with the tasks reordered.

---

# CS686: Motion Planning and Applications
## Problem Assignment 1

### Objective

Your task is to complete the provided code skeleton to implement motion planning algorithms using the Open Motion Planning Library (OMPL). Specifically, you will fill in the blanks to set up the problem and implement collision checks. You will then run the PRM, PRM*, RRT, and RRT* algorithms and visualize the results using OpenGL.

### Setup

#### Installing OMPL

To install OMPL, you can use the package manager. On Ubuntu, run the following command:

```bash
sudo apt-get install libompl-dev
```

For more detailed installation instructions, you can refer to the [official OMPL installation guide](http://ompl.kavrakilab.org/installation.html).

#### Installing OpenGL and Related Packages

To install the necessary packages for OpenGL, execute the following command:

```bash
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

This will install:

- `libglu1-mesa-dev`: Development files for the OpenGL Utility Library (GLU)
- `freeglut3-dev`: Development files for the OpenGL Utility Toolkit (GLUT)
- `mesa-common-dev`: Development files for the Mesa 3D Graphics Library

#### Compiling with CMake

To compile the code, you'll need to use CMake. Follow these steps:

1. install cmake
```bash
using sudo apt install cmake
```
2. Navigate to the directory containing your `CMakeLists.txt` file.
3. Run `cmake .` to generate the Makefile.
4. Run `make` to compile the code.

Here are the commands:

```bash
cd /path/to/your/project (e.g., PA1)
mkdir build
cd build
cmake ..
make
```

After running these commands, you should see an executable file generated in your project directory. 
Run this executable to test your implementation and see the visualization of the result.

### Assignment Tasks

1. Complete the setup of the state space, bounds, and space information in the provided code skeleton.
2. Fill in the blanks in the `isStateValid` function to implement collision checking.
3. Run the following algorithms and visualize their paths and obstacles:
    - PRM (Probabilistic Roadmap)
    - PRM* (Optimized version of PRM)
    - RRT (Rapidly-exploring Random Trees)
    - RRT* (Optimized version of RRT)

---

Feel free to add or modify sections as needed for your specific assignment requirements.
