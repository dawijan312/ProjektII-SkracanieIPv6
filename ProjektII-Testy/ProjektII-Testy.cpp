#include "pch.h"
#include "CppUnitTest.h"
#include "IPv6.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjektIITesty
{
	TEST_CLASS(ProjektIITesty)
	{
	public:
		
		TEST_METHOD(Dummy)
		{
			Assert::IsTrue(true);
		}

		TEST_METHOD(TestValidate)
		{
			Assert::IsTrue(IPv6::validate("1::1"));
			Assert::IsTrue(IPv6::validate("1:2:3:4:5:6:7:8"));
			Assert::IsTrue(IPv6::validate("1:2:3:4:5:6:7::"));
			Assert::IsTrue(IPv6::validate("1:2:3:4:5:6::"));
			Assert::IsTrue(IPv6::validate("1:2:3:4:5::"));
			Assert::IsTrue(IPv6::validate("1:2:3:4::"));
			Assert::IsTrue(IPv6::validate("1:2:3::"));
			Assert::IsTrue(IPv6::validate("1:2::"));
			Assert::IsTrue(IPv6::validate("1::"));
			Assert::IsTrue(IPv6::validate("::"));
			Assert::IsTrue(IPv6::validate("::1"));
		}
	};
}
