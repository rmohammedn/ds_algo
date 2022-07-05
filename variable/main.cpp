//#include"second.h"
//#include"first.h"
#include<iostream>
#include<vector>
#include<typeinfo>

std::vector<int> checkReturn()
{
    std::vector<int> vec(10);
    for (int i=0; i<10; i++)
        vec[i] = i;
    return vec;
}
struct Node
{
    int x;
    Node(int num):x(num){std::cout << x << "in constructor" << std::endl;}
};

class Default
{
    public:
    int x{10};
    Node y{3};
    Default(int val){}
    Default(){std::cout << "in side" << std::endl;}
};

int main()
{
    int x{1};
    int y{0};
    int sum = x+y;
    //std::cout << add(x, y) << std::endl;
    //std::cout << getMg(10) << std::endl;
    std::vector<int> vec{checkReturn()};
    std::vector<int> vec2;
    vec2 = vec;
    vec2[2] = 10;
    Default obj();
    //std::cout << obj.x << std::endl;
    //std::cout<< std::size(vec) << std::endl;
    return 0;
}