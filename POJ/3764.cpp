#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200000;
int cnt = 0, ans = 0, c = 0;
int trie[N << 5][2];
int head[N], nxt[N], weight[N], to[N];
int d[N];

void insert(int x) {
    int u = 0;
    for (int i = 30; i >= 0; --i) {
        int y = ((x >> i) & 1);
        if (!trie[u][y]) {
            trie[u][y] = ++cnt;
        }
        u = trie[u][y];
    }
}

int find(int x) {
    int u = 0;
    int res = 0;
    for (int i = 30; i >= 0; --i) {
        int y = ((x >> i) & 1);
        if (trie[u][y ^ 1]) {
            u = trie[u][y ^ 1];
            res |= (1 << i);
        } else {
            u = trie[u][y];
        }
    }
    return res;
}

void add(int u, int v, int w) {
	nxt[++c] = head[u];
	head[u] = c;
	to[c] = v;
	weight[c] = w;
}

void DFS(int u, int p) {
    insert(d[u]);
    ans = max(ans, find(d[u]));

    for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
        if (v != p) {
            d[v] = d[u] ^ weight[i];
            DFS(v, u);
        }
    }
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
	while (scanf("%d", &n) != EOF) {
		ans = cnt = 0;
		c = -1;
		memset(trie, 0, sizeof(int) * (n << 5) * 2);
		memset(head, -1, sizeof(int) * n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}

		memset(d, 0, sizeof(d));
		DFS(0, -1);
		printf("%d\n", ans);
	}

    return 0;
}
