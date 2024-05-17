#include "kolejka.h"

#define MAX_QUEUE_SIZE 10

static int queue[MAX_QUEUE_SIZE];
static int head = -1;
static int tail = -1;

void enqueue(int value) {
    if (!isQueueFull()) {
        if (head == -1) head = 0;
        tail = (tail + 1) % MAX_QUEUE_SIZE;
        queue[tail] = value;
    }
}

int front() {
    if (!isQueueEmpty()) {
        return queue[head];
    }
    return -1; // lub inne odpowiednie zachowanie w przypadku pustej kolejki
}

void dequeue() {
    if (!isQueueEmpty()) {
        if (head == tail) {
            head = tail = -1; // kolejka jest teraz pusta
        } else {
            head = (head + 1) % MAX_QUEUE_SIZE;
        }
    }
}

bool isQueueEmpty() {
    return head == -1;
}

bool isQueueFull() {
    return (tail + 1) % MAX_QUEUE_SIZE == head;
}