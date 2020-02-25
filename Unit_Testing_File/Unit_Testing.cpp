#include "pch.h"
#include "CppUnitTest.h"

#include "../Main_File/test_header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingFile
{
	TEST_CLASS(Test_Header)
	{
	public:
		
		TEST_METHOD(Is_Ten)
		{
			Assert::IsTrue(isItTen(10), L"Must be true");
		}
		TEST_METHOD(Is_Minus_Ten)
		{
			Assert::IsFalse(isItTen(-10), L"Must be false");
		}
		TEST_METHOD(Is_Nine)
		{
			Assert::IsFalse(isItTen(9), L"Must be false");
		}
		TEST_METHOD(Is_Eleven)
		{
			Assert::IsFalse(isItTen(11), L"Must be false");
		}
	};
}
