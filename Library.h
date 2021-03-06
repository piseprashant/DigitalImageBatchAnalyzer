#pragma once
#include "PropertyEditBox.h"
#include "IPO_Stack.h"
#include "ParameterObject.h"
#include "SettingFiles.h"
namespace DigitalImageBatchAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Library
	/// </summary>
	public ref class Library : public System::Windows::Forms::Form
	{
	public:
		Library(void)
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
		~Library()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::ListView^  PropertyShow;
	protected: 


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  ImProc;

	private: System::Windows::Forms::TabPage^  Measure;

	private: System::Windows::Forms::TabPage^  ObjectCount;

	private: System::Windows::Forms::Panel^  panel1;




	private: System::Windows::Forms::ColumnHeader^  Value;
	private: System::Windows::Forms::ColumnHeader^  Property;









//MyVars
	public: IPO_Stack^ IPOStack;//This should come from parent Form
	public: SettingFiles^ SettingFilesHandler;//This should come from parent Form
	

//********************************************************************************************************************************//
//IPOs
			ParameterObject^ Current_IPO;
		static	ParameterObject^ IPO_BinaryThreshold;
		static	ParameterObject^ IPO_RGBThreshold;
		static ParameterObject^  IPO_Crop;
		static ParameterObject^  IPO_Edges;
		static ParameterObject^  IPO_RGBPercentage;
		static ParameterObject^	 IPO_BWPercentage;
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
	private: System::Windows::Forms::Panel^  ParameterMeasurementPanel;
	private: System::Windows::Forms::Panel^  ObjectCountPanel;
	public: 

	public: 
		//IPOs
//********************************************************************************************************************************//

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
			this->ImProc = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Measure = (gcnew System::Windows::Forms::TabPage());
			this->ParameterMeasurementPanel = (gcnew System::Windows::Forms::Panel());
			this->ObjectCount = (gcnew System::Windows::Forms::TabPage());
			this->PropertyShow = (gcnew System::Windows::Forms::ListView());
			this->Property = (gcnew System::Windows::Forms::ColumnHeader());
			this->Value = (gcnew System::Windows::Forms::ColumnHeader());
			this->ObjectCountPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->ImProc->SuspendLayout();
			this->Measure->SuspendLayout();
			this->ObjectCount->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->AutoScroll = true;
			this->splitContainer1->Panel1->Controls->Add(this->tabControl1);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Library::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->PropertyShow);
			this->splitContainer1->Size = System::Drawing::Size(429, 306);
			this->splitContainer1->SplitterDistance = 261;
			this->splitContainer1->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->ImProc);
			this->tabControl1->Controls->Add(this->Measure);
			this->tabControl1->Controls->Add(this->ObjectCount);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(254, 293);
			this->tabControl1->TabIndex = 0;
			// 
			// ImProc
			// 
			this->ImProc->AutoScroll = true;
			this->ImProc->AutoScrollMargin = System::Drawing::Size(10, 10);
			this->ImProc->AutoScrollMinSize = System::Drawing::Size(10, 0);
			this->ImProc->Controls->Add(this->panel1);
			this->ImProc->Location = System::Drawing::Point(4, 22);
			this->ImProc->Name = L"ImProc";
			this->ImProc->Padding = System::Windows::Forms::Padding(3);
			this->ImProc->Size = System::Drawing::Size(246, 267);
			this->ImProc->TabIndex = 0;
			this->ImProc->Text = L"Pre Processing";
			this->ImProc->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(8, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(210, 996);
			this->panel1->TabIndex = 0;
			// 
			// Measure
			// 
			this->Measure->AutoScroll = true;
			this->Measure->Controls->Add(this->ParameterMeasurementPanel);
			this->Measure->Location = System::Drawing::Point(4, 22);
			this->Measure->Name = L"Measure";
			this->Measure->Padding = System::Windows::Forms::Padding(3);
			this->Measure->Size = System::Drawing::Size(246, 267);
			this->Measure->TabIndex = 1;
			this->Measure->Text = L"Measurements";
			this->Measure->UseVisualStyleBackColor = true;
			// 
			// ParameterMeasurementPanel
			// 
			this->ParameterMeasurementPanel->Location = System::Drawing::Point(3, 3);
			this->ParameterMeasurementPanel->Name = L"ParameterMeasurementPanel";
			this->ParameterMeasurementPanel->Size = System::Drawing::Size(210, 996);
			this->ParameterMeasurementPanel->TabIndex = 1;
			// 
			// ObjectCount
			// 
			this->ObjectCount->Controls->Add(this->ObjectCountPanel);
			this->ObjectCount->Location = System::Drawing::Point(4, 22);
			this->ObjectCount->Name = L"ObjectCount";
			this->ObjectCount->Padding = System::Windows::Forms::Padding(3);
			this->ObjectCount->Size = System::Drawing::Size(246, 267);
			this->ObjectCount->TabIndex = 2;
			this->ObjectCount->Text = L"Object Counting";
			this->ObjectCount->UseVisualStyleBackColor = true;
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
			this->PropertyShow->Size = System::Drawing::Size(164, 306);
			this->PropertyShow->TabIndex = 0;
			this->PropertyShow->UseCompatibleStateImageBehavior = false;
			this->PropertyShow->View = System::Windows::Forms::View::Details;
			this->PropertyShow->ItemActivate += gcnew System::EventHandler(this, &Library::PropertyShow_ItemActivate);
			this->PropertyShow->SelectedIndexChanged += gcnew System::EventHandler(this, &Library::PropertyShow_SelectedIndexChanged);
			// 
			// Property
			// 
			this->Property->Text = L"Property";
			this->Property->Width = 94;
			// 
			// Value
			// 
			this->Value->Text = L"Value";
			this->Value->Width = 64;
			// 
			// ObjectCountPanel
			// 
			this->ObjectCountPanel->Location = System::Drawing::Point(3, 3);
			this->ObjectCountPanel->Name = L"ObjectCountPanel";
			this->ObjectCountPanel->Size = System::Drawing::Size(210, 996);
			this->ObjectCountPanel->TabIndex = 2;
			this->ObjectCountPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Library::ObjectCountPanel_Paint);
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(429, 306);
			this->Controls->Add(this->splitContainer1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(540, 0);
			this->Name = L"Library";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"IPO Library";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Library::Library_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->ImProc->ResumeLayout(false);
			this->Measure->ResumeLayout(false);
			this->ObjectCount->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
/***********************************************************************************************/
//Function to run when library starts
/***********************************************************************************************/
	private: System::Void Library_Load(System::Object^  sender, System::EventArgs^  e) {
try{
				this->SettingFilesHandler->isIPOLibraryAvilable=true;
				MakeLibraryObjects();
} catch ( Exception^ ex ) {
	ThrowError(ex, "Library_Load");
	//LogMessage("","");
}

			 }
		
/***********************************************************************************************/
//Function to show properies in the GUI
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
//Function to add items in the list
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
//Function to add items to list
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
//Function to execuite when user click on any item
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
			 ShowBox->ShowDialog();
			 
} catch ( Exception^ ex ) {
	ThrowError(ex, "PropertyShow_ItemActivate");
	//LogMessage("","");
}			 
			 }
