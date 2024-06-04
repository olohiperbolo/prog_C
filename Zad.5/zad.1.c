#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void add_first(node_t** head, int val) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        exit(1);
    }

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t** head) {
    if (*head == NULL) {
        exit(1);
    }

    int deleted = 0;
    node_t* next_node = NULL;

    next_node = (*head)->next;
    deleted = (*head)->val;
    free(*head);
    *head = next_node;

    printf("usunieto %d\n", deleted);
}

void remove_last(node_t** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node_t* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void remove_by_index(node_t** head, int n) {
    if (*head == NULL || n < 0) {
        return;
    }

    node_t* current = *head;
    node_t* temp = NULL;

    if (n == 0) {
        *head = current->next;
        free(current);
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (current->next == NULL) {
            return;
        }
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main() {
    node_t* head = NULL;
    add_first(&head, 3);
    add_first(&head, 1);
    add_first(&head, 2);

    print_list(head);
    pop(&head);
    print_list(head);

    remove_last(&head);
    print_list(head);

    remove_by_index(&head, 0);
    print_list(head);

    while (head != NULL) {
        node_t* tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}