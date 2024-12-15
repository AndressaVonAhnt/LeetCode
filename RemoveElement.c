void ShiftLeft(int *arr, int size){
    if (size <= 1) 
        return;

    for (int i = 0; i < size - 1; i++) 
        arr[i] = arr[i + 1];
}

int removeElement(int* nums, int numsSize, int val) {
    int k = numsSize;

    for(int i = 0; i < k;){
        if(nums[i] == val){
            k--;
            ShiftLeft(&nums[i], k - i + 1);

        }else
            i++;
    }
    return k;
}
