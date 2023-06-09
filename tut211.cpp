// Approach 1 O(k) //
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    set<long> window;

    for (int i = 0; i < nums.size(); ++i) {
      if (const auto it =
              window.lower_bound(static_cast<long>(nums[i]) - valueDiff);
          it != cend(window) && *it - nums[i] <= valueDiff)
        return true;
      window.insert(nums[i]);
      if (i >= indexDiff)
        window.erase(nums[i - indexDiff]);
    }

    return false;
  }
};
