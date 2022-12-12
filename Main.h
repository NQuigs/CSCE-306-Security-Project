/*
Author: Rubber Duckers LLC
Security Project
12/11/2022
What it is supposed to do: Function like a shop and let customers log in, place orders, and update their accounts, allow managers/sales to process orders,
allow managers to update store items and create accounts, save order info, account info.

What it currently does: login

Future updates: Implement created classes to allow a functioning security shop.

Issues: Linker would have issues when performing multi-leveled inheritance and caused errors. When attempted to fix, the classes would be 
considered undefined despite having their class definitions included from another file. Deadline didn't allow for a production level design.
Github still did not work, so only one person could work on the form. When we managed to share the files, the files didn't work on
the other computers despite matching settings/environments in visual studio. Time spent working together was mainly focused on troubleshooting errors instead
of focusing on the implementation of desired functionality
*/


#pragma once
#include "BusinessCustomer.h"
#include "PersonalCustomer.h"
#include "GovernmentCustomer.h"
#include "Manager.h"
#include "Sales.h"
#include <msclr\marshal_cppstd.h>




namespace PRJSecurityProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
		User* currentUser;
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnLogIn;
	private: System::Windows::Forms::TextBox^ txtUser;
	private: System::Windows::Forms::TextBox^ txtPass;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLogIn = (gcnew System::Windows::Forms::Button());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnLogIn
			// 
			this->btnLogIn->Location = System::Drawing::Point(465, 312);
			this->btnLogIn->Name = L"btnLogIn";
			this->btnLogIn->Size = System::Drawing::Size(175, 77);
			this->btnLogIn->TabIndex = 1;
			this->btnLogIn->Text = L"Log in";
			this->btnLogIn->UseVisualStyleBackColor = true;
			this->btnLogIn->Click += gcnew System::EventHandler(this, &Main::btnLogIn_Click);
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(415, 120);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(281, 26);
			this->txtUser->TabIndex = 2;
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(415, 202);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(281, 26);
			this->txtPass->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(509, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(513, 176);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1173, 524);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->btnLogIn);
			this->Name = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/// <summary>
	/// Log in. Displays success or failure 
	/// </summary>
	private: System::Void btnLogIn_Click(System::Object^ sender, System::EventArgs^ e) {
		Customer cust;

		System::String^ username = txtUser->Text;
		System::String^ password = txtPass->Text;

		std::string user = msclr::interop::marshal_as<std::string>(username);
		std::string pass = msclr::interop::marshal_as<std::string>(password);

		Utilities util;

		std::vector<std::string> userInfo = util.read("CustAccountInfo.txt", user, pass);
		if (userInfo.size() == 3)
		{
			int accessLevel = std::stoi(userInfo[2]);

			//initializes user object based on access level
			switch (accessLevel)
			{
			case 1:
			{
				Manager mgmt;
				mgmt.setUserId(userInfo[0]);
				mgmt.setPassword(userInfo[1]);
				mgmt.setAccessLevel(userInfo[2]);
				saveObject(&mgmt);
				break;
			}
			case 2:
			{
				Sales sale;
				sale.setUserId(userInfo[0]);
				sale.setPassword(userInfo[1]);
				sale.setAccessLevel(userInfo[2]);
				saveObject(&sale);
				break;
			}
			case 3:
			{
				GovernmentCustomer gov;
				gov.setUserId(userInfo[0]);
				gov.setPassword(userInfo[1]);
				gov.setAccessLevel(userInfo[2]);
				saveObject(&gov);
				break;
			}
			case 4:
			{
				BusinessCustomer bus;
				bus.setUserId(userInfo[0]);
				bus.setPassword(userInfo[1]);
				bus.setAccessLevel(userInfo[2]);
				saveObject(&bus);
				break;
			}
			case 5:
			{
				PersonalCustomer person;
				person.setUserId(userInfo[0]);
				person.setPassword(userInfo[1]);
				person.setAccessLevel(userInfo[2]);
				saveObject(&person);
				break;
			}
			}
		}

		else
			MessageBox::Show("Login failed!");
	}
	
	//Saves the created object
	private: System::Void saveObject(User* user)
	{
		currentUser = user;
		MessageBox::Show("Login successful!");
	}

	};
}
