#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void encrypt(const vector<string>& numbers, char keyDigit, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error 7: Error writing encryption level file." << endl;
        exit(1);
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        const string& number = numbers[i];
        for (size_t j = 0; j < number.size(); ++j) {
            char digit = number[j];
            int originalDigit = digit - '0';
            int randomValue = (keyDigit - '0') * (j + 1);
            int encryptedDigit = (originalDigit + (keyDigit - '0') + randomValue) % 10;
            outFile << encryptedDigit;
        }
        outFile << " ";
    }
    outFile.close();
}

int main() {
    vector<string> numbers(10);
    char keyDigit;
    for (int i = 0; i < 10; ++i) {
        cout << "< decode > " << (i + 1) << ": ";
        cin >> numbers[i];
        for (char c : numbers[i]) {
            if (!isdigit(c)) {
                cerr << "Error 8: Arbitrary encoding error due to the input of an unavailable encryption character." << endl;
                return 1;
            }
        }
    }
    cout << "<< Key Level >> ";
    cin >> keyDigit;
    encrypt(numbers, keyDigit, "LevelCore.prlvl");
}
