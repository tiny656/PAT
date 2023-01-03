#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const double esp = 1e-8;

struct Point { double x, y; };
struct Path { vector<int> child; };

double dp[301][301][11];
vector<pair<Point, int>> ngon;

Path pathInfo[301][301][11];

/*
double cross(double x1, double y1, double x2, double y2) {
    return x1*y2 - x2*y1;
}

double compare(Point a, Point b, Point c) {
    return cross(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}
*/

double GetTriangleArea(int idx1, int idx2, int idx3) {
    Point a = ngon[idx1].first;
    Point b = ngon[idx2].first;
    Point c = ngon[idx3].first;
    double area = 0.5 * abs(a.x*b.y+b.x*c.y+c.x*a.y-c.x*b.y-b.x*a.y-a.x*c.y);
    // printf("GetTriangleArea(%d, %d, %d) - %f\n", idx1, idx2, idx3, area);
    return area;
}


// 自顶向下备忘录DP search 答案
// GetMaxArea(begin, end, sides) 表示begin到end的范围的点集合和begin,end组成的为sides条边的多边形的最大面积
double GetMaxArea(int begin, int end, int sides) {
    // printf("call: GetMaxArea(%d, %d, %d)\n", begin, end, sides);
    if (sides <= 2) return 0.;
    if (dp[begin][end][sides] > esp) return dp[begin][end][sides];
    
    double area = -1;
    // max{GetMaxArae(begin, i, sides-1)} + TriArea(begin, i, end) 其中 i -> {begin+sides-2, end-1}
    for (int i = begin+sides-2; i <= end-1; i++) {
        double v = GetMaxArea(begin, i, sides-1) + GetTriangleArea(begin, i, end);
        if (v > area) {
            area = v;
            pathInfo[begin][end][sides].child = { begin, i, sides-1 };
        }
    }

    dp[begin][end][sides] = area;
    return area;
}

// 正向推演路径
vector<int> GetIndices(int begin, int end, int sides) {
    set<int> s;
    do {
        Path p = pathInfo[begin][end][sides];
        s.insert(ngon[begin].second);
        s.insert(ngon[end].second);
        if (p.child[2] <= 2) {
            s.insert(ngon[p.child[1]].second);
            break;
        } else {
            begin = p.child[0];
            end = p.child[1];
            sides = p.child[2];
        }
    } while (true);

    vector<int> ans(s.rbegin(), s.rend());
    /*
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i] << endl;
    }
    cout << endl;
    */
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int N, n;
    Point o {0.0, 0.0};
    cin >> N >> n;
    ngon.resize(N);
    for (int i = 0; i < N; i++) {
        // 记录点和原始位置关系
        ngon[i].second = i;
        cin >> ngon[i].first.x >> ngon[i].first.y;
        o.x += ngon[i].first.x;
        o.y += ngon[i].first.y;
    }

    o.x /= N;
    o.y /= N;

    // 极角排序
    sort(ngon.begin(), ngon.end(), [&](const pair<Point, int> a, const pair<Point, int> b) {
        double c1 = atan2(a.first.y - o.y, a.first.x - o.x); 
        double c2 = atan2(b.first.y - o.y, b.first.x - o.x);
        if (c1 != c2) return c1 < c2;
        else return a.first.x < b.first.x;
    });

    /*
    for (int i = 0 ; i < N; i++) {
        cout << " (" << ngon[i].first.x << " " << ngon[i].first.y << ") " << ngon[i].second << endl;
    }
    */

    tuple<int, int, int> s;
    double area = 0;
 
    /* 备忘录递归，最后一个数据点超时
    for (int i = N-n; i >= 0; i--) {
        for (int j = N-1; j >= n-1+i; j--) {
            if (GetMaxArea(i, j, n) > area) {
                area = GetMaxArea(i, j, n);
                // printf("Main: GetMaxArea(%d, %d, %d) - %f\n", i, j, n, area);
                s = {i, j, n};
            }
        }
    }
    */

    // 递推，不超时
    for (int side = 3; side <= n; side++) {
        for (int i = 0; i <= N-side; i++) {
            for (int j = side-1+i; j <= N-1; j++) { 
                for (int k = i+side-2; k <= j-1; k++) {
                    double v = dp[i][k][side-1] + GetTriangleArea(i, k, j);
                    if (v > dp[i][j][side]) {
                        dp[i][j][side] = v;
                        pathInfo[i][j][side].child = { i, k, side-1 };
                        if (side == n && dp[i][j][side] > area) {
                            area = dp[i][j][side];
                            s = {i, j, n};
                        }
                    }
                }
            }
        }
    }

    // print path
    vector<int> ans = GetIndices(get<0>(s), get<1>(s), get<2>(s));
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}