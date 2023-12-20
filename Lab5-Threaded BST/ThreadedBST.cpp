#include "ThreadedBST.h"

///-----------------------------------------------
/// Erases all nodes in the tree
/// 
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
    BSTNode* curr = this->min();

    while (curr != nullptr) {
        BSTNode* n = this->next(curr);
        delete curr;
        curr = n;
    }
}

///-----------------------------------------------
/// Adds a given key to the BST
/// 
void ThreadedBST::add(int key) {
    if (root == nullptr) {
        root = new BSTNode(key);
        return;
    }

    BSTNode* curr = root;
    BSTNode* parent = nullptr;

    while (curr != nullptr) {
        parent = curr;

        if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                break;
            curr = curr->left;
        }
        else if (key > curr->key) {
            if (curr->rightLinkType == THREAD)
                break;
            curr = curr->right;
        }
        else {
            // Key already exists, do nothing
            return;
        }
    }

    BSTNode* newNode = new BSTNode(key);

    if (key < parent->key) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->leftLinkType = CHILD;
    }
    else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightLinkType = CHILD;
    }
}


///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
/// 
void ThreadedBST::remove(int key) {
    BSTNode* curr = root;
    BSTNode* parent = nullptr;

    while (curr != nullptr) {
        if (key == curr->key)
            break;

        parent = curr;

        if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                return; // Key not found
            curr = curr->left;
        }
        else {
            if (curr->rightLinkType == THREAD)
                return; // Key not found
            curr = curr->right;
        }
    }

    if (curr == nullptr)
        return; // Key not found

    if (curr->left == nullptr && curr->right == nullptr) {
        if (parent == nullptr) {
            delete root;
            root = nullptr;
            return;
        }

        if (curr == parent->left) {
            parent->left = curr->left;
            parent->leftLinkType = THREAD;
        }
        else {
            parent->right = curr->right;
            parent->rightLinkType = THREAD;
        }

        delete curr;
    }
    else if (curr->left != nullptr && curr->right != nullptr) {
        BSTNode* successor = min();

        int temp = curr->key;
        curr->key = successor->key;
        successor->key = temp;

        remove(successor->key);
    }
    else {
        BSTNode* child = (curr->left != nullptr) ? curr->left : curr->right;

        if (parent == nullptr) {
            delete root;
            root = child;
            return;
        }

        if (curr == parent->left) {
            parent->left = child;
        }
        else {
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
///
BSTNode* ThreadedBST::find(int key) {
    BSTNode* curr = root;

    while (curr != nullptr) {
        if (key == curr->key)
            return curr;
        else if (key < curr->key) {
            if (curr->leftLinkType == THREAD)
                return nullptr;
            curr = curr->left;
        }
        else {
            if (curr->rightLinkType == THREAD)
                return nullptr;
            curr = curr->right;
        }
    }

    return nullptr;
}

BSTNode* ThreadedBST::min() {
    BSTNode* curr = root;

    while (curr != nullptr && curr->leftLinkType != THREAD) {
        curr = curr->left;
    }

    return curr;
}

BSTNode* ThreadedBST::max() {
    BSTNode* curr = root;

    while (curr != nullptr && curr->rightLinkType != THREAD) {
        curr = curr->right;
    }

    return curr;
}

BSTNode* ThreadedBST::previous(BSTNode* node) {
    if (node == nullptr)
        return nullptr;

    if (node->leftLinkType == THREAD)
        return node->left;

    node = node->left;
    while (node != nullptr && node->rightLinkType != THREAD) {
        node = node->right;
    }

    return node;
}
BSTNode* ThreadedBST::next(BSTNode* node) {
    if (node == nullptr)
        return nullptr;

    // Eğer THREAD bağlantısı varsa, bir sonraki düğümü direkt olarak döndür.
    if (node->rightLinkType == THREAD)
        return node->right;

    // Eğer CHILD bağlantısı varsa, sağ çocuğun en küçük düğümünü bul.
    if (node->rightLinkType == CHILD) {
        node = node->right;
        while (node->leftLinkType == CHILD)
            node = node->left;
        return node;
    }

    return nullptr; // Geçersiz durum, hata durumunu işaretlemek için nullptr döndürülebilir.
}