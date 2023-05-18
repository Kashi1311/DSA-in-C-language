#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); ++i) {
      if (!seen.insert(nums[i]).second)
        return true;
      if (i >= k)
        seen.erase(nums[i - k]);
    }

    return false;
  }
};
