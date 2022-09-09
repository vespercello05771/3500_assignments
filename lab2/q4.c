#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int arr[] = {98,57,49,1,5,7,4,3,1,2,13};
#define N 11
#define n 3// number of subthreads
#define element 7

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void merge(int low, int mid, int high)
{
    int left[mid - low + 1];
    int right[high - mid];

    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = arr[i + low];

    for (i = 0; i < n2; i++)
        right[i] = arr[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void *routine(void *arg)
{
    int c = *(int *)arg;

    if (c == 0)
    {

        int i, j, min_idx;

       
        for (i = 0; i < N/2; i++)
        {

            min_idx = i;
            for (j = i + 1; j < N/2; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            if (min_idx != i)
                swap(&arr[min_idx], &arr[i]);
        }
        
    }
    if (c == 1)
    {
        int i, j, min_idx;
    
        for (i = N/2 ; i < N; i++)
        {

            min_idx = i;
            for (j = i + 1; j < N; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            if (min_idx != i)
                swap(&arr[min_idx], &arr[i]);
        }

    }
    if (c == 2)
    {
        
        merge(0,N/2 -1,N-1);
    }

    free(arg);
}
void* routine2(void *arg){
    int c = *(int *)arg;
    int sizee;
    if(N%n == 0){
        sizee = N/n;
    }
    else{
        sizee = N/n + 1;
    }
    int* cnt = malloc(sizeof(int));
    int count = 0;
    for(int i = (c-1)*sizee;i<c*sizee && i<N;i++){
        if(arr[i]%element == 0){
            count++;
        }
    }
    printf("count in thread %d is %d\n",c,count);
    *cnt = count;
    free(arg);
    return (void*) cnt;
}
// Driver Code
int main()
{

    pthread_t threads[3];

    for (int i = 0; i < 3; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;

        if (pthread_create(&threads[i], NULL, &routine, a) != 0)
        {
            perror("Failed to create a thread");
        }
    }
    // join 3 threads
    for (int i = 0; i < 3; i++)
    {
        if(pthread_join(threads[i], NULL)!=0){
            perror("Failed to join threads");
        }
    }
    // displaying sorted array

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);


    printf("\n");
    int count  = 0;
    pthread_t threads2[n];
    for(int i = 0;i<n;i++){
        int *a = malloc(sizeof(int));
        *a = i+1;

        if (pthread_create(&threads2[i], NULL, &routine2, a) != 0)
        {
            perror("Failed to create a thread\n");
        }

    }
    for (int i =0; i < n; i++)
    {
        int* res;
        if(pthread_join(threads2[i],(void**) &res)!=0){
            perror("failed to join thread\n");
        }
        count+=*res;
    }
    printf("total count is %d\n",count);
    return 0;
}