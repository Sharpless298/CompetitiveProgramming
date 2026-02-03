struct ForwardStar {
	int cnt;
	vector<int> head, nxt, to, weight;

	ForwardStar(int _n) : n(_n) {
		cnt = -1;
		head.assign(n, -1);
		nxt.resize(n << 1);
		to.resize(n << 1);
		weight.resize(n << 1);
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
