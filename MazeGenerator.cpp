/* 
 * File:   MazeGenerator.cpp
 * Author: ovoloshchuk
 * 
 * Created on December 27, 2011, 3:13 PM
 */

#include "MazeGenerator.h"
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <stack>
#include <list>
#include <time.h>

#include <iostream>

using namespace std;

MazeGenerator::MazeGenerator() {
}

MazeGenerator::MazeGenerator(const MazeGenerator& orig) {
}

MazeGenerator::~MazeGenerator() {
}

void MazeGenerator::visit(Maze::Cell &pt, std::stack<Maze::Cell> &stPath, bool **ppVisited, int &nCounter) {
    stPath.push(pt);
    ppVisited[pt.col][pt.row] = true;
    nCounter--;
}

//returns a cell next to ptFrom in direction 'to'
Maze::Cell MazeGenerator::next(Maze::Cell ptFrom, Direction to) {
    Maze::Cell ptResult = ptFrom;
    switch (to) {
        case UP:
            ptResult.row--;
            break;
        case RIGHT:
            ptResult.col++;
            break;
        case DOWN:
            ptResult.row++;
            break;
        case LEFT:
            ptResult.col--;
            break;
    }
    return ptResult;
}

//returns a random direction available from the cell
//or NONE if the cell is blocked by other cells on all directions
Direction MazeGenerator::pickDirection(Maze::Cell& ptFrom, Maze& maze, bool** ppVisited) {
    list<Direction> lsDirs;
    for (int i = 0; i != (int) NONE; i++) {
        if (canGo(ptFrom, (Direction) i, maze, ppVisited))
            lsDirs.push_back((Direction) i);
    }
    if (lsDirs.empty())
        return NONE;
    int nIndex = rand() % lsDirs.size();
    list<Direction>::const_iterator iter = lsDirs.begin();
    for (int i = 0; i < nIndex; i++)
        iter++;
    return *iter;
}

//returns true if moving from ptFrom in the direction specified by 'to' is allowed
bool MazeGenerator::canGo(Maze::Cell& ptFrom, Direction to, Maze &maze, bool** ppVisited) {
    if (ptFrom.col < 0 || ptFrom.col >= maze.width()
            || ptFrom.row < 0 || ptFrom.row >= maze.height())
        return false;
    switch (to) {
        case UP:
            return (ptFrom.row - 1 >= 0
                    && !ppVisited[ptFrom.col][ptFrom.row - 1]);
        case RIGHT:
            return (ptFrom.col + 1 < maze.width()
                    && !ppVisited[ptFrom.col + 1][ptFrom.row]);
        case DOWN:
            return (ptFrom.row + 1 < maze.height()
                    && !ppVisited[ptFrom.col][ptFrom.row + 1]);
        case LEFT:
            return (ptFrom.col - 1 >= 0
                    && !ppVisited[ptFrom.col - 1][ptFrom.row]);
    }
    return false;
}

void MazeGenerator::generate(Maze &maze) {
    srand((unsigned) time(NULL));
    int width = maze.width(), height = maze.height();
    bool **ppVisited = new bool*[width]; //visited points matrix
    for (int i = 0; i < width; i++) {
        ppVisited[i] = new bool[height];
        memset(ppVisited[i], 0, height * sizeof (bool));
    }

    int nCol = 0;
    int nRow = rand() % height;
    Maze::Cell pt(nCol, nRow); //starting point
    Direction dir;

    int nCellsLeft = width*height;

    stack<Maze::Cell> stPath; //current path stack
    visit(pt, stPath, ppVisited, nCellsLeft);

    while (nCellsLeft > 0) {
        while ((dir = pickDirection(pt, maze, ppVisited)) != NONE) { //walk a path while possible
            maze.setWall(pt.col, pt.row, dir, false);
            pt = next(pt, dir);
            visit(pt, stPath, ppVisited, nCellsLeft);
        }
        stPath.pop();
        while (!stPath.empty()) { //backtrack until we find a cell 
            pt = stPath.top();    //from which we can start a new path
            if (pickDirection(pt, maze, ppVisited) != NONE)
                break;
            stPath.pop();
        }
    }

    for (int i = 0; i < width; i++)
        delete[] ppVisited[i];
    delete[] ppVisited;
}