#include <stdlib.h>
#include <fstream>
#include <iostream>

#include "VolumetricTexture.h"

using namespace std;


void VolumetricTexture::parseFile(const std::string& file_name)
{
    std::ifstream fin(file_name.c_str());
    if(fin.fail()){
        std::cout<<"error--failed to open file: "<<file_name<<std::endl;
        exit(1);
    }

//    fin>>counts[0]>>counts[1]>>counts[2];
    counts[0] = 45;
    counts[1] = 45;
    counts[2] = 45;
    
    updateGrid(counts);
    cout << "COUNTS: " << counts[0] << ", " << counts[1] << ", " << counts[2] << endl;
    for(int z=0; z<counts[2]; z++){
        for(int y=0; y<counts[1]; y++){
            for(int x=0; x<counts[0]; x++){
                fin>>values[getIndex(x,y,z)];
                cout << "values[(" << x << ", " << y << ", " << z << ")]: " << values[getIndex(x,y,z)] << endl;
                if(fin.fail()){
                    std::cout<<"error encountered while reading from file: "<<file_name<<std::endl;
                    exit(1);
                }
            }
        }
    }

    fin.close();
}
