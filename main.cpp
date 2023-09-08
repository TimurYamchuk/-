#include <iostream>
using namespace std;

class Student
{
    char* name;
    char* surname;
    double salary;
    char* number;

public:
    Student()
    {
        name = nullptr;
        surname = nullptr;
        number = nullptr;
        salary = 0;
        cout << "Constructor by default\n";
    }

    Student(const char* n, const char* s, double a, const char* u)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        surname = new char[strlen(s) + 1];
        strcpy(surname, s);
        salary = a;
        number = new char[strlen(u) + 1];
        strcpy(number, u);
        cout << "Constructor by params\n";
    }

    void Input()
    {
        char buff[40];
        cout << "Enter name -> ";
        cin >> buff;
        if (name != nullptr)
        {
            delete[] name;
            cout << "Deleted " << name << endl;
        }
        name = new char[strlen(buff) + 1];
        strcpy(name, buff);

        cout << "Enter salary -> ";
        cin >> salary;

        cout << "Enter surname -> ";
        cin >> buff;
        if (surname != nullptr)
        {
            delete[] surname;
            cout << "Deleted " << surname << endl;
        }
        surname = new char[strlen(buff) + 1];
        strcpy(surname, buff);

        cout << "Enter number -> ";
        cin >> buff;
        if (number != nullptr)
        {
            delete[] number;
            cout << "Deleted " << number << endl;
        }
        number = new char[strlen(buff) + 1];
        strcpy(number, buff);
    }

    void Delete()
    {
        // Mark the student as deleted (set name, surname, and number to nullptr)
        delete[] name;
        delete[] surname;
        delete[] number;
        name = nullptr;
        surname = nullptr;
        number = nullptr;
        cout << "Student deleted\n";
    }

    void Print()
    {
        if (IsDeleted()) {
            cout << "This student has been deleted." << endl;
            return;
        }
        cout << "Name: " << name << "\tSurname: " << surname << "\tSalary: " << salary << "\tNumber: " << number << endl;
    }

    bool IsDeleted() const
    {
        return (name == nullptr);
    }

    ~Student()
    {
        delete[] name;
        delete[] surname;
        delete[] number;
        cout << "Destructor\n";
    }
};

int main()
{
    const int maxStudents = 5;
    Student* students = new Student[maxStudents];

    students[0] = Student("Anna", "Smith", 25000, "123-456-789");
    students[1] = Student("David", "Johnson", 30000, "234-567-890");
    students[2] = Student("Emily", "Brown", 28000, "345-678-901");
    students[3] = Student("James", "Davis", 27000, "456-789-012");
    students[4] = Student("Olivia", "Jones", 26000, "567-890-123");

    for (int i = 0; i < maxStudents; i++) {
        cout << "Student " << i + 1 << ":\n";
        students[i].Print();
        cout << endl;
    }
    
    delete[] students;

    return 0;
}
