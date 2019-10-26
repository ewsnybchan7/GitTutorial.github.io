#pragma once
// visual studio 2017
// ����Ʈ�����к�
// 2016726030 ������
#include <algorithm> // copy �Լ��� ����ϱ� ���� include �Ͽ���
#include <cassert> // assert �Լ��� ����ϱ� ���� include �Ͽ���
using namespace std; // std:: �� ��ø� �����ϱ� ���� �����Ͽ���

class MyDoubleVector {
private:
	double* data; // ���� �����͸� �����ϴ� �迭
	size_t used; // ���� ������ ũ��, �ܺο��� ������ 0~used�������� �����ϴ�
	size_t vCapacity; // ���� ������ �뷮, ũ���� �ִ밪�̴�

public:
	static const size_t Default_Capacity = 100; // ����Ʈ capacity

	MyDoubleVector(size_t init_capacity = Default_Capacity); // ����Ʈ ������
	// Precondition: init_capacity > 0�� ������
	// �ʱ� ũ�⸦ ������� �ϱ� ������ 0���� ū ���� ���;� �Ѵ�
	// Postcondition: ���ڷ� ���� capacity�� ���� ��ü�� �����Ѵ�
	// �ʱ� ���ڰ� ���� ���, ����Ʈ capacity�� ��� ����
	// �Է¹��� capacity�� ���� data �迭�� ũ�⸦ ������ ��, �� �޸𸮿� �Ҵ�
	// used=0, capacity=init_capacity�� �ʱ�ȭ��Ų��

	MyDoubleVector(const MyDoubleVector& v); // ���� ������
	// Precondition: �ڱ� �ڽ��� �ƴ� MyDoubleVector ��ü�� ���;� �Ѵ�
	// Postcondition: ���ڷ� ���� v�� ���� �������� ������� ��ü�� �����Ѵ�
	// �Է¹��� v�� ���� capacity�� data �迭�� ũ�⸦ ������ ��, �� �޸𸮿� �Ҵ�
	// data �迭�� �ε����� ���� v�� data������ ������� �� ����� �ʱ�ȭ��Ų��
	// used�� capacity�� ���� v�� used�� capacity�� ���� �ʱ�ȭ��Ų��

	MyDoubleVector& operator=(const MyDoubleVector& v); // ���Կ�����
	// Precondition: MyDoubleVector ��ü�� ���;� �Ѵ�
	// Postcondition: ���ڷ� ���� v�� ���� �������� ��ü�� ����������� ���� �ٲ۴�
	// ���� �ڱ��ڽ��� ���ڷ� ���� ��� �ڱ��ڽ��� ��ȯ�Ѵ�
	// ���� �Ҵ��� data�迭�� ������Ű��, v�� ���� capacity�� data �迭�� ũ�⸦ ����, �� �޸𸮿� �Ҵ�
	// data �迭�� �ε����� ���� v�� data������ ������� �� ����� �ʱ�ȭ��Ų��
	// used�� capacity�� ���� v�� used�� capacity�� ���� �ʱ�ȭ��Ų��
	// ��ȯ���� v������ ���簡 �� �ڱ� �ڽ��� ��ȯ�Ѵ�

	void operator+=(const MyDoubleVector& v); // operator+= / ���̱� ������
	// Precondition: MyDoubleVector ��ü�� ���;� �Ѵ�
	// Postcondition: ���ڷ� ���� v�� ���� ��ü �ڿ� �����δ�
	// ���� ���� ũ��� v�� ũ���� ���� ���� capacity�� Ŭ ��� capacity�� �� ������ �ٲ۴�
	// ���� ũ�⸦ ���� ũ��� v�� ũ���� ������ �ٲ۴�

	double& operator[](size_t idx); // operator[] / �ε��� ������
	// Precondition: 0 <= idx < used(size)�� �������� ���;� �Ѵ�
	// Postcondition: ���ڷ� ���� idx�� data �迭�� �����Ѵ�
	// ������ data�� ���۷����� ��ȯ�Ѵ�

	MyDoubleVector operator+(const MyDoubleVector& v); // operator+ / ���� ������
	// Precondtion: MyDoubleVector ��ü�� ���;� �Ѵ�
	// ���� ��ü�� size�� v�� size�� ���ƾ� �Ѵ�
	// Postcondition: ���ڷ� ���� v�� data ����� ���� ��ü�� data ������ �ε����� ���� ���� ���Ѵ�
	// ���� ���� ���ο� ��ü�� ����� ������ ��, �� ��ü�� ��ȯ�Ѵ�

