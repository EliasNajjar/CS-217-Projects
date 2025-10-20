#include <iostream>
using namespace std;

int maxNum(int arr[], int start, int end) {
    if (start == end) { // if one element, return that
        return arr[start];
    }
    int m = (start + end) / 2; // average index
    int maxLeft = maxNum(arr, start, m); // max from left
    int maxRight = maxNum(arr, m+1, end); // max from right
    if (maxLeft >= maxRight) { // return higher value
        return maxLeft;
    }
    else {
        return maxRight;
    }
}

int main() {
    int test[] = {1, 2, 452, 5, 7, 34, 64, 235};
    cout << maxNum(test,0,7) << endl;

    return 0;
}