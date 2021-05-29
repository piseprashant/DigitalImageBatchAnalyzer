#pragma once

#include"IPOHandling.h"

namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for IPORunNotification
	/// </summary>
	public ref class IPORunNotification : public System::Windows::Forms::Form
	{
	public:
		IPORunNotification(void)
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
		~IPORunNotification()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  Log;
	protected: 

	private: System::Windows::Forms::Button^  button1;
			 //My vars
	public: static IPOHandling^ IPOHandler;
	public: static Thread ^StackExecutionThread;
	protected: 

	protected: 

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
			this->Log = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Log
			// 
			this->Log->Location = System::Drawing::Point(0, 1);
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Log->Size = System::Drawing::Size(283, 218);
			this->Log->TabIndex = 1;
			this->Log->Text = L"";
			// 
			// button1
			// 
			this->button1->AutoEllipsis = true;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1, 221);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(283, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IPORunNotification::button1_Click);
			// 
			// IPORunNotification
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Log);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"IPORunNotification";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Stack Running....";
			this->Load += gcnew System::EventHandler(this, &IPORunNotification::IPORunNotification_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
/***********************************************************************************************/
//Function to stop the stack run
/***********************************************************************************************/
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

IPOHandler->Stop_BatchProcessing=true;
IPOHandler->Stop_CamCapture=true;
IPOHandler->Stop_DinamicMonitor=true;
IPOHandler->StopDinamicMonitor(StackExecutionThread);
this->Close();
}
	private: System::Void IPORunNotification_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
