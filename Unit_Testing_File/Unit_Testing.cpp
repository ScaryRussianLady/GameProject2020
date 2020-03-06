#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"

#include "../Main_File/test_header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingFile
{
	TEST_CLASS(create_gladiatior_test)
	{
	public:
		
		TEST_METHOD(Is_Ten)
		{
			std::cout << "TEST" << std::endl;

			Assert::IsTrue(isItTen(10), L"Must be true");
		}
	};
}
