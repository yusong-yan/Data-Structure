#include <iostream>
#include "Tries.hpp"

Tries::Tries(){
    this->root = new Node();
}

Tries::~Tries(){
    queue<Node*> q;
    q.push(root);
    unordered_map<char, Node*> cur;
    while(!q.empty()){
        cur = q.front()->children;
        for(auto i = cur.begin(); i!=cur.end(); i++){
            q.push(i->second);
        }
        delete q.front();
        q.pop();
    }
}

void Tries::insert(string s){
    Node* cur = this->root;
    for(int i = 0; i < s.size(); i++){
        if (cur->children.find(s[i]) == cur->children.end()){
            cur->children[s[i]] = new Node();
        }
        cur = cur->children[s[i]];
    }
    cur->isKey = true;
}

bool Tries::contain(string s){
    Node* cur = this->root;
    for(int i = 0; i < s.size(); i++){
        if (cur->children.find(s[i]) == cur->children.end()){
            return false;
        }
        cur = cur->children[s[i]];
    }
    return cur->isKey;
}

vector<string> Tries::collect(){
    return stringWithPrefix("");
}

vector<string> Tries::stringWithPrefix (string prefix){
    vector<string> result;
    Node* cur = this->root;
    for(int i = 0; i < prefix.size(); i++){
        if (cur->children.find(prefix[i]) == cur->children.end()){
            return result;
        }
        cur = cur->children[prefix[i]];
    }
    stringWithPrefixHelper(prefix, cur, result);
    return result;
}

void Tries::stringWithPrefixHelper(string prefix, Node* cur, vector<string> &result){
    if (!cur)
        return;
    if (cur->isKey){
        result.push_back(prefix);
    }
    for(auto i = cur->children.begin(); i!= cur->children.end(); i++){
        stringWithPrefixHelper(prefix+i->first, i->second, result);
    }
}

