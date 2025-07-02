#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

    public:
        SinglyLinkedList() : head(nullptr) {}

        void insert(int value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        Node* search(int value) {
            Node* temp = head;
            while(temp != nullptr) {
                if(temp->val == value) {
                    return temp; 
                }
                temp = temp->next;
            }
            return nullptr; 
        }

        void delete_value(int value) {
            if(head == nullptr) return;
            if(head->val == value) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr && temp->next->val != value) {
                temp = temp->next;
            }
            if(temp->next != nullptr) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    SinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    Node* foundNode = list.search(20);  
    list.delete_value(20);
    foundNode = list.search(20); 
    if(foundNode) {
        cout << "Found: " << foundNode->val << endl;
    } else {
        cout << "Value not found." << endl;
    }
    
    return 0;
}   