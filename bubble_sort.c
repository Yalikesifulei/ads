#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long cpy=0, cmp=0;

void bubble_sort(int Array[], int n) {
	int temp, f=1, k=n-2;
	int i;
	
	while (f) {
		f=0;
		for (i=0; i<=k; i++){
			cmp++;
			if (Array[i]>Array[i+1]) {
				temp=Array[i];
				Array[i]=Array[i+1];
				Array[i+1]=temp;
				f=1;
				cpy++;
			}
		}
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
		case 1: gen_best(arr,n); bubble_sort(arr, n); break;
		case 2: for(i=1; i<=1000; i++){ gen_random(arr,n); bubble_sort(arr, n);}; cmp/=1000; cpy/=1000; break;
		case 0: gen_worst(arr,n); bubble_sort(arr, n); break;
	}
	
	printf("comparisons: %llu, swaps: %llu", cmp, cpy);
	
	free(arr);
    return 0; 
} 
