#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
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
void applyFormatting(const vector<string>& formats, string text) {
    string formattedText = text;
    for (const auto& format : formats) {
        if (format == "bold") {
            formattedText = "\033[1m" + formattedText + "\033[0m";
        }
        else if (format == "italic") {
            formattedText = "\033[3m" + formattedText + "\033[0m";
        }
        else if (format == "weak") {
            formattedText = "\033[2m" + formattedText + "\033[0m";
        }
        else if (format == "underlined") {
            formattedText = "\033[4m" + formattedText + "\033[0m";
        }
        else if (format == "blinking") {
            formattedText = "\033[5m" + formattedText + "\033[0m";
        }
        else if (format == "negative") {
            formattedText = "\033[9m" + formattedText + "\033[0m";
        }

        else if (format == "black") {
            formattedText = "\033[30m" + formattedText + "\033[0m";
        }
        else if (format == "red") {
            formattedText = "\033[31m" + formattedText + "\033[0m";
        }
        else if (format == "green") {
            formattedText = "\033[32m" + formattedText + "\033[0m";
        }
        else if (format == "yellow") {
            formattedText = "\033[33m" + formattedText + "\033[0m";
        }
        else if (format == "blue") {
            formattedText = "\033[34m" + formattedText + "\033[0m";
        }
        else if (format == "purple") {
            formattedText = "\033[35m" + formattedText + "\033[0m";
        }
        else if (format == "cyan") {
            formattedText = "\033[36m" + formattedText + "\033[0m";
        }
        else if (format == "white") {
            formattedText = "\033[37m" + formattedText + "\033[0m";
        }

        else if (format == "blackb") {
            formattedText = "\033[40m" + formattedText + "\033[0m";
        }
        else if (format == "redb") {
            formattedText = "\033[41m" + formattedText + "\033[0m";
        }
        else if (format == "greenb") {
            formattedText = "\033[42m" + formattedText + "\033[0m";
        }
        else if (format == "yellowb") {
            formattedText = "\033[43m" + formattedText + "\033[0m";
        }
        else if (format == "blueb") {
            formattedText = "\033[44m" + formattedText + "\033[0m";
        }
        else if (format == "purpleb") {
            formattedText = "\033[45m" + formattedText + "\033[0m";
        }
        else if (format == "cyanb") {
            formattedText = "\033[46m" + formattedText + "\033[0m";
        }
        else if (format == "whiteb") {
            formattedText = "\033[47m" + formattedText + "\033[0m";
        }

        else if (format == "rgb") {
            formattedText = "\033[38m" + formattedText + "\033[0m";
        }

        else if (format == "doubleunderlined") {
            formattedText = "\033[21m" + formattedText + "\033[0m";
        }

        else if (format == "framed") {
            formattedText = "\033[51m" + formattedText + "\033[0m";
        }

        else if (format == "circled") {
            formattedText = "\033[52m" + formattedText + "\033[0m";
        }

        else if (format == "overlined") {
            formattedText = "\033[53m" + formattedText + "\033[0m";
        }
    }
    cout << formattedText;
}

void formatAndPrint(string text) {
    text.erase(remove(text.begin(), text.end(), '<'), text.end());
    text.erase(remove(text.begin(), text.end(), '>'), text.end());

    vector<string> formats;

    if (text.size() >= 4 && text.substr(0, 2) == "**" && text.substr(text.size() - 2) == "**") {
        formats.push_back("bold");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 2 && text[0] == '*' && text[text.size() - 1] == '*') {
        formats.push_back("italic");
        text = text.substr(1, text.size() - 2);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "##" && text.substr(text.size() - 2) == "##") {
        formats.push_back("weak");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "__" && text.substr(text.size() - 2) == "__") {
        formats.push_back("underlined");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "!!" && text.substr(text.size() - 2) == "!!") {
        formats.push_back("blinking");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "--" && text.substr(text.size() - 2) == "--") {
        formats.push_back("negative");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "@1" && text.substr(text.size() - 2) == "@1") {
        formats.push_back("black");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@2" && text.substr(text.size() - 2) == "@2") {
        formats.push_back("red");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@3" && text.substr(text.size() - 2) == "@3") {
        formats.push_back("green");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@4" && text.substr(text.size() - 2) == "@4") {
        formats.push_back("yellow");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@5" && text.substr(text.size() - 2) == "@5") {
        formats.push_back("blue");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@6" && text.substr(text.size() - 2) == "@6") {
        formats.push_back("purple");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@7" && text.substr(text.size() - 2) == "@7") {
        formats.push_back("cyan");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "@8" && text.substr(text.size() - 2) == "@8") {
        formats.push_back("white");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "$1" && text.substr(text.size() - 2) == "$1") {
        formats.push_back("blackb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$2" && text.substr(text.size() - 2) == "$2") {
        formats.push_back("redb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$3" && text.substr(text.size() - 2) == "$3") {
        formats.push_back("greenb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$4" && text.substr(text.size() - 2) == "$4") {
        formats.push_back("yellowb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$5" && text.substr(text.size() - 2) == "$5") {
        formats.push_back("blueb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$6" && text.substr(text.size() - 2) == "$6") {
        formats.push_back("purpleb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$7" && text.substr(text.size() - 2) == "$7") {
        formats.push_back("cyanb");
        text = text.substr(2, text.size() - 4);
    }
    if (text.size() >= 4 && text.substr(0, 2) == "$8" && text.substr(text.size() - 2) == "$8") {
        formats.push_back("whiteb");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "%%" && text.substr(text.size() - 2) == "%%") {
        formats.push_back("rgb");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "^^" && text.substr(text.size() - 2) == "^^") {
        formats.push_back("doubleunderlined");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "[[" && text.substr(text.size() - 2) == "]]") {
        formats.push_back("framed");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "{{" && text.substr(text.size() - 2) == "}}") {
        formats.push_back("circled");
        text = text.substr(2, text.size() - 4);
    }

    if (text.size() >= 4 && text.substr(0, 2) == "||" && text.substr(text.size() - 2) == "||") {
        formats.push_back("overlined");
        text = text.substr(2, text.size() - 4);
    }
    applyFormatting(formats, text);
    cout << endl;
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
    //Text
    while (l<1) {
        string action;
        string input;
        cin >> action;
        set<string> IncludedExtensions;
        if (action == "-include <Text_Extension>") {
            IncludedExtensions.insert("Median_TextExtension");
        }
        else if (action == "-mh"){
            string filename;
            cout << "Enter the name of the text file with the .median extension (or specify its path): " << endl;
            cin >> input;
            getline(cin, filename);
            while (true) {
                readFile(filename);
                cin >> input;
            }
        }
    }
    return 0;
}
