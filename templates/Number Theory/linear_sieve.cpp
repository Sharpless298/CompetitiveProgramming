vector<int> p, lpf(100005);

void sieve(int n) {
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			p.push_back(i);
		}
		for (int j : p) {
			if (i * j > n)
				break;
			lpf[i * j] = j;
			if (j == lpf[i])
				break;
		}
	}
}
