#include "ExampleScene.h"

void ExampleScene::initializeSceneBasicGeometry()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,0.f,10.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Custom_Tests/BasicGeometry.png");
	rtBounceDepth(1);
	rtUseShadow(false);
	rtShadowBias(1e-4f);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(/*location*/STPoint3(0.f,0.f,5.f),STColor3f(1.f,1.f,1.f));

	////objects
	////triangle
	Material mat_tri(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(1.f,0.f,0.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_tri);
	rtTriangle(/*v1*/STPoint3(-1.f,-1.f,0.f),/*v2*/STPoint3(1.f,-1.f,0.f),/*v3*/STPoint3(0.f,1.f,0.f));

	////sphere
	Material mat_sphere(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(0.f,1.f,0.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_sphere);
	rtSphere(STPoint3(2.f,2.f,0.f),1.f);

	////box
	Material mat_box(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(0.f,0.f,1.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_box);
	rtBox(STPoint3(-2.2f,-2.2f,0.f),STVector3(2.f,2.f,2.f));
}

void ExampleScene::initializeSceneBasicLightingAndShading()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,0.f,10.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Custom_Tests/BasicLightingAndShading.png");
	rtBounceDepth(1);
	rtShadowBias(1e-4f);
	rtSampleRate(4);

	////lighting:
//	rtAmbientLight(STColor3f(.1f,.1f,.1f));
//	rtPointLight(/*location*/STPoint3(4.f,4.f,8.f),STColor3f(.5f,.5f,.5f));
//	rtPointLight(/*location*/STPoint3(4.f,-2.f,8.f),STColor3f(.5f,.5f,.5f));
//	rtAreaLight(/*v1*/STPoint3(1.5f,.25f,.75f),/*v2*/STPoint3(1.5f,-.25f,1.25f),/*v3*/STPoint3(1.5f,.25f,1.25f),STColor3f(.8f,.8f,.8f));

	////objects:
	////sphere
	Material mat_sphere(STColor3f(0.f,0.f,1.f),STColor3f(0.f,0.f,.8f),STColor3f(1.f,1.f,1.f),STColor3f(0.f,0.f,0.f),30.f);
	rtMaterial(mat_sphere);
	rtSphere(STPoint3(-.5f,-.5f,1.f),1.f);

	////background wall
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(0.8f,0.8f,.8f),STColor3f(0.f,0.f,0.f),STColor3f(0.f,0.f,0.f),30.f);
	rtMaterial(mat_ground);
	addBackgroundWall(STPoint3(-8.f,-8.f,-1.f),STVector2(16.f,16.f));
}

