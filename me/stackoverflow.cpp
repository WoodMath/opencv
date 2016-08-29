#include <iostream>

using namespace std;


class Foo{

private:
	int iX;

public:
	void printX(string sLabel){
		cout << sLabel << " : " << " Foo::iX = " << Foo::iX << endl;
	}; 
	void setX(int iX){
		Foo::iX = iX;
		Foo::printX("setX(void) Method");
	};
	Foo(){
		Foo::iX = 1;
		Foo::printX("Foo(void) Constructor");
	};

	Foo(int iX){
		Foo::setX(iX);
		Foo::printX("Foo(int) Constructor");
		Foo::Foo();
		Foo::printX("Foo(int) Constructor");
		
	};


};


int main( int argc, char** argv ){
	

	Foo bar(2);

	return 0;
}
