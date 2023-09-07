#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+5;

int n;
int ary[MAXN];

int lbound(int l, int r, int k) {
	int m;

	while(l < r) {
		m = (l+r)/2;
		if(ary[m] < k)
			l = m+1;
		else
			r = m;
	}
	return l;
}

int ubound(int l, int r, int k) {	
	int m;

	while(l < r) {
		m = (l+r)/2;
		if(ary[m] <= k)
			l = m+1;
		else
			r = m;
	}
	return l;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, k;

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ary[i];
	cin >> m;
	
	sort(ary, ary+n);
	while(m--) {
		cin >> k;
		cout << ubound(0, n, k) - lbound(0, n, k) << '\n';
	}
}
