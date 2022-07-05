#include <iostream>
#include <cstring>
 
template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};
 
public:
	T* getArray() { return m_array; }
 
	T& operator[](int index)
	{
		return m_array[index];
	}
};
 
template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}
 
int main()
{
	// declare an int array
	StaticArray<int, 4> int4{};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;
 
	// Print the array
	print(int4);
 
	return 0;
}