#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int value) : val(value),next(nullptr){}
};

Node* reverseIterative(Node* head){
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr){
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
};

Node* reverseRecursive(Node* head) {
    if(head == nullptr || head->next == nullptr){return head;}
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head; 
    head->next = nullptr;    
    return newHead;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original List: ";
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
    
    Node* reversedHeadIterative = reverseIterative(head);
    cout << "Reversed List (Iterative): ";
    temp = reversedHeadIterative;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";

    Node* reversedHeadRecursive = reverseRecursive(reversedHeadIterative);
    cout << "Reversed List (Recursive): ";
    temp = reversedHeadRecursive;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}

