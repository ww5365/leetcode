/*
 * 16_combination.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: wangwei69
 */

#include <vector>
#include <iostream>
#include <cmath>
#include "test_main.h"

using namespace std;

class Solution{

public:
    //实现bool型数组作为二进制数，自动加1
    bool add_one(vector<bool> &selected);
    //位向量法：使用上面的二进制加1，实现全部的组合排列


};


/*
 * 实现bool型数组作为二进制数，自动加1
 * 正常返回true；溢出时，返回false；
 *
 * example：
 * 110 + 1 -> 111 返回true
 * 111 + 1 -> 1000 ,溢出，返回false
 */

bool Solution::add_one(vector<bool> &selected){
    bool flag = true; //进位标识
    size_t i = 0;
    for(i = selected.size() - 1; i >= 0 && flag; i--){
        flag = (selected[i] + 1)/2;
        selected[i] = (selected[i] + 1)%2;
        //cout << "e: " << selected[i] << endl;
    }
    if (flag && i == selected.size()){
        //溢出
        return false;
    }
    return true;
}


void combination_test(){

    Solution s;

    const int elem_size = 4;
    vector<bool> selected(elem_size, false);


    while (s.add_one(selected)){

        for (auto e: selected){
            if (e){
                cout << " 1 ";
            }else{
                cout << " 0 ";
            }
        }
        cout << endl;
    }


}





