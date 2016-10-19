#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void recursivereverse(struct node** head_ref)
{
    struct node* first;
    struct node* res;

    if (*head_ref== NULL)
        return;
    first = *head_ref;
    res = first->next;
    
    if (res == NULL)
        return;
    
    recursivereverse(&res);
    first->next->next = first;
    first->next = NULL;

    *head_ref = res;

}

void insertNode(struct node** head_ref, int new_data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = new_data;
    newnode->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = newnode;
        return;
    }

    struct node* last = *head_ref;
    while(last->next != NULL)
        last = last->next;
    
    last->next = newnode;
    return;
}

void printlist(struct node* node)
{
    while(node!=NULL)
    {
        printf("->%d", node->data);
        node = node->next;
    }
    return;
}

int main()
{
    struct node *head = NULL;
    insertNode(&head,2);
    insertNode(&head,4);
    insertNode(&head,6);
    insertNode(&head,8);
    insertNode(&head,10);
    printlist(head);

    recursivereverse(&head);
    printf("\n");
    printlist(head);
    return 0;
}
