#include <bits/stdc++.h>
using namespace std;

bool checkSum(vector<int> arr, int sum, int n) {
    if (n == 0) {
        return false;
    } 
    if (sum == 0) {
        return true;
    }

    if (arr[n-1] > sum) {
        return checkSum(arr, sum, n-1);
    } 
  
    return (checkSum(arr, sum, n-1) || checkSum(arr, sum-arr[n-1], n-1));
}

int main() {
    cout << "Hello DP!" << endl;

    vector<int> arr = {2,4,6,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    if(checkSum(arr, 11, n) == true) {
        cout << "Sum found";
    } else {
        cout << "Sum not found";
    }
    return 0;
}
