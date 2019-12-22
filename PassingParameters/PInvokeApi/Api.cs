using System;
using System.Runtime.InteropServices;

namespace PInvokeApi
{
    public class Api
    {
        #region Public Classes

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
        public class MyClass
        {
            public bool boolValue;
            public string textValue;
        }

        #endregion Public Classes

        #region Public Delegates

        public delegate void EchoBoolCallback(bool value);

        public delegate void EchoCharCallback([In, MarshalAs(UnmanagedType.U2)] char value);

        public delegate void EchoUnsignedByteCallback(byte value);

        public delegate void EchoSignedByteCallback(sbyte value);

        public delegate void EchoUnsignedShortCallback(ushort value);

        public delegate void EchoSignedShortCallback(short value);

        public delegate void EchoUnsignedIntCallback(uint value);

        public delegate void EchoSignedIntCallback(int value);

        public delegate void EchoUnsignedLongCallback(ulong value);

        public delegate void EchoSignedLongCallback(long value);

        public delegate void EchoFloatCallback(float value);

        public delegate void EchoDoubleCallback(double value);

        public delegate void EchoStringCallback([In, MarshalAs(UnmanagedType.LPWStr)] string value);

        public delegate void EchoClassCallback(MyClass value);

        #endregion Public Delegates

        #region P/Invoke API

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoBool(bool value, EchoBoolCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode)]
        private static extern void EchoChar(char value, EchoCharCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoUnsignedByte(byte value, EchoUnsignedByteCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoSignedByte(sbyte value, EchoSignedByteCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoUnsignedShort(ushort value, EchoUnsignedShortCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoSignedShort(short value, EchoSignedShortCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoUnsignedInt(uint value, EchoUnsignedIntCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoSignedInt(int value, EchoSignedIntCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoUnsignedLong(ulong value, EchoUnsignedLongCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoSignedLong(long value, EchoSignedLongCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoFloat(float value, EchoFloatCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern void EchoDouble(double value, EchoDoubleCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode)]
        private static extern void EchoString(string value, EchoStringCallback callback);

        [DllImport(
            "NativeLib.dll",
            CallingConvention = CallingConvention.Cdecl,
            CharSet = CharSet.Unicode)]
        private static extern void EchoClass(MyClass value, EchoClassCallback callback);

        #endregion P/Invoke API

        #region Public Methiods

        public static void ApiEchoBool(bool value, EchoBoolCallback callback)
        {
            EchoBool(value, callback);
        }

        public static void ApiEchoChar(char value, EchoCharCallback callback)
        {
            EchoChar(value, callback);
        }

        public static void ApiEchoUnsignedByte(byte value, EchoUnsignedByteCallback callback)
        {
            EchoUnsignedByte(value, callback);
        }

        public static void ApiEchoSignedByte(sbyte value, EchoSignedByteCallback callback)
        {
            EchoSignedByte(value, callback);
        }

        public static void ApiEchoUnsignedShort(ushort value, EchoUnsignedShortCallback callback)
        {
            EchoUnsignedShort(value, callback);
        }

        public static void ApiEchoSignedShort(short value, EchoSignedShortCallback callback)
        {
            EchoSignedShort(value, callback);
        }

        public static void ApiEchoUnsignedInt(uint value, EchoUnsignedIntCallback callback)
        {
            EchoUnsignedInt(value, callback);
        }

        public static void ApiEchoSignedInt(int value, EchoSignedIntCallback callback)
        {
            EchoSignedInt(value, callback);
        }

        public static void ApiEchoUnsignedLong(ulong value, EchoUnsignedLongCallback callback)
        {
            EchoUnsignedLong(value, callback);
        }

        public static void ApiEchoSignedLong(long value, EchoSignedLongCallback callback)
        {
            EchoSignedLong(value, callback);
        }

        public static void ApiEchoFloat(float value, EchoFloatCallback callback)
        {
            EchoFloat(value, callback);
        }

        public static void ApiEchoDouble(double value, EchoDoubleCallback callback)
        {
            EchoDouble(value, callback);
        }

        public static void ApiEchoString(string value, EchoStringCallback callback)
        {
            EchoString(value, callback);
        }

        public static void ApiEchoClass(MyClass value, EchoClassCallback callback)
        {
            EchoClass(value, callback);
        }

        #endregion Public Methiods
    }
}