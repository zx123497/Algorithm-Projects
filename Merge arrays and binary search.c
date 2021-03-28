#include <stdio.h>
#include <stdlib.h>


int arr1[100];
int arr2[100];
int merge[100];
int main(){
	int i=0;
	int ptr1=0,ptr2=0;
	int size1=0,size2=0;
	
	int target=0;
	scanf("%d %d",&size1,&size2);
	int mergeSize=size1+size2;
	for (i=0;i<size1;i++){
		scanf("%d ",&arr1[i]);
	}
	arr1[size1]=100000;
	for (i=0;i<size2;i++){
		scanf("%d ",&arr2[i]);
	}
	arr2[size2]=100000;
	scanf("%d",&target);
	for (i=0;i<mergeSize;i++){
		if(arr1[ptr1]>arr2[ptr2]){
			merge[i]=arr2[ptr2];
			ptr2++;
		}
		else if(arr1[ptr1]<arr2[ptr2]){
			merge[i]=arr1[ptr1];
			ptr1++;
		}
		else if(arr1[ptr1]==arr2[ptr2]){
			merge[i]=arr1[ptr1];
			ptr1++;
		}
	}
	for (i=0;i<mergeSize;i++){
		if(i==mergeSize-1){
			printf("%d\n",merge[i]);
		}
		else{
			printf("%d ",merge[i]);
		}
		
	}
	
	ptr1=0;
	ptr2=mergeSize-1;
	int mid=0;
	int finish=0;
	while(finish!=1){
		mid=(ptr1+ptr2)/2;
		if(merge[mid]==target){
			printf("%d\n",mid);
			finish=1;
		}
		else if(merge[mid]>target){
			ptr2=mid;
		}
		else if(merge[mid]<target){
			ptr1=mid;
		}
		
		if(ptr1==ptr2||(ptr1+1)==ptr2){
			printf("not found\n");
			finish=1;
		}
	}
}

