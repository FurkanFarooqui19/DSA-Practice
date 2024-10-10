#include<stdio.h>

#include<stdlib.h>

#define SIZE 10
 
void enQueue(int);
void deQueue();
void display();
 
int queue[SIZE], front = -1, rear = -1;
 
void main()
{
   int value, choice;
  
   while(1){
      printf("\n\n***** MENU *****\n");
      printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be inserted: ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}
void enQueue(int value){
   if(rear == SIZE-1)
      printf("\nQueue is Full! Insertion is not possible!");
   else{
      if(front == -1)
	 front = 0;
      rear++;
      queue[rear] = value;
      printf("\n Insertion success!!!");
   }
}
void deQueue(){
   if(front > rear || (front ==-1 && rear ==-1))
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted : %d", queue[front]);
      front++;
      if(front > rear)
	 front = rear = -1;
   }
}
void display(){
   if(front > rear || (front ==-1 && rear ==-1))
      printf("\nQueue is Empty!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	  printf("%d\t",queue[i]);
   }
}