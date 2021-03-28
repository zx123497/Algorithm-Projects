#include <stdio.h>
#include <stdlib.h>
//Insertion Sort
int arr[6]={31,41,59,26,41,58};

int main(){
	int i,j;
	int key;
	for(i=1;i<6;i++){
		key=arr[i];
		printf("key=%d\n",key);
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	for (i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
} 
