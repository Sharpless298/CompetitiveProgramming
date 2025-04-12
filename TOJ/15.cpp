#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int n, m, x;
string s, t;
map<string, int> mp;
tuple<string, int, int> ary[10005];

bool cmp(tuple<string, int, int> &a, tuple<string, int, int> &b) {
	if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
		return get<0>(a) < get<0>(b);
	else if (get<1>(a) == 5 && get<1>(b) == 5)
		return get<2>(a) < get<2>(b);
	else if (get<1>(a) == get<1>(b))
		return get<2>(a) > get<2>(b);
	else
		return get<1>(a) < get<1>(b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	mp["elder"] = 1;
	mp["nursy"] = 2;
	mp["kit"] = 3;
	mp["warrior"] = 4;
	mp["appentice"] = 5;
	mp["medicent"] = 6;
	mp["deputy"] = 7;
	mp["leader"] = 8;

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> s >> t >> x;
			ary[i] = {s, mp[t], x};
		}

		sort(ary, ary + n, cmp);

		if (m > n)
			m = n;
		for (int i = 0; i < m; i++)
			cout << get<0>(ary[i]) << '\n';
	}
}
