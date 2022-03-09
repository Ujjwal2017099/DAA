#include <stdio.h>
#include<math.h>

void linearSearch(int arr[],int j,int n,int key)
{

    int i = j;
    while (key != arr[i] && i < n)
    {
        i++;
    }

    if (arr[i] == key)
    {
        printf("Present");
    }
    else
    {
        printf("Not found");
    }

    return;
}

void jumpSearch(int arr[],int n,int key)
{
    int m = sqrt(n);

    int i=0;
    while(i < n)
    {
        if (arr[i] == key)
        {
            /* code */
            printf("found");
            return;
        }
        else if (arr[i] < key)
        {
            /* code */
            if ((i+m) > n)
            {
                /* code */
                linearSearch(arr,i,n,key);
                return;
            }
            else{
                i += m;
            }

            
        }

        else if (arr[i] > key)
        {
            /* code */
            i -= m;
            linearSearch(arr,i,n,key);

            return;
        }
        
        
    }
        printf("not found"); return;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter key to search : ");
    scanf("%d",&key);
    jumpSearch(arr,n,key);
    

}
