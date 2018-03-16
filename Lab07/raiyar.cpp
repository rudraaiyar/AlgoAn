#include <iostream>
#include <string>
#include <sstream>


using namespace std;

// Representation of an element in the tree
struct Node {
    int val;   // Value of the node
    Node *left;   // Pointer to the left node
    Node *right;  // Pointer to the right node
    Node *parent; // Pointer to the parent node
};

class BST {
    // Public Functions/Variables
public:
    BST();  // Constructor #1
    ~BST(); // Destructor
    void Insert(int toInsert);
    void Delete(int toDelete);
    void Print(string Order);
    
private:
    Node *root;
    
    Node *Search(int toFind); // Search for a node in the tree
    Node *Successor(Node *curr); // Find the successor of the given node
    Node *Minimum(Node *curr); // Find the minimum node of the given subtree
    Node *Maximum(Node *curr); // Find the minimum node of the given subtree
    void Transplant(Node *u, Node *v); // Replace the subtree rooted at node u with the subtree rooted at node v
    void InOrder(Node *curr); // Inorder traversal
    void PreOrder(Node *curr); // Preorder traversal
    void PostOrder(Node *curr); // Postorder traversal
};


BST::BST() {
    root = NULL;
}

BST::~BST() {
}

void BST::Insert(int toInsert) {
    Node* y = NULL;
    Node* x = root;
    Node* z = new Node();
    z-> val = toInsert;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    while(x != NULL) {
        y = x;
        if(toInsert < (x->val)) {
            x = (x->left);
        } else {
            x = (x->right);
        }
    }
    z->parent = y;
    if(y == NULL) {
        root = z;
    }
    else if(toInsert < (y->val)) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void BST::Delete(int toDelete) {
    Node* z = Search(toDelete);
    Node* y;
    if(z->left == NULL) {
        Transplant(z, z->right);
    }
    else if (z->right == NULL) {
        Transplant(z, z->left);
    } else {
        y = Minimum(z->right);
        if(y->parent != z) {
            Transplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
    }
}

void BST::Transplant(Node *u, Node *v) {
    Node* z = root;
    if(u->parent == NULL) {
        root = v;
    }
    else if(u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if(v != NULL) {
        v->parent=u->parent;
    }
}

Node *BST::Successor(Node *x) {
    Node* y;
    if(x->right == NULL) {
        return Minimum(x->right);
    }
    y = x->parent;
    while(y != NULL && x == (y->right)) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node *BST::Minimum(Node *x) {
    while(x->left != NULL) {
        x = x->left;
    }
    return x;
}

Node *BST::Maximum(Node *x) {
    while(x->right == NULL) {
        x = x->right;
    }
    return x;
}

Node *BST::Search(int toFind) {
    Node* temp = root;
    while(temp != NULL && toFind != temp->val) {
        if(temp->val > toFind) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return temp;
}

void BST::Print(string Order) {
    if(Order == "IN") {
        InOrder(root);
    }
    else if(Order == "PRE") {
        PreOrder(root);
    }
    else if(Order == "POST") {
        PostOrder(root);
    }
}

void BST::PreOrder(Node *x) {
    if(x != NULL) {
        cout << x->val <<endl;
        PreOrder(x->left);
        PreOrder(x->right);
    }
}

void BST::InOrder(Node *x) {
    if(x != NULL) {
        InOrder(x->left);
        cout << x->val <<endl;
        InOrder(x->right);
    }
}

void BST::PostOrder(Node *x) {
    if(x!= NULL) {
        PostOrder(x->left);
        PostOrder(x->right);
        cout << x->val <<endl;
    }
}

int main(int argc,char **argv) {
    // empty bst
    BST Tree;
    
    char line[100];
    while(std::cin.getline(line,100)) {
        string str(line);
        if(str.size() ==0) continue;
        if(str.substr(0,1) == "e") return 1;
        
        if(str.substr(0,1) == "o") {
            if(str.substr(0,3) == "oin") {
                Tree.Print("IN");
            }
            else if(str.substr(0,4) == "opre") {
                Tree.Print("PRE");
            }
            else if(str.substr(0,5) == "opost") {
                Tree.Print("POST");
            }
            continue;
        }
        
        int key;
        stringstream convert_stm(str.substr(1,str.size()-1));
        if(!(convert_stm >> key)) {
            key = -1;
        }
        
        if(str.substr(0,1) == "i") Tree.Insert(key);
        else if(str.substr(0,1) == "d") Tree.Delete(key);
    }
    
    cout<<endl;
    return 1;
    
}
