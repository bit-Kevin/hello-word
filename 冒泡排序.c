#include <stdio.h>
int main()
{
    int arr[5];
    int i, j, p, temp; //i循环的轮数 j比较的次数 p输入次数 temp零时变量
    printf("请输入5个数：\n");
    for (p = 0; p < 5; p++)
    { //输入
        scanf("%d", &arr[p]);
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            { //比较大小，小在前
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("结果：");
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}