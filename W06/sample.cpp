#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void createNode(Node* p, int data) {
    p->data = data;
    p->next = NULL;
}

Node* addFirst(Node* head, Node* p) {
    if (head == NULL) {
        head = p;
        return head;
    }
    else {
        p->next = head;
        head = p;
        return head;
    }
}

void display(Node* head) {
    if (head == 0) return;
    while (!(head == 0)) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node* p;
        createNode(p, data);
        head = addFirst(head, p);
    }

    display(head);

    return 0;
}