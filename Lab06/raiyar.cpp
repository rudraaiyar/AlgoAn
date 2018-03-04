//
//  main.cpp
//  lab6
//
//  Created by Rudra Aiyar on 3/3/18.
//  Copyright © 2018 Rudra Aiyar. All rights reserved.
//
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

void Insert(list<int>* Table, int key, int size) {
    int index = key % size;
    Table[index].push_front(key);
}

void Output(list<int>* Table, int size) {
    list<int>::iterator it;
    for(int i = 0; i < size; i++) {
        cout << i << ":";
        for(it = Table[i].begin(); it != Table[i].end(); ++it) {
            cout << *it << "->";
        }
        cout << ";" <<endl;
    }
}
void Search(list<int>* Table, int key, int size) {
    int index = key % size, count = 0;
    bool flag;
    list<int>::iterator it;
    for(it = Table[index].begin(); it != Table[index].end(); ++it) {
        if(*it == key) {
            cout << key << ":" << "FOUND_AT" << index << "," << count << ";" <<endl;
            flag = true;
            break;
        }
        count++;
    }
    if(!flag) {
        cout << key << ":NOT_FOUND;" <<endl;
    }
}

bool Delete(list<int>* Table, int key, int size) {
    int index = key % size, count = 0;
    list<int>::iterator it;
    bool flag;
    for(it = Table[index].begin(); it != Table[index].end(); ++it) {
        if(*it == key) {
            list<int>::iterator it_del = Table[index].begin();
            advance(it_del, count);
            Table[index].erase(it_del);
            bool flag = true;
            cout << key << ":DELETED;" <<endl;
            return true;
        }
        count++;
    }
    if(!flag) {
        cout << key << ":DELETE_FAILED;" <<endl;
    }
    return false;
}


int main(int argc, char **argv) {
    int size;
    cin >> size;
    list<int>* Table = new list<int>[size];
    char line[100];
    while(std::cin.getline(line, 100)) {
        string str(line);
        if(str.size() == 0) {
            continue;
        }
        if(str.substr(0,1) == "o") {
            Output(Table, size);
            continue;
        }
        if(str.substr(0,1) == "e") {
            return 0;
        }
        int key;
        stringstream convert_stm(str.substr(1,str.size()-1));
        if(!(convert_stm >> key)) {
            key = -1;
        }
        if(str.substr(0,1) == "d") {
            Delete(Table, key, size);
        }
        if(str.substr(0,1) == "i") {
            Insert(Table, key, size);
        }

        if(str.substr(0,1) == "s") {
            Search(Table, key, size);
        }
    }
    delete[] Table;
    return 0;
}
