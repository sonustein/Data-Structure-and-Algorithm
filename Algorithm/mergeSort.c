#include <stdio.h>
#include <stdlib.h>
int array[5000];
static int count;
void merge(int a[], int l, int m, int h)
{   // merge algorithm
    count++;
    int i, j, k = l;
    i = l;
    j = m + 1;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            array[k++] = a[i++];
        else
            array[k++] = a[j++];
    }
    if (j > h)
    {
        while (i <= m)
        {
            array[k++] = a[i++];
        }
    }
    else
    {
        while (j <= h)
        {
            array[k++] = a[j++];
        }
    }
    for (int m = l; m <= h; m++)
    {
        a[m] = array[m];
    }
}
void mergeSort(int a[],int left, int right){
    count++;
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid); //sorting first half 
        mergeSort(a,mid+1,right);//sorting second half 
        merge(a,left,mid,right);//merging both half and sorting completed 
    }
}
int main()
{
    // int arr[]={38,27,43,3,9,82,10};
    int len;
    scanf("%d",&len);
    int *arr=(int*)malloc(sizeof(int)*len);
    for(int j=0;j<len;j++){
        scanf("%d",&arr[j]);
    }
    mergeSort(arr,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("number of steps  %d",count);
    return 0;
}

// note: - space complexity is O(n) auxilary
//         and time complexity is O(nlogn)