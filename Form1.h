#pragma once
#include "Library.h"
#include "IPO_Stack.h"
#include "SettingFiles.h"
#include "NewProjectForm.h"
#include "IPOHandling.h"
#include "ErrorLogs.h"

typedef enum {
	NoProject,
	ProjectLoaded,
	ShowLeftPic,
	ShowCustomPic,
	ShowRightPic,
	ShowWholePic,
	PathShows,
}GUICommand ;




namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}



			 //MyVars
	
	
	public: String^ PathCWD;
	public: static String^ StatusLog;
	public: SettingFiles^ SettingFilesHandler;
	IPO_Stack^ IPOStack;
	Library^ IPOLibrary;
	IPOHandling^ IPOHandler;
	public: ImageShow^ ImShow;
	static bool LoadConfigurationMutx=false;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public: 
	private: System::Windows::Forms::ToolStripMenuItem^  newStackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem1;
	private: System::Windows::Forms::OpenFileDialog^  OpenProject;
	private: System::Windows::Forms::Panel^  Main;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ObjectLibraryOn;
	private: System::Windows::Forms::ToolStripMenuItem^  ObjectSatckOn;




	private: System::Windows::Forms::GroupBox^  SelectRegion;
	private: System::Windows::Forms::GroupBox^  Output;
	private: System::Windows::Forms::TextBox^  SamplePer100;



	private: System::Windows::Forms::CheckBox^  QualityControl;
	private: System::Windows::Forms::Button^  OutputDirPathBtn;




	private: System::Windows::Forms::GroupBox^  Input;
	private: System::Windows::Forms::CheckBox^  CaptureFromCam;

	private: System::Windows::Forms::Button^  InputDirPathBtn;

	private: System::Windows::Forms::Button^  VideoFilePathBtn;






	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  saveAsTimeBasedSettingsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSettingsToolStripMenuItem1;


	private: System::Windows::Forms::ToolStripMenuItem^  loadDefaultToolStripMenuItem;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CornerD;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CornerC;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  CornerB;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  CornerA;

	private: System::Windows::Forms::RadioButton^  ImageTopThird;
	private: System::Windows::Forms::RadioButton^  ImageBottomTwoThird;
	private: System::Windows::Forms::RadioButton^  ImageCustom;



	private: System::Windows::Forms::RadioButton^  ImageWhole;

	private: System::Windows::Forms::CheckBox^  DinamicBatchMonitor;

	private: System::Windows::Forms::CheckBox^  BatchProcess;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^		loadAdvancedSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^		LoadTimeBasedSettings;
	private: System::Windows::Forms::ToolStripMenuItem^		LoadImageSpecificSettings;
	private: System::Windows::Forms::OpenFileDialog^		VideoFilePath;
	private: System::Windows::Forms::FolderBrowserDialog^	InputDirPath;
	private: System::Windows::Forms::FolderBrowserDialog^	OutputDirPath;
	private: System::Windows::Forms::OpenFileDialog^		LoadSettings;
	private: System::Windows::Forms::ToolStripMenuItem^		ImagesDisplay;






	private: System::Windows::Forms::SaveFileDialog^  SaveStack;
	private: System::Windows::Forms::OpenFileDialog^  TimeSpecificSettings;
	private: System::Windows::Forms::OpenFileDialog^  ImageSpecificSettings;
private: System::Windows::Forms::ToolStripMenuItem^  saveAsImageSpecificSettingsToolStripMenuItem;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Label^  QualityControlDirShow;

private: System::Windows::Forms::Label^  OutputDirShow;

private: System::Windows::Forms::Label^  InputVedioShow;

