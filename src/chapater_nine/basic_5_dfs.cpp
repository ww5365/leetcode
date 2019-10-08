/*
 * basic_5_dfs.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: wangwei69
 */

#include <string>
#include <vector>

#include <iostream>


using namespace std;

/*
 * 1、给定字符串s，切成子串，返回是回文的子串；
 *
 * 一个问题包含了两种算法考察：？
 * a. 如何得到字符串的所有的子串：  组合问题
 * b. 如何判断一个字符串是回文：    动态规划
 *
 */

class Solution{

public:
    void all_substring(string &s){

        vector<string> path;
        vector<vector<string>> res;

        dfs(s, 0, path, res);

        cout << "all substring : " << res.size() << endl;

        for (auto elems: res){
            cout << "substr res: " << endl;
            for(auto elem: elems){
                cout << elem << "|";
            }

            cout << endl;
        }
    }


private:

    //深度优先算法，切分字符串s，得到所有子串
    void dfs(const string &s, vector<string> &path, vector<vector<string>> &res){

        size_t len = s.size();
        if (len == 0) {
            res.push_back(path);
            return;
        }

        for(int idx = 1; idx <= len ; ++idx){
            path.push_back(s.substr(0, idx));
            dfs(s.substr(idx), path, res);  //怎么保持递归调用中，s是同一个，而不是发生值拷贝？ 参数定义为const
            path.pop_back();
        }
    }


    //字符串s的切割成子串开始位置：start
    void dfs(string &s, int start, vector<string> &path, vector<vector<string>> &res){

        int len = s.size();

        if (start >= len){
            res.push_back(path);
            return;
        }

        //i代表截取长度
        cout << "sub_str len - start----:" << len - start << endl;
        for(int i = 1; i <= (len - start); ++i){
            string sub_str = s.substr(start, i);
            path.push_back(sub_str);
            cout << "sub_str---:" << sub_str  << " : " << start << ":"<< i << endl;
            dfs(s, start + sub_str.size(), path, res);

            path.pop_back();
            cout << "---------" << endl;
        }



    }




};






void test_base_5_dfs(){


    Solution test;
    string s = "abc";
    test.all_substring(s);


}



