#include <stdio.h>
int main()
{
    int arr[5];
    int i, j, p, temp; //iѭ�������� j�ȽϵĴ��� p������� temp��ʱ����
    printf("������5������\n");
    for (p = 0; p < 5; p++)
    { //����
        scanf("%d", &arr[p]);
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            { //�Ƚϴ�С��С��ǰ
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("�����");
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}