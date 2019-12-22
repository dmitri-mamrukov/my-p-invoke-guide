#include "pch.h"
#include "CppUnitTest.h"

#include <cwchar>

#include "NativeLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeLibTests
{
    TEST_CLASS(NativeLibTests)
    {
    public:
        static bool boolValue;
        static wchar_t charValue;
        static unsigned char unsignedByteValue;
        static char signedByteValue;
        static unsigned short unsignedShortValue;
        static short signedShortValue;
        static unsigned int unsignedIntValue;
        static int signedIntValue;
        static unsigned __int64 unsignedLongValue;
        static __int64 signedLongValue;
        static float floatValue;
        static double doubleValue;
        static wchar_t* textValue;
        static MyClass* classValue;

        static void Callback(bool value)
        {
            NativeLibTests::boolValue = value;
        }

        static void Callback(wchar_t value)
        {
            NativeLibTests::charValue = value;
        }

        static void Callback(unsigned char value)
        {
            NativeLibTests::unsignedByteValue = value;
        }

        static void Callback(char value)
        {
            NativeLibTests::signedByteValue = value;
        }

        static void Callback(unsigned short value)
        {
            NativeLibTests::unsignedShortValue = value;
        }

        static void Callback(short value)
        {
            NativeLibTests::signedShortValue = value;
        }

        static void Callback(unsigned int value)
        {
            NativeLibTests::unsignedIntValue = value;
        }

        static void Callback(int value)
        {
            NativeLibTests::signedIntValue = value;
        }

        static void Callback(unsigned __int64 value)
        {
            NativeLibTests::unsignedLongValue = value;
        }

        static void Callback(__int64 value)
        {
            NativeLibTests::signedLongValue = value;
        }

        static void Callback(float value)
        {
            NativeLibTests::floatValue = value;
        }

        static void Callback(double value)
        {
            NativeLibTests::doubleValue = value;
        }

        static void Callback(const wchar_t* value)
        {
            auto size = wcslen(value) + 1;
            NativeLibTests::textValue = new wchar_t[size];
            wcscpy_s(NativeLibTests::textValue, size, value);
        }

        static void Callback(MyClass* value)
        {
            NativeLibTests::classValue = new MyClass;

            NativeLibTests::classValue->boolValue = value->boolValue;

            auto size = wcslen(value->textValue) + 1;
            NativeLibTests::classValue->textValue = new wchar_t[size];
            wcscpy_s(NativeLibTests::classValue->textValue, size, value->textValue);
        }

        TEST_METHOD(EchoBoolWithFalse)
        {
            NativeLibTests::boolValue = false;

            EchoBool(false, &Callback);

            Assert::IsFalse(NativeLibTests::boolValue);
        }

        TEST_METHOD(EchoBoolWithTrue)
        {
            NativeLibTests::boolValue = false;

            EchoBool(true, &Callback);

            Assert::AreEqual(true, NativeLibTests::boolValue);
        }

        TEST_METHOD(EchoCharWithAscii)
        {
            NativeLibTests::charValue = L'?';

            EchoChar(L'f', &Callback);

            Assert::AreEqual(L'f', NativeLibTests::charValue);
        }

        TEST_METHOD(EchoCharWithUnicode)
        {
            NativeLibTests::charValue = L'?';

            EchoChar(L'ф', &Callback);

            Assert::AreEqual(L'ф', NativeLibTests::charValue);
        }

        TEST_METHOD(EchoUnsignedByteWithByte)
        {
            NativeLibTests::unsignedByteValue = 0;

            EchoUnsignedByte(1, &Callback);

            Assert::AreEqual((unsigned char)1, NativeLibTests::unsignedByteValue);
        }

        TEST_METHOD(EchoSignedByteWithByte)
        {
            NativeLibTests::signedByteValue = 0;

            EchoSignedByte(1, &Callback);

            Assert::AreEqual((char)1, NativeLibTests::signedByteValue);
        }

        TEST_METHOD(EchoUnsignedShortWithShort)
        {
            NativeLibTests::unsignedShortValue = 0;

            EchoUnsignedShort(1, &Callback);

            Assert::AreEqual((unsigned int)1, (unsigned int)NativeLibTests::unsignedShortValue);
        }

        TEST_METHOD(EchoSignedShortWithShort)
        {
            NativeLibTests::signedShortValue = 0;

            EchoSignedShort(1, &Callback);

            Assert::AreEqual((short)1, NativeLibTests::signedShortValue);
        }

        TEST_METHOD(EchoUnsignedIntWithInt)
        {
            NativeLibTests::unsignedIntValue = 0;

            EchoUnsignedInt(1, &Callback);

            Assert::AreEqual((unsigned int)1, NativeLibTests::unsignedIntValue);
        }

        TEST_METHOD(EchoSignedIntWithInt)
        {
            NativeLibTests::signedIntValue = 0;

            EchoSignedInt(1, &Callback);

            Assert::AreEqual(1, NativeLibTests::signedIntValue);
        }

        TEST_METHOD(EchoUnsignedLongWithLong)
        {
            NativeLibTests::unsignedLongValue = 0;

            EchoUnsignedLong(1, &Callback);

            Assert::AreEqual((unsigned __int64)1, NativeLibTests::unsignedLongValue);
        }

        TEST_METHOD(EchoSignedLongWithLong)
        {
            NativeLibTests::signedLongValue = 0;

            EchoSignedLong(1, &Callback);

            Assert::AreEqual((__int64)1, NativeLibTests::signedLongValue);
        }

        TEST_METHOD(EchoFloatWithFloat)
        {
            NativeLibTests::floatValue = 0.0;

            EchoFloat(1, &Callback);

            Assert::AreEqual((float)1.0, NativeLibTests::floatValue);
        }

        TEST_METHOD(EchoFloatWithDouble)
        {
            NativeLibTests::doubleValue = 0.0;

            EchoDouble(1, &Callback);

            Assert::AreEqual((double)1.0, NativeLibTests::doubleValue);
        }

        TEST_METHOD(EchoStringWithEmptyText)
        {
            NativeLibTests::textValue = nullptr;

            EchoString(L"", &Callback);

            Assert::AreEqual(L"", NativeLibTests::textValue);
        }

        TEST_METHOD(EchoStringWithAsciiText)
        {
            NativeLibTests::textValue = nullptr;

            EchoString(L"hello", &Callback);

            Assert::AreEqual(L"hello", NativeLibTests::textValue);
        }

        TEST_METHOD(EchoStringWithUnicodeText)
        {
            NativeLibTests::textValue = nullptr;

            EchoString(L"hello - привет", &Callback);

            Assert::AreEqual(L"hello - привет", NativeLibTests::textValue);
        }

        TEST_METHOD(EchoClassWithClass)
        {
            NativeLibTests::classValue = nullptr;
            MyClass myClass;
            myClass.boolValue = true;
            myClass.textValue = L"hello - привет";

            EchoClass(&myClass, &Callback);

            Assert::IsNotNull(NativeLibTests::classValue);
            if (NativeLibTests::classValue != nullptr)
            {
                Assert::AreEqual(true, NativeLibTests::classValue->boolValue);
                Assert::AreEqual(L"hello - привет", NativeLibTests::classValue->textValue);
            }
        }
    };

    bool NativeLibTests::boolValue = false;
    wchar_t NativeLibTests::charValue = L'?';
    unsigned char NativeLibTests::unsignedByteValue = 0;
    char NativeLibTests::signedByteValue = 0;
    unsigned short NativeLibTests::unsignedShortValue = 0;
    short NativeLibTests::signedShortValue = 0;
    unsigned int NativeLibTests::unsignedIntValue = 0;
    int NativeLibTests::signedIntValue = 0;
    unsigned __int64 NativeLibTests::unsignedLongValue = 0;
    __int64 NativeLibTests::signedLongValue = 0;
    float NativeLibTests::floatValue = 0;
    double NativeLibTests::doubleValue = 0;
    wchar_t* NativeLibTests::textValue = nullptr;
    MyClass* NativeLibTests::classValue = nullptr;
};