	MyDoubleVector operator-(const MyDoubleVector& v); // operator- / ���� ������
	// Precondition: MyDoubleVector ��ü�� ���;� �Ѵ�
	// ���� ��ü�� size�� v�� size�� ���ƾ� �Ѵ�
	// Postcondition: ���� ��ü�� data ����� ���ڷ� ���� v�� data ������ �ε����� ���� ���� ����
	// ������ ���� ���ο� ��ü�� ����� ������ ��, �� ��ü�� ��ȯ�Ѵ�

	double operator*(const MyDoubleVector& v); // operator* / ���� ������
	// Precondition: MyDoubleVector ��ü�� ���;� �Ѵ�
	// ���� ��ü�� size�� v�� size�� ���ƾ� �Ѵ�
	// Postcondition: ���� ���Ϳ� v ���͸� ���� ����Ѵ�
	// ������ ���� ��ȯ�Ѵ�

	MyDoubleVector operator-(); // operator- / unary minus operator
	// Precondition: �ڱ� �ڽ��� ��ȣ�� ������Ű�� ������ �Է������� ����
	// Postcondition: ���� ��ü�� ��� data ������ ��ȣ�� ������Ų ���� ���ο� ��ü�� �����Ѵ�
	// �� ��ü�� ��ȯ�Ѵ�

	bool operator==(const MyDoubleVector& v); // operator== / ���� ������
	// Precondition: MyDoubleVector ��ü�� ���;� �Ѵ�
	// ���� ��ü�� size�� v�� size�� ���ƾ� �Ѵ�
	// Postcondition: ���� ��ü�� data ���� ���ڷ� ���� v�� data ���� �ε����� ���� ���Ѵ�
	// �ϳ��� ���� �ٸ� ��� false�� ��ȯ, ��� ���� ���� ��� true�� ��ȯ�Ѵ�

	void operator()(double x); // operator() / �Լ� ȣ�� ������
	// Precondition: double�� �Ǽ��� ���ڷ� �޴´�
	// Postcondition: ���� ��ü�� data ������ size�� �ε������� ���ڷ� ���� �Ǽ��� �ٲ۴�
	// ��ȯ���� ����

	void pop_back(); // pop_back �Լ� / ������ ���� �Լ�
	// Precondition: ���� size�� 0�̶�� ����ϸ� �ȵȴ�
	// size > 0 �� ��쿡�� ����ؾ� �Ѵ�
	// Postcondition: data�� ������ ���� �����ǰ� size�� 1 �����Ѵ�
	// ��ȯ���� ����

	void push_back(double x); // push_back �Լ� / ������ �߰� �Լ�
	// Precondition: double�� �Ǽ��� ���ڷ� �޴´�
	// Postcondition: data�� ������ ��ġ�� ���� �߰��Ѵ�
	// ���� size�� capacity�� ���� �����͸� �� �̻� �߰��� �� ���ٸ� reserve�� �̿��Ͽ� capacity�� �� ��� �ø���
	// size�� 1 �����Ѵ�

	size_t capacity() const; //  capacity get�Լ�
	// Precondition: �Է������� ����
	// Postcondition: ���� ��ü�� capacity ���� ��ȯ�Ѵ�
	// size_t ���̱� ������ capacity>=0�� �����Ѵ�

	size_t size() const; // size get�Լ�
	// Precondition: �Է������� ����
	// Postcondition: ���� ��ü�� size ���� ��ȯ�Ѵ�
	// size_t ���̱� ������ size>=0�� �����Ѵ�

	void reserve(size_t n); // capacity ��ȯ �Լ�
	// Precondition: n >= 0 �� �������� ���;� �Ѵ�
	// Postcondition: ���� ��ü�� capacity ���� ���ڷ� ���� n���� �ٲٰ� data�� ���� ���� n��ŭ �ٲ۴�
	// ���� �Է¹��� n�� size���� ���� ��� ������ �ս��� ������ n�� size�� �ٲ۴�
	// ���� �Է¹��� n�� ���� capacity�� ���� ��� �Լ��� ������
	// ��ȯ���� ����

	bool empty() const; // empty �Լ�
	// Precondition: �Է������� ����
	// Postcondition: ���� ��ü�� data�� ����ִ��� Ȯ���Ѵ�
	// size�� 0�̶��  true�� ��ȯ�ϰ�, �ƴ϶�� false�� ��ȯ�Ѵ�

	void clear(); // �ʱ�ȭ �Լ�
	// Precondition: �Է������� ����
	// Postcondition: ���� ��ü�� data�� delete �ϰ�, NULL�� ����Ű�� �Ѵ�
	// used�� capacity�� 0���� �ʱ�ȭ�Ͽ� �� ���͸� �����
	// ��ȯ���� ����

	~MyDoubleVector(); // �Ҹ���
	// Precondition: �Է�����������
	// Postcondition: ���� ��ü�� �Ҹ�� ��, data�� delete �Ͽ� �����ϰ� �� ������ ������ ��ȯ�Ѵ�
};