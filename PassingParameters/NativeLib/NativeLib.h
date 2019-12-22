#ifndef _NATIVELIB_H_
#define _NATIVELIB_H_

#ifndef MYAPI
#define MYAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        bool boolValue;
        wchar_t* textValue;
    } MyClass;

    MYAPI void EchoBool(
        bool value,
        void __stdcall callback(bool value));

    MYAPI void EchoChar(
        wchar_t value,
        void __stdcall callback(wchar_t value));

    MYAPI void EchoUnsignedByte(
        unsigned char value,
        void __stdcall callback(unsigned char value));

    MYAPI void EchoSignedByte(
        char value,
        void __stdcall callback(char value));

    MYAPI void EchoUnsignedShort(
        unsigned short value,
        void __stdcall callback(unsigned short value));

    MYAPI void EchoSignedShort(
        short value,
        void __stdcall callback(short value));

    MYAPI void EchoUnsignedInt(
        unsigned int value,
        void __stdcall callback(unsigned int value));

    MYAPI void EchoSignedInt(
        int value,
        void __stdcall callback(int value));

    MYAPI void EchoUnsignedLong(
        unsigned __int64 value,
        void __stdcall callback(unsigned __int64 value));

    MYAPI void EchoSignedLong(
        __int64 value,
        void __stdcall callback(__int64 value));

    MYAPI void EchoFloat(
        float value,
        void __stdcall callback(float value));

    MYAPI void EchoDouble(
        double value,
        void __stdcall callback(double value));

    MYAPI void EchoString(
        const wchar_t* value,
        void __stdcall callback(const wchar_t* value));

    MYAPI void EchoClass(
        MyClass* value,
        void __stdcall callback(MyClass* value));

#ifdef __cplusplus
}
#endif

#endif // _NATIVELIB_H_