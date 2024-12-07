#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Text_Extension.h"
using namespace std;
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void readFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error 0: Failed to open the specified text file: " << filename << endl;
        return;
    }
    string line;
    clearConsole();
    while (getline(inputFile, line)) {
        size_t startPos = 0;
        while ((startPos = line.find('<', startPos)) != string::npos) {
            size_t endPos = line.find('>', startPos);
            if (endPos != string::npos) {
                string text = line.substr(startPos + 1, endPos - startPos - 1);
                formatAndPrint(text);
                startPos = endPos + 1;

            }
            else {
                break;
            }
        }
    }
    inputFile.close();
}
int main() {
    string filename;
    cout << "Enter the name of the text file with the .median extension (or specify its path): " << endl;
    getline(cin, filename);
    readFile(filename);
    return 0;
}

