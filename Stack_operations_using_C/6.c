#include <stdio.h>
//to make the implementation of stack
int top=-1;
int arr[10];
int arrsize=10;
void stack_push(){
    if(top==arrsize-1){
        printf("Overflow Condition\n");
    }
    else{
        int num;
        printf("Enter a number : ");
        scanf("%d", &num);
        top++;
        arr[top]=num;
    }
}
void stack_pop(){
    if(top==-1){
        printf("Under Flow condition\n");
    }
    else{
        printf("The element to be removed is : %d\n", arr[top]);
        arr[top]=0;
        top--;
    }

}
void stack_display(){
    int asize=arrsize;
    while(asize>=0){
        printf("%d\n", arr[asize]);
        asize--;
    }
}
int main(){
    while(1==1){
        printf("Press 1 to Push\n");
        printf("Press 2 to Pop\n");
        printf("Press 3 to Display Stack\n");
        printf("Press 4 to Exit\n");
        int choice;
        printf("--------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==1){
            stack_push();
        }
        else if(choice==2){
            stack_pop();
        }
        else if(choice==3){
            stack_display();
        }
        else if(choice==4){
            break;
        }
    }
    return 0;
}