#include "ex02functions.hpp"

Base * generate(void){
	srand (time(NULL));
	switch(rand() % 3  )
	{
    case 0: return new A;
    case 1: return new B;
    case 2: return new C;
}
	return (new A);
}
void identify(Base* p){
	dynamic_cast<A*>(p) != 0 ? std::cout << "Pointer is A class\n"
		: dynamic_cast<B*>(p) != 0 ? std::cout << "Pointer is B class\n"
		: dynamic_cast<C*>(p) != 0 ? std::cout << "Pointer is C class\n"
		: dynamic_cast<Base*>(p) != 0 ? std::cout << "Pointer is Base class\n"
		: std::cout << "Pointer is Unknown class\n";
}
void identify(Base& p){
	try{dynamic_cast<A&>(p);	std::cout << "Reference is A class\n"; return;	} catch (...){}
	try{dynamic_cast<B&>(p);	std::cout << "Reference is B class\n"; return;	} catch (...){}
	try{dynamic_cast<C&>(p);	std::cout << "Reference is C class\n"; return;	} catch (...){}
	try{(void)dynamic_cast<Base&>(p);	std::cout << "Reference is Base class\n"; return;	} catch (...){}
	std::cout << "Reference is Unknown class\n";	
}