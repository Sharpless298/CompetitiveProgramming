struct BIT {
	int n;
	vector<int> bit;

	BIT(int _n):n(_n) {
		bit.assign(n+1, 0);
	}
	void update(int i, int x) {
		for(; i<=n; i+=(i&-i)) bit[i] += x;
	}
	int query(int i) {
		int sum = 0;
		for(; i; i-=(i&-i)) sum += bit[i];
		return sum;
	}
};
