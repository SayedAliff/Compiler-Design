#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);


    char operators[] = {'+', '-', '*', '/', '%', '=', '>', '<', '!', '&', '|', '^', '~'};
    int count = 0;
    int opNum = 1;

    for (int i = 0; i < input.length(); i++) {
        for (int j = 0; j < sizeof(operators); j++) {
            if (input[i] == operators[j]) {
                cout << "operator" << opNum << " : " << input[i] << endl;
                count++;
                opNum++;
            }
        }
    }
    cout << "number of operators = " << count << endl;
    return 0;
}
