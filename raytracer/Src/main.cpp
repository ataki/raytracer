#include "st.h"
#include "stgl.h"
#include "stglut.h"
#include "ExampleScene.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, const char * argv[])
{
    ExampleScene *scene = new ExampleScene();
    scene->initializeFinalScene();
//    scene->initializeSceneParticipatingMedia();

    clock_t start, end;
    start=clock();

    scene->Render();

    end=clock();
    cout << "Render time: "<<(double)(end-start) / ((double)CLOCKS_PER_SEC)<<" s"<<std::endl;

    //system("PAUSE");

    return 0;
}

