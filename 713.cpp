#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int start = 0, cur = 0, end = nums.size();
        int mul = 1;
        while (cur < end) {
            if (nums[cur] >= k) {
                // int tmp = 0;
                for (int i = 1; i <= cur-start; ++i) {
                    // tmp += i;
                    res += i;
                }
                // res += tmp;
                start = cur + 1;
                mul = 1;
            } else {
                mul *= nums[cur];
                while (mul >= k) {
                    mul /= nums[start];
                    res += cur - start;
                    start++;
                }
            }
            cur++;
        }
        for (int i = 1; i <= cur-start; ++i) {
            res += i;
        }
        return res;
    }
};