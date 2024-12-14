#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int front, rear, maxOrders;
    int *orders;

public:
    // Constructor to initialize the circular queue
    PizzaParlor(int size) {
        maxOrders = size;
        orders = new int[maxOrders];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~PizzaParlor() {
        delete[] orders;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % maxOrders);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to add an order to the queue
    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Cannot place order. The queue is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }
        
        rear = (rear + 1) % maxOrders;
        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully." << endl;
    }

    // Function to serve an order from the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }

        cout << "Order " << orders[front] << " is served." << endl;

        if (front == rear) {  // Only one order in the queue
            front = rear = -1;  // Reset queue after serving
        } else {
            front = (front + 1) % maxOrders;
        }
    }

    // Function to display current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in queue: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxOrders;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter maximum number of orders the pizza parlor can handle: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);

    int choice, orderID;
    do {
        cout << "\n--- Pizza Parlor Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID to place: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
