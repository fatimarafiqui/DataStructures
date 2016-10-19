#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* mergelist(struct node* a, struct node* b)
{
    struct node* result = NULL;
    if (a == NULL)
        return (b);
    if (b == NULL)
        return (a);

    if(a->data <= b->data)
    {
        result = a;
        result->next = mergelist(a->next,b);
    }
    else
    {
        result = b;
        result->next = mergelist(a,b->next); 
    }
    return(result);
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
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    insertNode(&head1,2);
    insertNode(&head1,4);
    insertNode(&head1,6);
    insertNode(&head1,8);
    insertNode(&head1,10);
    printlist(head1);
    printf("\n");
    insertNode(&head2,1);
    insertNode(&head2,3);
    insertNode(&head2,5);
    insertNode(&head2,9);
    insertNode(&head2,12);
    printlist(head2);
    struct node* result = mergelist(head1,head2);
    printf("\n");
    printlist(result);
    return 0;
}
