#include <iostream>
using namespace std;

class JobQueue {
private:
    int front, rear, size;
    int *queueArray;

public:
    // Constructor to initialize the job queue with a given size
    JobQueue(int s) {
        size = s;
        queueArray = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~JobQueue() {
        delete[] queueArray;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to add a job to the queue
    void addJob(int jobID) {
        if (isFull()) {
            cout << "Job queue is full. Cannot add job." << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0; // Initialize front for the first element
        }
        
        rear++;
        queueArray[rear] = jobID;
        cout << "Job " << jobID << " added to the queue." << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (isEmpty()) {
            cout << "Job queue is empty. No job to delete." << endl;
            return;
        }

        cout << "Job " << queueArray[front] << " is being processed and removed from the queue." << endl;
        
        front++;
        
        // Reset queue when all jobs are processed
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Function to display the current jobs in the queue
    void displayJobs() {
        if (isEmpty()) {
            cout << "Job queue is empty." << endl;
            return;
        }

        cout << "Current jobs in queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, jobID;
    cout << "Enter the size of the job queue: ";
    cin >> size;

    JobQueue jobQueue(size);

    do {
        cout << "\n--- Job Queue Menu ---\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job ID to add: ";
                cin >> jobID;
                jobQueue.addJob(jobID);
                break;
            case 2:
                jobQueue.deleteJob();
                break;
            case 3:
                jobQueue.displayJobs();
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
