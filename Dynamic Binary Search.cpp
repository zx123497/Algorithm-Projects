#include <cstdio>
 #include <cstdlib>
 #include <math.h>
#include <vector>
using namespace std;

vector <int> vec;
int arr[15]={0,0,0,9,10,11,12,2,3,4,5,6,7,8,100};


void printElements();
int checkPower(int);
void searchElement(int);
void searchElement(int);
int nextRow(int);
int binarySearch(int,int,int);
void insertElement(int);
int *merge(int[],int[]);
int main(){
	int operation=0;
	int input=0;
	vec.assign(arr,arr+15);
	while(true)
	{
		printf("Dynamic Binary Search Operation:\n(1) Insert\n(2) Search\n(3) Delete\n(4) Print\n(5) Exit\nInput an operation...>");
		scanf("%d",&operation);
		if(operation==1){
			printf("\n***Insert***\n");
			printf("input a number...>");
			scanf("%d",&input); 
			insertElement(input);
		}
		else if(operation==2){
			printf("\n***Search***\n");
			printf("input a number...>");
			scanf("%d",&input); 
			searchElement(input);
		}
		else if(operation==3){
			printf("\n***Delete***\n");
			printf("input a number...>");
			scanf("%d",&input); 
			
		}
		else if(operation==4){		// print function finished
			printf("\n***Print***\n"); 
			printElements();
		}
		else if(operation==5){
			printf("\n***Exit***\n");
			break;
		}
		else{
			printf("please insert number 1~5!\n");
		}
		operation=0;
		input=0;
		system("pause");
	}
}

void printElements(){				//print function implement
	int i;
	for(i=0;i<vec.size();i++){
		if(checkPower(i+1)==1){ 	//if index+1 == power of 2,then \n
			printf("\n");
		}
		printf("%d ",vec[i]);
	}	
	printf("\n");
}

int checkPower(int n){				// whether n == power of 2 
	if(n>0&&(n&n-1)==0){
		return 1;
	}
	else{
		return 0;
	}
}

void searchElement(int n){ 			// searching implement
	int row_count=0;
	int row_start=0;
	int found=-1;
	int row_end=0;
	while(row_start<vec.size()){
		row_end=nextRow(row_start)-1;
		found=binarySearch(n,row_start,row_end);
		if(found!=-1){
			break;
		}
		else{
			row_start=nextRow(row_start);
			row_count++;
		}
		
	}
	if(found!=-1){
		printf("%d: [%d][%d]\n",n,row_count,found-row_start);
	}else{
		printf("Not found!\n");
	}
	return;
} 

int nextRow(int n){
	n=(n+1)*2-1;
	return n;
}

int binarySearch(int n,int start,int end){
	while(start<=end){
		int mid=(start+end)/2; 
		if(n==vec[start]){
			return start;
		}
		else if(n==vec[end]){
			return end;
		}
		else if(n==vec[mid]){
			return mid;
		}
		else if(n>vec[mid]){
			start=mid+1;
		}
		else if(n<vec[mid]){
			end=mid-1;
		}
	}
	return -1;
}

void insertElement(int n){
	
	int row_start=0;
	int *final=(int*)malloc((2*100)*sizeof(int));
	final[0]=n;
	while(vec[row_start]!=0&&row_start<vec.size()){
		int pointer=row_start;
		int row_end=nextRow(row_start)-1;
		int *temp=(int*)malloc((2*100)*sizeof(int));
		int *temp2=(int*)malloc((2*100)*sizeof(int));
		int i=0;
		int a=0;
		temp=final;
		for(pointer=row_start;pointer<=row_end;pointer++){
			temp2[i++]=vec[pointer];
			vec[pointer]=0;
		}
		final=merge(temp,temp2);
		row_start=nextRow(row_start);
	}
	
	if(row_start==vec.size()){
		final[vec.size()]=NULL;
		int index=0;
		while(final[index]!=NULL){
			vec.push_back(final[index]);
			//printf("push_back: %d\n",final[index]);
			index++;
		}	
	}
	else{
		int ind=0;
		int input=row_start;
		int end=nextRow(row_start)-1;
		while(input<=end){
			vec[input++]=final[ind++];
		}
	}	
}

int *merge(int *arr1,int *arr2){
	int *c=(int*)malloc((2*100)*sizeof(int));
	int res_pointer=0;
	int index1=0;
	int index2=0;
	while(arr1[index1]!=NULL&&arr2[index2]!=NULL){
		if(arr1[index1]==arr2[index2]){
			c[res_pointer++]=arr1[index1++];
			c[res_pointer++]=arr2[index2++];
		}
		else if(arr1[index1]>arr2[index2]){
			c[res_pointer++]=arr2[index2++];
		}
		else if(arr1[index1]<arr2[index2]){
			c[res_pointer++]=arr1[index1++];
		}
	}
	while(arr1[index1]!=NULL){
		c[res_pointer++]=arr1[index1++];
	}
	while(arr2[index2]!=NULL){
		c[res_pointer++]=arr2[index2++];
	}
	return c;
}


