// Complexity
// Best: O(1)TS
// Worst: O(n)T and O(1)S

#include<bits/stdc++.h>

using namespace std;

// if target available then return the index
// else returns -1
int linear_search(vector<int> arr, int target) {
	int len = arr.size();

	// here i represents the index of each iteration
	for (int i = 0; i < len; ++i) 
		if (arr[i] == target) return i;

	// target has not found
	return -1;
}


// ------ search char in string
int search_in_string(string str, char target) {
	int len = str.size();

	for (int i=0; i<len; i++) 
		if (str[i]==target) return i;

	return -1;
}

//=====================
//==== Driver Code ====
//=====================
int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int val; // modifies everytime new value inputs

vector<int> arr;

while(cin>>val) arr.push_back(val); // input values into the array

cout << "Search In Numbers: " << linear_search(arr, 8) << endl;

// Linear Serch on String
cout << "Search In String: " << search_in_string("Leskeboy", 'b') << endl;

return 0;
}

