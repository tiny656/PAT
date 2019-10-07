# 令dp[i] 表示以列表A第i个元素结尾的最大子序列和，所以一个列表的最大子序列和=max{dp[i] | i<-[1,...,n]}
# dp[0] = max(0, A[0])
# dp[i] = max(dp[i-1]+A[i], 0)
# 滚动数组优化

def MaxSum(arr):
    result, t = 0, 0
    for v in arr:
        t += v
        if t < 0:
            t = 0
        if result < t:
            result = t
    return result

k = int(raw_input())
arr = map(int, raw_input().split())
print MaxSum(arr)