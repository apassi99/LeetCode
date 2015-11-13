#include <iostream>
#include <string.h>

// Given a root of a binary search tree print the
// boundries of the tree in anti-clock wise direction
// Example :
//                    100
//             50              150
//     25            75               225
//           40   60               200
//       35    
//
// Boundry Traversal would be : 100, 50, 25, 40, 35,  60, 200, 225, 150

// Solution :
// This question can be divided into three parts
// 1) Print the left boundry of the tree (Top to Bottom)
// 2) Print the leaf nodes of the tree (In order)
// 3) Print the right boundry of the tree (Bottom to Top)


struct node * node_init(int data, struct node *, struct node*);
struct node * insert(struct node *, int);
struct node * clear(struct node *);

void print_boundries(struct node *);
void print_leaves(struct node *);
void print_left_boundry(struct node *);
void print_right_boundry(struct node *);

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
  root = insert(root, 60);
  root = insert(root, 225);
  root = insert(root, 200);
  root = insert(root, 40);
  root = insert(root, 35);

  print_boundries(root);

  root = clear(root);
}

void print_boundries(struct node * root) {

  if (!root)
    return;

  std::cout << root->data << "\n";

  print_left_boundry(root->left);
  print_leaves(root->left);
  print_leaves(root->right);
  print_right_boundry(root->right);
}

/* Print the left boundry of the tree */
void print_left_boundry(struct node * root) {
  
  if (!root)
    return;

  if (root->left) {
    std::cout << root->data << "\n";
    print_left_boundry(root->left);
  } else if (root->right) {
    std::cout << root->data << "\n";
    print_right_boundry(root->right);
  }
}

/* Print the leaves of the tree */
void print_leaves(struct node * root) {

  if (!root)
    return;

  /* Print if leaf */
  if (!root->left && !root->right)
    std::cout << root->data << "\n";

  /* Do an inoder traversal */
  print_leaves(root->left);
  print_leaves(root->right);
}

/* Recursively print the right boundry of the tree. */
void print_right_boundry(struct node * root) {
  if (!root)
    return;

  if (root->right) {
    print_right_boundry(root->right);
    std::cout << root->data << "\n";
   } else if (root->left) {
    print_right_boundry(root->left);
    std::cout << root->data << "\n";
   }
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
