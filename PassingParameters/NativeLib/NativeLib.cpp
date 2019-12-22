#include "pch.h"

#include <cwchar>

#include "NativeLib.h"

using namespace std;

MYAPI void EchoBool(
    bool value,
    void __stdcall callback(bool value)) {
    callback(value);
}

MYAPI void EchoChar(
    wchar_t value,
    void __stdcall callback(wchar_t value)) {
    callback(value);
}

MYAPI void EchoUnsignedByte(
    unsigned char value,
    void __stdcall callback(unsigned char value)) {
    callback(value);
}

MYAPI void EchoSignedByte(
    char value,
    void __stdcall callback(char value)) {
    callback(value);
}

MYAPI void EchoUnsignedShort(
    unsigned short value,
    void __stdcall callback(unsigned short value)) {
    callback(value);
}

MYAPI void EchoSignedShort(
    short value,
    void __stdcall callback(short value)) {
    callback(value);
}

MYAPI void EchoUnsignedInt(
    unsigned int value,
    void __stdcall callback(unsigned int value)) {
    callback(value);
}

MYAPI void EchoSignedInt(
    int value,
    void __stdcall callback(int value)) {
    callback(value);
}

MYAPI void EchoUnsignedLong(
    unsigned __int64 value,
    void __stdcall callback(unsigned __int64 value)) {
    callback(value);
}

MYAPI void EchoSignedLong(
    __int64 value,
    void __stdcall callback(__int64 value)) {
    callback(value);
}

MYAPI void EchoFloat(
    float value,
    void __stdcall callback(float value)) {
    callback(value);
}

MYAPI void EchoDouble(
    double value,
    void __stdcall callback(double value)) {
    callback(value);
}

MYAPI void EchoString(
    const wchar_t* value,
    void __stdcall callback(const wchar_t* value)) {
    auto size = wcslen(value) + 1;
    auto copy = new wchar_t[size];
    wcscpy_s(copy, size, value);

    callback(copy);

    delete[] copy;
}

MYAPI void EchoClass(
    MyClass* value,
    void __stdcall callback(MyClass* value)) {
    callback(value);
}