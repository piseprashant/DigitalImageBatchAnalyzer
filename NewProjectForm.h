#pragma once
#include "SettingFiles.h"

namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	


	

	/// <summary>
	/// Summary for NewProjectForm
	/// </summary>
	public ref class NewProjectForm : public System::Windows::Forms::Form
	{
	public:
		NewProjectForm(void)
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
		~NewProjectForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  newprojectname;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::FolderBrowserDialog^  newprojectfolder;

	public: String ^ PathCWD;
	public: String^ ProjectName;
	public: bool IsSaved;

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
			this->newprojectname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->newprojectfolder = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(162, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewProjectForm::button1_Click);
			// 
			// newprojectname
			// 
			this->newprojectname->Location = System::Drawing::Point(162, 38);
			this->newprojectname->Name = L"newprojectname";
			this->newprojectname->Size = System::Drawing::Size(228, 20);
			this->newprojectname->TabIndex = 1;
			this->newprojectname->Text = L"<prjoect name>";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Browse project directory";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(234, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NewProjectForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(315, 64);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &NewProjectForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Project Name";
			// 
			// newprojectfolder
			// 
			this->newprojectfolder->HelpRequest += gcnew System::EventHandler(this, &NewProjectForm::folderBrowserDialog1_HelpRequest);
			// 
			// NewProjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(402, 105);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->newprojectname);
			this->Controls->Add(this->button1);
			this->Name = L"NewProjectForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New Project";
			this->Load += gcnew System::EventHandler(this, &NewProjectForm::NewProjectForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/***********************************************************************************************/
//Open a folder diloage box for browsing to new project directory
/***********************************************************************************************/
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
try{
				newprojectfolder->ShowDialog();
} catch ( Exception^ ex ) {
	ThrowError(ex, "OpenfolderNewproject");
	//LogMessage("","");
}
			 }
	private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
			 }

/***********************************************************************************************/
//Save the new created project
/***********************************************************************************************/
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 
try{			
			this->PathCWD=this->newprojectfolder->SelectedPath;
			
				if(!Path::HasExtension(newprojectname->Text))
			this->ProjectName=String::Concat(newprojectname->Text,".",ProjectExtension);
			
		     this->IsSaved=true;
			 this->Close();
} catch ( Exception^ ex ) {
	ThrowError(ex, "saveproject");
	//LogMessage("","");
}

		 }
/***********************************************************************************************/
//Cancel the creation of new project
/***********************************************************************************************/
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
try{
			  this->Close();
} catch ( Exception^ ex ) {
	ThrowError(ex, "NewprojectCancel");
	//LogMessage("","");
}
		 }

/***********************************************************************************************/
//Initializing project creation flag to false
/***********************************************************************************************/
private: System::Void NewProjectForm_Load(System::Object^  sender, System::EventArgs^  e) {
try{
IsSaved=false;
} catch ( Exception^ ex ) {
	ThrowError(ex, "NewProjectForm_Load");
	//LogMessage("","");
}
		 }
};
}
