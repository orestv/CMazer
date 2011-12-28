/* 
 * File:   Maze.h
 * Author: seth
 *
 * Created on 21 грудня 2011, 20:14
 */

#ifndef MAZE_H
#define	MAZE_H

enum Direction {UP, RIGHT, DOWN, LEFT, NONE};

class Maze {
public:
    Maze(int width, int height);
    Maze(const Maze& orig);
    virtual ~Maze();
    
    bool hasWall(int x, int y, Direction dir);
    void setWall(int x, int y, Direction dir, bool bWall);
    
    int width();
    int height();
    
    struct Cell {
        int col;
        int row;
        Cell(int col, int row);
    };
private:
    void init(int width, int height);
    virtual void destroy();
    
    bool& getWallReference(int nCol, int nRow, Direction dir);
    
    bool **m_ppHorizontalWalls;
    bool **m_ppVerticalWalls;
    
    int m_nWidth;
    int m_nHeight;
};

#endif	/* MAZE_H */

