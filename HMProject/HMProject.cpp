#include "mylibrary.h"
string gmail="";

void Sign_in(string mail, string pass)
{
	static int counte = 0;
	logo();
	string email;
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t Email : ";
	cin >> email;
	if (checkemail(email, mail)) {
		int n = password(mail, pass);
		if (n == 1)
		{
			gmail = email;
			return;
		}
	}
	else
		if (counte < 2)
		{
			counte++;
			cout << "\n wrong email try again please!!! \n ";
			system("pause");
			system("cls");
			gmail = "";
			Sign_in(mail, pass);
		}
		else
		{
			cout << "\nYou have crossed the limit to enter wrong email!!!!\n\n\n";
			exit(0);
		}
}

int main()
{
	char ch;
menu:
	drawframe("mainfile/page1.txt");
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
	ch = _getche();
	if (ch == '1')
	{
		system("cls");
		drawframe("mainfile/page2.txt");
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
		char ch1;
		ch1 = _getche();
		if (ch1 == '1')
		{ //string gmail;
			system("cls");
			Sign_in("mainfile/adminemail.txt", "mainfile/adminpass.txt");
			cout << "\n\n\n";
		docback:
			system("pause");
			system("cls");
			drawframe("mainfile/admin.txt");
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
			char ch2;
			ch2 = _getche();
			switch (ch2)
			{
			case '1':
				system("cls");
				Add_Doctor();
				goto docback;
			case '2':
				system("cls");
				Add_recep();
				goto docback;
			case '3':
				system("cls");
				show_doctor();
				goto docback;
			case '4':
				system("cls");
				show_recep();
				goto docback;
			case '5':
				system("cls");
				show_all_doctor();
				goto docback;
			case '6':
				system("cls");
				show_all_recep();
				goto docback;
			case '7':
				system("cls");
				remove_doctor();
				goto docback;
			case '8':
				system("cls");
				remove_recep();
				goto docback;
			case '9':
				cout << "\nlogout..";
				log_out_animation();
				system("cls");
				gmail = "";
				goto menu;
			default:
				cout << "\nINVALID CHOICE!!!!!!!!!\n";
				goto docback;

			}

		}
		else
			if (ch1 == '2')
			{   // //string gmail;
				system("cls");
				Sign_in("mainfile/doctoremail.txt", "mainfile/doctorpass.txt");
				cout << "\n\n\n";
			dback:
				system("pause");
				system("cls");
				drawframe("mainfile/doctor.txt");
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
				char ch3;
				ch3 = _getche();
				switch (ch3)
				{
				case '1':
					system("cls");
					show_doctor_dir(gmail);
					goto dback;
				case '2':
					system("cls");
					Edit_doctor(gmail);
					goto dback;
				case '3':
					system("cls");
					show_all_doctor();
					goto dback;
				case '4':
					system("cls");
					show_patient();
					goto dback;
				case '5':
					system("cls");
					show_all_Patient();
					goto dback;
				case '6':
					system("cls");
					discharge_patient();
					goto dback;
				case '7':
					cout << "\nlogout..";
					log_out_animation();
					system("cls");
					gmail = "";
					goto menu;
				default:
					cout << "\nINVALID CHOICE!!!!!!!!!\n";
					goto dback;

				}
			}
			else
				if (ch1 == '3')
				{   ////string gmail;
					system("cls");
					Sign_in("mainfile/patientemail.txt", "mainfile/patientpass.txt");
					cout << "\n\n\n";
				back:
					system("pause");
					system("cls");
					drawframe("mainfile/patient.txt");
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
					char ch4;
					ch4 = _getche();
					switch (ch4)
					{
					case '1':
						system("cls");
						show_patient_dir(gmail);
						goto back;
					case '2':
						system("cls");
						Edit_patient(gmail);
						goto back;
					case '3':
						cout << "\nlogout..";
						log_out_animation();
						system("cls");
						gmail = "";
						goto menu;
					case '4':
						system("cls");
						drawframe("mainfile/abouthospital.txt");
						about_animation();
						goto back;
					default:
						cout << "\nINVALID CHOICE!!!!!!!!!\n";
						goto back;
					}
				}
				else
					if (ch1 == '4')
					{ // string gmail;
						system("cls");
						Sign_in("mainfile/recepemail.txt", "mainfile/receppass.txt");
						cout << "\n\n\n";
					rback:
						system("pause");
						system("cls");
						drawframe("mainfile/receptionist.txt");
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
						char ch5;
						ch5 = _getche();
						switch (ch5)
						{
						case '1':
							system("cls");
							show_recep_dir(gmail);
							goto rback;
						case '2':
							system("cls");
							Edit_recep(gmail);
							goto rback;
						case '3':
							system("cls");
							Add_Patient();
							goto rback;
						case '4':
							system("cls");
							show_patient();
							goto rback;
						case '5':
							system("cls");
							show_all_Patient();
							goto rback;
						case '6':
							system("cls");
							discharge_patient();
							goto rback;
						case '7':
							cout << "\nlogout..";
							log_out_animation();
							system("cls");
							gmail = "";
							goto menu;
						default:
							cout << "\nINVALID CHOICE!!!!!!!!!\n";
							goto rback;

						}
					}
					else
						if (ch1 == '5')
						{
							system("cls");
							goto menu;
						}
						else
						{
							cout << "\nINVALID CHOICE!!!!!!\n";
							system("pause");
							system("cls");
							goto menu;
						}
	}
	else
		if (ch == '2')
		{
			system("cls");
			drawframe("mainfile/page3.txt");
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Enter choice :";
			char ch22;
			ch22 = _getche();
			if (ch22 == '1')
			{
				system("cls");
				Signup_as_a_doctor();
				system("pause");
				system("cls");
				goto menu;
			}
			else
				if (ch22 == '2')
				{
					system("cls");
					Signup_as_a_patient();
					system("pause");
					system("cls");
					goto menu;
				}
				else
					if (ch22 == '3')
					{
						system("cls");
						Signup_as_a_recep();
						system("pause");
						system("cls");
						goto menu;
					}
					else
						if (ch22 == '4')
						{
							system("cls");
							goto menu;
						}
						else
						{
							cout << "\nINVALID CHOICE!!!!!!\n";
							system("pause");
							system("cls");
							goto menu;
						}

		}
		else
		{
			cout << "\nINVALID CHOICE!!!!!!\n";
			system("pause");
			system("cls");
			goto menu;
		}
	return 0;
}