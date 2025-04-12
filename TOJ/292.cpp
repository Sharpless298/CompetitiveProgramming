#include <iostream>
using namespace std;

long long int t, ans;

int main() {
	long long int A, B, C;
	cin >> A >> B >> C;

	for (int i = 1; C != 0; i *= A) {
		t += C % 10 * i;
		C /= 10;
	}
	for (int i = 1; t != 0; i *= 10) {
		ans += t % B * i;
		t /= B;
	}
	cout << ans << '\n';
}
