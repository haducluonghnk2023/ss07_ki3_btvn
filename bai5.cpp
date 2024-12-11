#include <stdio.h>
#include <stdlib.h>

#define MAX 1

typedef struct {
    int priority;
    int data;
} Element;
typedef struct {
    Element elements[MAX];
    int size;
} PriorityQueue;
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}
int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}
void enqueue(PriorityQueue *pq, int priority, int data) {
    if (isFull(pq)) {
        printf("Hang doi da day. Khong the them phan tu.\n");
        return;
    }

    Element newElement;
    newElement.priority = priority;
    newElement.data = data;

    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority < priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }

    pq->elements[i + 1] = newElement;
    pq->size++;
    printf("Da them phan tu (Priority: %d, Data: %d) vao hang doi.\n", priority, data);
}

void dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        return;
    }

    Element lastElement = pq->elements[pq->size - 1];
    printf("Da lay phan tu (Priority: %d, Data: %d) ra khoi hang doi.\n", lastElement.priority, lastElement.data);
    pq->size--;
}
void printQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Cac phan tu trong hang doi:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("(Priority: %d, Data: %d) ", pq->elements[i].priority, pq->elements[i].data);
    }
    printf("\n");
}

// Chuong trình chính
int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int choice, priority, data;

    do {
        printf("\n=========== MENU ==========\n");
        printf("0. Thoat.\n");
        printf("1. Them phan tu vao hang doi (enqueue).\n");
        printf("2. Lay phan tu co uu tien cao nhat (dequeue).\n");
        printf("3. Hien thi hang doi.\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                return 0;
            case 1:
                printf("Nhap uu tien: ");
                scanf("%d", &priority);
                printf("Nhap du lieu: ");
                scanf("%d", &data);
                enqueue(&pq, priority, data);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                printQueue(&pq);
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (1);

    return 0;
}

