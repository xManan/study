#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int min;
    int max;
} Pair;

Pair* findMinAndMax(int s, int e, int arr[]){
    if(s==e) return new Pair({arr[s],arr[e]});
    if(s+1==e){
        int min_ = min(arr[s], arr[e]); 
        int max_ = max(arr[s], arr[e]);
        return new Pair({min_,max_});
    }
    Pair *first_pair=findMinAndMax(s,(s+e)/2,arr); 
    Pair *second_pair=findMinAndMax(((s+e)/2)+1,e,arr);
    int min_=min(first_pair->min, second_pair->min);
    int max_=max(first_pair->max, second_pair->max);
    delete first_pair;
    delete second_pair;
    return new Pair({min_,max_});
}

int main(){
    //int arr[] = {4,7,2,5,1,3,6,9,8}; 
    int arr[] = {56,2323,1223,123,676546,323,12,656,333,9090,1231,45343,231254,14131,4454,11,4545,31412,13123}; 
    int n = sizeof(arr)/sizeof(int);
    Pair *p = findMinAndMax(0,n-1,arr);
    cout << "min: " << p->min << " max: " << p->max << endl;
}
