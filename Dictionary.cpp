#include <iostream>
#include<stdlib.h>
#include <string>
#include<fstream>

using namespace std;


class Dictionary
{

public:


	Dictionary();
	void input();
	void add_word();
	void delete_word();
	void search_word();
	void read_word();
	~Dictionary();
};

///////////////////////////////////////


int main(int argc, char** argv)
{
	Dictionary d;
    cout<<"\t\t\t\tSimple Dictionary"<<endl;

	while(true)
	{

		cout << "Select choice ! " << endl << endl
			 << " 1 - Search Word "
			 << "\n 2 - Add Word " << endl
			 << " 3 - Delete Word " << endl
			 << " 4 - Display Words " << endl
			 << " 5 - Exit " << endl << endl;

		int choice;
		cin >> choice;
		switch (choice)
		{

		case 1:
			d.search_word();
			break;

		case 2:
			d.add_word();
			break;

		case 3:
			d.delete_word();
			break;
		case 4:
			d.read_word();
			break;

		case 5:
			exit(0);
			break;

		default:
			cout << "Wrong Choice !" << endl;
		}

	}

	system("pause");
	return 0;
}


//////////////////////////////////////////////////


Dictionary ::Dictionary()// constructor of d
{

	/**
	 * Checking if file exist.
	 */
	fstream file("file.txt");

	if (!file)
	{

		cout << "File Not Found." << endl;
		cout << "Please Wait..." << endl;
		/**
		 * Creating new file.
		 */
		system("type nul >file.txt");
		cout << "New File Created." << endl;

	}


}


//////////////////////////////////////////////////



void Dictionary ::add_word()
{

	fstream file;
	string word;
	string meaning;


	try
	{
file.open("file.txt", ios::in | ios::app);

		if (file.is_open())
		{

			cout << "Enter World : ";
			cin.ignore(10, '\n');
			getline(cin, word);

			cout << "Enter Meaning : ";
			getline(cin, meaning);

            system("cls");
			file << word << "\t" << meaning << endl;
			cout << "Successfully Added." << endl;
			file.close();
		}
		else
		{
			cerr << "Error During Opening File" << endl;
		}

	}
	catch(exception& e)
	{

		cout << "Standard exception: " << e.what() << endl;
	}

}

//////////////////////////////////////


void Dictionary ::search_word()
{

	fstream file;
	string tmp;
	string line;
	size_t pos;
	char ch;
	int count = 0;



	try
	{

		file.open("file.txt");
		if (file.is_open())
		{
			cout << "Enter World for Search : ";
			cin.ignore(10, '\n');
			getline(cin, tmp);

			while (!file.eof())
			{

				getline(file, line);
				pos = line.find(tmp);

				if (pos != string::npos)
				{

                    system("cls");
					cout << "Word Found : " << line << endl;
					count++;
				}

			}


			file.close();

			if (count != 0)
			{

				cout << "Total Words Found : " << count << endl;
			}

			else
			{

				cout << "Word Not Found: " << endl;
				cout << "Do You Want To Add This World?(y/n) ";

				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{

					system("cls");

					add_word();

				}

			}

		}
		else
		{
			cerr << "Error During Opening File" << endl;

		}

	}
	catch(exception& e)
	{

		cout << "Standard exception: " << e.what() << endl;
	}
}

//////////////////////////////////////



void Dictionary ::read_word()
{
	fstream file;
	string line;


	try
	{

		file.open("file.txt");
		if (file.is_open())
		{

            system("cls");
			cout << "\t\t*********************************************" << endl;
			cout << "\t\t\t\tWord : Meaning " << endl;
			cout << "\t\t*********************************************" << endl;

			while (!file.eof())
			{

				getline(file, line);
				cout << "\t\t\t\t " << line << endl;

			}
		}
		else
		{
			cerr << "Error During Opening File" << endl;
		}

	}
	catch(exception& e)
	{

		cout << "Standard exception: " << e.what() << endl;
	}
}


///////////////////////////////////////////////////


void Dictionary ::delete_word()
{
	fstream file;
	fstream tmp;
	size_t pos;
	string line;
	string word;


	try
	{


		file.open("file.txt");
		tmp.open("tmp.txt", ios::app);

		cout << "Enter Word for Edit" << endl;
		cin >> word;

		if (file.is_open())
		{

			while (!file.eof())
			{

				getline(file, line);
				pos = line.find(word);
				if (pos != string::npos)
				{
                    system("cls");
					cout << "Found: " << line << endl;
					cout << "Word Delete" << endl;
					cout << "Dictionary Updated" << endl;

				}
				else
				{
					tmp << line << endl;
				}

			}
		}
		else
		{
			cout << "Error During Opening File" << endl;
		}

		file.close();
		tmp.close();

		remove("file.txt");
		rename("tmp.txt", "file.txt");
	}
	catch(exception& e)
	{

		cout << "Standard exception: " << e.what() << endl;
	}

}
/////////////////////////////////////////////////////////

Dictionary ::~Dictionary()
{

	cout << "Have a nice day " << endl;
}