void ExampleScene::initializeSceneTransform()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,0.f,10.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/Transform.png");
	rtBounceDepth(1);
	rtShadowBias(1e-4f);
	rtSampleRate(2);

	////lighting:
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(/*location*/STPoint3(4.f,4.f,8.f),STColor3f(.5f,.5f,.5f));
	rtPushMatrix();
	rtTranslate(0.f,-4.f,0.f);
	rtPointLight(/*location*/STPoint3(4.f,4.f,8.f),STColor3f(.5f,.5f,.5f));
	rtPopMatrix();

	////box
	Material mat_box(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(0.f,0.f,1.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_box);
	rtBox(/*center*/STPoint3(0.f,0.f,0.f),/*size*/STVector3(1.f,1.f,1.f));

	////box2
	Material mat_box2(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(1.f,0.f,0.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_box2);
	rtPushMatrix();
	rtTranslate(2.f,0.f,0.f);
	rtRotate(0.f,0.f,60.f);
	rtBox(/*center*/STPoint3(0.f,0.f,0.f),/*size*/STVector3(1.f,1.f,1.f));
	rtPopMatrix();

	////box3
	Material mat_box3(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(0.f,1.f,0.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_box3);
	rtPushMatrix();
	rtTranslate(-2.f,0.f,0.f);
	rtScale(1.f,2.f,1.f);
	rtBox(/*center*/STPoint3(0.f,0.f,0.f),/*size*/STVector3(1.f,1.f,1.f));
	rtPopMatrix();

	////background wall
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(0.f,0.f,0.f),STColor3f(0.f,0.f,0.f),30.f);
	rtMaterial(mat_ground);
	addBackgroundWall(STPoint3(-8.f,-8.f,-1.f),STVector2(16.f,16.f));
}

void ExampleScene::initializeSceneAccelerationStructureGrid()
{
    rtClear();

    ////global settings
    rtCamera(/*eye*/STPoint3(0.f,0.f,40.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/60.f,/*aspect*/1.f);
    rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/AccelerationStructureGrid.png");
    rtBounceDepth(1);
    //rtUseShadow(false);
    rtShadowBias(1e-4f);
//	rtSampleRate(4);

    ////lighting
    rtAmbientLight(STColor3f(.1f,.1f,.1f));
    rtPointLight(STPoint3(0.f,0.f,10.f),STColor3f(1.f,1.f,1.f));

    ////objects
    int counts[3]={10,10,1};
    float size[3]={40.f,40.f,4.f};
    STPoint3 min_corner(-size[0]*.5f,-size[1]*.5f,-size[2]*.5f);
    STPoint3 max_corner(size[0]*.5f,size[1]*.5f,size[2]*.5f);
    STVector3 dx(size[0]/(float)counts[0],size[1]/(float)counts[1],size[2]/(float)counts[2]);

    int num_objs = 0;
    ////spheres and cubes
    for(int i=0;i<counts[0];i++){
        for(int j=0;j<counts[1];j++){
            for(int k=0;k<counts[2];k++){
                STColor3f color((float)rand()/RAND_MAX,(float)rand()/RAND_MAX,(float)rand()/RAND_MAX);
                Material mat(color,color,STColor3f(),STColor3f(),40.f);
                STVector3 perturb((float)rand()/RAND_MAX,(float)rand()/RAND_MAX,(float)rand()/RAND_MAX);
                STPoint3 center=min_corner+STVector3(dx.Component(0)*(float)(i+.5f+(perturb.Component(0)-.5f)*.2f),dx.Component(1)*(float)(j+.5f+(perturb.Component(1)-.5f)*.2f),dx.Component(2)*(float)(k+.5f+(perturb.Component(2)-.5f)*.2f));
                rtMaterial(mat);
                int mode=rand()%2;
                num_objs++;
                rtSphere(center,.75f);break;

            }
        }
    }
    printf("NUM OBJ: %d\n", num_objs);

	//background
	STColor3f background_color(.75f,.7f,.7f);
	Material background_mat(background_color,background_color,STColor3f(.2f,.2f,.2f),STColor3f(),40.f);
	rtMaterial(background_mat);
	addBackgroundWall(/*min_corner*/STPoint3(-size[0]*.6f,-size[1]*.6f,-2.f),/*size*/STVector2(size[0]*1.2f,size[1]*1.2f));

    ////use acceleration structure
    //////aabb tree
    accel_structure=AABB_TREE;
    AABBTree* aabb_tree=new AABBTree(objects);
    aabb_trees.push_back(aabb_tree);

    //////uniform grid
//    accel_structure=UNIFORM_GRID;
//    AABB scene_bounding_box;getObjectsAABB(objects,scene_bounding_box);
//    int subdivision[3]={20,20,2};
//    uniform_grid=new UniformGrid(objects,scene_bounding_box,subdivision);
}

void ExampleScene::initializeSceneAccelerationStructureBVH()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,0.f,30.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/60.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/AccelerationStructureBVH.png");
	rtBounceDepth(1);
	//rtUseShadow(false);
	rtShadowBias(1e-4f);
	//rtSampleRate(4);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(STPoint3(0.f,0.f,20.f),STColor3f(1.f,1.f,1.f));

	////objects
	std::vector<STPoint3> centers;
	centers.push_back(STPoint3(-10.f,5.f,0.f));
	centers.push_back(STPoint3(10.f,5.f,0.f));
	centers.push_back(STPoint3(0.f,-5.f,0.f));

	int counts[3]={10,10,1};
	float size[3]={10.f,10.f,10.f};

	for(int i=0;i<(int)centers.size();i++){
		STPoint3 center=centers[i];
		STPoint3 min_corner=center+STVector3(-size[0]*.5f,-size[1]*.5f,-size[2]*.5f);
		STPoint3 max_corner=center+STVector3(size[0]*.5f,size[1]*.5f,size[2]*.5f);
		STVector3 dx(size[0]/(float)counts[0],size[1]/(float)counts[1],size[2]/(float)counts[2]);
		for(int i=0;i<counts[0];i++){
			for(int j=0;j<counts[1];j++){
				for(int k=0;k<counts[2];k++){
					STVector3 perturb((float)rand()/RAND_MAX,(float)rand()/RAND_MAX,(float)rand()/RAND_MAX);
					STPoint3 pos=min_corner+STVector3(dx.Component(0)*(float)(i+.5f+(perturb.Component(0)-.5f)*.2f),dx.Component(1)*(float)(j+.5f+(perturb.Component(1)-.5f)*.2f),dx.Component(2)*(float)(k+.5f+(perturb.Component(2)-.5f)*.2f));
					if((pos-center).Length()>5.f){continue;}
					
					STColor3f color((float)rand()/RAND_MAX,(float)rand()/RAND_MAX,(float)rand()/RAND_MAX);
					Material mat(color,color,STColor3f(),STColor3f(),40.f);
					rtMaterial(mat);
					int mode=rand()%3;
					switch(mode){
                        case 0:rtSphere(pos,.3f);break;
                        case 1:rtBox(pos,STVector3(.6f));break;
                        case 2:rtCylinder(center, center+3, 0.5f);break;
					}
				}
			}
		}
	}

	////background
	STColor3f background_color(.6f,.1f,.0f);
	Material background_mat(background_color,background_color,STColor3f(.2f,.2f,.2f),STColor3f(),40.f);
	rtMaterial(background_mat);
	addBackgroundWall(/*min_corner*/STPoint3(-25.f,-25.f,-8.f),/*size*/STVector2(50.f,50.f));

	////use acceleration structure
	////aabb tree
//	accel_structure=AABB_TREE;
//	AABBTree* aabb_tree=new AABBTree(objects);
//	aabb_trees.push_back(aabb_tree);

	////////uniform grid
	accel_structure=UNIFORM_GRID;
	AABB scene_bounding_box;getObjectsAABB(objects,scene_bounding_box);
	int subdivision[3]={10,10,1};
	uniform_grid=new UniformGrid(objects,scene_bounding_box,subdivision);
}

void ExampleScene::initializeSceneTransparentObject()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(10.f,5.f,19.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(10.f,3.f,0.f),/*fov*/45.f,/*aspect*/1.33f);
	rtOutput(/*width*/640,/*height*/480,/*path*/"../Standard_Tests/TransparentObject.png");
	rtBounceDepth(5);
	rtUseTransparentShadow(true);
	rtShadowBias(.001f);
	rtSampleRate(4);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(STPoint3(15.f,10.f,15.f),STColor3f(.6f,.6f,.6f));
	rtPointLight(STPoint3(5.f,10.f,15.f),STColor3f(.6f,.6f,.6f));
	//rtPointLight(STPoint3(10.f,15.f,4.f),STColor3f(.2f,.2f,.2f));

	Material mat_glass1(/*ambient*/STColor3f(),/*diffuse*/STColor3f(),/*spec*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f,/*refr*/STColor3f(.9f,.3f,.1f),/*sn*/1.3f);
	Material mat_glass2(/*ambient*/STColor3f(),/*diffuse*/STColor3f(),/*spec*/STColor3f(1.f,1.f,1.f),/*mirror*/STColor3f(.1f,.1f,.1f),/*shiness*/30.f,/*refr*/STColor3f(.7f,.6f,.9f),/*sn*/1.3f);
	Material mat_metal(/*ambient*/STColor3f(.6f,.4f,.3f),/*diffuse*/STColor3f(.6f,.4f,.3f),/*spec*/STColor3f(.2f,.2f,.2f),/*mirror*/STColor3f(.6f,.4f,.3f),/*shiness*/90.f);

	rtMaterial(mat_glass1);
	rtSphere(STPoint3(6.f,1.01f,5.f),1.f);

	rtMaterial(mat_metal);
	rtCylinder(STPoint3(9.f,0.01f,5.f),STPoint3(9.f,3.01f,5.f),1.f);
	
	rtMaterial(mat_glass2);
	rtBox(STPoint3(12.f,2.01f,5.f),STVector3(2.f,4.f,.8f));

	////environment box
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(),STColor3f(),0.f);
	Material mat_wall(STColor3f(1.f,1.f,1.f),STColor3f(.4f,.2f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ground);
	////ground
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);
	rtMaterial(mat_wall);
	////ceil
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),false);
	////background wall
	addBackgroundWall(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);
	////forward wall
	addBackgroundWall(STPoint3(0.f,0.f,20.f),STVector2(20.f,20.f),false);
	////left wall
	addWall(STPoint3(0.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),true);
	////right wall
	addWall(STPoint3(20.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),false);
}

