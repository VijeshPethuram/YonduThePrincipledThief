#include <stdio.h>
#include <cstdlib>
#include <time.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *llist;

int lptime(int YonduKey,int LockKey,int N,llist Keys);
void insert(int x,llist head);
void remove(llist head);
int retrieve(int pos,llist head);
void display(llist head);
int find_minimum(int a[], int n);
long factorial(int n);
int* randarray(int N);
void makeempty(llist head);

int main() {
	llist head;
	head=(llist)malloc(sizeof(struct node));
	head->next=NULL;
	if(head==NULL) {
		printf("Linked list Creation Failed!\n");
		exit(0);
	}
		

	int YonduKey,LockKey,N,*Keys,i,LockpickingTime,*lpt;
	printf("\nEnter Lock Key of the Bank: ");
	scanf("%d",&LockKey);

	printf("\nEnter the Key which Yondu Has: ");
	scanf("%d",&YonduKey);

	printf("\nEnter no. of other keys Yondu Has: ");
	scanf("%d",&N);

	printf("\nEnter values of other keys: \n");
	Keys=(int*)calloc(N,sizeof(int));
	for(i=0; i<N; i++) {
		scanf("%d",&Keys[i]);
		insert(Keys[i],head);
	}
	printf("\nOther keys are: ");
	display(head);

	lpt=(int*)calloc(factorial(N)*3,sizeof(int));
	for(i=0; i<factorial(N)*3; i++) { //*3 for more accuracy
		lpt[i]=lptime(YonduKey,LockKey,N,head);
	}
	int minindex=find_minimum(lpt,3*factorial(N));
	LockpickingTime=lpt[minindex];
	if(LockpickingTime<N+1)
		printf("\n\nMinimum Time taken to pick the Lock is %d seconds",LockpickingTime);
	else {
		printf("\n\nYondu cannot find the Lock Key");
	}
	makeempty(head);

	return 0;
}

//Lock Operations-----
int lptime(int YonduKey,int LockKey,int N,llist Keys) {

	int ltime=0,i;
	int *array=randarray(N);
	int j=0;
	i=*(array+j);
	while(i<N) {
		if((YonduKey!=LockKey)) {
			YonduKey=YonduKey * retrieve(i,Keys)%100000;
			ltime++;
		} 
		else {
			return ltime;
		}
		j++;
		i=*(array+j);
	}
	return 9999;
}


int find_minimum(int a[], int n) { //Finding minimum-----
	int c, index = 0;
	for (c = 1; c < n; c++) {
		int min=a[index];
		if (a[c] < min)
			index = c;
	}
	return index;
}

long factorial(int n) { //Finding factorial-----
	if (n == 0)
		return 1;
	else
		return(n * factorial(n-1));
}

int* randarray(int N) { //Returns the shuffled array when an array is given as input-----

	static int j=0;
	time_t t;
	time(&t);
	srand(t+j);
	static int array[100];
	for (int i = 0; i < N; i++) {
		array[i] = i;
	}


	for (int i = 0; i < N; i++) {
		int temp = array[i];
		int randomIndex = rand() % N;

		array[i]           = array[randomIndex];
		array[randomIndex] = temp;
	}
	j++;


	return array;
}

//llist Operations -----
void insert(int x,llist head) {//Insert at first-----
	llist temp;
	temp=(llist)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->next=head->next;
	head->next=temp;

}

void remove(llist head) { //Delete at first-----
	llist k=(llist)malloc(sizeof(struct node));
	if(head->next!=NULL) {
		k=head->next;
		int temp=k->data;
		head->next=head->next->next;
		free(k);
	}

}

int retrieve(int pos,llist head) {//retrieve an element at given position-----
	llist t=head;
	for(int i=0; i<=pos; i++) {
		if(t->next!=NULL)
			t=t->next;
	}
	return t->data;
}

void display(llist head) {//Displays the linked list-----
	llist t=head->next;
	while(t!=NULL) {
		printf(" %d",t->data);
		t=t->next;
	}
}

void makeempty(llist head)//Makes the linked list empty-----
{
	while(head->next!=NULL)
	{
		remove(head);
	}
}