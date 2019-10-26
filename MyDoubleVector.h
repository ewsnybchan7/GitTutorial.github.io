#pragma once
// visual studio 2017
// 소프트웨어학부
// 2016726030 윤병찬
#include <algorithm> // copy 함수를 사용하기 위해 include 하였다
#include <cassert> // assert 함수를 사용하기 위해 include 하였다
using namespace std; // std:: 의 명시를 생략하기 위해 기입하였다

class MyDoubleVector {
private:
	double* data; // 실제 데이터를 보관하는 배열
	size_t used; // 현재 벡터의 크기, 외부에서 접근은 0~used전까지만 가능하다
	size_t vCapacity; // 현재 벡터의 용량, 크기의 최대값이다

public:
	static const size_t Default_Capacity = 100; // 디폴트 capacity

	MyDoubleVector(size_t init_capacity = Default_Capacity); // 디폴트 생성자
	// Precondition: init_capacity > 0인 정수값
	// 초기 크기를 정해줘야 하기 때문에 0보다 큰 값이 들어와야 한다
	// Postcondition: 인자로 받은 capacity에 맞춰 객체를 생성한다
	// 초기 인자가 없을 경우, 디폴트 capacity가 대신 들어간다
	// 입력받은 capacity에 따라 data 배열의 크기를 설정한 뒤, 힙 메모리에 할당
	// used=0, capacity=init_capacity로 초기화시킨다

	MyDoubleVector(const MyDoubleVector& v); // 복사 생성자
	// Precondition: 자기 자신이 아닌 MyDoubleVector 객체가 들어와야 한다
	// Postcondition: 인자로 받은 v와 같은 내용으로 복사시켜 객체를 생성한다
	// 입력받은 v와 같은 capacity로 data 배열의 크기를 설정한 뒤, 힙 메모리에 할당
	// data 배열은 인덱스에 맞춰 v의 data값들을 복사시켜 그 값들로 초기화시킨다
	// used와 capacity는 각각 v의 used와 capacity와 같게 초기화시킨다

	MyDoubleVector& operator=(const MyDoubleVector& v); // 대입연산자
	// Precondition: MyDoubleVector 객체가 들어와야 한다
	// Postcondition: 인자로 받은 v와 같은 내용으로 객체의 멤버변수들의 값을 바꾼다
	// 만약 자기자신을 인자로 받을 경우 자기자신을 반환한다
	// 원래 할당한 data배열을 해제시키고, v와 같은 capacity로 data 배열의 크기를 설정, 힙 메모리에 할당
	// data 배열은 인덱스에 맞춰 v의 data값들을 복사시켜 그 값들로 초기화시킨다
	// used와 capacity는 각각 v의 used와 capacity와 같게 초기화시킨다
	// 반환값은 v값으로 복사가 된 자기 자신을 반환한다

	void operator+=(const MyDoubleVector& v); // operator+= / 붙이기 연산자
	// Precondition: MyDoubleVector 객체가 들어와야 한다
	// Postcondition: 인자로 받은 v를 현재 객체 뒤에 덧붙인다
	// 만약 현재 크기와 v의 크기의 합이 현재 capacity가 클 경우 capacity를 그 합으로 바꾼다
	// 원래 크기를 현재 크기와 v의 크기의 합으로 바꾼다

	double& operator[](size_t idx); // operator[] / 인덱스 연산자
	// Precondition: 0 <= idx < used(size)인 정수값이 들어와야 한다
	// Postcondition: 인자로 받은 idx로 data 배열에 접근한다
	// 접근한 data의 레퍼런스를 반환한다

	MyDoubleVector operator+(const MyDoubleVector& v); // operator+ / 덧셈 연산자
	// Precondtion: MyDoubleVector 객체가 들어와야 한다
	// 현재 객체의 size와 v의 size가 같아야 한다
	// Postcondition: 인자로 받은 v의 data 값들과 현재 객체의 data 값들을 인덱스에 맞춰 각각 더한다
	// 더한 값을 새로운 객체를 만들어 저장한 뒤, 그 객체를 반환한다

