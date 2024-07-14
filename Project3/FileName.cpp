#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Bank {
public:
	string loginacc;
	int moneyonthebank;
	string passwordacc;
	string seedphrase;
public:
	int transfer() {
		cout << "in order to make a transfer, you must write the recipients username" << endl;
		string recipent; cin >> recipent;
		if (recipent == loginacc) {
			cout << "You cant make a translation for yourself." << endl;
			return 0;
		}
		ifstream check;
		check.open(recipent + ".txt");
		if (check.is_open() == false) {
			cout << "there is no such user." << endl;
			return 0;
		}
		int moneyrec;
		string str;
		while (!check.eof()) {
			check >> str;
		}
		check.close();
		moneyrec = stoi(str);
		cout << "How much money do you want to send ?" << endl;
		int money; cin >> money;
		ifstream yep;
		yep.open(loginacc + ".txt");
		string mone;
		while (!yep.eof()) {
			yep >> mone;
		}
		yep.close();
		ofstream edit;
		ofstream editrec;
		edit.open(loginacc + ".txt", ofstream::app);
		editrec.open(recipent + ".txt", ofstream::app);
		edit << "\n" << stoi(mone) - money;
		editrec << "\n" << stoi(str) + money;
		edit.close();
		editrec.close();
		getmoney();
		
	}
	void plus_money() {
		cout << "How much money have you contributed?" << endl;
		int money; cin >> money;
		ifstream yep;
		yep.open(loginacc + ".txt");
		string mone;
		while (!yep.eof()) {
			yep >> mone;
		}
		yep.close();
		ofstream blya;
		blya.open(loginacc + ".txt", ofstream::app);
		int plus = money + stoi(mone);
		blya << "\n" << plus;
		blya.close();
		getmoney();

	}
	int minus_money() {
		g:
		cout << "How much money do you want to withdraw?" << endl;
		int money; cin >> money;
		ifstream yep;
		yep.open(loginacc + ".txt");
		string mone;
		while (!yep.eof()) {
			yep >> mone;
		}
		yep.close();
		if (money > stoi(mone)) {
			cout << "it isnt right number of money" << endl;
			cout << "Do you want to try again or quit ?" << endl;
			cout << "1 leave\n2 try again" << endl;
			int c; cin >> c;
			if (c == 1) {
				return 0;
			}
			else if (c == 2) {
				goto g;
			}
			else {
				cout << "ERROR!" << endl;
				return 0;
			}
		}
		ofstream qwe;
		qwe.open(loginacc + ".txt", ofstream::app);
		qwe << "\n" << stoi(mone) - money;
		qwe.close();
		getmoney();

	}


	string getpssword(){
		cout << "If you want to take password, you must to write your login and  seed phrase" << endl;
		string login; cin >> login;
		string seed;
		cin >> seed;
		ifstream yep;
		string seeda;
		string str; string password;

		yep.open(login+ ".txt");
		int g = 0;
		while (!yep.eof()) {
			g++;
			yep >> str;
			if (g == 1) {
				password = str;
			}
			if (g == 2) {
				seeda = str;
			}
		}
		yep.close();
		if (seed == seeda) {
			cout << "Your password is " << password << endl;
			return password;
		}
		else {
			cout << "seed is not right" << endl;
			return "Error";
		}

	}
	
	void getmoney() {
		ifstream yep;
		yep.open(loginacc + ".txt");
		int g = 0;
		string mone;
		int money;
		while (!yep.eof()) {
			yep >> mone;
		}
		money = stoi(mone);
		cout << "Now in your account    " << money << '$' << endl;
		yep.close();
		welcome();
	}
	void welcome() {
		cout << "If uou want to do a transfer,press1\nIf you want to withdraw money, press 2\nIf you want to deposit money, press 3\nIf you want to know your balance,press 4\nIf you want to leave, press 5\n";
		int doing; cin >> doing;
		if (doing == 1) {
			transfer();
		}
		if (doing == 2) {
			minus_money();
		}
		if (doing == 3) {
			plus_money();
		}if (doing == 4) {
			getmoney();
		}if (doing == 5) {
			exit(0);
		}



	}
};

bool join(Bank& people) {
dontsucces:
	cout << "write your username." << endl;
	string logina;
	cin >> logina;
	string login = logina + ".txt";
	ifstream check;
	check.open(login);
	if (check.is_open() == true) {
		cout << "write your password" << endl;
	}
	else {
		cout << "there is no account with this username!" << endl;
		cout << "Do you want to go out or try to come in again?" << endl;
		cout << "to leave you must to write 1                   to try it again you must to write 2" << endl;
		int exit; cin >> exit;
		if (exit == 1) {
			return 0;
		}
		else {
			goto dontsucces;
		}
	}
	string password; cin >> password;
	string passworda;
	getline(check, passworda);
	if (password == passworda) {
		cout << "you are logged into your account." << endl;
		check.close();
		people.passwordacc = password;
		people.loginacc = logina;
		return 1;
	}
	else {
		cout << "Your password isnt right" << endl;
		check.close();
		return 0;
	}
}
bool registr(Bank &people) {
fuck:
	cout << "come up with a username." << endl;
	string login; cin >> login;
	login += ".txt";
	ifstream check;
	check.open(login);
	if (check.is_open() == true) {
		cout << "this account already exists" << endl;
		check.close();
		cout << "to leave you must to write 1		to try it again you must to write 2" << endl;
		int a; cin >> a;
		if (a == 1) {
			return 0;
		}
		else {
			goto fuck;
		}
	}
	check.close();
	ofstream add;
	add.open(login);
	if (add.is_open() == false) {
		cout << "Something went wrong" << endl;
		return 0;
	}
	cout << "enter your password" << endl;
	string password;
	cin >> password;
	cout << "Come up with a phrase Sid" << endl;
	string seed; cin >> seed;
	add << password << "\n" << seed << "\n500";
	add.close();
	people.passwordacc = password;
	people.loginacc = login;
	people.moneyonthebank = 500;
	people.seedphrase = seed;
	cout << "Succes" << endl;
	return 1;
}
int main() {
	Bank people;
	cout << "Welcome to ExPat Bank!" << endl << "We give 500$ to new users of our bank." << endl;
	cout << "1 if you have account\t2 if you dont havea account\t " << "3 if you forgot your password\n ";

	int a;
	cin >> a;bool succes;
	d:
	if (a == 1) {
		succes = join(people);
		if (succes == 0) {
			return 0;
		}
	}
	else if(a ==2 ) {
		registr(people);
		cout << people.passwordacc << endl; 
		cout << "wanna you login in your account?" << endl << "1 if you want to login\t\t\t2 if you want to leave" << endl;
		int asdf;
		cin >> asdf;
		if (asdf == 1) {
			join(people);
		}
		else {
			return 0;
		}
	}
	else if (a == 3) {
		people.getpssword();
		cout << "Do you want to exit or login?\n 1 login\t2 exit" << endl;
		int c;
		cin >> c;
		if (c == 1) {
			a = 1;
			goto d;
		}
	}
	else {
		cout << "error!" << endl;
		return 0;
	}
	people.welcome();
	return 0;
}