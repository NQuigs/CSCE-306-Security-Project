#pragma once
//#include "User.h"


namespace PRJSecurityProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Shop
	/// </summary>
	public ref class Shop : public System::Windows::Forms::Form
	{
		User* user;
	public:
		Shop(User* currentUser)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			user = currentUser;
		}
		
		Shop()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Shop()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBuy;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;

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
			this->btnBuy = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBuy
			// 
			this->btnBuy->Location = System::Drawing::Point(390, 216);
			this->btnBuy->Name = L"btnBuy";
			this->btnBuy->Size = System::Drawing::Size(210, 114);
			this->btnBuy->TabIndex = 0;
			this->btnBuy->Text = L"Buy me";
			this->btnBuy->UseVisualStyleBackColor = true;
			this->btnBuy->Click += gcnew System::EventHandler(this, &Shop::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(466, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"LeStuff";
			// 
			// Shop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 431);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnBuy);
			this->Name = L"Shop";
			this->Text = L"Shop";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		/*std::string itemName;
		itemName = label1->Text; 
			DataTable */

	}
	};
}
