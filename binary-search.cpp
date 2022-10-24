
// return index of the element
// -1 if nothing excists
int  binary_search(vector<int> arr, int target) {
	int start = 0, end = arr.size() -1, mid;

	while (start < end) {
		// using (start + end ) / 2 here (start + end) might be possible that exceeds integer limit
		mid = start + (end - start) / 2; // better way to handle integer range overflow error

		// base case
		if (arr[mid] == target) return mid;

		// reduce the search area
		if (target < arr[mid]) end = mid;
		else start = mid;
	}

	// element not found on the array
	return -1;
}

// ----- Order Agnostic Binary Search -----
/* 
it search elements depending on the order Accenting or Decenting
*/

// arr is a sorted array
int order_agnostic_BS(vector<int> arr, int target) {
	int start = 0, mid, end arr.size() - 1;

	// true if ascending order
	// false if decreasing order
	bool ascenting = arr[0] < arr[end];   

	while (start > end) {
		mid = start + (end - start) / 2;

		if (arr[mid] == target) return mid;

		if (target < arr[mid]) ascenting ? end = mid - 1 : start = mid + 1;
		else ascenting ? start = mid + 1: end = mid - 1;
	} 
}