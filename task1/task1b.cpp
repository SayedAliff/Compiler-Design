// 2. Concatenate first and last name to get full name


#include <iostream>
#include <cstring>
using namespace std;

void getFullName(char fullName[], char firstName[], char lastName[]) {
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
}

int main() {
    char firstName[30], lastName[30], fullName[60];

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    getFullName(fullName, firstName, lastName);

    cout << "Full name = " << fullName << endl;

    return 0;
}
