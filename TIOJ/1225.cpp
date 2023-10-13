#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int lli;

const int INF = 2e9;
const int MAXN = 1e6;

int ary[MAXN+5], pre[MAXN+5], nxt[MAXN+5];
vector<pair<int, int>> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	lli ans = 0;

	cin >> n;
	for(int i=0, x; i<n; i++) {
		cin >> x;
		ary[i] = x;
		v.emplace_back(x, i);
	}
	sort(v.begin(), v.end());

	pre[0] = nxt[n-1] = INF;
	for(int i=1; i<n; i++)
		pre[i] = i-1;
	for(int i=0; i<n-1; i++)
		nxt[i] = i+1;

	for(int i=0, idx; i<n-1; i++) {
		idx = v[i].second;
		if(pre[idx]==INF || nxt[idx]==INF) {
			if(pre[idx] < nxt[idx]) {
				ans += ary[pre[idx]];
				nxt[pre[idx]] = nxt[idx];
			}
			else {
				ans += ary[nxt[idx]];
				pre[nxt[idx]] = pre[idx];
			}
		}
		else {
			if(ary[pre[idx]] < ary[nxt[idx]])
				ans += ary[pre[idx]];
			else 
				ans += ary[nxt[idx]];

			pre[nxt[idx]] = pre[idx];
			nxt[pre[idx]] = nxt[idx];
		}
	}

	cout << ans << '\n';
}
