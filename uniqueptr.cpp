#include <iostream>
#include <memory>

class Resource
{
public:
    Resource();
    friend std::ostream& operator<<(std::ostream &out, Resource &res);
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
std::ostream& operator<<(std::ostream &out, Resource &res)
{
    out << "I am in print" << std::endl;
    return out;
}


void useResource(std::unique_ptr<Resource> &ptr)
{
    std::cout << *ptr << std::endl;
}


int main()
{
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    std::shared_ptr<Resource> res2 = std::make_shared<Resource>();
    auto res3 = res2;
    useResource(res);
    return 0;
}