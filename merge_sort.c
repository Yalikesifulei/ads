#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cpy=0, cmp=0;

void merge(int Array[], int left, int m, int right){ 
    int i,j,k; 
    int n_l = m-left+1; 
    int n_r = right-m; 
  
    int L[n_l], R[n_r]; 
    
    for (i=0, k=left; k<m+1; k++, i++){
    	L[i]=Array[k];
	}
	
	for (j=0; k<=right; k++, j++){
    	R[j]=Array[k];
	}
	
	i=0; j=m+1;
	
	for (k=left; k<=right; k++) {
		cmp++;
		if (i<=m && j<=right) {
			if (L[i] < R[j]) {
				Array[k]=L[i]; i++; cpy++;
			}
			else {
				Array[k]=R[j]; j++; cpy++;
			}
		}
		else if (i<=m) {
			Array[k]=L[i]; i++; cpy++;
		}
		else {
			Array[k]=R[j]; j++; cpy++;
		}
	}
    
} 

void mergeSort(int Array[], int left, int right) 
{ 
    if (left<right) 
    { 
        int m = left+(right-left)/2; 
        
        mergeSort(Array, left, m); 
        mergeSort(Array, m+1, right); 
  
        merge(Array, left, m, right); 
    } 
}

void gen_best(int best[], int n){
	int el;
	for (el=0; el<n; el++){
		best[el]=el;
	}
}

void gen_worst(int worst[], int n){
	int c,el;
	for (c=n-1,el=0; c>=0; c--, el++){
		worst[c]=el;
	}
}

void gen_random(int rnd[], int n){
	srand(time(NULL));
	int el;
	for (el=0; el<n; el++){
		rnd[el]=rand()%10000;
	}
}

int main() { 
    int *arr;
	int n,ch,i;
	
	do {
		printf("Enter size of array (1000 / 10000 / 100000)\n"); 
		scanf("%i", &n);
	} 	
	while (n!=1000 && n!=10000 && n!=100000);
	
	arr = (int*)malloc(sizeof(int)*n);
	
	do {
		printf("Enter 1 for best, 0 for worst and 2 for random:\n");
		scanf("%i", &ch);
	}
	while (ch!=0 && ch!=1 && ch!=2);
	
	switch (ch) {
		case 1: gen_best(arr,n); mergeSort(arr, 0, n-1); break;
		case 2: for(i=1; i<=1000; i++){ gen_random(arr,n); mergeSort(arr, 0, n-1);}; cmp/=1000; cpy/=1000; break;
		case 0: gen_worst(arr,n); mergeSort(arr, 0, n-1); break;
	}
	
	printf("comparisons: %i, swaps: %i", cmp, cpy);
	
	free(arr);
    return 0; 
} 
