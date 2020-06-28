n = int(input())
arr = input()

validOpen = []
invalidClose = []

output = 0

for ch in arr:
    if ch == '(':
        if len(invalidClose) == 0:
            validOpen.append('(')
        else:
            del invalidClose[0]
    else:
        if len(validOpen) > 0:
            del validOpen[0]
        else:
            invalidClose.append(')')
    if (len(invalidClose) > 0):
        output += 1

if len(validOpen) > 0 or len(invalidClose) > 0:
    print(-1)
else:
    print(output)
