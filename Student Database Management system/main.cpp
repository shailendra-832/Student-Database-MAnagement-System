/*                              STUDENT MANAGEMENT SYSTEM
Sanket Annamwar: SYCOA103
Kunal Bhosikar: SYCOA112
Shreyas Bhosle: SYCOA113
Shailendra Chaudhary: SYCOA123*/
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
fstream file;

/*void display_file()
{
    fstream f;
    string data;
    f.open("Records.txt");

    if (f.is_open())
    {
        string line;
        while (getline(f, line))
        {
            cout << line << endl;
        }
        f.close();
    }
}
void display_file() 
{
  char s[1000];
  fstream f;
  f.open("Records.txt",ios :: in);
  f.read((char *)s , sizeof(s));
  cout<<"\n";
  cout<< s;
}*/

struct administrator
{
    char user_name[10];
    char password[10];
} admin;
void welcome();
void thanks();
int verify_password();
void assign_user();
class student // Base Class I
{
public: // public variables
    string name, date_of_birth;
    int roll_no;
    int clss;
    float physics;
    float chemistry;
    float maths;
    float total;
    long long int mobile;
    static int count;
    student() // Default Constructor
    {
        name = "";
        roll_no = 00;
        clss = 00;
        date_of_birth = "_";
        physics = 00;
        chemistry = 00;
        maths = 00;
        mobile = 00;
    }
    ~student() // Destructor
    {
    }
    friend void update_data(student *, int);
    void get_data()
    {
        file.open("Records.txt", ios::app);
        file << "\nStudent Profile data :\n";
        cout << "\nInput Student Profile data :\n";
        cout << "Enter name: ";
        cin >> name;
        file << "Name :" << name<<"\n";
        cout << "Enter Roll.No.: ";
        cin >> roll_no;
        file << "Roll No :" << roll_no << "\n";
        cout << "Enter Class: ";
        cin >> clss;
        file << "Class :" << clss << "\n";
        cout << "Enter date of birth: ";
        cin >> date_of_birth;
        file << "Date of Birth :" << date_of_birth << "\n";
        cout << "Enter mobile number: ";
        cin >> mobile;
        file << "Mobile Number :" << mobile << "\n";
        file.close();
    }
    void put_data()
    {
        cout << "-----------------------------------------------------------";
        cout << "\nName of the Student: "
             << "          " << name;
        cout << "\nRoll.No. of the Student: "
             << "      " << roll_no;
        cout << "\nClass of the Student: "
             << "         " << clss;
        cout << "\nDate of birth of the Student: "
             << " " << date_of_birth;
        cout << "\nMobile Number of the Student: "
             << " " << mobile << endl;
    }
    inline static int studcount()
    { // Static function
        count = count + 1;
        return count;
    }
    virtual void total_marks() = 0; //pure virtual function
};
int student ::count = 0;
class extra // Base class II
{
public: // public variables of Base class II
    int sport;
    int yoga;
    int music;
    int photo;
    int a;
    // friend void update_extra(extra *,int );
    void get_skills() // public functions
    {
        file.open("Records.txt", ios::app);
        file << "\nExtra-Skills Score" << endl;
        cout << "\nInput Extra-Skills Score" << endl;
        cout << "Enter sports score (out of 100) :";
        cin >> sport;
        file << "Sports score :" << sport << "\n";
        cout << "Enter yoga score (out of 100) :";
        cin >> yoga;
        file << "Yoga score :" << yoga << "\n";
        cout << "Enter music score (out of 100) :";
        cin >> music;
        file << "Music score :" << music << "\n";
        cout << "Enter photography score (out of 100) :";
        cin >> photo;
        file << "Photography score  :" << photo << "\n";
        file.close();
    }
    void put_skills()
    {
        cout << "------------------------------------------------------------";
        cout << "\nStudent's sport marks is(out of 100) : "
             << " " << sport << endl;
        cout << "Student's yoga marks is(out of 100) :  "
             << " " << yoga << endl;
        cout << "Student's music marks is(out of 100) : "
             << " " << music << endl;
        cout << "Student's photo marks is(out of 100) : "
             << " " << photo << endl;
    }
};
class score : public student, public extra // Child Class/Derived Class
{
public: // public functions of child class
        // friend void update_score(score *,int );
    void get()
    {
        student::get_data();
        extra::get_skills();
        file.open("Records.txt", ios ::app);
        file << "\nStudent subject score is :\n";
        cout << "\nEnter the score of student in subjects" << endl;
        cout << "Enter your physics marks (out of 100): ";
        cin >> physics;
        file << "Physics score :" << physics << "\n";
        cout << "Enter your maths marks(out of 100) : ";
        cin >> maths;
        file << "Maths score :" << maths << "\n";
        cout << "Enter your chemistry marks(out of 100) : ";
        cin >> chemistry;
        file << "Chemistry score :" << chemistry << "\n";
        file.close();
    }
    void display()
    {
        put_data();
        put_skills();
        cout << "------------------------------------------------------------";
        cout << "\nPhysics marks of the Student (out of 100) :   " << physics;
        cout << "\nChemistry marks of the Student (out of 100) : " << chemistry;
        cout << "\nMaths marks of the Student (out of 100) :     " << maths << endl;
        cout << "------------------------------------------------------------";
        cout << "\nTotal marks of the student in academics (out of 300):                   " << sum(physics, chemistry, maths);

        cout << "\nTotal marks of the student in extra curricular activities (out of 400): " << sum(sport, yoga, music, photo) << endl;
        cout<<"\n Total score obtained by student are :"<<(((sum(physics, chemistry, maths)/3)*0.7) +((sum(sport, yoga, music, photo)/4)*0.3))<<endl;
    }
    void total_marks()
    {
        cout << "\nTotal marks obtained by student are : " << physics + chemistry + maths << endl;
    }
    int sum(int num1, int num2, int num3) // Function overloading
    {
        return num1 + num2 + num3;
    }
    int sum(int num1, int num2, int num3, int num4) // Function overloading
    {
        return num1 + num2 + num3 + num4;
    }
};
void update_data(score a[], int n)
{
    int roll, ch, c;
    cout << "\nEnter the roll number of student :";
    cin >> roll;
    for (int i = 0; i < n; i++)
    {
        if (roll == a[i].roll_no)
        {
            while (c != 1)
            {
                cout << "\nSelect the category which you want to change" << endl
                     << "1) - change name" << endl
                     << "2) - Change DOB " << endl
                     << "3) - Change Mobile number" << endl
                     << "4) - Exit update" << endl;
                cin >> ch;
                switch (ch)
                {
                case 1:
                    cout << "Enter new name :";
                    cin >> a[i].name;
                    break;
                case 2:
                    cout << "Enter new DOB :";
                    cin >> a[i].date_of_birth;
                    break;
                case 3:
                    cout << "Enter new mobile number :";
                    cin >> a[i].mobile;
                    break;
                case 4:
                    c = 1;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    welcome();
    score s[100];
    student *ss[100];
    ss[100] = &s[100]; // upcasting
    int N, stu=0;
    string msg;

    while (1)
    {
        cout << "\nSelect from below :";
        cout << "\nEnter 1 to Insert Student Information";
        cout << "\nEnter 2 to Display  Students Information";
        cout << "\nEnter 3 to Find The Number of Students";
        cout << "\nEnter 4 to Update the Students data";
        cout << "\nEnter 5 to EXIT !!!!";
        cout << "\nSelect one option: ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int p;
            cout<<"\nLogin before Insertion"<<endl;
            cout<<"****LOGIN using USERNAME and ID****"<<endl;
            assign_user();
            p = verify_password();
            if (p == 0)
            {
            cout << "\nEnter Number Of Students You Have To Insert Details: ";
            cin >> N;
            try // Exception handling
            {
                if (N > (100-stu))
                    throw msg;
            }
            catch (string msg)
            {
                cout << "Class has capacity of 100 students only.\n Re-Enter the number of students." << endl;
            }
                for (int i = 0; i < N; i++)
                {
                    s[i].get();
                    stu = student ::studcount();
                }
            }
            else
            {
                cout << "\n\tU R Not a Valid User.";
            }
        }
        break;
        case 2:
        {
            for (int j = 0; j < N; j++)
            {
                s[j].display();
                // ss[j]->total_marks();
            }
        }
        break;
        case 3:
        {
            cout << "The number of students are: " << stu << endl
                 << endl;
        }
        break;
        case 4:
        {
            int p;
            cout<<"\nLogin before Updation"<<endl;
            cout<<"****LOGIN using USERNAME and ID****"<<endl;
            assign_user();
            p = verify_password();
            update_data(s, N);
            break;
        }
        case 5:
        {
            thanks();
            return 0;
        }
        break;
        }
    }
}
void assign_user()
{
    strcpy(admin.user_name, "pccoe");
    strcpy(admin.password, "pccoe");
}
int verify_password()
{
    char u_name[10];
    char u_pwd[10], temp[2];
    int x = 1;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
    cout << "\n       Enter user name : ";
    cin >> u_name;
    cout << "\n       Enter Password : ";
    cin >> u_pwd;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
    x = strcmp(admin.user_name, u_name);
    if (x == 0)
    {
        x = strcmp(admin.password, u_pwd);
    }
    cin.getline(temp, 2);
    return (x);
}
void welcome()
{
    // clrscr();
    cout << "\t%%      %%      ";
    cout << "\n\t%%      %%  %%%%%%%  %%       %%%%%%   %%%%%%  %%%%  %%%%  %%%%%%%";
    cout << "\n\t%%      %%  %%       %%       %%       %%  %%  %%  %%% %%  %%       ";
    cout << "\n\t%%  %%  %%  %%%%%    %%       %%       %%  %%  %%  %%% %%  %%%%%      ";
    cout << "\n\t%%  %%  %%  %%       %%       %%       %%  %%  %%      %%  %%           ";
    cout << "\n\t%%%%%%%%%%  %%%%%%%  %%%%%%%  %%%%%%%  %%%%%%  %%      %%  %%%%%%%     ";
    cout << "\n\n\t\t\t        $$$$$$$$  $$$$$        ";
    cout << "\n\t\t\t           $$     $   $      ";
    cout << "\n\t\t\t           $$     $$$$$    ";

    cout << "\n\n\n\tPROJECT BASED LEARNING ON CLASS MANAGEMENT SYSTEM\n";
}
void thanks()
{
    // clrscr();
    cout << "\n\n\n\n\n\n\n\t**   T H A N K   Y O U   F O R   W O R K I N G   *"<<endl;
}