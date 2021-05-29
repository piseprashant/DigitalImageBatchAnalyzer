#pragma once
#include "ParameterObject.h"
#include "SettingFiles.h"
#include "PropertyEditBox.h"
#include "ImageShow.h"
#include "IPOHandling.h"
#include "IPORunNotification.h"



#define RunningNotificationLogs(str) if(!StepThroughFlg){RunningNotificationLog=str; MainThread->Invoke(MainThread->ApplyLogDeligate);}

namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for IPO_Stack
	/// </summary>


	public ref class IPO_Stack : public System::Windows::Forms::Form
	{
	public:
		IPO_Stack(void)
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
		~IPO_Stack()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::TabControl^  tabControl1;

	protected: 

	private: System::Windows::Forms::TabPage^  PreProcessingTab;

	private: System::Windows::Forms::Panel^  PreProcessingPanel;



	private: System::Windows::Forms::ListView^  PropertyShow;
	private: System::Windows::Forms::ColumnHeader^  Property;
	private: System::Windows::Forms::ColumnHeader^  Value;


	private:delegate void ApplyLogDlgt();
	ApplyLogDlgt^ ApplyLogDeligate;
	String^ RunningNotificationLog;

	static bool End_StepThroughFlg=false;
	static bool StepThroughFlg=false;
	static bool Next_StepThroughFlg=false;

	IPO_Stack^ MainThread;

	public: static SettingFiles^ SettingFilesHandler;//This should come from parent Form
	public: static ImageShow^ ImShow;//This should come from the parent form
	public: static IPOHandling^ IPOHandler;
	public: Thread ^StackExecutionThread;
	public: IPORunNotification^ RunningNotification;
	

	//********************************************************************************************************************************//
//IPOs
			ParameterObject^ Current_IPO;
			static ParameterObject^ IPO_BinaryThreshold;
			static ParameterObject^ IPO_RGBThreshold;
			static ParameterObject^ IPO_Crop;
			static ParameterObject^ IPO_RGBPercentage;
			static ParameterObject^ IPO_BWPercentage;
			static ParameterObject^ IPO_Edges;
			static ParameterObject^	 IPO_BackgroundSubstraction;
			static ParameterObject^	 IPO_Brightness;
			static ParameterObject^	 IPO_Contrast;
			static ParameterObject^	 IPO_Saturation;
			static ParameterObject^	 IPO_CounterSearch;
			static ParameterObject^	 IPO_IMCalculator;
			static ParameterObject^	 IPO_BoundingShape;
			static ParameterObject^	 IPO_ColorCNV;
			static ParameterObject^	 IPO_AreaThreshold;
			static ParameterObject^	 IPO_ParameterThreshold;
			static ParameterObject^	 IPO_AVGBrightness;
			static ParameterObject^	 IPO_AVGRGB;
			static ParameterObject^	 IPO_Luma;
			static ParameterObject^	 IPO_AVGLightness;
			static ParameterObject^	 IPO_AVGIntensity;
			static ParameterObject^	 IPO_DePixalate;
			static ParameterObject^	 IPO_Counter;


			static array <ParameterObject^>^ IPO_List={IPO_BinaryThreshold,IPO_RGBThreshold,IPO_Crop,IPO_RGBPercentage,IPO_BWPercentage,IPO_Edges,IPO_BackgroundSubstraction,IPO_Brightness,IPO_Contrast,IPO_Saturation,IPO_CounterSearch,IPO_IMCalculator,IPO_BoundingShape,IPO_ColorCNV,IPO_AreaThreshold,IPO_ParameterThreshold,IPO_AVGBrightness,IPO_AVGRGB,IPO_Luma,IPO_AVGLightness,IPO_AVGIntensity,IPO_DePixalate,IPO_Counter};
			static array <ParameterObject^>^ IPO_StackList={IPO_BinaryThreshold,IPO_RGBThreshold,IPO_Crop,IPO_RGBPercentage,IPO_BWPercentage,IPO_Edges,IPO_BackgroundSubstraction,IPO_Brightness,IPO_Contrast,IPO_Saturation,IPO_CounterSearch,IPO_IMCalculator,IPO_BoundingShape,IPO_ColorCNV,IPO_AreaThreshold,IPO_ParameterThreshold,IPO_AVGBrightness,IPO_AVGRGB,IPO_Luma,IPO_AVGLightness,IPO_AVGIntensity,IPO_DePixalate,IPO_Counter};//dummy initialization
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  Run;
	private: System::Windows::Forms::ToolStripMenuItem^  Single_step;
	private: System::Windows::Forms::TabPage^  ParaMeasurement;
	private: System::Windows::Forms::Panel^  ParameterMeasurementPanel;
	private: System::Windows::Forms::TabPage^  ObjectCounting;

	private: System::Windows::Forms::Panel^  ObjectCountPanel;
	private: System::Windows::Forms::ToolStripMenuItem^  startSteppingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nextStepToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  endStepingToolStripMenuItem;



	public: 


	public: 

//IPOs
//********************************************************************************************************************************//

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->PreProcessingTab = (gcnew System::Windows::Forms::TabPage());
			this->PreProcessingPanel = (gcnew System::Windows::Forms::Panel());
			this->ParaMeasurement = (gcnew System::Windows::Forms::TabPage());
			this->ParameterMeasurementPanel = (gcnew System::Windows::Forms::Panel());
			this->ObjectCounting = (gcnew System::Windows::Forms::TabPage());
			this->ObjectCountPanel = (gcnew System::Windows::Forms::Panel());
			this->PropertyShow = (gcnew System::Windows::Forms::ListView());
			this->Property = (gcnew System::Windows::Forms::ColumnHeader());
			this->Value = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Run = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Single_step = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startSteppingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nextStepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->endStepingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->PreProcessingTab->SuspendLayout();
			this->ParaMeasurement->SuspendLayout();
			this->ObjectCounting->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->AutoScroll = true;
			this->splitContainer1->Panel1->Controls->Add(this->tabControl1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->PropertyShow);
			this->splitContainer1->Size = System::Drawing::Size(429, 312);
			this->splitContainer1->SplitterDistance = 259;
			this->splitContainer1->TabIndex = 1;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->PreProcessingTab);
			this->tabControl1->Controls->Add(this->ParaMeasurement);
			this->tabControl1->Controls->Add(this->ObjectCounting);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(253, 300);
			this->tabControl1->TabIndex = 0;
			// 
			// PreProcessingTab
			// 
			this->PreProcessingTab->AutoScroll = true;
			this->PreProcessingTab->AutoScrollMargin = System::Drawing::Size(10, 10);
			this->PreProcessingTab->AutoScrollMinSize = System::Drawing::Size(10, 0);
			this->PreProcessingTab->Controls->Add(this->PreProcessingPanel);
			this->PreProcessingTab->Location = System::Drawing::Point(4, 22);
			this->PreProcessingTab->Name = L"PreProcessingTab";
			this->PreProcessingTab->Padding = System::Windows::Forms::Padding(3);
			this->PreProcessingTab->Size = System::Drawing::Size(245, 274);
			this->PreProcessingTab->TabIndex = 0;
			this->PreProcessingTab->Text = L"Pre Processing";
			this->PreProcessingTab->UseVisualStyleBackColor = true;
			// 
			// PreProcessingPanel
			// 
			this->PreProcessingPanel->Location = System::Drawing::Point(8, 6);
			this->PreProcessingPanel->Name = L"PreProcessingPanel";
			this->PreProcessingPanel->Size = System::Drawing::Size(204, 996);
			this->PreProcessingPanel->TabIndex = 0;
			// 
			// ParaMeasurement
			// 
			this->ParaMeasurement->AutoScroll = true;
			this->ParaMeasurement->Controls->Add(this->ParameterMeasurementPanel);
			this->ParaMeasurement->Location = System::Drawing::Point(4, 22);
			this->ParaMeasurement->Name = L"ParaMeasurement";
			this->ParaMeasurement->Size = System::Drawing::Size(245, 274);
			this->ParaMeasurement->TabIndex = 1;
			this->ParaMeasurement->Text = L"Parameter Measurement";
			this->ParaMeasurement->UseVisualStyleBackColor = true;
			// 
			// ParameterMeasurementPanel
			// 
			this->ParameterMeasurementPanel->Location = System::Drawing::Point(8, 6);
			this->ParameterMeasurementPanel->Name = L"ParameterMeasurementPanel";
			this->ParameterMeasurementPanel->Size = System::Drawing::Size(204, 996);
			this->ParameterMeasurementPanel->TabIndex = 1;
			// 
			// ObjectCounting
			// 
			this->ObjectCounting->AutoScroll = true;
			this->ObjectCounting->Controls->Add(this->ObjectCountPanel);
			this->ObjectCounting->Location = System::Drawing::Point(4, 22);
			this->ObjectCounting->Name = L"ObjectCounting";
			this->ObjectCounting->Padding = System::Windows::Forms::Padding(3);
			this->ObjectCounting->Size = System::Drawing::Size(245, 274);
			this->ObjectCounting->TabIndex = 2;
			this->ObjectCounting->Text = L"Object Counting";
			this->ObjectCounting->UseVisualStyleBackColor = true;
			// 
			// ObjectCountPanel
			// 
			this->ObjectCountPanel->Location = System::Drawing::Point(8, 6);
			this->ObjectCountPanel->Name = L"ObjectCountPanel";
			this->ObjectCountPanel->Size = System::Drawing::Size(204, 996);
			this->ObjectCountPanel->TabIndex = 2;
			// 
			// PropertyShow
			// 
			this->PropertyShow->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->PropertyShow->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->Property, this->Value});
			this->PropertyShow->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PropertyShow->FullRowSelect = true;
			this->PropertyShow->GridLines = true;
			this->PropertyShow->LabelEdit = true;
			this->PropertyShow->Location = System::Drawing::Point(0, 0);
			this->PropertyShow->Name = L"PropertyShow";
			this->PropertyShow->Size = System::Drawing::Size(166, 312);
			this->PropertyShow->TabIndex = 0;
			this->PropertyShow->UseCompatibleStateImageBehavior = false;
			this->PropertyShow->View = System::Windows::Forms::View::Details;
			this->PropertyShow->ItemActivate += gcnew System::EventHandler(this, &IPO_Stack::PropertyShow_ItemActivate);
			// 
			// Property
			// 
			this->Property->Text = L"Property";
			this->Property->Width = 102;
			// 
			// Value
			// 
			this->Value->Text = L"Value";
			this->Value->Width = 59;
			// 
			// menuStrip1
			// 
			this->menuStrip1->AllowMerge = false;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->Run, this->Single_step, 
				this->startSteppingToolStripMenuItem, this->nextStepToolStripMenuItem, this->endStepingToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(429, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &IPO_Stack::menuStrip1_ItemClicked);
			// 
			// Run
			// 
			this->Run->Checked = true;
			this->Run->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(40, 20);
			this->Run->Text = L"Run";
			this->Run->Click += gcnew System::EventHandler(this, &IPO_Stack::runToolStripMenuItem_Click);
			// 
			// Single_step
			// 
			this->Single_step->Checked = true;
			this->Single_step->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Single_step->Name = L"Single_step";
			this->Single_step->Size = System::Drawing::Size(74, 20);
			this->Single_step->Text = L"SingleStep";
			this->Single_step->Click += gcnew System::EventHandler(this, &IPO_Stack::Stop_Click);
			// 
			// startSteppingToolStripMenuItem
			// 
			this->startSteppingToolStripMenuItem->Name = L"startSteppingToolStripMenuItem";
			this->startSteppingToolStripMenuItem->Size = System::Drawing::Size(86, 20);
			this->startSteppingToolStripMenuItem->Text = L"Start Steping";
			this->startSteppingToolStripMenuItem->Click += gcnew System::EventHandler(this, &IPO_Stack::startSteppingToolStripMenuItem_Click);
			// 
			// nextStepToolStripMenuItem
			// 
			this->nextStepToolStripMenuItem->Name = L"nextStepToolStripMenuItem";
			this->nextStepToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->nextStepToolStripMenuItem->Text = L"Next Step";
			this->nextStepToolStripMenuItem->Click += gcnew System::EventHandler(this, &IPO_Stack::nextStepToolStripMenuItem_Click);
			// 
			// endStepingToolStripMenuItem
			// 
			this->endStepingToolStripMenuItem->Name = L"endStepingToolStripMenuItem";
			this->endStepingToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->endStepingToolStripMenuItem->Text = L"End Steping";
			this->endStepingToolStripMenuItem->Click += gcnew System::EventHandler(this, &IPO_Stack::endStepingToolStripMenuItem_Click);
			// 
			// IPO_Stack
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->ClientSize = System::Drawing::Size(429, 336);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(540, 330);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"IPO_Stack";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"IPO_Stack";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &IPO_Stack::IPO_Stack_FormClosed);
			this->Load += gcnew System::EventHandler(this, &IPO_Stack::IPO_Stack_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->PreProcessingTab->ResumeLayout(false);
			this->ParaMeasurement->ResumeLayout(false);
			this->ObjectCounting->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/***********************************************************************************************/
//Function to execuite when form gets closed
/***********************************************************************************************/
	private: System::Void IPO_Stack_Load(System::Object^  sender, System::EventArgs^  e) {
try{
		ApplyLogDeligate = gcnew ApplyLogDlgt(this, &IPO_Stack::StackRunThreadLog);

		this->SettingFilesHandler->isIPOStackAvilable4Reload=true;
		MakeLibraryObjects();
		ReloadStack();
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_Stack_Load");
	//LogMessage("","");
}
			 }
/***********************************************************************************************/
//Function to Make library objects in stack
/***********************************************************************************************/
		 private: void MakeLibraryObjects()
				  {
try{
//****************************************************IPO_BinaryThreshold*********************************************************//
				  //Make the Binary threshold Object
				  ParameterObjectinit(SettingFilesHandler,IPO_BinaryThreshold,Enum_BinaryThreshold,"Threshold","128","Display Result","False","Quality Control","False");
				  IPO_BinaryThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_BinaryThresholdPrprtyButton=IPO_BinaryThreshold->CreatePropertyButton(Point(0,0),"Binary Threshold",0);
				  IPO_BinaryThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				 // this->PreProcessingPanel->Controls->Add(IPO_BinaryThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BinaryThresholdPopButton=IPO_BinaryThreshold->CreatePopButton(Point(226,0),1);
				  IPO_BinaryThresholdPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			     // 


				  //Set the Property list for Binary threshold 
				  {	
					array<String^>^ argstring={"64","128","256"};
					ListViewItem^ Item=this->PopulateItems("Threshold","128",argstring,"Value Range: 0:256 \n Value< Threshold = 0 \n Value>Threshold =255 ");
				
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
					array<ListViewItem^>^ tmp={Item,Item2,Item3};
					IPO_BinaryThreshold->PropertyList=tmp;
				  }

				   IPO_List->SetValue(IPO_BinaryThreshold,0);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_RGBThreshold*********************************************************************//				  
				 
				   //Make the RGBThreshold Object
				  ParameterObjectinit(SettingFilesHandler,IPO_RGBThreshold,Enum_RGBThreshold,"Threshold","128","R","128","G","128","B","128","Display Result","False","Quality Control","False");
				  IPO_RGBThreshold->ObjectKind=PreProcessing;//PreProcessing;
				  System::Windows::Forms::Button^ IPO_RGBThresholdPrprtyButton=IPO_RGBThreshold->CreatePropertyButton(Point(0,60),"RGB Threshold",2);
				  IPO_RGBThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  //this->PreProcessingPanel->Controls->Add(IPO_RGBThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_RGBThresholdPopButton=IPO_RGBThreshold->CreatePopButton(Point(226,60),3);
				  IPO_RGBThresholdPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //this->PreProcessingPanel->Controls->Add(IPO_RGBThresholdPopButton);
				  //Set the Property list for Binary threshold 
				  {	
					array<String^>^ argstring={"64","128","256"};
					ListViewItem^ Item=this->PopulateItems("R","128",argstring,"Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
					ListViewItem^ Item1=this->PopulateItems("G","128",argstring,"Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
					ListViewItem^ Item2=this->PopulateItems("B","128",argstring,"Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
				
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item3=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item4=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item,Item1,Item2,Item3,Item4};
					IPO_RGBThreshold->PropertyList=tmp;
				  }

				  IPO_List->SetValue(IPO_RGBThreshold,1);
//********************************************************************************************************************************//				  
//*********************************************IPO_Crop*********************************************************************//				  
				  //Make the Crop Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Crop,Enum_Crop,"Method","Whole","CornerA","0,0","CornerB","100,0","CornerC","100,100","CornerD","0,100","Display Result","False","Quality Control","False");
				  IPO_Crop->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_CropPrprtyButton=IPO_Crop->CreatePropertyButton(Point(0,(ButtonHight*2)),"Crop",4);
				  IPO_CropPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				 // this->PreProcessingPanel->Controls->Add(IPO_CropPrprtyButton);
				  System::Windows::Forms::Button^ IPO_CropPopButton=IPO_Crop->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_CropPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			     // this->PreProcessingPanel->Controls->Add(IPO_CropPushButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"TopThird","BottomTwoThird","Custom"};
					ListViewItem^ Item1=this->PopulateItems("Method","Whole",argstring,"Select methods to crop image accordingly. If select Custom method, user corner values to adjust the custom selection");
					array<String^>^ Cornerstring={"0,200","200,0","200,200","0,0"};
					ListViewItem^ Item2=this->PopulateItems("CornerA","0,0",Cornerstring,"Custom method must be selected to apply Corner values");
					ListViewItem^ Item3=this->PopulateItems("CornerB","100,0",Cornerstring,"Custom method must be selected to apply Corner values");
					ListViewItem^ Item4=this->PopulateItems("CornerC","100,100",Cornerstring,"Custom method must be selected to apply Corner values");
					ListViewItem^ Item5=this->PopulateItems("CornerD","0,100",Cornerstring,"Custom method must be selected to apply Corner values");
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item6=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item7=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3,Item4,Item5,Item6,Item7};
					IPO_Crop->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Crop,2);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_RGBPercentage*********************************************************************//				  
				  //Make the RGBPercentage Object
				  ParameterObjectinit(SettingFilesHandler,IPO_RGBPercentage,Enum_RGBPercentage,"Display Result","False","Quality Control","False");
				  IPO_RGBPercentage->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_RGBPercentagePrprtyButton=IPO_RGBPercentage->CreatePropertyButton(Point(0,(ButtonHight*1)),"RGB Percentage",2);
				  IPO_RGBPercentagePrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_RGBPercentagePopButton=IPO_RGBPercentage->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_RGBPercentagePopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_RGBPercentage->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_RGBPercentage,3);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_BWPercentage*********************************************************************//				  
				  //Make the BWPercentage Object
				  ParameterObjectinit(SettingFilesHandler,IPO_BWPercentage,Enum_BWPercentage,"Display Result","False","Quality Control","False");
				  IPO_BWPercentage->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_BWPercentagePrprtyButton=IPO_BWPercentage->CreatePropertyButton(Point(0,(ButtonHight*1)),"BW Percentage",2);
				  IPO_BWPercentagePrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_BWPercentagePopButton=IPO_BWPercentage->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_BWPercentagePopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_BWPercentage->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_BWPercentage,4);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_Edges*********************************************************************//				  
				  //Make the Edges Object
				 ParameterObjectinit(SettingFilesHandler,IPO_Edges,Enum_Edges,"threshold1","32","threshold2","32","apertureSize","3","Display Result","False","Quality Control","False");
				  IPO_Edges->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_EdgePrprtyButton=IPO_Edges->CreatePropertyButton(Point(0,(ButtonHight*2)),"Edges",4);
				  IPO_EdgePrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  
				  System::Windows::Forms::Button^ IPO_EdgePopButton=IPO_Edges->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_EdgePopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			     // this->panel1->Controls->Add(IPO_EdgePushButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"32","64","128","250"};
					ListViewItem^ Item1=this->PopulateItems("threshold1","32",argstring,"First threshold for the hysteresis procedure");
					
					ListViewItem^ Item2=this->PopulateItems("threshold2","32",argstring,"Second threshold for the hysteresis procedure");
					
					array<String^>^ SobelSize={"1","3","5","7"};
					ListViewItem^ Item3=this->PopulateItems("apertureSize","3",SobelSize,"Aperture size for the Sobel() operator");
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item4=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item5=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					

					array<ListViewItem^>^ tmp={Item1,Item2,Item3,Item4,Item5};
					IPO_Edges->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Edges,5);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_BackgroundSubstraction*********************************************************************//				  
				  //Make the Edge Object
