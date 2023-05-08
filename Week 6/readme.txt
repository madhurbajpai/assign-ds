Name - Madhur Bajpai
Reg. No. 2022CA047
Week 6

In this week we learnt about 
1. Tree traversal using recursion 
	1.1 Inorder traversal
		We have implemented following function recursively
		1.1.1 First traverse the left subtree recursively
		1.1.2 Second traverse the root node
		1.1.3 Third traverse the right subtree recursively
	1.1 Preorder traversal
		We have implemented following function recursively
		1.1.1 First traverse the root node
		1.1.2 Second traverse the left subtree recursively
		1.1.3 Third traverse the right subtree recursively
	1.1 Postorder traversal
		We have implemented following function recursively
		1.1.1 First traverse the left subtree recursively
		1.1.2 Second traverse the right subtree recursively
		1.1.3 Third  traverse the root node
2. Tree traversal using iteration
	In preorder traversal we first create the empty stack and push root node to stack. In loop we did the following
	pop an item from the stack and print it.
	push right child of a popped item to stack
	push left child of a popped item to stack
	In postorder we first push root to first stack and did following in loop
	pop a node from first stack and push it to second stack
	push left and right children of the popped to first stack
	print contents of second stack
3. Heap sort
	In heap sort we first build a max heap. Then, the maximum element is stored at the root of the heap. Replace it with the 	last item of the heap followed by reducing the size of the heap by 1. Finally, heapify the root of the tree. Repeat previous 	step while the size of the heap is greater than 1.
