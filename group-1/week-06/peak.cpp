class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l + 1 < r) {
            int m1 = l + (r - l) / 3;
            int m2 = l + (r - l) * 2 / 3;
            if (arr[m1] < arr[m2]) l = m1 + 1;
            else r = m2;
        }
        if (l == r) return l;
        if (arr[l] > arr[r]) return l;
        return r;
    }
};
