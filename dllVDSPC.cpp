#include "dllVDSPC.h"
#include <windows.h>
#include <sys/stat.h>
using namespace std;
//DllClass::DllClass(std::string &pathToValid){
//    std::string pathToValidOK = pathToValid;
//}
DllClass::DllClass(){
}
DllClass::~DllClass(){
}

bool DllClass::pathValidator(string &pathToValid){
    struct stat st;
    char pathChar[pathToValid.length()+1];
    strcpy(pathChar, pathToValid.c_str());

    if(stat(pathChar, &st) == 0){
        return true;
    }else{
        return false;
    }

    return false;
}

BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved){
    switch(reason){
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
