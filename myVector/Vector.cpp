#include "Vector.h"

/*CONSTRUCTORS*/
Vector::Vector()
{
	arr = new int[cap];
}
Vector::Vector(unsigned int cap)
{
	this->cap = cap;
	arr = new int[cap];
}
Vector::Vector(const Vector& other)
{
	Clone(other);
}

/*PRIVATE*/
void Vector::EnsureCapacity(int value)
{
	while (true)
	{
		if (value > cap)
		{
			cap *= 1.5 + 1;

			int* tmp = new int[cap];
			for (int i = 0; i < size; i++)
				tmp[i] = arr[i];

			delete[] arr;
			arr = tmp;
		}
		else
			return;
	}
}
void Vector::val_swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Vector::QuickSortAlgorithm(int* arr, int start, int pivot)
{
	if (start < pivot)
	{
		int new_pivot = QuickSortPartition(arr, start, pivot);

		QuickSortAlgorithm(arr, start, new_pivot - 1);
		QuickSortAlgorithm(arr, new_pivot + 1, pivot);
	}
}
int Vector::QuickSortPartition(int* arr, int start, int pivot)
{
	int low = start - 1;
	int high = pivot - 1;

	for (int j = start; j <= high; j++)
	{
		if (arr[j] <= arr[pivot])
		{
			low++;
			val_swap(&arr[low], &arr[j]);
		}
	}

	val_swap(&arr[low + 1], &arr[pivot]);

	return low + 1;
}

/*METHODS*/
const void Vector::Print() const
{
	for (int i = 0; i < size; i++)
		printf("%d: %d\n", i + 1, arr[i]);
}
void Vector::PushBack(int num)
{
	Insert(num, size);
}
void Vector::PushFront(int num)
{
	Insert(num, 0);
}
void Vector::Insert(int num, int index)
{
	if (index > size || index < 0)
		return;

	size++;
	EnsureCapacity(size);
	
	for (int i = size - 1; i >= index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = num;
}
void Vector::RemoveAt(int index)
{
	if (index > size || index < 0 || size == 0)
		return;

	for (int i = index; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
}
void Vector::Remove(int num)
{
	int tmpsize = size;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != num)
		{
			arr[j] = arr[i];
			j++;
		}
		else
		{
			tmpsize--;
		}
	}

	size = tmpsize;
}
void Vector::PopFront()
{
	RemoveAt(0);
}
void Vector::PopBack()
{
	RemoveAt(size);
}
void Vector::Clear()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
	size = 0;
}
void Vector::TrimToSize()
{
	int* tmparr = new int[size];
	for (int i = 0; i < size; i++)
		tmparr[i] = arr[i];

	delete[] arr;
	arr = tmparr;
	cap = size;
}
void Vector::Reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - i - 1]);
	}
}
void Vector::SortAsc()
{
	int start = 0;
	int pivot = size - 1;
	QuickSortAlgorithm(arr, start, pivot);
}
void Vector::SortDesc()
{
	SortAsc();
	Reverse();
}
void Vector::Shuffle()
{
	for (int i = 0; i < size; i++)
	{
		swap(arr[i], arr[rand() % size]);
	}
}
void Vector::RandomFill()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 199;
	}
}
void Vector::Clone(const Vector& other)
{
	delete[] arr;
	size = other.size;
	cap = other.cap;

	arr = new int[cap];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

const int Vector::IndexOf(int num) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}
const int Vector::LastIndexOf(int num) const
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}

const bool Vector::isEmpty() const
{
	return !size;
}
const bool Vector::Equals(const Vector& other) const
{
	if (size != other.size)
		return false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] != other.arr[i])
			return false;
	}
	return true;
}
const int Vector::GetElementAt(int index) const
{
	if (index > size || index < 0 || size == 0)
		return -1;

	return arr[index];
}

/*OPERATORS*/
ostream& operator<<(ostream& output, const Vector& src)
{
	src.Print();
	return output;
}
istream& operator>>(istream& input, Vector& src)
{
	int num;
	input >> num;
	src.PushBack(num);
	return input;
}
Vector& Vector::operator=(const Vector& other)
{
	Clone(other);
	return *this;
}
int Vector::operator[](int index)
{
	return GetElementAt(index);
}
bool Vector::operator==(const Vector& other)
{
	return other.Equals(other);
}

/*DEST-GET-SET*/
Vector::~Vector()
{
	if (arr != nullptr) { delete[] arr; }
}

const int Vector::GetSize() const
{
	return size;
}
const int Vector::GetCap() const
{
	return cap;
}
void Vector::SetElement(int num, int index)
{
	if (index < 0 || index > size)
		return;
	arr[index] = num;
}
void Vector::SetCap(unsigned int cap)
{
	this->cap = cap;
}