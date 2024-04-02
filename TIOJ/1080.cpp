#include <iostream>
using namespace std;

typedef long long int lli;

int n, c, ary[100005], tmp[100005];
lli ans;

void merge(int l, int r) {
	int m = (l+r)/2;

	for(int i=l, j=m+1, k=l; k<=r; k++) {
		if(i > m)
			tmp[k] = ary[j++];
		else if(j > r)
			tmp[k] = ary[i++];
		else if(ary[i] <= ary[j])
			tmp[k] = ary[i++];
		else {
			tmp[k] = ary[j++];
			ans += (m-i+1);
		}
	}
	for(int i=l; i<=r; i++)
		ary[i] = tmp[i];
}

void merge_sort(int l, int r) {
	if(l == r) return;

	int m = (l+r)/2;

	merge_sort(l, m);
	merge_sort(m+1, r);
	merge(l, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin>>n && n) {
		ans = 0;

		for(int i=0; i<n; i++)
			cin >> ary[i];
		
		merge_sort(0, n-1);

		cout << "Case #" << ++c << ": " << ans << '\n';
	}
}
