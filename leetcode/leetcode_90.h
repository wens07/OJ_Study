//
// Created by qiang weng on 2018/7/22.
//

#ifndef LEARN_CPP_LEETCODE_90_H
#define LEARN_CPP_LEETCODE_90_H

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {

        auto len = nums.size();
        auto cloest = numeric_limits<int>::max();

        for (auto i = 0; i < len - 2; ++i) {

            for (auto j = i + 1; j < len - 1; ++j) {

                for (auto k = j + 1; k < len; ++k) {

                    auto sum = nums[i] + nums[j] +  nums[k];

                    if (sum == target)
                        return sum;
                    else {
                        if (std::abs(target - sum) < std::abs(cloest) )
                            cloest = target - sum;
                    }



                }

            }

        }

        return target  - cloest;


    }
};


#endif //LEARN_CPP_LEETCODE_90_H
