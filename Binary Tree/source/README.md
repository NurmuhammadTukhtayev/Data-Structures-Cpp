## Binary tree. Create a new node.
<b>
In this file we gonna create Node for our binary tree. To create binary tree we need node with value and pointers.
</b>
</br></br>
<p>Our node has data (int type, it can be whatever you want), left and right pointers. So we use struct for this node as shown below.</p>

``` cpp
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
```

<p>To create a new node we gonna use function called createNode. This function takes integer data as a parameter and returns the new node with pointers.</p>

``` cpp
    Node* createNode(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;

        return newNode;
    }
```

In the main.cpp file we can include Node.h header file and use the function to create new binary tree with nodes.

``` cpp
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

```

This part of code will create binary tree like this:
![image](https://user-images.githubusercontent.com/83575005/211039837-f7fedd76-6207-44d0-acae-ce93b2b5a6ee.png)

## Binary tree Traversal
<b> A Tree is typically traversed in two ways: 
    <ul>
        <li>Depth First Traversal:
            <ol>
                <li>Inorder Traversal (Left-Root-Right)
                <li>Preorder Traversal (Root-Left-Right)
                <li>Postorder Traversal (Left-Right-Root)
            </ol>
        <li>Breadth First Traversal (Or Level Order Traversal)  
    </ul>
</b>

---
~~~
Depth First Traversal
~~~
<p>
Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. 

So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.
</p>

![Depth-First-Search](https://user-images.githubusercontent.com/83575005/211043185-5e80f81d-c00e-4ec6-8b40-ffd6209af947.gif)


Depth First Search code implementation.

```cpp
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
```

We can traversal inorder or postorder just by changing the order of line codes.

``` cpp
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
```

---
~~~
Breadth First Traversal (Level Order) 
~~~
<p>
Print the level order traversal of the tree using recursive function to traverse all nodes of a level. Find height of tree and run depth first search and maintain current height, print nodes for every height from root and for 1 to height and match if the current height is equal to height of the iteration then print node’s data.
</p>


![1_3NKvODZparRFVKEwtVmrkw](https://user-images.githubusercontent.com/83575005/211041607-28e7ca5b-c713-4fec-86b0-5b99351017b0.gif)

Code implementation:

``` cpp
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
```


~~~
Code output and result.
~~~
<b>In main.cpp file we can use all above functions.</b>

``` cpp
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
```

The output should be like
![image](https://user-images.githubusercontent.com/83575005/211045247-cad3423e-5b94-4fc4-b72a-da61682f7295.png)


<i> Source information [geeksforgeeks.org](https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/)
</i>