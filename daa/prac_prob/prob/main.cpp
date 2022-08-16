#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> myvector){
    for (auto it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';}
int main ()
{
  vector<int> v1 = vector<int>();
  vector<int> v2 = {1,2,3,45,34};
  v1.insert(v1.begin(),v2.begin()+1, v2.end()-1);
  printVector(v1);
  
  return 0;
}
