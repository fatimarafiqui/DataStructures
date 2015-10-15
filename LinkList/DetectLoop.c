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
 
void createloop(struct node *node1, struct node *head1)
{  struct node *node2;
    while(node1!=NULL)
      {
        node2 = node1;
       	node1=node1->next;
      }
    node2->next=head1->next;
    printf("loop created");
}
 
void detectloop(struct node *node)
{
	struct node *ptr1,*ptr2;
	ptr1=node;
	ptr2=node;
	do
	{
		if(ptr1==NULL||ptr2==NULL)
	    {
	    	printf("No loop detected");
	      break;
	    }
		
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
		if(ptr1==ptr2)
	{	
	  printf("loop detected!");
    break;
	}
	}while((ptr1!=NULL)&&(ptr2!=NULL));
 
}
 
int main(void) 
{   
	struct node *head = NULL;
	insert(&head, 5);
  insert(&head, 10);
  insert(&head, 15);
  insert(&head, 20);
  createloop(head,head);
  detectloop(head);
	return 0;
	return 0;
}
