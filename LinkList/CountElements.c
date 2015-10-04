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
 
void display (struct node *node)
 {
 	while(node!=NULL)
 	 {
 	 	printf("%d  ", node-> data);
 	 	node= node->next;
 	 }
 	 printf("\n");
 }
int count(struct node *head_ref)
{
	struct node *start = head_ref;
	int flag=0;
	while(start!=NULL)
	{
		start= start->next;
		flag++;
	}
	return flag;
}

int main(void)
{
	int count1,count2;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
    insert(&head1, 5);
    insert(&head1, 10);
    insert(&head1, 15);
    insert(&head2, 2);
    insert(&head2, 4);
    insert(&head2, 8);
    insert(&head2, 8);
    display(head1);
    display(head2);
    count1= count(head1);
    count2= count(head2);
    printf("Number of elements in list 1 is %d\n", count1);
    printf("Number of elements in list 2 is %d\n", count2);

	return 0;
}
