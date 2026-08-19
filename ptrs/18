#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    long long va = *(const int*)a;
    long long vb = *(const int*)b;
    return (va > vb) - (va < vb);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // 1. Initial configuration and sorting
    *returnSize = 0;
    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate memory for results. Max combinations can be large, use a safe limit.
    int max_results = 2000; 
    int** result = (int**)malloc(max_results * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_results * sizeof(int));

    // 2. First outer loop (First number: i)
    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicate values for the first position
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // 3. Second outer loop (Second number: j)
        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicate values for the second position
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 4. Two-pointer convergence for the remaining two positions
            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                // Use long long to prevent integer overflow during summation
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    // Match found! Allocate and save the quadruplet
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Resize results buffer if we hit the limit
                    if (*returnSize >= max_results) {
                        max_results *= 2;
                        result = (int**)realloc(result, max_results * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, max_results * sizeof(int));
                    }

                    // Move pointers and bypass duplicate entries
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if (sum < target) {
                    left++; // Sum is too small, move left pointer to a larger value
                } 
                else {
                    right--; // Sum is too large, move right pointer to a smaller value
                }
            }
        }
    }

    return result;
}
