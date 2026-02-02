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
    int pos, x;
    //Input position and element to insert
    printf("Enter position of the element to be inserted: ");
    scanf("%d", &pos);
    printf("Enter element to be inserted: ");
    scanf("%d", &x);
    //Shift elements to the right
    for(i=n-1; i>=pos-1; i--)
    {
        arr[i+1]=arr[i];
    }
    //Insert the element
    arr[pos-1]=x;
    n++;
    //Display the updated array
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}