# http://codeforces.com/problemset/problem/1328/B

# input
t = int(input())
test_cases = []
for i in range(t):
    test_cases.append([int(v) for v in input().split(' ', 2)])


def find_group(n):
    s = 1
    i = 1
    while s < n:
        i += 1
        s += i
    return [i, s]


def solution(t, test_cases):
    outputs = []
    for test in test_cases:
        n = test[0]
        k = test[1]
        result = ['a' for i in range(n)]
        group, total = find_group(k)

        result[n - group - 1] = 'b'
        result[n - group  + total - k] = 'b'

        outputs.append(''.join(result))
    return outputs


for s in solution(t, test_cases):
    print(s)
