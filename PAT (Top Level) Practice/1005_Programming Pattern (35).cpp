#include <bits/stdc++.h>
using namespace std;

/*
1. 构造后缀数组
2. height[i,...,j]连续超过limit的最大区间max_cnt则是答案，记录当前位置为height[p]对应rank为p和p-1的公共前缀
3. 因为后缀数组的有序，从前往后扫一遍height，不用处理max_cnt相等情况，所以最后就可以得到答案为sa[p]位置字符开始，向后limit个字符
*/

const int maxn = 1050000;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], n;
int height[maxn], Rank[maxn];
void build_sa(int m) {
    int i, *x = t, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i]=s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;

    for (int k = 1; k < n; k <<= 1) {
        int p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) {
            if (sa[i] >= k)
                y[p++] = sa[i] - k;
        }
        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;  x[sa[0]] = 0;
        for (i = 1; i < n; i++) x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n)  break;
        m = p;
    }
}

void getHeight() {
    int i, j, k = 0; // height[]的合法范围为 1-N, 其中0是结尾加入的字符
    for (i = 0; i < n; i++) Rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k)  k--;
        j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k])    k++;
        height[Rank[i]] = k;
    }
}

int main() {
    int limit, cnt = 0, ans = 0, ans_pos = -1;
    scanf("%d", &limit);
    getchar();
    gets(s);
    n = strlen(s) + 1; //此处N比输入的N要多1，为人工添加的一个字符，用于避免CMP时越界
    build_sa(128);
    getHeight();
    for (int i = 1; i <= n; i++) {
        if (height[i] >= limit) {
            cnt++;
            if (cnt > ans) ans = cnt, ans_pos = i-1;
        } else cnt = 0;
    }

    for (int i = 0; i < limit; i++)
        printf("%c", s[i + sa[ans_pos]]);
    printf(" %d\n", ans+1);
    return 0;
}
/*
4
//A can can can a can.

3
int a=~~~~~~~~~~~~~~~~~~~~~0;
*/
