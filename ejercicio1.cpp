#include <iostream>
using namespace std;

/*Crear la clase personaje con vida, daño y clase string tres objetos: mago, guerrrero, soporte
funciòn que muestra su informacion
funcion que recibe curacion (dato entero) y aumenta su vida
funcion que recibe un daño y baja su vida (recibe objeto)*/

class Personaje{
    private:
        int vida;
        int danio;
        string clase;
    public:
        Personaje(int vida, int danio, string clase){
            this->vida = vida;
            this->danio = danio;
            this->clase = clase;
        }
        //Get 
        int getVIda(){
            return vida;
        }

        int getDanio(){
            return danio;
        }

        string getClase(){
            return clase;
        }

        //Funciones extra
        void mostrarInfo(){
            cout<<endl;
            cout<<"Clase: "<<clase<<endl;
            cout<<"Danio: "<<danio<<endl;
            cout<<"Vida: "<<vida<<endl;
        }

        void recibirCuracion(int curar){
            vida = vida + curar;
        }

        void recibirDano(Personaje p){
            vida = vida - p.getDanio();
        }
};

int main(){
    Personaje p1(200,20,"mago");
    Personaje p2(400,10,"guerrero");
    Personaje p3(100,6,"soporte");

    p1.recibirCuracion(p3.getDanio());
    p2.recibirDano(p1);

    cout <<"--IMPRIMIENTO EL USO DE LAS HABILIDADES--"<<endl;

    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();

    return 0;


}