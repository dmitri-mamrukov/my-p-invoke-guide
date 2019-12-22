using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PInvokeApi.Tests
{
    [TestClass]
    public class ApiTest
    {
        private static bool boolValue = false;
        private static char charValue = '?';
        private static byte unsignedByteValue = 0;
        private static sbyte signedByteValue = 0;
        private static ushort unsignedShortValue = 0;
        private static short signedShortValue = 0;
        private static uint unsignedIntValue = 0;
        private static int signedIntValue = 0;
        private static ulong unsignedLongValue = 0;
        private static long signedLongValue = 0;
        private static float floatValue = 0;
        private static double doubleValue = 0;
        private static string textValue = null;
        private static Api.MyClass classValue = null;

        [TestMethod]
        public void ApiEchoBoolWithFalse()
        {
            boolValue = false;

            Api.ApiEchoBool(false, x => boolValue = x);

            Assert.IsFalse(boolValue);
        }

        [TestMethod]
        public void ApiEchoBoolWithTrue()
        {
            boolValue = false;

            Api.ApiEchoBool(true, x => boolValue = x);

            Assert.IsTrue(boolValue);
        }

        [TestMethod]
        public void ApiEchoCharWithAscii()
        {
            charValue = '?';

            Api.ApiEchoChar('f', x => charValue = x);

            Assert.AreEqual('f', charValue);
        }

        [TestMethod]
        public void ApiEchoCharWithUnicode()
        {
            charValue = '?';

            Api.ApiEchoChar('ф', x => charValue = x);

            Assert.AreEqual('ф', charValue);
        }

        [TestMethod]
        public void ApiEchoUnsignedByteWithByte()
        {
            unsignedByteValue = 0;

            Api.ApiEchoUnsignedByte(1, x => unsignedByteValue = x);

            Assert.AreEqual((byte)1, unsignedByteValue);
        }

        [TestMethod]
        public void ApiEchoSignedByteWithByte()
        {
            signedByteValue = 0;

            Api.ApiEchoSignedByte(1, x => signedByteValue = x);

            Assert.AreEqual((sbyte)1, signedByteValue);
        }

        [TestMethod]
        public void ApiEchoUnsignedShortWithShort()
        {
            unsignedShortValue = 0;

            Api.ApiEchoUnsignedShort(1, x => unsignedShortValue = x);

            Assert.AreEqual((ushort)1, unsignedShortValue);
        }

        [TestMethod]
        public void ApiEchoSignedShortWithShort()
        {
            signedShortValue = 0;

            Api.ApiEchoSignedShort(1, x => signedShortValue = x);

            Assert.AreEqual((short)1, signedShortValue);
        }

        [TestMethod]
        public void ApiEchoUnsignedIntWithInt()
        {
            unsignedIntValue = 0;

            Api.ApiEchoUnsignedInt(1U, x => unsignedIntValue = x);

            Assert.AreEqual(1U, unsignedIntValue);
        }

        [TestMethod]
        public void ApiEchoSignedIntWithInt()
        {
            signedIntValue = 0;

            Api.ApiEchoSignedInt(1, x => signedIntValue = x);

            Assert.AreEqual(1, signedIntValue);
        }

        [TestMethod]
        public void ApiEchoUnsignedLongWithLong()
        {
            unsignedLongValue = 0;

            Api.ApiEchoUnsignedLong(1, x => unsignedLongValue = x);

            Assert.AreEqual(1UL, unsignedLongValue);
        }

        [TestMethod]
        public void ApiEchoSignedLongWithLong()
        {
            signedLongValue = 0;

            Api.ApiEchoSignedLong(1L, x => signedLongValue = x);

            Assert.AreEqual(1L, signedLongValue);
        }

        [TestMethod]
        public void ApiEchoFloatWithFloat()
        {
            floatValue = 0;

            Api.ApiEchoFloat(1.0F, x => floatValue = x);

            Assert.AreEqual(1.0F, floatValue, 0.0F);
        }

        [TestMethod]
        public void ApiEchoDoubleWithDouble()
        {
            doubleValue = 0;

            Api.ApiEchoDouble(1.0D, x => doubleValue = x);

            Assert.AreEqual(1.0D, doubleValue, 0.0D);
        }

        [TestMethod]
        public void ApiEchoStringWithEmptyText()
        {
            textValue = null;

            Api.ApiEchoString("", x => textValue = x);

            Assert.AreEqual("", textValue);
        }

        [TestMethod]
        public void ApiEchoStringWithAsciiText()
        {
            textValue = null;

            Api.ApiEchoString("hello", x => textValue = x);

            Assert.AreEqual("hello", textValue);
        }

        [TestMethod]
        public void ApiEchoStringWithUnicodeText()
        {
            textValue = null;

            Api.ApiEchoString("hello - привет", x => textValue = x);

            Assert.AreEqual("hello - привет", textValue);
        }

        [TestMethod]
        public void ApiEchoClassWithClass()
        {
            classValue = null;
            var value = new Api.MyClass { boolValue = true, textValue = "hello - привет" };

            Api.ApiEchoClass(value, x => classValue = x);

            Assert.IsTrue(classValue.boolValue);
            Assert.AreEqual("hello - привет", classValue.textValue);
        }
    }
}