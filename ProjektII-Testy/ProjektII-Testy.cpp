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

		TEST_METHOD(TestValidateValid1)
		{
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
			Assert::IsTrue(IPv6::validate("::1:2"));
			Assert::IsTrue(IPv6::validate("::1:2:3"));
			Assert::IsTrue(IPv6::validate("::1:2:3:4"));
			Assert::IsTrue(IPv6::validate("::1:2:3:4:5"));
			Assert::IsTrue(IPv6::validate("::1:2:3:4:5:6"));
			Assert::IsTrue(IPv6::validate("::1:2:3:4:5:6:7"));
		}
		TEST_METHOD(TestValidateValid2)
		{
			Assert::IsTrue(IPv6::validate("1::1"));
			Assert::IsTrue(IPv6::validate("1:2::1"));
			Assert::IsTrue(IPv6::validate("1:2:3::1"));
			Assert::IsTrue(IPv6::validate("01:002:0003::0003:002:01"));
			Assert::IsTrue(IPv6::validate("1:2:3:4:5:6:7:8"));
			Assert::IsTrue(IPv6::validate("9:a:b:c:d:e:f:0"));
			Assert::IsTrue(IPv6::validate("AA:BBB:CCCC:DDDD:EEEE:FFFF::"));
			Assert::IsTrue(IPv6::validate("FE80::1"));
		}
		TEST_METHOD(TestValidateInvalid1)
		{
			Assert::IsFalse(IPv6::validate("1:2:3:4:5:6:7:8:9"));
			Assert::IsFalse(IPv6::validate("1:2:3:4:5:6:7:"));
			Assert::IsFalse(IPv6::validate("1:2:3:4:5:6:"));
			Assert::IsFalse(IPv6::validate("1:2:3:4:5:"));
			Assert::IsFalse(IPv6::validate("1:2:3:4:"));
			Assert::IsFalse(IPv6::validate("1:2:3:"));
			Assert::IsFalse(IPv6::validate("1:2:"));
			Assert::IsFalse(IPv6::validate("1:"));
			Assert::IsFalse(IPv6::validate(":"));
			Assert::IsFalse(IPv6::validate(":::"));
			Assert::IsFalse(IPv6::validate("::1:"));
			Assert::IsFalse(IPv6::validate("::1:2:"));
			Assert::IsFalse(IPv6::validate("::1:2:3:"));
			Assert::IsFalse(IPv6::validate("::1:2:3:4:"));
			Assert::IsFalse(IPv6::validate("::1:2:3:4:5:"));
			Assert::IsFalse(IPv6::validate("::1:2:3:4:5:6:"));
			Assert::IsFalse(IPv6::validate("::1:2:3:4:5:6:7:"));
		}
		TEST_METHOD(TestValidateInvalid2)
		{
			Assert::IsFalse(IPv6::validate("1::1::1"));
			Assert::IsFalse(IPv6::validate(""));
			Assert::IsFalse(IPv6::validate("010000:002:0003::002:01:"));
			Assert::IsFalse(IPv6::validate("12345::"));
			Assert::IsFalse(IPv6::validate("1000000000000::"));
			Assert::IsFalse(IPv6::validate("AAAAA:BBBBB::"));
			Assert::IsFalse(IPv6::validate("G::H"));
		}

		TEST_METHOD(TestShortened)
		{
			IPv6 ip("0:0:0:0:0:0:0:0");
			std::string fin = ip.shortened();
			Assert::AreEqual("::", ip.shortened().c_str());
			ip.store("2a01::78b4:0:0:0:1");
			Assert::AreEqual("2a01:0:0:78b4::1", ip.shortened().c_str());
			ip.store("2a01:0000:0000:78b4:0000:0000:0000:0001");
			Assert::AreEqual("2a01:0:0:78b4::1", ip.shortened().c_str());
		}

		TEST_METHOD(TestExtended)
		{
			IPv6 ip("::");
			Assert::AreEqual("0000:0000:0000:0000:0000:0000:0000:0000", ip.extended().c_str());
			ip.store("2a01:0:0:78b4::1");
			Assert::AreEqual("2a01:0000:0000:78b4:0000:0000:0000:0001", ip.extended().c_str());
		}

		TEST_METHOD(TestOutput)
		{
			IPv6 ip("::");
			Assert::AreEqual("0:0:0:0:0:0:0:0", ip.output().c_str());
			ip.store("2a01:0:0:78b4::1");
			Assert::AreEqual("2a01:0:0:78b4:0:0:0:1", ip.output().c_str());
		}
	};
}
