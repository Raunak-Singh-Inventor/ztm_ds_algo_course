#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *right;
    Node *left;

    Node(int val) {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

struct parentChildPair {
    Node *parent;
    Node *child;
};

class BST {
    Node *root;
public:
    BST(int val) {
        root = new Node(val);
    }

private:
    void traverse(Node *tmp) {
        cout << tmp->val << endl;
        if (tmp->right != nullptr) {
            cout << tmp->val << " R-> ";
            traverse(tmp->right);
        }
        if (tmp->left != nullptr) {
            cout << tmp->val << " L-> ";
            traverse(tmp->left);
        }
    }

    void insert(Node *tmp, int val) {
        while (true) {
            while (tmp->val >= val) {
                if (tmp->left == nullptr) {
                    tmp->left = new Node(val);
                    return;
                }
                tmp = tmp->left;
            }
            if (tmp->right == nullptr) {
                tmp->right = new Node(val);
                return;
            } else {
                tmp = tmp->right;
            }
        }
    }

    parentChildPair search(Node *tmp, int val) {
        parentChildPair pair = {};
        if (tmp->val == val) {
            pair.parent = nullptr;
            pair.child = tmp;
            return pair;
        }
        while (tmp != nullptr) {
            if ((tmp->right == nullptr || tmp->right->val != val) && (tmp->left == nullptr || tmp->left->val != val)) {
                if (val > tmp->val) {
                    tmp = tmp->right;
                } else if (val < tmp->val) {
                    tmp = tmp->left;
                }
                continue;
            }
            break;
        }
        if (val == tmp->right->val) {
            pair.parent = tmp;
            pair.child = tmp->right;
        }
        if (val == tmp->left->val) {
            pair.parent = tmp;
            pair.child = tmp->left;
        }
        return pair;
    }

public:
    void print() {
        traverse(root);
    }

    void insert(int val) {
        insert(root, val);
    }

    void remove(int val) {
        parentChildPair node_to_delete = search(root, val); // child is node that will be deleted from tree
        if (node_to_delete.child == nullptr) {
            return;
        }
        if (node_to_delete.child->right == nullptr && node_to_delete.child->left == nullptr) {
            if (node_to_delete.parent != nullptr) {
                if (node_to_delete.parent->right == node_to_delete.child) {
                    node_to_delete.parent->right = nullptr;
                } else if (node_to_delete.parent->left == node_to_delete.child) {
                    node_to_delete.parent->left = nullptr;
                }
            } else {
                root = nullptr;
            }
        } else if (node_to_delete.child->right && node_to_delete.child->left) {
            Node *parentSuccesorNode = node_to_delete.child;
            Node *succesorNode = node_to_delete.child->right;
            while (succesorNode->left != nullptr) {
                if (parentSuccesorNode == node_to_delete.child) {
                    parentSuccesorNode = parentSuccesorNode->right;
                } else {
                    parentSuccesorNode = parentSuccesorNode->left;
                }
                succesorNode = succesorNode->left;
            }
            if (node_to_delete.parent != nullptr) {
                if (node_to_delete.parent->right == node_to_delete.child) {
                    node_to_delete.parent->right = succesorNode;
                } else if (node_to_delete.parent->left == node_to_delete.child) {
                    node_to_delete.parent->left = succesorNode;
                }
            } else {
                root->val = succesorNode->val;
                if (parentSuccesorNode->left == succesorNode) {
                    parentSuccesorNode->left = nullptr;
                } else if (parentSuccesorNode->right == succesorNode) {
                    parentSuccesorNode->right = nullptr;
                }
                return;
            }
            succesorNode->left = node_to_delete.child->left;
            if (succesorNode->right != nullptr) {
                succesorNode->left = succesorNode->right;
                succesorNode->right = nullptr;
            }
        } else {
            if (node_to_delete.child->right != nullptr) {
                if (node_to_delete.parent != nullptr) {
                    if (node_to_delete.parent->right == node_to_delete.child) {
                        node_to_delete.parent->right = node_to_delete.child->right;
                    } else if (node_to_delete.parent->left == node_to_delete.child) {
                        node_to_delete.parent->left = node_to_delete.child->right;
                    }
                } else {
                    node_to_delete.child = node_to_delete.child->right;
                }
            } else if (node_to_delete.child->left != nullptr) {
                if (node_to_delete.parent != nullptr) {
                    if (node_to_delete.parent->right == node_to_delete.child) {
                        node_to_delete.parent->right = node_to_delete.child->left;
                    } else if (node_to_delete.parent->left == node_to_delete.child) {
                        node_to_delete.parent->left = node_to_delete.child->left;
                    }
                } else {
                    node_to_delete.child = node_to_delete.child->left;
                }
            }
        }
    }
};

int main() {
    BST *bst = new BST(50);
    bst->insert(25);
    bst->insert(75);
    bst->insert(10);
    bst->insert(33);
    bst->insert(56);
    bst->insert(89);
    bst->insert(4);
    bst->insert(11);
    bst->insert(30);
    bst->insert(40);
    bst->insert(52);
    bst->insert(61);
    bst->insert(82);
    bst->insert(95);
    bst->remove(4);
    bst->remove(10);
    bst->remove(56);
    // bst->remove(50);
    bst->insert(55);
    bst->print();
    return 0;
}
