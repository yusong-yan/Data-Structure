#ifndef TRIES
#define TRIES

#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Tries{

public:
    Tries();
    ~Tries();
    void insert(string s);
    bool contain(string s);
    vector<string> collect();
    vector<string> stringWithPrefix(string prefix);


private:
    struct Node{
        bool isKey;
        unordered_map<char, Node*> children;
        Node(){
            this->isKey = false;
        }
    };
    Node* root;

    void stringWithPrefixHelper(string prefix, Node* cur, vector<string> &result);
};

#endif