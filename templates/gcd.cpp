#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b?gcd(b, a%b):a;
}

long long int gcd(long long int a, long long int b) {
	while(b){
        a %= b;
        a ^= b, b ^= a, a ^= b;
    }
    return a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << gcd(-2, -4) << '\n';
}