void ExampleScene::initializeSceneTransparentObject2()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(10.f,6.f,19.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(10.f,3.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/TransparentObject2.png");
	rtBounceDepth(5);
	rtUseTransparentShadow(true);
	rtShadowBias(1e-4f);
	rtSampleRate(4);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(STPoint3(10.f,10.f,15.f),STColor3f(.2f,.2f,.2f));
	rtPointLight(STPoint3(10.f,10.f,5.f),STColor3f(.2f,.2f,.2f));
	rtPointLight(STPoint3(5.f,10.f,8.f),STColor3f(.2f,.2f,.2f));
	rtPointLight(STPoint3(15.f,10.f,8.f),STColor3f(.2f,.2f,.2f));
	rtPointLight(STPoint3(10.f,8.f,16.f),STColor3f(.2f,.2f,.2f));
	Material mat(STColor3f(.5f,.5f,.5f),STColor3f(.3f,.3f,.3f),STColor3f(),STColor3f(),10.f);
	Material mat_glass(/*ambient*/STColor3f(.1f,.1f,.1f),/*diffuse*/STColor3f(),/*spec*/STColor3f(0.5f,0.5f,0.5f),/*mirror*/STColor3f(.2f,.2f,.2f),/*shiness*/30.f,/*refr*/STColor3f(.7f,.6f,.9f),/*sn*/1.2f);
	rtMaterial(mat_glass);
	rtAttenuation(1.f);

	rtPushMatrix();
	rtTranslate(10.f,.2f,8.f);
	rtScale(30.f,30.f,30.f);
	rtTriangleMesh("../Standard_Tests/bunny.obj",true,false);
	rtPopMatrix();

	////environment box
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ground);
	////ground
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);

	////ceil
	Material mat_ceil(STColor3f(1.f,1.f,1.f),STColor3f(.2f,.2f,.48f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ceil);
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),false);
	////background wall
	Material mat_wall(STColor3f(1.f,1.f,1.f),STColor3f(.4f,.2f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_wall);
	addBackgroundWall(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);
	//////forward wall
	addBackgroundWall(STPoint3(0.f,0.f,20.f),STVector2(20.f,20.f),false);
	////left wall
	Material mat_left_wall(STColor3f(1.1f,1.f,1.f),STColor3f(.1f,.8f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_left_wall);
	addWall(STPoint3(0.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),true);
	////right wall
	Material mat_right_wall(STColor3f(1.1f,1.f,1.f),STColor3f(.1f,.2f,.8f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_right_wall);
	addWall(STPoint3(20.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),false);
}

void ExampleScene::initializeSceneObjMesh()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(10.f,6.f,23.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(10.f,3.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/ObjMesh.png");
	rtBounceDepth(10);
	rtShadowBias(1e-4f);
	rtSampleRate(2);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(STPoint3(15.f,10.f,15.f),STColor3f(.8f,.8f,.8f));
	rtPointLight(STPoint3(5.f,10.f,15.f),STColor3f(.2f,.2f,.2f));

	Material mat(STColor3f(.5f,.5f,.5f),STColor3f(.5f,.5f,.5f),STColor3f(),STColor3f(),10.f);
	rtMaterial(mat);
	rtPushMatrix();
	rtTranslate(10.f,3.5f,8.f);
	rtRotate(-90.f,0.f,0.f);
	rtScale(.1f,.1f,.1f);
	rtTriangleMesh("../Standard_Tests/totoro.obj",true,false);
	rtPopMatrix();

	Material mat3(STColor3f(.6f,.8f,.9f),STColor3f(.6f,.8f,.9f),STColor3f(),STColor3f(),10.f);
	rtMaterial(mat3);
	rtPushMatrix();
	rtTranslate(13.f,1.5f,10.f);
	rtRotate(-90.f,0.f,0.f);
	rtScale(.04f,.04f,.04f);
	rtTriangleMesh("../Standard_Tests/totoro.obj",true,false);
	rtPopMatrix();

	////environment box
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ground);
	////ground
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);

	Material mat_wall(STColor3f(1.f,1.f,1.f),STColor3f(.4f,.2f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_wall);
	////ceil
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),false);
	////background wall
	addBackgroundWall(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);
	//////forward wall
	//addBackgroundWall(STPoint3(0.f,0.f,20.f),STVector2(20.f,20.f),false);
	////left wall
	addWall(STPoint3(0.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),true);
	////right wall
	addWall(STPoint3(20.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),false);
}

