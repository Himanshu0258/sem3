#include <iostream>
using namespace std;

class Deque {
private:
    int front, rear, size;
    int *dequeArray;

public:
    // Constructor to initialize deque with given size
    Deque(int s) {
        size = s;
        dequeArray = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~Deque() {
        delete[] dequeArray;
    }

    // Function to check if deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    // Function to check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to add an element at the front
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front." << endl;
            return;
        }

        if (isEmpty()) { // First element to be inserted
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1; // Wrap around
        } else {
            front--;
        }

        dequeArray[front] = element;
        cout << "Inserted " << element << " at front." << endl;
    }

    // Function to add an element at the rear
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear." << endl;
            return;
        }

        if (isEmpty()) { // First element to be inserted
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }

        dequeArray[rear] = element;
        cout << "Inserted " << element << " at rear." << endl;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }

        cout << "Deleted " << dequeArray[front] << " from front." << endl;

        if (front == rear) { // Only one element in deque
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }

        cout << "Deleted " << dequeArray[rear] << " from rear." << endl;

        if (front == rear) { // Only one element in deque
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1; // Wrap around
        } else {
            rear--;
        }
    }

    // Function to display the contents of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque contents: ";
        int i = front;
        while (true) {
            cout << dequeArray[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, element;
    cout << "Enter the size of the deque: ";
    cin >> size;

    Deque deque(size);

    do {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at front: ";
                cin >> element;
                deque.insertFront(element);
                break;
            case 2:
                cout << "Enter element to insert at rear: ";
                cin >> element;
                deque.insertRear(element);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
