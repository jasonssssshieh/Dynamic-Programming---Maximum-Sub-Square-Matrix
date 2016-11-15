//
//  main.cpp
//  Dynamic Programming - Maximum Sub Square Matrix
//
//  Created by Zijian Xie on 2016/11/14.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MaxSubSqr{
private:
    vector<vector<int>> nums;
public:
    MaxSubSqr(vector<vector<int>>& nums){
        this->nums = nums;
    }
    
    int DP(){
        int m = (int)nums.size();
        int n = (int)nums[0].size();
        vector<int> pre(n+1,0);
        for(int i = 1; i <= m; ++i){
            vector<int> cur(n+1,0);
            for(int j = 1; j <= n; ++j){
                if(nums[i-1][j-1] != 0){
                    cur[j] = min(cur[j-1], min(pre[j-1], pre[j])) + 1;
                }
            }
            pre = cur;
        }
        cout<<"max side length is: "<<pre[n]<<endl;
        cout<<"max square area is: "<<pre[n]*pre[n]<<endl;
        return pre[n];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> nums = {{0,0,1,1,1},{1,0,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};
    MaxSubSqr* test = new MaxSubSqr(nums);
    test->DP();
    return 0;
}
