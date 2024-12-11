#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>
#include <filesystem>
#include <fstream>
#include "Text_Extension.h"
namespace fs = std::filesystem;
using namespace std;
void install_extension(const string& extension) {
    cout << "Installing extension: " << extension << endl;
}
void check_downloaded_extensions() {
    cout << "Checking downloaded extensions..." << endl;
}
void readFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error 0: Failed to open the specified text file " << filename << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        formatAndPrint(line);
    }
    inputFile.close();
}

void findFileByName(const fs::path& currentPath, const string& fileName) {
    cout << "Searching for file: " << fileName << " in " << currentPath << endl;
}
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};
class InstallCommand : public Command {
    string extension;
public:
    InstallCommand(string ext) : extension(ext) {}
    void execute() override {
        install_extension(extension);
    }
};
class CheckCommand : public Command {
public:
    void execute() override {
        check_downloaded_extensions();
    }
};
class OpenFileCommand : public Command {
    string filename;
public:
    OpenFileCommand(string fn) : filename(fn) {}

    void execute() override {
        readFile(filename);
    }
};
class CreateCommand : public Command {
    string fileName;
public:
    CreateCommand(string fn) : fileName(fn) {}

    void execute() override {
        fs::path currentPath = fs::current_path();
        findFileByName(currentPath, fileName);
    }
};
class CommandHandler {
    unordered_map<string, function<unique_ptr<Command>(const string&)>> commandMap;

public:
    CommandHandler() {
        commandMap["-install"] = [](const string& extension) { return make_unique<InstallCommand>(extension); };
        commandMap["-check"] = [](const string&) { return make_unique<CheckCommand>(); };
        commandMap["-open"] = [](const string& filename) { return make_unique<OpenFileCommand>(filename); };
        commandMap["-create"] = [](const string& filename) { return make_unique<CreateCommand>(filename); };
    }
    unique_ptr<Command> createCommand(const string& action, const string& argument = "") {
        if (commandMap.count(action)) {
            return commandMap[action](argument);
        }
        return nullptr;
    }
};
int main() {
    cout << "Median HEAD is working (or type '-exit' to exit)\n";
    CommandHandler commandHandler;
    while (true) {
        string command;
        cout << "process Main[Directory] >> ";
        getline(cin, command);
        if (command == "-exit") {
            break;
        }
        if (command.find("-install ") == 0) {
            string extension = command.substr(9);
            auto cmd = commandHandler.createCommand("-install", extension);
            cmd->execute();
        }
        else if (command == "-check") {
            auto cmd = commandHandler.createCommand("-check");
            cmd->execute();
        }
        else {
            cout << "Use '-check' or '-install <extension>'\n";
        }
    }
    while (true) {
        string action;
        cout << "process New_Project[] >> ";
        cin >> action;
        if (action == "-include <Text_Extension>") {
            cout << "Include command not implemented.\n";
        }
        else if (action == "-open") {
            string filename;
            cout << "Enter the name of the text file with the .median extension (or specify its path): " << endl;
            cin >> filename;
            auto cmd = commandHandler.createCommand("-open", filename);
            cmd->execute();
        }
        else if (action.find("-create") == 0) {
            string fileName = "ObserverLevel.cpp"; // or extract this from the action
            auto cmd = commandHandler.createCommand("-create", fileName);
            cmd->execute();
        }
        else if (action == "-exit") {
            break;
        }
        else {
            cout << "Unknown command in project processing.\n";
        }
    }
    return 0;
}
