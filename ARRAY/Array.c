#include<stdio.h>

int main(){
  int arr[100],i,pos,val,n,choice;
  printf("Enter the numbers of element in the array:\n");
  scanf("%d",&n);
  printf("Enter the Elemnts of the Array: \n");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("Choose an Operation:\n");
  printf("1.Insert an Element:\n");
  printf("2.Delete an Element:\n");
  printf("Enter your Choice(1 OR 2):");
  scanf("%d",&choice);
  if(choice==1){
    printf("Enter the Position where you want to insert an Element: ");
    scanf("%d",&pos);
    if(pos<1 || pos>n+1){
      printf("Invalid Position!!\n");
      return 1;
    }
    printf("Enter the value to insert:");
    scanf("%d",&val);
    for(i=n;i>=pos;i--){
      arr[i]=arr[i-1];
    }
    arr[pos-1]=val;
    n++;
    printf("Array after Insertion: \n");
    for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
  }
  else if(choice==2){
    printf("Enter the position of the Element to delete: ");
    scanf("%d",&pos);
    if(pos<1 || pos>n){
      printf("Invalid Position");
      return 1;
    }
    for(i=pos-1;i<n-1;i++){
      arr[i]=arr[i+1];
    }
    n--;
    printf("Array after Deletion: \n");
     for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
      printf("\n");
  }
  else{
    printf("Invalid Choice!!\n");
  }
  return 0;
}