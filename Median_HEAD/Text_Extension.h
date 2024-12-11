#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <functional>
using namespace std;
std::string textformatting(std::string text) { return text; }
class Formatter {
public:
    void addFormat(const string& key, const string& format) {
        formatMap[key] = format;
    }
    vector<string> getFormats(const string& text) const {
        vector<string> formats;
        for (const auto& [key, format] : formatMap) {
            if (text.size() >= 4 && text.substr(0, 2) == key && text.substr(text.size() - 2) == key) {
                formats.push_back(format);
                string newText = text.substr(2, text.size() - 4);
                return formats;
            }
        }
        return formats;
    }
private:
    unordered_map<string, string> formatMap;
};
void applyFormatting(const vector<std::string>& formats, std::string text) {
    std::string formattedText = text;
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
    Formatter formatter;
    formatter.addFormat("*", "italic");
    formatter.addFormat("**", "bold");
    formatter.addFormat("##", "weak");
    formatter.addFormat("__", "underlined");
    formatter.addFormat("!!", "blinking");
    formatter.addFormat("--", "negative");
    formatter.addFormat("@1", "black");
    formatter.addFormat("@2", "red");
    formatter.addFormat("@3", "green");
    formatter.addFormat("@4", "yellow");
    formatter.addFormat("@5", "blue");
    formatter.addFormat("@6", "purple");
    formatter.addFormat("@7", "cyan");
    formatter.addFormat("@8", "white");
    formatter.addFormat("$1", "blackb");
    formatter.addFormat("$2", "redb");
    formatter.addFormat("$3", "greenb");
    formatter.addFormat("$4", "yellowb");
    formatter.addFormat("$5", "blueb");
    formatter.addFormat("$6", "purpleb");
    formatter.addFormat("$7", "cyanb");
    formatter.addFormat("$8", "whiteb");
    formatter.addFormat("%%", "rgb");
    formatter.addFormat("^^", "doubleunderlined");
    formatter.addFormat("[[", "framed");
    formatter.addFormat("{{", "circled");
    formatter.addFormat("||", "overlined");
    vector<string> formats = formatter.getFormats(text);
    applyFormatting(formats, text);
    cout << endl;
}
