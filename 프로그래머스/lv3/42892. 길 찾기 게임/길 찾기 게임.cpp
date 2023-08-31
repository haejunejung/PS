#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 두 팀이 같은 곳을 다른 순서로 방문하도록 해서, 먼저 순회를 마친 팀이 승리
// 각 장소를 이진트리의 노드가 되도록 구성한 후, 순회 방법을 힌트로 주어 각 팀이 스스로 경로를 찾는다.

// 1. 이진 트리로 만든다.
// 2. 전위 순회, 후위 순회한 결과를 반환한다.

using namespace std;

struct Point {
    int x;
    int y;
    int val;
    
    Point () {
        x = y = val = 0;
    }
    
    Point (int x_, int y_, int val_) {
        x   = x_;
        y   = y_;
        val = val_;
    }
};

struct Node {
    Point    p;
    Node    *l;
    Node    *r;
    
    explicit Node (Point p_) {
        p = p_;
        l = r = nullptr;
    }
    
};

class binary_tree {
  private   :
    Node *root;
  public    :
    binary_tree () : root(nullptr) {}
    
    void push (Point node) {
        
        Node *newNode = new Node(node);
        if (root == nullptr) {
            root = newNode;
            return;
        }   
        
        Node *now = root;
        while (now) {
            if (now->p.x < node.x) {
                if (now->r) {
                    now = now->r;
                }
                else {
                    now->r = newNode;
                    break;
                }
            }
            
            else {
                if (now->l) {
                    now = now->l;
                }
                else {
                    now->l = newNode;
                    break;
                }
            }
        }
    }
    
    vector<int> preorder (Node *curr, vector<int> &answer) {
        if (curr) {
            answer.push_back(curr->p.val);
            if (curr->l) {
                preorder (curr->l, answer);
            }
            
            if (curr->r) {
                preorder (curr->r, answer);
            }
        }
        
        return answer;
    }
    
    vector<int> postorder (Node *curr, vector<int> &answer) {
        if (curr) {
            if (curr->l) {
                postorder (curr->l, answer);
            }
            if (curr->r) {
                postorder (curr->r, answer);
            }
            answer.push_back(curr->p.val);
        }
        
        return answer;
    }
    
    Node *getRoot () {
        return root;
    }
};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    binary_tree bt;
    
    for (size_t i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i+1);
    }
    
    std::sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    });
        
    for (size_t i = 0; i < nodeinfo.size(); i++) {
        bt.push(Point(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]));  
    }
    
    vector<int> pre;
    vector<int> post;
    
    answer.push_back(bt.preorder(bt.getRoot(), pre));
    answer.push_back(bt.postorder(bt.getRoot(), post));
    
    return answer;
}