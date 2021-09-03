// implement using an array pointer

#include <iostream>

using namespace std;

class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *elements;
};

Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue;
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->elements = new int[queue->capacity];
    return queue;
}

bool isEmpty(Queue *queue)
{
    return queue->size == 0 ? true : false;
}

int isFull(Queue *queue)
{
    return queue->size == queue->capacity ? true : false;
}

bool enqueue(Queue *queue, int item)
{
    if (isFull(queue))
        return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
    queue->size = queue->size + 1;
    return true;
}

int dequeue(Queue *queue){
    if(isEmpty(queue)){
        return INT32_MIN;
    }
    int item = queue->elements[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size = queue->size+1;
    return item;
}

int main(){
    Queue *queue = createQueue(5);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    enqueue(queue,50);
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;
    cout<<dequeue(queue)<<endl;

}