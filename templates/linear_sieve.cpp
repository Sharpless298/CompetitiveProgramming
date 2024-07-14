#include <iostream>
#include <vector>
using namespace std;

int lpf[100005];
vector<int> p;

void sieve(int n) {
	fill(lpf, lpdf+n+1, 1);

	for(int i=2; i<=n; i++) {
		if(lpf[i] == 1) {
			lpf[i] = i;
			p.push_back(i);
		}
		for(int j:p) {
			if(i*j > n) break;
			lpf[i*j] = j;
			if(j == lpf[i]) break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(100);
}
