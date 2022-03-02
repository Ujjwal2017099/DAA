#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while(t!=0)
    {

        int n;
        scanf("%d",&n);

        int arr[n];
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&arr[i]);
        }

        int key;
        scanf("%d",&key);

        int i=0;
        while(key != arr[i] && i<n)
        {
            i++;
        }

        if(arr[i] == key)
        {
            printf("Present %d",(i+1));
        }
        else
        {
            printf("Not found %d",(i));
        }


        --t;
    }
}
