#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6 + 7;
const int INF = 0x3f3f3f3f;
struct node {
    int val, rnk, lc, rc, size;
}tree[nmax];
int tot, seed = 233, root = 0;
inline int rrand() {
    return seed = int(seed * 482711ll % 2147483647);
}
inline void update(int rt) {
    tree[rt].size = tree[tree[rt].lc].size + tree[tree[rt].rc].size + 1;
}
int add_node(int val) {
    tree[++tot].size = 1;
    tree[tot].val = val;
    tree[tot].lc = tree[tot].rc = 0;
    tree[tot].rnk = rrand();
    return tot;
}
void split(int rt, int & a, int & b, int val) {
    if (rt == 0) {
        a = b = 0;
        return;
    }
    if (tree[rt].val <= val) {
        a = rt;
        split(tree[rt].rc, tree[a].rc, b, val);
    } else {
        b = rt;
        split(tree[rt].lc, a, tree[b].lc, val);
    }
    update(rt);
}
void merge(int & rt, int a, int b) {
    if (a == 0 || b == 0) {
        rt = a + b;
        return;
    }
    if (tree[a].rnk < tree[b].rnk) {
        rt = a;
        merge(tree[rt].rc, tree[a].rc, b);
    } else {
        rt = b;
        merge(tree[rt].lc, a, tree[b].lc);
    }
    update(rt);
}
void insert(int & rt, int val) {
    int x = 0, y = 0, nnode = add_node(val);
    split(rt, x, y, val);
    merge(x, x, nnode);
    merge(rt, x, y);
}
void delete_node(int & rt, int val){
    int x = 0, y = 0, z = 0;
    split(rt, x, y, val);
    split(x, x, z, val - 1);
    merge(z, tree[z].lc, tree[z].rc);
    merge(x, x, z);
    merge(rt, x, y);
}
int get_kth(int rt, int k) {
    while (tree[tree[rt].lc].size + 1 != k) {
        if (tree[tree[rt].lc].size >= k)
            rt = tree[rt].lc;
        else {
            k -= tree[tree[rt].lc].size + 1;
            rt = tree[rt].rc;
        }
    }
    return tree[rt].val;
}
int get_rank(int & rt, int val) {
    int x = 0, y = 0;
    split(rt, x, y, val - 1);
    int tmp = tree[x].size + 1;
    merge(rt, x, y);
    return tmp;
}
int get_pre(int & rt, int val) {
    int x = 0, y = 0;
    split(rt, x, y, val - 1);
    int tmp = get_kth(x, tree[x].size);
    merge(rt, x, y);
    return tmp;
}
int get_scc(int & rt, int val) {
    int x = 0, y = 0;
    split(rt, x, y ,val);
    int tmp = get_kth(y, 1);
    merge(rt, x, y);
    return tmp;
}
int n;
int main() {
    scanf("%d", &n);
    int op, val;
    add_node(INF);
    tot = 1;
    tree[1].size = 0;
    root = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &op, &val);
        if (op == 1) {
            insert(root, val);
        } else if (op == 2) {
            delete_node(root, val);
        } else if (op == 3) {
            printf("%d\n", get_rank(root, val));
        } else if (op == 4) {
            printf("%d\n", get_kth(root, val));
        } else if (op == 5) {
            printf("%d\n", get_pre(root, val));
        } else {
            printf("%d\n", get_scc(root, val));
        }
    }
    return 0;
}
