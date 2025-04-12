#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> get_hash(string &s) {
	vector<long long> res(s.size() + 1);
	for (int i = 0; i < (int)s.size(); i++)
		res[i + 1] = (res[i] * 29 + s[i] - 'a') % MOD;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int len = (int)s.size();

	vector<long long> pref = get_hash(s);
	vector<long long> pow(len + 1);
	pow[0] = 1;
	for (int i = 0; i < len; i++)
		pow[i + 1] = pow[i] * 29 % MOD;

	for (int i = len / 2; i < len - 1; i++) {
		if (pref[i + 1] == ((pref[len] - pref[len - i - 1] * pow[i + 1]) % MOD + MOD) % MOD) {
			cout << "YES\n";
			cout << s.substr(0, i + 1);
			return 0;
		}
	}
	cout << "NO\n";
}
