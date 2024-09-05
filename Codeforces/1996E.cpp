#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int lli;

const int MOD = 1e9+7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;

		int n = s.size();
		vector<int> a(n);
		for(int i=0; i<n; i++)
			a[i] = (s[i]=='1' ? 1 : -1);

		vector<int> pref(n+1);
		for(int i=0; i<n; i++)
			pref[i+1] = pref[i] + a[i];

		lli ans = 0;
		map<int, lli> mp;
		for(int i=1; i<=n; i++) {
			ans = (ans + 
		}
	}
}