private: System::Void BinaryThreshold_Click(System::Object^  sender, System::EventArgs^  e) {

/*
			  
				array<String^>^ argstring={"64","128","256"};
				ListViewItem^ Item=this->PopulateItems("Threashold","128",argstring,"Value Range: 0:256 \n Value< Threshold = 0 \n Value>Threshold =255 ");
				
				array<String^>^ truefalsetring={"False","True"};
				ListViewItem^ Item2=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
				ListViewItem^ Item3=this->PopulateItems("Quality Controll","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");				
				array<ListViewItem^>^ tmp={Item,Item2,Item3};
				this->ShowProperties(tmp);*/
		 }
private: System::Void RGBThreshold_Click(System::Object^  sender, System::EventArgs^  e) {
			 
/*				
				ListViewItem^ Item=this->PopulateItems("R","128","Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
				ListViewItem^ Item1=this->PopulateItems("G","128","Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
				ListViewItem^ Item2=this->PopulateItems("B","128","Value Range: 0:256 \n X< Value not counted \n X>Value counted ");
				
				array<String^>^ truefalsetring={"False","True"};
				ListViewItem^ Item3=this->PopulateItems("Display Result","False",truefalsetring,"True value displays the result runtime");
				ListViewItem^ Item4=this->PopulateItems("Quality Controll","False",truefalsetring,"True value Enables quality check \nmechanism for the parameter");
				
				array<ListViewItem^>^ tmp={Item,Item1,Item2,Item3,Item4};
				this->ShowProperties(tmp);
				*/
		 }
private: System::Void BT_Add_Click(System::Object^  sender, System::EventArgs^  e) {

			  }


/***********************************************************************************************/
//Function to create library objects

