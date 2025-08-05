vector<int> primes, lpf(100005);
void sieve(int n) {
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (i * p > n) break;
			lpf[i * p] = p;
			if (p == lpf[i]) break;
		}
	}
}
