struct ForwardStar {
	int cnt;
	vector<int> head, nxt, to, weight;

	ForwardStar(int _n) {
		cnt = -1;
		head.assign(_n, -1);
		nxt.resize(_n << 1);
		to.resize(_n << 1);
		weight.resize(_n << 1);
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
