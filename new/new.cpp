#include <iostream>
#include <string>
//#define DEBUG
#define tab "\t"
using namespace std;

class Purse {
private:
	//field
	double money = 0.00;
	string valuta;
	string name;

public:
	Purse(string _valuta, string _name) {
		valuta = _valuta;
		name = _name;
	}
		//methods
	void topUp_balance() {
		float how_many;
		cout << "Ваш баланс = " << money << endl;
		cout << "На сколько хотите пополнить:  "; cin >> how_many;

		money = money + how_many;
		cout << "Теперь ваш баланс = " << money;

		}

		void topDown_balance() {
			double how_many;
			cout << "Сколько хотите потратить: "; cin >> how_many;
			if (how_many > money)
			{
				cout << "Недостаточно средств";
			}
			else
			{
				money = money - how_many;
				cout << "Теперь ваш баланс = " << money << endl;
			}
			
		}
		
		void info() {
			cout << "Баланс = " << money << " " << valuta << endl;
			cout << "Имя владельца: " << name << endl;
		}
};

int main()
{
	setlocale(LC_ALL, "ru");
	int switchh;
	int how_many;
	string password; string password_verify;
	string valuta; string name;
	cout << "Имя пользователя: " << endl; cin >> name;
	cout << "Пароль: " << endl; cin >> password;
	
	cout << "Проверка учетной записи" << endl
		<< "Введите пароль" << endl; cin >> password_verify;
	
	if (password != password_verify)
	{
		cout << "Неверный пароль" << endl;
	}

	else {
		L1:
		cout << "Тип валюты: " << endl; cin >> valuta;

		Purse purse(valuta, name);

		while (true) {
			cout << endl;
			cout << "Какое действие хотите выполнить?" << endl
				<< "1.Пополнить кошелёк " << endl
				<< "2.Потратить деньги" << endl
				<< "3.Информация о кошельке" << endl;
			cin >> switchh;

			switch (switchh)
			{
			case 1:
				purse.topUp_balance();
				cout << endl;
	
				break;

			case 2:
				purse.topDown_balance();
				cout << endl;
				break;
			case 3:
				purse.info();
				cout << endl;
				break;
			default:
				cout << "Действие не выбранно" << endl;
				cout << endl;
				break;
			}
		}
	}
	
	end:
	
	return 0;
}
