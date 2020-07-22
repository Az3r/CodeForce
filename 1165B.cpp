// https://codeforces.com/problemset/problem/1165/B

/** analyze problem
 * Polycarp has to solve k problems in day k
 * contest ith has a[i] problems
 * At day k, polycarp chooses a contest which has more than k problems, solves k problems from it and discard other problems
 * if no such contest exists than polycarp stop training
 * */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> contests(n);
    for (int i = 0; i < n; i++)
    {
        int problems;
        std::cin >> problems;
        contests.push_back(problems);
    }

    // find the index whose value which is closest to given days
    auto findClosestValue = [&contests](int k) {
        int value = INT_MAX;
        int index = INT_MAX;
        for (size_t i = 0; i < contests.size(); i++)
        {
            int problems = contests[i];
            if (problems >= k && problems - k < value) {
                value = problems;
                index = i;
            }
        }
        return index;
    };

    int days = 1;
    while (days <= n)
    {
        int index = findClosestValue(days);
        if (index == INT_MAX)
        {
            --days;
            break;
        }
        contests[index] = days;
        ++days;
    }
    std::cout << days << std::endl;

    return 0;
}