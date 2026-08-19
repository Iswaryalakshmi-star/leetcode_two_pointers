#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be MALCOFFED/allocated.
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Estimate initial capacity for the result array
    int capacity = 16;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // If the lowest number is greater than 0, no triplet can sum to 0
        if (nums[i] > 0) {
            break;
        }
        
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Expand result capacity if needed
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res, capacity * sizeof(int*));
                }
                
                // Allocate and store the matched triplet
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnSize)++;
                
                left++;
                right--;
                
                // Skip duplicates for the second element
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                // Skip duplicates for the third element
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    
    // Set the column sizes for each returned triplet (always 3)
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    
    return res;
}
