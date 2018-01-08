/*
 * 5_3Sum.cpp
 *Given an array S of n integers,are there elements a, b, c in Find all unique triplets in the array which gives the sum of zero（a+b+c=0）
 *Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c) The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4} .
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 *
 *分析：
 *疑问：有时间复杂度要求？空间复杂度？
 *self idea：将S中元素存在hashtable中；利用a+b=-c,顺序取数组中相邻两个元素ab，查询是否存在-(a+b)；找到c后，排下序列；
 *self idea 问题：
 *1、时间：o(n),但空间：o(n)
 *2、取出来数据，需要排序，还得去重
 *
 *reference idea：排序，左右夹逼，同时去重； 时间复杂度o(n^2)
 * -c = a+b
 *
 *(-2,-1,-1,0,1,2,2,3,3,4,5)
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

#include "test_main.h"

using namespace std;
class Solution{

public:
    vector<vector<int> > threeSum(vector<int> &vec){

        vector<vector<int> >res;

        if (vec.size() < 3){
            return res;
        }

        sort(vec.begin(),vec.end());//对数组中元素排序，升序排

        for (int i = 0;i < vec.size(); i++){
            int target = -vec[i];

            int front = i+1;
            int end = vec.size() - 1;

            while(front < end){//前，后，夹逼着来找target
                int sum = vec[front] + vec[end];
                if (sum < target){
                    front++;
                }else if(sum > target){
                    end--;
                }else{ //-c = a+b
                    res.emplace_back(vector<int> {vec[i],vec[front],vec[end]});
                    //使用emplace_back比push_back快：20ms左右，从23%-》65%
                    //res.push_back({vec[i],vec[front],vec[end]});
                    while(vec[++front] == vec[front - 1]);//去掉重复的 a
                    while(vec[--end] == vec[end + 1]); //去掉重复的 b
                }
            }//end while
            while(vec[i] == vec[i + 1]) i++;//去掉重复的c
        }//end for

        return res;

    }//end threeSum
};


void three_sum(){

    int arr[] = {-2,-1,-1,0,1,2,2,11,3,3,4,5};
    vector<int> num(arr,arr + 12);
    cout <<"before process" <<endl;
    for(size_t i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;

    Solution s;
    vector<vector<int> > res = s.threeSum(num);
    cout <<"after process" <<endl;
    for(size_t i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;

    cout << "the final res is: " <<endl;
    for(auto i = 0; i < res.size(); i++){
        for(size_t j = 0;j < res[i].size(); j++){
            cout <<res[i][j]<<" ";
        }
        cout << endl;
    }

    cout << endl;

}







