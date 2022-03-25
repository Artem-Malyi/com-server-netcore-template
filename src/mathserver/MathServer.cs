using System;
using System.Runtime.InteropServices;

namespace comserver_netcore
{
    [ComVisible(true)]
    [Guid("C0B5F93D-A766-4B65-AE5F-FC0AA0E6DBEB")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IMathServer
    {
        int Add(int num1, int num2);
    }

    [ComVisible(true)]
    [Guid("AE9DE624-3FED-45A2-87EB-8A55FFB93F77")]
    public class MathServer : IMathServer
    {
        public int Add(int num1, int num2)
        {
            return num1 + num2;
        }
    }
}
