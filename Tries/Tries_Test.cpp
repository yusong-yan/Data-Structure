#include "Tries.hpp"
#include <iostream>
#include <set>
#include <stdio.h>


using namespace std;

void msg(int testCase, string method, string result){
    printf("Tries %s Test%d: %s\n", method.c_str(), testCase, result.c_str());
}

bool checkVector(vector<string> const &actual, set<string> &expect){
    if (actual.size()!=expect.size()){
        return false;
    }
    for(int i = 0; i < actual.size(); i++){
        if (expect.find(actual[i]) == expect.end()){
            return false;
        }
    }
    return true;
}

void testContain(){
    Tries t;

    int testCase = 1;
    t.insert("yusong");
    if (t.contain("yusong")){
        msg(testCase, "Contain", "PASS");
    }else{
        msg(testCase, "Contain", "FAIL");
    }

    testCase = 2;
    t.insert("yusongyan");
    if (!t.contain("yusongy")){
        msg(testCase, "Contain", "PASS");
    }else{
        msg(testCase, "Contain", "FAIL");
    }
    if (t.contain("yusongyan")){
        msg(testCase, "Contain", "PASS");
    }else{
        msg(testCase, "Contain", "FAIL");
    }

    testCase = 3;
    t.insert("yanyusong");
    t.insert("minghaozhang");
    if (t.contain("yanyusong")){
        msg(testCase, "Contain", "PASS");
    }else{
        msg(testCase, "Contain", "FAIL");
    }
    if (t.contain("minghaozhang")){
        msg(testCase, "Contain", "PASS");
    }else{
        msg(testCase, "Contain", "FAIL");
    }
}

void testCollect(){
    Tries t;

    int testCase = 1;
    t.insert("yusong");
    t.insert("yusongyan");
    t.insert("yanyusong");
    t.insert("minghaozhang");
    set<string> expect = {"yusong", "yusongyan", "yanyusong", "minghaozhang"};
    if (checkVector(t.collect(), expect)){
        msg(testCase, "Collect", "PASS");
    }else{
        msg(testCase, "Collect", "FAIL");
    }

    testCase = 2;
    t.insert("song2612");
    expect.insert("song2613");
    if (!checkVector(t.collect(), expect)){
        msg(testCase, "Collect", "PASS");
    }else{
        msg(testCase, "Collect", "FAIL");
    }

}

int main(){
    cout<<"\n---Start Test Contain---"<<endl;
    testContain();
    cout<<"---End Test Contain---\n"<<endl;

    cout<<"\n---Start Test Collect---"<<endl;
    testCollect();
    cout<<"---End Test Collect---\n"<<endl;
}