// Infix = <operand> <operator> <operand>
// Prefix = <operator> <operand> <operand>
// Postfix = <operand> <operand> <operator>

/*
Precendence of Operators:
    1. (), [], {}   
    2. ^              (R-L)
    3. *, /           (L-R)
    4. +, -           (L-R)
*/


/*
Infix to Postfix conversion:  (using stack LIFO)
    1. Print operands as they arrive
    2. If stack is empty or contains a left parentheses on top, push the incoming operator onto the stack
    3. If incoming symbol is '(' push it onto stack
    4. If incoming symbol is ')' pop the stack & print the operators until left prenthese is found
    5. If upcoming symbol has higher precendence then the top of the stack, push it on the stack.
    6. If upcoming symbol has lower precendence then the top of the stack, pop & print the top. Then test the incoming operator against the new top of the stack
    7. If incoming operator has equal precedence with the top of the stack, use associativity rule.
    8. At the end of the expression, pop & print all operators of stack.

    -> associativity L to R then pop & print the top of the stack & then push the incoming operator
    -> R to L then push the incoming operator
*/

// Infix expression: A+B/C
// Postfix expression: ABC/+

// Infix expression: A-B/C*D+E
// Postfix expression: ABC/D*-E+

// Infix expression: K+L-M*N+(O^P)*W/U/V*T+Q
// Postfix expression: KL+MN*-OP^W*U/V/T*+Q+          // we don't print parentheses

// Infix expression: A-B+(M^N)*(O+P)-Q/R^S*T+Z
// Postfix expression: AB-MN^OP+*+QRS^/T*-Z+




// Infix to Prefix using Stack: 
// Reverse the expression
// Then follow the same above rules to convert the expression
// Only the rule 3<->4 of parentheses replaces and rule 2 will apply on ')' right parentheses
// Plus in case same precedence the rule of associativity also reverses.
// Then again reverse the expression


// Infix Expression: K+L-M*N+(O^P)*W/U/V*T+Q      // reverse the orignal infix expression
// Reverse: Q+T*V/U/W*)P^O(+N*M-L+K       
// Conversion: QTVWPO^*//*NM*LK+-++              // reverse the converted expression to get prefix expression
// Prefix Expression: ++-+KL*MN*//*^OPWVTQ




// Evalution of Prefix Expression:
// We will start fron end of the expression (right to left)
// If Operand comes we will push it into the stack
// If a operator comes you will pop out two operands out of the stack and store it into o1 and o2
// Now you will evalutate o1 <operator> 02
// the answer will be pushed into stack
// repeat the process
// When you have reached end of expression and if you have only one operand at the end then that is your answer


/*
Scan Prefix expresion from right to left

for each char in prefix expr:   (length-1 to 0)
    do
        if operand is there, push it onto stack
        else if operator is there, pop 2 elements
            op1 = top element
            op2 = next to top element
            result = op1 operator op2
            push resilt onto stack
    return stack[top]
*/



// Evalution of Postfix Expression:
// We will evaluate from left to right
// very similar process 
// push operands in stack
// when you find a operator pop out to operands and evaluate the answer     (op2 will be top element and op1 will be nnext to top element)
// push the answer into the stack and repeat the process

/*
Scan Post expresion from left to right

    for each char in prefix expr:   (0 to length-1)
    do
        if operand is there, push it onto stack
        else if operator is there, pop 2 elements
            op2 = top element
            op1 = next to top element
            result = op1 operator op2
            push resilt onto stack
    return stack[top]
*/



// Postfix to Infix
// scan from left to right
// if operand comes push it into the stack
// if operator comes pop two operand from the stack and place that two operand between the operator
// result = B operator A        // apply parentheses on the result
// and push the result into the stack
// repeat the process



// Prefix to Infix
// scan from right to left
// if operand comes push it into the stack
// if operator comes pop two operand from the stack and place that two operand between the operator
// result = A operator B       // apply parentheses on the result
// and push the result into the stack
// repeat the process






#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int top;
    int max_size;
    char* arr;

public:
    Stack(int size) {
        top = -1;
        max_size = size;
        arr = new char[max_size];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top < max_size - 1) {
            arr[++top] = c;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    char pop() {
        if (top != -1) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
    }

    char peek() {
        return (top != -1) ? arr[top] : '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}


// convert to postfix
string convertToPostfix(string infix) {
    Stack operatorStack(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];

        if (isOperand(currentChar)) {
            postfix += currentChar;
        } else if (currentChar == '(') {
            operatorStack.push(currentChar);
        } else if (currentChar == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            while (!operatorStack.isEmpty() && getPrecedence(currentChar) <= getPrecedence(operatorStack.peek())) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

// convert to prefix
string convertToPrefix(string infix) {
    string reversedInfix(infix.rbegin(), infix.rend());

    for (int i = 0; i < reversedInfix.length(); i++) {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }

    string postfix = convertToPostfix(reversedInfix);
    string prefix = string(postfix.rbegin(), postfix.rend());

    return prefix;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = convertToPostfix(infixExpression);

    cout << "The corresponding postfix expression is: " << postfixExpression << endl;

    return 0;
}
