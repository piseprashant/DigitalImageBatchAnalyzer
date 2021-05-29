#pragma once
#include "SettingFiles.h"


using namespace System::Drawing;
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	#define ParameterObjectinit(settingfiles,Object,ID,...)  {array<String^>^ s ={##__VA_ARGS__};  Object=gcnew ParameterObject(SettingFilesHandler->Properties2Str(s),ID,settingfiles);}
	#define PUSHPOPBUTTON_Font (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, \
											static_cast<System::Byte>(0)))

	
#define PropertyBUTTON_Font  (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))

#define ButtonHight 30
#define PropertyButtonWidth 150
#define PushPopButtonWidth 50
#define PUSHPOPBtnSize System::Drawing::Size(PushPopButtonWidth, ButtonHight)
#define PropertyShowSize System::Drawing::Size(PropertyButtonWidth, ButtonHight)	

typedef enum ParameterObjectKind_S{
	PreProcessing,
	ParameterMeasurement,
	ObjectCount,
} ParameterObjectKind;



ref class ParameterObject
{

public: Stack_Section UniqueID;
public: Bitmap^ Input;
public: Bitmap^ Result;
public: String^ Properties;
public: String^ ExtraResults;
public: System::Windows::Forms::Button^ Push;
public: System::Windows::Forms::Button^ Pop;
public: System::Windows::Forms::Button^ ShowProperty;
public:array<ListViewItem^>^ PropertyList;

public: SettingFiles^ SettingFilesHandler;
public: ParameterObjectKind ObjectKind;



public:

/**********************************************************************************************
	  Constructor of parameter object
**********************************************************************************************/
	ParameterObject(String^ properties, Stack_Section uniqueID, SettingFiles^ settingfiles)
	{
try{
		this->UniqueID=uniqueID;
		this-> Properties=properties;
		this->SettingFilesHandler=settingfiles;
		
} catch ( Exception^ ex ) {
	ThrowError(ex, "ParameterObject");
	//LogMessage("","");
}

	}
/**********************************************************************************************
	  Copy constructor of parameter object
**********************************************************************************************/
	ParameterObject(ParameterObject^ obj){
try{
		this->UniqueID=obj->UniqueID;
		this->ObjectKind=obj->ObjectKind;
		this->Properties=gcnew String(obj->Properties);
		this->SettingFilesHandler=obj->SettingFilesHandler;

		this->ShowProperty=this->CreatePropertyButton(Point(0,0),obj->ShowProperty->Text,0);
		//this->ShowProperty->Click+=obj->ShowProperty->Click;

		this->Push=this->CreatePopButton(Point(0,0),0);
		//this->Push->Click->Add(obj->Pop->Click);

		this->PropertyList=(array<ListViewItem^>^)obj->PropertyList->Clone();

		for(int i=0; i<obj->PropertyList->Length;i++){
			this->PropertyList[i]=(ListViewItem^)obj->PropertyList[i]->Clone();
		}

} catch ( Exception^ ex ) {
	ThrowError(ex, "ParameterObject");
	//LogMessage("","");
}		

	}
/**********************************************************************************************
	 
**********************************************************************************************/
public: void GenerateListItems()
		{
			//Generate list items to display for the list
		}

/**********************************************************************************************
	 Return string conatinign parameters to put into Database
**********************************************************************************************/
public: void DatabseItemsListItems()
		{
			//Generate list items to display for the list
		}

/**********************************************************************************************
	 Image processing task of parameter object
**********************************************************************************************/
public: void Execuite();
		
/**********************************************************************************************
	 Function to push the object to stack
**********************************************************************************************/
public: void Pushing2Stack()
		{
try{
			//Adding self to stack.
			String^ Properties;
			Int32 ID=(Int32)this->UniqueID;
			
			for(;(ID-this->UniqueID)<MAXSTACKIPO;ID++){
			if(SettingFilesHandler->ReadStackSection((Stack_Section)ID,Properties)==NoStackSectionError)
				break;
			}
			if((ID-this->UniqueID)<MAXSTACKIPO){
				this->SettingFilesHandler->UpdateStackSection((Stack_Section)ID,this->Properties);
			this->SettingFilesHandler->UpdateStackFile();
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "Pushing2Stack");
	//LogMessage("","");
}
		}
/**********************************************************************************************
	  Function to pop the object from the stack
**********************************************************************************************/
public: void PopingFromStack()
		{
try{
			//Adding self to stack.
			this->SettingFilesHandler->RemoveStackSection(this->UniqueID);
			this->SettingFilesHandler->UpdateStackFile();
} catch ( Exception^ ex ) {
	ThrowError(ex, "PopingFromStack");
	//LogMessage("","");
}
		}
/**********************************************************************************************
	  Create push button for the parameter stack
**********************************************************************************************/
public: System::Windows::Forms::Button^ CreatePushButton(System::Drawing::Point Point, int tabindex){
try{
											this->Push =	(gcnew System::Windows::Forms::Button());
											this->Push->Font = PUSHPOPBUTTON_Font;
											this->Push->Location = Point;
											//Button->Name = String::Concat(this->UniqueID,"Push");
											this->Push->Size = PUSHPOPBtnSize;
											this->Push->TabIndex = tabindex;
											this->Push->Text = L"Push";
											this->Push->UseVisualStyleBackColor = true;
											this->Push->Tag=String::Format("{0}",(int)this->UniqueID);
											return this->Push;
} catch ( Exception^ ex ) {
	ThrowError(ex, "CreatePushButton");
	//LogMessage("","");
}
		}
/**********************************************************************************************
	 Creating a pop button for the parameter stack
**********************************************************************************************/
public: System::Windows::Forms::Button^ CreatePopButton(System::Drawing::Point Point, int tabindex){
try{			
											this->Pop =	(gcnew System::Windows::Forms::Button());
											this->Pop->Font = PUSHPOPBUTTON_Font;
											this->Pop->Location = Point;
											//Button->Name = String::Concat(this->UniqueID,"Pop");
											this->Pop->Size = PUSHPOPBtnSize;
											this->Pop->TabIndex = tabindex;
											this->Pop->Text = L"Pop";
											this->Pop->UseVisualStyleBackColor = true;
											this->Pop->Tag=String::Format("{0}",(int)this->UniqueID);
											return this->Pop;
} catch ( Exception^ ex ) {
	ThrowError(ex, "CreatePopButton");
	//LogMessage("","");
}
		}
/**********************************************************************************************
	  Create the property button for the object
**********************************************************************************************/

public: System::Windows::Forms::Button^ CreatePropertyButton(System::Drawing::Point Point,String^ Name, int tabindex){
try{		
											this->ShowProperty =	(gcnew System::Windows::Forms::Button());
											this->ShowProperty->Font = PropertyBUTTON_Font;
											this->ShowProperty->Location = Point;
											//Button->Name = String::Concat(this->UniqueID,"Push");
											this->ShowProperty->Size = PropertyShowSize;
											this->ShowProperty->TabIndex = tabindex;
											this->ShowProperty->Text = Name;
											this->ShowProperty->Tag=String::Format("{0}",(int)this->UniqueID);
											this->ShowProperty->UseVisualStyleBackColor = true;
											return this->ShowProperty;
} catch ( Exception^ ex ) {
	ThrowError(ex, "CreatePropertyButton");
	//LogMessage("","");
}											
		}




/***********************************************************************************************/
//Function to convert results and parameters simple desired form
/***********************************************************************************************/
		
void ConvertionLayer(String^& Results, String^& Parameters)
{
	
	Stack_Section ID=this->UniqueID;
	

	if((ID>=Enum_BinaryThreshold)&&ID<=(Enum_BinaryThreshold+MAXSTACKIPO)){

	Parameters=SettingFilesHandler->ReadProperty("Threshold",this->Properties);

	
	}
	else if((ID>=Enum_RGBThreshold)&&ID<=(Enum_RGBThreshold+MAXSTACKIPO)){
	Parameters=SettingFilesHandler->ReadProperty("R",this->Properties);
	Parameters=Parameters+","+SettingFilesHandler->ReadProperty("G",this->Properties);
	Parameters=Parameters+","+SettingFilesHandler->ReadProperty("B",this->Properties);
	}
	else if((ID>=Enum_Crop)&&ID<=(Enum_Crop+MAXSTACKIPO)){
	Parameters=SettingFilesHandler->ReadProperty("Method",this->Properties);
	if(Parameters == "Custom"){
	Parameters=Parameters+"(["+SettingFilesHandler->ReadProperty("CornerA",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerB",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerC",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerD",this->Properties)+"]";
	Parameters=Parameters+")";
	}
	}
	else if((ID>=Enum_RGBPercentage)&&ID<=(Enum_RGBPercentage+MAXSTACKIPO)){
	Parameters=SettingFilesHandler->ReadProperty("Method",this->Properties);
	if(Parameters == "Custom"){
	Parameters=Parameters+"(["+SettingFilesHandler->ReadProperty("CornerA",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerB",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerC",this->Properties)+"]";
	Parameters=Parameters+",["+SettingFilesHandler->ReadProperty("CornerD",this->Properties)+"]";
	Parameters=Parameters+")";
	Results=SettingFilesHandler->ReadProperty("Red Pixel Percentage",this->ExtraResults);
	Results=Results+","+SettingFilesHandler->ReadProperty("Green Pixels Percentage",this->ExtraResults);
	Results=Results+","+SettingFilesHandler->ReadProperty("Blue Pixels Percentage",this->ExtraResults);
	}
	}
	else if((ID>=Enum_BWPercentage)&&ID<=(Enum_BWPercentage+MAXSTACKIPO)){
	Results=SettingFilesHandler->ReadProperty("Black Pixels Percentage",this->ExtraResults);
	Results=Results+","+SettingFilesHandler->ReadProperty("White Pixel Percentage",this->ExtraResults);
	
	}


	Parameters="'"+Parameters+"'";
	Results="'"+Results+"'";
	}
	
/***********************************************************************************************/
//Function to convert results and parameters simple desired form
/***********************************************************************************************/
	
String^ ConvertionLayer2(int number)
{
	
	Stack_Section ID=this->UniqueID;
	
	String^ Parameters;
	
	String^ Name=String::Format("{0}-{1}",this->ShowProperty->Text,number);

    

	if((ID>=Enum_BinaryThreshold)&&ID<=(Enum_BinaryThreshold+MAXSTACKIPO)){

	Parameters = "`"+Name+"`='"+SettingFilesHandler->ReadProperty("Threshold",this->Properties)+"'";

	
	}
	else if((ID>=Enum_RGBThreshold)&&ID<=(Enum_RGBThreshold+MAXSTACKIPO)){

	Parameters="`"+Name+"(Red Threshold)`='"+SettingFilesHandler->ReadProperty("R",this->Properties)+"'";
	Parameters+=",`"+Name+"(Green Threshold)`='"+SettingFilesHandler->ReadProperty("G",this->Properties)+"'";
	Parameters+=",`"+Name+"(Blue Threshold)`='"+SettingFilesHandler->ReadProperty("B",this->Properties)+"'";


	}
	else if((ID>=Enum_Crop)&&ID<=(Enum_Crop+MAXSTACKIPO)){

	Parameters="`"+Name+"(Method)`='"+SettingFilesHandler->ReadProperty("Method",this->Properties)+"'";
	if(SettingFilesHandler->ReadProperty("Method",this->Properties) == "Custom"){

	Parameters+=",`"+Name+"(CornerA)`='"+SettingFilesHandler->ReadProperty("CornerA",this->Properties)+"'";
	Parameters+=",`"+Name+"(CornerB)`='"+SettingFilesHandler->ReadProperty("CornerB",this->Properties)+"'";
	Parameters+=",`"+Name+"(CornerC)`='"+SettingFilesHandler->ReadProperty("CornerC",this->Properties)+"'";
	Parameters+=",`"+Name+"(CornerD)`='"+SettingFilesHandler->ReadProperty("CornerD",this->Properties)+"'";

	}
	}
	else if((ID>=Enum_RGBPercentage)&&ID<=(Enum_RGBPercentage+MAXSTACKIPO)){

	Parameters="`"+Name+"(Red Percentage)`='"+SettingFilesHandler->ReadProperty("Red Pixel Percentage",this->ExtraResults)+"'";
	Parameters+=",`"+Name+"(Green Percentage)`='"+SettingFilesHandler->ReadProperty("Green Pixels Percentage",this->ExtraResults)+"'";
	Parameters+=",`"+Name+"(Blue Percentage)`='"+SettingFilesHandler->ReadProperty("Blue Pixels Percentage",this->ExtraResults)+"'";
	
	}
	else if((ID>=Enum_BWPercentage)&&ID<=(Enum_BWPercentage+MAXSTACKIPO)){

	Parameters="`"+Name+"(Black Percentage)`='"+SettingFilesHandler->ReadProperty("Black Pixels Percentage",this->ExtraResults)+"'";
	Parameters+=",`"+Name+"(White Percentage)`='"+SettingFilesHandler->ReadProperty("White Pixel Percentage",this->ExtraResults)+"'";
	
	
	}


	return Parameters;
}

/***********************************************************************************************/
//Function to convert results and parameters simple desired form
/***********************************************************************************************/
String^ GenerateFields(int number)
{
	
	Stack_Section ID=this->UniqueID;
	String^ Fields;
	
	String^ Name=String::Format("{0}-{1}",this->ShowProperty->Text,number);

	if((ID>=Enum_BinaryThreshold)&&ID<=(Enum_BinaryThreshold+MAXSTACKIPO)){

	
	
	Fields="`"+Name+"` INT NULL";
	
	}
	else if((ID>=Enum_RGBThreshold)&&ID<=(Enum_RGBThreshold+MAXSTACKIPO)){

	Fields="`"+Name+"(Red Threshold)` INT NULL";
	Fields+=",`"+Name+"(Green Threshold)` INT NULL";
	Fields+=",`"+Name+"(Blue Threshold)` INT NULL";
	
	}
	else if((ID>=Enum_Crop)&&ID<=(Enum_Crop+MAXSTACKIPO)){

	Fields="`"+Name+"(Method)` VARCHAR(200) NULL";
	Fields+=",`"+Name+"(CornerA)` VARCHAR(200) NULL";
	Fields+=",`"+Name+"(CornerB)` VARCHAR(200) NULL";
	Fields+=",`"+Name+"(CornerC)` VARCHAR(200) NULL";
	Fields+=",`"+Name+"(CornerD)` VARCHAR(200) NULL";

	
	
	}
	else if((ID>=Enum_RGBPercentage)&&ID<=(Enum_RGBPercentage+MAXSTACKIPO)){
	Fields="`"+Name+"(Red Percentage)` INT NULL";
	Fields+=",`"+Name+"(Green Percentage)` INT NULL";
	Fields+=",`"+Name+"(Blue Percentage)` INT NULL";
	}
	else if((ID>=Enum_BWPercentage)&&ID<=(Enum_BWPercentage+MAXSTACKIPO)){
	Fields="`"+Name+"(Black Percentage)` INT NULL";
	Fields+=",`"+Name+"(White Percentage)` INT NULL";
	
	
	}

	
	
	return Fields;
}


/***********************************************************************************************/
//Function to convert results and parameters simple desired form
/***********************************************************************************************/
String^ GetFields(int number)
{
	
	Stack_Section ID=this->UniqueID;
	String^ Fields;
	
	String^ Name=String::Format("{0}-{1}",this->ShowProperty->Text,number);

	if((ID>=Enum_BinaryThreshold)&&ID<=(Enum_BinaryThreshold+MAXSTACKIPO)){

	
	
	Fields="`"+Name+"`";
	
	}
	else if((ID>=Enum_RGBThreshold)&&ID<=(Enum_RGBThreshold+MAXSTACKIPO)){

	Fields="`"+Name+"(Red Threshold)`";
	Fields+=",`"+Name+"(Green Threshold)`";
	Fields+=",`"+Name+"(Blue Threshold)`";
	
	}
	else if((ID>=Enum_Crop)&&ID<=(Enum_Crop+MAXSTACKIPO)){

	Fields="`"+Name+"(Method)` ";
	Fields+=",`"+Name+"(CornerA)`";
	Fields+=",`"+Name+"(CornerB)`";
	Fields+=",`"+Name+"(CornerC)`";
	Fields+=",`"+Name+"(CornerD)`";

	
	
	}
	else if((ID>=Enum_RGBPercentage)&&ID<=(Enum_RGBPercentage+MAXSTACKIPO)){
	Fields="`"+Name+"(Red Percentage)`";
	Fields+=",`"+Name+"(Green Percentage)`";
	Fields+=",`"+Name+"(Blue Percentage)`";
	}
	else if((ID>=Enum_BWPercentage)&&ID<=(Enum_BWPercentage+MAXSTACKIPO)){
	Fields="`"+Name+"(Red Percentage)`";
	
	
	}

	
	
	return Fields;
}



};








