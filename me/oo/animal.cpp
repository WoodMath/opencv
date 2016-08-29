#include <iostream>	
#include "animal.h"	
	
using namespace std;	
	
void Animal::makeNoise() { 	
     cout << "generic animal sound" << endl; 	
};	
	
void Dog::makeNoise() { 	
     cout << "woof" << endl;     	
};	
	
void Pig::makeNoise(){	
     cout << "oink" << endl;	
};	
	
/*	
void animalNoise( Animal& a ) {	
	a.makeNoise();
}	
	
int main() {	
	Dog d;
	Pig p;
	animalNoise( d );
	animalNoise( p );
	
	return 0;
}	
*/	
