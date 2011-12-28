/* 
 * File:   MazeGenerator.h
 * Author: ovoloshchuk
 *
 * Created on December 27, 2011, 3:13 PM
 */

#ifndef MAZEGENERATOR_H
#define	MAZEGENERATOR_H

#include "Maze.h"
#include <stack>

class MazeGenerator {
public:
    MazeGenerator();
    MazeGenerator(const MazeGenerator& orig);
    virtual ~MazeGenerator();
    
    static void generate(Maze &maze);
    static bool canGo(Maze::Cell &ptFrom, Direction to, Maze &maze, bool **ppVisited);
    static Direction pickDirection (Maze::Cell &ptFrom, Maze &maze, bool **ppVisited);
    static void markVisited(Maze::Cell &pt, std::stack<Maze::Cell> &stPath, bool **ppVisited, int &nCounter);
    static Maze::Cell next(Maze::Cell ptFrom, Direction to);
    
private:
    
};

#endif	/* MAZEGENERATOR_H */

