#include <cstdio>
#include <string>

struct node {
    std::string value;
    node *left;
    node *right;

    node(std::string value) { this->value = value; }
};

void find_leaves_depths(node *root, int curr_depth, int *depths_sum,
                        int *num_leaves) {

    if (!root->left && !root->right) {
        *depths_sum += curr_depth;
        *num_leaves += 1;
    }

    if (root->left) {
        find_leaves_depths(root->left, curr_depth + 1, depths_sum, num_leaves);
    }

    if (root->right) {
        find_leaves_depths(root->right, curr_depth + 1, depths_sum, num_leaves);
    }

    return;
}

float avg_depth(node *root) {

    int depths_sum = 0;
    int num_leaves = 0;

    find_leaves_depths(root, 0, &depths_sum, &num_leaves);

    return (float)depths_sum / (float)num_leaves;
}

int main(void) {
    node *a = new node("a");
    node *b = new node("b");
    node *c = new node("c");
    node *d = new node("d");
    node *e = new node("e");
    node *f = new node("f");

    a->left = b;
    a->right = c;
    b->left = d;
    d->left = e;
    c->right = f;

    float depth = avg_depth(f);

    printf("Average Depth: %f\n", depth);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;

    return 0;
}

