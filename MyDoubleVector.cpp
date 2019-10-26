#include "MyDoubleVector.h"
// visual studio 2017
// 소프트웨어학부
// 2016726030 윤병찬

MyDoubleVector::MyDoubleVector(size_t init_capacity)
{
	data = new double[init_capacity];
	vCapacity = init_capacity;
	used = 0;
}
MyDoubleVector::MyDoubleVector(const MyDoubleVector& v)
{
	data = new double[v.vCapacity];
	vCapacity = v.vCapacity;
	used = v.used;
	copy(v.data, v.data + used, data);
}
MyDoubleVector& MyDoubleVector::operator=(const MyDoubleVector& v)
{
	if (this == &v) return *this;
	if (vCapacity != v.vCapacity)
	{
		delete[] data;
		data = new double[v.vCapacity];
		vCapacity = v.vCapacity;
	}
	used = v.used;
	copy(v.data, v.data + used, data);
	return *this;
}

void MyDoubleVector::operator+=(const MyDoubleVector& v)
{
	if (used + v.used > vCapacity)
		reserve(used + v.used);
	copy(v.data, v.data + v.used, data + used);
	used += v.used;
}

double& MyDoubleVector::operator[](size_t idx)
{
	assert(idx>=0 && idx<used);

	return data[idx];
}

MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v)
{
	assert(used == v.used);

	MyDoubleVector temp(*this);
	temp.reserve(used);
	for (int i = 0; i < used; i++)
		temp.data[i] += v.data[i];

	return temp;
}

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector & v)
{
	assert(used == v.used);

	MyDoubleVector temp(*this);
	temp.reserve(used);
	for (int i = 0; i < used; i++)
		temp.data[i] -= v.data[i];

	return temp;
}

double MyDoubleVector::operator*(const MyDoubleVector & v)
{
	assert(used == v.used);

	double result = 0;

	for (int i = 0; i < used; i++)
		result += this->data[i] * v.data[i];

	return result;
}

MyDoubleVector MyDoubleVector::operator-()
{
	MyDoubleVector temp(*this);
	temp.reserve(used);
	for (int i = 0; i < used; i++)
		temp.data[i] *= -1;

	return temp;
}

bool MyDoubleVector::operator==(const MyDoubleVector & v)
{
	assert(used == v.used);

	for (int i = 0; i < used; i++)
		if (this->data[i] != v.data[i]) return false;
	return true;
}

void MyDoubleVector::operator()(double x)
{
	for (int i = 0; i < used; i++)
		this->data[i] = x;
}

void MyDoubleVector::pop_back()
{
	assert(used > 0);

	data[--used] = INT16_MAX;
}

void MyDoubleVector::push_back(double x)
{
	if (used == vCapacity)
		reserve(vCapacity * 2);

	data[used++] = x;
}

size_t MyDoubleVector::capacity() const
{
	return vCapacity;
}

size_t MyDoubleVector::size() const
{
	return used;
}

void MyDoubleVector::reserve(size_t n)
{
	double* larger_array;
	if (n == vCapacity) return;
	if (n < used) n = used;

	larger_array = new double[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	vCapacity = n;
}

bool MyDoubleVector::empty() const
{
	if (used == 0) return true;
	else return false;
}

void MyDoubleVector::clear()
{
	delete[] data;
	data = NULL;
	used = 0;
	vCapacity = 0;
}

MyDoubleVector::~MyDoubleVector()
{
	delete[] data;
}