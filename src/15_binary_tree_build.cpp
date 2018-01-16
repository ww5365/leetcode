/*
 * ds_tree_buid.h
 *
 *  Created on: Jan 15, 2018
 *      Author: wangwei69
 */



#include "ds_common.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 * 功能：
 * 1、输入：前序 和 中序 序列 生成一颗二叉树
 * 2、返回：二叉树树根
 *
 * 比如：下面的树如何通过前序和中序构造？
 *
 *       1
 *    2     3
 *  4   5      6
 *
 * 前序：1 2 4 5 3 6
 * 中序：4 2 5 1 3 6
 *
 * 思路：
 *
 * 1、前序中，可以知道，第一个元素是根节点的位置，通过中序序列确定出左右子树的子序列；
 * 2、通过左右子树的子序列（前，中），又递归的创建左右子树；
 *
 */

class Solution {

public:

    //迭代器版本
    TreeNode* build_tree1(vector<int>& pre_order, vector<int>& in_order){
        //使用前，中序序列，递归创建二叉树
        return build(pre_order.begin(),pre_order.end(),
                in_order.begin(),in_order.end());
    }

    //下标版本
    TreeNode* build_tree2(vector<int>& pre_order,vector<int>& in_order){

        return build(pre_order,0, pre_order.size()-1, in_order,0,in_order.size()-1);

    }



private:

    //使用下标的版本,元素范围：[pre_start,pre_end] [in_start,in_end]

    TreeNode* build(vector<int> &pre, size_t pre_start,size_t pre_end,
                    vector<int> &in, size_t in_start,size_t in_end ){

        if (pre_start > pre_end|| in_start > in_end ) return nullptr;

        TreeNode* root = new TreeNode(pre[pre_start]);

        size_t pos = in_start;

        for( size_t i = in_start;i <= in_end ;i++){
            if(in[i] == pre[pre_start]){
                pos = i;
                break;
            }
        }


        cout << "pos: " << pos << " in_start:"<< in_start << endl;
        size_t len = pos - in_start;

        root -> left = build(pre, pre_start+1, pre_start + len,
                             in, in_start, in_start + len - 1);

        root -> right = build(pre, pre_start + 1 + len,pre_end,
                              in, in_start + len + 1, in_end);
        return root;

    }


    //迭代器版本 [pre_first,pre_last)
    TreeNode* build(vector<int>::iterator pre_first, vector<int>::iterator pre_last,
                    vector<int>::iterator in_first, vector<int>::iterator in_last){
        if (pre_first == pre_last) return nullptr;
        if (in_first == in_last) return nullptr;

        TreeNode *root = new TreeNode(*pre_first);
        //使用迭代器访查找某个范围内[in_first,in_last)值；返回找到值的迭代器值，否则返回in_last
        auto it = find(in_first,in_last, *pre_first); //algorithm
        int left_size = distance(in_first, it);

        root->left = build(next(pre_first), next(pre_first,left_size+1),
                           in_first, next(in_first, left_size));

        root->right = build(next(pre_first,left_size+1),pre_last,
                            next(it),in_last);

        return root;

    }

};


void post_reverse(TreeNode* root){

    if (!root)
        return;
    post_reverse(root->left);
    post_reverse(root->right);

    cout << root ->val << " ";

}


void binary_tree_build_test(){

    int pre[] = {1, 2, 4, 5, 3, 6};
    int in[] =  {4, 2, 5, 1, 3, 6};

    vector<int> pre_order(pre,pre+6);
    vector<int> in_order(in,in+6);


    Solution s;

    //使用构建版本1，迭代器版本
    TreeNode* root1 = s.build_tree1(pre_order,in_order);

    //使用构建版本2，使用下标版本
    TreeNode* root2 = s.build_tree2(pre_order,in_order);

    //给出个后续遍历的序列

    cout << "post travese1: " << endl;
    post_reverse(root1);

    cout << endl << "post travese2: " << endl;
    post_reverse(root2);



}






