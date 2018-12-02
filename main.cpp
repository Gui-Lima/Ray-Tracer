#include <iostream>
#include <fstream>
#include "Object/Object.h"
#include "Camera/Camera.h"
#include "Scene/Scene.h"
#include <cstdlib>

using namespace std;


//Apernas criando a imagem
void saveStringToFile(std::string imagePBM){
    std::ofstream myFile;
    myFile.open("saida.pbm");
    myFile << imagePBM;
    myFile.close();
}

std::string imageRender(int sizeX, int sizeY, Camera cam, Scene c ){
    std::string stringedFile = "";
    stringedFile.append("P3\n" + std::to_string(sizeX) + " " + std::to_string(sizeY) + "\n255\n");
    Vec3 col(0, 0, 0);
    int samples=5;
    //Iterando ao longo dos pixels e renderizando
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {

            for(int k=0; k<samples; k++){
                float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float u = (j+random) / float(sizeX);
                float v = (i+random) / float(sizeY);
                Ray r = cam.getRay(u, v);
                col += c.trace(r);
            }

            col = col / samples;
            int ir = std::min(255, int(col[0]));
            int ig = std::min( 255, int(col[1]));
            int ib = std::min( 255, int(col[2]));
            //Escrevendo os pixels na imagem
            stringedFile.append(std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib) + "\n");
        }
    }

    return stringedFile;
}


void leituraDOIDA(){
    /* ENTRADA:
     * X Ÿ -> Resolução
     * Ox Oy Oz Tx Ty Tz Ux Uy Uz FOV NEAR -> Camera
     * Numero de Materiais
     * R G B KS KD KE ALPHA x Numero de Materiais -> Materiais
     * X Y Z Raio x Numero de Materiais -> Esferas
     */

    int resX, resY;
    cin >> resX >> resY;
    float Ox, Oy, Oz, Tx, Ty, Tz, Ux, Uy, Uz,fov,near;
    cin >> Ox >> Oy >> Oz >> Tx >> Ty >> Tz >> Ux >> Uy >> Uz >> fov >> near;
    cout << "Lido: " << Ox << " " << Oy << " " << Oz << " " << Tx << " " << Ty << " " << Tz << " " << Ux << " " << Uy << " " << Uz << " " << fov << " " << near << endl;
    Vec3 Origin{Ox, Oy, Oz};
    Vec3 Target{Tx, Ty, Tz};
    Vec3 Up{Ux, Uy, Uz};
    Camera c(Origin, fov, Target, near,Up, resX, resY);

    int quantidadeMateriais;
    cin >> quantidadeMateriais;
    Material* m[quantidadeMateriais];
    for (int i =0;i<quantidadeMateriais;i++){
        float r,g,b,ks,kd,ke,alpha;
        cin >> r >> g >> b >> ks >> kd >> ke >> alpha;
        cout << "Lido: " << r << " " << g << " " << b << " " << ks << " " << kd << " " << ke << " " << alpha << endl;
        Vec3 color(r,g,b);
        m[i] = new Material(color, ks, kd, ke, alpha);
    }
    int quantidadeDeEsferas;
    cin >> quantidadeDeEsferas;

    Sphere* sp[quantidadeDeEsferas];
    Object* ob[quantidadeDeEsferas];
    Scene cena;
    for(int i =0;i<quantidadeDeEsferas;i++){
        int relacMat;
        cin >> relacMat;
        float x,y,z,raio;
        cin >> x >> y >> z >> raio;
        cout << "Lido :" << x << " " << y << " " << z << " " << raio << endl;
        Vec3 pos(x,y,z);
        sp[i] = new Sphere(pos, raio);
        ob[i] = new Object(sp[i], m[relacMat]);
        cena.add(ob[i]);
    }

    saveStringToFile(imageRender(resX, resY,c,cena));
}


int main() {
    //Resolução
    leituraDOIDA();


    return 0;
}