#pragma once
#include "BusinessCustomer.h"
#include "PersonalCustomer.h"
#include "GovernmentCustomer.h"
#include "Manager.h"
#include "Sales.h"
#include <msclr\marshal_cppstd.h>
#include "Shop.h"



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
	private: System::Windows::Forms::Button^ btnCreate;
	protected:
	private: System::Windows::Forms::Button^ btnLogIn;
	private: System::Windows::Forms::TextBox^ txtUser;
	private: System::Windows::Forms::TextBox^ txtPass;

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
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btnLogIn = (gcnew System::Windows::Forms::Button());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnCreate
			// 
			this->btnCreate->Location = System::Drawing::Point(667, 316);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(186, 77);
			this->btnCreate->TabIndex = 0;
			this->btnCreate->Text = L"Create Account";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &Main::btnCreate_Click);
			// 
			// btnLogIn
			// 
			this->btnLogIn->Location = System::Drawing::Point(257, 316);
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
			this->txtPass->Location = System::Drawing::Point(338, 202);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(422, 26);
			this->txtPass->TabIndex = 3;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1173, 524);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->btnLogIn);
			this->Controls->Add(this->btnCreate);
			this->Name = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e) {


	}

	private: System::Void btnLogIn_Click(System::Object^ sender, System::EventArgs^ e) {
		Customer cust;

		System::String^ username = txtUser->Text;
		System::String^ password = txtPass->Text;

		std::string user = msclr::interop::marshal_as<std::string>(username);
		std::string pass = msclr::interop::marshal_as<std::string>(password);

		Utilities util;

		std::vector<std::string> userInfo = util.read("CustAccountInfo.txt", user, pass);

		int accessLevel = std::stoi(userInfo[2]);

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
		default:
			std::string error = "Something went wrong. Please try again.";
		}

		Shop^ frm = gcnew Shop(currentUser);
		this->Show(frm);
			
	}
	

	private: System::Void saveObject(User* user)
	{
		currentUser = user;
	}

	};
}
