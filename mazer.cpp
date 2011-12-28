/* 
 * File:   mazer.cpp
 * Author: seth
 *
 * Created on 21 грудня 2011, 20:13
 */

#include <cstdlib>
#include <iostream>
#include "Maze.h"
#include "MazeGenerator.h"

using namespace std;

void printMazeToConsole(Maze &m) {
    int width = m.width(), height = m.height();
    for (int col = 0; col < width; col++) {
        cout<<" _";
    }
    cout<<endl;
    for (int row = 0; row < height; row++) {
        cout<<"|";
        for (int col = 0; col < width; col++) {
            if (m.hasWall(col, row, DOWN))
                cout<<"_";
            else
                cout<<" ";
            if (m.hasWall(col, row, RIGHT))
                cout<<"|";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    int width = 15, height = 15;
    Maze m(width, height);
    
    MazeGenerator::generate(m);
    
    printMazeToConsole(m);
    
    return 0;
}

