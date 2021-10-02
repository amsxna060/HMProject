#include "mylibrary.h"

void drawframe(string path)
{
    char* page = &path[0];
    char ch;
    ifstream fin;
    fin.open(page, ios::binary);
    while (!fin.eof())
    {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
}

void log_out_animation()
{
    Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
    Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
    Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
    Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
}

void about_animation() {
    cout << "                                                               ";
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "T"; Sleep(200); cout << "H"; Sleep(200); cout << "A"; Sleep(200); cout << "N"; Sleep(200); cout << "K"; Sleep(200); cout << " "; Sleep(200);
    cout << "Y"; Sleep(200); cout << "O"; Sleep(200); cout << "U"; Sleep(200); cout << " "; Sleep(200); cout << "F"; Sleep(200); cout << "O"; Sleep(200);
    cout << "R"; Sleep(200); cout << " "; Sleep(200); cout << "V"; Sleep(200); cout << "I"; Sleep(200); cout << "S"; Sleep(200); cout << "I"; Sleep(200);
    cout << "T"; Sleep(200); cout << "I"; Sleep(200); cout << "N"; Sleep(200); cout << "G"; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200);
    cout << "\n\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void logo()
{
    DATE_TIME T;
    exit();
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t  ";
    cout << "Date :";
    T.show_date();
    cout << "\t\t\t\t\t\t\t\t\t\t";
    cout << "Time :";
    T.show_time();
    cout << "\n\n";
    cout << "\t\t\t\t\t\t  *******************************************************************************\n";
    cout << "\t\t\t\t\t\t\t\t  DIGITAL WELL BEING HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t\t\t  *******************************************************************************\n";
    cout << "\n\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void lastline_firstline()
{
    cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int password(string mail, string pass)
{
    static int countp = 0;
    string passw = "";
    cout << "\t\t\t\t\t\t\t\t\t\t Password: ";
    char ch;
    ch = _getch();
    while (ch != 13)
    {
        passw.push_back(ch);
        cout << "*";
        ch = _getch();
        if (passw.size() > 11)
            break;
    }
    if (checkpassword(passw, pass))
    {
        cout << "\ngranted!!\n";
        return 1;
    }
    else
        if (countp < 1)
        {
            countp++;
            cout << " \n wrong password \n";
            system("pause");
            system("cls");
            Sign_in(mail, pass);
            password(mail, pass);
        }
        else
        {
            cout << "\n\nYOU HAVE CROSSED THE LIMIT TO ENTER WRONG PASSWORD!!!!!!\n\n\n\n";
            exit(0);
        }
}
/**********************************************************************************************************/
/**********************************************************************************************************************************/
bool checkemail(string email, string file)
{
    vector<string> str;
    char* page = &file[0];
    ifstream fin;
    fin.open(page);
    while (!fin.eof()) {
        string s = "";
        getline(fin, s);
        str.push_back(s);

    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == email)
            return true;
    }
    return false;
    fin.close();
}
/**********************************************************************************************************************************/
bool checkpassword(string pass, string file)
{
    vector<string> str;
    char* page = &file[0]; 
    ifstream fin;
    fin.open(page);
    while (!fin.eof()) {
        string s = "";
        getline(fin, s);
        str.push_back(s);

    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == pass)
            return true;
    }
    return false;
    fin.close();
}
/********************************************************************************************************************************/
void show_patient()
{
    ifstream fin;
    vector <string> str;
    string file;
reenterfile:
    logo();
    cin.ignore(1, '\n');
    cout << "Enter the patient name you want to open :";
    getline(cin, file);
    file = "patient/" + file + ".txt";
    char* filename = &file[0]; 
    fin.open(filename);

    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        system("cls");
        goto reenterfile;
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Patient First Name :" << str[0] << endl;
        cout << "2. Patient Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Previous Disease :" << str[8] << endl;
        cout << "10. Current Symtomp :" << str[9] << endl;
        cout << "11. Weight :" << str[10] << " KG" << endl;
        cout << "12. Description of last few days :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Patient::input_patient()
{
    int n;
    ofstream fout, fpall;
    fstream fserial;
    string dummy;
    logo();
    fpall.open("mainfile/patientall.txt", ios::app);
    fpall << endl;
    fserial.open("mainfile/pserialno.txt", ios::in);
    fserial >> n;
    n++;
    fpall << setw(34) << n << ".";
    fserial.close();
    fserial.open("mainfile/pserialno.txt", ios::out);
    fserial << n;
    fserial.close();
    cin.ignore(100, '\n');
    cout << "Patient First Name :";
    getline(cin, pfname); fpall << setw(18) << pfname << " ";
    cout << "Patient Last Name :";
    getline(cin, plname); fpall << plname;
    dummy = "patient/" + pfname + " " + plname + ".txt";
    char* filename = &dummy[0];
    fout.open(filename, ios::binary);
    fout << pfname << endl;
    fout << plname << endl;
birth:
    cout << "Date of Birth :";
    getline(cin, pDOB);
    if (pDOB.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT (DD/MM/YYYY) \n";
        goto birth;
    }
    fpall << setw(17) << pDOB;
    fout << pDOB << endl;
    cout << "Age :";
    {
        string sb = pDOB.substr(6, 9);
        int year = stoi(sb);
        sb = pDOB.substr(3, 2);
        int month = stoi(sb);
        sb = pDOB.substr(0, 2);
        int date = stoi(sb);
        int autoage = auto_age(date, month, year);
        page = to_string(autoage);
        cout << page << endl;
    }
    fpall << setw(12) << page;
    fout << page << endl;
s:
    cout << "Sex :";
    getline(cin, psex);
    if (psex != "female" && psex != "Female" && psex != "F" && psex != "FEMALE" && psex != "MALE" && psex != "Male" && psex != "M" && psex != "male")
    {
        cout << "WRONG ENTRY!!!PLEASE CHOOSE Right Gender \n";
        goto s;
    }
    fout << psex << endl;
    cout << "Address :";
    getline(cin, paddress);
    fout << paddress << endl;
    fpall << setw(15) << paddress;
    cout << "City :";
    getline(cin, pcity); fpall << " " << pcity;
    fout << pcity << endl;
pin:
    cout << "Pin code :";
    getline(cin, ppin);
    if (ppin.size() != 6)
    {
        cout << "WRONG PINCODE!!!  \n";
        goto pin;
    }
    fout << ppin << endl;
    cout << "Previous Disease :";
    getline(cin, pre_dis);
    fout << pre_dis << endl;
    cout << "Current Symtomp :";
    getline(cin, cur_sym);
    fout << cur_sym << endl;
    fpall << setw(18) << cur_sym;
w:
    cout << "Weight :";
    getline(cin, weight);
    if (weight.size() > 3)
    {
        cout << "WRONG WEIGHT !!!\n";
        goto w;
    }
    fpall << setw(12) << weight;
    fout << weight << endl;
    cout << "Description of last few days :";
    getline(cin, discreption);
    fout << discreption << endl;
cn:
    cout << "Contact number :";
    getline(cin, contact_no);
    if (contact_no.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT 72XXXX3060 \n";
        goto cn;
    }
    fpall << setw(16) << contact_no;
    fout << contact_no << endl;
checkm:
    cout << "Email :";
    getline(cin, mail);
    {
        if (checkemail(mail, "mainfile/patientemail.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME EMAIL IN OUR DATEBASE!!..PLEASE TRY DIFFRENT EMAIL\n";
            goto checkm;
        }

    }
    fout << mail << endl;
    fpall << setw(26) << mail << endl;
passcheck:
newpasscheck: cout << "New password :";
    getline(cin, newpass);
    {
        if (checkpassword(newpass, "mainfile/patientpass.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME Password IN OUR DATEBASE!!..PLEASE TRY DIFFRENT password\n";
            goto newpasscheck;
        }
    }
    cout << "Confirm password :";
    getline(cin, conpass);
    if (conpass != newpass || newpass.size() >= 10)
    {
        cout << "Password does not match!!!!!!!\n";
        cout << "OR your password is more than 10 words!!!!!\n";
        goto passcheck;
    }
    ofstream femail, fpass;
    femail.open("mainfile/patientemail.txt", ios::app);
    femail << mail << endl;
    femail.close();
    fpass.open("mainfile/patientpass.txt", ios::app);
    fpass << newpass << endl;
    fpass.close();
check:
    string checkok;
    cout << "Type OK to confirm!!!!\n";
    cin >> checkok;
    if (checkok != "OK")
    {
        cout << "Please Type OK correctly!!!";
        goto check;
    }
    string tmail = "patient/" + mail + ".txt";
    copyfile(dummy, tmail);
    fpall.close();
    fout.close();
}
/*************************************************************************************************************************/
void Add_Patient()
{
    Patient p;
    p.input_patient();
}
/*******************************************************************************************************************************/
void Signup_as_a_patient()
{
    Add_Patient();
    cout << "You Have Sign Up As a Patient Sucessfully...!!!\n\n";
}
/////////////////////////////////////////////////////////////////////////////////////////
void Add_Doctor()
{
    Doctor D;
    D.input_doctor();

}
///////////////////////////////////////////////////////////////////////////////////////////
void Signup_as_a_doctor()
{
    Add_Doctor();
    cout << "You Have Sign Up As a Doctor Successfully...!!!\n\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void remove_doctor()
{
    string delfile;
    logo();
    cin.ignore(1, '\n');
    cout << "ENTER THE DOCTOR NAME YOU WANT TO FIRED : ";
    getline(cin, delfile);
    delfile = "doctor/" + delfile + ".txt";
    char* filedel = &delfile[0];
    vector<string> s;
    ifstream fin;
    fin.open(filedel);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    vector<string> ss;
    fin.open("mainfile/doctoremail.txt");
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        ss.push_back(temp);
    }
    fin.close();
    string temp = s[13];
    ofstream fout;
    fout.open("mainfile/doctoremail.txt", ios::binary);

    temp = "doctor/" + temp + ".txt";
    char* maildel = &temp[0];

    const int result1 = remove(filedel);
    const int result2 = remove(maildel);

    if (result1 == 0 && result2 == 0) {
        printf("\n\n\nYOUR DOCTOR IS FIRED!!!!!!\n\n\n");
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == s[13])
            {
                fout << '\0';
            }
            else
                fout << ss[i] << endl;
        }
    }
    else {
        printf("\n\nFILE NOT FOUND!!!!ERRORRR...!!!\n\n\n");
        system("cls");
        remove_doctor();
    }
    fout.close();
}

//////////////////////////////////////////////////////////////////////////////////////////
void discharge_patient() {
    string delfile;
    logo();
    cin.ignore(1, '\n');
    cout << "ENTER THE PATIENT NAME YOU WANT TO DISCHARGED : ";
    getline(cin, delfile);
    delfile = "patient/" + delfile + ".txt";
    char* filedel = &delfile[0];
    vector<string> s;
    ifstream fin;
    fin.open(filedel);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    vector<string> ss;
    fin.open("mainfile/patientemail.txt");
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        ss.push_back(temp);
    }
    fin.close();
    string temp = s[13];
    ofstream fout;
    fout.open("mainfile/patientemail.txt", ios::binary);

    temp = "patient/" + temp + ".txt";
    char* maildel = &temp[0];

    const int result1 = remove(filedel);
    const int result2 = remove(maildel);

    if (result1 == 0 && result2 == 0) {
        printf("\n\n\nYOUR PATIENT IS DISCHARGED!!!!!!\n\n\n");
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == s[13])
            {
                fout << '\0';
            }
            else
                fout << ss[i] << endl;
        }
    }
    else {
        printf("\n\nFILE NOT FOUND!!!!ERRORRR...!!!\n\n\n");
        system("cls");
        discharge_patient();
    }
    fout.close();

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////void show_all_Patient()
void show_all_Patient()
{
    char ch;
    ifstream fin;
    fin.open("mainfile/patientall.txt", ios::binary);
    while (!fin.eof())
    {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
}
//////////////////////////////////////////////////////////////////////////////////
void show_all_doctor()
{
    char ch;
    ifstream fin;
    fin.open("mainfile/doctorall.txt", ios::binary);
    while (!fin.eof())
    {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void exit()
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   Press (Ctrl+C) to close(^_^)";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Doctor::input_doctor()
{
    int n;
    ofstream fout, fpall;
    fstream fserial;
    string dummy;
    logo();
    fpall.open("mainfile/doctorall.txt", ios::app);
    fpall << endl;
    fserial.open("mainfile/dserialno.txt", ios::in);
    fserial >> n;
    n++;
    fpall << setw(34) << n << ".";
    fserial.close();
    fserial.open("mainfile/dserialno.txt", ios::out);
    fserial << n;
    fserial.close();
    cin.ignore(100, '\n');
    cout << "Doctor First Name :";
    getline(cin, fname); fpall << setw(18) << fname << " ";
    cout << "Doctor Last Name :";
    getline(cin, lname); fpall << lname;
    dummy = "doctor/" + fname + " " + lname + ".txt";
    char* filename = &dummy[0];
    fout.open(filename, ios::binary);
    fout << fname << endl;
    fout << lname << endl;
birth:
    cout << "Date of Birth :";
    getline(cin, DOB);
    if (DOB.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT (DD/MM/YYYY) \n";
        goto birth;
    }
    fpall << setw(17) << DOB;
    fout << DOB << endl;
    cout << "Age :";
    {
        string sb = DOB.substr(6, 9);
        int year = stoi(sb);
        sb = DOB.substr(3, 2);
        int month = stoi(sb);
        sb = DOB.substr(0, 2);
        int date = stoi(sb);
        int autoage = auto_age(date, month, year);
        age = to_string(autoage);
        cout << age << endl;
    }
    fpall << setw(12) << age;
    fout << age << endl;
s:
    cout << "Sex :";
    getline(cin, sex);
    if (sex != "female" && sex != "Female" && sex != "F" && sex != "FEMALE" && sex != "MALE" && sex != "Male" && sex != "M" && sex != "male")
    {
        cout << "WRONG ENTRY!!!PLEASE CHOOSE Right Gender \n";
        goto s;
    }
    fout << sex << endl;
    cout << "Address :";
    getline(cin, address);
    fout << address << endl;
    fpall << setw(15) << address;
    cout << "City :";
    getline(cin, city); fpall << " " << city;
    fout << city << endl;
pin:
    cout << "Pin code :";
    getline(cin, ppin);
    if (ppin.size() != 6)
    {
        cout << "WRONG PINCODE!!!  \n";
        goto pin;
    }
    fout << ppin << endl;
    cout << "High Degree :";
    getline(cin, higdeg);
    fout << higdeg << endl;
    fpall << setw(12) << higdeg;
    cout << "Special Degree :";
    getline(cin, spedeg);
    fout << spedeg << endl;
    fpall << setw(14) << spedeg;
w:
    cout << "Years of experience :";
    getline(cin, yearexp);
    if (!checkstrsize(yearexp, 2))
        goto w;
    fout << yearexp << endl;
    cout << "Specialty about you :";
    getline(cin, spec_ab_u);
    fout << spec_ab_u << endl;
cn:
    cout << "Contact number :";
    getline(cin, contact_no);
    if (contact_no.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT 72XXXX3060 \n";
        goto cn;
    }
    fpall << setw(18) << contact_no;
    fout << contact_no << endl;
checkm:
    cout << "Email :";
    getline(cin, mail);
    {
        if (checkemail(mail, "mainfile/doctoremail.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME EMAIL IN OUR DATEBASE!!..PLEASE TRY DIFFRENT EMAIL\n";
            goto checkm;
        }

    }
    fout << mail << endl;
    fpall << setw(26) << mail << endl;
passcheck:
newpasscheck: cout << "New password :";
    getline(cin, newpass);
    {
        if (checkpassword(newpass, "mainfile/doctorpass.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME PASSWORD IN OUR DATEBASE!!..PLEASE TRY DIFFRENT PASSWORD\n";
            goto newpasscheck;
        }
    }
    cout << "Confirm password :";
    getline(cin, conpass);
    if (conpass != newpass || newpass.size() >= 10)
    {
        cout << "Password does not match!!!!!!!\n";
        cout << "OR your password is more than 10 words!!!!!\n";
        goto passcheck;
    }
    ofstream femail, fpass;
    femail.open("mainfile/doctoremail.txt", ios::app);
    femail << mail << endl;
    femail.close();
    fpass.open("mainfile/doctorpass.txt", ios::app);
    fpass << newpass << endl;
    fpass.close();
check:
    string checkok;
    cout << "Type OK to confirm!!!!\n";
    cin >> checkok;
    if (checkok != "OK")
    {
        cout << "Please Type OK correctly!!!";
        goto check;
    }
    string tmail = "doctor/" + mail + ".txt";
    copyfile(dummy, tmail);
    fpall.close();
    fout.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copyfile(string source, string destination)
{
    char* src = &source[0]; 
    char* dest = &destination[0]; 

    ifstream fin;
    ofstream fout;
    fin.open(src, ios::binary);
    fout.open(dest, ios::binary);
    while (!fin.eof())
    {
        string temp;
        getline(fin, temp);
        fout << temp << endl;
    }
    fout.close();
    fin.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool checkstrsize(string s, int n)
{
    if (s.size() <= n)
        return true;
    else
    {
        cout << "\nWRONG!!!!" << " please be in range 1 to " << n << endl;
        return false;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int auto_age(int d, int m, int y)
{
    DATE_TIME T;
    if (y < T.get_year())
    {
        if (m < T.get_month())
        {
            int sage = T.get_year() - y;
            return sage;
        }
        else
            if (m > T.get_month())
            {
                int sage = T.get_year() - y;
                return sage - 1;
            }
            else
                if (m == T.get_month())
                {
                    if (d < T.get_date())
                    {
                        int sage = T.get_year() - y;
                        return sage;
                    }
                    else
                        if (d > T.get_date())
                        {
                            int sage = T.get_year() - y;
                            return (sage - 1);
                        }
                        else
                            if (d == T.get_date())
                            {
                                cout << "!!!!HAPPY BIRTHDAY!!!!";
                                int sage = T.get_year() - y;
                                return sage;
                            }
                }
    }
    else
        if (y == T.get_year())
        {
            cout << "(less than one year)";
            return 0;
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void show_patient_dir(string file)
{
    file = "patient/" + file + ".txt";

    ifstream fin;
    vector <string> str;
    char* filename = &file[0];
    logo();
    fin.open(filename);
    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        exit(0);
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Patient First Name :" << str[0] << endl;
        cout << "2. Patient Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Previous Disease :" << str[8] << endl;
        cout << "10. Current Symtomp :" << str[9] << endl;
        cout << "11. Weight :" << str[10] << " KG" << endl;
        cout << "12. Description of last few days :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Edit_patient(string file)
{
    show_patient_dir(file);
    file = "patient/" + file + ".txt";
    char* filename = &file[0];
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    ofstream out;
    out.open(filename, ios::binary);
A:
    cout << "\nEnter choice you want to edit : ";
    int n;
    string ss;
    cin >> n;
    cin.ignore(1, '\n');
    system("cls");
    logo();
    lastline_firstline();
    cout << "\n\n\n";


    if (n == 1)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i == n - 1) {
                cout << "1. Patient First Name :";
                getline(cin, ss);
                out << ss << endl;
            }
            else
                out << s[i] << endl;
        }
    }
    else
        if (n == 2)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i == n - 1) {
                    cout << "2. Patient Last Name :";
                    getline(cin, ss);
                    out << ss << endl;
                }
                else
                    out << s[i] << endl;
            }
        }
        else
            if (n == 3)
                for (int i = 0; i < s.size(); i++)
                {
                    if (i == n - 1) {
                        cout << "3. Date of Birth :";
                        getline(cin, ss);
                        out << ss << endl;
                    }
                    else
                        out << s[i] << endl;
                }
            else
                if (n == 4)
                    for (int i = 0; i < s.size(); i++)
                    {
                        if (i == n - 1) {
                            cout << "4. Age :";
                            getline(cin, ss);
                            out << ss << endl;
                        }
                        else
                            out << s[i] << endl;
                    }
                else
                    if (n == 5)
                        for (int i = 0; i < s.size(); i++)
                        {
                            if (i == n - 1) {
                                cout << "5. Sex :";
                                getline(cin, ss);
                                out << ss << endl;
                            }
                            else
                                out << s[i] << endl;
                        }
                    else
                        if (n == 6)
                            for (int i = 0; i < s.size(); i++)
                            {
                                if (i == n - 1) {
                                    cout << "6. Address :";
                                    getline(cin, ss);
                                    out << ss << endl;
                                }
                                else
                                    out << s[i] << endl;
                            }
                        else
                            if (n == 7)
                                for (int i = 0; i < s.size(); i++)
                                {
                                    if (i == n - 1) {
                                        cout << "7. City :";
                                        getline(cin, ss);
                                        out << ss << endl;
                                    }
                                    else
                                        out << s[i] << endl;
                                }
                            else
                                if (n == 8)
                                    for (int i = 0; i < s.size(); i++)
                                    {
                                        if (i == n - 1) {
                                            cout << "8. Pin code :";
                                            getline(cin, ss);
                                            out << ss << endl;
                                        }
                                        else
                                            out << s[i] << endl;
                                    }
                                else
                                    if (n == 9)
                                        for (int i = 0; i < s.size(); i++)
                                        {
                                            if (i == n - 1) {
                                                cout << "9. Previous Disease :";
                                                getline(cin, ss);
                                                out << ss << endl;
                                            }
                                            else
                                                out << s[i] << endl;
                                        }
                                    else
                                        if (n == 10)
                                            for (int i = 0; i < s.size(); i++)
                                            {
                                                if (i == n - 1) {
                                                    cout << "10. Current Symtomp :";
                                                    getline(cin, ss);
                                                    out << ss << endl;
                                                }
                                                else
                                                    out << s[i] << endl;
                                            }
                                        else
                                            if (n == 11)
                                                for (int i = 0; i < s.size(); i++)
                                                {
                                                    if (i == n - 1) {
                                                        cout << "11. Weight :";
                                                        getline(cin, ss);
                                                        out << ss << endl;
                                                    }
                                                    else
                                                        out << s[i] << endl;
                                                }
                                            else
                                                if (n == 12)
                                                    for (int i = 0; i < s.size(); i++)
                                                    {
                                                        if (i == n - 1) {
                                                            cout << "12. Description of last few days :";
                                                            getline(cin, ss);
                                                            out << ss << endl;
                                                        }
                                                        else
                                                            out << s[i] << endl;
                                                    }
                                                else
                                                    if (n == 13)
                                                        for (int i = 0; i < s.size(); i++)
                                                        {
                                                            if (i == n - 1) {
                                                                cout << "13. Contact number :";
                                                                getline(cin, ss);
                                                                out << ss << endl;
                                                            }
                                                            else
                                                                out << s[i] << endl;
                                                        }
                                                    else
                                                        if (n == 14)
                                                            for (int i = 0; i < s.size(); i++)
                                                            {
                                                                if (i == n - 1) {
                                                                    cout << "14. Email :";
                                                                    getline(cin, ss);
                                                                    out << ss << endl;
                                                                }
                                                                else
                                                                    out << s[i] << endl;
                                                            }
                                                        else
                                                        {
                                                            cout << "INVALID CHOICE!!!!!!";
                                                            system("cls");
                                                            goto A;
                                                        }
    out.close();
    string tem = "patient/" + s[0] + " " + s[1] + ".txt";
    copyfile(filename, tem);
    cout << "\nyou have change information successfully\n\n\n\n";
    lastline_firstline();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void show_doctor()
{
    ifstream fin;
    vector <string> str;
    string file;
reenterfile:
    logo();
    cin.ignore(1, '\n');
    cout << "Enter the Doctor name you want to open :";
    getline(cin, file);
    file = "doctor/" + file + ".txt";
    char* filename = &file[0]; 
    fin.open(filename);

    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        system("cls");
        goto reenterfile;
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t Dr. " << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Doctor First Name :" << str[0] << endl;
        cout << "2. Doctor Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Highest Degree :" << str[8] << endl;
        cout << "10. Special Degree :" << str[9] << endl;
        cout << "11. Years of Experience :" << str[10] << " YEARS" << endl;
        cout << "12. Specialty About You :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void show_doctor_dir(string file)
{
    file = "doctor/" + file + ".txt";

    ifstream fin;
    vector <string> str;
    char* filename = &file[0];
    logo();
    fin.open(filename);

    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        system("cls");
        exit(0);
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t Dr. " << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Doctor First Name :" << str[0] << endl;
        cout << "2. Doctor Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Highest Degree :" << str[8] << endl;
        cout << "10. Special Degree :" << str[9] << endl;
        cout << "11. Years of Experience :" << str[10] << " YEARS" << endl;
        cout << "12. Specialty About You :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Edit_doctor(string file)
{
    show_doctor_dir(file);
    file = "doctor/" + file + ".txt";
    char* filename = &file[0]; 
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    ofstream out;
    out.open(filename, ios::binary);
A:
    cout << "\nEnter choice you want to edit : ";
    int n;
    string ss;
    cin >> n;
    cin.ignore(1, '\n');
    system("cls");
    logo();
    lastline_firstline();
    cout << "\n\n\n";


    if (n == 1)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i == n - 1) {
                cout << "1. Docter First Name :";
                getline(cin, ss);
                out << ss << endl;
            }
            else
                out << s[i] << endl;
        }
    }
    else
        if (n == 2)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i == n - 1) {
                    cout << "2. Doctor Last Name :";
                    getline(cin, ss);
                    out << ss << endl;
                }
                else
                    out << s[i] << endl;
            }
        }
        else
            if (n == 3)
                for (int i = 0; i < s.size(); i++)
                {
                    if (i == n - 1) {
                        cout << "3. Date of Birth :";
                        getline(cin, ss);
                        out << ss << endl;
                    }
                    else
                        out << s[i] << endl;
                }
            else
                if (n == 4)
                    for (int i = 0; i < s.size(); i++)
                    {
                        if (i == n - 1) {
                            cout << "4. Age :";
                            getline(cin, ss);
                            out << ss << endl;
                        }
                        else
                            out << s[i] << endl;
                    }
                else
                    if (n == 5)
                        for (int i = 0; i < s.size(); i++)
                        {
                            if (i == n - 1) {
                                cout << "5. Sex :";
                                getline(cin, ss);
                                out << ss << endl;
                            }
                            else
                                out << s[i] << endl;
                        }
                    else
                        if (n == 6)
                            for (int i = 0; i < s.size(); i++)
                            {
                                if (i == n - 1) {
                                    cout << "6. Address :";
                                    getline(cin, ss);
                                    out << ss << endl;
                                }
                                else
                                    out << s[i] << endl;
                            }
                        else
                            if (n == 7)
                                for (int i = 0; i < s.size(); i++)
                                {
                                    if (i == n - 1) {
                                        cout << "7. City :";
                                        getline(cin, ss);
                                        out << ss << endl;
                                    }
                                    else
                                        out << s[i] << endl;
                                }
                            else
                                if (n == 8)
                                    for (int i = 0; i < s.size(); i++)
                                    {
                                        if (i == n - 1) {
                                            cout << "8. Pin code :";
                                            getline(cin, ss);
                                            out << ss << endl;
                                        }
                                        else
                                            out << s[i] << endl;
                                    }
                                else
                                    if (n == 9)
                                        for (int i = 0; i < s.size(); i++)
                                        {
                                            if (i == n - 1) {
                                                cout << "9. High Degree :";
                                                getline(cin, ss);
                                                out << ss << endl;
                                            }
                                            else
                                                out << s[i] << endl;
                                        }
                                    else
                                        if (n == 10)
                                            for (int i = 0; i < s.size(); i++)
                                            {
                                                if (i == n - 1) {
                                                    cout << "10. Special Degree :";
                                                    getline(cin, ss);
                                                    out << ss << endl;
                                                }
                                                else
                                                    out << s[i] << endl;
                                            }
                                        else
                                            if (n == 11)
                                                for (int i = 0; i < s.size(); i++)
                                                {
                                                    if (i == n - 1) {
                                                        cout << "11. Years of Experience :";
                                                        getline(cin, ss);
                                                        out << ss << endl;
                                                    }
                                                    else
                                                        out << s[i] << endl;
                                                }
                                            else
                                                if (n == 12)
                                                    for (int i = 0; i < s.size(); i++)
                                                    {
                                                        if (i == n - 1) {
                                                            cout << "12. Specialty About you :";
                                                            getline(cin, ss);
                                                            out << ss << endl;
                                                        }
                                                        else
                                                            out << s[i] << endl;
                                                    }
                                                else
                                                    if (n == 13)
                                                        for (int i = 0; i < s.size(); i++)
                                                        {
                                                            if (i == n - 1) {
                                                                cout << "13. Contact number :";
                                                                getline(cin, ss);
                                                                out << ss << endl;
                                                            }
                                                            else
                                                                out << s[i] << endl;
                                                        }
                                                    else
                                                        if (n == 14)
                                                            for (int i = 0; i < s.size(); i++)
                                                            {
                                                                if (i == n - 1) {
                                                                    cout << "14. Email :";
                                                                    getline(cin, ss);
                                                                    out << ss << endl;
                                                                }
                                                                else
                                                                    out << s[i] << endl;
                                                            }
                                                        else
                                                        {
                                                            cout << "INVALID CHOICE!!!!!!";
                                                            system("cls");
                                                            goto A;
                                                        }
    out.close();
    string tem = "doctor/" + s[0] + " " + s[1] + ".txt";
    copyfile(filename, tem);
    cout << "\nyou have change information successfully\n\n\n\n";
    lastline_firstline();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Receptionist::input_recep()
{
    int n;
    ofstream fout, fpall;
    fstream fserial;
    string dummy;
    logo();
    fpall.open("mainfile/recepall.txt", ios::app);
    fpall << endl;
    fserial.open("mainfile/rserialno.txt", ios::in);
    fserial >> n;
    n++;
    fpall << setw(34) << n << ".";
    fserial.close();
    fserial.open("mainfile/rserialno.txt", ios::out);
    fserial << n;
    fserial.close();
    cin.ignore(100, '\n');
    cout << "Your First Name :";
    getline(cin, fname); fpall << setw(18) << fname << " ";
    cout << "Your Last Name :";
    getline(cin, lname); fpall << lname;
    dummy = "reception/" + fname + " " + lname + ".txt";
    char* filename = &dummy[0];
    fout.open(filename, ios::binary);
    fout << fname << endl;
    fout << lname << endl;
birth:
    cout << "Date of Birth :";
    getline(cin, DOB);
    if (DOB.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT (DD/MM/YYYY) \n";
        goto birth;
    }
    fpall << setw(17) << DOB;
    fout << DOB << endl;
    cout << "Age :";
    {
        string sb = DOB.substr(6, 9);
        int year = stoi(sb);
        sb = DOB.substr(3, 2);
        int month = stoi(sb);
        sb = DOB.substr(0, 2);
        int date = stoi(sb);
        int autoage = auto_age(date, month, year);
        age = to_string(autoage);
        cout << age << endl;
    }
    fpall << setw(12) << age;
    fout << age << endl;
s:
    cout << "Sex :";
    getline(cin, sex);
    if (sex != "female" && sex != "Female" && sex != "F" && sex != "FEMALE" && sex != "MALE" && sex != "Male" && sex != "M" && sex != "male")
    {
        cout << "WRONG ENTRY!!!PLEASE CHOOSE Right Gender \n";
        goto s;
    }
    fout << sex << endl;
    cout << "Address :";
    getline(cin, address);
    fout << address << endl;
    fpall << setw(15) << address;
    cout << "City :";
    getline(cin, city); fpall << " " << city;
    fout << city << endl;
pin:
    cout << "Pin code :";
    getline(cin, ppin);
    if (ppin.size() != 6)
    {
        cout << "WRONG PINCODE!!!  \n";
        goto pin;
    }
    fout << ppin << endl;
    cout << "High Degree :";
    getline(cin, higdeg);
    fout << higdeg << endl;
    fpall << setw(12) << higdeg;
    cout << "Language You know :";
    getline(cin, lang);
    fout << lang << endl;
w:
    cout << "Years of experience :";
    getline(cin, yearexp);
    if (!checkstrsize(yearexp, 2))
        goto w;
    fpall << setw(14) << yearexp;
    fout << yearexp << endl;
d_n:
    cout << "Day/Night Shift :";
    getline(cin, D_N_shift);
    if (D_N_shift != "day" && D_N_shift != "Day" && D_N_shift != "DAY" && D_N_shift != "Night" && D_N_shift != "NIGHT" && D_N_shift != "night")
    {
        cout << "WRONG ENTRY!!!PLEASE CHOOSE ONLY Day/night \n";
        goto d_n;
    }
    fout << D_N_shift << endl;
cn:
    cout << "Contact number :";
    getline(cin, contact_no);
    if (contact_no.size() != 10)
    {
        cout << "PLEASE BE IN FORMAT 72XXXX3060 \n";
        goto cn;
    }
    fpall << setw(18) << contact_no;
    fout << contact_no << endl;
checkm:
    cout << "Email :";
    getline(cin, mail);
    {
        if (checkemail(mail, "mainfile/recepemail.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME EMAIL IN OUR DATEBASE!!..PLEASE TRY DIFFRENT EMAIL\n";
            goto checkm;
        }

    }
    fout << mail << endl;
    fpall << setw(26) << mail << endl;
passcheck:
newpasscheck: cout << "New password :";
    getline(cin, newpass);
    {
        if (checkpassword(newpass, "mainfile/receppass.txt"))
        {
            cout << "YOU HAVE ENTER THE SAME PASSWORD IN OUR DATEBASE!!..PLEASE TRY DIFFRENT PASSWORD\n";
            goto newpasscheck;
        }
    }
    cout << "Confirm password :";
    getline(cin, conpass);
    if (conpass != newpass || newpass.size() >= 10)
    {
        cout << "Password does not match!!!!!!!\n";
        cout << "OR your password is more than 10 words!!!!!\n";
        goto passcheck;
    }
    ofstream femail, fpass;
    femail.open("mainfile/recepemail.txt", ios::app);
    femail << mail << endl;
    femail.close();
    fpass.open("mainfile/receppass.txt", ios::app);
    fpass << newpass << endl;
    fpass.close();
check:
    string checkok;
    cout << "Type OK to confirm!!!!\n";
    cin >> checkok;
    if (checkok != "OK")
    {
        cout << "Please Type OK correctly!!!";
        goto check;
    }
    string tmail = "reception/" + mail + ".txt";
    copyfile(dummy, tmail);
    fpall.close();
    fout.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Add_recep()
{
    Receptionist R;
    R.input_recep();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Signup_as_a_recep()
{
    Add_recep();
    cout << "You have Sign up As a Receptionist Successfully!!!!!\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void show_all_recep()
{
    char ch;
    ifstream fin;
    fin.open("mainfile/recepall.txt", ios::binary);
    while (!fin.eof())
    {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void remove_recep()
{
    string delfile;
    logo();
    cin.ignore(1, '\n');
    cout << "ENTER THE RECEPTIONIST NAME YOU WANT TO FIRED : ";
    getline(cin, delfile);
    delfile = "reception/" + delfile + ".txt";
    char* filedel = &delfile[0];
    vector<string> s;
    ifstream fin;
    fin.open(filedel);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    vector<string> ss;
    fin.open("mainfile/recepemail.txt");
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        ss.push_back(temp);
    }
    fin.close();
    string temp = s[13];
    ofstream fout;
    fout.open("mainfile/recepemail.txt", ios::binary);

    temp = "reception/" + temp + ".txt";
    char* maildel = &temp[0];

    const int result1 = remove(filedel);
    const int result2 = remove(maildel);

    if (result1 == 0 && result2 == 0) {
        printf("\n\n\nYOUR RECEPTIONIST IS FIRED!!!!!!\n\n\n");
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == s[13])
            {
                fout << '\0';
            }
            else
                fout << ss[i] << endl;
        }
    }
    else {
        printf("\n\nFILE NOT FOUND!!!!ERRORRR...!!!\n\n\n");
        system("cls");
        remove_recep();
    }
    fout.close();

}
////////////////////////////////////////////////////////////////////////////////////////////
void show_recep()
{
    ifstream fin;
    vector <string> str;
    string file;
reenterfile:
    logo();
    cin.ignore(1, '\n');
    cout << "Enter the Receptionist name you want to open :";
    getline(cin, file);
    file = "reception/" + file + ".txt";
    char* filename = &file[0];
    fin.open(filename);

    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        system("cls");
        goto reenterfile;
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Receptionist First Name :" << str[0] << endl;
        cout << "2. Receptionist Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Highest Degree :" << str[8] << endl;
        cout << "10. Language You know :" << str[9] << endl;
        cout << "11. Years of Experience :" << str[10] << " years" << endl;
        cout << "12. Day/Night Shift :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
////////////////////////////////////////////////////////////////
void show_recep_dir(string file)
{
    file = "reception/" + file + ".txt";

    ifstream fin;
    vector <string> str;
    char* filename = &file[0];
    logo();
    fin.open(filename);

    if (!fin)
    {
        cout << "\nError while opening the file\n";
        system("pause");
        system("cls");
        exit(0);
    }
    else
    {
        while (!fin.eof()) {
            string s = "";
            getline(fin, s);
            str.push_back(s);

        }
        cout << "\n\n";
        cout << "\t\t\t\t*******************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << str[0] + " " + str[1] << endl;
        cout << "\t\t\t\t*******************************************************************************************************************\n\n\n";
        cout << "1. Your First Name :" << str[0] << endl;
        cout << "2. Your Last Name :" << str[1] << endl;
        cout << "3. Date of Birth :" << str[2] << endl;
        cout << "4. Age :" << str[3] << " YEARS" << endl;
        cout << "5. Sex :" << str[4] << endl;
        cout << "6. Address :" << str[5] << endl;
        cout << "7. City :" << str[6] << endl;
        cout << "8. Pin code :" << str[7] << endl;
        cout << "9. Highest Degree :" << str[8] << endl;
        cout << "10. Language You Know :" << str[9] << endl;
        cout << "11. Years of Experience :" << str[10] << " years" << endl;
        cout << "12. Day/Night shift :" << str[11] << endl;
        cout << "13. Contact number :" << str[12] << endl;
        cout << "14. Email :" << str[13] << endl;
        cout << "\n\t\t\t\t**********************************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t\t\t\t.............ENDING OF FILE...........\n\n";
        fin.close();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Edit_recep(string file)
{
    show_recep_dir(file);
    file = "reception/" + file + ".txt";
    char* filename = &file[0];
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while (!fin.eof()) {
        string temp = "";
        getline(fin, temp);
        s.push_back(temp);
    }
    fin.close();
    ofstream out;
    out.open(filename, ios::binary);
A:
    cout << "\nEnter choice you want to edit : ";
    int n;
    string ss;
    cin >> n;
    cin.ignore(1, '\n');
    system("cls");
    logo();
    lastline_firstline();
    cout << "\n\n\n";


    if (n == 1)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i == n - 1) {
                cout << "1. Your First Name :";
                getline(cin, ss);
                out << ss << endl;
            }
            else
                out << s[i] << endl;
        }
    }
    else
        if (n == 2)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i == n - 1) {
                    cout << "2. Your Last Name :";
                    getline(cin, ss);
                    out << ss << endl;
                }
                else
                    out << s[i] << endl;
            }
        }
        else
            if (n == 3)
                for (int i = 0; i < s.size(); i++)
                {
                    if (i == n - 1) {
                        cout << "3. Date of Birth :";
                        getline(cin, ss);
                        out << ss << endl;
                    }
                    else
                        out << s[i] << endl;
                }
            else
                if (n == 4)
                    for (int i = 0; i < s.size(); i++)
                    {
                        if (i == n - 1) {
                            cout << "4. Age :";
                            getline(cin, ss);
                            out << ss << endl;
                        }
                        else
                            out << s[i] << endl;
                    }
                else
                    if (n == 5)
                        for (int i = 0; i < s.size(); i++)
                        {
                            if (i == n - 1) {
                                cout << "5. Sex :";
                                getline(cin, ss);
                                out << ss << endl;
                            }
                            else
                                out << s[i] << endl;
                        }
                    else
                        if (n == 6)
                            for (int i = 0; i < s.size(); i++)
                            {
                                if (i == n - 1) {
                                    cout << "6. Address :";
                                    getline(cin, ss);
                                    out << ss << endl;
                                }
                                else
                                    out << s[i] << endl;
                            }
                        else
                            if (n == 7)
                                for (int i = 0; i < s.size(); i++)
                                {
                                    if (i == n - 1) {
                                        cout << "7. City :";
                                        getline(cin, ss);
                                        out << ss << endl;
                                    }
                                    else
                                        out << s[i] << endl;
                                }
                            else
                                if (n == 8)
                                    for (int i = 0; i < s.size(); i++)
                                    {
                                        if (i == n - 1) {
                                            cout << "8. Pin code :";
                                            getline(cin, ss);
                                            out << ss << endl;
                                        }
                                        else
                                            out << s[i] << endl;
                                    }
                                else
                                    if (n == 9)
                                        for (int i = 0; i < s.size(); i++)
                                        {
                                            if (i == n - 1) {
                                                cout << "9. High Degree :";
                                                getline(cin, ss);
                                                out << ss << endl;
                                            }
                                            else
                                                out << s[i] << endl;
                                        }
                                    else
                                        if (n == 10)
                                            for (int i = 0; i < s.size(); i++)
                                            {
                                                if (i == n - 1) {
                                                    cout << "10. Language You know :";
                                                    getline(cin, ss);
                                                    out << ss << endl;
                                                }
                                                else
                                                    out << s[i] << endl;
                                            }
                                        else
                                            if (n == 11)
                                                for (int i = 0; i < s.size(); i++)
                                                {
                                                    if (i == n - 1) {
                                                        cout << "11. Years of Experience :";
                                                        getline(cin, ss);
                                                        out << ss << endl;
                                                    }
                                                    else
                                                        out << s[i] << endl;
                                                }
                                            else
                                                if (n == 12)
                                                    for (int i = 0; i < s.size(); i++)
                                                    {
                                                        if (i == n - 1) {
                                                            cout << "12. Day/Night Shift :";
                                                            getline(cin, ss);
                                                            out << ss << endl;
                                                        }
                                                        else
                                                            out << s[i] << endl;
                                                    }
                                                else
                                                    if (n == 13)
                                                        for (int i = 0; i < s.size(); i++)
                                                        {
                                                            if (i == n - 1) {
                                                                cout << "13. Contact number :";
                                                                getline(cin, ss);
                                                                out << ss << endl;
                                                            }
                                                            else
                                                                out << s[i] << endl;
                                                        }
                                                    else
                                                        if (n == 14)
                                                            for (int i = 0; i < s.size(); i++)
                                                            {
                                                                if (i == n - 1) {
                                                                    cout << "14. Email :";
                                                                    getline(cin, ss);
                                                                    out << ss << endl;
                                                                }
                                                                else
                                                                    out << s[i] << endl;
                                                            }
                                                        else
                                                        {
                                                            cout << "INVALID CHOICE!!!!!!";
                                                            system("cls");
                                                            goto A;
                                                        }
    out.close();
    string tem = "reception/" + s[0] + " " + s[1] + ".txt";
    copyfile(filename, tem);
    cout << "\nyou have change information successfully\n\n\n\n";
    lastline_firstline();
}