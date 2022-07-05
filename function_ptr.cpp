#include<iostream>
#include<vector>
#include<functional>
#include <string.h>

void print(std::string& str)
{
    std::cout<< str << std::endl;
}
int sum(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

using func_ptr = int(*)(int, int);

void doThis(int x, int y, std::function<int(int, int)> func)
{
    std::cout<< func(x, y) << std::endl;
}
void doThat(int x, int y, func_ptr func)
{
    std::cout<< func(x, y) << std::endl;
}

void doSomething(int x, int y, int(*func)(int, int))
{
    std::cout << func(x, y) << std::endl;
}

void* memcpy(void *dst, const void *src, int n)
{
    char *dstc = static_cast<char*>(dst);
    const char *srcc = static_cast<const char*>(src);
    for (int i=0; i<4; i++)
        std::cout << *(srcc++) << ", ";
    if ((srcc != NULL) && (dstc != NULL))
    {
        while(n)
        {
            //std::cout << *srcc << ", ";
            *(dstc++) = *(srcc++);
            n--;
        }
    }
    return dst;
}

void * Memcpy(void* dst, const void* src, unsigned int cnt)
{
    char *pszDest = (char *)dst;
    const char *pszSource =( const char*)src;
    if((pszDest!= NULL) && (pszSource!= NULL))
    {
        while(cnt) //till cnt
        {
            //Copy byte by byte
            *(pszDest++)= *(pszSource++);
            --cnt;
        }
    }
    return dst;
}


int main()
{
    void (*func_ptr)(std::string&) {&print};
    std::string str{"Hi"};
    func_ptr(str);
    int x{9}, y{3};
    doSomething(x, y, sum);
    doThis(x, y, sum);
    doThat(x, y, sub);
    int array[] = {1,2,3,4};
    int arr2[4] = {0,0,0,0};
    Memcpy(arr2, array, 4);
    for (int i=0; i<4; i++)
        std::cout<< arr2[i] ;
    return 0;
}