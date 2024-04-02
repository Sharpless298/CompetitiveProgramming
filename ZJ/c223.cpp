#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long int lli;

lli n, t, ans, ary[1000005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin>>n && n) {
		ans = 0;
		queue<lli> q;

		for(int i=0, x; i<n; i++) {
			cin >> x;
			ary[i] = x;
		}

		sort(ary, ary+n);
		q.push(ary[0]);
		for(int i=1; (n-i)+q.size()>1;) {
			if(i!=n && ary[i]<q.front()) t = ary[i], i++;
			else t = q.front(), q.pop();

			if(i==n) t += q.front(), q.pop();
			else if(q.empty()) t += ary[i], i++;
			else if(ary[i] < q.front()) t += ary[i], i++;
			else t += q.front(), q.pop();

			q.push(t);
			ans += t;
		}
		
		cout << ans << '\n';
	}
}
