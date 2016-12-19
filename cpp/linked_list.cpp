#include <cstdio>

class linked_list_node
{
    public:
    linked_list_node * next = NULL;
    int value;

    linked_list_node(int val)
    {
        this->value = val;
    }

};

void list_print(linked_list_node * head)
{
    linked_list_node *curr = head;

    while (curr != NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
}

// Return the new head
linked_list_node * list_invert(linked_list_node * head)
{
    // We need to keep track of the prev, and the next element for each element
    // of the list in each iteration.
    linked_list_node * prev;
    linked_list_node * curr;
    linked_list_node * next;

    // Check if the list size is zero or one. In this case, there's nothing to
    // invert.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // For the first element, prev is NULL
    prev = NULL;
    curr = head;

    // Traverse the list inverting direction
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // End has been found. The new head is the previous element.
    return prev;
}

// Return -1 in case of error and 0 if found and delete.
int list_delete(linked_list_node *elm)
{
    // Delete the element elm from the it leaves in We will actually not delete
    // the element itself. We will make the same as the next.

    // A problem arises if the last element is given. There's no value to copy.
    // And if I delete the element, there will be a dangling pointer problem.
    // To solve that there should be an element that will be always null in the
    // end, and this element will never be deleted. To do that I will need to
    // have a special class for the list that will abstract this peculiarity.

    // Check if either the element is invalid or it is the last element. In
    // this case, there's no way to remove it.
    if(elm == NULL || elm->next == NULL) {
        return -1;
    }

    linked_list_node * next = elm->next;
    elm->value = next->value;
    elm->next = next->next;

    return 0;
}

void test_invertion(linked_list_node *head)
{
    printf("Elements before invertion:\n");
    list_print(head);

    linked_list_node *new_head = list_invert(head);

    printf("Elements after invertion\n");
    list_print(new_head);
}

linked_list_node * find_kth_to_last(linked_list_node * head, int k)
{
    // Traverse the list storing a pointer to the kth node to last
    linked_list_node * kth_to_last = NULL;
    linked_list_node * curr = head;

    // Check k value
    if (k < 1) {
        return kth_to_last;
    }

    // Shift the curr pointer k - 1 elements to the right
    while(k > 1 && curr != NULL) {
        curr = curr->next;
        k--;
    }

    // Shift both pointers to the right one by one in each iteration
    while (curr != NULL) {
        if (kth_to_last == NULL) {
            kth_to_last = head;
        } else {
            kth_to_last = kth_to_last->next;
        }
        curr = curr->next;
    }

    return kth_to_last;
}

void test_find_kth_to_last(linked_list_node *head, int k)
{
    linked_list_node * kth_to_last_elm = find_kth_to_last(head, k);

    printf("List:\n");
    list_print(head);

    // Check if element has been found successfully or not
    if(!kth_to_last_elm) {
        printf("%dth element does not exist\n", k);
        return;
    }

    // Element has been found
    printf("%dth to last element: %d\n", k, kth_to_last_elm->value);
    return;
}

int main(void)
{
    linked_list_node *a = new linked_list_node(1);
    linked_list_node *b = new linked_list_node(2);
    linked_list_node *c = new linked_list_node(3);

    a->next = b;
    b->next = c;

    //test_invertion(a);
    test_find_kth_to_last(a, 0);

    return 0;
}

