template <typename T>
struct SparseTable {
	int n, K;
	vector<vector<T>> st;
	vector<int> lg;
	function<T(T, T)> f;

	SparseTable(const auto &a, auto _f) : n((int)a.size()), f(_f) {
		lg.resize(n + 1);
		lg[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i / 2] + 1;
		}

		st.resize(n, vector<T>(lg[n] + 1));
		for (int i = 0; i < n; i++) {
			st[i][0] = a[i];
		}

		for (int k = 1; k <= lg[n]; k++) {
			for (int i = 0; i + (1 << k) <= n; i++) {
				st[i][k] = f(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
			}
		}
	}

	T query(int l, int r) {
		int k = lg[r - l];
		return f(st[l][k], st[r - (1 << k)][k]);
	}
};
