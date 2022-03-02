#include<stdio.h>

int main()
{

    int n;
    scanf("%d",&n);
    int arr[n];
    int k = 0;
    for(k ; k<n ; k++)
    {
        scanf("%d",&arr[k]);
    }

    int e;
    scanf("%d",&e);

    int i=0,j=n-1;
    int pivot;
    while(i <= j){
        pivot = i + (j-i)/2;

        if(arr[pivot] == e){
            break;
        }

        else if(arr[pivot]<e)
        {
            i=pivot+1;

        }
        else{
            j=pivot-1;

        }


    }


    if(arr[pivot]==e){
        printf("Present");
    }
    else{
        printf("not found");
    }


}
