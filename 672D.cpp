// https://codeforces.com/contest/672/problem/D
// get time exceeding at test 16

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int first_occurence(const vector<int>& v, int key) {
    int ans = -1;
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key < v[mid]) high = mid - 1;
        else if (key > v[mid]) low = mid + 1;
        else {
            if (mid == 0 || v[mid] > v[mid - 1]) return mid;
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}


int last_occurence(const vector<int>& v, int key) {
    int ans = -1;
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key < v[mid]) high = mid - 1;
        else if (key > v[mid]) low = mid + 1;
        else {
            if (mid == v.size() - 1 || v[mid] < v[mid + 1]) return mid;
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}



int solve(vector<int>& v, int k) {
    sort(v.begin(), v.end());
    size_t l = v.size();

    int first_max = l;
    int last_min = -1;

    while (k > 0) {
        int max = v[l - 1];
        int min = v[0];
        if (max == min) return 0;
        else if (max - min == 1) return 1;

        if (first_max >= l) first_max = first_occurence(v, max);
        if (first_max == 0) return 0;
        if (last_min < 0) last_min = last_occurence(v, min);
        if (last_min == l - 1) return 0;


        while (k > 0 && last_min >= 0 && first_max < l) {
            v[first_max++] -= 1;
            v[last_min--] += 1;
            --k;
        }
    }

    return v[l - 1] - v[0];
}


int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
   

    std::vector<int> citizens(n);
    for (auto it = citizens.begin(); it != citizens.end(); ++it) std::cin >> *it;

    cout << solve(citizens, k) << endl;
    return 0;
}


