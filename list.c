#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct points_list {
	int x;
	int y;
	struct points_list * next;
} p_list;

p_list * create_node(int, int);
p_list * max(p_list *);
p_list * add(p_list *, p_list *);
void del(p_list *);
p_list * shift(p_list *, int);
void print(p_list *);
void clear(p_list *);

int main(){
	int x,y,n,i,k,c;
	srand(time(NULL));
	printf("enter size of list: ");
	scanf("%i", &n);
	p_list *head = NULL, *d;
	
	for (i=0; i<n; i++){
		x=rand()%21-10; y=rand()%21-10;
		d = create_node(x,y);
		head = add(head, d);
		//printf("%i %i\n", x,y);
	}
	print(head);
	
	do {
		printf("\n\nenter 1 for list shifting, 2 for deleting tail: ");
		scanf("%i", &c);
		switch(c){
			case 1: {
				printf("enter k: "); scanf("%i", &k);
				puts("\nshifted list:");
				head = shift(head, k);
				print(head);
				break;
			}
			case 2: {
				del(head);
				print(head);
				break;
			}
		}
	} while (c!=1 && c!=2);
	
	clear(head);
	
	return 0;
}

p_list * create_node(int x, int y){
	p_list *result = (p_list *)malloc(sizeof(p_list));
	if (result){
		result->x=x;
		result->y=y;
		result->next=result;
	}
	return result;
}

p_list * add(p_list *head, p_list *new){
	p_list *t = head;
	if (!(head)) {
		head = new;
		return head;
	}	
	else {
		do {
			if (( (abs(t->x)+abs(t->y)) <= (abs(new->x)+abs(new->y)) ) && ( (abs((t->next)->x)+abs((t->next)->y)) >= (abs(new->x)+abs(new->y))) ) {
				new->next = t->next;
				t->next = new;
				return head;
			}
			else t=t->next;
		} while(t->next!=head);
		
		new->next = head;
		t->next = new;
		if ((abs(head->x)+abs(head->y)) >= (abs(new->x)+abs(new->y))) 
			return new;
		else return head;
	}
}

void del(p_list *list){
	p_list *el = list, *temp = list, *head = list;
	while ((el->next)->next!=head) el=el->next;
	temp = el->next;
	temp->next = NULL;
	el->next = head;
	free(temp);
	
}

p_list * shift(p_list *head, int k){
	int i;
	p_list * new_head = head;
	for (i=0; i<k; i++){
		new_head = new_head->next;
	}
	return new_head;
}

void print(p_list *list){
	p_list *t = list;
	do {
		printf("%i, %i", t->x, t->y);
		t = t->next;
		if (t!=list) printf(" -> ");
	} while (t!=list);
}

void clear(p_list *list){
	p_list *temp = list->next, *x, *head = list;
	if (head->next==head) {
		free(head);
		exit(0);
	}
	else if (temp->next==head) {
		free(temp);
		free(head);
		exit(0);
	}
	else do {
		x = temp;
		temp = temp->next;
		free(x);
	} while(temp->next != head);
	free(head);
}
