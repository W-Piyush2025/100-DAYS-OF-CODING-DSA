#include<stdio.h>
int main()
{
    int n, i;
    //Input number of elements
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);
    int arr[n];
    //Input array elements
    printf("Enter elements in the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int pos;
    //Input position of the element to be deleted
    printf("Enter position of the element to be deleted: ");
    scanf("%d", &pos);
    //Shift elements to the left
    for(i=pos-1; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    //Display the updated array
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}