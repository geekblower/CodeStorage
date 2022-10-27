#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

void insertNewNode(Node* &tail, int data, int element=0) {
    Node* insertNode = new Node(data);

    // For empty list
    if(tail == NULL) {
        insertNode->next = insertNode;
        tail = insertNode;
        return;
    }

    Node* temp = tail->next;

    while(temp->data != element && element != 0) {
        if(temp == tail) {
            cout<<"Element "<<element<<" not found in the list!\n";
            return;
        }
        
        temp = temp->next;
    }

    if(element == 0) {
        temp = tail;
    }

    insertNode->next = temp->next;
    temp->next = insertNode;
    
    // For list with single node
    if(temp == tail) {
        tail = insertNode;
    }
}

void deleteNode(Node* &tail, int target) {
    if(tail == NULL) {
        cout<<"List is empty! Nothing to delete"<<endl;
        return;
    }

    Node* temp = tail->next;

    while(temp->next->data != target) {
        if(temp == tail) {
            cout<<"Target element "<<target<<" not found in the list\n";
            return;
        }
        
        temp = temp->next;
    }

    Node* targetNode = temp->next;
    temp->next = targetNode->next;

    if(targetNode == tail) {
        // For handling tail and list with single node
        tail = (tail->next == tail) ? NULL : temp;
    }

    delete targetNode;
}

void print(Node* tail) {
    if(tail == NULL) {
        cout<<"List is empty\n";
        return;
    }

    Node* temp = tail->next;

    while(temp != tail) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<tail->data<<endl;
}

int main() {
    //Node* node1 = new Node(10);
    //node1->next = node1;
    //Node* tail = node1;

    Node* tail = NULL;

    for(int i=1; i<=6; i++) {
        insertNewNode(tail, i*5);
    }
    //cout<<"tail->data = "<<tail->data<<endl;

    print(tail);
    return 0;
}
