#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> get_hash(string &s) {
	vector<long long> res(s.size() + 1);
	for (int i = 0; i < (int)s.size(); i++)
		res[i + 1] = (res[i] * 29 + s[i] - 'A') % MOD;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	string t(s.rbegin(), s.rend());

	vector<long long> pow(n + 1);
	pow[0] = 1;
	for (int i = 0; i < n; i++)
		pow[i + 1] = pow[i] * 29 % MOD;

	vector<long long> a = get_hash(s), b = get_hash(t);

	for (int i = 0; i < n; i++) {
		if ((a[n] - (a[i] * pow[n - i]) % MOD + MOD) % MOD == b[n - i]) {
			cout << i << '\n';
			return 0;
		}
	}
}
