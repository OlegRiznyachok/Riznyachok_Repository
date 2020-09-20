#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	
	setlocale(LC_ALL,"Russian");
	string start_line, final_line,command;
	char symbol;
	int offset;
	cout << "Введите велечину сдвига(допускается отрицательное значение): ";
	cin >> offset;
	do{
		cout << "Введите encode для кодирования или decode для расшифровки: ";
		cin >> command;
		if (command == "decode")offset *= -1;
			
	} while ((command!="encode")and( command!="decode"));
	cout << "Введите предложение(не использовать кириллические символы): ";
	cin >> start_line;
	final_line.resize(start_line.length());
	for(int i=0;i<start_line.length();i++){
		if((start_line[i]>96)and(start_line[i]<123)){
			symbol = start_line[i] += offset;
			symbol= char(97+(26*(1-(symbol/97)))+((symbol-97)%26));
			final_line[i] = symbol;
		}
		else if ((start_line[i] > 64) and (start_line[i] < 91)) {
			symbol = start_line[i] += offset;
			symbol = char(64 + (26 * (1 - (symbol / 64))) + ((symbol - 64) % 26));
			final_line[i] = symbol;
		}
		
		else {
			final_line[i] = start_line[i];
		}
	}
	cout <<"Результат: "<< final_line;
	
}