#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <cctype>
using namespace std;

unordered_set<string> kw = {"int","float","if","else","for","while","return","void","double","char","main"};
unordered_set<char> op = {'+','-','*','/','%','=','>','<','!'};

bool valid(string s) {
    if(!isalpha(s[0]) && s[0]!='_') return false;
    for(char c:s) if(!isalnum(c) && c!='_') return false;
    return true;
}

int main() {
    ifstream f("input.txt");
    string w;
    while(f >> w) {
        if(kw.count(w)) cout << "Keyword: " << w << endl;
        else if(w.size()==1 && op.count(w[0])) cout << "Operator: " << w << endl;
        else if(valid(w)) cout << "Valid Identifier: " << w << endl;
        else cout << "Invalid Identifier: " << w << endl;
    }
    f.close();
    return 0;
}