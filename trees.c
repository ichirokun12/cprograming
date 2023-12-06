#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, m;
    struct node *root = NULL;

    printf("Enter the number of nodes for the tree: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter the element for node %d: ", i);
        scanf("%d", &m);
        struct node *p = createnode(m);

        if (root == NULL) {
            root = p;
        } else {
            // Insert the node into the binary tree (you can implement your own logic here)
            // For simplicity, let's insert all nodes to the left of the root
            p->left = root;
            root = p;
        }
    }

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
