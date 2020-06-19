#include <iostream>

std::string longestPalindrome(std::string s) {
    int len = s.length();
    if (len <= 1) {
        return s;
    }
    int core = 0;
    int min = 0, max = 0;
    int left, right;
    while (core < len - 1) {

        left = right = core;

        while (right + 1 < s.length() && s[core] == s[right + 1]) {
            right++;
        }
        core = (left + right) / 2 + 1;

        while (left - 1 >= 0 && right + 1 < len) {
            if (s[left - 1] == s[right + 1]) {
                left--;
                right++;
            } else {
                break;
            }
        }
        if (right - left > max - min) {
            min = left;
            max = right;
        }
    }
    return s.substr(min, max - min + 1);
}

int main() {
    std::cout << longestPalindrome("abcba") << std::endl;
    return 0;
}
