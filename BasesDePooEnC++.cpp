#include <iostream>;
using namespace std;

class Person{
    protected: // Asi permitimos que la clase padre tenga hijos. (EN PRIVADO NO PODRA HEREDAR)
        string nombre; /*ATRIBUTO*/
        int edad; /*ATRIBUTO*/
    
    public:
     /*CONSTRUCTOR*/
        Person(string _nombre, int _edad){
            this->nombre = _nombre;
            this->edad = _edad;
        }
    /*FIN CONSTRUCTOR*/

    /*METODOS*/
        string getNombre(){ /*EJEMPLO METODO (OBTENER NOMBRE)*/
            return nombre;
        }

        int getEdad(){ /*EJEMPLO METODO (OBTENER EDAD)*/
            return edad;
        }

        void setNombre(string _nombre){ /*EJEMPLO METODO (CAMBIAR NOMBRE)*/
            nombre = _nombre;
        }
        
        void setEdad(int _Edad){ /*EJEMPLO METODO (CAMBIAR EDAD)*/
            edad = _Edad;
        }
    /*FIN METODOS*/

    /*METODO EXTRA*/


    virtual void Presentarse(){ // Se declara virtual para poder usar el polimorfismo
        cout << "Mi nombre es "<<nombre<<" y tengo "<<edad<< "anios."<<endl;
    }

    /*FIN METODO EXTRA*/
};


class Profesor : public Person{
    private: // Sus atributos pueden ser privados ya que no tendra hijos.
        int clases;
        string materia;
    
    // Constructor
    public:
        Profesor(string nombre, int edad, string materia, int clases) : Person(nombre, edad){
            this-> materia = materia;
            this-> clases = clases;
        }
    // Fin Constructor

    //Metodos
    int getClases(){
        return clases;
    }

    string getMateria(){
        return materia;
    }

    //Fin metodos



    /*METODO EXTRA*/

    virtual void Presentarse(){ // Se declara virtual para poder usar el polimorfismo
        cout << "Mi nombre es "<<nombre<<" y tengo "<<edad<< "anios."<<endl;
        cout << "Doy el numero de clases de "<< clases <<" y la materia "<< materia << endl;
    }

    /*FIN METODO EXTRA*/
};

int main (){
    // Crear Objeto
    Person *p1 = new Person("Estebxn", 25);
    Person *p2 = new Profesor("Roberto", 35, "Fisica", 2);



    //Todos nuestros objetos a un arreglo
    Person *personas[] = {p1,p2};

    for(int i=0; i <2; i++){ 
        personas[i]->Presentarse(); // Imprimir todos los objetos de manera sencilla.
    }

    return 0;
}