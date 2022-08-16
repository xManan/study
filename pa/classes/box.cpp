#include<iostream>
using namespace std;

class Square{
    int side;
    public:
        Square(int s1=0)
        {
            side = s1;
        }
        int area() const
        {
            return side*side;
        }
        friend Square compareMax(const Square&, const Square&);
};

Square compareMax(const Square& s1, const Square& s2)
{
    if(s1.area() > s2.area())
    {
        return s1;
    }
    else
    {
        return s2;
    }
}

int main()
{
    Square s1(3);
    Square s2(4);
    s1.area();
    s2.area();
    cout<<"The greater area is "<<(compareMax(s1,s2)).area();
}