//Adding object proceedure
//	1. Change names 
//	2. declare object global add to array
//	3. add enumerator
//	4. add push and pop button accordingly
//	5. add object kind accordingly
/***********************************************************************************************/

		 private: void MakeLibraryObjects()
				  {
try{
//****************************************************IPO_BinaryThreshold*********************************************************//
				  //Make the Binary threshold Object
				  ParameterObjectinit(SettingFilesHandler,IPO_BinaryThreshold,Enum_BinaryThreshold,"Threshold","128","Display Result","False","Quality Control","False");
				  IPO_BinaryThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_BinaryThresholdPrprtyButton=IPO_BinaryThreshold->CreatePropertyButton(Point(0,0),"Binary Threshold",0);
				  IPO_BinaryThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_BinaryThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BinaryThresholdPushButton=IPO_BinaryThreshold->CreatePushButton(Point(PropertyButtonWidth,0),1);
				  IPO_BinaryThresholdPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_BinaryThresholdPushButton);
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
				  IPO_RGBThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_RGBThresholdPrprtyButton=IPO_RGBThreshold->CreatePropertyButton(Point(0,(ButtonHight*1)),"RGB Threshold",2);
				  IPO_RGBThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_RGBThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_RGBThresholdPushButton=IPO_RGBThreshold->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_RGBThresholdPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_RGBThresholdPushButton);
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
				  IPO_List->SetValue(IPO_RGBThreshold,1);//Setting IPO value to array
