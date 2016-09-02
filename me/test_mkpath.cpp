#include <iostream>
#include <string>
#include "mkpath.hpp"



int main(int argc, char* argv[]){

	int k;
	k = mkpath("./test/a/b/c/d", 0755);
	
	return 0;
}

