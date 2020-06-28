# http://codeforces.com/problemset/problem/1324/C
t = int(input())
test_cases = [input() for i in range(t)]


def solve_test(test_case):
    pos = len(test_case)
    d = 1
    while pos >= 0:
        jump = 1
        while test_case[pos - jump] != 'R':
            jump += 1
        d = max(jump, d)
        pos -= jump
    return d


def solve(test_cases):
    for test in test_cases:
        print(solve_test(test))


solve(test_cases)
