#ifndef STARTUPMANAGER_H
#define STARTUPMANAGER_H

#include <string>
#include <windows.h>

#include "settingManager.hpp"

namespace startupManager
{

    void StartApp(const Setting::Setting::App &app)
    {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        CreateProcessA(NULL, strdup(app.path.c_str()), NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

        // Close process and thread handles.
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    };

}

#endif