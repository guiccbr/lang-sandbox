#include <cstdio>
#include <string>
#include <cassert>

template <class T>
struct stack_elm {
    stack_elm<T> * next;
    T value;

    stack_elm(T val) {
        this->value = val;
    }
};

template <class T>
struct stack {

    stack_elm<T> *last;

    bool is_empty() { return last == NULL; }

    void push(T val) {
        stack_elm<T> *new_elm = new stack_elm<T>(val);
        new_elm->next = last;
        last = new_elm;
    }

    T pop() {
        if (this->is_empty()) {
            throw "Popping from an empty stack\n";
        }

        T value = this->last->value;
        stack_elm<T> *new_last = last->next;
        delete last;
        last = new_last;
        return value;
    }

    T get_last() {

        if (this->is_empty()) {
            throw "Getting last element from an empty stack\n";
        }

        return this->last->value;
    }
};

struct node {
    std::string value;
    node *left;
    node *right;

    node(std::string value) { this->value = value; }
    node(int value) { this->value = std::to_string(value); }
    void print() { printf("%s\n", value.c_str()); }
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

int test_avg_depth() {

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

void dfs_stack_print_left_first(node *root, stack<node *> *s) {

    if (!root) {
        return;
    }

    node *curr = root;

    while (true) {
        if (curr == NULL) {
            if (!s->is_empty()) {
                curr = s->pop();

                // In-order
                curr->print();
                curr = curr->right;

                // Pre-order
                // curr = curr->right;
                
                // Post-order
                // curr->print();
                // curr = curr->left;

            } else {
                break;
            }
        } else {
            s->push(curr);

            // In-order
            curr = curr->left;
            
            // Pre-order
            // curr->print();
            // curr = curr->left;
            
            // Post-order
            // curr = curr->right;
        }
    }
}

void dfs_print_left_first(node * root) {

    if(!root) {
        return;
    }

    dfs_print_left_first(root->left);
    root->print();
    dfs_print_left_first(root->right);
}

node * create_bst(int * array, int i, int j) {

    if(j <= i) {
        return NULL;
    }

    int middle_elm = (i + j)/2;
    node *root = new node(array[middle_elm]);
    root->left = create_bst(array, i, middle_elm);
    root->right = create_bst(array, middle_elm + 1, j);

    return root;

}

void delete_tree(node *root) {

    if (!root) {
        return;
    }

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int test_create_bst() {

    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13};
    int size = sizeof(input) / sizeof(input[0]);

    node *bst_root = create_bst(input, 0, size);
    dfs_print_left_first(bst_root);
    delete_tree(bst_root);

    return 0;
}

void test_print_tree(){

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

    dfs_print_left_first(a);

}

void test_stack() {

    stack<int> s;
    assert(s.is_empty());
    
    s.push(1);
    assert(s.get_last() == 1);
    printf("last: %d\n", s.get_last());

    s.push(2);
    assert(s.get_last() == 2);
    printf("last: %d\n", s.get_last());

    s.push(3);
    assert(s.get_last() == 3);
    printf("last: %d\n", s.get_last());

    assert(s.pop() == 3);
    printf("last: %d\n", s.get_last());

    assert(s.pop() == 2);
    printf("last: %d\n", s.get_last());

    assert(s.pop() == 1);
    assert(s.is_empty());

}

void dfs_stack() {

}

void test_dfs_stack() {

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

    stack<node *> s;

    dfs_stack_print_left_first(a, &s);
}

int main(void) {

    // test_avg_depth();
    // test_create_bst();
    //test_print_tree();
    //test_stack();
    test_dfs_stack();

    return 0;
}

