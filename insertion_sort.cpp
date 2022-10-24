#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> nums) {
	int len = nums.size();

	if (len == 0) {
		cout << "List is Empty" << endl; 
		return;
	}

	for (int i=0; i<len -1; i++) 
		for (int j=i+1; j>0; j--) {
			if (nums[j] < nums[j-1]) swap(nums[j], nums[j-1]);
			else break;
		}
	

	for (int num : nums) cout << num << " ";
}


int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

vector<int> nums;
int inp;

while (cin>>inp) nums.push_back(inp); 

insertion_sort(nums);

return 0;
}

