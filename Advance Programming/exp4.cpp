#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin;
    fstream f;
    ofstream fout;
    int input;
    do
    {
        fin.open("Employee.txt");
        fout.open("Employee.txt", ios::app);
        cout << "\n\n***************************************************************************************\n\n";
        cout << "What actions do you wanna perform on employee system : " << endl;
        cout << "1 : Insert into table" << endl;
        cout << "2 : Print data" << endl;
        cout << "3 : Search in data" << endl;
        cout << "4 : Delete data" << endl;
        cout << "5 : Exit from System " << endl;
        cout << "\nEnter input : ";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            string id, age, name, salary;
            cout << "Enter name of Employee : ";
            cin >> name;
            cout << "Enter id of employee : ";
            cin >> id;
            cout << "Enter age of employee : ";
            cin >> age;
            cout << "Enter salary of employee : ";
            cin >> salary;
            if (fin.is_open())
            {
                fout << id << "\t" << name << "\t" << age << "\t" << salary << "\n";
            }
            break;
        }
        case 2:
        {
            cout << "The employee data present in file are as follows :" << endl;
            string str;
            cout << "\nID\tName\tAge\tsalary\n"
                 << endl;
            while (fin)
            {
                getline(fin, str);
                cout << str << endl;
            }
            break;
        }
        case 3:
        {
            int counter = 0;
            string check;
            cout << "Enter the Id/NAME data you wanna check : " << endl;
            cin >> check;
            string str;
            cout << "\nID\tName\tAge\tsalary\n"
                 << endl;
            while (!fin.eof())
            {
                getline(fin, str);
                string a = str;
                istringstream ss(a);
                string word;
                while (ss >> word)
                {
                    if (word.compare(check) == 0)
                    {
                        cout << " " << endl;
                        cout << str << endl;
                        cout << " " << endl;
                        counter++;
                    }
                }
            }
            if (counter == 0)
            {
                cout << "Inserted ID/Name is not present in out System !" << endl;
            }
            break;
        }
        case 4:
        {
            int number;
            cout << "Enter the line number you want to delete" << endl;
            cin >> number;
            f.open("Employee.txt");
            if (f.fail())
            {
                cout << "Error opening file" << endl;
                return 1;
            }
            vector<string> lines;
            string line;
            while (getline(f, line))
            {
                lines.push_back(line);
            }
            f.close();
            if (number > lines.size())
            {
                cout << "line " << number << " not in the file" << endl;
                continue;
            }
            number--;
            ofstream fout1;
            fout1.open("Employee.txt");
            for (int i = 0; i < lines.size(); i++)
            {
                if (i != number)
                {
                    fout1 << lines[i] << endl;
                }
            }
            fout1.close();
            cout << "Line deleted" << endl;
            break;
        }
        case 5:
        {
            cout << "Thanks for using our system ! " << endl;
            break;
        }
        default:
        {
            cout << "Select the right option" << endl;
            break;
        }
        }
        fin.close();
        fout.close();
    } while (input != 5);
    return 0;
}
