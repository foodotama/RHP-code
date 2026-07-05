#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int flag = 0;

    for(char ch : s) {
        if(ch >= '0' && ch <= '9')
            flag |= (1 << (ch - '0'));
    }

    cout << (flag == (1 << 10) - 1 ? "Yes" : "No");
} 