#ifdef SCIENTIFIC
ParameterObjectinit(SettingFilesHandler,IPO_BackgroundSubstraction,Enum_BackgroundSubstraction,"Learning Rate","0.01","History","def","nmixtures","def","backgroundRatio","def","noiseSigma","def","Display Result","False","Quality Control","False");
#else
ParameterObjectinit(SettingFilesHandler,IPO_BackgroundSubstraction,Enum_BackgroundSubstraction,"Learning Rate","0.01","Display Result","False","Quality Control","False");
#endif

				  IPO_BackgroundSubstraction->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_BackgroundSubstractionPrprtyButton=IPO_BackgroundSubstraction->CreatePropertyButton(Point(0,(ButtonHight*2)),"BackgroundSubstraction",4);
				  IPO_BackgroundSubstractionPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  //this->panel1->Controls->Add(IPO_BackgroundSubstractionPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BackgroundSubstractionPopButton=IPO_BackgroundSubstraction->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BackgroundSubstractionPopButton->Click += gcnew System::EventHandler(this,&IPO_Stack::IPO_PopAction);
			      //this->panel1->Controls->Add(IPO_BackgroundSubstractionPopButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"0.01","0.1","0.001","1"};
					ListViewItem^ Item1=this->PopulateItems("Learning Rate","0.01",argstring,"Rate of learning Background");
					