private: System::Windows::Forms::Label^  InputDirShow;
private: System::Windows::Forms::FolderBrowserDialog^  QualityControlDir;















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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->newStackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ObjectLibraryOn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ObjectSatckOn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImagesDisplay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsTimeBasedSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsImageSpecificSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadSettingsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadDefaultToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadAdvancedSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadTimeBasedSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadImageSpecificSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenProject = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Main = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->QualityControlDirShow = (gcnew System::Windows::Forms::Label());
			this->OutputDirShow = (gcnew System::Windows::Forms::Label());
			this->InputVedioShow = (gcnew System::Windows::Forms::Label());
			this->InputDirShow = (gcnew System::Windows::Forms::Label());
			this->SelectRegion = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CornerD = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CornerC = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->CornerB = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->CornerA = (gcnew System::Windows::Forms::TextBox());
			this->ImageTopThird = (gcnew System::Windows::Forms::RadioButton());
			this->ImageBottomTwoThird = (gcnew System::Windows::Forms::RadioButton());
			this->ImageCustom = (gcnew System::Windows::Forms::RadioButton());
			this->ImageWhole = (gcnew System::Windows::Forms::RadioButton());
			this->Output = (gcnew System::Windows::Forms::GroupBox());
			this->DinamicBatchMonitor = (gcnew System::Windows::Forms::CheckBox());
			this->BatchProcess = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SamplePer100 = (gcnew System::Windows::Forms::TextBox());
			this->QualityControl = (gcnew System::Windows::Forms::CheckBox());
			this->OutputDirPathBtn = (gcnew System::Windows::Forms::Button());
			this->Input = (gcnew System::Windows::Forms::GroupBox());
			this->CaptureFromCam = (gcnew System::Windows::Forms::CheckBox());
			this->InputDirPathBtn = (gcnew System::Windows::Forms::Button());
			this->VideoFilePathBtn = (gcnew System::Windows::Forms::Button());
			this->VideoFilePath = (gcnew System::Windows::Forms::OpenFileDialog());
			this->InputDirPath = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->OutputDirPath = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->LoadSettings = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveStack = (gcnew System::Windows::Forms::SaveFileDialog());
			this->TimeSpecificSettings = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ImageSpecificSettings = (gcnew System::Windows::Forms::OpenFileDialog());
			this->QualityControlDir = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->menuStrip1->SuspendLayout();
			this->Main->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SelectRegion->SuspendLayout();
			this->Output->SuspendLayout();
			this->Input->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->newStackToolStripMenuItem, 
				this->viewToolStripMenuItem, this->saveToolStripMenuItem, this->loadSettingsToolStripMenuItem, this->loadAdvancedSettingsToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1008, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// newStackToolStripMenuItem
			// 
			this->newStackToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->newToolStripMenuItem, 
				this->closeToolStripMenuItem, this->closeToolStripMenuItem1});
			this->newStackToolStripMenuItem->Name = L"newStackToolStripMenuItem";
			this->newStackToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->newStackToolStripMenuItem->Text = L"Project";
			this->newStackToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newStackToolStripMenuItem_Click);
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->newToolStripMenuItem->Text = L"Open";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->closeToolStripMenuItem->Text = L"New";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem1
			// 
			this->closeToolStripMenuItem1->Name = L"closeToolStripMenuItem1";
			this->closeToolStripMenuItem1->Size = System::Drawing::Size(103, 22);
			this->closeToolStripMenuItem1->Text = L"Close";
			this->closeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::closeToolStripMenuItem1_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ObjectLibraryOn, 
				this->ObjectSatckOn, this->ImagesDisplay});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// ObjectLibraryOn
			// 
			this->ObjectLibraryOn->CheckOnClick = true;
			this->ObjectLibraryOn->Name = L"ObjectLibraryOn";
			this->ObjectLibraryOn->Size = System::Drawing::Size(112, 22);
			this->ObjectLibraryOn->Text = L"Library";
			this->ObjectLibraryOn->Click += gcnew System::EventHandler(this, &Form1::ShowLibrary);
			// 
			// ObjectSatckOn
			// 
			this->ObjectSatckOn->CheckOnClick = true;
			this->ObjectSatckOn->Name = L"ObjectSatckOn";
			this->ObjectSatckOn->Size = System::Drawing::Size(112, 22);
			this->ObjectSatckOn->Text = L"Stack";
			this->ObjectSatckOn->Click += gcnew System::EventHandler(this, &Form1::ShowStack);
			// 
			// ImagesDisplay
			// 
			this->ImagesDisplay->CheckOnClick = true;
			this->ImagesDisplay->Name = L"ImagesDisplay";
			this->ImagesDisplay->Size = System::Drawing::Size(112, 22);
			this->ImagesDisplay->Text = L"Display";
			this->ImagesDisplay->Click += gcnew System::EventHandler(this, &Form1::displayToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->saveAsToolStripMenuItem, 
				this->saveAsTimeBasedSettingsToolStripMenuItem, this->saveAsImageSpecificSettingsToolStripMenuItem});
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->saveToolStripMenuItem->Text = L"Save Stack";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(225, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// saveAsTimeBasedSettingsToolStripMenuItem
			// 
			this->saveAsTimeBasedSettingsToolStripMenuItem->Name = L"saveAsTimeBasedSettingsToolStripMenuItem";
			this->saveAsTimeBasedSettingsToolStripMenuItem->Size = System::Drawing::Size(225, 22);
			this->saveAsTimeBasedSettingsToolStripMenuItem->Text = L"Save As Time Based Stack";
			this->saveAsTimeBasedSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsTimeBasedSettingsToolStripMenuItem_Click);
			// 
			// saveAsImageSpecificSettingsToolStripMenuItem
			// 
			this->saveAsImageSpecificSettingsToolStripMenuItem->Name = L"saveAsImageSpecificSettingsToolStripMenuItem";
			this->saveAsImageSpecificSettingsToolStripMenuItem->Size = System::Drawing::Size(225, 22);
			this->saveAsImageSpecificSettingsToolStripMenuItem->Text = L"Save As Image Specific Stack";
			this->saveAsImageSpecificSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsImageSpecificSettingsToolStripMenuItem_Click);
			// 
			// loadSettingsToolStripMenuItem
			// 
			this->loadSettingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->loadSettingsToolStripMenuItem1, 
				this->loadDefaultToolStripMenuItem});
			this->loadSettingsToolStripMenuItem->Name = L"loadSettingsToolStripMenuItem";
			this->loadSettingsToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->loadSettingsToolStripMenuItem->Text = L"Load Stack";
			// 
			// loadSettingsToolStripMenuItem1
			// 
			this->loadSettingsToolStripMenuItem1->Name = L"loadSettingsToolStripMenuItem1";
			this->loadSettingsToolStripMenuItem1->Size = System::Drawing::Size(112, 22);
			this->loadSettingsToolStripMenuItem1->Text = L"Load";
			this->loadSettingsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::loadSettingsToolStripMenuItem1_Click);
			// 
			// loadDefaultToolStripMenuItem
			// 
			this->loadDefaultToolStripMenuItem->Name = L"loadDefaultToolStripMenuItem";
			this->loadDefaultToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->loadDefaultToolStripMenuItem->Text = L"Default";
			this->loadDefaultToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadDefaultToolStripMenuItem_Click);
			// 
			// loadAdvancedSettingsToolStripMenuItem
			// 
			this->loadAdvancedSettingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->LoadTimeBasedSettings, 
				this->LoadImageSpecificSettings});
			this->loadAdvancedSettingsToolStripMenuItem->Name = L"loadAdvancedSettingsToolStripMenuItem";
			this->loadAdvancedSettingsToolStripMenuItem->Size = System::Drawing::Size(137, 20);
			this->loadAdvancedSettingsToolStripMenuItem->Text = L"Load Advanced Stacks";
			// 
			// LoadTimeBasedSettings
			// 
			this->LoadTimeBasedSettings->CheckOnClick = true;
			this->LoadTimeBasedSettings->Name = L"LoadTimeBasedSettings";
			this->LoadTimeBasedSettings->Size = System::Drawing::Size(211, 22);
			this->LoadTimeBasedSettings->Text = L"Load Time Specific Stack";
			this->LoadTimeBasedSettings->Click += gcnew System::EventHandler(this, &Form1::loadTimeBasedSettingsToolStripMenuItem_Click);
			// 
			// LoadImageSpecificSettings
			// 
			this->LoadImageSpecificSettings->CheckOnClick = true;
			this->LoadImageSpecificSettings->Name = L"LoadImageSpecificSettings";
			this->LoadImageSpecificSettings->Size = System::Drawing::Size(211, 22);
			this->LoadImageSpecificSettings->Text = L"Load Image Specific Stack";
			this->LoadImageSpecificSettings->Click += gcnew System::EventHandler(this, &Form1::LoadImageSpecificSettings_Click);
			// 
			// OpenProject
			// 
			this->OpenProject->Filter = L"project files (*.pip)|*.pip";
			// 
			// Main
			// 
			this->Main->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Main->Controls->Add(this->panel1);
			this->Main->Controls->Add(this->SelectRegion);
			this->Main->Controls->Add(this->Output);
			this->Main->Controls->Add(this->Input);
			this->Main->Location = System::Drawing::Point(0, 25);
			this->Main->Name = L"Main";
			this->Main->Size = System::Drawing::Size(540, 230);
			this->Main->TabIndex = 4;
			this->Main->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Main_Paint);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->QualityControlDirShow);
			this->panel1->Controls->Add(this->OutputDirShow);
			this->panel1->Controls->Add(this->InputVedioShow);
			this->panel1->Controls->Add(this->InputDirShow);
			this->panel1->Location = System::Drawing::Point(11, 146);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(522, 77);
			this->panel1->TabIndex = 3;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// QualityControlDirShow
			// 
			this->QualityControlDirShow->AutoSize = true;
			this->QualityControlDirShow->Location = System::Drawing::Point(6, 54);
			this->QualityControlDirShow->Name = L"QualityControlDirShow";
			this->QualityControlDirShow->Size = System::Drawing::Size(120, 13);
			this->QualityControlDirShow->TabIndex = 3;
			this->QualityControlDirShow->Text = L"Quality Control Directory";
			// 
			// OutputDirShow
			// 
			this->OutputDirShow->AutoSize = true;
			this->OutputDirShow->Location = System::Drawing::Point(6, 37);
			this->OutputDirShow->Name = L"OutputDirShow";
			this->OutputDirShow->Size = System::Drawing::Size(84, 13);
			this->OutputDirShow->TabIndex = 2;
			this->OutputDirShow->Text = L"Output Directory";
			// 
			// InputVedioShow
			// 
			this->InputVedioShow->AutoSize = true;
			this->InputVedioShow->Location = System::Drawing::Point(6, 20);
			this->InputVedioShow->Name = L"InputVedioShow";
			this->InputVedioShow->Size = System::Drawing::Size(61, 13);
			this->InputVedioShow->TabIndex = 1;
			this->InputVedioShow->Text = L"Input Video";
			// 
			// InputDirShow
			// 
			this->InputDirShow->AutoSize = true;
			this->InputDirShow->Location = System::Drawing::Point(6, 4);
			this->InputDirShow->Name = L"InputDirShow";
			this->InputDirShow->Size = System::Drawing::Size(76, 13);
			this->InputDirShow->TabIndex = 0;
			this->InputDirShow->Text = L"Input Directory";
			// 
			// SelectRegion
			// 
			this->SelectRegion->Controls->Add(this->label5);
			this->SelectRegion->Controls->Add(this->CornerD);
			this->SelectRegion->Controls->Add(this->label4);
			this->SelectRegion->Controls->Add(this->CornerC);
			this->SelectRegion->Controls->Add(this->label3);
			this->SelectRegion->Controls->Add(this->CornerB);
			this->SelectRegion->Controls->Add(this->label2);
			this->SelectRegion->Controls->Add(this->CornerA);
			this->SelectRegion->Controls->Add(this->ImageTopThird);
			this->SelectRegion->Controls->Add(this->ImageBottomTwoThird);
			this->SelectRegion->Controls->Add(this->ImageCustom);
			this->SelectRegion->Controls->Add(this->ImageWhole);
			this->SelectRegion->Location = System::Drawing::Point(303, 13);
			this->SelectRegion->Name = L"SelectRegion";
			this->SelectRegion->Size = System::Drawing::Size(230, 127);
			this->SelectRegion->TabIndex = 2;
			this->SelectRegion->TabStop = false;
			this->SelectRegion->Text = L"Image Selection Illsutration";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(120, 99);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"D";
			// 
			// CornerD
			// 
			this->CornerD->Location = System::Drawing::Point(137, 96);
			this->CornerD->Name = L"CornerD";
			this->CornerD->Size = System::Drawing::Size(74, 20);
			this->CornerD->TabIndex = 10;
			this->CornerD->TextChanged += gcnew System::EventHandler(this, &Form1::CornerD_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(120, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"C";
			// 
			// CornerC
			// 
			this->CornerC->Location = System::Drawing::Point(137, 70);
			this->CornerC->Name = L"CornerC";
			this->CornerC->Size = System::Drawing::Size(74, 20);
			this->CornerC->TabIndex = 8;
			this->CornerC->TextChanged += gcnew System::EventHandler(this, &Form1::CornerC_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(120, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"B";
			// 
			// CornerB
			// 
			this->CornerB->Location = System::Drawing::Point(137, 44);
			this->CornerB->Name = L"CornerB";
			this->CornerB->Size = System::Drawing::Size(74, 20);
			this->CornerB->TabIndex = 6;
			this->CornerB->TextChanged += gcnew System::EventHandler(this, &Form1::CornerB_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(120, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"A";
			// 
			// CornerA
			// 
			this->CornerA->Location = System::Drawing::Point(137, 18);
			this->CornerA->Name = L"CornerA";
			this->CornerA->Size = System::Drawing::Size(74, 20);
			this->CornerA->TabIndex = 4;
			this->CornerA->TextChanged += gcnew System::EventHandler(this, &Form1::CornerA_TextChanged);
			// 
			// ImageTopThird
			// 
			this->ImageTopThird->AutoSize = true;
			this->ImageTopThird->Location = System::Drawing::Point(7, 47);
			this->ImageTopThird->Name = L"ImageTopThird";
			this->ImageTopThird->Size = System::Drawing::Size(71, 17);
			this->ImageTopThird->TabIndex = 3;
			this->ImageTopThird->Text = L"Top Third";
			this->ImageTopThird->UseVisualStyleBackColor = true;
			this->ImageTopThird->CheckedChanged += gcnew System::EventHandler(this, &Form1::ImageTopThird_CheckedChanged);
			// 
			// ImageBottomTwoThird
			// 
			this->ImageBottomTwoThird->AutoSize = true;
			this->ImageBottomTwoThird->Location = System::Drawing::Point(7, 73);
			this->ImageBottomTwoThird->Name = L"ImageBottomTwoThird";
			this->ImageBottomTwoThird->Size = System::Drawing::Size(106, 17);
			this->ImageBottomTwoThird->TabIndex = 2;
			this->ImageBottomTwoThird->Text = L"BottomTwo Third";
			this->ImageBottomTwoThird->UseVisualStyleBackColor = true;
			this->ImageBottomTwoThird->CheckedChanged += gcnew System::EventHandler(this, &Form1::ImageBottomTwoThird_CheckedChanged);
			// 
			// ImageCustom
			// 
			this->ImageCustom->AutoSize = true;
			this->ImageCustom->Location = System::Drawing::Point(7, 99);
			this->ImageCustom->Name = L"ImageCustom";
			this->ImageCustom->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ImageCustom->Size = System::Drawing::Size(60, 17);
			this->ImageCustom->TabIndex = 1;
			this->ImageCustom->Text = L"Custom";
			this->ImageCustom->UseVisualStyleBackColor = true;
			this->ImageCustom->CheckedChanged += gcnew System::EventHandler(this, &Form1::ImageCustom_CheckedChanged);
			// 
			// ImageWhole
			// 
			this->ImageWhole->AutoSize = true;
			this->ImageWhole->Location = System::Drawing::Point(7, 21);
			this->ImageWhole->Name = L"ImageWhole";
			this->ImageWhole->Size = System::Drawing::Size(56, 17);
			this->ImageWhole->TabIndex = 0;
			this->ImageWhole->Text = L"Whole";
			this->ImageWhole->UseVisualStyleBackColor = true;
			this->ImageWhole->CheckedChanged += gcnew System::EventHandler(this, &Form1::ImageWhole_CheckedChanged);
			// 
			// Output
			// 
			this->Output->Controls->Add(this->DinamicBatchMonitor);
			this->Output->Controls->Add(this->BatchProcess);
			this->Output->Controls->Add(this->label1);
			this->Output->Controls->Add(this->SamplePer100);
			this->Output->Controls->Add(this->QualityControl);
			this->Output->Controls->Add(this->OutputDirPathBtn);
			this->Output->Location = System::Drawing::Point(115, 13);
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(182, 127);
			this->Output->TabIndex = 1;
			this->Output->TabStop = false;
			this->Output->Text = L"Output";
			// 
			// DinamicBatchMonitor
			// 
			this->DinamicBatchMonitor->AutoSize = true;
			this->DinamicBatchMonitor->Location = System::Drawing::Point(6, 103);
			this->DinamicBatchMonitor->Name = L"DinamicBatchMonitor";
			this->DinamicBatchMonitor->Size = System::Drawing::Size(133, 17);
			this->DinamicBatchMonitor->TabIndex = 5;
			this->DinamicBatchMonitor->Text = L"Dinamic Batch Monitor";
			this->DinamicBatchMonitor->UseVisualStyleBackColor = true;
			this->DinamicBatchMonitor->CheckedChanged += gcnew System::EventHandler(this, &Form1::DinamicBatchMonitor_CheckedChanged);
			// 
			// BatchProcess
			// 
			this->BatchProcess->AutoSize = true;
			this->BatchProcess->Location = System::Drawing::Point(6, 80);
			this->BatchProcess->Name = L"BatchProcess";
			this->BatchProcess->Size = System::Drawing::Size(95, 17);
			this->BatchProcess->TabIndex = 4;
			this->BatchProcess->Text = L"Batch Process";
			this->BatchProcess->UseVisualStyleBackColor = true;
			this->BatchProcess->CheckedChanged += gcnew System::EventHandler(this, &Form1::BatchProcess_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Sample/100";
			// 
			// SamplePer100
			// 
			this->SamplePer100->Location = System::Drawing::Point(77, 49);
			this->SamplePer100->Name = L"SamplePer100";
			this->SamplePer100->Size = System::Drawing::Size(94, 20);
			this->SamplePer100->TabIndex = 2;
			this->SamplePer100->TextChanged += gcnew System::EventHandler(this, &Form1::SamplePer100_TextChanged);
			// 
			// QualityControl
			// 
			this->QualityControl->AutoSize = true;
			this->QualityControl->Location = System::Drawing::Point(77, 23);
			this->QualityControl->Name = L"QualityControl";
			this->QualityControl->Size = System::Drawing::Size(94, 17);
			this->QualityControl->TabIndex = 1;
			this->QualityControl->Text = L"Quality Control";
			this->QualityControl->UseVisualStyleBackColor = true;
			this->QualityControl->CheckedChanged += gcnew System::EventHandler(this, &Form1::QualityControl_CheckedChanged);
			// 
			// OutputDirPathBtn
			// 
			this->OutputDirPathBtn->BackColor = System::Drawing::SystemColors::Control;
			this->OutputDirPathBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->OutputDirPathBtn->Location = System::Drawing::Point(6, 19);
			this->OutputDirPathBtn->Name = L"OutputDirPathBtn";
			this->OutputDirPathBtn->Size = System::Drawing::Size(65, 23);
			this->OutputDirPathBtn->TabIndex = 0;
			this->OutputDirPathBtn->Text = L"Directory";
			this->OutputDirPathBtn->UseVisualStyleBackColor = false;
			this->OutputDirPathBtn->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Input
			// 
			this->Input->Controls->Add(this->CaptureFromCam);
			this->Input->Controls->Add(this->InputDirPathBtn);
			this->Input->Controls->Add(this->VideoFilePathBtn);
			this->Input->Location = System::Drawing::Point(11, 13);
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(89, 127);
			this->Input->TabIndex = 0;
			this->Input->TabStop = false;
			this->Input->Text = L"Input";
			// 
			// CaptureFromCam
			// 
			this->CaptureFromCam->AutoSize = true;
			this->CaptureFromCam->Enabled = false;
			this->CaptureFromCam->Location = System::Drawing::Point(6, 78);
			this->CaptureFromCam->Name = L"CaptureFromCam";
			this->CaptureFromCam->Size = System::Drawing::Size(62, 17);
			this->CaptureFromCam->TabIndex = 2;
			this->CaptureFromCam->Text = L"Camera";
			this->CaptureFromCam->UseVisualStyleBackColor = true;
			this->CaptureFromCam->CheckedChanged += gcnew System::EventHandler(this, &Form1::CaptureFromCam_CheckedChanged);
			// 
			// InputDirPathBtn
			// 
			this->InputDirPathBtn->Location = System::Drawing::Point(6, 49);
			this->InputDirPathBtn->Name = L"InputDirPathBtn";
			this->InputDirPathBtn->Size = System::Drawing::Size(75, 23);
			this->InputDirPathBtn->TabIndex = 1;
			this->InputDirPathBtn->Text = L"Directory";
			this->InputDirPathBtn->UseVisualStyleBackColor = true;
			this->InputDirPathBtn->Click += gcnew System::EventHandler(this, &Form1::InputDirPathBtn_Click);
			// 
			// VideoFilePathBtn
			// 
			this->VideoFilePathBtn->BackColor = System::Drawing::SystemColors::Control;
			this->VideoFilePathBtn->Enabled = false;
			this->VideoFilePathBtn->Location = System::Drawing::Point(6, 20);
			this->VideoFilePathBtn->Name = L"VideoFilePathBtn";
			this->VideoFilePathBtn->Size = System::Drawing::Size(75, 23);
			this->VideoFilePathBtn->TabIndex = 0;
			this->VideoFilePathBtn->Text = L"Video";
			this->VideoFilePathBtn->UseVisualStyleBackColor = false;
			this->VideoFilePathBtn->Click += gcnew System::EventHandler(this, &Form1::VideoFilePathBtn_Click);
			// 
			// VideoFilePath
			// 
			this->VideoFilePath->FileName = L"openFileDialog1";
			// 
			// LoadSettings
			// 
			this->LoadSettings->Filter = L"settings files (*.sip)|*.sip";
			// 
			// SaveStack
			// 
			this->SaveStack->Filter = L"settings files (*.sip)|*.sip";
			// 
			// TimeSpecificSettings
			// 
			this->TimeSpecificSettings->FileName = L"openFileDialog1";
			this->TimeSpecificSettings->Filter = L"settings files (*.sip)|*.sip";
			this->TimeSpecificSettings->Multiselect = true;
			// 
			// ImageSpecificSettings
			// 
			this->ImageSpecificSettings->FileName = L"openFileDialog1";
			this->ImageSpecificSettings->Filter = L"settings files (*.sip)|*.sip";
			this->ImageSpecificSettings->Multiselect = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->Main);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Digital Image Batch Analyzer-V2";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->Main->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->SelectRegion->ResumeLayout(false);
			this->SelectRegion->PerformLayout();
			this->Output->ResumeLayout(false);
			this->Output->PerformLayout();
			this->Input->ResumeLayout(false);
			this->Input->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/***********************************************************************************************/
//Function to show Library Window
/***********************************************************************************************/

private: System::Void ShowLibrary(System::Object^  sender, System::EventArgs^  e) {
try{
		if(this->ObjectLibraryOn->Checked){				 
				if(!IPOLibrary||!IPOLibrary->Created){
					IPOLibrary= (gcnew Library);
					IPOLibrary->IPOStack=this->IPOStack;
					IPOLibrary->MdiParent = this;
					IPOLibrary->SettingFilesHandler=this->SettingFilesHandler;
					IPOLibrary->Show();
				}
		}
this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "ShowLibrary");
	//LogMessage("","");
}
}
/***********************************************************************************************/
//Form Load function
/***********************************************************************************************/
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

try{					
					
					DisableinitComponents();
					ImShow=gcnew ImageShow;
					ImShow->IPOHandler=IPOHandler;
					ImShow->MdiParent = this;
					IPOHandler = gcnew IPOHandling;
					UpdateForm(NoProject);
					

} catch ( Exception^ ex ) {
	ThrowError(ex, "Form1load");
	//LogMessage("","");
}
}
/***********************************************************************************************/
//Function to show Stack Window
/***********************************************************************************************/
private: System::Void ShowStack(System::Object^  sender, System::EventArgs^  e) {
try{
		if(ObjectSatckOn->Checked){
			if(!IPOStack||!IPOStack->Created){
				IPOStack= (gcnew IPO_Stack);
	 			IPOStack->MdiParent = this;
	 			IPOStack->SettingFilesHandler=this->SettingFilesHandler;
	 			IPOStack->ImShow=this->ImShow;
	 				if(this->SettingFilesHandler->isIPOLibraryAvilable)
						IPOLibrary->IPOStack=IPOStack;
				IPOStack->IPOHandler=this->IPOHandler;
				IPOStack->Show();
			}
		}
this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "SnowStack");
	//LogMessage("","");
}
}
			 
/***********************************************************************************************/
//Function to Log Status Messages
/***********************************************************************************************/
public:  void LogStatus(String^ message, String^ ID)
{
	try{
	File::AppendAllText(StatusLog, String::Concat(ID,message) );
	} catch ( Exception^ ex ) {
	ThrowError(ex, "LogStatus");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to ShowMessage window
/***********************************************************************************************/
	
public:System::Windows::Forms::DialogResult ShowMessageBox(String^ message, String^ caption)
{ // Initializes the variables to pass to the MessageBox::Show method.
 
try{
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result;
		// Displays the MessageBox.
        result = MessageBox::Show( this, message, caption, buttons );
		return result;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ShowMessageBox");
	//LogMessage("","");
	
}
}
/***********************************************************************************************/
//
/***********************************************************************************************/
private: System::Void newStackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
/***********************************************************************************************/
//Function to open a project
/***********************************************************************************************/
private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	System::Windows::Forms::DialogResult result=this->OpenProject->ShowDialog();			
	if(result == ::DialogResult::OK){
			this->PathCWD=Path::GetDirectoryName(	OpenProject->FileName);
			
			this->ProjectStart(Path::GetFileName(OpenProject->FileName));
			this->LoadConfiguration();
			this->displayToolStripMenuItem_Click(sender,e);
			this->ShowLibrary(sender,e);
			this->ShowStack(sender,e);
	}	

} catch ( Exception^ ex ) {
	ThrowError(ex, "newprojectopen");
	//LogMessage("","");
}	
}
/***********************************************************************************************/
//Function Start project
/***********************************************************************************************/
public: void ProjectStart(String^ ProjectName){
try{
		//My initializations
		//
	   
		String ^ SettingFileName=Path::ChangeExtension(ProjectName,SettingExtension);
		StatusLog= Path::Combine(PathCWD,"Logs.txt");
		GStatusLog=(char*)(void*)Marshal::StringToHGlobalAnsi(StatusLog);
		if ( File::Exists( StatusLog ) ){
			  File::Delete( StatusLog );
		}
		// 			
		SettingFilesHandler=gcnew SettingFiles(StatusLog,Path::Combine(PathCWD,ProjectName),Path::Combine(PathCWD,SettingFileName));
		UpdateForm(ProjectLoaded);
		this->Text=String::Concat("Digital Image Batch Analyzer - ",ProjectName);
//		 IPOHandler->HandleDatabase();
} catch ( Exception^ ex ) {
	ThrowError(ex, "ProjectStart");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to start a new project
/***********************************************************************************************/
	
private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	NewProjectForm^ NewProject = gcnew NewProjectForm;
	NewProject->ShowDialog();
	if(!NewProject->IsDisposed&&NewProject->IsSaved){
		this->PathCWD=NewProject->PathCWD;

		this->ProjectStart(NewProject->ProjectName);
		this->displayToolStripMenuItem_Click(sender,e);
		this->ObjectLibraryOn->Checked=true;
		this->ObjectSatckOn->Checked=true;
		this->ImagesDisplay->Checked=true;
		this->displayToolStripMenuItem_Click(sender,e);
		this->ShowLibrary(sender,e);
		this->ShowStack(sender,e);
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "StartNewproject");
	//LogMessage("","");
}

}
/***********************************************************************************************/
//Function to Update the form elements
/***********************************************************************************************/

public: void UpdateForm(GUICommand command){
try{	

	switch(command){
	case NoProject: 
		Main->Enabled=false;
		viewToolStripMenuItem->Enabled=false;
		saveToolStripMenuItem->Enabled=false;
		loadSettingsToolStripMenuItem->Enabled=false;
		loadAdvancedSettingsToolStripMenuItem->Enabled=false;
		break;
	case ProjectLoaded:
		viewToolStripMenuItem->Enabled=true;
		Main->Enabled=true;
		saveToolStripMenuItem->Enabled=true;
		loadSettingsToolStripMenuItem->Enabled=true;
		loadAdvancedSettingsToolStripMenuItem->Enabled=true;
		break;
	case ShowLeftPic:
			
		 if(ImShow&&ImShow->Created)
				{
			 Bitmap^ Im=IPOHandler->SampleInput(true);
			  if(Im){
			//Im=IPOHandler->TopThird(Im);
			 ImShow->ShowImage(Im);
			  }
	
			}
		 break;
	case ShowRightPic:
		
		 if(ImShow&&ImShow->Created)
				{
			 Bitmap^ Im=IPOHandler->SampleInput(true);
			  if(Im){
			// Im=IPOHandler->BottomTwoThird(Im);
			 ImShow->ShowImage(Im);
			  }
	
			}
		 break;
case ShowCustomPic:
		
		 if(ImShow&&ImShow->Created)
				{
			 Bitmap^ Im=IPOHandler->SampleInput(true);
			 if(Im){
			// Im=IPOHandler->CustomPortion(Im);
			 ImShow->ShowImage(Im);
			 }
	
			}
		 break;

case	ShowWholePic:
	
	if(ImShow&&ImShow->Created)
				{
			 Bitmap^ Im=IPOHandler->SampleInput(true);
			 if(Im){
			 
			 ImShow->ShowImage(Im);
			 }
	
			}
case	PathShows:

		InputDirShow->Text=				"Input Directory :" + IPOHandler->InputDirPath;
		OutputDirShow->Text=			"Output Directory :" + IPOHandler->OutputDirPath;	
		QualityControlDirShow->Text=	"Quality Control Directory :"+ IPOHandler->QualityControlDir;	
		InputVedioShow->Text=			"Input Video :" + IPOHandler->VideoFilePath;
		break;
	default:
		break;
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateForm");
	//LogMessage("","");
}
}

private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void Main_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }

/***********************************************************************************************/
//Function to close the main form
/***********************************************************************************************/

private: System::Void closeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
try{
			 UpdateForm(NoProject);
} catch ( Exception^ ex ) {
	ThrowError(ex, "Closemainform");
	//LogMessage("","");
}
		 }
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
/***********************************************************************************************/
//Function to set the output path
/***********************************************************************************************/

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

try{		System::Windows::Forms::DialogResult result=this->OutputDirPath->ShowDialog();			
		if(result == ::DialogResult::OK){//pressed ok button
		this->SaveConfiguration();
		}	
} catch ( Exception^ ex ) {
	ThrowError(ex, "Settheoutputpath");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to Load time based settings
/***********************************************************************************************/
private: System::Void loadTimeBasedSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
			if(LoadTimeBasedSettings->Checked){
				System::Windows::Forms::DialogResult result=this->TimeSpecificSettings->ShowDialog();			
				if(result == ::DialogResult::OK){//pressed ok button
				LoadTimeBasedSettings->Checked=true;
				IPOHandler->TimeSpecificSettingFiles = TimeSpecificSettings->FileNames;
				}
				else
				LoadTimeBasedSettings->Checked=false;
	}
this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "LoadtimebasedSettings");
	//LogMessage("","");
}
}

