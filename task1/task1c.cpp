// 3. Take number of students, their name and marks, write to file and read it


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int num;
    cout << "Enter number of students: ";
    cin >> num;

    string name;
    int marks;

    ofstream outFile("students.txt");
    for(int i = 0; i < num; i++)
    {
        cout << "Enter name of student " << i+1 << ": ";
        cin >> name;
        cout << "Enter marks of " << name << ": ";
        cin >> marks;
        outFile << name << " " << marks << endl;
    }
    outFile.close();

    cout << "\nReading from file:" << endl;
    ifstream inFile("students.txt");
    while(inFile >> name >> marks) {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
    inFile.close();

    return 0;
}
