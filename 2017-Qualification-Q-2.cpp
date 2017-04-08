/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

int getCounts(int *w, int n) {
	sort(w, w+n);

	int l, r, count, sum;

	l = 0;
	r = n-1;
	count = 0;

	while(l <= r) {
		sum = w[r];
		r--;

		if(sum >= 50) {
			count++;
			continue;
		}

		while(l <= r && sum < 50) {
			l++;
			sum += w[r+1];
		}

		if(sum >= 50)
			count++;
	}

	return count;
}

int main(void) {
	int t, n, j, *w;

	cin >> t;
	j = 1;

	while(j <= t) {
		cin >> n;

		w = new int[n];

		for(int i = 0; i < n; i++)
			cin >> w[i];

		cout << "Case #" << j << ": " << getCounts(w, n) << endl;

		delete[] w;
		j++;
	}

	return 0;
}
