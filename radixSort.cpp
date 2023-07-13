#include <iostream>
#include <string>
#include <queue>
using namespace std;

void radixSort(string arr[], int n) {
	queue<string> q[26];
	int max = 0, pos;
	for (int i = 0; i < n; i++) {
		if (arr[i].length() > max) {
			max = arr[i].length();
		}
	}
	pos = max;
	for (int i = 0; i < max; i++) {
		pos--;
		for (int j = 0; j < n; j++) {
			int id = pos - arr[j].size();
			if (id >= 0) {
				q[0].push(arr[j]);
			}
			else {
				q[arr[j][pos] - 97].push(arr[j]);
			}
		}
		int ind = 0;
		for (int k = 0; k < 26; k++) {
			while (!q[k].empty()) {
				arr[ind] = q[k].front();
				q[k].pop();
				ind++;
			}
		}
	}
}

int main() {
	string arr[12] = { "ali", "bilal", "rizwan", "usama", "usman", "haider", "shadab", "wahab", "farhan", "farrukh", "hammad", "aslam" };
	cout << "Before sorting:\n";
	for (int i = 0; i < 12; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n\nAfter sorting:\n";
	radixSort(arr, 12);
	for (int i = 0; i < 12; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
	return 0;
}