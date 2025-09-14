vector<int> primes, lpf;
void sieve(int n) {
	lpf.assign(n + 1, 1);
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (i * p > n) {
				break;
			}
			lpf[i * p] = p;
			if (p == lpf[i]) {
				break;
			}
		}
	}
}
