#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Deque;
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;  
}
int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->rear == dq->front - 1);
}
void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Cac phan tu trong hang doi: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq->data[dq->rear]);
}
void addFront(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front == 0) ? MAX - 1 : dq->front - 1;
    }
    dq->data[dq->front] = data;
    printf("Da them phan tu %d vao dau hang doi.\n", data);
    printDeque(dq);
}
void addRear(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear == MAX - 1) ? 0 : dq->rear + 1;
    }
    dq->data[dq->rear] = data;
    printf("Da them phan tu %d vao cuoi hang doi.\n", data);
    printDeque(dq);
}
void removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        return;
    }

    int removedData = dq->data[dq->front];
    if (dq->front == dq->rear) { 
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front == MAX - 1) ? 0 : dq->front + 1;
    }
    printf("Da lay phan tu %d ra khoi dau hang doi.\n", removedData);
    printDeque(dq);
}
void removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        return;
    }

    int removedData = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear == 0) ? MAX - 1 : dq->rear - 1;
    }
    printf("Da lay phan tu %d ra khoi cuoi hang doi.\n", removedData);
    printDeque(dq);
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, data;

    do {
        printf("\n=========== MENU ==========\n");
        printf("0. Thoat.\n");
        printf("1. Them phan tu vao dau hang doi (addFront).\n");
        printf("2. Them phan tu vao cuoi hang doi (addRear).\n");
        printf("3. Lay phan tu ra khoi dau hang doi (removeFront).\n");
        printf("4. Lay phan tu ra khoi cuoi hang doi (removeRear).\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                return 0;
            case 1:
                printf("Nhap du lieu: ");
                scanf("%d", &data);
                addFront(&dq, data);
                break;
            case 2:
                printf("Nhap du lieu: ");
                scanf("%d", &data);
                addRear(&dq, data);
                break;
            case 3:
                removeFront(&dq);
                break;
            case 4:
                removeRear(&dq);
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (1);

    return 0;
}

