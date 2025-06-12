#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

//Declared function prototypes....

struct node *createNode(int data);

void insertBegin(struct node **head, int data);

void insertEnd(struct node **head, int data);

void printListItems(struct node *head);

void insertPos(struct node **head, int data, int pos);

void DeleteFirst(struct node **head);

void DeleteLast(struct node **head);

//....

int main(void)
{
    struct node *head = NULL;

    struct node *ptr = createNode(65);

    struct node *ptr1 = createNode(66);

    struct node *ptr2 = createNode(45);

    insertEnd(&head, ptr1->data);

    insertBegin(&head, ptr->data);

    int position = 2;

    insertPos(&head, ptr2->data, position);

    printListItems(head);

    DeleteFirst(&head);

    printListItems(head);

    DeleteLast(&head);

    printListItems(head);

    return 0;
}

//Function to create new node

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode-> data = data;
    newNode-> next = NULL;

    return newNode;
}

void insertBegin(struct node **head, int data)
{
    struct node *beginNode = createNode(data);

    //if list is empty

    if (*head == NULL)
    {
        beginNode->next = *head;
        *head = beginNode;
    }

    else
    {
        beginNode->next = *head;
        *head = beginNode;
    }
}

//function to add node at certain position

void insertPos(struct node **head, int data, int pos)
{
    struct node *addPos = createNode(data);

    struct node *temp = *head;

    if (pos < 1)
    {
        printf("Insert position must be greater or equal to one");
    }

    else if (*head == NULL)
    {
        printf("List is empty, node will be added at the beginning of the list");
        addPos->next = *head;
        *head = addPos;
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        addPos->next = temp->next;
        temp->next = addPos;

    }

}

//function to add node at the end of list

void insertEnd(struct node **head, int data)
{
    struct node *addEnd = createNode(data);

    // if list is empty

    if (*head == NULL)
    {
        addEnd->next = *head;
        *head = addEnd;
    }
    else
    {
        struct node *temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = addEnd;
    }

}

//function to delete node at the begining

void DeleteFirst(struct node **head)
{

    if (*head == NULL)
    {
        printf("List is already empty\n");
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head= NULL;
    }
    else
    {
        struct node *temp = *head;

        *head = (*head)->next;
        free(temp);
    }
}

//Function to delete last node of a list

void DeleteLast(struct node **head)
{
    if(*head == NULL)
    {
        printf("List is already empty\n");
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct node *temp = *head;
        struct node *temp2 = (*head)->next;

        while (temp2->next != NULL)
        {
            temp = temp2;
            temp2 = temp2->next;
        }
        temp->next = NULL;
        free(temp2);
    }
}

//function to print list items

void printListItems(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
