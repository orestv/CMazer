/* 
 * File:   Maze.cpp
 * Author: seth
 * 
 * Created on 21 грудня 2011, 20:14
 */

#include "Maze.h"
#include <memory.h>

Maze::Maze(int width, int height) {
    m_ppHorizontalWalls = 0;
    m_ppVerticalWalls = 0;
    init(width, height);
}

Maze::Maze(const Maze& orig) {
    init(orig.m_nWidth, orig.m_nHeight);
    
    for (int i = 0; i < m_nWidth+1; i++)
        memcpy(m_ppHorizontalWalls[i], orig.m_ppHorizontalWalls[i], (m_nHeight+1)*sizeof(bool));
}

Maze::~Maze() {
    destroy();
}

void Maze::destroy() {
    if (m_ppHorizontalWalls != 0 && m_nWidth > 0) {
        for (int i = 0; i < m_nWidth; i++)
            delete[] m_ppHorizontalWalls[i];
        delete[] m_ppHorizontalWalls;
        m_ppHorizontalWalls = 0;
    }
    
    if (m_ppVerticalWalls != 0 && m_nHeight > 0) {
        for (int i = 0; i < m_nWidth+1; i++)
            delete[] m_ppVerticalWalls[i];        
        delete[] m_ppVerticalWalls;
    }
}

int Maze::width() {
    return m_nWidth;
}

int Maze::height() {
    return m_nHeight;
}

Maze::Cell::Cell(int col, int row) {
    this->col = col;
    this->row = row;
}

void Maze::init(int width, int height) {
    destroy();
    
    m_nWidth = width;
    m_nHeight = height;
    
    m_ppVerticalWalls = new bool*[m_nWidth+1];
    m_ppHorizontalWalls = new bool*[m_nWidth];
    
    for (int nCol = 0; nCol < m_nWidth+1; nCol++) {
        m_ppVerticalWalls[nCol] = new bool[m_nHeight];
        for (int nRow = 0; nRow < m_nHeight; nRow++)
            m_ppVerticalWalls[nCol][nRow] = true;
    }    
    for (int nCol = 0; nCol < m_nWidth; nCol++) {
        m_ppHorizontalWalls[nCol] = new bool[m_nHeight+1];
        for (int nRow = 0; nRow < m_nHeight+1; nRow++)
            m_ppHorizontalWalls[nCol][nRow] = true;
    }
}

bool& Maze::getWallReference(int nCol, int nRow, Direction dir) {
    switch (dir) {
        case UP:
            return m_ppHorizontalWalls[nCol][nRow];
        case RIGHT:
            return m_ppVerticalWalls[nCol+1][nRow];
        case DOWN:
            return m_ppHorizontalWalls[nCol][nRow+1];            
        case LEFT:
            return m_ppVerticalWalls[nCol][nRow];            
    }
}

bool Maze::hasWall(int nCol, int nRow, Direction dir) {    
    if (nCol<0 || nRow<0 || nCol > m_nWidth || nRow > m_nHeight)
        return false;
    return getWallReference(nCol, nRow, dir);
}

void Maze::setWall(int nCol, int nRow, Direction dir, bool bWall) {
    if (nCol<0 || nRow<0 || nCol > m_nWidth || nRow > m_nHeight)
        return;
    bool &bExistingWall = getWallReference(nCol, nRow, dir);
    bExistingWall = bWall;
}
