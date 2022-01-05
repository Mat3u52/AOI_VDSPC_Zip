#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>

using namespace std;
namespace fs = filesystem;

bool pathValidator(string &pathToValid);

int main(){
    string year = "";
    string mounth = "";

    cout<<"[step 1.] Please, provide year:";
    cin>>year;
    cout<<endl;
    cout<<"[step 2.] Please, provide mounth:";
    cin>>mounth;

    //string path = year+"\\"+mounth;
    string pathSource = "\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth; /// source

    string pathDestination = "\\\\tcznt100\\VITROX_AOI_ZIPPED_FILES\\vdspc_image\\"+year+"\\"+mounth; /// destination


    if(pathValidator(pathSource) == true){
        //for(const auto& entry : fs::directory_iterator(year+"\\"+mounth+"\\")){ ///source
        for(const auto& entry : fs::directory_iterator(pathSource+"\\")){ ///source
            const auto filenameStr = entry.path().filename().string();
            if(entry.is_directory()){
                cout<<"dir:  "<<filenameStr<<endl;

                if(pathValidator(pathDestination) == false){
                    fs::create_directory(pathDestination);
                }
                //string pathSnD = "powershell Compress-Archive -Path \""+year+"\\"+mounth+"\\"+filenameStr+"\" -DestinationPath \""+year+"\\"+mounth+"\\"+filenameStr+".zip\"";
                string pathSnD = "powershell Compress-Archive -Path \"\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth+"\\"+filenameStr+"\" -DestinationPath \"\\\\tcznt100\\VITROX_AOI_ZIPPED_FILES\\vdspc_image\\"+year+"\\"+mounth+"\\"+filenameStr+".zip\"";
                cout<<pathSnD<<endl;
                system(pathSnD.c_str());
            }else if (entry.is_regular_file()){
                cout<<"file: "<<filenameStr<<endl;
            }else{
                cout<<"?? "<<filenameStr<<endl;
            }
        }
    }

    return 0;
}

bool pathValidator(string &pathToValid){
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
