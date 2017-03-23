# DisableGhostWindow
Simple DLL to modify window "not responding" behaviour

Since Microsoft Windows 2008 R2, Microsoft has  published recommendations regarding application development. One of these recomendations is to make sure your program respond to human interaction as a top priority i.e. mouse and keyboard input must be handled by the application even if it's not able to process them at the moment they arrive.
This mechanism is detailed in the following article: https://msdn.microsoft.com/en-us/library/windows/desktop/dd744765(v=vs.85).aspx.
If your application does not handle this properly, you'll face the famous "not responding" message in the title bar of your app. The application will also get a transparent aspect and users might be able to forcibly kill it after a while.

In most cases, those bad behaving app are:
- single thread
- querying a backend while not allowing any user input
- usually old applications
- usually 32 bit

You may minimize the issue by reviewing the environment used by the app and see if you can improve responsiveness.

The underlying issue can only be fixed by the application developper as he needs to handle user input at all times in his application.


The code provided here can be compiled using Visual Studio C++ to get a DLL to inject in the bad behaving application to prevent the "not responding" message and the ability for users to kill the app. Instead, the application will appear frozen, just the way it was on Windows 2003 and older versions.

To inject the DLL, you may use the usuall AppInit_DLLs registry key:
HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Windows
AppInit_Dlls = C:\PATH\TO\DLL.DLL (REG_SZ)
LoadAppInit_DLLs = 0x00000001 (REG_DWORD)
RequireSignedAppInit_DLLs = 0x00000000 (REG_DWORD)

This code is provided "AS IS"and I do not recommend to use it unless you want to prove a point to the application developper. :)
