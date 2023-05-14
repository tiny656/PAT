#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
#+BEGIN_EXPORT latex
\begin{aligned}
&1. 对于珠子数量N，设t为需要的step数量，则N = \frac{t \times(t+1)}{2}, 得到t = \frac{\sqrt{1+8N}-1}{2}\\
&2. 对于1...t的某个step i，只有两种操作，选择Red珠子或者Blue珠子\\
&等于在每一步选择Red珠子就是1，不选就是0。\\
&针对题目的数据N=10，此时t=4，求解的问题就变成:\\
&在一共4次step中，Red珠子使用量不超过4的条件下，所有的方案数，\\
&因为Blue珠子也是有数量限制，所以Red珠子需要满足至少在区间[N-B, A]内，才是有效的方案数。\\
&3. 根据01背包的求解方法，这里step的i，既是物品编号，值也是物品容量大小，\\
&这里就可以定义f(i, j):\\
&表示共i个step，Red珠子容量为j时候，恰好使用j个Red珠子，所得到的方案数。\\
& 初始化时候f(0,0)=1,其余f(0,x)=-\infty \\
&对于Sample答案就是f(4, 3) + f(4, 4) \\
&4. 数据范围要求，这里需要使用滚动数组优化。
\end{aligned}
#+END_EXPORT
*/

const int INF = 0x3fffffff;
const int M = 1000000007;

bool isSquare(int n) {
	int t = sqrt(n);
	return t*t == n;
}

int main() {
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;

	if (a + b < n || !isSquare(1+8*n)) {
		cout << 0 << endl;
		return 0;
	}

	int t = (sqrt(1+8*n)-1)/2.;
	vector<int> f(a+1, -INF); // 预置所有无效状态
	f[0] = 1; // f(0,0)设置为有效状态, 以上是恰好装满的初始化条件

	// 01背包滚动数组优化
	for (int i = 1; i <= t; i++) {
		for (int j = a; j >= i; j--) {
			if (f[j] > 0 && f[j - i] > 0) f[j] = (f[j] + f[j - i]) % M;
			else if (f[j-i] > 0) f[j] = f[j-i];
		}
	}

	int ans = 0;
	for (int i = n-b; i <= a; i++) {
		if (f[i] > 0) {
			ans = (f[i] + ans) % M;
		}
	}

	cout << ans << endl;
	return 0;
}