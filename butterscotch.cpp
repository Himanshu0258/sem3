#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;  // Student ID
    Node* next;

    Node(int id) : data(id), next(NULL) {}
};

// Class to represent a set using linked list
class Set {
public:
    Node* head;

    Set() : head(NULL) {}

    // Function to add an element to the set
    void add(int studentID) {
        // Check if the element already exists in the set
        if (!contains(studentID)) {
            Node* newNode = new Node(studentID);
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to display the set
    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to find intersection of two sets
    Set intersection(const Set& other) const {
        Set result;
        Node* temp1 = head;
        while (temp1) {
            Node* temp2 = other.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    result.add(temp1->data);  // Add common student to result
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return result;
    }

    // Function to find symmetric difference (students who like either, but not both)
    Set symmetricDifference(const Set& other) const {
        Set result;
        Node* temp1 = head;

        // Add students who are in the first set but not in the second set
        while (temp1) {
            bool found = false;
            Node* temp2 = other.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    found = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (!found) {
                result.add(temp1->data);
            }
            temp1 = temp1->next;
        }

        // Add students who are in the second set but not in the first set
        Node* temp2 = other.head;
        while (temp2) {
            bool found = false;
            Node* temp1 = head;
            while (temp1) {
                if (temp2->data == temp1->data) {
                    found = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (!found) {
                result.add(temp2->data);
            }
            temp2 = temp2->next;
        }

        return result;
    }

    // Function to check if an element exists in the set
    bool contains(int studentID) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == studentID) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to count the number of students in the set
    int count() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to find the total number of students (union of both sets)
    int totalStudents(const Set& other) const {
        int total = count();
        Node* temp2 = other.head;
        while (temp2) {
            if (!contains(temp2->data)) {
                total++;
            }
            temp2 = temp2->next;
        }
        return total;
    }
};

int main() {
    Set setA, setB;

    // Add students who like Vanilla ice-cream (Set A)
    setA.add(1);
    setA.add(2);
    setA.add(3);
    setA.add(4);

    // Add students who like Butterscotch ice-cream (Set B)
    setB.add(3);
    setB.add(4);
    setB.add(5);
    setB.add(6);

    // Display the sets
    cout << "Set A (Vanilla lovers): ";
    setA.display();
    cout << "Set B (Butterscotch lovers): ";
    setB.display();

    // a) Students who like both Vanilla and Butterscotch (Intersection of A and B)
    Set common = setA.intersection(setB);
    cout << "Students who like both Vanilla and Butterscotch: ";
    common.display();

    // b) Students who like either Vanilla or Butterscotch but not both (Symmetric Difference)
    Set diff = setA.symmetricDifference(setB);
    cout << "Students who like either Vanilla or Butterscotch but not both: ";
    diff.display();

    // c) Number of students who like neither Vanilla nor Butterscotch
    int totalStudents = setA.totalStudents(setB);
    int studentsInAorB = setA.count() + setB.count() - common.count();  // Students in A or B or both
    int neither = totalStudents - studentsInAorB;

    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neither << endl;

    return 0;
}
