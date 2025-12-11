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
    struct node *newnode, *temp;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

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
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL || tail == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
        head->prev = newnode;
    } 
    else {
        head->prev = newnode;
        newnode->next = head;
        head =  newnode;
    }
}

void insert_rear() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at rear: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (tail == NULL || head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
        tail->prev = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insert_pos(int count) {
    int pos, i = 1;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the position: ");
    scanf("%d", &pos);

    if (pos > count + 1 || pos < 1)
        printf("\nInvalid Position");
    else if(pos > count)
        insert_rear();
    else if (pos == 1)
        insert_front();
    else {
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        printf("\nEnter Data you want to insert at the specified position: ");
        scanf("%d", &newnode->data);
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delete_front() {
    struct node *temp;
    if (head == NULL || tail == NULL)
        printf("\nList is empty.");
    else if (head->next == NULL) {
        temp = head;
        head = tail = NULL;
        free(temp);
    }
    else {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void delete_rear() {
    struct node *temp;
    if (tail == NULL)
        printf("\nList is empty!");
    else if (tail->prev == NULL) {
        temp = tail;
        head = tail = NULL;
        free(temp);
    }
    else {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void delete_pos(int count) {
    int pos, i = 1;
    struct node *temp;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos > count || pos < 1)
        printf("\nInvalid Position");
    else if (pos == 1)
        delete_front();
    else if (pos == count)
        delete_rear();
    else {
        temp = head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("\nDeleted Element: %d", temp->data);
        free(temp);
    }
    
}

int length_ll() {
    int count = 0;
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty!");
        return 0;
    }
    else {
        temp = head;
        printf("\nThe Linked List is: ");
    }
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("\nLength: %d", count);
    return count;
}

int main() {
    create_list();
    insert_front();
    insert_rear();
    int total_elements = length_ll();
    // insert_pos(total_elements);
    // delete_front();
    // delete_rear();
    // total_elements = length_ll();
    // delete_pos(total_elements);
    return 0;
}

