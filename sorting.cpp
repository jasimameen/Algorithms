// swaps two elements
void swap (int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// minimum of two Numbers
int min (int& a, int& b) {
	if (a<b) return a;
	return b;
}

// get smallest of the array
int smallestOfArray(int[]& arr, int& lastIndex) {
	int minimum = arr[lastIndex];
	while(lastIndex--) minimum = min(arr[lastIndex], minimum);
}


// BruteForce aproch
void BruteForce(int[] arr, int n) {
	for (int i=0; i<n-1; i++) 
		for (int j=i+1; j<n;j++) 
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);

	while (n--) cout<<arr[n]<<endl;
}

void selection_sort(int arr[MAX], int n) {
	int i =0, smallest;
	while (i<n) {
		smallest = smallestOfArray(arr, i);
		swap(arr[i], smallest);
		i++;
	}

	while(n--)  cout << arr[n];
}
