#include <iostream>
#include <cstdlib>
#include <stdio.h>

template <typename T>
class Equations{
private:
	T** a;
	T* x;
    int inda, indb;
public:
	Equations(int g);
    Equations() {}
	~Equations();
    void addValue(T value, int g);
//	void enterData(int g);
	void solveEquation(int g);
    T* returnResult();
    bool isEmpty(int g);
//	void showResult(int g);
};