void ExampleScene::initializeSceneObjMesh2()
{
    rtClear();

    ////global settings
    rtCamera(/*eye*/STPoint3(0.f,0.f,15.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/45.f,/*aspect*/1.f);
    rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/ObjMesh2.png");
    rtBounceDepth(10);
    rtShadowBias(1e-4f);
    rtSampleRate(4);

    ////lighting
    rtAmbientLight(STColor3f(.1f,.1f,.1f));
    rtPointLight(STPoint3(10.f,15.f,10.f),STColor3f(1.f,1.f,1.f));

    ////default material
    Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(),STColor3f(),30.f);
    rtMaterial(mat_ground);

    ////plane
    rtPushMatrix();
    rtScale(6e-4f,6e-4f,6e-4f);
    rtTriangleMeshWithMaterialAndTexture("../Standard_Tests/turbosonic/turbosonic.obj",true,false);
    rtPopMatrix();

    //////wall
    addWall(STPoint3(-10.f,-10.f,-1.f),STVector3(20.f,0.f,0.f),STVector3(0.f,20.f,0.f),true);
}

void ExampleScene::initializeSceneTexture()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,0.f,12.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Custom_Tests/Texture.png");
	rtBounceDepth(1);
	rtUseShadow(true);
	rtShadowBias(1e-4f);

	int tex_id;rtLoadTexture("../Custom_Tests/scene2/textures/sky.jpg",tex_id);
	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(/*location*/STPoint3(-3.f,-3.f,6.f),STColor3f(.8f,.8f,.8f));

	////objects
	////sphere
	Material mat_sphere(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(1.f,1.f,0.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_sphere);
	rtSphere(STPoint3(1.f,1.f,0.f),.5f);

	////triangle
	Material mat_tri(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(1.f,1.f,1.f),/*specular*/STColor3f(.2f,.2f,.2f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/40.f);
	rtMaterial(mat_tri);
	rtBindTexture(tex_id);
	rtTriangle(/*v1*/STPoint3(-4.f,-4.f,0.f),/*v2*/STPoint3(4.f,-4.f,0.f),/*v3*/STPoint3(4.f,4.f,0.f),
		/*uv1*/STPoint2(0.f,0.f),/*uv2*/STPoint2(1.f,0.f),/*uv3*/STPoint2(1.f,1.f));
	rtTriangle(/*v1*/STPoint3(-4.f,-4.f,0.f),/*v2*/STPoint3(4.f,4.f,0.f),/*v3*/STPoint3(-4.f,4.f,0.f),
		/*uv1*/STPoint2(0.f,0.f),/*uv2*/STPoint2(1.f,1.f),/*uv3*/STPoint2(0.f,1.f));
	rtUnbindTexture();
}

void ExampleScene::initializeSceneDepthOfField()
{
	rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(0.f,1.f,6.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(0.f,0.f,0.f),/*fov*/55.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Standard_Tests/DepthOfField.png");
	rtBounceDepth(3);
	rtUseShadow(true);
	rtShadowBias(1e-4f);
	rtSampleRate(4);

	rtAmbientLight(STColor3f(.1f,.1f,.1f));
	rtPointLight(STPoint3(0.f,3.f,2.f),STColor3f(1.f,1.f,1.f));

	////ground
	Material mat_tri(/*ambient*/STColor3f(1.f,1.f,1.f),/*diffuse*/STColor3f(.4f,.4f,.4f),/*specular*/STColor3f(.0f,.0f,.0f),/*mirror*/STColor3f(.9f,.9f,.9f),/*shiness*/0.f);
	rtMaterial(mat_tri);
	addGround(STPoint3(-500.f,-1.f,-500.f),STVector2(1000.f,1000.f),true);

	////sphere1
	Material mat_sphere1(/*ambient*/STColor3f(1.f,.75f,.75f),/*diffuse*/STColor3f(1.f,.75f,.75f),/*specular*/STColor3f(1.f,1.f,1.f),/*mirror*/STColor3f(.75f,.75f,.75f),/*shiness*/50.f);
	rtMaterial(mat_sphere1);
	rtSphere(STPoint3(1.f,0.f,-3.f),1.f);

	////sphere2
	Material mat_sphere2(/*ambient*/STColor3f(.75f,.75f,1.f),/*diffuse*/STColor3f(.75f,.75f,1.f),/*specular*/STColor3f(0.f,0.f,0.f),/*mirror*/STColor3f(0.f,0.f,0.f),/*shiness*/0.f);
	rtMaterial(mat_sphere2);
	rtSphere(STPoint3(-1.f,0.f,-1.f),1.f);

	////sphere3
	Material mat_sphere3(/*ambient*/STColor3f(.0f,1.f,.0f),/*diffuse*/STColor3f(.0f,1.f,.0f),/*specular*/STColor3f(.3f,.3f,.3f),/*mirror*/STColor3f(0.f,0.3f,0.f),/*shiness*/50.f);
	rtMaterial(mat_sphere3);
	rtSphere(STPoint3(.2f,-.5f,1.f),.5f);
	
	////set focus on sphere 3
	rtSetApeture(2.f);
	rtSetFocus(STPoint3(.2f, -.5f, 1.f));
}

void ExampleScene::initializeSceneParticipatingMedia()
{
    rtClear();

	////global settings
	rtCamera(/*eye*/STPoint3(10.f,6.f,19.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(10.f,3.f,0.f),/*fov*/45.f,/*aspect*/1.f);
	rtOutput(/*width*/512,/*height*/512,/*path*/"../Custom_Tests/ParticipatingMedia.png");
	rtBounceDepth(5);
	//rtUseTransparentShadow(true);
    rtUseShadow(false);
	rtShadowBias(1e-4f);
	//rtSampleRate(4);

	////lighting
	rtAmbientLight(STColor3f(.1f,.1f,.1f));
//	rtPointLight(STPoint3(10.f,10.f,15.f),STColor3f(.2f,.2f,.2f));
//	rtPointLight(STPoint3(10.f,10.f,5.f),STColor3f(.2f,.2f,.2f));
//	rtPointLight(STPoint3(5.f,10.f,8.f),STColor3f(.2f,.2f,.2f));
//	rtPointLight(STPoint3(15.f,10.f,8.f),STColor3f(.2f,.2f,.2f));
//	rtPointLight(STPoint3(10.f,8.f,16.f),STColor3f(.2f,.2f,.2f));
	Material mat(STColor3f(.5f,.5f,.5f),STColor3f(.3f,.3f,.3f),STColor3f(),STColor3f(),10.f);

	////environment box
	Material mat_ground(STColor3f(1.f,1.f,1.f),STColor3f(.8f,.8f,.8f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ground);
	////ground
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);

	////ceil
	Material mat_ceil(STColor3f(1.f,1.f,1.f),STColor3f(.2f,.2f,.48f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_ceil);
	addGround(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),false);
	////background wall
	Material mat_wall(STColor3f(1.f,1.f,1.f),STColor3f(.4f,.2f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_wall);
	addBackgroundWall(STPoint3(0.f,0.f,0.f),STVector2(20.f,20.f),true);
	//////forward wall
	addBackgroundWall(STPoint3(0.f,0.f,20.f),STVector2(20.f,20.f),false);
	////left wall
	Material mat_left_wall(STColor3f(1.1f,1.f,1.f),STColor3f(.1f,.8f,.1f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_left_wall);
	addWall(STPoint3(0.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),true);
	////right wall
	Material mat_right_wall(STColor3f(1.1f,1.f,1.f),STColor3f(.1f,.2f,.8f),STColor3f(),STColor3f(),30.f);
	rtMaterial(mat_right_wall);
	addWall(STPoint3(20.f,0.f,0.f),STVector3(0.f,20.f,0.f),STVector3(0.f,0.f,20.f),false);

    ////fire participating medium
    Material participating_medium(STColor3f(1.f,0.f,1.f),STColor3f(0.f,0.f,1.f),STColor3f(0.f,0.f,0.f),STColor3f(0.f,0.f,0.f),0.f);
    VolumetricTexture* volume_tex = new VolumetricTexture("../Standard_Tests/sim_grid.txt");

    rtVolumetricTexture(volume_tex);
    participating_medium.volumetric_texture=volume_tex;
    rtMaterial(participating_medium);
    STPoint3 o(2.5f,1.f,4.f);
    STPoint3 x=o;x.x+=10.f;
    STPoint3 y=o;y.y+=5.f;
    STPoint3 z=o;z.z+=5.f;
    rtBox(o,x,y,z);
}

void ExampleScene::addGround(const STPoint3& min_corner,const STVector2& size,bool counterclockwise/*=true*/)
{
	if(counterclockwise){
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z));
		rtTriangle(min_corner,STPoint3(min_corner.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y));
	}
	else{
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y));
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x,min_corner.y,min_corner.z+size.y));
	}
}

