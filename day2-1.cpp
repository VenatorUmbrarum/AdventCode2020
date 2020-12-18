#include <iostream>
#include <fstream>
#include <string>

//This is actually the second part of day 2, I forgot to save a new file

int main() {
    std::string currentLine;
    std::ifstream inputFile("2-1.txt");
    //std::ifstream inputFile("17example.txt");
    
    unsigned int validCount = 0;

    unsigned int lineNo = 0;
    while(getline(inputFile, currentLine)) {
        int hyphenIndex, colonIndex;
        //std::cout << currentLine << "\n";
        for(int i = 0; i < currentLine.size(); i++) {
            //std::cout << currentLine[i] << "\n";
            if(currentLine[i] == '-') {
                hyphenIndex = i;
            } else if(currentLine[i] == ':') {
                colonIndex = i;
                //break;
                //Could use string::find but I'm not sure how it works - not a big deal for one char though
            }
            
        }
        //std::cout << "hyphen " << hyphenIndex << " colon " << colonIndex << "\n";
        int min, max;
        min = std::stoi(currentLine.substr(0,hyphenIndex));
        max = std::stoi(currentLine.substr(hyphenIndex+1, colonIndex-hyphenIndex-3));
        //std::cout << "values " << min << "-" << max << "\n";
        char targetChar = currentLine.substr(colonIndex - 1, 1)[0];
        //std::cout << targetChar << "\n";
        unsigned int charCount = 0;
        if(currentLine[min + colonIndex + 1] == targetChar) {
            charCount++;
        }
        if(currentLine[max + colonIndex + 1] == targetChar) {
            charCount++;
        }
        //std::cout << currentLine << "\n";
        //std::cout << "count " << charCount << "\n";
        if(charCount == 1) {
            validCount++;
            //std::cout << "valid\n";
        }

        lineNo += 1;
    }

    std::cout << validCount << "\n";

    return 0;
}