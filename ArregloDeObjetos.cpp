#include <iostream>
using namespace std;

class Cancion{
    private:
        string nombre;
        string autor;

    public:
        Cancion(string nombre, string autor){
            this->nombre = nombre;
            this->autor = autor;
        }
        string getNombre(){
            return nombre;
        }
        string getAutor(){
            return autor;
        }
        void infoCancion(){
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Autor: "<<autor<<endl;
        }
};

int main(){

    int index;
    Cancion s1("song1", "a1");
    Cancion s2("song2", "a2");
    Cancion s3("song3", "a3");

    Cancion play_list[] = {s1,s2,s3};

    for(int i=0; i<3; i++){ // Recorrer
        play_list[i].infoCancion();
    }

    cout<<"Ingrese un numero del 1 al 3, para escuchar la cancion"<<endl;
    cin>>index;

    play_list[index-1].infoCancion();

    return 0;

}

