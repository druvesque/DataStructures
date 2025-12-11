#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create_list() {
    int choice = 1;
    struct node *temp, *newnode;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL || tail == NULL)
            tail = head = temp = newnode;
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("\nEnter More? (Press 1 otherwise 0): ");
        scanf("%d", &choice);
    }
    temp->next = head;
    head->prev = temp;
    tail = temp; 
}

void insert_front() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at front: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL || tail == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
        head->prev = newnode;
    }

    else {
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_rear() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at rear: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (tail == NULL || head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
        head->prev = newnode;
    }
    else {
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        tail = newnode;
    }
}

void insert_pos(int count) {
    int pos, i = 1;
    struct node *newnode, *temp;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1)
        printf("\nInvalid Position");
    else if (pos > count)
        insert_rear();
    else if (pos == 1)
        insert_front();
    else {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data you want to insert at the specified position: ");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
    } 
}

void delete_front() {
    struct node* temp;
    if (head == NULL || tail == NULL) {
        printf("\nList is empty.");
        head = tail = NULL;
    }
    else if (tail->next == tail) {
        tail = head = NULL;
        free(tail);
    }
    else {
        printf("\nElement to be deleted: %d", head->data);
        temp = head;
        tail->next = temp->next;
        temp->next->prev = tail;
        free(temp);
        head = tail->next;
    }
}

void delete_rear() {
    struct node *temp;
    if (head == NULL || tail == NULL) {
        printf("\nList is empty.");
        head = tail = NULL;
    }
    else if (tail->next == tail) {
        tail = head = NULL;
        free(tail);
    }
    else {
        printf("\nElement to be deleted: %d", tail->data);
        temp = tail;
        tail = temp->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void delete_pos(int count) {
    int pos, i = 1;
    struct node *temp, *current;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1)
        printf("\nInvalid Position");
    else if (pos > count)
        delete_rear();
    else if (pos == 1)
        delete_front();
    else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        current = temp->next;
        temp->next = current->next;
        current->next->prev = temp;
        free(current); 
    }
}

int length_ll() {
    int count = 0;
    struct node *temp;
    if (head == NULL || tail == NULL)
        printf("\nList is empty!");
    else {
        temp = head;
        printf("\nThe Linked List is:\t");
    }
    do {
        printf("%d\t", temp->data);
        temp=temp->next;
        count++;
    } while (temp != head);
    
    printf("\n\nLength of the list: %d\n", count); 
    return count;
}

int main() {
    create_list();
    insert_front();
    insert_rear();
    int length = length_ll();
    insert_pos(length);
    delete_front();
    delete_rear();
    length = length_ll();
    delete_pos(length);
    length_ll();
    return 0;
}
