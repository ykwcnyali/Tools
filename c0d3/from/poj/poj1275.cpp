#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define M(a, b) memset(a, b, sizeof(a))
const int N = 30;
int d[N], a[N], R[N], cnt[N], m;
bool inq[N];
struct Node {
    int to, w;
};
vector<Node> G[N];
void AddEdge(int u, int v, int w) {
    G[u].push_back(Node{v, w});
}
bool spfa(int s) {
    M(d, INF); M(cnt, 0); M(inq, 0);
    d[s] = 0; cnt[s] = 1;
    queue<int> q;
    q.push(s); inq[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Node &e = G[u][i];
            if (d[e.to] > d[u] + e.w) {
                d[e.to] = d[u] + e.w;
                if (inq[e.to]) continue;
                q.push(e.to); inq[e.to] = 1;
                if (++cnt[e.to] > 24) return false;
            }
        }
    }
    return true;
}
void build(int sum) {
    for (int i = 0; i <= 24; ++i) G[i].clear();
    for (int i = 1; i <= 24; ++i)
        AddEdge(i, i-1, 0), AddEdge(i-1, i, a[i]);
    for (int i = 8; i <= 24; ++i) AddEdge(i, i-8, -R[i]);
    for (int i = 1; i < 8; ++i) AddEdge(i, i+16, sum-R[i]);
    AddEdge(24, 0, -sum);
}
int main() {
    int T, b;
    scanf("%d", &T);
    while (T--) {
        M(a, 0);
        for (int i = 1; i <= 24; ++i) scanf("%d", &R[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b);
            a[b+1]++;
        }
        int l = 0, r = m, mid, ans = -1;
        while (l < r) {
            mid = (l + r) >> 1;
            build(mid);
            if (spfa(0)) ans = mid, r = mid;
            else l = mid+1;
        }
        if (~ans) printf("%d\n", ans);
        else printf("No Solution\n");
    }

    return 0;
}
