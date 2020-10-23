#include <iostream>
#include "Grafo.h"
#include <windows.h>

using namespace std;

int main()
{
    Grafo G;
    G.Inicializa();

    int opc;

    G.InsertaVertice("Guadalajara");
    G.InsertaVertice("Puebla");
    G.InsertaVertice("DF");
    G.InsertaVertice("Zacatecas");
    G.InsertaVertice("Michoacan");
    G.InsertaVertice("Los Cabos");

    G.InsertaArista(G.GetVertice("Guadalajara"),G.GetVertice("DF"),500);
    G.InsertaArista(G.GetVertice("Guadalajara"),G.GetVertice("Zacatecas"),200);
    G.InsertaArista(G.GetVertice("Guadalajara"),G.GetVertice("Los Cabos"),600);
    G.InsertaArista(G.GetVertice("Puebla"),G.GetVertice("Michoacan"),100);
    G.InsertaArista(G.GetVertice("Puebla"),G.GetVertice("DF"),500);
    G.InsertaArista(G.GetVertice("DF"),G.GetVertice("Los Cabos"),200);
    G.InsertaArista(G.GetVertice("Zacatecas"),G.GetVertice("Puebla"),300);
    G.InsertaArista(G.GetVertice("Zacatecas"),G.GetVertice("Los Cabos"),300);
    G.InsertaArista(G.GetVertice("Michoacan"),G.GetVertice("Guadalajara"),400);
    G.InsertaArista(G.GetVertice("Michoacan"),G.GetVertice("DF"),300);
    G.InsertaArista(G.GetVertice("Los Cabos"),G.GetVertice("Michoacan"),300);

    do
    {
        system("cls");
        cout<<"1. Ingresar vertice"<<endl;
        cout<<"2. Ingresar arista"<<endl;
        cout<<"3. Lista de adyacencia"<<endl;
        cout<<"4. Tama�o"<<endl;
        cout<<"5. Elimnar vertice"<<endl;
        cout<<"6. Eliminar arista"<<endl;
        cout<<"7. Anular"<<endl;
        cout<<"8. Recorrido en anchura"<<endl;
        cout<<"9. Recorrido en profundidad"<<endl;
        cout<<"10. Primero en anchura"<<endl;
        cout<<"11. Primero en profundidad"<<endl;
        cout<<"12. Primero el mejor"<<endl;
        cout<<"13. Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;

        switch(opc)
        {
            case 1:
            {
                string nombre;
                system("cls");
                cout<<"Ingrese el nombre del vertice: ";
                cin.ignore();
                getline(cin,nombre, '\n');
                G.InsertaVertice(nombre);
                cin.get();
                cin.get();
                break;
            } //case 1
            case 2:
            {
                string origen, destino;
                int peso;
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo est� vacio"<<endl;
                }
                else
                {
                    cout<<"Ingresar del nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin,origen,'\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin, destino,'\n');
                    cout<<"Ingrese el peso: ";
                    cin>>peso;

                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Uno de los vertices no es valido"<<endl;
                    }
                    else
                    {
                        G.InsertaArista(G.GetVertice(origen), G.GetVertice(destino), peso);
                    }
                    cin.get();
                    cin.get();
                    break;
                }
            } //case 2
            case 3:
            {
                    system("cls");
                    if(G.Vacio())
                    {
                        cout<<"El grafo esta vacio"<<endl;
                    }
                    else
                    {
                        G.ListaAdyacencia();
                    }
                    cin.get();
                    cin.get();
                    break;
            } //case 3
            case 4:
            {
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Tama�o: "<<G.Tamano()<<endl;
                }
                cin.get();
                cin.get();
                break;
            } //case 4
            case 5:
            {
                string nombre;
                system("cls");

                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Ingrese el nombre del vertice a eliminar: ";
                    cin.ignore();
                    getline(cin, nombre, '\n');
                    if(G.GetVertice(nombre) == NULL)
                    {
                        cout<<"Vertice invalido"<<endl;
                    }
                    else
                    {
                        G.EliminarVertice(G.GetVertice(nombre));
                    }
                }
                cin.get();
                cin.get();
                break;

            } //case 5
            case 6:
            {
                string origen, destino;
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Ingrese el nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin, origen, '\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin,destino, '\n');
                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Vertices no validos"<<endl;
                    }
                    else
                    {
                        G.EliminarArista(G.GetVertice(origen), G.GetVertice(destino));
                    }
                    cin.get();
                    cin.get();
                    break;
                }
            }//case 6
            case 7:
            {
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    G.Anular();
                }
                cin.get();
                cin.get();
                break;
            }//case 7
            case 8:
            {
                 string nombre;
                 system("cls");
                 if(G.Vacio())
                 {
                     cout<<"El grafo esta vacio"<<endl;
                 }
                 else
                 {
                    cout<<"Ingrese el nombre del vertice incial: ";
                    cin.ignore();
                    getline(cin, nombre, '\n');
                    if(G.GetVertice(nombre) == NULL)
                    {
                        cout<<"Ese vertice es invalido"<<endl;
                    }
                    else
                    {
                        G.RecorridoAnchura(G.GetVertice(nombre));
                    }
                    cin.get();
                    cin.get();
                    break;
                 }
            }//case 8
            case 9:
            {
                 string nombre;
                 system("cls");
                 if(G.Vacio())
                 {
                     cout<<"El grafo esta vacio"<<endl;
                 }
                 else
                 {
                    cout<<"Ingrese el nombre del vertice incial: ";
                    cin.ignore();
                    getline(cin, nombre, '\n');
                    if(G.GetVertice(nombre) == NULL)
                    {
                        cout<<"Ese vertice es invalido"<<endl;
                    }
                    else
                    {
                        G.RecorridoProfundidad(G.GetVertice(nombre));
                    }
                    cin.get();
                    cin.get();
                    break;
                 }
            }//case 9
            case 10:
            {
                string origen, destino;
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Ingrese el nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin, origen, '\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin,destino, '\n');
                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Vertices no validos"<<endl;
                    }
                    else
                    {
                        G.PrimeroAnchura(G.GetVertice(origen), G.GetVertice(destino));
                    }
                    cin.get();
                    cin.get();
                    break;
                }
            }//case 10
            case 11:
            {
                string origen, destino;
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    cout<<"Ingrese el nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin, origen, '\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin,destino, '\n');
                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Vertices no validos"<<endl;
                    }
                    else
                    {
                        G.PrimeroProfundidad(G.GetVertice(origen), G.GetVertice(destino));
                    }
                    cin.get();
                    cin.get();
                    break;
                }
            }//case 11
            case 12:
            {
                string origen, destino;
                system("cls");
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                    cin.get();
                    cin.get();
                }
                else
                {
                    cout<<"Ingrese el nombre del vertice origen: ";
                    cin.ignore();
                    getline(cin, origen, '\n');
                    cout<<"Ingrese el nombre del vertice destino: ";
                    getline(cin, destino, '\n');
                    if(G.GetVertice(origen) == NULL || G.GetVertice(destino) == NULL)
                    {
                        cout<<"Vertices invalidos"<<endl;
                    }
                    else
                    {
                        G.PrimeroMejor(G.GetVertice(origen), G.GetVertice(destino));
                    }
                }
                cin.get();
                cin.get();
                break;
            } //case 12
            case 13:
            {
                if(G.Vacio())
                {
                    cout<<"El grafo esta vacio"<<endl;
                }
                else
                {
                    G.Anular();
                }
                break;
            }
        }//switch
    }while(opc != 13);

}
