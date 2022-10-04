
// return index of the element
// -1 if nothing excists
int  binary_search(vector<int> arr, int target) {
	int start = 0, end = arr.size() -1, mid;

	while (start < end) {
		// using (start + end ) / 2 may exceeds the integer limit when it comes to huge inputs
		mid = start + (end - start) / 2; // better way to handle integer range overflow

		// base case
		if (mid == target) return mid;

		// reduce the search area
		if (target < arr[mid]) end = mid;
		else start = mid;
	}

	// element not found on the array
	return -1;
}