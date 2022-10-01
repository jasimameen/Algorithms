// Ref: freecodecamp YT
// NOTE: some of the below are psudo code


// 1. string reversal

string reverseString(string input) {
	// base case
	if (input == '') return ""; 

	// smallest amound of work to do in each iteration
	return reverseString(input.substr(1)) + input[0];
}

// 2. palindrom

bool isPalindroim(string input) {
	int n = input.size(); // length of the input

	// base case/ stoping condition
	if (n == 0 || n == 1) return true;

	// Do some work to shrink the problem space
	if (input[0] == input[n-1]) return isPalindroim(input.substr(1, n-1));

	// Additional base case to handle non-palindroms
	return false;
}


// 3. Decimal to Binary

string findBinary(int decimal, sring result) {
	if (decimal==0) return result;

	char rem = (decimal % 2) + '0'; // finds remider then converts to char
	return findBinary(decimal/2, rem + result);
} 	

// 4. Sum of Natural Numbers
int recursiveSummation(int inputNumber) {
	if (inputNumber <= 1) return inputNumber;

	return inputNumber + recursiveSummation(inputNumber-1);
}


/*  ------ Divide & Conquer -------
	(1) Divide problem into several smaller subproblems
	Normally, the subproblems are similar to the original

	(2) Conquer the subproblems by solving them recursively
	Base case: solve small enough problem by bruteforce

	(3) Combine the solutions to get a solution to the subproblems
	And finally a solution to the original problem

	(4) Divide and Conquer algoritms are normally recursive


*/

// 1. Binary Search (Find element from a sorted Array)
int binary_search(int[] arr, int left, int right, int target) {
	// base case 1, Elemtn Not Fount
	if (left > right) return -1;

	int middle = (left + right)/2;

	// Base Case 2, Element found at [middle]
	if (arr[middle] == target) return middle;

	// element in right side
	if (arr[middle] < target) return binary_search(arr, middle + 1, right, target);

	// element in left side
	return binary_search(arr, left, middle - 1, target);
}

// 2. Fibonacci (Non-Optimized)
long fib(long n) {
	if (n==0 || n==1) return n;

	return fib(n-1) + fib(n-2); // sum of the previous two elements
}

// 3. MergeSort

void merge_sort(int[] data, int start, int end) {
	if (start > end ) return data;

	int middle = (start + end) / 2;

	merge_sort(data, start, middle);
	merge_sort(data, middle, end);

	merge(data, start, middle, end);
}

void merge(int[] data, int start, int middle, int end) {
	// build temp array to avoid modifying original contents
	int temp[end - start + 1];

	int i = start, j = middle+1, k=0;

	// while both sub-arrays have values then merge them in sorted order
	while (i<= middle && j <= end) {
		if (data[i] <= data[j]) temp[k++] = data[i++];
		else temp[k++] = data[j++];
	}

	// right sub-array run out of values
	// add rest of the values from left sub-array into temp
	while (i <= middle) temp[k++] = data[i++];

	// left sub-array run out of values
	// add rest of the values from right sub-array into temp
	while (j <= end) temp[k++] = data[j++];

	// copying temp-array to original-arary
	for (i = start; i <= end; i++) data[i] = temp[i - start]; 

}


// ------ LinkeList

// 1. reverse a LinkedList

ListNode reverseList(ListNode head) {
	if (ListNode == null || ListNode.next == null) return head;

	ListNode p = reverseList(head.next);
	head.next.next = head;
	head.next = null;
	return p;
}

// 2. Merge 2 Sorted LinkedList

Node merge_list(Node A,Node B) {
	if (A == null) return B;
	if (B == null) return A;

	if (A.val < B.val) {
		A.next = merge_list(A.next, B);
		return A; 
	}

	B.next = merge_list(A, B.next);
	return B;
}

// ----- Trees

// 1. Insert Value into Binary Search Tree (BST)

void insertNode(Node head, int data) {

	// BST insertion always hapen at the leaf level
	// when head hits null that means it is a leaf node
	if (head == null) {
		head = Node();
		head.data = data;
		return head;
	} 

	// BST only allows Distinct values
	// if value already present, there is no need to insert that value into the tree
	if (head.data == data) return head;

	// when [data] is less than or equals to the node then recurse left
	if (data < head.data) head.left = insertNode(head.left, data);

	// otherwise recuser right
	else head.right = insertNode(head.right, data);


	// return original rootnode after insertion
	return head;
}

// 2. Print All leaf Nodes of BST using

void printLeafs(Node root) {
	// if no value present pop from the stack
	if (root == null) return;

	// leaf node has 0 children
	// given node is leaf
	if (root.left == null && root.right == null) {
		cout << root.data << ", ";
		return;
	}

	// recurse to the left if it has value
	if (root.left != null) printLeafs(root.left);

	// recurse to the right if it has value
	if (root.right != null) printLeafs(root.right);
}


// ------ Graphs

// 1. Depth-First-Search
 bool dfs(Node node, Set<Node> visted, int target) {
 	if (Node == null) return false;

 	if (node.data == target) return true;

 	for (Node child : node.children) {
 		// ignore current iteration if the node alredy visted
 		// it helps to avoid cycles
 		if (visted.contains(child)) continue;
 		
 		// adds current node to the visted list
 		visted.push_back(child);


 		bool found = dfs(child, visted, target);

 		if (found) return true;
 	}

 	// item not found in the graph
 	return false;
 }

// ----- Optimization

/*
--- Memoization & Caching

How can we speed up our program by "caching" things we've already done?

*/

 // ---- Fibonaci (Optimized)

 unordered_map<int, int> memoizedCache;
 
 // initilize the fib of 0 and 1 that we already knows
 memoizedCache[0] = 0;
 memoizedCache[1] = 1;

 long fib(long n) {
 	// if the fib result for the [n] excits in the map return its value
 	if (memoizedCache.contains(n)) return memoizedCache[n];

 	int result = fib(n-1) + fib(n-2);
 	
 	// cache result
 	memoizedCache[n] = result;

 	return result;
 }