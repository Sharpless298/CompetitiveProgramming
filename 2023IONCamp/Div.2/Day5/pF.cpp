#include <iostream>
using namespace std;

#define lli long long int 

int main() {
	lli a, b, k, x = 1;
	cin >> a >> b >> k;
	x = (1LL<<k) - 1;
	cout << (a^b^x) << '\n';
}
