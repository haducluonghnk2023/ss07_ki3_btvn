#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
	int array[MAX];
	int front;
	int rear;
} Queue;
// khoi tao hang doi
void initQueue(Queue* q){
	q->front = -1;
	q->rear = -1;
}
// kiem tra rong
int isEmpty(Queue* q){
	return q->front == -1;
}
//kiem tra day
int isFull(Queue* q){
	return q->rear == MAX - 1;
}
//them phan tu vao cuoi hang doi
void enqueue(Queue* q,int value){
	if(isFull(q)){
		printf("hang doi da day.\n");
		return;
	}
	if(isEmpty(q)){
		q->front = 0;
	}
	q->array[++(q->rear)] = value;
}
// loai bo
void dequeue(Queue* q){
	if(isEmpty(q)){	
		printf("hang doi rong.\n");
		return;
	}
	printf("phan tu %d da bi xoa.\n",q->array[q->front]);
	q->front++;
	if(q->front > q->rear){
		initQueue(q);
	}
}
// hien thi
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong.\n");
        return;
    }
    printf("hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}
int main(){
	Queue queue;
	initQueue(&queue);
	int value,n;
	do{
		printf("\n===========MENU==========\n");
		printf("0. Thoat.\n");
		printf("1. Them phan tu vao cuoi hang doi.\n");
		printf("2. In queue.\n");
		printf("3. Xoa.\n");
		int choice;
		printf("nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				exit(0);
			case 1:
				printf("moi ban nhap gia tri:");
				scanf("%d",&value);
				enqueue(&queue,value);
				break;
			case 2:
				printQueue(&queue);
				break;
			case 3:
				dequeue(&queue);
				break;
			default:
				printf("vui long nhap lai:");
		}

	}while(1 == 1);
	return 0;
}

