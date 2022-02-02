#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	int cap = 10;
	int size = 0;
	int* arr;

	void EnsureCapacity(int value);
	void val_swap(int* a, int* b);
	void QuickSortAlgorithm(int* arr, int start, int pivot);
	int QuickSortPartition(int* arr, int start, int pivot);

public:
	/*CONSTRUCTORS*/
	Vector();
	Vector(unsigned int cap);
	Vector(const Vector& other);

	/*METHODS*/
	const void Print() const;
	void PushBack(int num);
	void PushFront(int num);
	void Insert(int num, int index);
	void RemoveAt(int index);
	void Remove(int num);
	void PopFront();
	void PopBack();
	void Clear();
	void TrimToSize();
	void Reverse();
	void SortAsc();
	void SortDesc();
	void Shuffle();
	void RandomFill();
	void Clone(const Vector& other);

	const int IndexOf(int num) const;
	const int LastIndexOf(int num) const;
	const int GetElementAt(int index) const;

	const bool isEmpty() const;
	const bool Equals(const Vector& other) const;

	/*OPERATORS*/
	friend ostream& operator<<(ostream& output, const Vector& src);
	friend istream& operator>>(istream& input, Vector& src);
	Vector& operator=(const Vector& other);
	int operator[](int index);
	bool operator==(const Vector& other);

	/*DEST-GET-SET*/
	~Vector();

	const int GetSize() const;
	const int GetCap() const;
	void SetElement(int num, int index);
	void SetCap(unsigned int cap);
};