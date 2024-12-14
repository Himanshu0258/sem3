#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the expression is well parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> s;  // Stack to store opening parentheses

    // Traverse through the expression using a standard for loop
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];  // Get current character

        // Push opening parentheses to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing parenthesis, check for match
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if stack is empty (no matching opening parenthesis)
            if (s.empty()) {
                return false;
            }
            // Check if the top of the stack matches the corresponding opening parenthesis
            char top = s.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                s.pop();  // Pop the matching opening parenthesis
            } else {
                return false;  // Mismatched parentheses
            }
        }
    }

    // If stack is empty, all parentheses were matched correctly
    return s.empty();
}

int main() {
    string expression;
    
    cout << "Enter an expression: ";
    cin >> expression;

    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is not well parenthesized." << endl;
    }

    return 0;
}
