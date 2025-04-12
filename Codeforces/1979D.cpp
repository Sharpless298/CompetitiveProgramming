#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
const long long P = rng() % MOD + 26;

int n;

long long f(string &s) {
	long long res = 0;
	for (int i = 0; i < n; i++)
		res = (res * P + s[i] - '0') % MOD;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> power(100001);
	power[0] = 1;
	for (int i = 1; i < 100001; i++)
		power[i] = power[i - 1] * P % MOD;

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> n >> k;
		string s;
		cin >> s;

		string s1, s2;
		s1.resize(n), s2.resize(n);
		for (int i = 0; i < n; i++) {
			s1[i] = (char)('0' + (i / k) % 2);
			s2[i] = (char)('0' + (i / k + 1) % 2);
		}

		vector<long long> pref(n + 1), suf(n + 1);
		pref[0] = 0;
		for (int i = 0; i < n; i++)
			pref[i + 1] = (pref[i] * P + s[i] - '0') % MOD;
		suf[0] = 0;
		for (int i = 0; i < n; i++)
			suf[i + 1] = (suf[i] * P + s[n - i - 1] - '0') % MOD;

		bool ok = false;
		long long hash1 = f(s1), hash2 = f(s2);
		for (int i = 1; i <= n; i++) {
			long long t = (pref[n - i] * power[i] % MOD + suf[i]) % MOD;

			if (t == hash1 || t == hash2) {
				ok = true;
				cout << n - i << '\n';
				break;
			}
		}
		if (!ok)
			cout << -1 << '\n';
	}
}
