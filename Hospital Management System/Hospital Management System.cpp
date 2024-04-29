#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// Hospital Class
class hospital {
public:
	void login();
	void main_menu();
	void add_doctor();
	void show_doctors();
	void add_doctor_appointments();
	void show_doctor_appointments();
	void update_doctor();
	void del_doctor();
	void hospitaldetails();
};

void hospital::login()
{
	system("cls");
	cout<<"loging details";
}

// Function to display the menus
void hospital::main_menu()
{
	system("cls");
	cout<<"\t\t---------------------------------------------"<<endl;
	cout << "\t\t<<---*** SPIRE HEALTH CARE HOSPITAL ***--->>\n";
	cout<<"\t\t---------------------------------------------"<<endl;
	cout << "\n\n1. ADD DOCTOR";
	cout << "\n2. DISPLAY DOCTORS";
	cout << "\n3. ADD DOCTOR APPOINTMENT";
	cout << "\n4. VIEW DOCTOR APPOINTMENT";
	cout << "\n5. UPDATE DOCTOR";
	cout << "\n6. DELETE DOCTOR";
	cout << "\n7. HOSPITAL DETAILS";
	cout << "\n8. EXIT";
}

// Function to add doctor
void hospital::add_doctor()
{
	system("cls");
	fstream file;
	
	string d_id,d_name, d_chatgory;
	cout << "\n\n\t\t\t\tADD DOCTORS";
	cout << "\n\nDoctor ID : ";
	cin >> d_id;
	cout << "\nDoctor Name : ";
	cin >> d_name;
	cout << "\nDoctors Chatogary : ";
	cin >> d_chatgory;
	
	

	// Open file in append or
	// output mode
	file.open("doctor.txt",
			ios::out | ios::app);  
	file << " " << d_id << "    "
		<< d_name << "    " << d_chatgory<< "\n";
	file.close();
}

// Function to show doctors
void hospital::show_doctors()
{
	system("cls");
	fstream file;
	string d_id,d_name, d_chatgory;
	cout << "\n\n\t\t\t\t\tAll DOCTORS";

	// Open the file in input mode
	file.open("doctor.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nDoctor ID\t\tDoctor"
			<< "\t\tDoctor Chatogory\t\t\n\n";
		file >> d_id >> d_name;
		file >> d_chatgory;

		while (!file.eof()) {

			cout << " " << d_id
				<< "\t\t\t" << d_name
				<< "\t\t" << d_chatgory
				<< "\n\n";
			file >> d_id >> d_name;
			file >> d_chatgory;
		}

		system("pause");

		// Close the file
		file.close();
	}
}

// Function to add doctor appointments
void hospital::add_doctor_appointments()
{
	system("cls");
	fstream file;
	
	string app_id, ptn_name, d_name, date;

	cout << "\n\n\t\t\t\tADD APPOINMENTS";
	cout << "\n\nAPPOINMENT ID : ";
	cin >> app_id;
	cout << "\nPatient Name : ";
	cin >> ptn_name;
	cout << "\nDoctor Name : ";
	cin >> d_name;
	cout << "\nDate : ";
	cin >> date;
	
	// Open file in append or
	// output mode
	file.open("appoinment.txt",
			ios::out | ios::app);
	file << " " << app_id << "     "
		<< ptn_name << "     " << d_name<<"     "<< date<< "\n";
	file.close();

}


// Function to show doctor appoinments
void hospital::show_doctor_appointments()
{
	system("cls");
	fstream file;
	string app_id, ptn_name, d_name, date;
	cout << "\n\n\t\t\t\t\tAll APPOINMENTS";

	// Open the file in input mode
	file.open("appoinment.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\n APPOINMENT ID\t\tPatient Name"
			<< "\t\tDoctor Name\t\tDate\n\n";
		file >> app_id >> ptn_name;
		file >> d_name>> date;

		while (!file.eof()) {

			cout << "  " << app_id
				<< "\t\t\t" << ptn_name
				<< "\t\t\t" << d_name
				<< "\t\t" << date
				<< "\n\n";
			file >> app_id >> ptn_name;
			file >> d_name>>date;
		}

		system("pause");

		// Close the file
		file.close();
	}
}

