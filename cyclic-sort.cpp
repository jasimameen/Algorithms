#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums) {
	int len = nums.size();
	int i =0;

	while (i<len) {

		// elements are in range (0 - N)
		int correct = nums[i]; // use nums[i] - 1 insted when the range is (1 - N)

		if (nums[i] == nums[correct]) i++;
		else swap(nums[i], nums[correct]);
	}

	for (int val : nums) cout << val << " ";
}


int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

vector<int> nums;
int inp;

while (cin >> inp) nums.push_back(inp);

solve(nums);

return 0;
}

