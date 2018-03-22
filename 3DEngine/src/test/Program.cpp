#include <iostream>

#include "Test_Matrix.h"
#include "Test_Vector.h"

bool TEST_SUCCESS = true;
#define TEST(name) \
   if(name()) std::cout << "|0| SUCCESS: " #name << std::endl; \
   else { std::cout << "|X| FAILED: " #name << std::endl; \
   TEST_SUCCESS = false; } \

int main(int argc, char** argv)
{
	TEST(VectorConstruct);
	TEST(VectorIndexing);

	TEST(MatrixConstruct);
	TEST(MatrixIndexing);

	std::cout << std::endl;

	if (TEST_SUCCESS)
		std::cout << "|0| Tests successfully completed." << std::endl;
	else
		std::cout << "|X| Tests did not all complete successfully, re-valiudate code" << std::endl;


	system("pause");

	return 0;

}
