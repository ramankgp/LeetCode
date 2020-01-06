// Time: O(n ^ 2)
// Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0, n = s.size();
        for (int i = 0; i < n;) {
            if (n - i <= len / 2)
                break;
            
            int l = i, r = i;
            while (r + 1 < n && s[r] == s[r + 1])
                ++r;
            
            i = r + 1;
            
            do {
                --l;
                ++r;
            } while (l >= 0 && r < n && s[l] == s[r]);
            
            if (r - l  - 1 > len) {
                start = l + 1;
                len = r - l - 1;
            }
        }
        return s.substr(start, len);
    }
};
