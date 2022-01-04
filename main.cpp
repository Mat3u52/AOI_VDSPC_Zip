#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>

using namespace std;
namespace fs = filesystem;

struct stat st;
string year = "";
string mounth = "";

int main(){
    cout<<"[step 1.] Please, provide year:";
    cin>>year;
    cout<<endl;
    cout<<"[step 2.] Please, provide mounth:";
    cin>>mounth;
    //string path = year+"\\"+mounth;
    string pathScr = "\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth; /// source
    char pathCharScr[pathScr.length()+1];
    strcpy(pathCharScr, pathScr.c_str());

    string pathDes = "\\\\tcznt100\\VITROX_AOI_ZIPPED_FILES\\vdspc_image\\"+year+"\\"+mounth; /// destination
    char pathCharDes[pathDes.length()+1];
    strcpy(pathCharDes, pathDes.c_str());

    if(stat(pathCharScr, &st) == 0){
        //for(const auto& entry : fs::directory_iterator(year+"\\"+mounth+"\\")){ ///source
        for(const auto& entry : fs::directory_iterator("\\\\tcznt100\\VITROX_AOI_BACKUP\\vdspc_image\\"+year+"\\"+mounth+"\\")){ ///source
            const auto filenameStr = entry.path().filename().string();
            if(entry.is_directory()){
                cout<<"dir:  "<<filenameStr<<endl;
                ///add feature to create a new dir on the tcznt100\vitrox_aoi_backup
                if(stat(pathCharDes, &st) != 0){
                    fs::create_directory(pathDes);
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
