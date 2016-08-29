#include <iostream>	
	
using namespace std;	
	
class Animal {	
	public:
	void makeNoise();
};	
	
class Dog : public Animal {	
	public:
	void makeNoise();
};	
	
class Pig : public Animal {	
	public:
	void makeNoise();
};	
