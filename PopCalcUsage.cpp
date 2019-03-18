#include <Windows.h>
#include <iostream>

int main(int argc, char** argv) {
	HINSTANCE hPopCalc = LoadLibrary(TEXT("PopCalc.dll"));
	
	std::cout << "LoadLibrary: PopCalc.dll" << std::endl;
	if (!hPopCalc) {
		std::cerr << "[!] Error: Could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}