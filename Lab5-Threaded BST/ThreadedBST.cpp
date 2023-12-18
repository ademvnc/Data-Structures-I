#include "ThreadedBST.h"

///-----------------------------------------------
/// Erases all nodes in the tree
/// 
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
	BSTNode *curr = this->min();

	while (curr != NULL){
		BSTNode *n = this->next(curr);
		delete curr;
		curr = n;
	} // end-while
	
} //end-eraseTreeNodes

///-----------------------------------------------
/// Adds a given key to the BST
/// 
void ThreadedBST::add(int key) {
    if (root == NULL) {
        root = new BSTNode(key);
        return;
    }

    BSTNode* curr = root;
    BSTNode* parent = NULL;

    while (curr != NULL) {
        parent = curr;

        if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                break;
            curr = curr->left;
        } else if (key > curr->key) {
            if (curr->rightLinkType == THREAD)
                break;
            curr = curr->right;
        } else {
            // Anahtar zaten mevcut, bir şey yapma
            return;
        }
    }

    BSTNode* newNode = new BSTNode(key);

    if (key < parent->key) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->leftLinkType = CHILD;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightLinkType = CHILD;
    }

    // Yeni düğümün bağ tipini ayarla
    newNode->leftLinkType = THREAD;
    newNode->rightLinkType = THREAD;
}

///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
/// 
void ThreadedBST::remove(int key) {
    BSTNode* curr = root;
    BSTNode* parent = NULL;

    // Find the node to be removed
    while (curr != NULL && curr->key != key) {
        parent = curr;
        if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                return; // Key not found
            curr = curr->left;
        } else {
            if (curr->rightLinkType == THREAD)
                return; // Key not found
            curr = curr->right;
        }
    }

    if (curr == NULL)
        return; // Key not found

    // Case 1: Node to be removed is a leaf
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == NULL) {
            delete root;
            root = NULL;
            return;
        }

        if (curr == parent->left) {
            parent->left = curr->left;
            parent->leftLinkType = THREAD;
        } else {
            parent->right = curr->right;
            parent->rightLinkType = THREAD;
        }

        delete curr;
    }
    // Case 2: Node to be removed has two children
    else if (curr->left != NULL && curr->right != NULL) {
        // BSTNode* successor = min();
        BSTNode* successor = curr->right;
        while (successor->leftLinkType != THREAD) {
            successor = successor->left;
        }

        // Swap key values
        int temp = curr->key;
        curr->key = successor->key;
        successor->key = temp;

        // Continue with the removal process
        remove(successor->key);
    }
    // Case 3: Node to be removed has one child
    else {
        BSTNode* child = (curr->left != NULL) ? curr->left : curr->right;

        if (parent == NULL) {
            delete root;
            root = child;
            return;
        }

        if (curr == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        delete curr;
    }
}


///-----------------------------------------------
/// Searches a given key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::find(int key) {
    BSTNode* curr = root;

    while (curr != NULL) {
        if (key == curr->key)
            return curr;
        else if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                return NULL;
            curr = curr->left;
        } else {
            if (curr->rightLinkType == THREAD)
                return NULL;
            curr = curr->right;
        }
    }

    return NULL;
}

///-----------------------------------------------
/// Returns the minimum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::min() {
    BSTNode* curr = root;

    while (curr != NULL && curr->leftLinkType != THREAD) {
        curr = curr->left;
    }

    return curr;
}

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::max() {
    BSTNode* curr = root;

    while (curr != NULL && curr->rightLinkType != THREAD) {
        curr = curr->right;
    }

    return curr;
}

///-----------------------------------------------
/// Given a valid pointer to a node in ThreadedBST,
/// returns a pointer to the node that contains the inorder predecessor
/// If the inorder predecessor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::previous(BSTNode* node) {
    if (node->leftLinkType == THREAD)
        return node->left;

    
    BSTNode* predecessor = node->left;
    while (predecessor->rightLinkType != THREAD) {
        predecessor = predecessor->right;
    }

    return predecessor;
}

///-----------------------------------------------
/// Given a valid pointer to a node in the ThreadedBST,
/// returns a pointer to the node that contains the inorder successor
/// If the inorder successor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::next(BSTNode* node) {
    if (node->rightLinkType == THREAD)
        return node->right;

    
    BSTNode* successor = node->right;
    while (successor->leftLinkType != THREAD) {
        successor = successor->left;
    }

    return successor;
}
