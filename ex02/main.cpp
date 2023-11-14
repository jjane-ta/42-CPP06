#include "ex02functions.hpp"

int main(){
	Base *b = generate();
	identify(b);
	identify(*b);
	delete b;
}