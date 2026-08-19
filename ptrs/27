int removeElement(int* nums, int numsSize, int val) {
    // Tracks the insertion index for elements that are NOT equal to val
    int write_ptr = 0;

    // Scan through the entire array
    for (int read_ptr = 0; read_ptr < numsSize; read_ptr++) {
        // If the current element is a valid number we want to keep
        if (nums[read_ptr] != val) {
            nums[write_ptr] = nums[read_ptr];
            write_ptr++; // Move the write head forward
        }
    }

    // write_ptr naturally tracks the total count of valid elements (k)
    return write_ptr;
}
