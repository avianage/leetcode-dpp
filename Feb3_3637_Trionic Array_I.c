// Problem Link:
// https://leetcode.com/problems/trionic-array-i/description/ (Easy Question)

#include<stdlib.h>
#include <stdbool.h>

bool isTrionic(int* nums, int numsSize) {
    if (numsSize < 4){
        return false;
    }
    else{
        int p = -1, q = -1;
        int i = 0;
        int j = 0;
        for (j; j < numsSize-1; j++){
            if (nums[j] == nums[j+1]){
                return false;
            }
        }
        for (i; i < numsSize-1; i++){
            if ((nums[i] < nums[i+1]) && (p == -1) && (q == -1)){
                continue;
            }
            if (nums[i] > nums[i+1] && (p == -1) && (q == -1)){
                p = i;
            }
            if (nums[i] > nums[i+1] && (p != -1) && q == -1){
                continue;
            }
            if (nums[i] < nums[i+1] && (p != -1) && q == -1){
                if( i > p){
                    q = i;
                }
                else{
                    break;
                }
            }
            if (nums[i] < nums[i+1] && (p != -1) && (q != -1)){
                continue;
            }
            if (nums[i] > nums[i+1] && (p != -1) && (q != -1)){
                break;
            }
        }
        if ((p != -1) && (q != -1) && (p && q) && (i == numsSize-1)){
            return true;
        }
        else {
            return false;
        }
    }    
}

// Leetcode Solution:

// bool isTrionic(int* nums, int numsSize) {
//     if (nums[0] >= nums[1]) {
//         return false;
//     }
//     int count = 1;
//     for (int i = 2; i < numsSize; i++) {
//         if (nums[i - 1] == nums[i]) {
//             return false;
//         }
//         if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
//             count++;
//         }
//     }
//     return count == 3;
// }


// Note to self:
// Solved via jugad. Need to use concepts learnt and simplify the solution