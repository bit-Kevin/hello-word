# include <stdio.h>
int main()
{
    int i;
    // ÐÐÊý
    for(i=1;i<=9;i++)
    {
        int j;
        for (j=1 ; j <=i; j++)
        {
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}