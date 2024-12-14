#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;  // Stores binary digit (0 or 1)
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

// Class for binary numbers using doubly linked list
class BinaryNumber {
public:
    Node* head;
    Node* tail;

    // Constructor to initialize the doubly linked list
    BinaryNumber() {
        head = NULL;
        tail = NULL;
    }

    // Function to append a binary digit to the list
    void append(int digit) {
        Node* newNode = new Node(digit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to compute the 1's complement
    void onesComplement() {
        Node* temp = head;
        while (temp) {
            temp->data = (temp->data == 0) ? 1 : 0;
            temp = temp->next;
        }
    }

    // Function to compute the 2's complement
    void twosComplement() {
        onesComplement();  // First compute 1's complement
        addBinary(1);       // Then add 1 to the result
    }

    // Function to add a binary number
    void addBinary(int num) {
        Node* temp = tail;
        int carry = num;

        while (temp) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        if (carry == 1) {
            // If there's a carry left, append it to the front
            Node* newNode = new Node(1);
            newNode->next = head;
            newNode->prev = NULL;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        }
    }

    // Function to add two binary numbers
    static BinaryNumber add(BinaryNumber& bin1, BinaryNumber& bin2) {
        BinaryNumber result;
        Node* temp1 = bin1.tail;
        Node* temp2 = bin2.tail;
        int carry = 0;

        while (temp1 || temp2) {
            int bit1 = (temp1) ? temp1->data : 0;
            int bit2 = (temp2) ? temp2->data : 0;

            int sum = bit1 + bit2 + carry;
            result.append(sum % 2);
            carry = sum / 2;

            if (temp1) temp1 = temp1->prev;
            if (temp2) temp2 = temp2->prev;
        }

        if (carry == 1) {
            result.append(1);
        }

        return result;
    }
};

// Main function to test the BinaryNumber class
int main() {
    BinaryNumber bin1, bin2;

    // Input binary numbers
    cout << "Enter first binary number: ";
    string num1;
    cin >> num1;
    // Replace range-based for loop with traditional for loop
    for (int i = 0; i < num1.length(); ++i) {
        bin1.append(num1[i] - '0');
    }

    cout << "Enter second binary number: ";
    string num2;
    cin >> num2;
    // Replace range-based for loop with traditional for loop
    for (int i = 0; i < num2.length(); ++i) {
        bin2.append(num2[i] - '0');
    }

    // Display the entered binary numbers
    cout << "First binary number: ";
    bin1.display();

    cout << "Second binary number: ";
    bin2.display();

    // Compute and display 1's complement of the first binary number
    cout << "1's complement of first binary number: ";
    bin1.onesComplement();
    bin1.display();

    // Reset the first binary number and compute 2's complement
    cout << "2's complement of first binary number: ";
    for (int i = 0; i < num1.length(); ++i) {
        bin1.append(num1[i] - '0');
    }
    bin1.twosComplement();
    bin1.display();

    // Add the two binary numbers
    BinaryNumber sum = BinaryNumber::add(bin1, bin2);
    cout << "Sum of the two binary numbers: ";
    sum.display();

    return 0;
}
