#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
 
void insert(struct node **head_ref, int new_data)
 {
 	struct node *new_node = (struct node*)malloc(sizeof(struct node));
 	struct node *last= *head_ref;
 
 	new_node->data = new_data;
 	new_node->next = NULL;
 
 	if(*head_ref == NULL)
 	{
 		*head_ref = new_node;
 		return;
 	}
    while (last->next != NULL)
   		last = last->next;
 
    last->next = new_node;
    return;
 }
 
 struct node* deleteN(struct node *head, int n)
{
    if (head == NULL)
    return NULL;
    if (n == 1)
    {
        struct node *temp = head;
        head = temp->next;
        free(temp);
        return head;
    }
    head->next = deleteN(head->next, n-1);
    return head;
}

 
 
void display (struct node *node)
 {
 	while(node!=NULL)
 	 {
 	 	printf("%d  ", node-> data);
 	 	node= node->next;
 	 }
 	 printf("\n");
 }
 
int main(void) 
{   
	struct node *head = NULL;
	insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 5);
    insert(&head, 25);
    display(head);
    head = deleteN(head, count);
    display(head);
    
	return 0;
}
