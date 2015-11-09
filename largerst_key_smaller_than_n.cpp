#include <iostream>

// Given a root of a binary search tree and a key x, 
// find the largest key in the tree that is smaller than x.
// Example: if an in-order list of all keys in the tree is 
// {2, 3, 4, 7, 17, 19, 21, 35, 89} and x is 19, 
// the biggest key that is smaller than x is 17.

struct node * node_init(int data, struct node *, struct node*);
struct node * insert(struct node *, int);
struct node * clear(struct node *);

struct node * find_largest_smaller_than_n(struct node *, int);

struct node {
	struct node * left;
	struct node * right;
	int data;
};

int main() {
	struct node * root = NULL;

	root = insert(root, 100);
	root = insert(root, 50);
	root = insert(root, 75);
	root = insert(root, 25);
	root = insert(root, 150);

	struct node * n = find_largest_smaller_than_n(root, 100);
	std::cout << n->data << "\n";

	n = find_largest_smaller_than_n(root, 60);
	std::cout << n->data << "\n";

	
	n = find_largest_smaller_than_n(root, 20);

        std::cout << n << "\n";

	root = clear(root);
}

struct node * find_largest_smaller_than_n(struct node * root, int data) {
	if (!root)
		return root;

	struct node * max_node = NULL;

	while (root) {
		if (root->data < data) {
			max_node = root;
			root = root->right;
		} else {
			root = root->left;
		}
	}

	return max_node;
}

/** 
 * Initializes a node
 * Args :
 *	- data : data element
 *	- l : left child
 *	- r : right child
 * Return :
 *	Pointer to the node.
 */
struct node * node_init(int data, struct node *l, struct node *r) {
	struct node * n = new struct node;
	n->data = data;
	n->left = l;
	n->right = r;
	return n;
}

/* Inserts a data element in the BST */
struct node * insert(struct node * root, int data) {
	if (!root) {
		root = node_init(data, NULL, NULL);
		return root;
	}

	// Not allowing duplicates
	if (root->data == data) {
		return root;
	}

	if (root->data > data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}

        return root;
}

/* Remove all the elements in the BST */
struct node * clear(struct node * root) {
	if (!root)
		return root;

	if (!root->left && !root->right) {
		free(root);
	 	return NULL;
	}

	root->left = clear(root->left);
	root->right = clear(root->right);
	free(root);
        return NULL;
}