#ifdef SCIENTIFIC
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
					
					ListViewItem^ Item4=this->PopulateItems("History","def","Refer OpenCV manual");
					ListViewItem^ Item5=this->PopulateItems("nmixtures","def","Refer OpenCV manual");
					ListViewItem^ Item6=this->PopulateItems("backgroundRatio","def","Refer OpenCV manual");
					ListViewItem^ Item7=this->PopulateItems("noiseSigma","def","Refer OpenCV manual");
					array<ListViewItem^>^ tmp={Item1,Item2,Item3,Item4,Item5,Item6,Item7};
					IPO_BackgroundSubstraction->PropertyList=tmp;



#else				

					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_BackgroundSubstraction->PropertyList=tmp;
				
#endif		

					
				  }
				  IPO_List->SetValue(IPO_BackgroundSubstraction,6);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_Brightness*********************************************************************//				  
				  //Make the Brightness Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Brightness,Enum_Brightness,"Value","8","Display Result","False","Quality Control","False");
				  IPO_Brightness->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_BrightnessPrprtyButton=IPO_Brightness->CreatePropertyButton(Point(0,(ButtonHight*2)),"Brightness",4);
				  IPO_BrightnessPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_BrightnessPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BrightnessPopButton=IPO_Brightness->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BrightnessPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_BrightnessPopButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"8","16","32","64"};
					ListViewItem^ Item1=this->PopulateItems("Value","8",argstring,"Enter the Brightness value to be applied Range (-100 to 100) ");
					
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					

					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_Brightness->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Brightness,7);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_Contrast*********************************************************************//				  
				  //Make the Contrast Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Contrast,Enum_Contrast,"Value","8","Display Result","False","Quality Control","False");
				  IPO_Contrast->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_ContrastPrprtyButton=IPO_Contrast->CreatePropertyButton(Point(0,(ButtonHight*2)),"Contrast",4);
				  IPO_ContrastPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_ContrastPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ContrastPopButton=IPO_Contrast->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ContrastPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_ContrastPopButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"1","1.5","2","2.5"};
					ListViewItem^ Item1=this->PopulateItems("Value","1",argstring,"Enter the Contrast value to be applied Range (0.1 to 5.0)");
					
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					

					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_Contrast->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Contrast,8);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_Saturation*********************************************************************//				  
				  //Make the Saturation Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Saturation,Enum_Saturation,"Value","8","Display Result","False","Quality Control","False");
				  IPO_Saturation->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_SaturationPrprtyButton=IPO_Saturation->CreatePropertyButton(Point(0,(ButtonHight*2)),"Saturation",4);
				  IPO_SaturationPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_SaturationPrprtyButton);
				  System::Windows::Forms::Button^ IPO_SaturationPopButton=IPO_Saturation->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_SaturationPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    // this->panel1->Controls->Add(IPO_SaturationPopButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"8","16","32","64"};
					ListViewItem^ Item1=this->PopulateItems("Value","8",argstring,"Enter the Saturation value to be applied Range (-100 to 100) ");
					
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					

					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_Saturation->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Saturation,9);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_CounterSearch*********************************************************************//				  
				  //Make the CounterSearch Object
				  ParameterObjectinit(SettingFilesHandler,IPO_CounterSearch,Enum_CounterSearch,"Contour","All","Area Threshold","100","Perimeter Threshold","100","Display Result","False","Quality Control","False");
				  IPO_CounterSearch->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_CounterSearchPrprtyButton=IPO_CounterSearch->CreatePropertyButton(Point(0,(ButtonHight*2)),"CounterSearch",4);
				  IPO_CounterSearchPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  
				  System::Windows::Forms::Button^ IPO_CounterSearchPopButton=IPO_CounterSearch->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_CounterSearchPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			     
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"All","OnlyExternal", "OnlyInternal"};
					ListViewItem^ Item1=this->PopulateItems("Contour","All",argstring,"Contour level");
					array<String^>^ argstring2={"10","100", "200"};
					ListViewItem^ Item2=this->PopulateItems("AreaThreshold","100",argstring2,"Select contours with larger area than threshold");
					ListViewItem^ Item3=this->PopulateItems("PerimeterThreshold","100",argstring2,"Select contours with larger perimeter than threshold");
					
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item4=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item5=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					

					array<ListViewItem^>^ tmp={Item1,Item2,Item3,Item4,Item5};
					IPO_CounterSearch->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_CounterSearch,10);//Setting IPO value to array
