#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct interval{
    int l;
    int r;
} interval;

int main(){
    ifstream inp_file("input");
    int t;
    if(!inp_file.is_open()){
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    inp_file >> t;
    // cout << t << '\n';
    while(t--){
        int n,m;
        inp_file >> n >> m;
        // cout << n << ' ' << m << '\n'; 
        interval intervals[n];
        for(int i=0; i<n; ++i){
            interval tmp;
            inp_file >> tmp.l >> tmp.r;
            intervals[i] = tmp;
            // cout << intervals[i].l << ' ' << intervals[i].r << '\n';
        }
        for(int i=0; i<m; ++i){
            int p;
            inp_file >> p;
            bool flag = false;
            int closest = 1000000001;
            for(int j=0; j<n; ++j){
                if(p >= intervals[j].l && p < intervals[j].r){
                    cout << 0 << '\n';
                    flag = true;
                    break;
                }
                if(p < intervals[j].l && intervals[j].l < closest){
                    closest = intervals[j].l;
                }
            }
            if(flag) continue;
            if(closest == 1000000001){
                cout << -1 << '\n';
            }
            else {
                cout << closest-p << '\n';
            }
            // cout << p << '\n';
        }
    }
    inp_file.close();
    return 0;
}

