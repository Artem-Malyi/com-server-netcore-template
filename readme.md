# COM server .NET Core template

Minimalistic solution for the managed COM InProcServer (C# assembly) implementing IUnknown and native C++ command line client


Based on:
 * https://docs.microsoft.com/en-us/dotnet/core/native-interop/expose-components-to-com
 * https://github.com/dotnet/samples/tree/main/core/extensions/COMServerDemo


Usage:
1. register COM host dll with `regsvr32 mathserver.comhost.dll`
2. run `testclient.exe`, this will lead to:
   * mathserver.dll and its COM-Callable Wrapper (CCW) will be loaded to testclient.exe address space
   * testclient will be able to create instance of the COM object and call its methods, getting back results
3. unregister COM host dll with `regsvr32 /u mathserver.comhost.dll`
