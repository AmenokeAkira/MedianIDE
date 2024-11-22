#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
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
int main() {
    string command;
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
        else if (command.find("-lib") == 0) {
            fileName = command.substr(5);
            fs::path currentPath = fs::current_path();
            findFileByName(currentPath, fileName);
            return 0;
        }
        else if (command == "-check") {
            check_downloaded_extensions();
        }
        else {
            cout << "Use '-check' or '-install <extension>'\n";
        }
    }

    return 0;
}
