#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    string patterns[] = 
    {
        "abc",
        "abc*",
        "abc+",
        "a(bc)+",
        "a(bc)?",
        "[abc]",
        "[a-z]",
        "[a\\-z]",
        "[-a-z]",
        "[A-Za-z0-9]+",
        "[ \\t\\n]+",
        "[^ab]",
        "a|b"
    };
    string meanings[] = 
    {
        "only 'abc'",
        "'ab', 'abc', 'abcc' ...",
        "'abc', 'abcc' ...",
        "'abc', 'abcbc' ...",
        "'a', 'abc'",
        "'a', 'b', or 'c'",
        "any lowercase letter (a-z)",
        "'a', '-', or 'z'",
        "'-', 'a', or 'z'",
        "one or more letters or digits",
        "space, tab, or newline",
        "anything except 'a' or 'b'",
        "'a' or 'b'"
    };

    string input;
    cout << "Enter input: ";
    getline(cin, input);

    bool anyMatch = false;
    for(int i=0; i<13; i++) 
    {
        regex r("^" + patterns[i] + "$");  
        if(regex_match(input, r)) 
        {
            cout << "Pattern: " << patterns[i] << " => " << meanings[i] << endl;
            anyMatch = true;
        }
    }

    if(!anyMatch) 
    {
        cout << "No pattern matched!" << endl;
    }
    return 0;
}