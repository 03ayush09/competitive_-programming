#include <bits/stdc++.h>

// Define a node structure for a singly linked list
struct Linked_List_node {
    int ele;
    Linked_List_node* nxt;
    Linked_List_node(int ele_to_assigned) : ele(ele_to_assigned), nxt(nullptr) {}
};

using namespace std;
typedef Linked_List_node LLN;

// Queue implementation using linked list
class adt_queue {
public:
    LLN* frnt; // Pointer to the front of the queue
    LLN* bck;  // Pointer to the back of the queue
    int sz;    // Size of the queue

    adt_queue() : frnt(NULL), bck(NULL), sz(0) {}

    // Check if the queue is empty
    bool is_empty() {
        return sz == 0;
    }

    // Add an element to the back of the queue
    void push(int elemt) {
        LLN* new_apnode = new LLN(elemt);
        if (is_empty()) {
            frnt = new_apnode;
            bck = new_apnode;
            bck->nxt = NULL;
        } else {
            bck->nxt = new_apnode;
            bck = new_apnode;
        }
        sz++;
    }

    // Remove and return an element from the front of the queue
    int pop() {
        if (is_empty()) {
            return -1;
        }
        int elemt = frnt->ele;
        if (sz == 1) {
            delete frnt;
            frnt = nullptr;
            bck = nullptr;
        } else {
            LLN* tmp = frnt;
            frnt = frnt->nxt;
            bck->nxt = nullptr;
            delete tmp;
        }
        sz--;
        return elemt;
    }
};

// Circular deque implementation based on the queue
class Adtcircular_deque : private adt_queue {
public:
    Adtcircular_deque() {}

    // Inherit methods from adt_queue
    using adt_queue::is_empty;
    using adt_queue::push;
    using adt_queue::pop;

    // Add an element to the back of the circular deque
    void push(int elemt) {
        adt_queue::push(elemt);
        bck->nxt = frnt; // Make it circular
    }

    // Remove and return an element from the front of the circular deque
    int pop() {
        int ap03 = adt_queue::pop();
        bck->nxt = frnt; // Make it circular again
        return ap03;
    }

    // Add an element to the front of the circular deque
    void inject(int val) {
        LLN* new_apnode = new LLN(val);
        if (is_empty()) {
            frnt = new_apnode;
            bck = new_apnode;
            new_apnode->nxt = new_apnode;
        } else {
            new_apnode->nxt = frnt;
            bck->nxt = new_apnode;
            frnt = new_apnode;
        }
        sz++;
    }

    // Remove and return an element from the rear of the circular deque
    int pop_rear() {
        if (is_empty()) {
            return -1;
        }
        int elemt = bck->ele;
        if (sz == 1) {
            delete bck;
            frnt = NULL;
            bck = NULL;
        } else {
            LLN* crnt = frnt;
            while (crnt->nxt != bck) crnt = crnt->nxt;
            crnt->nxt = frnt;
            delete bck;
            bck = crnt;
        }
        sz--;
        return elemt;
    }

    // Print the elements in the circular deque
    void print_deque() {
        if (is_empty()) {
            cout << -1 << endl;
        } else {
            LLN* crnt = frnt;
            do {
                cout << crnt->ele << " ";
                crnt = crnt->nxt;
            } while (crnt != frnt);
            cout << endl;
        }
    }

    // Print the elements in reverse order
    void print_reverse() {
        if (is_empty()) {
            cout << -1 << endl;
        } else {
            LLN* crnt = bck;
            do {
                cout << crnt->ele << " ";
                if (crnt == frnt) break;
                crnt = find_previous(crnt);
            } while (true);
            cout << endl;
        }
    }

    // Find an element at a specified position
    int find_elem(int pos) {
        if (pos < 1 || pos > sz) {
            return -1;
        }
        LLN* crnt = frnt;
        for (int i = 1; i < pos; i++) {
            crnt = crnt->nxt;
        }
        return crnt->ele;
    }

    // Find the previous node of a given node
    LLN* find_previous(LLN* linked_listnode) {
        LLN* crnt = frnt;
        while (crnt->nxt != linked_listnode) {
            crnt = crnt->nxt;
        }
        return crnt;
    }

    // Remove k elements from the front of the circular deque
    void remove_k_elems(int o) {
        for (int p = 0; p < min(o, sz); p++) {
            pop();
        }
    }
};

int main() {
    Adtcircular_deque dq_22bce027;

    // Input the number of operations
    int n;
    cin >> n;

    // Process each operation
    while (n--) {
        string x;
        cin >> x;
        int y, z;
        y = x[x.size() - 1] - '0';
        if (y == 1) cin >> z, dq_22bce027.push(z);
        if (y == 2) cout << dq_22bce027.pop() << '\n';
        if (y == 3) cin >> z, dq_22bce027.inject(z);
        if (y == 4) cout << dq_22bce027.pop_rear() << '\n';
        if (y == 5) dq_22bce027.print_deque();
        if (y == 6) dq_22bce027.print_reverse();
        if (y == 7) cin >> z, cout << dq_22bce027.find_elem(z) << '\n';
        if (y == 8) cin >> z, dq_22bce027.remove_k_elems(z);
    }
    return 0;
}
// sample input
/*  15
    OPER1
    4
    OPER3
    5
    OPER1
    2
    OPER1
    6
    OPER2
    OPER4
    OPER1
    1
    OPER5
    OPER3
    7
    OPER6
    OPER3
    3
    OPER7
    4
    OPER8
    3
    OPER5
    OPER7
    3
    */
