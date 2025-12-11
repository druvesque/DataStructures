#include<stdio.h>
#include<stdlib.h>

struct node {
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
        newnode->next = NULL;

        if (head == NULL || tail == NULL)
            tail=head=temp=newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nEnter More? (Press 1 otherwise 0): ");
        scanf("%d", &choice);
    }
    temp->next = head;
    tail = temp;
}

void insert_front() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at front: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL; 

    if (tail == NULL || head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        head = newnode;
    }
}

void insert_rear() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert at rear: ");
    scanf("%d", &newnode->data);

    if (tail == NULL || head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void delete_front() {
    struct node *temp;
    if (tail == NULL || head == NULL) {
        printf("\nList is empty!");
        head = tail = NULL;
    }
    else if (tail->next == tail) {
        tail = head = NULL;
        free(tail);
    }
    else {
        printf("%d", tail->next->data);
        temp = tail->next;
        tail->next = temp->next;
        free(temp);
        head = tail->next;
    }
}

void delete_rear() {
    struct node *temp, *current;
    if (head == NULL || tail == NULL) {
        printf("\nList is empty!");
        head = tail = NULL;
    }
    else if (tail->next == tail) {
        tail = head = NULL;
        free(tail);
    }
    else {
        temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        current = tail;
        temp->next = tail->next;
        tail = temp;
        free(current);
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
        printf("\nEnter data you want to insert at specified position: ");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
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
        free(current);
    }
}

int length_ll() {
    int count = 0;
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty!");
    else {
        temp = head;
        printf("\nNow the linked list is: ");
    }
    do {
        printf("%d\t", temp->data);
        temp=temp->next;
        count++;
    } while (temp != head);

    printf("\nLength of the list: %d\n", count);
    return count;
}

int main() {
    create_list();
    insert_front();
    insert_rear();
    int total_elements = length_ll();
    insert_pos(total_elements);
    length_ll();
    delete_front();
    length_ll();
    delete_rear();
    total_elements = length_ll();
    delete_pos(total_elements);
    length_ll();
    return 0;
}
