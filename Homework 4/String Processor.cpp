#include <iostream>
#include <string>
#include <stack>
using namespace std;

class StringProcessor {
public:
    string processStringInput(string s) {
        stack<char> resStack;
        for (char i : s) {
            if (i == '<') { // < means backspace, so pop top
                resStack.pop();
            }
            else {
                resStack.push(i);
            }
        }
        string resRev;
        while (!resStack.empty()) { // put stack in string, but it will be reversed
            resRev += resStack.top();
            resStack.pop();
        }
        string res;
        for (int i = resRev.length() - 1;i >= 0;i--) { // read string backwards
            res += resRev[i];
        }
        return res;
    }

    bool isPalindrome(string s) {
        stack<char> half; // stack for first half the string, to go back and check with back half
        int i = 0;
        for (;i < s.length() / 2;i++) {
            half.push(s[i]);
        }
        if (s.length() % 2) {
            i++; // ignore middle element if there is one
        }
        for (;i < s.length();i++) { // check rest of string
            if (s[i] != half.top()) { // if not equal to element in stack
                return false;
            }
            half.pop(); // to see the character before
        }
        return true; // return true if it goes through the whole string
    }
};

int main() {
    StringProcessor p;
    string in;
    cout << "Enter a string, < for backspace:" << endl;
    getline(cin,in);
    string result = p.processStringInput(in);
    cout << "Resulting string: " << result << endl;
    if (p.isPalindrome(result)) {
        cout << result << " is a palindrome " << endl;
    }
    else {
        cout << result << " is not a palindrome " << endl;
    }

    return 0;
}