 Dequeue
Moderate
Score
160/160
Average time to solve is 40m
Problem statement
Send feedback

You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.

You don't need to double the capacity.

You need to implement the following functions -

1. constructor

You need to create the appropriate constructor. Size for the queue passed is 10.

2. insertFront -

This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.

3. insertRear -

This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.

4. deleteFront -

This function removes an element from the front of queue. Print -1 if queue is empty.

5. deleteRear -

This function removes an element from the end of queue. Print -1 if queue is empty.

6. getFront -

Returns the element which is at front of the queue. Return -1 if queue is empty.

7. getRear -

Returns the element which is at end of the queue. Return -1 if queue is empty.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 1 49 1 64 2 99 5 6 -1

Sample Output 1:
-1
64
99

Explanation:
The first choice code corresponds to getFront. Since the queue is empty, hence the output is -1. 
The following input adds 49 at the top and the resultant queue becomes: 49.
The following input adds 64 at the top and the resultant queue becomes: 64 -> 49
The following input add 99 at the end and the resultant queue becomes: 64 -> 49 -> 99
The following input corresponds to getFront. Hence the output is 64.
The following input corresponds to getRear. Hence the output is 99.

  class Deque {
private:
    int *arr;
    int front, rear, size;

public:
    Deque(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = 0;
    }

    void insertFront(int element) {
        if ((front == 0 && rear == size - 1) || front == rear + 1) {
            cout << "-1" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = element;
    }

    void insertRear(int element) {
        if ((front == 0 && rear == size - 1) || front == rear + 1) {
            cout << "-1" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "-1" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            if (front == size - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    void deleteRear() {
        if (front == -1) {
            cout << "-1" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    int getFront() {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (front == -1) {
            return -1;
        }
        return arr[rear];
    }
};