private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
/***********************************************************************************************/
//Function to save the project configuraion
/***********************************************************************************************/

private: void SaveConfiguration(){
try{

	if(!LoadConfigurationMutx){
		this->SettingFilesHandler->UpdateProjectSection(Enum_ObjectLibraryOn,String::Format("{0}",(int)ObjectLibraryOn->Checked));
		this->SettingFilesHandler->UpdateProjectSection(Enum_ObjectSatckOn,String::Format("{0}",(int)ObjectSatckOn->Checked));
		this->SettingFilesHandler->UpdateProjectSection(Enum_VideoFilePath,VideoFilePath->FileName);
		IPOHandler->VideoFilePath=VideoFilePath->FileName;
		this->SettingFilesHandler->UpdateProjectSection(Enum_InputDirPath,InputDirPath->SelectedPath);
		IPOHandler->InputDirPath = InputDirPath->SelectedPath;
		this->SettingFilesHandler->UpdateProjectSection(Enum_CaptureFromCam, String::Format("{0}",(int)CaptureFromCam->Checked));
		IPOHandler->CaptureFromCam =CaptureFromCam->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_OutputDirPath,OutputDirPath->SelectedPath);
		IPOHandler->OutputDirPath =OutputDirPath->SelectedPath;
		this->SettingFilesHandler->UpdateProjectSection(Enum_QualityControl,String::Format("{0}",(int)QualityControl->Checked));
		IPOHandler->OutputDirPath =OutputDirPath->SelectedPath;
		{
		this->SettingFilesHandler->UpdateProjectSection(Enum_SamplePer100,SamplePer100->Text);
		IPOHandler->QualityControl =QualityControl->Checked;
		Int32 Val;
		Int32::TryParse(SamplePer100->Text,Val);
		IPOHandler->SamplePer100 =Val;
		}
		this->SettingFilesHandler->UpdateProjectSection(Enum_CornerA, CornerA->Text);
			{
				array <String^>^ delimiter = {"(",",","("};
				array <String^>^ arr = CornerA->Text->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
					if(arr->Length==2){
						Int32 Val1,Val2;
						Int32::TryParse(arr[0],Val1);
						Int32::TryParse(arr[1],Val2);
						IPOHandler->CornerA = Point(Val1,Val2);
					}
			}
		this->SettingFilesHandler->UpdateProjectSection(Enum_CornerB, CornerB->Text);
		{
			array <String^>^ delimiter = {"(",",","("};
			array <String^>^ arr = CornerB->Text->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
				if(arr->Length==2){
					Int32 Val1,Val2;
					Int32::TryParse(arr[0],Val1);
					Int32::TryParse(arr[1],Val2);
					IPOHandler->CornerB = Point(Val1,Val2);
				}
		}
		this->SettingFilesHandler->UpdateProjectSection(Enum_CornerC, CornerC->Text);
		{
			array <String^>^ delimiter = {"(",",","("};
			array <String^>^ arr = CornerC->Text->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			if(arr->Length==2){
				Int32 Val1,Val2;
				Int32::TryParse(arr[0],Val1);
				Int32::TryParse(arr[1],Val2);
				IPOHandler->CornerC = Point(Val1,Val2);
			}
		}
		this->SettingFilesHandler->UpdateProjectSection(Enum_CornerD, CornerD->Text);
		{
			array <String^>^ delimiter = {"(",",","("};
			array <String^>^ arr = CornerD->Text->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			if(arr->Length==2){
				Int32 Val1,Val2;
				Int32::TryParse(arr[0],Val1);
				Int32::TryParse(arr[1],Val2);
				IPOHandler->CornerD = Point(Val1,Val2);
			}
		}
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImageWhole,String::Format("{0}",(int)ImageWhole->Checked));
		IPOHandler->ImageWhole = ImageWhole->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImageTopThird,String::Format("{0}",(int)ImageTopThird->Checked));
		IPOHandler->ImageTopThird = ImageTopThird->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImageBottomTwoThird,String::Format("{0}",(int)ImageBottomTwoThird->Checked));
		IPOHandler->ImageBottomTwoThird = ImageBottomTwoThird->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImageCustom,String::Format("{0}",(int)ImageCustom->Checked));
		IPOHandler->ImageCustom =ImageCustom->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_BatchProcess,String::Format("{0}",(int)BatchProcess->Checked));
		IPOHandler->BatchProcess =BatchProcess->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_DinamicBatchMonitor,String::Format("{0}",(int)DinamicBatchMonitor->Checked));
		IPOHandler->DinamicBatchMonitor = DinamicBatchMonitor->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_LoadTimeBasedSettings,String::Format("{0}",(int)LoadTimeBasedSettings->Checked));
		IPOHandler->LoadTimeBasedSettings = LoadTimeBasedSettings->Checked;
		
		if(IPOHandler->TimeSpecificSettingFiles&&IPOHandler->TimeSpecificSettingFiles->Length)
		this->SettingFilesHandler->UpdateProjectSection(Enum_TimeSpecificSettingFiles,String::Join(PROPERTYEND,IPOHandler->TimeSpecificSettingFiles));

		this->SettingFilesHandler->UpdateProjectSection(Enum_LoadImageSpecificSettings,String::Format("{0}",(int)LoadImageSpecificSettings->Checked));		
		IPOHandler->LoadImageSpecificSettings =LoadImageSpecificSettings->Checked;
		if(IPOHandler->ImageSpecificSettingFiles&&IPOHandler->ImageSpecificSettingFiles->Length)
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImageSpecificSettingFiles,String::Join(PROPERTYEND, IPOHandler->ImageSpecificSettingFiles));
		IPOHandler->ImagesDisplay=ImagesDisplay->Checked;
		this->SettingFilesHandler->UpdateProjectSection(Enum_ImagesDisplay,String::Format("{0}",(int)ImagesDisplay->Checked));
		IPOHandler->QualityControlDir=this->QualityControlDir->SelectedPath;
		this->SettingFilesHandler->UpdateProjectSection(Enum_QualityControlDir,IPOHandler->QualityControlDir);
		
		this->SettingFilesHandler->UpdateProjectFile();
		//Do all the required GUI updates
		UpdateForm(PathShows);
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "SaveConfiguration");
	//LogMessage("","");
}
}


