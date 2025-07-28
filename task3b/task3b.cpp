#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

bool integer(string s) {
    if(s.empty()) return false;
    if(s[0]=='-') s=s.substr(1);
    for(char c:s) if(!isdigit(c)) return false;
    return true;
}

bool real(string s) {
    int dot=0;
    if(s.empty()) return false;
    if(s[0]=='-') s=s.substr(1);
    for(char c:s) {
        if(c=='.') dot++;
        else if(!isdigit(c)) return false;
    }
    return dot==1;
}

int main() {
    ifstream f("input.txt");
    string line;
    while(getline(f,line)) {
        for(char c:line) {
            if(c==','||c==';'||c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']') cout << "Delimiter: " << c << endl;
        }
        stringstream ss(line);
        string w;
        while(ss >> w) {
            if(integer(w)) cout << "Integer: " << w << endl;
            else if(real(w)) cout << "Real Number: " << w << endl;
        }
    }
    f.close();
    return 0;
}