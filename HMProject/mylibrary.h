#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<string>
#include<vector>
#include<process.h>
#include<stdio.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<windows.h>
#include<winuser.h>
#include<windowsx.h>
#include<time.h>
using namespace std;

void drawframe(string s);
void log_out_animation();
void about_animation();
void logo();
void lastline_firstline();
void Signup_as_a_doctor();
void show_all_doctor();
void remove_doctor();
int password(string, string);
void Sign_in(string, string);
bool checkpassword(string, string);
bool checkemail(string, string);
void Add_Patient();
void show_patient();
void frame(string ss, string s);
void Signup_as_a_patient();
void discharge_patient();
void show_all_Patient();
void exit();
void copyfile(string, string);
bool checkstrsize(string, int);
int auto_age(int, int, int);
void Edit_patient(string);
void show_patient_dir(string);
void show_doctor_dir(string);
void show_doctor();
void Edit_doctor(string);
void Add_Doctor();
void remove_recep();
void show_all_recep();
void Add_recep();
void Signup_as_a_recep();
void show_recep();
void show_recep_dir(string);
void Edit_recep(string);



/**************************************************************************************************************************************************/
class DATE_TIME
{
private:
    int year;
    int month;
    int date;
public:
    void show_time()
    {   
        tm ptr;
        time_t t = time(0);
        localtime_s(&ptr,&t);
        cout << ptr.tm_hour << ":" << ptr.tm_min << ":" << ptr.tm_sec;
    }
    int get_year()
    {
        time_t t = time(0);
        tm ptr;
        localtime_s(&ptr,&t);
        year = ptr.tm_year;
        year -= 100;
        year += 2000;
        return year;
    }
    int get_month()
    {
        time_t t = time(0);
        tm ptr;
        localtime_s(&ptr,&t);
        month = ptr.tm_mon;
        month += 1;
        return month;
    }
    int get_date()
    {
        time_t t = time(NULL);
        tm ptr;
        localtime_s(&ptr, &t);
        date = ptr.tm_mday;
        return date;
    }
    void show_date()
    {
        cout << get_date() << "-" << get_month() << "-" << get_year();
    }
};
/*************************************************************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class Patient
{
private:
    string pfname;
    string plname;
    string pDOB;
    string page;
    string psex;
    string paddress;
    string pcity;
    string ppin;
    string pre_dis;
    string cur_sym;
    string weight;
    string discreption;
    string contact_no;
    string mail;
    string newpass;
    string conpass;
public:
    void input_patient();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Doctor
{
private:
    string fname;
    string lname;
    string DOB;
    string age;
    string sex;
    string address;
    string city;
    string ppin;
    string higdeg;
    string spedeg;
    string yearexp;
    string spec_ab_u;
    string contact_no;
    string mail;
    string newpass;
    string conpass;
public:

    void input_doctor();
};
/**********************************************************************************************************************/
class Receptionist
{
private:
    string fname;
    string lname;
    string DOB;
    string age;
    string sex;
    string address;
    string city;
    string ppin;
    string higdeg;
    string lang;
    string yearexp;
    string D_N_shift;
    string contact_no;
    string mail;
    string newpass;
    string conpass;
public:

    void input_recep();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////