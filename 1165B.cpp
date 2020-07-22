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

int n;
std::vector<int> contests;
int predicate(int k, int start);
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int problems;
        std::cin >> problems;
        contests.push_back(problems);
    }

    std::sort(contests.begin(), contests.end());

    /**
     * first sort the contests ascending
     * for day k, find the contest whose number of problems is the closest to but bigger than k, method is expressed in function predicate
     * if no such contest is found, return total of trained days which is (k - 1)
     * because at the following day k + 1, every contest before has the number of problems < k,
     * algorithm can save time by starting at the next contest without searching from the start of the list
    */


    int start = 0;
    int days = 0;
    while (++days <= n)
    {
        int k = predicate(days, start);
        if (k >= contests.size()) break;
        start = k + 1;
    }
    std::cout << days - 1 << std::endl;
    return 0;
}
int predicate(int k, int start) {
    static int size = contests.size();
    while (start < size && contests[start] < k) ++start;
    return start; 
}
