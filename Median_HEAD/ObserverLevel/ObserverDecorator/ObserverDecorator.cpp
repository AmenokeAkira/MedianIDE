#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void decrypt(const string& filename, char keyDigit, const vector<string>& inputNumbers) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error 9: Access error to the multi-level system." << endl;
        return;
    }
    string encryptedLine;
    getline(inFile, encryptedLine);
    inFile.close();
    vector<string> decryptedNumbers;
    size_t start = 0;
    size_t end = 0;
    while ((end = encryptedLine.find(' ', start)) != string::npos) {
        string encryptedNumber = encryptedLine.substr(start, end - start);
        string decryptedNumber;
        for (size_t j = 0; j < encryptedNumber.size(); ++j) {
            char encryptedDigit = encryptedNumber[j];
            int encDigit = encryptedDigit - '0';
            int randomValue = (keyDigit - '0') * (j + 1);
            int decryptedDigit = (encDigit - (keyDigit - '0') - randomValue + 10) % 10;
            decryptedNumber += to_string(decryptedDigit);
        }
        decryptedNumbers.push_back(decryptedNumber);
        start = end + 1;
    }
    bool isMatch = true;
    for (size_t i = 0; i < inputNumbers.size(); ++i) {
        if (decryptedNumbers[i] != inputNumbers[i]) {
            isMatch = false;
            break;
        }
    }
}
int main() {
    char keyDigit;
    cout << "< Access Key > ";
    cin >> keyDigit;
    vector<string> inputNumbers(10);
    for (int i = 0; i < 10; ++i) {
        cout << "< decode ... > " << (i + 1) << " ";
        cin >> inputNumbers[i];
    }
    decrypt("LevelCore.prlvl", keyDigit, inputNumbers);
    return 0;
}
