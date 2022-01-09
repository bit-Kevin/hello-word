#include <string.h>
#include <stdio.h>
int my_strlen(char *p)
{
    if (*p != '\0')
    {
        return 1 + my_strlen(p + 1);
    }
    else
        return 0;
}
int main()
{
    char arr[] = "bit-kevin" ;
    printf("×Ö·û´®³¤¶ÈÎª£º%d", my_strlen(arr));
    return 0;
}