#include <string_view>

int main()
{
	char* foo = "bar"; 
	std::string_view(foo, 3);	
	return 0;
}