void ExampleScene::addBackgroundWall(const STPoint3& min_corner,const STVector2& size,bool counterclockwise/*=true*/)
{
	if(counterclockwise){
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z));
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x,min_corner.y+size.y,min_corner.z));
	}
	else{
		rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z));
		rtTriangle(min_corner,STPoint3(min_corner.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z));
	}
}

void ExampleScene::addWall(const STPoint3& min_corner,const STVector3& u,const STVector3& v,bool counterclockwise/*=true*/)
{
	if(counterclockwise){
		rtTriangle(min_corner,min_corner+u,min_corner+u+v);
		rtTriangle(min_corner,min_corner+u+v,min_corner+v);
	}
	else{
		rtTriangle(min_corner,min_corner+u+v,min_corner+u);
		rtTriangle(min_corner,min_corner+v,min_corner+u+v);
	}
}

/* -------------------------- Rendering Code for Assignment 6 / Final ----------------------- */


void ExampleScene::addGroundTexture(const STPoint3& min_corner,const STVector2& size,bool counterclockwise/*=true*/)
{
    if(counterclockwise){
        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
        rtTriangle(min_corner,STPoint3(min_corner.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
    }
    else{
        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z+size.y),STPoint3(min_corner.x,min_corner.y,min_corner.z+size.y),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
    }
}

void ExampleScene::addBackgroundWallTexture(const STPoint3& min_corner,const STVector2& size,bool counterclockwise/*=true*/)
{
    if(counterclockwise){
        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
//        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x,min_corner.y+size.y,min_corner.z),
//                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
    }
    else{
        rtTriangle(min_corner,STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y,min_corner.z),
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f)
        );
//        rtTriangle(min_corner,STPoint3(min_corner.x,min_corner.y+size.y,min_corner.z),STPoint3(min_corner.x+size.x,min_corner.y+size.y,min_corner.z),
//                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f)
//        );
    }
}

