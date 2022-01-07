#ifndef _DLL_H_
#define _DLL_H_

#include <windows.h>
#include <string>
using namespace std;

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */


//extern "C"{
//void DLLIMPORT pathValidator(void);
//void DLLIMPORT DllClass(void);
//}

class DllClass{
    public:
        //DllClass(std::string&);
        DllClass();
        virtual ~DllClass(void);

        bool pathValidator(string&);
    private:
        //std::string pathToValid;
};
#endif /* _DLL_H_ */
