#include <iostream>
#include <stack>
#include <cctype> // For isdigit() function
#include <string>

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isdigit(c)) {
            // If the character is an operand, add it to the postfix expression
            postfix += c;
        } else if (isOperator(c)) {
            // Pop operators from the stack while they have higher or equal precedence
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            // Push the current operator to the stack
            operators.push(c);
        } else if (c == '(') {
            // Push '(' to the stack
            operators.push(c);
        } else if (c == ')') {
            // Pop until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // Remove '(' from the stack
            }
        }
    }

    // Pop all remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (size_t i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isdigit(c)) {
            // Convert character to integer and push it to the stack
            operands.push(c - '0');
        } else if (isOperator(c)) {
            // Pop two operands for the operation
            if (operands.size() < 2) {
                cout << "Error: Insufficient operands for operation." << endl;
                return -1;
            }
            int op2 = operands.top(); operands.pop();
            int op1 = operands.top(); operands.pop();

            // Perform the operation and push the result back
            switch (c) {
                case '+': operands.push(op1 + op2); break;
                case '-': operands.push(op1 - op2); break;
                case '*': operands.push(op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return -1;
                    }
                    operands.push(op1 / op2);
                    break;
            }
        }
    }

    // Final result should be at the top of the stack
    if (operands.size() == 1) {
        return operands.top();
    } else {
        cout << "Error: Invalid postfix expression." << endl;
        return -1;
    }
}

int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands only): ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    if (result != -1) {  // Check for error
        cout << "Result of postfix evaluation: " << result << endl;
    }

    return 0;
}
