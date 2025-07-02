#include<bits/stdc++.h>
using namespace std;

class BSTNode {
public:
    int value;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

void validateBST(BSTNode* node, int min, int max, bool& isValid){
    if( node == NULL ){return;}
    if( node->value < min || node->value > max ){
        isValid = false;
        return;
    }
    validateBST(node->left, min, node->value, isValid);
    validateBST(node->right, node->value, max, isValid);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    BSTNode* root = new BSTNode(10);
    root->left = new BSTNode(5);
    root->right = new BSTNode(15);
    root->left->left = new BSTNode(3);
    root->left->right = new BSTNode(7);
    root->right->right = new BSTNode(20);

    bool isValid = true;
    validateBST(root, INT_MIN, INT_MAX, isValid);
    if (isValid) {
        cout << "The tree is a valid Binary Search Tree.\n";
    } else {
        cout << "The tree is NOT a valid Binary Search Tree.\n";
    }

    return 0;
}