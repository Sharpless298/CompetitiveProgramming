template <typename T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n) : n(_n) {
		bit.assign(n + 1, 0);
	}

	void update(int i, T x) {
		for (; i <= n; i += (i & -i))
			bit[i] += x;
	}
	T query(int i) {
		T sum = 0;
		for (; i; i -= (i & -i))
			sum += bit[i];
		return sum;
	}
};
