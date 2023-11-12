#include "Serializer.hpp"

int main(){
	Data data = {'*', 42, 42.0f, 42.0};

	Data * data2 = Serializer::deserialize(Serializer::serialize(&data));

	std::cout << "pointer to data " << &data << std::endl;
	std::cout << "pointer to data2 " << data2<< std::endl;
	std::cout << "data => d= " << data.d << std::endl;
	std::cout << "data2 => d= " << data2->d << std::endl;	
}