// Function to update the doctor
void hospital::update_doctor()
{
	system("cls");
	fstream file, file1;
	int count = 0;
	string d_id,d_name, d_chatgory;
	string d_na,d_ca,d_idd;

	cout << "\n\n\t\t\t\tUpdate Doctor Record";
	file1.open("doctor1.txt",
			ios::app | ios::out);
	file.open("doctor.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nDoctor ID : ";
		cin >> d_id;
		file >> d_idd >> d_name;
		file >>d_chatgory;

		// Till end of file is reached
		while (!file.eof()) {
			if (d_id == d_idd) {
				system("cls");
				cout << "\t\t\t\t";
				cout<< "Update doctor Record";
				cout << "\n\nNew doctor Name : ";
				cin >> d_na;
				cout << "\nDoctor Chatogory : ";
				cin >> d_ca;
				
				file1 << " " << d_id << " "
					<< d_na << " "
					<< d_ca 
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << d_id
					<< " " << d_name
					<< " " << d_chatgory
					<< "\n\n";
			file >> d_idd >> d_name;
			file >> d_chatgory;
		}
		if (count == 0)
			cout << "\n\nDoctor ID"
				<< " Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	
}

// Function to delete doctor
void hospital::del_doctor()
{
	system("cls");
	fstream file, file1;
	int count = 0;
	string d_id, d_idd, d_name, d_chatgory;
	cout << "\n\n\t\t\t\tDelete a Doctor";

	// Append file in output mode
	file1.open("doctor1.txt",
			ios::app | ios::out);
	file.open("doctor.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\ndoctor ID : ";
		cin >> d_id;
		file >> d_idd >> d_name;
		file >> d_chatgory;
		while (!file.eof()) {

			if (d_id == d_idd) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete a Doctor";
				cout << "\n\nDoctor is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << d_idd
					<< " " << d_name
					<< " " << d_chatgory
					<< "\n\n";
			file >> d_idd >> d_name;
			file >> d_chatgory;
		}
		if (count == 0)
			cout << "\n\nDoctor ID "
				<< "Not Found...";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("doctor.txt");
	rename("doctor1.txt",
		"doctor.txt");
}
// hospital details
void hospital::hospitaldetails()
{

	system("cls");
	cout<<"\n---------------___--<< **ABOUT US** >>--___---------------\n ";
        	cout<<"\nHospital Name : SPIRE HEALTH CARE HOSPITAL "<<endl;
	        cout<<"\nLocation        : 432 Chapel Street, Manchester WID 6HQ, England "<<endl;
        	cout<<"\nContact Number  : +44 456 33445 / +44 456 33265 /+44 456 33358 "<<endl;
        	cout<<"\nFax Number      : +44 456 3341 "<<endl;
	        cout<<"\nEmail           : spirehealthcaregroup@uk.com "<<endl;
        	cout<<"\nOther branchers :Nottingham,Lincolnshire, "<<endl;
	cout<<"\n-------------___--<< ~~~~~~~~~~~~~~~~~~ >>--___------------- ";
	system("pause");
}

// Function for hospital shop record
void HospitalRecord()
{
	
	int choice;
	char x;
	hospital h;

	string username, password;
	
    cout<<"\n\n\n\t |************************************************************************|"<<endl;
	cout<<"\t |*************** | WELCOME TO SPIRE HEALTH CARE HOSPITAL | **************|"<<endl;
	cout<<"\t |************************************************************************|"<<endl;
	cout<<"\n\n\t Admin Loggin--->>\n";
do{
	cout<<"\n\n\t *Enter Your User name : ";
	cin>>username;
	cout<<"\t *Enter Your Password  : ";
	cin>>password;

	
	
	if (username=="admin" && password=="admin123")
	{
		cout<<"\n\n\t Loggin Success!";
		while (1) {

		h.main_menu();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				h.add_doctor();
				cout << "\n\nWant to add"
					<< " another doctor? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			h.show_doctors();
			break;

		case 3:
			do {
			h.add_doctor_appointments();
			cout << "\n\nWant to add"
					<< " another appointment? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;
		
		case 4:
			h.show_doctor_appointments();
			break;
				
		case 5:
			h.update_doctor();
			break;

		case 6:
			h.del_doctor();
			break;
		
		case 7:
		
			h.hospitaldetails();
			break;	
		
		case 8:
			cout << "\n\nAre you sure"
						"(y/n) : ";
				cin >> x;
				if(x=='y'){
					exit(0);
				}
				else{
					continue;
				}
		

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
	}
	
  else
	cout<< "\n\n\t Log in Failed";
	cout<< " \n\n\t Please Try Again";
  
}while(username!= "admin" || password!= "admin123");
}


int main()
{
	// Function Call
HospitalRecord();

	return 0;
}