//********************************************************************************************************************************//				  

	
//*********************************************IPO_IMCalculator*********************************************************************//				  
				  //Make the IMCalculator Object
				  ParameterObjectinit(SettingFilesHandler,IPO_IMCalculator,Enum_IMCalculator,"Operation","Add","Second Image","Prev Image","Display Result","False","Quality Control","False");
				  IPO_IMCalculator->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_IMCalculatorPrprtyButton=IPO_IMCalculator->CreatePropertyButton(Point(0,(ButtonHight*2)),"IMCalculator",4);
				  IPO_IMCalculatorPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  //this->panel1->Controls->Add(IPO_IMCalculatorPrprtyButton);
				  System::Windows::Forms::Button^ IPO_IMCalculatorPopButton=IPO_IMCalculator->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_IMCalculatorPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			     // this->panel1->Controls->Add(IPO_IMCalculatorPopButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"Add","Sub", "Bit And","Bit Or","Bit Xor","Bit Not"};
					ListViewItem^ Item1=this->PopulateItems("Operation","Add",argstring,"Operation between images");

					array<String^>^ argstring2={"Prev Image","Browse"};
					ListViewItem^ Item2=this->PopulateItems("Second Image","Prev Image",argstring2,"Second Image to be process");
					
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item3=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item4=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3,Item4};
					IPO_IMCalculator->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_IMCalculator,11);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_BoundingShape*********************************************************************//				  
				  //Make the BoundingShape Object
				  ParameterObjectinit(SettingFilesHandler,IPO_BoundingShape,Enum_BoundingShape,"BoundingShape","Rectangle","Display Result","False","Quality Control","False");
				  IPO_BoundingShape->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_BoundingShapePrprtyButton=IPO_BoundingShape->CreatePropertyButton(Point(0,(ButtonHight*2)),"BoundingShape",4);
				  IPO_BoundingShapePrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_BoundingShapePrprtyButton);
				  System::Windows::Forms::Button^ IPO_BoundingShapePushButton=IPO_BoundingShape->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BoundingShapePushButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_BoundingShapePushButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"Rectangle","Circle", "Elipse"};
					ListViewItem^ Item1=this->PopulateItems("BoundingShape","Rectangle",argstring,"Select contour shape");			
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_BoundingShape->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_BoundingShape,12);//Setting IPO value to array
//********************************************************************************************************************************//				  
			
