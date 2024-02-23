#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long int lli;

int n, m, q, sum, ary[1000005];
lli qs;
set<int> s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;
	for(int i=0; i<n; i++)
		cin >> ary[i];
	
	sort(ary, ary+n);
	for(int i=0; i<m; i++)
		sum += ary[i]*(m-i);
	s.insert(sum);
	while(next_permutation(ary, ary+n)) {
		sum = 0;
			
		for(int i=0; i<m; i++)
			sum += ary[i]*(m-i);
		s.insert(sum);
	}
	
	for(int i=0; i<q; i++) {
		cin >> qs;

		cout << "Case #" << i+1 << '\n';
		if(qs < *s.begin()*1LL)
			cout << "No Solution!\n";
		else
			cout << *prev(s.upper_bound((int)qs)) << '\n';
	}
}
