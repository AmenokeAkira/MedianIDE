#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
std::string textformatting(std::string text) { return text; }
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