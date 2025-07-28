#include <string>
#include <iostream>

using namespace std;

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);


    bool isSingleLineComment = input.substr(0, 2) == "//";
    bool isMultiLineComment = input.substr(0, 2) == "/*" && input.find("*/") != string::npos;


    if (isSingleLineComment) {
        cout << "This is a single line comment." << endl;
    } else if (isMultiLineComment) {
        cout << "This is a multi line comment." << endl;
    } else {
        cout << "This is not a comment." << endl;
    }

    return 0;
}