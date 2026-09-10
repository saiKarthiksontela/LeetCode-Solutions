/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    
    int arr1[numsSize];
    int arr2[numsSize];
    int last_arr1 = 0;
    int last_arr2 = 0;
    int pos = 0;
    *returnSize = numsSize;
    
    int* result = (int*)malloc(numsSize*sizeof(int));

    arr1[0] = nums[0];
    arr2[0] = nums[1];

    for(int i=2;i<numsSize;i++){

        if(arr1[last_arr1] > arr2[last_arr2]){
            last_arr1++;
            arr1[last_arr1] = nums[i];
        }
        else{
            last_arr2++;
            arr2[last_arr2] = nums[i];
        }
    }

    for(int i = 0;i <=last_arr1; i++){
        result[pos] = arr1[i];
        pos++;
    }

    for(int i = 0;i<=last_arr2; i++){
        result[pos] = arr2[i];
        pos++;
    }


    return result;
}