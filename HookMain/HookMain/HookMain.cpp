#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define DEF_DLL_NAME "KeyHook.dll"
#define DEF_HOOKSTART "HookStart"
#define DEF_HOOKSTOP "HookStop"

// 使用typedef 定义了两个函数类型
typedef void(*PFN_HOOKSTART)();
typedef void(*PFN_HOOKSTOP)();

int main()
{
	HMODULE hDll = NULL;
	PFN_HOOKSTART HookStart = NULL;
	PFN_HOOKSTOP HookStop = NULL;
	char ch = 0;

	//加载KeyHook.dll
	hDll = LoadLibraryA(DEF_DLL_NAME);

	//获取导出函数地址
	HookStart = (PFN_HOOKSTART)GetProcAddress(hDll, DEF_HOOKSTART);
	HookStop = (PFN_HOOKSTOP)GetProcAddress(hDll, DEF_HOOKSTOP);

	// 开始钩取
	HookStart();

	// 等待直到用户输入 "q"
	printf("please input 'q' to quit!\n");
	//MessageBox(NULL, TEXT("start"), TEXT("SHIT"), MB_OK);
	while (_getch() != 'q');

	//终止钩取
	HookStop();

	//卸载KeyHook.dll
	FreeLibrary(hDll);
	return 0;

}