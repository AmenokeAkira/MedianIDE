#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Text_Extension.h"
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;
void find_directory(const fs::path& current_path, const std::string& target_directory) {
    try {
        for (const auto& entry : fs::directory_iterator(current_path)) {
            if (entry.is_directory()) {
                if (entry.path().filename() == target_directory) {
                    std::cout << "\\Median\\pathInclude\\" << entry.path() << std::endl;
                }
                find_directory(entry.path(), target_directory);
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
        std::cout << "Please download the extension folder from GitHub.\n";
    }
}
bool directoryExists(const string& dirName) {
    string command = "dir \"" + dirName + "\" >nul 2>nul";
    return (system(command.c_str()) == 0);
}
void check_downloaded_extensions() {
    set<string> Extensions;
    Extensions.insert("Median_TextExtension");
    cout << "Checking for the following extensions:\n";
    for (string ext : Extensions) {
        if (directoryExists(ext)) {
            cout << "Found extension folder: " << ext << endl;
        }
    }
}
void install_extension(const string& extension) {
    cout << "Installing extension... " << extension << "\n";
    std::string target_directory = extension;
    fs::path start_path = fs::current_path();
    std::cout << "Directory searching... " << target_directory << std::endl;
    find_directory(start_path, target_directory);
}

void findFileByName(const fs::path& path, const std::string& fileName) {
    try {
        bool found = false;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry) && entry.path().filename() == fileName) {
                found = true;
                std::cout << entry.path() << std::endl;
                fs::path filePath = entry.path();
                string command = "start \"" + filePath.string() + "\"";
                system(command.c_str());
            }
        }

        if (!found) {
            std::cout << fileName << " not found in " << path << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error 2: Access error to the directory '" << path << "': " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error 3: Undefined - " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Error 4: An unknown error occurred." << std::endl;
    }
}

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
    clearConsole();
    string line;
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
    string command;
    int l = 0;
    string fileName;
    cout << "Median HEAD is working(or type '-exit' to exit)\n";
    while (true) {
        cout << "process Main[Directory] >> ";
        getline(cin, command);
        if (command == "-exit") {
            break;
        }
        if (command.find("-install ") == 0) {
            string extension = command.substr(9);
            if (!extension.empty()) {
                install_extension(extension);
            }
            else {
                cout << "Error 1: Please specify an extension name.\n";
            }
        }
        else if (command == "-check") {
            check_downloaded_extensions();
        }
        else {
            cout << "Use '-check' or '-install <extension>'\n";
        }
    }
    //Text
    while (l < 1) {
        string action;
        string input;
        cout << "process New_Project[] >> ";
        cin >> action;
        set<string> IncludedExtensions;
        if (action == "-include <Text_Extension>") {
            IncludedExtensions.insert("Median_TextExtension");
        }
        else if (action == "-open") {
            string filename;
            bool processUnfinished = true;
            cout << "Enter the name of the text file with the .median extension (or specify its path): " << endl;
            cin >> filename;
            while (processUnfinished) {
                readFile(filename);
                cin >> input;
                if (input == "-exit") {
                    processUnfinished = false;
                }
                cout << processUnfinished;
            }
        }
        else if (action.find("-create") == 0) {
            fileName = "ObserverLevel.cpp";
            fs::path currentPath = fs::current_path();
            findFileByName(currentPath, fileName);
        }
    }
    return 0;
}
