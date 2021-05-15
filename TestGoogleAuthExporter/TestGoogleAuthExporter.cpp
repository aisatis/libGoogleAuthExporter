// TestGoogleAuthExporter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../libGoogleAuthExporter/libGoogleAuthExporter.h"

int main(int argc, char** argv)
{
    std::string strInput;
    if (argc > 1)
        strInput = argv[1];
    else
    {
        strInput = "Ci8KHuS9nOiAhSA3aWFu5aSn5ZyjIHFxIDU0MTk4MDIwMBIHS2luaEtleSABKAEwAhAB";
        std::cout << "Not found input args,using default test input..." << std::endl;
    }
    char szOut[512] = { 0 };
    int nLen = 512;
    int nRet = GAuthExporter_Decode(strInput.c_str(), szOut, &nLen);
    if (nRet == 0)
        std::cout << szOut;
    else
        std::cout << "decoded failed with ret [" << nRet << "]" << std::endl;
    return nRet;
}