//********************************************************************************************************************************//				  
//*********************************************IPO_Crop*********************************************************************//				  
				  //Make the Crop Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Crop,Enum_Crop,"Method","Whole","CornerA","0,0","CornerB","100,0","CornerC","100,100","CornerD","0,100","Display Result","False","Quality Control","False");
				  IPO_Crop->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_CropPrprtyButton=IPO_Crop->CreatePropertyButton(Point(0,(ButtonHight*2)),"Crop",4);
				  IPO_CropPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_CropPrprtyButton);
				  System::Windows::Forms::Button^ IPO_CropPushButton=IPO_Crop->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_CropPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_CropPushButton);
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
//*********************************************IPO_Edges*********************************************************************//				  
				  //Make the Edge Object
				  ParameterObjectinit(SettingFilesHandler,IPO_Edges,Enum_Edges,"threshold1","32","threshold2","32","apertureSize","3","Display Result","False","Quality Control","False");
				  IPO_Edges->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_EdgePrprtyButton=IPO_Edges->CreatePropertyButton(Point(0,(ButtonHight*2)),"Edges",4);
				  IPO_EdgePrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_EdgePrprtyButton);
				  System::Windows::Forms::Button^ IPO_EdgePushButton=IPO_Edges->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_EdgePushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_EdgePushButton);
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

				  
				  
				  
//*********************************************IPO_RGBPercentage*********************************************************************//				  
				  //Make the RGBPercentage Object
				  ParameterObjectinit(SettingFilesHandler,IPO_RGBPercentage,Enum_RGBPercentage,"Display Result","False","Quality Control","False");
				  IPO_RGBPercentage->ObjectKind=ParameterMeasurement;
				  System::Windows::Forms::Button^ IPO_RGBPercentagePrprtyButton=IPO_RGBPercentage->CreatePropertyButton(Point(0,(ButtonHight*1)),"RGB Percentage",2);
				  IPO_RGBPercentagePrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_RGBPercentagePrprtyButton);
				  System::Windows::Forms::Button^ IPO_RGBPercentagePushButton=IPO_RGBPercentage->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_RGBPercentagePushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_RGBPercentagePushButton);
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
				  IPO_BWPercentagePrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_BWPercentagePopButton=IPO_BWPercentage->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_BWPercentagePopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_BWPercentage->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_BWPercentage,4);//Setting IPO value to array
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
				  IPO_BackgroundSubstractionPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_BackgroundSubstractionPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BackgroundSubstractionPushButton=IPO_BackgroundSubstraction->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BackgroundSubstractionPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_BackgroundSubstractionPushButton);
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
				  IPO_BrightnessPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_BrightnessPrprtyButton);
				  System::Windows::Forms::Button^ IPO_BrightnessPushButton=IPO_Brightness->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BrightnessPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_BrightnessPushButton);
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
				  IPO_ContrastPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_ContrastPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ContrastPushButton=IPO_Contrast->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ContrastPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_ContrastPushButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"1","1.5","2","2.5"};
					ListViewItem^ Item1=this->PopulateItems("Value","1",argstring,"Enter the Contrast value to be applied Range (0.1-5.0)");
					
					
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
				  IPO_SaturationPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_SaturationPrprtyButton);
				  System::Windows::Forms::Button^ IPO_SaturationPushButton=IPO_Saturation->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_SaturationPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_SaturationPushButton);
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
				  IPO_CounterSearchPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_CounterSearchPrprtyButton);
				  System::Windows::Forms::Button^ IPO_CounterSearchPushButton=IPO_CounterSearch->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_CounterSearchPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_CounterSearchPushButton);
				  //Set the Property list for Crop
				  {	
					array<String^>^ argstring={"All","OnlyExternal", "OnlyInternal"};
					ListViewItem^ Item1=this->PopulateItems("Contour","All",argstring,"Contour level");
					array<String^>^ argstring2={"100","10", "200"};
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
				  IPO_IMCalculatorPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_IMCalculatorPrprtyButton);
				  System::Windows::Forms::Button^ IPO_IMCalculatorPushButton=IPO_IMCalculator->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_IMCalculatorPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_IMCalculatorPushButton);
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
				  IPO_BoundingShapePrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_BoundingShapePrprtyButton);
				  System::Windows::Forms::Button^ IPO_BoundingShapePushButton=IPO_BoundingShape->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_BoundingShapePushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_BoundingShapePushButton);
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
				  IPO_ColorCNVPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_ColorCNVPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ColorCNVPushButton=IPO_ColorCNV->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ColorCNVPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_ColorCNVPushButton);
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
				  IPO_AreaThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_AreaThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_AreaThresholdPushButton=IPO_AreaThreshold->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_AreaThresholdPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_AreaThresholdPushButton);
				  //Set the Property list for Crop
				  {		
					array<String^>^ argstring={"Threshold"};
					ListViewItem^ Item1=this->PopulateItems("AreaThreshold","Threshold",argstring,"Determine Area the threshold");

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
				  ParameterObjectinit(SettingFilesHandler,IPO_ParameterThreshold,Enum_ParameterThreshold,"PerimeterThreshold","Threshold","Display Result","False","Quality Control","False");
				  IPO_ParameterThreshold->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_ParameterThresholdPrprtyButton=IPO_ParameterThreshold->CreatePropertyButton(Point(0,(ButtonHight*2)),"PerimeterThreshold",4);
				  IPO_ParameterThresholdPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_ParameterThresholdPrprtyButton);
				  System::Windows::Forms::Button^ IPO_ParameterThresholdPushButton=IPO_ParameterThreshold->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_ParameterThresholdPushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_ParameterThresholdPushButton);
				  //Set the Property list for Crop
				  {		
					array<String^>^ argstring={"Threshold"};
					ListViewItem^ Item1=this->PopulateItems("PerimeterThreshold","Threshold",argstring,"Determine the Parameter threshold");

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
				  IPO_AVGBrightnessPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGBrightnessPopButton=IPO_AVGBrightness->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGBrightnessPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
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
				  IPO_AVGRGBPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGRGBPopButton=IPO_AVGRGB->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGRGBPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
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
				  IPO_LumaPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_LumaPopButton=IPO_Luma->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_LumaPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
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
				  IPO_AVGLightnessPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGLightnessPopButton=IPO_AVGLightness->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGLightnessPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
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
				  IPO_AVGIntensityPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_AVGIntensityPopButton=IPO_AVGIntensity->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_AVGIntensityPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
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
				  ParameterObjectinit(SettingFilesHandler,IPO_DePixalate,Enum_DePixalate,"DePixalate"," kernel size ","Display Result","False","Quality Control","False");
				  IPO_DePixalate->ObjectKind=PreProcessing;
				  System::Windows::Forms::Button^ IPO_DePixalatePrprtyButton=IPO_DePixalate->CreatePropertyButton(Point(0,(ButtonHight*2)),"DePixalate",4);
				  IPO_DePixalatePrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  this->panel1->Controls->Add(IPO_DePixalatePrprtyButton);
				  System::Windows::Forms::Button^ IPO_DePixalatePushButton=IPO_DePixalate->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*2)),5);
				  IPO_DePixalatePushButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      this->panel1->Controls->Add(IPO_DePixalatePushButton);
				  //Set the Property list for Crop
				  {		
					array<String^>^ argstring={"kernel size"};
					ListViewItem^ Item1=this->PopulateItems("DePixalate"," kernel size",argstring,"Determine the  kernel size for PreProcessing");

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
				  IPO_CounterPrprtyButton->Click += gcnew System::EventHandler(this, &Library::IPO_ShowPropertyAction);
				  System::Windows::Forms::Button^ IPO_CounterPopButton=IPO_Counter->CreatePushButton(Point(PropertyButtonWidth,(ButtonHight*1)),3);
				  IPO_CounterPopButton->Click += gcnew System::EventHandler(this, &Library::IPO_PushAction);
			      //Set the Property list for Binary threshold 
				  {	
					array<String^>^ truefalsetring={"NA","NA"};
					ListViewItem^ Item3=this->PopulateItems("NA","NA",truefalsetring,"NA");
					
					array<ListViewItem^>^ tmp={Item3};
					IPO_Counter->PropertyList=tmp;
				  }
				  IPO_List->SetValue(IPO_Counter,22);//Setting IPO value to array
//********************************************************************************************************************************//				  
 ReloadLibrary();


} catch ( Exception^ ex ) {
	ThrowError(ex, "MakeLibraryObjects");
	//LogMessage("","");
}				  
}


