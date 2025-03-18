// Leetcode 1028
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isDigit(char c) {
    return (c >= '0' and c <= '9');
}

TreeNode* recoverFromPreorder(string traversal) {
    stack<TreeNode*> st;
    int i = 0;
    TreeNode* root = nullptr;
    while(i < traversal.length()) {
        int depth = 0, value = 0;
        while(i < traversal.length() and traversal[i] == '-') {
            depth++;
            i++;
        }
        while(i < traversal.length() and isDigit(traversal[i])) {
            value = value * 10 + (traversal[i++] - '0');
        }

        TreeNode* newNode = new TreeNode(value);
        while(st.size() > depth) st.pop();
        if(!st.empty()) {
            if(st.top()->left == nullptr) st.top()->left = newNode;
            else st.top()->right = newNode;
        } else {
            root = newNode;
        }

        st.push(newNode);
    }

    return root;
}
