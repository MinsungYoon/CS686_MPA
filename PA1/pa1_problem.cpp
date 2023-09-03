#include <iostream>
#include <GL/glut.h>
#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/base/PlannerData.h>
#include <vector>

namespace ob = ompl::base;
namespace og = ompl::geometric;

struct Point {
    double x, y;
};

struct Rectangle {
    double x, y, width, height;
};

std::vector<Point> path;  // To store the best path
std::vector<std::pair<Point, Point>> treeEdges;  // To store the tree edges

Rectangle obstacle = {3.0, 3.0, 2.0, 2.0}; // obs spec: {x, y, width, height}
bool isStateValid(const ob::State *state) {
    """
     TODO: Implement this function to check if the state is valid
     Hint 1: Use the 'obstacle' global variable to check for collision
     Hint 2: You can get the x and y coordinates from the state using state->as<ob::SE2StateSpace::StateType>()->getX() and getY()
     Hint 3: Check if the x and y coordinates are within the obstacle boundaries
    """
    // PLACE YOUR CODE HERE
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw obstacle
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(obstacle.x, obstacle.y);
    glVertex2f(obstacle.x + obstacle.width, obstacle.y);
    glVertex2f(obstacle.x + obstacle.width, obstacle.y + obstacle.height);
    glVertex2f(obstacle.x, obstacle.y + obstacle.height);
    glEnd();

    // Draw tree in sky blue
    glColor3f(0.53, 0.81, 0.98);
    glBegin(GL_LINES);
    for (const auto& edge : treeEdges) {
        glVertex2f(edge.first.x, edge.first.y);
        glVertex2f(edge.second.x, edge.second.y);
    }
    glEnd();

    // Draw path in red
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (const auto& point : path) {
        glVertex2f(point.x, point.y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    // Setup OMPL
    """
     TODO: Setup the state space, bounds, and space information
     Hint 1: Create an instance of ob::SE2StateSpace for the state space
     Hint 2: Create an instance of ob::RealVectorBounds and set the bounds for x and y to be [0, 10]
     Hint 3: Use the setBounds method of the state space to set the bounds
    """
    // PLACE YOUR CODE HERE

    """
     TODO: Create a SpaceInformation object and set its state validity checker
     Hint 1: Create an instance of ob::SpaceInformation and pass the state space to it
     Hint 2: Use setStateValidityChecker method to set 'isStateValid' as the state validity checker
    """
    // PLACE YOUR CODE HERE

    """
     TODO: Setup start and goal states
     Hint 1: Create instances of ob::ScopedState for the start and goal states
     Hint 2: Use the setXY method of ob::SE2StateSpace::StateType to set the start state to (0, 0) and the goal state to (10, 10)
    """
    // PLACE YOUR CODE HERE

    """
     TODO: Setup the problem definition
     Hint 1: Create an instance of ob::ProblemDefinition
     Hint 2: Use the setStartAndGoalStates method to set the start and goal states
    """
    // PLACE YOUR CODE HERE

    """
     TODO: Setup the planner and associate it with the problem definition
     Hint 1: Create an instance of og::RRT/RRTstar/PRM/PRMstar as the planner
     Hint 2: Use the setProblemDefinition method to associate the planner with the problem definition
    """
    // PLACE YOUR CODE HERE
    
    ompl::base::PlannerTerminationCondition ptc = ompl::base::timedPlannerTerminationCondition(1.0);
    ob::PlannerStatus solved = planner->solve(ptc);

    // After solving the problem, update the treeEdges and path
    if (solved) {
        ob::PlannerData plannerData(si);
        planner->getPlannerData(plannerData);
        treeEdges.clear();
        for (unsigned int i = 0; i < plannerData.numVertices(); ++i) {
            const auto* vertex = plannerData.getVertex(i).getState()->as<ob::SE2StateSpace::StateType>();
            Point vertexPoint = {vertex->getX(), vertex->getY()};
            std::vector<unsigned int> edgeList;
            plannerData.getEdges(i, edgeList);
            for (auto j : edgeList) {
                const auto* edge = plannerData.getVertex(j).getState()->as<ob::SE2StateSpace::StateType>();
                Point edgePoint = {edge->getX(), edge->getY()};
                treeEdges.push_back({vertexPoint, edgePoint});
            }
        }

        auto solutionPath = pdef->getSolutionPath()->as<og::PathGeometric>();
        for (std::size_t i = 0; i < solutionPath->getStateCount(); ++i) {
            const auto* state = solutionPath->getState(i)->as<ob::SE2StateSpace::StateType>();
            path.push_back({state->getX(), state->getY()});
        }
        std::cout << "Path length: " << solutionPath->length() << std::endl;
    }

    // Setup OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("RRT* Path with Obstacle");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 10, 0, 10);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
