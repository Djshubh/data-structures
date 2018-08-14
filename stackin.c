/*
 * C Program to Implement GRAHAM ALGO for CONVEX HULL
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int xc;
    int yc;
}point;

struct node
{
    point pt;
    struct node *link;
}*top = NULL;

#define MAX 500

// function prototypes
void push();
void pop();
void empty();
void stack_full();
int st_count();
void destroy();
void print_top();

void main()
{
    int choice;

    while (1)
    {
        printf("1. push an element \n");
        printf("2. pop an element \n");
        printf("3. check if stack is empty \n");
        printf("4. check if stack is full \n");
        printf("5. count/display elements present in stack \n");
        printf("6. empty and destroy stack \n");
        printf("7. Print top of the stack \n");
        printf("8. exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            point newpt= {3,4};
            push(newpt);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            empty();
            break;
        case 4:
            stack_full();
            break;
        case 5:{
            int cnt = st_count();printf("%d",cnt);
            break;
        }
        case 6:
            destroy();
            break;
        case 7:
            print_top();
            break;
        case 8:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}

// to insert elements in stack
void push(point val)
{
    int count;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    count = st_count();
    if (count <= MAX - 1)
    {
        //printf("\nEnter value which you want to push into the stack :\n");
        //scanf("%d",&val);
        temp->pt = val;
        temp->link = top;
        top = temp;
    }
    else
        printf("WARNING: STACK FULL\n");
}

// to delete elements from stack
void pop()
{
    struct node *temp;
    if (top == NULL)
        printf("**Stack is empty**\n");
    else
    {
        temp = top;
        printf("Value popped out is %d \n",temp->pt.xc,temp->pt.yc);
        top = top->link;
        free(temp);
    }
}

// to check if stack is empty
void empty()
{
    if (top == NULL)
        printf("STACK IS EMPTY\n");
    else
        printf("elements are present, stack is not empty \n");
}

// to check if stack is full
void stack_full()
{
    int count;

    count = st_count();
    if (count == MAX)
    {
        printf("stack  full\n");
    }
    else
        printf("stack not full \n");
}

// to count the number of elements

int st_count()
{
    int count = 0;
    struct node *temp;
    temp = top;
    while (temp!= NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

// to empty and destroy the stack
void destroy()
{
    struct node *temp;
    temp = top;
    while (temp!= NULL)
    {
        pop();
        temp = temp->link;
    }
    printf("stack destroyed\n");
}

// to print top element of stack
void print_top()
{
    if (top == NULL)
        printf("\n**Top is not available for an EMPTY stack**\n");
    else
        printf("\nTop of the stack is %d %d\n",top->pt.xc,top->pt.yc);
}
