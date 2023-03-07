n, k, l = map(int, input().split())
v = list(map(int, input().split()))

v.sort()

cost = float('inf')
for i in range(v[0], v[n-1]+1):

    incCnt = 0
    decCnt = 0
    for j in v:
        if j > i:
            decCnt += j - i
        else:
            incCnt += i - j
    if incCnt >= decCnt:
        incCnt -= decCnt
        decCost = k * decCnt
        incCost = l * incCnt
        cost = min(decCost + incCost, cost)

print(cost)
