//
// Created by Cola on 2023/12/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * queriesSize);
    memset(ans, 0, sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; ++i)
    {
        int cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
        for (int j = 0; j < pointsSize; ++j)
        {
            int px = points[j][0], py = points[j][1];
            if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr)
            {
                ++ans[i];
            }
        }
    }
    *returnSize = queriesSize;
    return ans;
}

int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int slow = 0, fast = 1;
    while(fast < numsSize)
    {
        if(nums[fast] != nums[slow])
        {
            slow = slow + 1;
            nums[slow] = nums[fast];
        }
        fast = fast + 1;
    }
    return slow + 1;
}


int main()
{
//    int points[4][2] = {1,3,3,3,5,3,2,2};
//    int queries[3][3] = {2,3,1,4,3,1,1,1,2};
//
//    int ans[3];

    int shuzu[15] = {2,3,1,1,1,7,7,5,9,9,3,2,2,1,9};

    removeDuplicates(shuzu,15);
    for(int i = 0;i<15;i++)
    {
        printf("%d ",shuzu[i]);
    }
    printf("\n");
}