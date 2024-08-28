#include<bits/stdc++.h>

using namespace std;

void push(vector<int> &stack , int a) {
    stack.push_back(a);
}
int pop(vector<int> &stack) {
    int top =  stack[stack.size() - 1];
    stack.pop_back();
    return top;
}
int peep(vector<char> &stack) {
    return stack[stack.size() - 1];
}

void traverse(vector<char> &stack) {
    if (stack.size() == 1) {
        cout << stack[0] << " ";
        return;
    }
    int top = pop(stack);
    cout << top << " ";
    traverse(stack);
}


int main() {
    int n;
    cin >> n;
    vector<char> stack;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        push(stack, x);
    }

    traverse(stack);


}