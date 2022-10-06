#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int TOP = -1;

void PUSH(int);
int POP();
void display();

void main()
{
    int choice, data;
    while(choice!=4)
    {
        printf("\n1 for push\n");
        printf("2 for pop\n");
        printf("3 for Display\n");
        printf("4 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d", &data);
            PUSH(data);
            break;

            case 2:
            data = POP();
            printf("\nPoped item is %d\n", data);
            break;

            case 3:
            display();
            break;

            case 4:
            exit(1);

            default:
            printf("\nWrong choice");

        }
    }
}

void PUSH(int item)
{
    if(TOP == SIZE -1)
    {
        printf("\nStack is overflow");
        return;
    }
    TOP = TOP +1;
    stack[TOP]=item;
}

int POP()
{
    int y;
    if(TOP==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        y = stack[TOP];
        TOP = TOP -1;
        return(y);
    }

}

void display()
{
    if(TOP == -1)
    {
        printf("\nStack is empty");
        return;
    }
        printf("\nStack elements are: ");
        for(int i=TOP;i>=0;i--)
    {
        printf("%d ", stack[i]);
    }
}