#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define lowbit(x) x&-x

int n;
vector<int> BIT;

void update(int id) {
	for(; id<=n; id+=lowbit(id)) BIT[id]++;
}

int query(int id) {
	int res = 0;
	for(; id; id-=lowbit(id)) res += BIT[id];
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int Case = 0;

	while(cin>>n && n) {
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin >> a[i];

		vector<int> v = a;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end())-v.begin());
		for(int i=0; i<n; i++)
			a[i] = (int)(upper_bound(v.begin(), v.end(), a[i])-v.begin());

		reverse(a.begin(), a.end());
		
		long long ans = 0;
		BIT.resize(n+1);
		fill(BIT.begin(), BIT.end(), 0);
		for(int i=0; i<n; i++) {
			ans += query(a[i]-1);
			update(a[i]);
		}

		cout << "Case #" << ++Case << ": " << ans << '\n';
	}
}
