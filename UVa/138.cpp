#include <iomanip>
#include <iostream>
using namespace std;

#define lli long long int

signed main() {
	int cnt = 10;
	lli sum_l = 1, sum_r = 3;

	for (int i = 4, j = 2; cnt; i++) {
		sum_r += i;
		while (j < i - 1 && sum_l < sum_r) {
			sum_l += j;
			sum_r -= (j + 1);
			j++;
		}
		if (sum_l == sum_r) {
			cout << setw(10) << j << setw(10) << i << '\n';
			cnt--;
		}
	}
}
