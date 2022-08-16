#include <stdio.h>
int min(int start, int end, int* arr){
    int _min = arr[end];
    int index = end;
    for(int i=end-1; i>=start; --i){
        if(arr[i] < _min){
            _min = arr[i];
            index = i;
        }
    }
    return index;
}

int max(int start, int end, int* arr){
    int _max = arr[start];
    int index = start;
    for(int i=start; i<=end; ++i){
        if(arr[i] > _max){
            _max = arr[i];
            index = i;
        }
    }
    return index;
}
int isAllSame(int start, int end, int* arr){
    for(int i=start; i<end; ++i){
        if(arr[i] != arr[i+1]) return 0;
    }
    return 1;
}
int maxChunksToSorted(int* arr, int arrSize){
    int index = 0;
    int ans = 0;
    while(index < arrSize){
        //pair p = min_max(0, arrSize-1, arr);
        int min_index = min(index, arrSize-1, arr);
        int max_index = max(index, min_index, arr);
        if(isAllSame(index, min_index, arr)) min_index = index;
        if(index != min_index && min_index != max_index){
            index = arrSize-1;
            while(index > min_index && arr[index] > arr[max_index]) --index;
            if(arr[index] == arr[max_index]) --index;
        }
        ++index;
        printf("%d\n", index);
        ++ans;
    }
    return ans;
}

int main(){
    // int arr[] = {2,1,3,4,4};
    int arr[] = {0,3,0,3,2};
    printf("%d\n", maxChunksToSorted(arr, sizeof(arr)/sizeof(int)));
}
