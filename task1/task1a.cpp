// 1. Find the average value of the elements of an array


#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float avg = (float)sum / n;
    cout << "Average value of the array elements: " << avg << endl;
    return 0;
}
