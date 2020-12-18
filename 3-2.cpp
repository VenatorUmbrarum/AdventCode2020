#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string currentLine;
    std::ifstream inputFile("3-1.txt");


    int lineCount = 0;
    //int treeCount = 0;

    int deltaYs[] = {1,1,1,1,2};
    int deltaXs[] = {1,3,5,7,1};
    int treeCounts[] = {0,0,0,0,0};
    while(getline(inputFile, currentLine)) {
        //std::cout << currentLine << "\n";
        for(int i = 0; i < 5; i++) {
            if((lineCount % deltaYs[i] == 0) && (currentLine[(deltaXs[i] * lineCount / deltaYs[i]) % currentLine.size()] == '#')) {
                //std::cout << "hit["<< i <<"]\n";
                treeCounts[i]++;
            }
        }

        lineCount++;
    }
    long long int treeProduct = 1;
    for(int i = 0; i < 5; i++) {
        std::cout << treeCounts[i] << "\n";
        treeProduct *= treeCounts[i];
    }

    std::cout << treeProduct << "\n";

    return 0;
}