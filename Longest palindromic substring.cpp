#include <iostream>

using namespace std;

const int N = 102;
const int P = 137;

int pht[N], sht[N];
int pwr[N];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	pwr[0] = 1;
	for (int i = 1; i < N; i++) {
		pwr[i] = pwr[i - 1] * P;
	}
	
	pht[0] = s[0];
	for (int i = 1; i < n; i++) {
		pht[i] = pht[i - 1] * P + s[i];
	}

	sht[n - 1] = s[n - 1];
	for (int i = 1; i < n; i++) {
		sht[n - i - 1] = sht[n - i] * P + s[n - i - 1];
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < n - i + 1; j++) {
			if (pht[j + i - 1] - (j - 1 >= 0 ? pht[j - 1] : 0) * pwr[i] ==
				sht[j] - (j + i < n ? sht[j + i] : 0) * pwr[i]) {
					cout << i;
					return 0;
				}
		}
	}
}
