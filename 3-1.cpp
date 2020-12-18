#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string currentLine;
    std::ifstream inputFile("3-1.txt");


    int lineCount = 0;
    int treeCount = 0;

    int deltaY = 1;
    int deltaX = 3;
    while(getline(inputFile, currentLine)) {
        if(currentLine[(deltaX * lineCount) % currentLine.size()] == '#') {
            treeCount++;
        }

        lineCount++;
    }

    std::cout << treeCount << "\n";

    return 0;
}