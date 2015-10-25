#include <iostream>
#include <algorithm>

void find_three_sum(int [], unsigned int, int);

int main() {
	int arr[5] = {5, 3, 2, 3, -1};
	find_three_sum(arr, 5, 4);

	find_three_sum(arr, 5, 10);

	return 0;
}

/* Finds and prints a set of 3 numbers that sum up to a value */
void find_three_sum(int arr[], unsigned int len, int target) {

	if (len < 3)
		return;

	std::sort(arr, arr + len);

	for (int i = 0; i <= len - 3; i++) {
		int j = i + 1;
		int k = len - 1;

		while (j < k) {
			if (arr[i] + arr[j] + arr[k] == target) {
				std::cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
				return;
			}

			if (arr[i] + arr[j] + arr[k] > target)
				k--;
			else
				j++;
		}
	}
}