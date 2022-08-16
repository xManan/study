#include <iostream>

using namespace std;

class abc{
	public:
		int x,y;
};

int main(){
	abc a = {2,3};
    cout  << a.x << '\n' << a.y;
}
