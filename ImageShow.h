#pragma once

#include "IPOHandling.h"

namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImageShow
	/// </summary>
	public ref class ImageShow : public System::Windows::Forms::Form
	{

	public: IPOHandling^ IPOHandler;///comes from the parent form
	public:
		ImageShow()
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
		~ImageShow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Bitmap^ Image;
	private: System::Windows::Forms::PictureBox^  IMShowbox;

	private: System::Windows::Forms::Button^  NextImage;

	


			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->IMShowbox = (gcnew System::Windows::Forms::PictureBox());
			this->NextImage = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->IMShowbox))->BeginInit();
			this->SuspendLayout();
			// 
			// IMShowbox
			// 
			this->IMShowbox->Location = System::Drawing::Point(0, 32);
			this->IMShowbox->Name = L"IMShowbox";
			this->IMShowbox->Size = System::Drawing::Size(530, 410);
			this->IMShowbox->TabIndex = 0;
			this->IMShowbox->TabStop = false;
			this->IMShowbox->Click += gcnew System::EventHandler(this, &ImageShow::IMShowbox_Click);
			// 
			// NextImage
			// 
			this->NextImage->Location = System::Drawing::Point(0, 1);
			this->NextImage->Name = L"NextImage";
			this->NextImage->Size = System::Drawing::Size(530, 25);
			this->NextImage->TabIndex = 2;
			this->NextImage->Text = L"Next Image";
			this->NextImage->UseVisualStyleBackColor = true;
			this->NextImage->Click += gcnew System::EventHandler(this, &ImageShow::NextImage_Click);
			// 
			// ImageShow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 446);
			this->Controls->Add(this->NextImage);
			this->Controls->Add(this->IMShowbox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(0, 230);
			this->Name = L"ImageShow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ImageShow";
			this->Load += gcnew System::EventHandler(this, &ImageShow::ImageShow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->IMShowbox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/***********************************************************************************************/
//Function to show image when app starts
/***********************************************************************************************/
	private: System::Void ImageShow_Load(System::Object^  sender, System::EventArgs^  e) {			
try{
			Bitmap^ Im=IPOHandler->SampleInput(false);
			if(Im)
					ShowImage(Im);
			else{
					
					Im=IPOHandler->SampleInput(true);
					if(Im)
					ShowImage(Im);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageShow_Load");
	//LogMessage("","");
}
			 }
/***********************************************************************************************/
//Function to show image
/***********************************************************************************************/

	public: void ShowImage(Bitmap^ Im)
			{
try{
				if(Im->Width>=Im->Height){
					Int32 newImheight=(int)(	(float)this->IMShowbox->Width/((float)Im->Width/(float)Im->Height));
					Image=gcnew Bitmap(Im,System::Drawing::Size(this->IMShowbox->Width,newImheight));
					IMShowbox->Image=Image;
				}
				else{
					Int32 newImwidth=(int)	((float)this->IMShowbox->Height*((float)Im->Width/(float)Im->Height));
					Image=gcnew Bitmap(Im,System::Drawing::Size(newImwidth,this->IMShowbox->Height));
					IMShowbox->Image=Image;
				}
} catch ( Exception^ ex ) {
	ThrowError(ex, "ShowImage");
	//LogMessage("","");
}				
			}
	private: System::Void IMShowbox_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				  
			 }
/***********************************************************************************************/
//Function to advance to next image on button press
/***********************************************************************************************/
private: System::Void NextImage_Click(System::Object^  sender, System::EventArgs^  e) {
try{
			Bitmap^ Im=IPOHandler->SampleInput(false);
			if(Im)
					ShowImage(Im);
			else{
					
					Im=IPOHandler->SampleInput(true);
					if(Im)
					ShowImage(Im);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "NextImage_Click");
	//LogMessage("","");
}
		 }
};
}
