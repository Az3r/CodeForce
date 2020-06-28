#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> a;
int n, h, l, r;
vector<vector<int>> table;

int solve(int remain, int start, vector<vector<int>>& table) {

    // base case
    int i = l <= start && start <= r ? 1 : 0;
    if (remain <= 0) return i;

    // search cache table
    if (table[remain - 1][start] >= 0) return table[remain - 1][start];

    int wake0 = (start + a[n - remain]) % h;
    int wake1 = (start + a[n - remain] - 1) % h;

    int b = i + solve(remain - 1, wake0, table);
    int c = i + solve(remain - 1, wake1, table);

    return table[remain - 1][start] = max(b, c);
}

int main()
{
    cin >> n >> h >> l >> r;
    a.resize(n);
    table = vector<vector<int>>(n, vector<int>(h, -1));
    for (auto it = a.begin(); it != a.end(); ++it) cin >> *it;


    int b = solve(n - 1, (a[0] - 1) % h, table);
    int c = solve(n - 1, a[0] % h, table);
    cout << max(b, c) << endl;

    return 0;
}


