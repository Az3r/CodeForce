#include <iostream>
#include <string>

using namespace std;

string s;

int solve(const string& s) {
    int validOpen = 0;
    int invalidClose = 0;
    int output = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && invalidClose > 0) {
            --invalidClose;
            if (invalidClose == 0) ++output;
        }
        else if (s[i] == '(') ++validOpen;
        else if (validOpen > 0) --validOpen;
        else ++invalidClose;

        if (invalidClose > 0) ++output;
    }

    if (validOpen > 0 || invalidClose > 0) return -1;
    return output;
}

int main()
{
    int n;
    cin >> n;
    cin >> s;
    
    cout << solve(s);

    return 0;
}


