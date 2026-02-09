#include <iostream>
#include <limits>
#include <conio.h>
#include <stdlib.h>

using namespace std;
int main()
{
    char sali;
    int temp,temp2,res;
    float num;
    do{
    	system("cls");
    	temp = 0,res = 1;
		cout<<"Ingresa el tope de la serie fibonacci: ";
    	while (true)                    
    	{
        	if (cin >> num)            
        	{
           	 break;
        	}
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cout << "Valor de entrada no valido. Introduce un numero entero: ";
    	}
   
    	if (num<=0){
        	do{
           	 cout<<"Numero no valido, ingresa un numero mayor a cero: ";
           	 while (true)                    
           	 {
           	     if (cin >> num)   
            	    {
                	    break;
                	}
                	cin.clear();
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	cout << "Valor de entrada no valido. Introduce un numero entero: ";
            	}
        	}while (num<=0);
    	}
    	
    	cout<<"Ingresa el numero de opcion del bucle a utilizar:\n1.For\n2.While \n3.Do While\n";
		getch();
		cout<<"La sequencia seria: \n";
		do{
			res+=temp;
			if (temp==0){
				cout << temp << " " << res << " ";
				temp=res;
			} else {	
				temp2=res;
				res=temp;
				temp=temp2;
				if(res+temp > num){
					cout<<temp;
					break;
				}	
			}
			cout << temp << " ";
			if(res+temp > num){
				break;
			}
			
		} while (res != num);
		
		cout << " | " << num;
		cout<<"\nPresiona [S] si deseas reiniciar el programa, presiona cualquiera otra tecla para salir.\n";
		cin>>sali;
		
	}while (sali=='S' || sali=='s');
    return 0;
}