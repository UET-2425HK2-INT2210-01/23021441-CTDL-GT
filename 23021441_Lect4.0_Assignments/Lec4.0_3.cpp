#include <iostream>
using namespace std;

struct Stack {
    char data[1000];
    int top;

    Stack() { top = -1; }

    void push(char c) { data[++top] = c; }
    char pop() { return (top >= 0) ? data[top--] : '\0'; }
    char peek() { return (top >= 0) ? data[top] : '\0'; }
    bool isEmpty() { return top == -1; }
};


bool isValid(string s) {
    Stack stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else {
            char top = stack.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string inputs[100];
    int count = 0;

    while (cin >> inputs[count]) {
        count++;
        if (cin.peek() == '\n') break;
    }

    for (int i = 0; i < count; i++) {
        cout << (isValid(inputs[i]) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}
