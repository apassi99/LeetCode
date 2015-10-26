#include <iostream>
#include <stdlib.h>  

/*
 * Following is a code to perform merge sort on a linked list.
 */

struct node * sort(struct node *);
struct node * merge(struct node *, struct node *);
struct node * get_mid(struct node *);

struct node * node_init(int, struct node *);
struct node * push_front(struct node *, int);
struct node * clear_list(struct node *);
void print_list(struct node *);

struct node {
	struct node * next;
	int data;
};

int main() {

	struct node * head = NULL;

	for (int i = 0; i < 15; i++) {
		head = push_front(head, rand() % 100);
	}

	print_list(head);
	head = sort(head);
	print_list(head);
	head = clear_list(head);


	for (int i = 15; i > 0; i--) {
		head = push_front(head, i);
	}

	print_list(head);
	head = sort(head);
	print_list(head);
	head = clear_list(head);

	for (int i = 15; i > 14; i--) {
		head = push_front(head, i);
	}

	print_list(head);
	head = sort(head);
	print_list(head);
	head = clear_list(head);

	for (int i = 0; i < 2; i++) {
		head = push_front(head, i);
	}

	print_list(head);
	head = sort(head);
	print_list(head);
	head = clear_list(head);

	return 0;
}

struct node * sort(struct node * head) {

	// List is empty or size is 1
	if (!head || !head->next)
		return head;

	/* mid will never be null*/
	struct node * mid = get_mid(head);
	struct node * temp = mid->next;
	mid->next = NULL;
	mid = temp;

	return merge(sort(head), sort(mid));
}

struct node * get_mid(struct node * head) {
	// List is empty or size is 1
	if (!head || !head->next)
		return head;

	struct node * cur = head;
	struct node * fast_cur = head;

	while (fast_cur->next && fast_cur->next->next) {
		cur = cur->next;
		fast_cur = fast_cur->next->next;
	}

	return cur;
}

struct node * merge(struct node * n1, struct node * n2) {

	if (!n1)
		return n2;
	if (!n2)
		return n1;

	struct node * new_head = new struct node;
	struct node * cur = new_head;
	struct node * temp = new_head;

	while (n1 && n2) {
		if (n1->data <= n2->data) {
			cur->next = n1;
			n1 = n1->next;
		} else {
			cur->next = n2;
			n2 = n2->next;
		}
		cur = cur->next;
	}

	cur->next = (n1) ? n1 : n2;
	new_head = new_head->next;
	free(temp);

	return new_head;

}

struct node * node_init(int data, struct node * next) {

	struct node *n = new struct node;
	n->data = data;
	n->next = next;
	return n;
}

struct node * push_front(struct node *head, int data) {
	struct node * new_head = node_init(data, head);
	return new_head;
}

void print_list(struct node * n) {
	if (!n)
		return;

	while(n) {
		std::cout << n->data << " ";
		n = n->next;
	}

	std::cout << "\n";
}

struct node * clear_list(struct node * head) {

	struct node * cur = head;

	while(head) {
		head = head->next;
		free(cur);
		cur = head;
	}

	return head;
}