#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int prime[1000005];
vector<int> p;

void sieve(int n) {
	fill(prime, prime + n + 1, 1);

	for (int i = 2; i <= n; i++) {
		if (prime[i] == 1)
			p.push_back(i);
		for (int j : p) {
			if (i * j > n)
				break;
			prime[i * j] = j;
			if (i % j == 0)
				break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans, A, B;

	sieve(1000000);

	while (cin >> A >> B) {
		ans = 0;

		if (A > B)
			swap(A, B);
		ans = (int)(upper_bound(p.begin(), p.end(), A) - p.begin());

		lli tmp = 1;
		for (int i = A + 1; i <= B; i++)
			tmp *= i;
		tmp++;

		for (int i = 0; i < ans; i++)
			while (tmp % p[i] == 0)
				tmp /= p[i];

		for (int i = ans; i < (int)p.size(); i++) {
			if (tmp % p[i] == 0) {
				ans++;
				while (tmp % p[i] == 0)
					tmp /= p[i];
			}
		}

		if (tmp != 1)
			ans++;
		cout << ans << '\n';
	}
}
