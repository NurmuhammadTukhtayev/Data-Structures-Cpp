#include<iostream>
#include "Node.h"

int main(){
	// root node | level 0
	Node* root = createNode(1);

	// level 1
	root->left = createNode(2);
	root->right = createNode(3);

	// level 2
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	// level 3
	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);

	// preorder DLR
	std::cout<<"Traversal binary tree as DFS (preorder)\n";
	printPreorder(root);
	std::cout<<'\n';

	// inorder LDR
	std::cout<<"Traversal binary tree as DFS (inorder)\n";
	printInorder(root);
	std::cout<<'\n';

	// postorder LRD
	std::cout<<"Traversal binary tree as DFS (postorder)\n";
	printPostorder(root);
	std::cout<<'\n';

	// Level Order traversal
	std::cout<<"Traversal binary tree as BFS\n";
	printLevelOrder(root);
	std::cout<<'\n';
}
