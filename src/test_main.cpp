/*
 * test_main.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: wangwei69
 */

#include <iostream>
#include "test_main.h"

#include <algorithm>
#include <vector>
//reverse swap

using namespace std;

int main(int argc,char *argv[]){

    cout << "hello leetcode!" <<endl;


    //测试下algorithm中reverse，swap函数的使用
    vector<int> num;
    for (int i = 0; i < 10; i++){
        num.emplace_back(i+1);
    }

    reverse(&num[0],&num[8]);
    swap(num[8],num[9]);

    for(auto e:num){
        cout << e <<" ";
    }

    cout << endl;
//////////////////////////////////////////////////

//    remove_duplicates_sort_array();
//    remove_duplicates_sort_array2();
//    longest_consecutive_sequence();
//    two_sum();
//    three_sum();
//    three_sum_closest();

//    next_permutation_test();


//    rotate_test();

    bsTree_test();

    return 0;


//////////////////////////////////////////////////
}