//*********************************************IPO_ColorCNV*********************************************************************//				  
				  //Make the ColorCNV Object
				  ParameterObjectinit(SettingFilesHandler,IPO_ColorCNV,Enum_ColorCNV,"ColorCNV","RGB2GRAY","Display Result","False","Quality Control","False");
				  IPO_ColorCNV->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_ColorCNVPrprtyButton=IPO_ColorCNV->CreatePropertyButton(Point(0,(ButtonHight*2)),"ColorCNV",4);
				  IPO_ColorCNVPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_ColorCNVPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ColorCNVPushButton=IPO_ColorCNV->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ColorCNVPushButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_ColorCNVPushButton);
				  //Set the Property list for Crop
				  {				
					array<String^>^ argstring={"RGB2GRAY","BGR2Luv","BGR2XYZ","RGB2XYZ","XYZ2BGR","XYZ2RGB","BGR2YCrCb","RGB2YCrCb","YCrCb2BGR","YCrCb2RGB", 
					"BGR2HSV","RGB2HSV","HSV2BGR","HSV2RGB","BGR2HLS","RGB2HLS","HLS2BGR","HLS2RGB","BGR2Lab","RGB2Lab","Lab2BGR","Lab2RGB",
					"BGR2Luv","RGB2Luv","Luv2BGR","Luv2RGB"};
					ListViewItem^ Item1=this->PopulateItems("ColorCNV","RGB2GRAY",argstring,"Convert Image");
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_ColorCNV->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_ColorCNV,13);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_AreaThreshold*********************************************************************//				  
				  //Make the AreaThreshold Object
				  ParameterObjectinit(SettingFilesHandler,IPO_AreaThreshold,Enum_AreaThreshold,"AreaThreshold","Threshold","Display Result","False","Quality Control","False");
				  IPO_AreaThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_AreaThresholdPrprtyButton=IPO_AreaThreshold->CreatePropertyButton(Point(0,(ButtonHight*2)),"AreaThreshold",4);
				  IPO_AreaThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_AreaThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_AreaThresholdPushButton=IPO_AreaThreshold->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_AreaThresholdPushButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_AreaThresholdPushButton);
				  //Set the Property list for Crop
				  {				
					array<String^>^ argstring={"Threshold"};
					ListViewItem^ Item1=this->PopulateItems("AreaThreshold","Threshold",argstring,"Determine the Area threshold");
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_AreaThreshold->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_AreaThreshold,14);//Setting IPO value to array
//********************************************************************************************************************************//				  

				  
//*********************************************IPO_ParameterThreshold*********************************************************************//				  
				  //Make the ParameterThreshold Object
				  ParameterObjectinit(SettingFilesHandler,IPO_ParameterThreshold,Enum_ParameterThreshold,"ParameterThreshold","Threshold","Display Result","False","Quality Control","False");
				  IPO_ParameterThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_ParameterThresholdPrprtyButton=IPO_ParameterThreshold->CreatePropertyButton(Point(0,(ButtonHight*2)),"ParameterThreshold",4);
				  IPO_ParameterThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_ParameterThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ParameterThresholdPushButton=IPO_ParameterThreshold->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ParameterThresholdPushButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_ParameterThresholdPushButton);
				  //Set the Property list for Crop
				  {				
					array<String^>^ argstring={"Threshold"};
					ListViewItem^ Item1=this->PopulateItems("ParameterThreshold","Threshold",argstring,"Determine the Parameter threshold");
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_ParameterThreshold->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_ParameterThreshold,15);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_AVGBrightness*********************************************************************//				  
				  //Make the AVGBrightness Object
				  ParameterObjectinit(SettingFilesHandler,IPO_AVGBrightness,Enum_AVGBrightness,"Display Result","False","Quality Control","False");
				  IPO_AVGBrightness->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_AVGBrightnessPrprtyButton=IPO_AVGBrightness->CreatePropertyButton(Point(0,(ButtonHight*1)),"AVG Brightness",2);
				  IPO_AVGBrightnessPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGBrightnessPopButton=IPO_AVGBrightness->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGBrightnessPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_AVGBrightness->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_AVGBrightness,16);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_AVGRGB*********************************************************************//				  
				  //Make the AVGRGB Object
				  ParameterObjectinit(SettingFilesHandler,IPO_AVGRGB,Enum_AVGRGB,"Display Result","False","Quality Control","False");
				  IPO_AVGRGB->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_AVGRGBPrprtyButton=IPO_AVGRGB->CreatePropertyButton(Point(0,(ButtonHight*1)),"AVG RGB",2);
				  IPO_AVGRGBPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGRGBPopButton=IPO_AVGRGB->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGRGBPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_AVGRGB->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_AVGRGB,17);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_Luma*********************************************************************//				  
				  //Make the Luma Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Luma,Enum_Luma,"Display Result","False","Quality Control","False");
				  IPO_Luma->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_LumaPrprtyButton=IPO_Luma->CreatePropertyButton(Point(0,(ButtonHight*1)),"Luma",2);
				  IPO_LumaPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_LumaPopButton=IPO_Luma->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_LumaPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_Luma->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Luma,18);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_AVGLightness*********************************************************************//				  
				  //Make the AVG Lightness Object
				  ParameterObjectinit(SettingFilesHandler,IPO_AVGLightness,Enum_AVGLightness,"Display Result","False","Quality Control","False");
				  IPO_AVGLightness->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_AVGLightnessPrprtyButton=IPO_AVGLightness->CreatePropertyButton(Point(0,(ButtonHight*1)),"AVG Lightness",2);
				  IPO_AVGLightnessPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGLightnessPopButton=IPO_AVGLightness->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGLightnessPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_AVGLightness->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_AVGLightness,19);//Setting IPO value to array
//********************************************************************************************************************************//				  
				  
//*********************************************IPO_AVGIntensity*********************************************************************//				  
				  //Make the AVG Intensity Object
				  ParameterObjectinit(SettingFilesHandler,IPO_AVGIntensity,Enum_AVGIntensity,"Display Result","False","Quality Control","False");
				  IPO_AVGIntensity->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_AVGIntensityPrprtyButton=IPO_AVGIntensity->CreatePropertyButton(Point(0,(ButtonHight*1)),"AVG Intensity",2);
				  IPO_AVGIntensityPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGIntensityPopButton=IPO_AVGIntensity->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGIntensityPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_AVGIntensity->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_AVGIntensity,20);//Setting IPO value to array
//********************************************************************************************************************************//
				  
//*********************************************IPO_DePixalate*********************************************************************//				  
				  //Make the DePixalate Object
				  ParameterObjectinit(SettingFilesHandler,IPO_DePixalate,Enum_DePixalate,"DePixalate","kernel size","Display Result","False","Quality Control","False");
				  IPO_DePixalate->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_DePixalatePrprtyButton=IPO_DePixalate->CreatePropertyButton(Point(0,(ButtonHight*2)),"DePixalate",4);
				  IPO_DePixalatePrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				//  this->panel1->Controls->Add(IPO_DePixalatePrprtyButton);
				  System::Windows::Forms::Button^ IPO_DePixalatePushButton=IPO_DePixalate->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_DePixalatePushButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			    //  this->panel1->Controls->Add(IPO_DePixalatePushButton);
				  //Set the Property list for Crop
				  {				
					array<String^>^ argstring={"kernel size"};
					ListViewItem^ Item1=this->PopulateItems("DePixalate","kernel size",argstring,"Determine the kernel size for PreProcessing");
					array<String^>^ truefalsetring={"False","True"};
					ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
					ListViewItem^ Item3=this->PopulateItems("Quality Control","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
					array<ListViewItem^>^ tmp={Item1,Item2,Item3};
					IPO_DePixalate->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_DePixalate,21);//Setting IPO value to array
//********************************************************************************************************************************//				  

//*********************************************IPO_Counter*********************************************************************//				  
				  //Make the Counter Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Counter,Enum_Counter,"Display Result","False","Quality Control","False");
				  IPO_Counter->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_CounterPrprtyButton=IPO_Counter->CreatePropertyButton(Point(0,(ButtonHight*1)),"Counter",2);
				  IPO_CounterPrprtyButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_CounterPopButton=IPO_Counter->CreatePopButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_CounterPopButton->Click += gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
			      //Set the Property list for Counter 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_Counter->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Counter,22);//Setting IPO value to array
//********************************************************************************************************************************//

} catch ( Exception^ ex ) {
	ThrowError(ex, "IPOStackMakeLibraryObjects");
	//LogMessage("","");
}				 
				 
				  
				  }


//********************************************************************************************************************************//
//********************************************************************************************************************************//
//Linking Color ratio button action
/***********************************************************************************************/
//Function to Execuite when user clicks on pop button
/***********************************************************************************************/
private: System::Void IPO_PopAction(System::Object^  sender, System::EventArgs^  e) {
try{
			 System::Windows::Forms::Button^ button=(System::Windows::Forms::Button^)sender;
			 String^ ID=(String^)button->Tag;
			 Int32 id;
			 Int32::TryParse((String^)button->Tag,id);

			 ParameterObject^ StackElement;

			 for(int i=0;i<IPO_StackList->Length;i++)
			 {
				 if(IPO_StackList[i]->UniqueID==id)
					 StackElement=IPO_StackList[i];
			 }
			 Current_IPO=StackElement;
			  StackElement->PopingFromStack();
			 this->ReloadStack();
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_PopAction");
	//LogMessage("","");
}
			 
			  }