	MyDoubleVector operator-(const MyDoubleVector& v); // operator- / 뺄셈 연산자
	// Precondition: MyDoubleVector 객체가 들어와야 한다
	// 현재 객체의 size와 v의 size가 같아야 한다
	// Postcondition: 현재 객체의 data 값들과 인자로 받은 v의 data 값들을 인덱스에 맞춰 각각 뺀다
	// 뺄셈한 값을 새로운 객체를 만들어 저장한 뒤, 그 객체를 반환한다

	double operator*(const MyDoubleVector& v); // operator* / 내적 연산자
	// Precondition: MyDoubleVector 객체가 들어와야 한다
	// 현재 객체의 size와 v의 size가 같아야 한다
	// Postcondition: 현재 벡터와 v 벡터를 내적 계산한다
	// 내적한 값을 반환한다

	MyDoubleVector operator-(); // operator- / unary minus operator
	// Precondition: 자기 자신을 부호를 반전시키기 때문에 입력조건이 없다
	// Postcondition: 현재 객체의 모든 data 값들의 부호를 반전시킨 값을 새로운 객체에 저장한다
	// 그 객체를 반환한다

	bool operator==(const MyDoubleVector& v); // operator== / 같음 연산자
	// Precondition: MyDoubleVector 객체가 들어와야 한다
	// 현재 객체의 size와 v의 size가 같아야 한다
	// Postcondition: 현재 객체의 data 값과 인자로 받은 v의 data 값을 인덱스에 맞춰 비교한다
	// 하나라도 값이 다를 경우 false를 반환, 모든 값이 같을 경우 true를 반환한다

	void operator()(double x); // operator() / 함수 호출 연산자
	// Precondition: double형 실수를 인자로 받는다
	// Postcondition: 현재 객체의 data 값들을 size전 인덱스까지 인자로 받은 실수로 바꾼다
	// 반환값은 없다

	void pop_back(); // pop_back 함수 / 데이터 제거 함수
	// Precondition: 만약 size가 0이라면 사용하면 안된다
	// size > 0 인 경우에만 사용해야 한다
	// Postcondition: data의 마지막 값이 삭제되고 size가 1 감소한다
	// 반환값은 없다

	void push_back(double x); // push_back 함수 / 데이터 추가 함수
	// Precondition: double형 실수를 인자로 받는다
	// Postcondition: data의 마지막 위치에 값을 추가한다
	// 만약 size와 capacity가 같아 데이터를 더 이상 추가할 수 없다면 reserve를 이용하여 capacity를 두 배로 늘린다
	// size가 1 증가한다

	size_t capacity() const; //  capacity get함수
	// Precondition: 입력조건은 없다
	// Postcondition: 현재 객체의 capacity 값을 반환한다
	// size_t 형이기 때문에 capacity>=0을 만족한다

	size_t size() const; // size get함수
	// Precondition: 입력조건은 없다
	// Postcondition: 현재 객체의 size 값을 반환한다
	// size_t 형이기 때문에 size>=0을 만족한다

	void reserve(size_t n); // capacity 변환 함수
	// Precondition: n >= 0 인 정수값이 들어와야 한다
	// Postcondition: 현재 객체의 capacity 값을 인자로 받은 n으로 바꾸고 data의 길이 또한 n만큼 바꾼다
	// 만약 입력받은 n이 size보다 작을 경우 데이터 손실이 없도록 n은 size로 바꾼다
	// 만약 입력받은 n이 현재 capacity와 같을 경우 함수를 끝낸다
	// 반환값은 없다

	bool empty() const; // empty 함수
	// Precondition: 입력조건은 없다
	// Postcondition: 현재 객체의 data가 비어있는지 확인한다
	// size가 0이라면  true를 반환하고, 아니라면 false를 반환한다

	void clear(); // 초기화 함수
	// Precondition: 입력조건은 없다
	// Postcondition: 현재 객체의 data를 delete 하고, NULL을 가리키게 한다
	// used와 capacity를 0으로 초기화하여 빈 벡터를 만든다
	// 반환값은 없다

	~MyDoubleVector(); // 소멸자
	// Precondition: 입력조건은없다
	// Postcondition: 현재 객체가 소멸될 때, data를 delete 하여 안전하게 힙 데이터 공간을 반환한다
};