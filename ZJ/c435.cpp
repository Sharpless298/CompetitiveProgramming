#include <iostream>
using namespace std;

const int INF = 2e9;

int n, ary[100005], ans;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ans = -INF;

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ary[i];
	
	for(int i=0, j=1; i<n; ) {
		ans = max(ary[i]-ary[j]);

		if(ary[i] <= ary[j]) i = j, j++;
		else j++;
	}
}
