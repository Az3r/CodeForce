// https://www.spoj.com/problems/COINS/

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<unsigned int, unsigned int> table;

unsigned int solve(unsigned int n) {
    if (n < 12) return n;
    if (table.find(n) != table.end()) return table[n];

    int s = solve(n / 2) + solve(n / 3) + solve(n / 4);

    table.insert({ n, s });
    return s;
}

int main()
{
    int t = 1;
    unsigned int n;
    while (t++ <= 10 && cin.good()) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}