/***********************************************************************************************/
//Function to load the project configuraion
/***********************************************************************************************/

private: void LoadConfiguration()
{

try{
	LoadConfigurationMutx=true;
	this->SettingFilesHandler->ReloadStackElements();
	String^ Value;
	Int32 Val;
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ObjectLibraryOn,Value)==Success){
		Int32::TryParse(Value,Val);
		ObjectLibraryOn->Checked= (bool)Val;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ObjectSatckOn,Value)==Success){
		Int32::TryParse(Value,Val);
		ObjectSatckOn->Checked=(bool)Val;//convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_VideoFilePath,Value)==Success){
		VideoFilePath->FileName=Value;
	}

	if(this->SettingFilesHandler->ReadProjectSection(Enum_InputDirPath,Value)==Success){
		InputDirPath->SelectedPath=Value;
	}

	if(this->SettingFilesHandler->ReadProjectSection(Enum_CaptureFromCam, Value)==Success){
		Int32::TryParse(Value,Val);
		CaptureFromCam->Checked=(bool)Val;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_OutputDirPath,Value)==Success){
		OutputDirPath->SelectedPath=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_QualityControlDir, Value)==Success){
		IPOHandler->QualityControlDir=Value;
		this->QualityControlDir->SelectedPath=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_QualityControl,Value)==Success){
		Int32::TryParse(Value,Val);
		QualityControl->Checked=Val;//boolvalue of Value
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_SamplePer100,Value)==Success){
		if(QualityControl->Checked)
			SamplePer100->Text=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_CornerA, Value)==Success){
		CornerA->Text=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_CornerB,Value)==Success){
		CornerB->Text=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_CornerC,Value)==Success){
		CornerC->Text=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_CornerD, Value)==Success){
		CornerD->Text=Value;
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImageWhole,Value)==Success){
		Int32::TryParse(Value,Val);
		ImageWhole->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImageTopThird,Value)==Success){
		Int32::TryParse(Value,Val);
		ImageTopThird->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImageBottomTwoThird,Value)==Success){
		Int32::TryParse(Value,Val);
		ImageBottomTwoThird->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImageCustom,Value)==Success){
		Int32::TryParse(Value,Val);
		ImageCustom->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_BatchProcess,Value)==Success){
		Int32::TryParse(Value,Val);
		BatchProcess->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_DinamicBatchMonitor,Value)==Success){
		Int32::TryParse(Value,Val);
		DinamicBatchMonitor->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_LoadTimeBasedSettings,Value)==Success){
		Int32::TryParse(Value,Val);
		LoadTimeBasedSettings->Checked=(bool)Val;//Convert value to bool
	}
	if(this->SettingFilesHandler->ReadProjectSection(Enum_LoadImageSpecificSettings,Value)==Success){
		Int32::TryParse(Value,Val);
		LoadImageSpecificSettings->Checked=(bool)Val;//Convert value to bool*/
	}

	if(this->SettingFilesHandler->ReadProjectSection(Enum_TimeSpecificSettingFiles,Value)==Success){
		array <String^>^ delimiter = {PROPERTYEND};
		IPOHandler->TimeSpecificSettingFiles= Value->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	}
	  
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImageSpecificSettingFiles,Value)==Success){
		array <String^>^ delimiter = {PROPERTYEND};
		IPOHandler->ImageSpecificSettingFiles= Value->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	 }
	if(this->SettingFilesHandler->ReadProjectSection(Enum_ImagesDisplay,Value)==Success){
		Int32::TryParse(Value,Val);
		ImagesDisplay->Checked=(bool)Val;//Convert value to bool*/
	}
	

	 LoadConfigurationMutx=false;
	 this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "LoadConfiguration");
	//LogMessage("","");
}

}