/***********************************************************************************************/
//Function to Execuite when user clicks on show property button
/***********************************************************************************************/
private: System::Void IPO_ShowPropertyAction(System::Object^  sender, System::EventArgs^  e) {
try{
			  System::Windows::Forms::Button^ button=(System::Windows::Forms::Button^)sender;
			 String^ ID=(String^)button->Tag;
			 Int32 id;
			 Int32::TryParse((String^)button->Tag,id);

			 ParameterObject^ StackElement;

			 for(int i=0;i<IPO_StackList->Length;i++)
			 {
				 if(IPO_StackList[i]->UniqueID==id)
					 StackElement=IPO_StackList[i];
			 }
			 Current_IPO=StackElement;
			 this->ShowProperties(StackElement->PropertyList);
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_ShowPropertyAction");
	//LogMessage("","");
}
			  }
//********************************************************************************************************************************//


/***********************************************************************************************/
//Function to show property on GUI
/***********************************************************************************************/

private: System::Void ShowProperties(array<ListViewItem^>^ ArgItems){
try{
				 this->PropertyShow->Items->Clear();
				 this->PropertyShow->Items->AddRange(ArgItems);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ShowProperties");
	//LogMessage("","");
}

			 }

/***********************************************************************************************/
//Function to Populate items in listview
/***********************************************************************************************/
	private: ListViewItem^ PopulateItems(String^ item1, String^ Val1,array<String^>^ argstring, String^ Tooltipstring){
try{
				ListViewItem^ ArgItems = gcnew ListViewItem( item1,0 );
				 ArgItems->SubItems->Add(Val1 );

				 if(argstring->Length>0)
					ArgItems->SubItems->AddRange(argstring );


				 ArgItems->ToolTipText =Tooltipstring;
				 return ArgItems;
} catch ( Exception^ ex ) {
	ThrowError(ex, "PopulateItems");
	//LogMessage("","");
}
			}


/***********************************************************************************************/
//Function to Populate items in listview
/***********************************************************************************************/
	private: ListViewItem^ PopulateItems(String^ item1, String^ Val1, String^ Tooltipstring){
try{
				ListViewItem^ ArgItems = gcnew ListViewItem( item1,0 );
				 ArgItems->SubItems->Add(Val1 );

				 


				 ArgItems->ToolTipText =Tooltipstring;
				 return ArgItems;
} catch ( Exception^ ex ) {
	ThrowError(ex, "PopulateItems");
	//LogMessage("","");
}
			}

/***********************************************************************************************/
//Function to execuite when user clicks on any item
/***********************************************************************************************/

	private: System::Void PropertyShow_ItemActivate(System::Object^  sender, System::EventArgs^  e) {
			 
try{				 
			 ListViewItem^ Item =(( ListView^) sender)->SelectedItems[0];
			 PropertyEditBox^ ShowBox = gcnew PropertyEditBox;

			 ShowBox->PropertyDescr->Text=  Item->ToolTipText;
			 ShowBox->PropertyTitle->Text= Item->Text;
			 ShowBox->Value->Text= Item->SubItems[1]->Text;

			

			 //Starts from 1 to avoid the first item name
			 for(int i=1; i<Item->SubItems->Count;i++){

				ShowBox->Value->Items->Add(Item->SubItems[i]->Text);
			 }

			 ShowBox->ItemFromParentForm=Item;//Passingreference to make the change
			 ShowBox->IPOFromParentForm=Current_IPO;
			 ShowBox->SettingFilesHandler= this->SettingFilesHandler;
			 ShowBox->ShowDialog();
			 
} catch ( Exception^ ex ) {
	ThrowError(ex, "PropertyShow_ItemActivate");
	//LogMessage("","");
}			 
			 
			 }

/***********************************************************************************************/
//Function to reload stack from the files
/***********************************************************************************************/

public: void ReloadStack(){
try{
			ParameterObject^ IPOHolder;
			SettingFilesHandler->ReloadStackElements();
			Array::Resize(IPO_StackList,0);//resizing array to 0
			this->PreProcessingPanel->Controls->Clear();
			

			for(int pos=0,i=0; i< SettingFilesHandler->StackLength(); i++)
			{
				String^ Properties;
				Int32 StackID=SettingFilesHandler->ReadStackID(i);
				int j=0;
				for(j=0;j<IPO_List->Length;j++)
				{
					if(abs(StackID-IPO_List[j]->UniqueID)<=MAXSTACKIPO){
					IPOHolder=IPO_List[j];
					IPOHolder->UniqueID=(Stack_Section)StackID;
					break;
					}

				}
				if(SettingFilesHandler->ReadStackSection(IPOHolder->UniqueID,Properties)!=NoStackSectionError)
				{
					
				 
				
				ParameterObject^ StackObject=gcnew ParameterObject(IPOHolder);
				//Setting button click and Tag
				StackObject->ShowProperty->Click+=gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				StackObject->Pop->Click+=gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
				Array::Resize(IPO_StackList,IPO_StackList->Length+1);
				IPO_StackList->SetValue(StackObject,IPO_StackList->Length-1);
				IPO_StackList[IPO_StackList->Length-1]->Properties=Properties;
				IPO_StackList[IPO_StackList->Length-1]->PropertyList=SettingFilesHandler->PropertyStr2List(IPO_StackList[IPO_StackList->Length-1]->PropertyList,Properties);
				//draw buttons
				IPO_StackList[IPO_StackList->Length-1]->ShowProperty->Location=Point(0,pos);
				this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StackList->Length-1]->ShowProperty);
				IPO_StackList[IPO_StackList->Length-1]->Pop->Location=Point(PropertyButtonWidth,pos);
				this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StackList->Length-1]->Pop);
				pos+=ButtonHight;

				}
				
				
				

			}
SortAndDisplayStack();

} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadStack");
	//LogMessage("","");
}			

			//Here clear the panel and redraw buttons again
}

		/***********************************************************************************************/
//Function to reload Library from the IPOStacks
/***********************************************************************************************/

public: void SortAndDisplayStack(){
try{
			
			
			this->PreProcessingPanel->Controls->Clear();
			this->ParameterMeasurementPanel->Controls->Clear();
			this->ObjectCountPanel->Controls->Clear();

			
			int IPO_StckList_Pos=0;
			
			ParameterObject^ IPO_Holder;
			array <ParameterObject^>^ ParameterMeasurementArray={IPO_Holder};
			array <ParameterObject^>^ PreprocessingArray={IPO_Holder};
			array <ParameterObject^>^ ObjectCountArray={IPO_Holder};


			Array::Resize(ParameterMeasurementArray,0);//resizing array to 0
			Array::Resize(PreprocessingArray,0);//resizing array to 0
			Array::Resize(ObjectCountArray,0);//resizing array to 0

			for(int i=0; i< IPO_StackList->Length; i++)
			{
					
				if(IPO_StackList[i]->ObjectKind==PreProcessing){ 
					Array::Resize(PreprocessingArray,PreprocessingArray->Length+1);
				    PreprocessingArray->SetValue(IPO_StackList[i],PreprocessingArray->Length-1);

					
				}
				else if(IPO_StackList[i]->ObjectKind==ParameterMeasurement){ 
					Array::Resize(ParameterMeasurementArray,ParameterMeasurementArray->Length+1);
				    ParameterMeasurementArray->SetValue(IPO_StackList[i],ParameterMeasurementArray->Length-1);

				}
				else if(IPO_StackList[i]->ObjectKind==ObjectCount){ 
					Array::Resize(ObjectCountArray,ObjectCountArray->Length+1);
				    ObjectCountArray->SetValue(IPO_StackList[i],ObjectCountArray->Length-1);

				}
				
			}
			IPO_StckList_Pos=0;
			int PreProcessingPos=0, ParameterMeasurementPos=0, ObjectCountPos=0; 
			
			for(int i=0; i< PreprocessingArray->Length; i++)
			{
				IPO_StackList[IPO_StckList_Pos]=PreprocessingArray[i];
				IPO_StackList[IPO_StckList_Pos]->ShowProperty->Location=Point(0,PreProcessingPos);
				IPO_StackList[IPO_StckList_Pos]->Pop->Location=Point(PropertyButtonWidth,PreProcessingPos);
				PreProcessingPos+=ButtonHight;
				this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->ShowProperty);
				this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->Pop);
				IPO_StckList_Pos++;
			}
			for(int i=0; i< ParameterMeasurementArray->Length; i++)
			{
				IPO_StackList[IPO_StckList_Pos]=ParameterMeasurementArray[i];
				IPO_StackList[IPO_StckList_Pos]->ShowProperty->Location=Point(0,ParameterMeasurementPos);
				IPO_StackList[IPO_StckList_Pos]->Pop->Location=Point(PropertyButtonWidth,ParameterMeasurementPos);
				ParameterMeasurementPos+=ButtonHight;
				this->ParameterMeasurementPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->ShowProperty);
				this->ParameterMeasurementPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->Pop);
				IPO_StckList_Pos++;
			}
			for(int i=0; i< ObjectCountArray->Length; i++)
			{
				IPO_StackList[IPO_StckList_Pos]=ObjectCountArray[i];
				IPO_StackList[IPO_StckList_Pos]->ShowProperty->Location=Point(0,ObjectCountPos);
				IPO_StackList[IPO_StckList_Pos]->Pop->Location=Point(PropertyButtonWidth,ObjectCountPos);
				ObjectCountPos+=ButtonHight;
	
				this->ObjectCountPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->ShowProperty);
				this->ObjectCountPanel->Controls->Add(IPO_StackList[IPO_StckList_Pos]->Pop);
				IPO_StckList_Pos++;
			}

} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadStack");
	//LogMessage("","");
}			

			//Here clear the panel and redraw buttons again
}

