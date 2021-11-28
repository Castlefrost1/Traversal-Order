#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *searchSmallestElement(struct node *);
struct node *deleteElement(struct node *, int);

int main(){
	int option, val;
	struct node *ptr;
	create_tree(tree);
	do {
		printf("\n ******MAIN MENU****** \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Preorder Traversal");
		printf("\n 3. Postorder Traversal");
		printf("\n 4. Search the smallest element");
		printf("\n 5. Delete an element");
		printf("\n 0. Exit");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\n Enter the value of the new node : ");
				scanf("%d", &val);
				tree = insertElement(tree, val);
				break;
			case 2:
				printf("\n The elements of the tree are : \n");
				preorderTraversal(tree);
				break;
			case 3:
				printf("\n The elements of the tree are : \n");
				postorderTraversal(tree);
				break;
			case 4:
				printf("\n The smallest element is : ");
				ptr = searchSmallestElement(tree);
				break;
			case 5:
				printf("\n Enter the element to be deleted : ");
				scanf("%d", &val);
				tree = deleteElement(tree, val);
				break;
			default :
				printf("Please input within the range number!\n");
				option = 0;
				break;
		}
	} while (option!=0);
	return 0;
}
struct node *temp;

void create_tree(struct node *tree){
	tree = NULL;
}

struct node *insertElement(struct node *tree, int val){
	if(tree == NULL){
		tree = (struct node *)malloc(sizeof(struct node));
		tree->data = val;
		tree->left = tree->right = NULL;
	} else {
		if(val < tree->data){
			tree->left = insertElement(tree->left, val);
		} else {
			tree->right = insertElement(tree->right, val);
		}
	}
}

void preorderTraversal(struct node *tree){
	if(tree != NULL){
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree){
	if(tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

struct node *searchSmallestElement(struct node *tree){
	if (tree != NULL){
		while(tree->left != NULL){
			tree = tree->left;
		}
		printf("%d", tree->data);
	} else
	printf("\n\n Tree is NULL!\n");
		
}

struct node *deleteElement(struct node *tree, int val){
	if(tree == NULL){
	printf("\nVal not found in the tree\n");
	}
	else if(val < tree->data){
		tree->left = deleteElement(tree->left, val);
	}
	else if(val > tree->data){
		tree->right = deleteElement(tree->right, val);
	}
	else if(tree->left && tree->right){
		temp = tree->left;
		tree->data = temp->data;
		tree->left = deleteElement(tree->left, temp->data);
	}
}
