#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void add_first(node_t**head, int val){
    node_t * new_node = (node_t*)malloc(sizeof(node_t ));

    new_node->val = val;
    new_node->next =* head;
    *head=new_node;
}
void pop(node_t**head){
    node_t *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
}
void remove_last(node_t**head){
    if ((*head)->next == NULL) {
        *head = NULL;
        return;
    }

    node_t *current = *head;
    node_t *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
}
void remove_by_index(node_t **head, int index){
    if(index==0){
        node_t * temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    node_t *current = *head;
    node_t *previous = NULL;
    int i = 0;

    while(current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }
    previous->next = current->next;
    free(current);
}

void print_list(node_t*head){
    while(head != NULL){
        printf("%d -> ", head->val);
        head = head -> next;
    }
    printf("NULL\n");
}
void remove_by_value(node_t **head, int value){
    node_t *current = *head;
    node_t *previous = NULL;

    while(current != NULL && current->val != value){
        previous = current;
        current = current->next;
    }
    if(previous == NULL){
        *head = (*head)->next;
        free(current);
    }
    else{
        previous->next=current->next;
        free(current);
    }
}
void add_by_value(node_t **head, int index, int value){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!\n");
        return;
    }
    new_node->val = value;

    if (index == 0) { // Jeśli chcemy dodać na początku listy
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t *current = *head;
    int i = 0;

    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    current->next = new_node;
}

int main() {

    node_t* head = NULL;
    add_first(&head, 3);
    add_first(&head, 5);
    add_first(&head, 7);
    add_first(&head, 6);
    add_first(&head, 11);
    add_first(&head, 8);
    add_first(&head, 10);
    remove_last(&head);
    remove_by_value(&head, 7);
    add_by_value(&head, 2, 15);

    remove_by_index(&head, 3);
    pop(&head);
    printf("Lista: ");
    print_list(head);
    return 0;
}
