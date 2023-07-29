class Solution {
public:
    //以s[left]和s[right]为回文中心去寻找最长的回文字符串
    pair<int, int> expandAroundCenter(const string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    //中心扩展算法
    string longestPalindrome(string s){
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i){
            //回文字符串是奇数个字符
            auto [left1, right1] = expandAroundCenter(s, i, i);
            //回文字符串是偶数个字符
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            //更新最长回文子串的起始位置
            if(right1 - left1 > end - start){
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start){
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
