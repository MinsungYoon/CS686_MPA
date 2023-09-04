#include <iostream>
#include <GL/glut.h>
#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/geometric/planners/prm/PRM.h>
#include <ompl/geometric/planners/prm/PRMstar.h>
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
Rectangle obstacle = {2.0, 2.0, 2.0, 2.0};
Rectangle obstacle2 = {6.0, 4.0, 2.0, 4.0};

bool isStateValid(const ob::State *state) {
    const auto *se2state = state->as<ob::SE2StateSpace::StateType>();
    double x = se2state->getX();
    double y = se2state->getY();

    // Check collision with the obstacle
    if (x >= obstacle.x && x <= obstacle.x + obstacle.width &&
        y >= obstacle.y && y <= obstacle.y + obstacle.height) {
        return false; // Invalid state due to collision with the obstacle
    }
    // Check collision with the obstacle2
    if (x >= obstacle2.x && x <= obstacle2.x + obstacle2.width &&
        y >= obstacle2.y && y <= obstacle2.y + obstacle2.height) {
        return false; // Invalid state due to collision with the obstacle
    }

    return true; // State is valid
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw obstacle
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(obstacle.x, obstacle.y);
    glVertex2f(obstacle.x + obstacle.width, obstacle.y);
    glVertex2f(obstacle.x + obstacle.width, obstacle.y + obstacle.height);
    glVertex2f(obstacle.x, obstacle.y + obstacle.height);
    glEnd();

    // Draw obstacle2
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(obstacle2.x, obstacle2.y);
    glVertex2f(obstacle2.x + obstacle2.width, obstacle2.y);
    glVertex2f(obstacle2.x + obstacle2.width, obstacle2.y + obstacle2.height);
    glVertex2f(obstacle2.x, obstacle2.y + obstacle2.height);
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
    // 1. Setup OMPL StateSpace and SpaceInformation
    auto space = std::make_shared<ob::SE2StateSpace>();
    ob::RealVectorBounds bounds(2);
    bounds.setLow(0);
    bounds.setHigh(10);
    space->setBounds(bounds);

    auto si = std::make_shared<ob::SpaceInformation>(space);
    si->setStateValidityChecker(isStateValid);
    si->setup();

    // 2. Define start and goal states
    ob::ScopedState<> start(space);
    start->as<ob::SE2StateSpace::StateType>()->setXY(1.0, 1.0);
    ob::ScopedState<> goal(space);
    goal->as<ob::SE2StateSpace::StateType>()->setXY(9.0, 9.0);

    // 3. Define the problem definition
    auto pdef = std::make_shared<ob::ProblemDefinition>(si);
    pdef->setStartAndGoalStates(start, goal);

    // 4. Create an RRT/RRTstar/PRM/PRMstar planner and set up the problem
    // by changing og::RRT part to og::RRTstar, og::PRM, or og::PRMstar.
    auto planner = std::make_shared<og::PRM>(si);
    planner->setProblemDefinition(pdef);
    planner->setup();

    // 5. Set a planner termination condition (i.e., time limit)
    ompl::base::PlannerTerminationCondition ptc = ompl::base::timedPlannerTerminationCondition(0.1);

    // 6. Solve the problem using the planner
    ob::PlannerStatus solved = planner->solve(ptc);

    // After solving the problem, update the treeEdges and path
    if (solved) {
        // Extract planner data and tree edges
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

        // Extract and store the solution path
        auto solutionPath = pdef->getSolutionPath()->as<og::PathGeometric>();
        for (std::size_t i = 0; i < solutionPath->getStateCount(); ++i) {
            const auto* state = solutionPath->getState(i)->as<ob::SE2StateSpace::StateType>();
            path.push_back({state->getX(), state->getY()});
        }
        std::cout << "Path length: " << solutionPath->length() << std::endl;
    }

    // Setup OpenGL and visualize the result
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
