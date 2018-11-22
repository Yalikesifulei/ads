#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long cmp=0, cpy=0;

void counting_sort(int A[], int B[], int n, int k){
	int i,j;
	int C[k];
	for (i=0; i<k; i++){
		C[i]=0;
	}
	for (j=0; j<n; j++){
		C[A[j]]++;
	}
	for (i=1; i<k; i++){
		C[i]+=C[i-1];
	}
	for (j=n-1; j>=0; j--){
		B[C[A[j]]-1]=A[j]; cpy++;
		C[A[j]]--;
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

const long N=1000;

int main(){
	int *arr, *sorted;
	int n,ch,i;
	
	do {
		printf("Enter size of array (1000 / 10000 / 100000)\n"); 
		scanf("%i", &n);
	} 	
	while (n!=1000 && n!=10000 && n!=100000);
	
	arr = (int*)malloc(sizeof(int)*n);
	sorted = (int*)malloc(sizeof(int)*n);
	
	do {
		printf("Enter 1 for best, 0 for worst and 2 for random:\n");
		scanf("%i", &ch);
	}
	while (ch!=0 && ch!=1 && ch!=2);
	
	switch (ch) {
		case 1: gen_best(arr,n); counting_sort(arr, sorted, n, n); break;
		case 2: for(i=1; i<=1000; i++){ gen_random(arr,n); counting_sort(arr, sorted, n, 10000);}; cmp/=1000; cpy/=1000; break;
		case 0: gen_worst(arr,n); counting_sort(arr, sorted, n, n); break;
	}

	printf("comparisons: %i, swaps: %i\n", cmp, cpy);
	
	free(arr); free(sorted);	
	return 0;
}
