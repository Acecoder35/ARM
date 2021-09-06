// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue){
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue){
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item){
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	//printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue){
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Print elements of stack
void printQueue(struct Queue* queue) {
  printf("Queue: ");
  for (int i = queue->front; i < queue->front + queue->size; i++) {
    printf("%d %p ", queue->array[i], &(queue->array[i]));
  }
  printf("\n");
}

// Driver program to test above functions./
int main(){
	struct Queue* queue = createQueue(10);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	
	printQueue(queue);

	//printf("%d dequeued from queue\n\n",dequeue(queue));
	dequeue(queue);
	printQueue(queue);

	return 0;
}
