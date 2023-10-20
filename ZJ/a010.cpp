#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int n, p;

	cin >> n;
	
	primes.emplace_back(2);
	for(int i=3; i<50000000; i+=2) {
		f = true;	
		for(int k:primes) {
			if(k*k > i) break;
			if(i%k == 0) {
				f = false;
				break;
			}
		}
		if(f) primes.emplace_back(i);
	}
	
	f = false;
	for(int i:primes) {
		p = 0;

		if(n < i) break;
		
		while(n%i == 0) {
			p++;
			n/=i;
		}
		
		if(p == 0) continue;
		if(p == 1) {
			if(f) cout << " * ";
			cout << i;
			f = true;
		}
		else {
			if(f) cout << " * ";
			cout << i << '^' << p;
			f = true;
		}
	}
}
