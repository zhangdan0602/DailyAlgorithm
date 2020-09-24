//
// Created by zd on 2020/9/24.
//
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Node{
public:
    int val;
    vector<Node*> child;
    Node(){}
    Node(int _val){
        val = _val;
    }
    Node(int _val, vector<Node*> _child){
        val = _val;
        child = _child;
    }
};

class Solution{
public:
    vector<int> preorder(Node* root){
        vector<int> result;
        stack<Node*> sta;
        if(!root)
            return result;
        sta.push(root);
        while (!sta.empty()){
            Node* node = sta.top();
            result.push_back(node->val);
            sta.pop();
            if(!node->child.empty()){
                for (int i = node->child.size() - 1; i >= 0; i--) {
                    sta.push(node->child[i]);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<Node*> third;
    third.push_back(new Node(5));
    third.push_back(new Node(6));

    vector<Node*> second;
    Node* three = new Node(3, third);
    second.push_back(three);
    second.push_back(new Node(2));
    second.push_back(new Node(4));

    Node* root = new Node(1, second);

    vector<int> res = solution.preorder(root);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    cout << endl;
}
