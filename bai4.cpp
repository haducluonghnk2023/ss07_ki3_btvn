#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q){
    return q->front == -1;
}
int isFull(Queue* q){
    return q->rear == MAX - 1;
}
void enqueue(Queue* q, int value){
    if (isFull(q)) {
        printf("Hang doi da day.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->array[++(q->rear)] = value;
    printf("Them phan tu %d vao hang doi thanh cong.\n", value);
}
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong. Khong the tra ve phan tu dau tien.\n");
        return -1; 
    }
    return q->array[q->front];
}
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}
int main(){
    Queue queue;
    initQueue(&queue);
    int value, choice;

    do {
        printf("\n=========== MENU ==========\n");
        printf("0. Thoat.\n");
        printf("1. Them phan tu vao cuoi hang doi.\n");
        printf("2. Xem phan tu dau tien.\n");
        printf("3. In hang doi.\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                return 0;
            case 1:
                printf("Moi ban nhap gia tri: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = peek(&queue);
                if (value != -1) {
                    printf("Phan tu dau tien trong hang doi la: %d\n", value);
                }
                break;
            case 3:
                printQueue(&queue);
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (1);

    return 0;
}

