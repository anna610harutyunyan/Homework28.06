#include <iostream>
#include <exception>
class Array
{
	int* ptr = nullptr;
public:
	int size;

	Array(int size)
	{
		this->size = size;
		ptr = new int[size];
		std::cout <<__func__ << std::endl;
	}

	Array(const Array& other)
	{
		this->size = other.size;
		this->ptr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << "Copy" <<__func__ << std::endl;

	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->size = other.size;
		delete[] this->ptr;
		this->ptr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << __func__ << std::endl;

		return *this;

	}

	
	int& at(int index)
	{
		std::cout << __func__ << std::endl;

		if (index<0 || index >size)
		{
			std::cerr << "Index is out of the range!!! \n";
		}
		return ptr[index];
	}
	~Array()
	{
		delete[] ptr;
		ptr = nullptr;
		std::cout << __func__ << std::endl;

	}

	int get_element(int index)
	{
		if (index >= size || index < 0)
		{
			std::cerr << "Error!! Index is out of size boundaries \n";
		}

		return  ptr[index];
	}
};

int main(int argc, char** argv)
{
	Array array1(7);
	std::cout << "5th element in array is " << array1.get_element(5);
	Array array2(array1);
	Array array3(4);
	array1.size = 15;
	array1.at(25);





	return 0;
}