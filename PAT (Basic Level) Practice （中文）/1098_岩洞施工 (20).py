n = int(input())
top = map(int, input().split())
bottom = map(int, input().split())
high = min(top)
low = max(bottom)
if high > low:
    print("Yes", high-low)
else:
    print("No", low-high+1)