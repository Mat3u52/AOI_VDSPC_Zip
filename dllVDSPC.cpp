#include "dllVDSPC.h"
#include <sys/stat.h>
#include <windows.h>
#include <string>
#include <iostream>
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
void DllClass::cleanUp(const string &y, const string &m){
    int month = stoi(m);
    int year = stoi(y);

    switch(month){
    case 1:
        year =- 1;
        char yearStr[10];
        itoa(year,yearStr,10);
        cout << yearStr << " " << "12" << endl;
        break;
    case 2:
        month =- 1;
        char monthStr[10];
        itoa(month,monthStr,10);
        cout << y << " " << monthStr << endl;
        break;
    case 3:
        cout << y << " " << m << endl;
        break;
    }
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
