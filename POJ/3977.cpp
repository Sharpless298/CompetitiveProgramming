#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define abs(x) (x < 0 ? -(x) : (x))

typedef long long int lli;

const lli INF = 9e18;

int n, n1, n2;
lli t, ary[64], sum;
pair<lli, lli> ans;
map<lli, lli> mp;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n && n) {
		map<lli, lli>::iterator it;

		n1 = n / 2, n2 = n - n1;
		ans.first = ans.second = INF;
		mp.clear();

		for (int i = 0; i < n; i++)
			cin >> ary[i];

		for (int i = 1; i < (1 << n1); i++) {
			sum = t = 0;

			for (int j = 0, k = i; j < n1; j++, k /= 2)
				if (k & 1)
					sum += ary[j], t++;
			ans = min(ans, make_pair(abs(sum), t));
			if (!mp[sum])
				mp[sum] = t;
			else
				mp[sum] = min(mp[sum], t);
		}

		for (int i = 1; i < (1 << n2); i++) {
			sum = t = 0;

			for (int j = 0, k = i; j < n2; j++, k /= 2)
				if (k & 1)
					sum += ary[j + n1], t++;
			ans = min(ans, make_pair(abs(sum), t));

			it = mp.lower_bound(-sum);
			if (it != mp.end())
				ans = min(ans, make_pair(abs(it->first + sum), it->second + t));
			if (it != mp.begin()) {
				it--;
				ans = min(ans, make_pair(abs(it->first + sum), it->second + t));
			}
		}

		cout << ans.first << ' ' << ans.second << '\n';
	}
}
