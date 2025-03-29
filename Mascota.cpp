#include <iostream>
using namespace std;

class Mascota
{
	private:
		
		string nombre;
		int energia;
		int hambre;
		int aburrimiento;

	public:
		
		Mascota(string, int,int,int);

		void comer();
		void jugar();
		void dormir();
		void estado();

		void setNombre(string);
		void setEnergia(int);
		void setHambre(int);
		void setAburrimiento(int);

		string getNombre();
		int getEnergia();
		int getHambre();
		int getAburrimiento();
};

//Permite que el estado de la mascota no pase de 10, cuando es una suma
int limiteEstadoS(int estado_base, int estado_accion, int limite = 10) {
    int resultado = estado_base + estado_accion;
    if (resultado > limite) {
        return limite;
    }
    return resultado;  
}

//Tiene la misma funcion que la anterior, con la diferencia de que esta es para las restas
int limiteEstadoR(int estado_base, int estado_accion, int limite = 10) {
    int resultado = estado_base - estado_accion;
    if (resultado > limite) {
        return limite;
    }
    return resultado;  
}

//Constructor de la mascota
Mascota::Mascota(string _nombre, int _energia, int _hambre, int _aburrimiento)
{
	nombre = _nombre;
	energia = _energia;
	hambre = _hambre;
	aburrimiento = _aburrimiento;
}

//Para poder hacer las pequeñas animaciones
void esperar(int ms) 
{ 
    for(clock_t t=clock(); (clock()-t)*1000/CLOCKS_PER_SEC < ms;); 
}

//Se encarga de limpiar la pantalla 
void limpiar_pantalla() 
{ 
    cout << "\033[2J\033[H"; 
}

void Mascota::comer()
{
	//Si el hambre es menor a 10 se le sumara cinco
     hambre = limiteEstadoS(hambre, 5);

    //Al comer tambien dara un poco de energia
	
	energia = limiteEstadoS(energia, 2);

    //En cada accion que realiza mientras no se jugar, se aburrira 
    aburrimiento = limiteEstadoS(aburrimiento, 2);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
	cout <<"( o.o ) "<<endl;
	cout <<" > ^ <"<<endl;
    esperar(500);

    cout <<" /|_/|"<< endl;
	cout <<"( ^.^ ) "<<endl;
	cout <<" > O <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
	cout <<"( o.o ) "<<endl;
	cout <<" > ^ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
	cout <<"( ^.^ ) "<<endl;
	cout <<" > O <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
	cout <<"( ^.^ ) "<<endl;
	cout <<" > ^ <"<<endl;
    esperar(200);

    cout << "\n El Hambre de tu mascota es de: " << hambre <<"/10"<< "\n La Energia de tu mascota es de: " <<  energia <<"/10"<<  endl;
}
void Mascota::jugar()
{
	//Cuando esten jugando el aburrimiento sera menor
	
		aburrimiento = limiteEstadoR(aburrimiento, 5);

	//Si juegan tambien se le restara energia
	
		energia = limiteEstadoR(energia, 2);

        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( o.o ) "<<endl;
        cout <<" > ^ <"<<endl;
        esperar(500);
    
        cout <<" /|_/|"<< endl;
        cout <<"( ^.^ ) "<<endl;
        cout <<" > O <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( o.o ) "<<endl;
        cout <<" > ^ <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( ^.^ ) "<<endl;
        cout <<" > O <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( ^.^ ) "<<endl;
        cout <<" > ^ <"<<endl;
        esperar(200);
	
	cout << "EL Aburrimiento de tu mascota es de: " << aburrimiento<<"/10" << "\n La Energia de tu mascota es de: "<<energia <<"/10" <<  endl;
}

void Mascota::dormir()
{
	//En cada accion que realiza mientras no se jugar, se aburrira 
    aburrimiento = limiteEstadoS(aburrimiento, 2);

    energia = 10;

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( o.o ) "<<endl;
    cout <<" > ^ <"<<endl;
    esperar(500);

    cout <<" /|_/|"<< endl;
    cout <<"( o.- ) "<<endl;
    cout <<" > ^ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( -.o ) "<<endl;
    cout <<" > ^ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( -.- ) "<<endl;
    cout <<" > _ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( -.- ) "<<endl;
    cout <<" > _ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( -.- ) "<<endl;
    cout <<" > _ <"<<endl;
    esperar(500);

    limpiar_pantalla();
    cout <<" /|_/|"<< endl;
    cout <<"( ^.^ ) "<<endl;
    cout <<" > ^ <"<<endl;
    esperar(200);
	cout <<"Energia Restablecida "<< energia<<endl;
}
void Mascota::estado()
{

	cout << "\n---- Estado de " << nombre << " ----" << endl;
	cout << "Energia: " << energia << endl;
    cout << "Hambre: " << hambre << endl;
	cout << "Abirrido: " << aburrimiento << endl;

}

//setter para modificar los valores 
void Mascota::setNombre(string _nombre) {
	nombre = _nombre;
}
void Mascota::setEnergia(int _energia) {
	energia = _energia;
}

void Mascota::setHambre(int _hambre) {
	hambre = _hambre;
}
void Mascota::setAburrimiento(int _aburrimiento) {
	aburrimiento = _aburrimiento;
}

//getter para obtener los valores 
string Mascota::getNombre() {
	return nombre;
}
int Mascota::getEnergia() {
	return energia;
}
int Mascota::getHambre() {
	return hambre;
}
int Mascota::getAburrimiento() {
	return aburrimiento;
}

void menuJuego() {
	cout << "\n----Tu Mascota----"<<endl;
	cout << "1. Como esta tu mascota   " <<" /|_/|"<< endl;
	cout << "2. Dale de comer         " << " ( o.o )"<<endl;
	cout << "3. Juega con tu mascota   " <<" > ^ <"<<endl;
	cout << "4. A dormir" << endl;
    cout << "5. para salir"<< endl;
}

int main()
{
	string nombre;
	int opcion;

	cout << "Ingrese un nombre para su Mascota" << endl;
	cin >> nombre;


	Mascota Usuario = Usuario;
	Usuario.setNombre(nombre);
	Usuario.setEnergia(5);
	Usuario.setHambre(5);
	Usuario.setAburrimiento(5);


	do
	{
		menuJuego();
		cin >> opcion;
        limpiar_pantalla();
		switch (opcion)
		{
		case 1:
        Usuario.estado();
			break;

		case 2:
        Usuario.comer();
			break;

		case 3:
        Usuario.jugar();
			break;

		case 4:
        Usuario.dormir();
			break;

        case 5:
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( o.o ) "<<endl;
        cout <<" > ^ <"<<endl;
        esperar(500);
    
        cout <<" /|_/|"<< endl;
        cout <<"( o.o ) "<<endl;
        cout <<" > O <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( T.T ) "<<endl;
        cout <<" > ~ <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( T.T ) "<<endl;
        cout <<" > _ <"<<endl;
        esperar(500);
    
        limpiar_pantalla();
        cout <<" /|_/|"<< endl;
        cout <<"( T.T ) "<<endl;
        cout <<" > _ <"<<endl;
        esperar(500);
        
		cout << "Saliendo del juego..." << endl;
			break;
		default: cout << "Opcion Incorrecta" << endl;
		}


	} while (opcion!=5);
	
    return 0;
}

