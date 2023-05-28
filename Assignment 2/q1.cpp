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
 
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in_order;
        make_in(root,in_order);
        return make_bst(in_order,0,in_order.size()-1);
	}
    void make_in(TreeNode* root,auto &v){
        if(!root)   return;
        make_in(root->left,v);
        v.push_back(root->val);
        make_in(root->right,v);
    }
    TreeNode* make_bst(auto &v,int l,int r){
        if(l>r)     return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=make_bst(v,l,mid-1);
        root->right=make_bst(v,mid+1,r);
        return root;
    }
};

void displayInOrder(TreeNode* root){
    if (!root){
        cout<<"null"<<" ";
        return;
    }
    cout<<root->val<<" ";
    displayInOrder(root->left);
    displayInOrder(root->right);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    //Test Case 1
    TreeNode* d = new TreeNode(4);
    TreeNode* c = new TreeNode(3,NULL,d);
    TreeNode* b = new TreeNode(2,NULL,c);
    TreeNode* a = new TreeNode(1,NULL,b);


    //display(a);
    //cout<<endl;
    Solution sol;
    displayInOrder(sol.balanceBST(a));
}