/***********************************************************************************************/
//Function Load the image specific settings
/***********************************************************************************************/

private: System::Void LoadImageSpecificSettings_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	if(LoadImageSpecificSettings->Checked){
			System::Windows::Forms::DialogResult result=this->ImageSpecificSettings->ShowDialog();			
			if(result == ::DialogResult::OK)//pressed ok button
				{
				 IPOHandler->ImageSpecificSettingFiles = ImageSpecificSettings->FileNames;
				}
			else
				LoadImageSpecificSettings->Checked=false;
	}

	this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "Loadtimespecificsettings");
	//LogMessage("","");
}
	}
/***********************************************************************************************/
//Function to get the video file path
/***********************************************************************************************/

private: System::Void VideoFilePathBtn_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	System::Windows::Forms::DialogResult result=this->VideoFilePath->ShowDialog();			
	if(result == ::DialogResult::OK)//pressed ok button
				{
				 InputDirPath->SelectedPath="";
				 CaptureFromCam->Checked=false;
				 this->SaveConfiguration();
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "VideoFilePath");
	//LogMessage("","");
}
			
	}

/***********************************************************************************************/
//Function to select input directory path
/***********************************************************************************************/

private: System::Void InputDirPathBtn_Click(System::Object^  sender, System::EventArgs^  e) {
try{
System::Windows::Forms::DialogResult result=InputDirPath->ShowDialog();
			if(result == ::DialogResult::OK)//pressed ok button
				{
				 VideoFilePath->FileName="";
				 CaptureFromCam->Checked=false;
				 this->SaveConfiguration();
				}	
} catch ( Exception^ ex ) {
	ThrowError(ex, "InputDirPath");
	//LogMessage("","");
}			
		 }