/***********************************************************************************************/
//Function to reload Library from the IPOStacks
/***********************************************************************************************/

public: void ReloadLibrary(){
try{
			
			
			this->panel1->Controls->Clear();
			this->ParameterMeasurementPanel->Controls->Clear();

			int PreprocessingPos=0;
			int ParameterMeasurementPos=0;

			for(int pos=0,i=0; i< IPO_List->Length; i++)
			{
					
				 
				if(IPO_List[i]->ObjectKind==PreProcessing){ 

				IPO_List[i]->ShowProperty->Location=Point(0,PreprocessingPos);
				this->panel1->Controls->Add(IPO_List[i]->ShowProperty);
				IPO_List[i]->Push->Location=Point(PropertyButtonWidth,PreprocessingPos);
				this->panel1->Controls->Add(IPO_List[i]->Push);
				PreprocessingPos+=ButtonHight;

				}
				else if(IPO_List[i]->ObjectKind==ParameterMeasurement){ 

				IPO_List[i]->ShowProperty->Location=Point(0,ParameterMeasurementPos);
				this->ParameterMeasurementPanel->Controls->Add(IPO_List[i]->ShowProperty);
				IPO_List[i]->Push->Location=Point(PropertyButtonWidth,ParameterMeasurementPos);
				this->ParameterMeasurementPanel->Controls->Add(IPO_List[i]->Push);
				ParameterMeasurementPos+=ButtonHight;

				}
				
			}

} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadStack");
	//LogMessage("","");
}			

			//Here clear the panel and redraw buttons again
}



//********************************************************************************************************************************//
//Linking binary threshold button action

/***********************************************************************************************/
//Function to Execuite when user clicks on Add button
/***********************************************************************************************/
private: System::Void IPO_PushAction(System::Object^  sender, System::EventArgs^  e) {
try{
			 System::Windows::Forms::Button^ button=(System::Windows::Forms::Button^)sender;
			 String^ ID=(String^)button->Tag;
			 Int32 id;
			 Int32::TryParse((String^)button->Tag,id);

			 ParameterObject^ StackElement;

			 for(int i=0;i<IPO_List->Length;i++)
			 {
				 if(IPO_List[i]->UniqueID==id)
					 StackElement=IPO_List[i];
			 }
			 Current_IPO=StackElement;
			 // StackElement->PopingFromStack();
			 //this->ReloadStack();


			 StackElement->Pushing2Stack();
			 this->UpdateStack();
			 
			 this->ShowProperties(StackElement->PropertyList);
			 if(this->SettingFilesHandler->isIPOStackAvilable4Reload)
			 {
				this->IPOStack->ReloadStack();
			 }
			  
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_PushAction");
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

			 for(int i=0;i<IPO_List->Length;i++)
			 {
				 if(IPO_List[i]->UniqueID==id)
					 StackElement=IPO_List[i];
			 }
			 Current_IPO=StackElement;
			 this->ShowProperties(StackElement->PropertyList);
} catch ( Exception^ ex ) {
	ThrowError(ex, "IPO_ShowPropertyAction");
	//LogMessage("","");
}
}
//********************************************************************************************************************************//


//********************************************************************************************************************************//

private: void UpdateStack()
{


}

private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }

/***********************************************************************************************/
//Function to execuite when form gets closed
/***********************************************************************************************/
private: System::Void Library_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
try{
			 this->SettingFilesHandler->isIPOLibraryAvilable=false;
} catch ( Exception^ ex ) {
	ThrowError(ex, "Library_FormClosed");
	//LogMessage("","");
}
		 }
private: System::Void PropertyShow_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ObjectCountPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}
