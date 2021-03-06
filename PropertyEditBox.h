#pragma once
#include "SettingFiles.h"
#include "ParameterObject.h"


namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PropertyEditBox
	/// </summary>
	public ref class PropertyEditBox : public System::Windows::Forms::Form
	{
	public:
		PropertyEditBox(ParameterObject^ Object, ListViewItem^ Item,SettingFiles^ handler)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->ItemFromParentForm=Item;
			this->IPOFromParentForm=Object;
			this->SettingFilesHandler=handler;
		}
		PropertyEditBox(void)
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
		~PropertyEditBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::Label^  PropertyTitle;
	public: System::Windows::Forms::Label^  PropertyDescr;
	private: System::Windows::Forms::Label^  label1;

	//Myvars
	public:  ListViewItem^ ItemFromParentForm;
	public:	 ParameterObject^ IPOFromParentForm;
	public: SettingFiles^ SettingFilesHandler;//This should come from parent Form
	public: System::Windows::Forms::ComboBox^  Value;


	public: 
	private: 



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->PropertyTitle = (gcnew System::Windows::Forms::Label());
			this->PropertyDescr = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Value = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(257, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PropertyEditBox::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(176, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PropertyEditBox::button2_Click);
			// 
			// PropertyTitle
			// 
			this->PropertyTitle->AutoSize = true;
			this->PropertyTitle->Location = System::Drawing::Point(12, 9);
			this->PropertyTitle->Name = L"PropertyTitle";
			this->PropertyTitle->Size = System::Drawing::Size(69, 13);
			this->PropertyTitle->TabIndex = 2;
			this->PropertyTitle->Text = L"Property Title";
			this->PropertyTitle->Click += gcnew System::EventHandler(this, &PropertyEditBox::label1_Click);
			// 
			// PropertyDescr
			// 
			this->PropertyDescr->AutoSize = true;
			this->PropertyDescr->Location = System::Drawing::Point(12, 34);
			this->PropertyDescr->Name = L"PropertyDescr";
			this->PropertyDescr->Size = System::Drawing::Size(74, 13);
			this->PropertyDescr->TabIndex = 3;
			this->PropertyDescr->Text = L"PropertyDescr";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Value";
			// 
			// Value
			// 
			this->Value->FormattingEnabled = true;
			this->Value->Location = System::Drawing::Point(47, 117);
			this->Value->Name = L"Value";
			this->Value->Size = System::Drawing::Size(285, 21);
			this->Value->TabIndex = 6;
			this->Value->SelectedIndexChanged += gcnew System::EventHandler(this, &PropertyEditBox::Value_SelectedIndexChanged);
			// 
			// PropertyEditBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(349, 179);
			this->Controls->Add(this->Value);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PropertyDescr);
			this->Controls->Add(this->PropertyTitle);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"PropertyEditBox";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Property Edit Box";
			this->Load += gcnew System::EventHandler(this, &PropertyEditBox::PropertyEditBox_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
/**********************************************************************************************
	  Updating the curresponding property value
**********************************************************************************************/
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
//Update curresponding IPO file
try{
	IPOFromParentForm->Properties=this->SettingFilesHandler->UpdateProperty(this->ItemFromParentForm->SubItems[0]->Text,this->Value->Text,IPOFromParentForm->Properties);
	this->ItemFromParentForm->SubItems[1]->Text=this->Value->Text;
	this->SettingFilesHandler->UpdateStackSection(this->IPOFromParentForm->UniqueID,this->IPOFromParentForm->Properties);
	this->SettingFilesHandler->UpdateStackFile();
	this->Close();
} catch ( Exception^ ex ) {
	ThrowError(ex, "Propertyedit_Save");
	//LogMessage("","");
}
			 }
/**********************************************************************************************
	 Cancel button click
**********************************************************************************************/
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->Close();
} catch ( Exception^ ex ) {
	ThrowError(ex, "PropertyeditCancel");
	//LogMessage("","");
}
		 }
private: System::Void PropertyEditBox_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Value_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