/***********************************************************************************************/
//Function to select camera input
/***********************************************************************************************/

private: System::Void CaptureFromCam_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 VideoFilePath->FileName="";
			 InputDirPath->SelectedPath="";
			 this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to switch on batch image processing
/***********************************************************************************************/

private: System::Void BatchProcess_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 this->SaveConfiguration();
		 }
/***********************************************************************************************/
//Function to switch on quality controll monitoring
/***********************************************************************************************/

private: System::Void QualityControl_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
	if(QualityControl->Checked&&!LoadConfigurationMutx)
	{
		this->QualityControlDir->SelectedPath=IPOHandler->QualityControlDir;
		System::Windows::Forms::DialogResult result=this->QualityControlDir->ShowDialog();			
		if(result == ::DialogResult::OK&&this->QualityControlDir->SelectedPath&&this->QualityControlDir->SelectedPath!=""){//pressed ok button
		
			IPOHandler->QualityControlDir=this->QualityControlDir->SelectedPath;
			this->SaveConfiguration();
			SamplePer100->Enabled=true;
			SamplePer100->Text="1";
		}
		else{
			QualityControl->Checked=false;
			SamplePer100->Enabled=false;
		}

			
	}
	else
		SamplePer100->Enabled=false;

} catch ( Exception^ ex ) {
	ThrowError(ex, "QualityControl_CheckedChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to set quality control number
/***********************************************************************************************/

private: System::Void SamplePer100_TextChanged(System::Object^  sender, System::EventArgs^  e) {
try{
		 if(QualityControl->Checked)
		 {
			this->SaveConfiguration();
		 }else
		 {
			ShowMessageBox("Check QualityControl First", "No QualityControl");
		 }
} catch ( Exception^ ex ) {
	ThrowError(ex, "SamplePer100_TextChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to Switch on dinamic batch monitor
/***********************************************************************************************/

private: System::Void DinamicBatchMonitor_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
 this->SaveConfiguration();		
 } catch ( Exception^ ex ) {
	ThrowError(ex, "DinamicBatchMonitor_CheckedChanged");
	//LogMessage("","");
}

		 }
/***********************************************************************************************/
//Function to select whole image for processing
/***********************************************************************************************/

private: System::Void ImageWhole_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			 if(ImageWhole->Checked)
			 UpdateForm(ShowWholePic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageWhole_CheckedChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to select image half proces portion sing
/***********************************************************************************************/

private: System::Void ImageTopThird_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

try{
		this->SaveConfiguration();
		if(ImageTopThird->Checked)
		UpdateForm(ShowLeftPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageTopThird_CheckedChanged");
	//LogMessage("","");
}

		 }

/***********************************************************************************************/
//Function to select image right half for processing
/***********************************************************************************************/

private: System::Void ImageBottomTwoThird_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			 if(ImageBottomTwoThird->Checked)
			 UpdateForm(ShowRightPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageBottomTwoThird_CheckedChanged");
	//LogMessage("","");
}

		 }

/***********************************************************************************************/
//Function to select custom portion of image for processing
/***********************************************************************************************/
private: System::Void ImageCustom_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			 if(ImageCustom->Checked)
			 {
				 CornerA->Enabled=true;
				 CornerB->Enabled=true;
				 CornerC->Enabled=true;
				 CornerD->Enabled=true;

			 }
			 else{
				 CornerA->Enabled=false;
				 CornerB->Enabled=false;
				 CornerC->Enabled=false;
				 CornerD->Enabled=false;
			 }
			 if(ImageCustom->Checked)
			 UpdateForm(ShowCustomPic);

} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageCustom_CheckedChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to select corner A
/***********************************************************************************************/
private: System::Void CornerA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			  UpdateForm(ShowCustomPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "CornerA_TextChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to select cornerB
/***********************************************************************************************/
private: System::Void CornerB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			  UpdateForm(ShowCustomPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "CornerB_TextChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to select cornerC
/***********************************************************************************************/
private: System::Void CornerC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			  UpdateForm(ShowCustomPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "CornerC_TextChanged");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to select CornerD
/***********************************************************************************************/
private: System::Void CornerD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
try{
			 this->SaveConfiguration();
			  UpdateForm(ShowCustomPic);
} catch ( Exception^ ex ) {
	ThrowError(ex, "CornerD_TextChanged");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to disable components while app initialization
/***********************************************************************************************/
private: void DisableinitComponents()
		 {
try{
				 SamplePer100->Enabled=false;
				 CornerA->Enabled=false;
				 CornerB->Enabled=false;
				 CornerC->Enabled=false;
				 CornerD->Enabled=false;
} catch ( Exception^ ex ) {
	ThrowError(ex, "DisableinitComponents");
	//LogMessage("","");
}
		 }

/***********************************************************************************************/
//Function to show the Preview window
/***********************************************************************************************/
private: System::Void displayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	if(ImagesDisplay->Checked){
			 if(!ImShow||!ImShow->Created)
				{
				ImShow=gcnew ImageShow;
				ImShow->IPOHandler=IPOHandler;
				ImShow->MdiParent = this;
				ImShow->Show();
				}
	}
	this->SaveConfiguration();
} catch ( Exception^ ex ) {
	ThrowError(ex, "displayToolStripMenuItem_Click");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to save as stack
/***********************************************************************************************/
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

try{
			 System::Windows::Forms::DialogResult result=this->SaveStack->ShowDialog();			

			if(result == ::DialogResult::OK)
			{
				File::Copy(SettingFilesHandler->StackFilename,SaveStack->FileName,true);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "saveAsToolStripMenuItem_Click");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to save default stack
/***********************************************************************************************/
private: System::Void saveAsDefaultSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{		
	/*	
	String^ path=	 Path::GetDirectoryName(SettingFilesHandler->ProjectFilename);

		path= Path::Combine(path,"Default.sip");
		File::Copy(SettingFilesHandler->StackFilename,path,true);
		ShowMessageBox("Default.sip saved.","Save");*/
} catch ( Exception^ ex ) {
	ThrowError(ex, "saveAsDefaultSettingsToolStripMenuItem_Click");
	//LogMessage("","");
}
		}
/***********************************************************************************************/
//Function to save as timebased settings
/***********************************************************************************************/
private: System::Void saveAsTimeBasedSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{			 
			DateTime d1 = DateTime::Now;
			String^ timestr=d1.ToString("HH-mm-ss_HH-mm-ss");
			SaveStack->FileName =timestr;
			System::Windows::Forms::DialogResult result=this->SaveStack->ShowDialog();			

			if(result == ::DialogResult::OK)
			{
			File::Copy(SettingFilesHandler->StackFilename,SaveStack->FileName,true);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "saveAsTimeBasedSettingsToolStripMenuItem_Click");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to load stack settings
/***********************************************************************************************/

private: System::Void loadSettingsToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
try{			
			System::Windows::Forms::DialogResult result=this->LoadSettings->ShowDialog();			

			if(result == ::DialogResult::OK)
			{
			
			SettingFilesHandler->SetStackFileName(LoadSettings->FileName);
			this->IPOStack->ReloadStack();
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "loadSettingsToolStripMenuItem1_Click");
	//LogMessage("","");
}

		 }

/***********************************************************************************************/
//Function to save as timebased settings
/***********************************************************************************************/

private: System::Void loadDefaultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	String ^ SettingFileName=Path::ChangeExtension(SettingFilesHandler->ProjectFilename,SettingExtension);	
	
	SettingFilesHandler->SetStackFileName(SettingFileName);
	this->IPOStack->ReloadStack();
		
		ShowMessageBox("General settings has loaded.","Load");
} catch ( Exception^ ex ) {
	ThrowError(ex, "loadSettingsToolStripMenuItem1_Click");
	//LogMessage("","");
}
}
private: System::Void saveAsImageSpecificSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{			 
			
			String^ str="ID<can be a part of ID>";
			SaveStack->FileName =str;
			System::Windows::Forms::DialogResult result=this->SaveStack->ShowDialog();			

			if(result == ::DialogResult::OK)
			{
			File::Copy(SettingFilesHandler->StackFilename,SaveStack->FileName,true);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "saveAsImageSpecificSettingsToolStripMenuItem_Click");
	//LogMessage("","");
}
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};


}

