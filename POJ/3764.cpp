#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct ForwardStar {
	int cnt;
	vector<int> head, nxt, to, weight;

	ForwardStar(int _n) {
		head.assign(_n, -1);
		nxt.resize(_n << 1);
		to.resize(_n << 1);
		weight.resize(_n << 1);
		cnt = -1;
	}

	void add_edge(int u, int v) {
		nxt[++cnt] = head[u];
		head[u] = cnt;
		to[cnt] = v;
	}

	void add_edge(int u, int v, int w) {
		nxt[++cnt] = head[u];
		head[u] = cnt;
		to[cnt] = v;
		weight[cnt] = w;
	}
};

const int N = 200000;
int cnt = 0, ans = 0;
int trie[N << 5][2];
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

void DFS(int u, int p, ForwardStar &G) {
    insert(d[u]);
    ans = max(ans, find(d[u]));

    for (int i = G.head[u]; ~i; i = G.nxt[i]) {
		int v = G.to[i];
        if (v != p) {
            d[v] = d[u] ^ G.weight[i];
            DFS(v, u, G);
        }
    }
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
	while (scanf("%d", &n) != EOF) {
		ans = cnt = 0;
		memset(trie, 0, sizeof(int) * (n << 5) * 2);

		ForwardStar G(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G.add_edge(u, v, w);
			G.add_edge(v, u, w);
		}

		memset(d, 0, sizeof(d));
		DFS(0, -1, G);
		printf("%d\n", ans);
	}

    return 0;
}
