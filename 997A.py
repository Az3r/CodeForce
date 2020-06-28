# http://codeforces.com/problemset/problem/977/A
n, k = [int(i) for i in input().split(' ', 2)]

def solution(n: int, k: int) -> int:
    """solution for problem"""
    while (k > 0):
        last_digit = n % 10
        if last_digit > 0:
            n -= 1
        else:
            n /= 10
        k -= 1
    return int(n)

print(solution(n, k))
