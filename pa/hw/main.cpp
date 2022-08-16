#include<iostream>

using namespace  std;

template<class T>
void printArr(T arr[], int size){
    cout << "\nArray = { ";
    for(int i=0; i<size; ++i){
        cout << arr[i];
        if(i!=size-1) cout << ", ";
    } 
    cout << " }\n";
}

template<class T>
int searchArr(T arr[], int size, T ele){
    for(int i=0; i<size; ++i){
        if(ele == arr[i])
            return i;
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the numbers of elements: ";
    cin >> n;
    const int size = n;
    double arr[size];
    for(int i=0; i<size; ++i) arr[i]=0;
    int curr_size = 0;

    enum arrayOperation{exit,traverse,insert,search,del};

    do{
        int opt;
        cout << "\nChoose any of the followings options:\n";
        cout << "1. Traverse array\n";
        cout << "2. Insert at a location\n";
        cout << "3. Search element\n";
        cout << "4. Delete element\n";
        cout << "0. Exit\n";
        cout << "\nEnter an option number: ";
        cin >> opt;

        switch(opt){
            case traverse:
                printArr<double>(arr,curr_size);
                break;

            case insert:
            {
                double ele;
                cout << "Enter the element: ";
                cin >> ele;
                int at;
                cout << "at ? ";
                cin >> at; // index
                if(at < 0 || at >= size){
                    cout << "\nErr: Index out of bounds!\n";
                    break;
                }
                if(at >= curr_size){
                    arr[at] = ele;
                    curr_size = at+1;
                }
                else{
                    double tmp = arr[curr_size-1];
                    for(int i=curr_size-2; i>=at; --i){
                        arr[i+1] = arr[i];
                    }
                    arr[at] = ele;
                    if(curr_size < size)
                        arr[curr_size++] = tmp;
                }
                break;
            }
            case search:
            {
                double ele;
                cout << "\nEnter an element to search for: ";
                cin >> ele;
                int index = searchArr<double>(arr, curr_size, ele);
                if(index == -1){
                    cout << "\nElement not found!\n";
                }
                else{
                    cout << "\nIndex of " << ele << " is " << index << '\n';
                }
                break;
            }
            case del:
            {
                if(curr_size == 0){
                    cout << "\nNo elements to delete!\n";
                }
                double ele;
                cout << "Enter the element to delete: ";
                cin >> ele;
                int index = searchArr<double>(arr, curr_size, ele);
                //cout << index <<endl;
                if(index == -1){
                    cout << "\nElement not found!\n";
                    break;
                }
                if(index == curr_size-1) --curr_size;
                for(int i=index; i<curr_size-1; ++i){
                    arr[index] = arr[index+1];
                }
                --curr_size;
                break;
            }
            case exit:
                return 0;
                break;

            default:
                cout << "Enter a valid option!\n";
        }

    }while(1);
}