void ExampleScene::addWallTexture(const STPoint3& min_corner,const STVector3& u,const STVector3& v,bool counterclockwise/*=true*/)
{
    if(counterclockwise){
        rtTriangle(min_corner,min_corner+u,min_corner+u+v,
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
        rtTriangle(min_corner,min_corner+u+v,min_corner+v,
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
    }
    else{
        rtTriangle(min_corner,min_corner+u+v,min_corner+u,
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
        rtTriangle(min_corner,min_corner+v,min_corner+u+v,
                   STPoint2(0.f, 0.f), STPoint2(1.f, 0.f), STPoint2(1.f, 1.f));
    }
}

void ExampleScene::initializeFinalScene()
{
    rtClear();
    
    ////global settings
    rtCamera(/*eye*/STPoint3(10.f,7.f,25.f),/*up*/STVector3(0.f,1.f,0.f),/*lookat*/STPoint3(10.f,3.f,0.f),/*fov*/45.f,/*aspect*/1.7f);
    rtOutput(/*width*/910,/*height*/512,/*path*/"../Custom_Tests/AssignmentFinal.png");
    rtBounceDepth(3);
    rtShadowBias(1e-4f);
    rtUseShadow(false);
    rtSampleRate(6);
    
    ///////////////////////////////////////
    //// Lighting
    //// Use a mixture of lights.
    //// Name output files based on the
    //// mixture of lights from experiments
    ///////////////////////////////////////

    rtAmbientLight(STColor3f(.3f,.3f,.3f));
    rtPointLight(STPoint3(5.3f,7.f,10.f), STColor3f(.9f,.9f,.9f));
    
    ///////////////////////////////////////
    //// Objects
    //// (some unused from last scene)
    ///////////////////////////////////////
  
    // stone
    rtPushMatrix();
    rtTranslate(3.3f,0.f,3.9f);
    rtRotate(15.f,15.f,0.f);
    rtScale(1.1f,1.1f,1.1f);
    rtTriangleMeshWithMaterialAndTexture("../Custom_Tests/scene2/obj_files/stone.obj",true,false);
    rtPopMatrix();
    
    // sword
    rtPushMatrix();
    Material mat_sword(/*ambient*/STColor3f(0.6f,.4f,.3f),
                       /*diffuse*/STColor3f(1.f,1.f,1.f),
                       /*spec*/STColor3f(.2f,.2f,.2f),
                       /*mirror*/STColor3f(.6f,.4f,.3f),
                       /*shiness*/90.f);
    rtTranslate(3.3f,-0.5f,4.f);
    rtScale(0.75f,0.75f,0.75f);
    rtTriangleMeshWithTextureAndCustomMaterial("../Custom_Tests/scene2/obj_files/sword.obj",true,false, &mat_sword);
    rtPopMatrix();
    
    
    ////////////////////////////////////////
    //// Temple, with flames as
    //// participating media
    ///////////////////////////////////////
    
    rtPushMatrix();
    rtTranslate(30.f,0.f,-15.f);
    rtRotate(0.f,-45.f,0.f);
    rtScale(.6f,.6,.6f);
    rtTriangleMeshWithMaterialAndTexture("../Custom_Tests/scene2/obj_files/test2.obj",true,false);

    
    ////fire participating medium
    Material participating_medium(
      /*ambient*/STColor3f(),
      /*diffuse*/STColor3f(),
      /*spec*/STColor3f(1.f,1.f,1.f),
      /*mirror*/STColor3f(.1f,.1f,.1f),
      /*shiness*/30.f,
      /*refr*/STColor3f(.7f,.6f,.9f),
      /*sn*/1.3f);
    VolumetricTexture* volume_tex = new VolumetricTexture("../Standard_Tests/sim_grid.txt");
    
    rtVolumetricTexture(volume_tex);
    participating_medium.volumetric_texture=volume_tex;
    
    float x_delta = -2.f;
    float y_delta = 1.25f;
    float z_delta = -3.85f;
    
    // left flame
    rtMaterial(participating_medium);
    STPoint3 o1(-3.8, 1.49, -0.18);
    o1.x += x_delta;
    o1.y += y_delta;
    o1.z += z_delta;
    STPoint3 x=o1;x.x+=3.f;
    STPoint3 y=o1;y.y+=10.f;
    STPoint3 z=o1;z.z+=6.f;
    rtBox(o1,x,y,z);
    
    // right flame
    STPoint3 o2(-19.4, 1.5, -0.08);
    o2.x += x_delta;
    o2.y += y_delta;
    o2.z += z_delta;
    STPoint3 x2=o2;x2.x+=3.f;
    STPoint3 y2=o2;y2.y+=10.f;
    STPoint3 z2=o2;z2.z+=6.f;
    rtBox(o2,x2,y2,z2);
    
    rtPopMatrix();
    
    
    ///////////////////////////////////////
    //// Water
    ///////////////////////////////////////

    Material mat_water(/*ambient*/STColor3f(.3f,.3f,.3f),/*diffuse*/STColor3f(.1f, .1f, .1f),/*spec*/STColor3f(),/*mirror*/STColor3f(.7f,.7f,.7f), 40.f);
    rtPushMatrix();
    rtTranslate(-45.f,-1.f,-45.f);
    rtScale(27.5f,3.5,27.5f);
    rtTriangleMeshWithTextureAndCustomMaterial("../Custom_Tests/scene2/Ocean-tile.obj", true, false, &mat_water);
    rtPopMatrix();

    
    ///////////////////////////////////////
    //// Environment Box
    ///////////////////////////////////////
    
    int tex_id_sky;
    rtLoadTexture("../Custom_Tests/scene2/textures/sky-1.jpg",tex_id_sky);
    
    Material mat_sky(/*ambient*/STColor3f(),/*diffuse*/STColor3f(1.f,1.f,1.f),/*specular*/STColor3f(.8f,.8f,.8f),/*mirror*/STColor3f(1.f,1.f,1.f),/*shiness*/40.f);
    rtMaterial(mat_sky);
    rtBindTexture(tex_id_sky);

    // no ground - ocean is ground
    
    // background wall - main sunset
    STPoint3 bg_min_corner = STPoint3(-7500.f,-60.f,-3500.f);
//    STPoint3 bg_min_corner_1 = STPoint3(-5000.f,-60.f,200.f);
    STVector2 bg_size = STVector2(9500.f, 6000.f);
    rtRotate(-20.f, 0.f, 0.f);
    addBackgroundWallTexture(bg_min_corner, bg_size, true);
//    addBackgroundWallTexture(bg_min_corner_1, bg_size, false);

//    STPoint3 wall_min_corner = STPoint3(-6000.f,-60.f,-2000.f);
//    STVector3 wall_u = STVector3(10500.f, 4000.f, 20.f);
//    STVector3 wall_v = STVector3(10500.f, 4000.f, 20.f);
//    STPoint3 wall_min_corner_1 = STPoint3(6000.f,-60.f,2000.f);
//    addWallTexture(wall_min_corner, wall_u, wall_v, true);
//    addWallTexture(wall_min_corner_1, wall_u, wall_v, false);

    rtUnbindTexture();
    
    // speed-up
    accel_structure=AABB_TREE;
    AABBTree* aabb_tree=new AABBTree(objects);
    aabb_trees.push_back(aabb_tree);
}
