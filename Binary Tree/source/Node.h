#pragma once
#include<queue>

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;

	return newNode;
}


// Traversal DFS (Depth First Search)
// preorer traversal (data, left, right DLR)
void printPreorder(Node* root){
	// base case
	if(root == nullptr) return;

	// data output
	std::cout<<root->data<<'\t';

	// recursice left
	printPreorder(root->left);

	// recursice right
	printPreorder(root->right);
}

void printInorder(Node* root){
	// inorder traversal (left, data, right)
	if(root == nullptr) return;

	printInorder(root->left);
	std::cout<<root->data<<'\t';
	printInorder(root->right);
}

void printPostorder(Node* root){
	// postorder traversal (left, right, data)
	if(root == nullptr) return;

	printPostorder(root->left);
	printPostorder(root->right);
	std::cout<<root->data<<'\t';
}

// Traversal BFS (Breadth First Search) Level Order
void printLevelOrder(Node* root){
	// Base case
	if(root == nullptr) return;

	// queue for level order traversal
	std::queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* node = q.front();
		std::cout<<node->data<<'\t';
		q.pop();

		// enqueue left child
		if(node->left != nullptr) q.push(node->left);

		// enqueue right child
		if(node->right != nullptr) q.push(node->right);
	}
}