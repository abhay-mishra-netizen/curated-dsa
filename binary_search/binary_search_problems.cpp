// ===== Leetcode 4: Median of Two Sorted Arrays =====
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Approach: Merge and sort both arrays, then return the median (brute force)

#include <bits/stdc++.h>
using namespace std;

class MedianSolution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        for (int i = 0; i < nums1.size(); i++) {
            v.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            v.push_back(nums2[i]);
        }

        sort(v.begin(), v.end());
        int n = v.size();

        if (n % 2 != 0) {
            return v[n / 2];
        } else {
            return (v[n / 2] + v[(n / 2) - 1]) / 2.0;
        }
    }
};

// ===== Leetcode 875: Koko Eating Bananas =====
// https://leetcode.com/problems/koko-eating-bananas/
// Approach: Binary search for the minimum eating speed that finishes in <= h hours

class KokoSolution {
public:
    int sum(int mid, vector<int>& v) {
        long long ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += (v[i] + mid - 1) / mid;
            if (ans > INT_MAX) return INT_MAX;
        }
        return ans;
    }

    int finding_k(int maxPile, int h, vector<int>& v) {
        int s = 1, e = maxPile, ans = maxPile;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (sum(mid, v) <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        return finding_k(maxPile, h, piles);
    }
};

// ===== Leetcode 162: Find Peak Element =====
// https://leetcode.com/problems/find-peak-element/
// Approach: Binary search comparing mid and mid+1 to move toward the peak

class PeakElementSolution {
public:
    int easy(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[mid + 1]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }

    int findPeakElement(vector<int>& nums) {
        return easy(nums);
    }
};
