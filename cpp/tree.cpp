#include<cstdio>

struct Node {
    Node * left = NULL;
    Node * right = NULL;
};

void traverse(Node *root, int *num_leaves, int *sum_of_depths)
{
    if (!root) {
        return;
    }

    if (root->left) {
        traverse(root->left, num_leaves, sum_of_depths);
    }

    if (root->right) {
        traverse(root->right, num_leaves, sum_of_depths);
    }

    if (!root->left && !root->right) {
        *num_leaves++;
    }

    *sum_of_depths++;

    return;
}

float avg_depth(Node *root)
{
    int num_leaves = 0;
    int sum_of_depths = 0;

    traverse(root, &num_leaves, &sum_of_depths);

    if (num_leaves != 0) {
        return sum_of_depths / num_leaves;
    } else {
        return 0;
    }
}

int main(void) {

    Node * root = new Node();

    printf("avg_depth: %.2f\n", avg_depth(root));

    delete root;
}

