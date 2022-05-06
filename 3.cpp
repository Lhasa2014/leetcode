class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int start = 0;
        int last = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto it = um.find(s[i]);
            if (it != um.end()) {
                ans = max(ans, i-start);
                //cout<<it->second<<endl;
                start = max(it->second+1,last);
                last = start;
                it->second = i;
            } else {
                um[s[i]] = i;
            }
        }
        //cout<<ans<<" "<<n<<" "<<start<<endl;
        ans = max(ans, n-start);
        return ans;
    }
};