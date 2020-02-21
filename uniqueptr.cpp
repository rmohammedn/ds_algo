#include <iostream>
#include <memory>

class Resource
{
public:
    Resource();
    ~Resource();
};

Resource::Resource()
{
    std::cout << "Resource object allocated" << std::endl;
}

Resource::~Resource()
{
    std::cout << "Resource object deallocated" << std::endl;
}

int main()
{
    std::unique_ptr<Resource> res1{new Resource};
    std::unique_ptr<Resource> res2 = res1;
    return 0;
}