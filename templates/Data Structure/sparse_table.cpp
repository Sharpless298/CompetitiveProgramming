template <typename T>
struct SparseTable {
	int n, K;
	// vector<vector<int>> mn;
	// vector<vector<int>> mx;
	vector<vector<int>> st;
	vector<int> lg;
	function<T(T, T)> f;
	SparseTable(const vector<int> &a, auto func) : f(func) {
		n = (int)a.size();
		lg.resize(n + 1);

		lg[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i / 2] + 1;
		}

		// mn.assign(n, vector<int>(lg[n] + 1));
		// mx.assign(n, vector<int>(lg[n] + 1));
		st.assign(n, vector<int>(lg[n] + 1));

		for (int i = 0; i < n; i++) {
			// mn[i][0] = a[i];
			// mx[i][0] = a[i];
			st[i][0] = a[i];
		}

		for (int k = 1; k <= lg[n]; k++) {
			for (int i = 0; i + (1 << k) <= n; i++) {
				// mn[i][k] = min(mn[i][k - 1], mn[i + (1 << (k - 1))][k - 1]);
				// mx[i][k] = max(mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1]);
				st[i][k] = f(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
			}
		}
	}
	/*
	int query_min(int l, int r) {
		int k = lg[r - l];
		return min(mn[l][k], mn[r - (1 << k)][k]);
	}

	int query_max(int l, int r) {
		int k = lg[r - l];
		return max(mx[l][k], mx[r - (1 << k)][k]);
	}
	*/
	T query(int l, int r) {
		int k = lg[r - l];
		return f(st[l][k], st[r - (1 << k)][k]);
	}
};
