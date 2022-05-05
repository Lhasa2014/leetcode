#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res(n+1, first);
        for (int i = 0; i < n; ++i) {
            res[i+1] = res[i] ^ encoded[i];
        }
        return res;
    }
};