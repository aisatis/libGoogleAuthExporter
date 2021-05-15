// TestGoogleAuthExporter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../libGoogleAuthExporter/libGoogleAuthExporter.h"

int main()
{

    const char* szTest = "Ci8KHuS9nOiAhSA3aWFu5aSn5ZyjIHFxIDU0MTk4MDIwMBIHS2luaEtleSABKAEwAhAB";
    char szOut[512] = { 0 };
    int nLen = 512;
    GAuthExporter_Decode(szTest, szOut, &nLen);
    std::cout << szOut;
    std::cin.get();
}
