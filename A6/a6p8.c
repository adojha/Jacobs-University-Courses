/*
CH-230-A
a6_p8.c
Aditya Ojha
ad.ojha@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

/* struct declaration */
struct list 
{
  int value;
  struct list *next;
};

void print_list(struct list *head)
{
    struct list *p;
    /*looping through the elements in list */
    for(p = head; p; p = p->next) 
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

struct list* beginning(struct list *head, int value)
{
    /* to add value to the beginning of the list */
    struct list * new_node;
 
    new_node = (struct list *)malloc(sizeof(struct list));
 
    if (new_node == NULL)
    {
        printf("Failed to insert element.");
    }
 
    (*new_node).value = value; 
    /* new value is connected with the list */ 
    (*new_node).next = head;
    return new_node;
}
struct list* end(struct list *head, int value)
{
    /* to add value to the end of the list */
    struct list *cursor , *newel;
    cursor = head;
    newel = (struct list *) malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf("Error allocating memory\n");
        return head;
    }
    newel->value = value;
    /* pointing the last element to null */
    newel->next = NULL;     

    if (head == NULL)
    return newel;

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    /* new value is connected with the list */
    cursor->next = newel;   
    return head;
}

struct list* deleteFirstNode(struct list *head) 
{ 
    if (head == NULL)
    return head;
    
    struct list *newlist; 
    /*start of the list pointing to the second element*/
    newlist = head->next; 
    head = NULL;

    return newlist; 
} 


void dispose_list(struct list *head) 
{
    /* deallocating memory stored in the list */
    struct list *nextelem;
    while (head != NULL) 
    {
        nextelem = head->next; 
        free(head);
        head = nextelem;
    } 
}

int main()
{
    char ch;
    int x, y;
    struct list* head = NULL;
    
    while(1)
    {
        scanf("%c", &ch);
        switch (ch)
        {
            /*performing the functions as requested*/
            case 'a':
                scanf("%d", &y);
                head = end(head, y);
            break;
            case 'b':
                scanf("%d", &x);
                head = beginning(head, x);
            break;
            case 'p':
                print_list(head);
            break;
            case 'r':
                head = deleteFirstNode(head);
            break;
            case 'q':
                dispose_list(head);
                exit(1); /* exiting the loop */
            break;
        }
    }
    return 0;
}
