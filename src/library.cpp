#include <opencv2/opencv.hpp>
#include "library.h"

const char* version = "0.9.5";

LIBMATCH_API const char* libmatch_version()
{
    // cv::getBuildInformation();
    return version;
}

const char readme[] = "-------------------------------------LibMatch------------------------------------\n"
                      "                                     ��������\n"
                      "һ. �������ȫ���ڸ�����Ȥ���ã��ɱ�����ҵ��ʱ�俪��.��һ�ȫ����ɫ���ɿ�����ѵ������Ʒ.\n"
                      "��. ���ñ�������������κ������Ʒ���ͱ����޹�.\n"
                      "��. ��������Բ�����κ�һ����Ϸ������Ϸ�����̣�����������ñ���������Ƿ���Ϸ���������˽�����׷���������Լ��������ε�Ȩ��.\n"
                      "��. ��ʹ�ñ���������µ��κ����⡢�������Լ�ٻ����̰�����Ȩ��֪ʶ��Ȩ�ַ���������ɵ��κ���ʧ�����˸Ų�������Ų��е��κ����»����·������Ρ�\n"
                      "��. ������Ĺ������������������������﷨�����������������Թٷ����κι�ϵ.\n"
                      "��. �����һ�ο�ʼʹ�ñ������ṩ���κ��������Դ����һ����ͽ�����Ϊ�Ա�����ȫ�����ݵ��Ͽɡ�ͬʱ�������Ͽ����������������ʹ�ñ��������Դ�������κ����飬��������ɾ�����������Դ����ֹͣʹ��.\n"
                      "��. �������ݣ����˱������ս���Ȩ��";




#ifdef _WIN32
#include "bmpWnd.h"
#include <thread>

BOOL WINAPI DllMain(
        HINSTANCE hinstDLL,  // handle to DLL module
        DWORD fdwReason,     // reason for calling function
        LPVOID lpvReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason )
    {
        case DLL_PROCESS_ATTACH:
            // Initialize once for each new process.
            // Return FALSE to fail DLL load.
            std::thread([] {
                TextWindow textWnd(readme, 10);
                textWnd.show();
                }).detach();
            break;

        case DLL_THREAD_ATTACH:
            // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
            // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:

            if (lpvReserved != nullptr)
            {
                break; // do not do cleanup if process termination scenario
            }

            // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

#endif