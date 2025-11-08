#include <iostream>
using namespace std;

int strToInt(string s) {
    if (s.length() == 1) {
        return s.front() - '0';
    }
    return 10 * strToInt(s.substr(0,s.length()-1)) + s.back() - '0';
}

int main() {
    cout << strToInt("237135694") << endl;

    return 0;
}