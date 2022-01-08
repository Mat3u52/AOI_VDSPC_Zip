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

class DllClass{
    public:
        DllClass();
        virtual ~DllClass(void);

        bool pathValidator(string&);
    private:
};
#endif /* _DLL_H_ */
