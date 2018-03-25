#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct node {
    double frequency;
    char content;
    string encoding;
    node *left;
    node *right;
};
vector<node> nodeArray;

node extractMin() {
    double value = INT_MAX;
    vector<node>::iterator i, x;
    for(i = nodeArray.begin(); i != nodeArray.end(); i++) {
        if(value > (*i).frequency) {
            x = i;
            value = (*i).frequency;
        }
    }
    node tempNode = (*x);
    nodeArray.erase(x);
    return tempNode;
}

node HuffmanTree() {
    while(!nodeArray.empty()) {
        node *tempNode = new node();
        node *tempNode1 = new node();
        node *tempNode2 = new node();
        *tempNode1 = extractMin();
        *tempNode2 = extractMin();
        
        tempNode->left = tempNode1;
        tempNode->right = tempNode2;
        tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
        nodeArray.push_back(*tempNode);
        if(nodeArray.size() == 1) {
            break;
        }
    }
    return nodeArray[0];
}

void BFS(node *temproot, string str, char ch) {
    node *root1 = new node();
    root1 = temproot;
    root1->encoding = str;
    if((root1->left == NULL) && (root1->right == NULL)) {
        if(root1->content == ch) {
            cout << root1->content << ":" << root1->encoding <<endl;
        }
    } else {
        root1->left->encoding = str.append("0");
        str.erase(str.end() - 1);
        root1->right->encoding = str.append("1");
        str.erase(str.end() - 1);
        BFS(root1->left, str.append("0"), ch);
        str.erase(str.end() - 1);
        BFS(root1->right, str.append("1"), ch);
        str.erase(str.end() - 1);
    }
}

int main() {
    double freqIn;
    char symbol = ' ';
    for(int i = 0; i < 6; i++) {
        node tempNode;
        cin >> freqIn;
        if(i == 0) {
            symbol = 'A';
        } else if(i == 1) {
            symbol = 'B';
        } else if(i == 2) {
            symbol = 'C';
        } else if(i == 3) {
            symbol = 'D';
        } else if(i == 4) {
            symbol = 'E';
        } else {
            symbol = 'F';
        }
        tempNode.frequency = freqIn;
        tempNode.content = symbol;
        tempNode.left = NULL;
        tempNode.right = NULL;
        nodeArray.push_back(tempNode);
    }
    
    node root = HuffmanTree();
    BFS(&root, "", 'A');	
    BFS(&root, "", 'B');
    BFS(&root, "", 'C');
    BFS(&root, "", 'D');
    BFS(&root, "", 'E');
    BFS(&root, "", 'F');
    return 0;
}