/***********************************************************************************************/
//Function to reload stack from run thread
/***********************************************************************************************/

public: void ReloadStackRunThread(){
try{
			ParameterObject^ IPOHolder;
			SettingFilesHandler->ReloadStackElements();
			Array::Resize(IPO_StackList,0);//resizing array to 0
			
			

			for(int pos=0,i=0; i< SettingFilesHandler->StackLength(); i++)
			{
				String^ Properties;
				Int32 StackID=SettingFilesHandler->ReadStackID(i);
				int j=0;
				for(j=0;j<IPO_List->Length;j++)
				{
					if(abs(StackID-IPO_List[j]->UniqueID)<=MAXSTACKIPO){
					IPOHolder=IPO_List[j];
					IPOHolder->UniqueID=(Stack_Section)StackID;
					break;
					}

				}
				if(SettingFilesHandler->ReadStackSection(IPOHolder->UniqueID,Properties)!=NoStackSectionError)
				{
					
				 
				
				ParameterObject^ StackObject=gcnew ParameterObject(IPOHolder);
				//Setting button click and Tag
				StackObject->ShowProperty->Click+=gcnew System::EventHandler(this, &IPO_Stack::IPO_ShowPropertyAction);
				StackObject->Pop->Click+=gcnew System::EventHandler(this, &IPO_Stack::IPO_PopAction);
				Array::Resize(IPO_StackList,IPO_StackList->Length+1);
				IPO_StackList->SetValue(StackObject,IPO_StackList->Length-1);
				IPO_StackList[IPO_StackList->Length-1]->Properties=Properties;
				IPO_StackList[IPO_StackList->Length-1]->PropertyList=SettingFilesHandler->PropertyStr2List(IPO_StackList[IPO_StackList->Length-1]->PropertyList,Properties);
				//draw buttons
				IPO_StackList[IPO_StackList->Length-1]->ShowProperty->Location=Point(0,pos);
				//this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StackList->Length-1]->ShowProperty);
				IPO_StackList[IPO_StackList->Length-1]->Pop->Location=Point(PropertyButtonWidth,pos);
				//this->PreProcessingPanel->Controls->Add(IPO_StackList[IPO_StackList->Length-1]->Pop);
				pos+=ButtonHight;

				}
				
				
				

			}

} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadStackRunThread");
	//LogMessage("","");
}			

			//Here clear the panel and redraw buttons again
}
/***********************************************************************************************/
//Function to execuite when stack form closes
/***********************************************************************************************/
private: System::Void IPO_Stack_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
try{
	this->SettingFilesHandler->isIPOStackAvilable4Reload=false;
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_Stack_FormClosed");
	//LogMessage("","");
}
		 }

private: bool Display(bool isdisplay,Bitmap^ Image){
try{
		//if image specific settings
		if(isdisplay||StepThroughFlg)
			ImShow->ShowImage(Image);
	return true;
} catch ( Exception^ ex ) {
	ThrowError(ex, "Display");
	//LogMessage("","");
}
	}
/***********************************************************************************************/
//Function start running the stack
/***********************************************************************************************/
private: System::Void runToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	if(RunSanityChecker()			 ){
	if(StackExecutionThread&&StackExecutionThread->IsAlive)
	{
	;
	}
	else{

	
	StackExecutionThread = gcnew Thread(gcnew ThreadStart(this, &IPO_Stack::FullRun));  
    StackExecutionThread->IsBackground = true;
    
	RunningNotification=gcnew IPORunNotification();
	RunningNotification->IPOHandler=IPOHandler;
	RunningNotification->StackExecutionThread=StackExecutionThread;
	MainThread=this;
	
	RunningNotification->Log->AppendText("**************Start*****************\n");
	RunningNotification->Log->AppendText("Input Directory:"+IPOHandler->InputDirPath+"\n");
	RunningNotification->Log->AppendText("Output Directory:"+IPOHandler->OutputDirPath+"\n");
	StackExecutionThread->Start();
	RunningNotification->ShowDialog();
	}
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "runToolStripMenuItem_Click");
	//LogMessage("","");
}			 
	}

/***********************************************************************************************/
//Function to run single step run
/***********************************************************************************************/
void SingleStep(void){
try{
	//loop
			 
			 //isApplySettings
			 //Take input
			 //execuit
			 //Output result
			 //Display
				IPOHandler->Stop_BatchProcessing=false;
				IPOHandler->Stop_CamCapture=false;
				IPOHandler->Stop_DinamicMonitor=false;
				//TODO::Load this only once
				IPOHandler->CreateResultCSV(IPO_StackList);
				

				 //bool Val;
				 IPOHandler->StartQualityControlCounter();
			     RunningNotificationLogs("Waiting for input\n");
				 Bitmap^ InputIm=IPOHandler->Input();

				 if(InputIm) {
					RunningNotificationLogs("Input:"+IPOHandler->CurrentImgName+"\n");
					RunStep(InputIm);
				 
				 }
				 else
					  RunningNotificationLogs("No Input: Finished.\n");
				
				 
				  RunningNotificationLogs("Stack Run has finished.\n");
				  RunningNotificationLogs("**************END*****************\n");
} catch ( Exception^ ex ) {
	ThrowError(ex, "SingleStep");
	//LogMessage("","");
}
}


