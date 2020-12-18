#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void trace(std::vector<std::vector<std::vector<bool>>> grid);
std::vector<std::vector<std::vector<bool>>> pad(std::vector<std::vector<std::vector<bool>>> grid);

int main() {
    std::vector<std::vector<std::vector<bool>>> grid = {{}};

    std::string currentLine;
    std::ifstream inputFile("17-1input");
    //std::ifstream inputFile("17example.txt");
    
    //std::cout << "Before while\n";
    unsigned int lineNo = 0;
    while(getline(inputFile, currentLine)) {
        //std::cout << currentLine;
        grid[0].push_back({});
        for(int i = 0; i < currentLine.size(); i++) {
            //std::cout << currentLine[i] << "\n";
            currentLine[i] == '\#' ? grid[0][lineNo].push_back(true) : grid[0][lineNo].push_back(false);
        }
        lineNo += 1;
    }
    //std::cout << "after while\n";

    for(int step = 0; step < 6; step++) {
        //std::cout << "Step: " << step << "\n";
        std::vector<std::vector<std::vector<bool>>> paddedGrid = pad(grid);

        //trace(paddedGrid);

        std::vector<std::vector<std::vector<bool>>> newGrid = {};

        for(int i = 0; i < paddedGrid.size(); i++) {
            newGrid.push_back({});
            //std::cout << "After first pushback\n";
            for(int j = 0; j < paddedGrid[0].size(); j++) {
                newGrid[i].push_back({});
                //std::cout << "After second pushback\n";
                for(int k = 0; k < paddedGrid[0][0].size(); k++) {

                    int neighborCount = 0; 
                    //std::cout << "Just declared neighborCount\n";
                    for(int x = i - 1; x < i + 2; x++) {
                        for(int y = j - 1; y < j + 2; y++) {
                            for(int z = k - 1; z < k + 2; z++) {
                                //std::cout << x << y << z << "\n";
                                if(!(x == i && y == j && z == k) && !(x == -1 || x == paddedGrid.size() || y == -1 || y == paddedGrid[0].size() || z == -1 || z == paddedGrid[0][0].size())) {
                                    if(paddedGrid[x][y][z]) {
                                        neighborCount++;
                                    } 
                                } else {
                                    //std::cout << "Out of bounds\n";
                                }
                            }
                        }
                    }
                    //std::cout << i << j << k << " Neighbor count: " << neighborCount << "\n";
                    if(paddedGrid[i][j][k] && (neighborCount == 2 || neighborCount == 3)) {
                        newGrid[i][j].push_back(true);
                        //std::cout << "still alive\n";
                    } else if(!paddedGrid[i][j][k] && neighborCount == 3) {
                        newGrid[i][j].push_back(true);
                        //std::cout << "born\n";
                    } else {
                        newGrid[i][j].push_back(false);
                        //std::cout << "dead\n";
                    }                    
                    //std:: cout << newGrid[i][j][k] << "\n";
                }
                //std::cout << "\n";
            }
            //std::cout << "\n\n";
        }

        grid = newGrid;
    }

    unsigned int aliveCount = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            for(int k = 0; k < grid[0][0].size(); k++) {
                if(grid[i][j][k]) {aliveCount++;}
                //std:: cout << grid[i][j][k];
            }
            //std::cout << "\n";
        }
        //std::cout << "\n\n";
    }
    //trace(grid);

    std::cout << aliveCount << "\n";

    return 0;
}


std::vector<std::vector<std::vector<bool>>> pad(std::vector<std::vector<std::vector<bool>>> grid) {
    std::vector<std::vector<std::vector<bool>>> newGrid = {};
    for(int i = 0; i < grid.size() + 2; i++) {
        newGrid.push_back({});
        for(int j = 0; j < grid[0].size() + 2; j++) {
            newGrid[i].push_back({});
            for(int k = 0; k < grid[0][0].size() + 2; k++) {
                if(i == 0 || i == grid.size() + 1 || j == 0 || j == grid[0].size() + 1 || k == 0 || k == grid[0][0].size() + 1) {
                    newGrid[i][j].push_back(false);
                } else {
                    newGrid[i][j].push_back(grid[i-1][j-1][k-1]);
                }
                //std:: cout << grid[i][j][k];
            }
            //std::cout << "\n";
        }
        //std::cout << "\n\n";
    }
    return newGrid;
}


void trace(std::vector<std::vector<std::vector<bool>>> grid) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            for(int k = 0; k < grid[0][0].size(); k++) {
                //if(grid[i][j][k]) {aliveCount++;}
                std:: cout << grid[i][j][k];
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
}