#include <stdlib.h>
#include <math.h>

// Comparison function needed for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // 1. Sort the array to enable the two-pointer technique
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize the closest sum with the first possible triplet
    int closest_sum = nums[0] + nums[1] + nums[2];

    // 2. Loop through the array, fixing the first element at index i
    for (int i = 0; i < numsSize - 2; i++) {
        // Initialize the two pointers for the remaining window
        int left = i + 1;
        int right = numsSize - 1;

        // 3. Converge pointers from opposite ends
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];

            // If we found a perfect match, return it immediately
            if (current_sum == target) {
                return current_sum;
            }

            // Update closest_sum if the current triplet is closer to the target
            if (abs(current_sum - target) < abs(closest_sum - target)) {
                closest_sum = current_sum;
            }

            // Move pointers based on how the sum compares to the target
            if (current_sum < target) {
                left++;  // Needs a larger sum
            } else {
                right--; // Needs a smaller sum
            }
        }
    }

    return closest_sum;
}
