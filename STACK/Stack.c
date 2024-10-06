#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void push();
void pop();
void display();

int stack[SIZE],top = -1;

void main(){
    int choice;
    while(1){
        printf("\n\n**********MENU**********\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit ");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("\nPlease Enter a valid choice.");
            }
        }
    }
}

void push(){
    int val;
    if(top==SIZE-1){
        printf("\nOVERFLOW(Stack is Full)");
    }
    else{
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&val);
        stack[++top] = val;
        printf("\nInsertion Success!!!");
    }
}
 
void pop(){
    if(top == -1){
        printf("\nUNDERFLOW(Stack is Empty)");
    }
    else{
        printf("\nDeleted: %d",stack[top--]);
    }
}

void display(){
       if(top == -1){
        printf("\nUNDERFLOW(Stack is Empty)");
    }
    else{
        printf("Stack Elements are:\n");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    } 
}