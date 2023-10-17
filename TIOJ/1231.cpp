#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> ary[100005];
priority_queue<int> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, idx = 0, ans = 0, t;

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ary[i].second >> ary[i].first;
	cin >> t;

	sort(ary, ary+n, greater<pair<int, int>>());
	
	while(t)  {
		while(idx<n && ary[idx].first>=t) {
			pq.push(ary[idx].second);
			idx++;
		}
		if(pq.empty()) {
			ans -= t-ary[idx].first;
			t = ary[idx].first;
		}
		else {
			ans += pq.top();
			pq.pop();
			t--;
		}
	}
	cout << ans << '\n';
}
