#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> get_hash(string &s) {
	vector<long long> res(s.size() + 1);
	for (int i = 0; i < (int)res.size() - 1; i++)
		res[i + 1] = (res[i] * 29 + s[i] - 'a') % MOD;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string t;
		cin >> t;
		vector<long long> pref = get_hash(t);

		int q;
		cin >> q;
		while (q--) {
			string p;
			cin >> p;

			int len = (int)p.size();
			long long k = 0;
			for (int i = 0; i < len; i++)
				k = (k * 29 + p[i] - 'a') % MOD;

			long long pow = 1;
			for (int i = 0; i < len; i++)
				pow = pow * 29 % MOD;

			int cnt = 0;
			for (int i = 0; i < (int)pref.size() - len; i++) {
				long long tmp = ((pref[i + len] - pref[i] * pow) % MOD + MOD) % MOD;
				if (tmp == k)
					cnt++;
			}

			cout << cnt << '\n';
		}
	}
}
