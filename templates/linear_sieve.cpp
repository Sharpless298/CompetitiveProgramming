#include <iostream>
#include <vector>
using namespace std;

int prime[100005];
vector<int> p;

void sieve(int n) {
	fill(prime, prime+n+1, 1);

	for(int i=2; i<=n; i++) {
		if(prime[i] == 1) p.push_back(i);
		for(int j:p) {
			if(i*j > n) break;
			prime[i*j] = j;
			if(i%j == 0) break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(100);
}
