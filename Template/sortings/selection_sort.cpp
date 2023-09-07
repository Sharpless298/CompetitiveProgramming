#include <iostream>
using namespace std;

void selection_sort() {
	for(int i=0; i<n-1; i++) {
		for(int j=i+1, smallest=i; j<n; j++) {
			if(ary[j] < ary[smallest])
				j = smallest;
		}
		swap(ary[i], ary[smallest]);
	}
}
			
