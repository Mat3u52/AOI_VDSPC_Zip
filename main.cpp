#include "dllVDSPC.h"
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main(){
    string year = "";
    string mounth = "";
    const string IPS = "\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\";
    const string IPD = "\\\\tcznt100\\VITROX_AOI_ZIPPED_FILES\\vdspc_image\\";

    cout<<"[step 1.] Please, provide year:";
    cin>>year;
    cout<<endl;
    cout<<"[step 2.] Please, provide mounth:";
    cin>>mounth;

    //string path = year+"\\"+mounth;
    //string pathSource = "\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth; /// source
    string pathSource = IPS+""+year+"\\"+mounth; /// source
    string pathDestination = IPD+""+year+"\\"+mounth; /// destination

    DllClass objectVDSPC(pathSource, pathDestination);

    if(objectVDSPC.pathValidatorSource() == true){
        //for(const auto& entry : fs::directory_iterator(year+"\\"+mounth+"\\")){ ///source
        for(const auto& entry : fs::directory_iterator(pathSource+"\\")){ ///source
            const auto filenameStr = entry.path().filename().string();
            if(entry.is_directory()){
                cout<<"dir:  "<<filenameStr<<endl;

                if(objectVDSPC.pathValidatorDestination() == false){
                    fs::create_directory(pathDestination);
                }
                //string pathSnD = "powershell Compress-Archive -Path \""+year+"\\"+mounth+"\\"+filenameStr+"\" -DestinationPath \""+year+"\\"+mounth+"\\"+filenameStr+".zip\"";
                //string pathSnD = "powershell Compress-Archive -Path \"\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth+"\\"+filenameStr+"\" -DestinationPath \"\\\\tcznt100\\VITROX_AOI_ZIPPED_FILES\\vdspc_image\\"+year+"\\"+mounth+"\\"+filenameStr+".zip\"";
                string pathSnD = "powershell Compress-Archive -Path \""+IPS+""+year+"\\"+mounth+"\\"+filenameStr+"\" -DestinationPath \""+IPD+""+year+"\\"+mounth+"\\"+filenameStr+".zip\"";
                cout<<pathSnD<<endl;
                system(pathSnD.c_str());
            }else if (entry.is_regular_file()){
                cout<<"file: "<<filenameStr<<endl;
            }else{
                cout<<"?? "<<filenameStr<<endl;
            }
        }
    }

    string pathSourceRemove = IPS+""+objectVDSPC.cleanUp(year, mounth); /// source
    string pathDestinationRemove = IPD+""+objectVDSPC.cleanUp(year, mounth); /// destination (not important)

    DllClass objectVDSPCRemove(pathSourceRemove, pathDestinationRemove);
    if(objectVDSPCRemove.pathValidatorSource() == true){
        cout << "Exist." << endl;
        for(const auto& entry : fs::directory_iterator(pathSourceRemove+"\\")){ ///source
            const auto filenameStr = entry.path().filename().string();
            if(entry.is_directory()){
                cout<<"dir:  "<<filenameStr<<endl;

                fs::remove_all(pathSourceRemove+"\\"+filenameStr);

            }else if (entry.is_regular_file()){
                cout<<"file: "<<filenameStr<<endl;
            }else{
                cout<<"?? "<<filenameStr<<endl;
            }
        }
    }

    return 0;
}
