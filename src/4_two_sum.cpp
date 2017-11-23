/*
 * problems:
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output:index1=1, index2=2
 *
 *解析思路：
 *1、o(n^2)的好想
 *2、？有没有更少复杂度？o(n)
 *  关键就是c++标准库hashmap的使用：unordered_map
 */

#include <vector>
#include  <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        //返回索引位置
        vector<int> res;
        unordered_map<int, int> num_index_map;
        for (size_t i = 0 ;i < nums.size(); i++){
            num_index_map[nums[i]] = i+1;
        }

        for (size_t i = 0;i< nums.size(); i++){
            //unordered_map<int ,int>::const_iterator it = num_index_map.find(target - nums[i]);
            auto it = num_index_map.find(target - nums[i]); //使用下c11的自动化变量
            if (it != num_index_map.end() && it->second > (i+1)){
                res.push_back(i+1);
                res.push_back(it->second);
            }
        }//end for
        return res;
    }

};


void two_sum(){

    vector<int> data;

    data.push_back(23);
    data.push_back(1);
    data.push_back(4);
    data.push_back(6);
    data.push_back(8);

    data.push_back(3454);

    Solution s;
    vector<int> res = s.twoSum(data, 24);

    for(auto e:res){
        cout << e << " ";
    }

    cout <<endl;


}

