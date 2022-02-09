#include "dllVDSPC.h"
#include <sys/stat.h>
#include <windows.h>
#include <string>
using namespace std;

DllClass::DllClass(const string &s, const string &d){
    if(s.length() > 0 && d.length() > 0){
        source = s;
        destination = d;
    }
}
DllClass::~DllClass(){
}
bool DllClass::pathValidatorSource(void){
    struct stat st;
    char pathChar[source.length()+1];
    strcpy(pathChar, source.c_str());

    if(stat(pathChar, &st) == 0){
        return true;
    }else{
        return false;
    }
return false;
}
bool DllClass::pathValidatorDestination(void){
    struct stat st;
    char pathChar[destination.length()+1];
    strcpy(pathChar, destination.c_str());

    if(stat(pathChar, &st) == 0){
        return true;
    }else{
        return false;
    }
return false;
}
void DllClass::cleanUp(void){

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
