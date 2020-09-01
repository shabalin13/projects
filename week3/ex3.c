#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_node(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete_node(struct Node **head, int data) {

    struct Node *temp = *head;

    if(*head == NULL)
        return;
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    else {
        delete_node(&((*head)->next), data);
    }
}

int main() {
    struct Node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 10);
    insert_node(&head, 3);
    insert_node(&head, 2);
    insert_node(&head, 0);
    insert_node(&head, 4);
    insert_node(&head, 234);
    print_list(head);

    delete_node(&head, 2);
    print_list(head);

    delete_node(&head, 234);
    print_list(head);

    delete_node(&head, 1);
    print_list(head);

    return 0;
}