/***********************************************************************************************/
//Function make run stack continuously
/***********************************************************************************************/
void FullRun(void){
try{
	
			IPOHandler->LoadBatchProcessDir();

			IPOHandler->Stop_BatchProcessing=false;
			IPOHandler->Stop_CamCapture=false;
			IPOHandler->Stop_DinamicMonitor=false;
		
			IPOHandler->StartQualityControlCounter();
			IPOHandler->CreateResultCSV(IPO_StackList);

				for(;;){	
			      RunningNotificationLogs("Waiting for input\n");
				  Bitmap^ InputIm=IPOHandler->Input();


				 if(InputIm) {
				  RunningNotificationLogs("Input:"+IPOHandler->CurrentImgName+"\n");
				  RunStep(InputIm);
				  if(End_StepThroughFlg){
					  End_StepThroughFlg=false;
					  break;
				  }

				}
				 else{

						if(StepThroughFlg){
							End_StepThroughFlg=true;
							Next_StepThroughFlg=false;
							StepThroughFlg=false;
						}

					  RunningNotificationLogs("No Input: Finished.\n");
					  break;
				 }
				 
				 
				   RunningNotificationLogs("Stack Run has finished.\n");
				   RunningNotificationLogs("**************END*****************\n");
				}

} catch ( Exception^ ex ) {
	ThrowError(ex, "FullRun");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to run stack
/***********************************************************************************************/
private: Bitmap^ RunStep(Bitmap ^ Input)
		 {
try{			
				String^ GeneralSettingsPath=SettingFilesHandler->StackFilename;
			 	bool Val;
				int i;
				/******************************************************************************/
				String^ path=IPOHandler->GetNewSettingsPath(IPOHandler->CurrentImgName);
				if(path!=""){
					SettingFilesHandler->SetStackFileName(path);
					ReloadStackRunThread();
				}
				/******************************************************************************/
				IPOHandler->OutputInputName();
				 for(i=0; i< IPO_StackList->Length; i++)
				 {
					Color CurrentColor = Color::FromName( "Red" );
					IPO_StackList[i]->ShowProperty->BackColor=CurrentColor;
					if(i){
					Color DoneColor = Color::FromName( "Control" );
					IPO_StackList[i-1]->ShowProperty->BackColor=DoneColor;
					}
					IPO_StackList[i]->Input=Input;
					//IPO_StackList[i]->Input=(i==0)?Input:IPO_StackList[i-1]->Result;
					IPO_StackList[i]->Execuite();
					RunningNotificationLogs(IPO_StackList[i]->ShowProperty->Text+":" +IPOHandler->CurrentImgName+"\n");
					
					Val=Boolean::Parse(SettingFilesHandler->ReadProperty("Quality Control", IPO_StackList[i]->Properties)); 
					
					IPOHandler->Output(IPO_StackList[i],Val);
					
					Val=Boolean::Parse(SettingFilesHandler->ReadProperty("Display Result",IPO_StackList[i]->Properties)); 
					//Input=gcnew Bitmap(IPO_StackList[i]->Result);
					this->Display(Val,IPO_StackList[i]->Result);
					//Code to step through
					if(StepThroughFlg){
						while(!End_StepThroughFlg&&!Next_StepThroughFlg)
							Thread::Sleep(200);
						if(End_StepThroughFlg){
							i++;
							break;
						}
						if(Next_StepThroughFlg) Next_StepThroughFlg=false;

					}
					//End code to step through

					Input=IPO_StackList[i]->Result;
				 }

				 Color DoneColor = Color::FromName( "Control" );
				 IPO_StackList[i-1]->ShowProperty->BackColor=DoneColor;

				 IPOHandler->OutputResultImg(IPO_StackList[IPO_StackList->Length-1]->Result);

				 if(GeneralSettingsPath !=SettingFilesHandler->StackFilename){
					SettingFilesHandler->SetStackFileName(GeneralSettingsPath);
					ReloadStackRunThread();
				 }


				 return IPO_StackList[IPO_StackList->Length-1]->Result;
} catch ( Exception^ ex ) {
	ThrowError(ex, "RunStep");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function start running the single step stack
/***********************************************************************************************/
private: System::Void Stop_Click(System::Object^  sender, System::EventArgs^  e) {
try{

	if(RunSanityChecker()	){
	if(StackExecutionThread&&StackExecutionThread->IsAlive)
		{
			;
		}
	else{
			StackExecutionThread = gcnew Thread(gcnew ThreadStart(this, &IPO_Stack::SingleStep));  
			StackExecutionThread->IsBackground = true;
			RunningNotification=gcnew IPORunNotification();
			RunningNotification->IPOHandler=IPOHandler;
			RunningNotification->StackExecutionThread=StackExecutionThread;
			MainThread=this;
	
			RunningNotification->Log->AppendText("**************Start*****************\n");
			RunningNotification->Log->AppendText("Input Directory:"+IPOHandler->InputDirPath+"\n");
			RunningNotification->Log->AppendText("Output Directory:"+IPOHandler->OutputDirPath+"\n");
			StackExecutionThread->Start();
			RunningNotification->ShowDialog();
		}
	}
		
} catch ( Exception^ ex ) {
	ThrowError(ex, "Stop_Click");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to log stack run result
/***********************************************************************************************/
void StackRunThreadLog(void)
{
try{
	if(RunningNotification)
	RunningNotification->Log->AppendText(RunningNotificationLog);
} catch ( Exception^ ex ) {
	ThrowError(ex, "StackRunThreadLog");
	//LogMessage("","");
}
}


private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }

/***********************************************************************************************/
//Sanity checker for app configuration
/***********************************************************************************************/
private: bool RunSanityChecker()
		 {
try{	
	if(	!this->IPOHandler->InputDirPath||this->IPOHandler->InputDirPath==""){
	if(	!this->IPOHandler->VideoFilePath||this->IPOHandler->VideoFilePath==""){
		if(!this->IPOHandler->CaptureFromCam){
			ShowMessageBox("Input not Configured", "Input Error");
			return false;
		}}}

	
	
	if(!this->IPOHandler->OutputDirPath||this->IPOHandler->OutputDirPath==""){
		ShowMessageBox("Output not Configured", "Output Error");
		return false;
	}

	
	if(!SettingFilesHandler->StackLength()){
		ShowMessageBox("No Stack Elements pushed", "Satck Error");
		return false;
	}

	return true;
} catch ( Exception^ ex ) {
	ThrowError(ex, "menuStrip1_ItemClicked");
	//LogMessage("","");
}
		 }
/***********************************************************************************************/
//Function to show message in messagebox
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
private: System::Void startSteppingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	End_StepThroughFlg=false;
	StepThroughFlg=true;
	Next_StepThroughFlg=false;

	this->Single_step->Enabled=false;
	this->Run->Enabled=false;
	this->startSteppingToolStripMenuItem->Enabled=false;

	this->nextStepToolStripMenuItem->Enabled=true;
	this->endStepingToolStripMenuItem->Enabled=true;

	/******************Exection thread *************************************/
	if(RunSanityChecker()			 ){
	if(StackExecutionThread&&StackExecutionThread->IsAlive)
	{
	;
	}
	else{

	
	StackExecutionThread = gcnew Thread(gcnew ThreadStart(this, &IPO_Stack::FullRun));  
    StackExecutionThread->IsBackground = true;
    

	MainThread=this;
	
	
	StackExecutionThread->Start();

	}
	}

	/******************Exection thread *************************************/


} catch ( Exception^ ex ) {
	ThrowError(ex, "startSteppingToolStripMenuItem_Click");
	//LogMessage("","");
}

	
		 }
private: System::Void nextStepToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
	if(!StepThroughFlg)
		startSteppingToolStripMenuItem_Click(sender,e);
	else{

	End_StepThroughFlg=false;
	Next_StepThroughFlg=true;
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "nextStepToolStripMenuItem_Click");
	//LogMessage("","");
}
}
private: System::Void endStepingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
try{
   if(StepThroughFlg){

	End_StepThroughFlg=true;
	Next_StepThroughFlg=false;
	StepThroughFlg=false;

	this->Single_step->Enabled=true;
	this->Run->Enabled=true;
	this->startSteppingToolStripMenuItem->Enabled=true;
	this->nextStepToolStripMenuItem->Enabled=false;
	this->endStepingToolStripMenuItem->Enabled=false;
	}
} catch ( Exception^ ex ) {
	ThrowError(ex, "endStepingToolStripMenuItem_Click");
	//LogMessage("","");
}

		 }
};


}
