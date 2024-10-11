#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;

void main()
{
   int choice, value;

   while(1){
      printf("\nSELECT ONE \n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be inserted:  ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nWrong. select the correct choice\n");
      }
   }
}
void enQueue(int value)
{
   if((front == rear + 1)||(front == 0 && rear == SIZE - 1))
      printf("\n QUEUE FULL \n");
   else{
      if(front == -1 && rear == -1)
	 {
	     front = 0;
	      rear = 0;
	 }
      else if(rear == SIZE-1 && front != 0)
	    rear = 0;
      else
	    rear++;	
      cQueue[rear] = value;
      printf("\n Value Inserted\n");
      
   }
}
void deQueue()
{
   if(front == -1 && rear == -1)
      printf("\n CIR QUEUE EMPTY \n");
   else{
	printf("\nDeleted element : %d\n",cQueue[front]);
	if(front==rear)
	{
		front = -1;
		rear =-1;
	}
	else{
		if(front== SIZE-1)
			front = 0;
		else
			front = front+1;
	}     
   }
}

void display()
{
   if(front == -1)
      printf("\n CIR QUEUE EMPTY\n");
   else{
      printf("Elements in the circular queue are: ");
 
    if(rear >= front)
    {
     
        for(int i = front; i <= rear; i++)
        {
            printf(" %d",cQueue[i]);
	    }
    }
 
    else
    {
         
        for(int i = front; i < SIZE; i++)
        {
             printf(" %d",cQueue[i]);
        }
 
        for(int i = 0; i <= rear; i++)
        {
             printf(" %d",cQueue[i]);
        }
   }
}
}