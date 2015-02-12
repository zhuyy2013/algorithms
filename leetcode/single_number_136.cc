//Given an array of integers, every element appears twice except for one. Find that single one.

class Solution {
public:
    int singleNumber(int A[], int n) {
        int value;
        for (int i = 0; i < n; ++i) value ^= A[i];
        return value;
    }
};
