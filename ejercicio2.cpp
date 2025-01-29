#include <iostream>
using namespace std;

/*Crear la clase auto: rendimiento (km/lt), litros y color de auto
el usuario ingresa los datos 
funcion que muestra la cantidad de kilometros que es capaz de recorrer
funcion que recibe otro auto y compara los rendimientos
funcion cargar gasolina*/

class Auto{
    private:
        int rendimiento;
        int litros;
        string color;
    public:
        Auto(int rendimiento, int litros, string color){
            this-> rendimiento = rendimiento;
            this-> litros = litros;
            this-> color = color;
        }

    // Get
    int getRendimiento(){
        return rendimiento;
    }
    int getLitros(){
        return litros;
    }
    string getColor(){
        return color;
    }

    /*FUNCIONES EXTRA*/
    void getRecorrido(){
        cout<<"El auto puede recorrer: "<<rendimiento*litros<<endl;
    }

    void compararRendimiento(Auto a){
        if (rendimiento > a.getRendimiento()){
            cout <<"El auto de color"<<color<<" tiene mayor rendimiento"<<endl;
        }else if (rendimiento == a.getRendimiento()){
            cout<<"Tienen el mismo rendimiento"<<endl;
        } else{
            cout<<"El auto de color "<<a.getColor()<<" tiene mayor rendimiento."<<endl;
        }
        
    }

    void cargarGasolina(int gasolina){
        litros = litros + gasolina;
    }
};

int main(){
    int r,l;
    string c;
    
    cout<<"--CREANDO SU AUTO"<<endl;
    cout<<"Rendimiento: "<<endl;
    cin>>r;
    cout<<"Litros: "<<endl;
    cin>>l;
    cout<<"Color: "<<endl;
    cin>>c;

    Auto a(r,l,c);
    Auto b(250,30,"red");

    cout<<"---------"<<endl;
    a.getRecorrido();
    cout<<"----------"<<endl;
    a.compararRendimiento(b);

    cout<<"--------"<<endl;
    cout<<"Gasolina del auto del color "<<a.getColor()<<" es de: "<<a.getLitros()<<endl;
    return 0;
}