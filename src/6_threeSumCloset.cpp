/*
 * 6_threeSumCloset.cpp
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4} , and target = 1 .
 * The sum that is closest to the target is 2. ( -1 + 2 + 1 = 2 ).
 *
 * 思路：？
 *
 * a + b + c ~= target  找三个数字他们的和最接近target；
 * 夹逼，绝对值最小
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include "test_main.h"

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int> &num, int target){

        //默认前提，num长度大于3

        sort(num.begin(),num.end());

        int res = 0;
        int min_gap = INT_MAX;
        bool equal_flag = false; //空值循环次数

        for (auto e = num.begin(); !equal_flag && e != prev(num.end(),2); e++){
            auto k = next(e); // 获取迭代器前后位置的函数：prev & next
            auto l = prev(num.end());
            while(k < l){
                int sum = *e + *k + *l; //迭代器访问元素
                int gap = abs(sum - target);
                if(gap < min_gap){
                    min_gap = gap;
                    res = sum;
                }

                if (sum == target){
                    equal_flag = true;//相等情况下，最接近的。不用再找了
                    break;
                }else if(sum < target){
                    k++; //变大点
                }else{
                    l--; //变小点
                }
            }//while
        }//end for

        return res;
    }

};


void three_sum_closest(){

    int arr[] = {-2,-1,-1,0,1,2,2,11,3,3,4,5};
    vector<int> num(arr,arr + 12);
    cout <<"before process" <<endl;
    for(size_t i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;

    Solution s;
    int res = s.threeSumClosest(num,21);
    cout <<"after process" <<endl;
    for(size_t i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;

    cout << "the final res is: " << res <<endl;

}


