#pragma once
#include "ErrorLogs.h"
    
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	

//#define SCIENTIFIC

#define OBJECT_ENDING "##@##"
#define PROPERTYEND "#@#"
#define VALUEEND "@&@"

#define ProjectExtension "pip"
#define SettingExtension "sip"

#define HandleError(ID,a) if(a!=Success) {LogStatus(String::Format("0:d",(int)a),ID); return a;}

#define HandleException(a,ID) try {a} catch ( Exception^ ex ) {ThrowError(ex, ID);}
	

/*************Project Section ID*****************/
#define PROJECTIDSTART		12345
#define PROJECTINCVAL		1876

	
	typedef enum Project_Section_S{
		Enum_ObjectLibraryOn	=	PROJECTIDSTART,
		Enum_ObjectSatckOn	=	(PROJECTIDSTART+(PROJECTINCVAL*1)),
		Enum_VideoFilePath	=	(PROJECTIDSTART+(PROJECTINCVAL*2)),
		Enum_InputDirPath	=	(PROJECTIDSTART+(PROJECTINCVAL*3)),
		Enum_CaptureFromCam	=	(PROJECTIDSTART+(PROJECTINCVAL*4)),
		Enum_OutputDirPath	=	(PROJECTIDSTART+(PROJECTINCVAL*5)),
		Enum_QualityControl	=	(PROJECTIDSTART+(PROJECTINCVAL*6)),
		Enum_SamplePer100	=	(PROJECTIDSTART+(PROJECTINCVAL*7)),
		Enum_CornerA			=	(PROJECTIDSTART+(PROJECTINCVAL*8)),
		Enum_CornerB			=	(PROJECTIDSTART+(PROJECTINCVAL*9)),
		Enum_CornerC			=	(PROJECTIDSTART+(PROJECTINCVAL*10)),
		Enum_CornerD			=	(PROJECTIDSTART+(PROJECTINCVAL*11)),
		Enum_ImageWhole			=	(PROJECTIDSTART+(PROJECTINCVAL*12)),
		Enum_ImageTopThird		=	(PROJECTIDSTART+(PROJECTINCVAL*13)),
		Enum_ImageBottomTwoThird		=	(PROJECTIDSTART+(PROJECTINCVAL*14)),
		Enum_ImageCustom		=	(PROJECTIDSTART+(PROJECTINCVAL*15)),
		Enum_BatchProcess		=	(PROJECTIDSTART+(PROJECTINCVAL*16)),
		Enum_DinamicBatchMonitor			=	(PROJECTIDSTART+(PROJECTINCVAL*17)),
		Enum_LoadTimeBasedSettings			=	(PROJECTIDSTART+(PROJECTINCVAL*18)),
		Enum_LoadImageSpecificSettings		=	(PROJECTIDSTART+(PROJECTINCVAL*19)),
		Enum_UseTimeBasedSettings			=	(PROJECTIDSTART+(PROJECTINCVAL*20)),
		Enum_UseImageBasedSettings			=	(PROJECTIDSTART+(PROJECTINCVAL*21)),
		Enum_TimeSpecificSettingFiles					=	(PROJECTIDSTART+(PROJECTINCVAL*22)),
		Enum_ImageSpecificSettingFiles					=	(PROJECTIDSTART+(PROJECTINCVAL*23)),
		Enum_ImagesDisplay								=	(PROJECTIDSTART+(PROJECTINCVAL*24)),
		Enum_QualityControlDir							=	(PROJECTIDSTART+(PROJECTINCVAL*25)),
	}Project_Section;


#define INIT_PROJECTSECTION_POPULATE \
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_ObjectLibraryOn,"0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_ObjectSatckOn,"0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_VideoFilePath,""));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_InputDirPath,""));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_CaptureFromCam, "0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_OutputDirPath, ""));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_QualityControl,"0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_SamplePer100,"0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_CornerA, "0,0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_CornerB, "0,0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_CornerC, "0,0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_CornerD, "0,0"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_BatchProcess, "1"));\
	HandleError("INIT_PROJECTSECTION_POPULATE",UpdateProjectSection(Enum_ImageWhole, "1"));
	
	//0-whole, 1-left half, 2- right half, 3- custom
	//number indicates the curresponding option in menu
	/*************Stack Section ID*****************/

	#define STACKIDSTART		67890
	#define STACKINCVAL			1234
	#define MAXSTACKIPO			256 //Max number of same IPOS in stack
	
	typedef enum Stack_Section_S{
		Enum_BinaryThreshold		=		STACKIDSTART,
		Enum_RGBThreshold			=		(STACKIDSTART+(STACKINCVAL*1)),
		Enum_Crop					=		(STACKIDSTART+(STACKINCVAL*2)),
		Enum_RGBPercentage			=		(STACKIDSTART+(STACKINCVAL*3)),
		Enum_BWPercentage			=		(STACKIDSTART+(STACKINCVAL*4)),
		Enum_Edges					=		(STACKIDSTART+(STACKINCVAL*5)),
		Enum_BackgroundSubstraction =		(STACKIDSTART+(STACKINCVAL*6)),
		Enum_Brightness				=		(STACKIDSTART+(STACKINCVAL*7)),
		Enum_Contrast				=		(STACKIDSTART+(STACKINCVAL*8)),
		Enum_Saturation				=		(STACKIDSTART+(STACKINCVAL*9)),
		Enum_CounterSearch			=		(STACKIDSTART+(STACKINCVAL*10)),
		Enum_IMCalculator			=		(STACKIDSTART+(STACKINCVAL*11)),
		Enum_BoundingShape			=		(STACKIDSTART+(STACKINCVAL*12)),
		Enum_ColorCNV				=		(STACKIDSTART+(STACKINCVAL*13)),
		Enum_AreaThreshold			=		(STACKIDSTART+(STACKINCVAL*14)),
		Enum_ParameterThreshold		=		(STACKIDSTART+(STACKINCVAL*15)),
		Enum_AVGBrightness			=		(STACKIDSTART+(STACKINCVAL*16)),
		Enum_AVGRGB					=		(STACKIDSTART+(STACKINCVAL*17)),
		Enum_Luma					=		(STACKIDSTART+(STACKINCVAL*18)),
		Enum_AVGLightness			=		(STACKIDSTART+(STACKINCVAL*19)),
		Enum_AVGIntensity			=		(STACKIDSTART+(STACKINCVAL*20)),
		Enum_DePixalate				=		(STACKIDSTART+(STACKINCVAL*21)),
		Enum_Counter				=		(STACKIDSTART+(STACKINCVAL*22)),
	}Stack_Section;



#define GetObjCnt(ID) ((ID-STACKIDSTART)%STACKINCVAL)+1
#define Poperty2Str(ID,section,...)  {array<String^>^ s ={##__VA_ARGS__};  HandleError(ID,UpdateStackSection(section, Properties2Str(s)));}

	
	#define INIT_STACKSECTION_POPULATE  
	//Poperty2Str("INIT_STACKSECTION_POPULATE",BinaryThreshold,"Threshold","128");\
	//Poperty2Str("INIT_STACKSECTION_POPULATE",RGBThreshold,"Threshold","128","R","128","G","128","B","128")
	

	/*****************************Stack Section Populate****************************/


	typedef enum {
		Success,
		FileUpdateError,
		NoProjectSectionError,
		NoStackSectionError,
		NoStackFileError,
		NOImageErr,

	}IPOErrors;



ref class SettingFiles
{
public: String^ ProjectFilename;
public: String^ StackFilename;
private:static array<String^>^ StackElements={"[IPO-Stack Setting File]"};
private:static array<String^>^ ProjectElements={"[IPO-Digital Batch Image Analyzer File]"};
private: String^ StatusLog;

public: static bool isIPOStackAvilable4Reload=false;
public: static bool isIPOLibraryAvilable=false;

public:

SettingFiles(String^ filename);
SettingFiles(String^ Logfile, String^ Projectfle, String^ Stackfle);


/***********************************************************************************************/
//Setting ProjectFilename of project
/***********************************************************************************************/
public:	IPOErrors SetProjectFileName(String^ filename){


try{

				ProjectFilename=filename;
			
				if(!File::Exists(ProjectFilename))
				{
				//Fill the file default values
				INIT_PROJECTSECTION_POPULATE
				HandleError("UpdateProjectFile",UpdateProjectFile());
				
				
				}
			
				ProjectElements = File::ReadAllLines(ProjectFilename);
} catch ( Exception^ ex ) {
	ThrowError(ex, "SetProjectFileName");
	//LogMessage("","");
}
			return Success;
			
		}
/***********************************************************************************************/
//Load stack elements from the Stack file
/***********************************************************************************************/
public:	IPOErrors ReloadStackElements(){

try{
				
				if(!File::Exists(StackFilename))
				{
				return NoStackFileError;
				
				
				}
			

				StackElements = File::ReadAllLines(StackFilename);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadStackElements");
	//LogMessage("","");
}
				return Success;
		}


/***********************************************************************************************/
//Load Project elements from the Project file
/***********************************************************************************************/

public:	IPOErrors ReloadProjectElements(){
try{
			
				
				if(!File::Exists(ProjectFilename))
				{
				return NoStackFileError;
				
				
				}
			

				ProjectElements = File::ReadAllLines(ProjectFilename);
} catch ( Exception^ ex ) {
	ThrowError(ex, "ReloadProjectElements");
	//LogMessage("","");
}
				return Success;
		}

/***********************************************************************************************/
//Set stack filename for the project
/***********************************************************************************************/

public:	IPOErrors SetStackFileName(String^ filename){



try{
				StackFilename= filename;
				if(!File::Exists(StackFilename))
				{
				//Fill the file default values
				INIT_STACKSECTION_POPULATE
				HandleError("UpdateStackFile",UpdateStackFile());
				
				
				}
			

				StackElements = File::ReadAllLines(StackFilename);
} catch ( Exception^ ex ) {
	ThrowError(ex, "SetStackFileName");
	//LogMessage("","");
}
				return Success;
		}
/***********************************************************************************************/
//Update a section of current project in the setting file
/***********************************************************************************************/
public:	IPOErrors UpdateProjectSection(Project_Section Section, String^ value){
	

try{
				String^ SectionStr =String::Format("{0:d}",(int)Section);
				int index=Array::IndexOf(ProjectElements,SectionStr);
				if(index<0){
					Array::Resize(ProjectElements,ProjectElements->Length+2);
					ProjectElements->SetValue(SectionStr,ProjectElements->Length-2);
					ProjectElements->SetValue(value,ProjectElements->Length-1);
				}
				else{
					ProjectElements->SetValue(value,index+1);
				}
				//search for the section in Project elements and update it
				//if no section present then add it
//,"UpdateProjectSection")
				return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateProjectSection");
	//LogMessage("","");
}
		}


/***********************************************************************************************/
//Read a section of the project.
/***********************************************************************************************/
public:	IPOErrors ReadProjectSection(Project_Section Section, String^ &value){
			 
try{
					String^ SectionStr =String::Format("{0:d}",(int)Section);
					int index=Array::IndexOf(ProjectElements,SectionStr);
					if(index<0){
						value="";
						return NoProjectSectionError;
					}
					else{
						value=(String^)ProjectElements->GetValue(index+1);
					}

					//search for the section in Project elements and update it
					//if no section present then add it
					return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ReadProjectSection");
	//LogMessage("","");
}
		}

/***********************************************************************************************/
//Read a section of the current project stack
/***********************************************************************************************/
public:	IPOErrors ReadStackSection(Stack_Section Section, String^ &value){
			 
try{
				String^ SectionStr =String::Format("{0}",(int)Section);
				int index=Array::IndexOf(StackElements,SectionStr);
				if(index<0){
					value="";
					return NoStackSectionError;
				}
				else{
					value=(String^)StackElements->GetValue(index+1);
				}

				//search for the section in Project elements and update it
				//if no section present then add it
				return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ReadProjectSection");
	//LogMessage("","");
}
		}

/***********************************************************************************************/
//Update a section of the current project stack
/***********************************************************************************************/
public:	IPOErrors UpdateStackSection(Stack_Section Section, String^ value){


try{
			//search for the section in Objects elements and update it
			//if no section present then add it
			
			String^ SectionStr =String::Format("{0:d}",(int)Section);
			int index=Array::IndexOf(StackElements,SectionStr);
			if(index<0)
			{
				Array::Resize(StackElements,StackElements->Length+2);
				StackElements->SetValue(SectionStr,StackElements->Length-2);
				StackElements->SetValue(value,StackElements->Length-1);
			}
			else{
				StackElements->SetValue(value,index+1);
			}


			return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateStackSection");
	//LogMessage("","");
}
		}
/***********************************************************************************************/
//Remove a section of the current project stack
/***********************************************************************************************/
public:	IPOErrors RemoveStackSection(Stack_Section Section){


try{
			//search for the section in Objects elements and update it
			//if no section present then add it
			
			String^ SectionStr =String::Format("{0:d}",(int)Section);
			int index=Array::IndexOf(StackElements,SectionStr);
			if(index<0)
			{
				return Success;
			}
			else{

				StackElements->SetValue(StackElements->GetValue(StackElements->Length-2),index);//copying second last element
				StackElements->SetValue(StackElements->GetValue(StackElements->Length-1),index+1);//copying last element
				Array::Resize(StackElements,StackElements->Length-2);
			}


			return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "RemoveStackSection");
	//LogMessage("","");
}
		}
/***********************************************************************************************/
//Update a the current project setting file
/***********************************************************************************************/
public: IPOErrors UpdateProjectFile(){

try{
			 //take the count and update rewrite the file
			 File::WriteAllLines(ProjectFilename,ProjectElements);


			return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateProjectFile");
	//LogMessage("","");
}
		 }

/***********************************************************************************************/
//Update a the current project setting file
/***********************************************************************************************/
public: IPOErrors UpdateStackFile(){

try{
			 //take the count and update rewrite the file
			 File::WriteAllLines(StackFilename,StackElements);

			return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateStackFile");
	//LogMessage("","");
}
		 }

/***********************************************************************************************/
//Log Status to the logfile
/***********************************************************************************************/
public:  void LogStatus(String^ message, String^ ID)
{
try{
File::AppendAllText(StatusLog, String::Concat(ID,message) );
File::AppendAllText(StatusLog, "\n****************************************************************************\n\n" );
} catch ( Exception^ ex ) {
	ThrowError(ex, "LogStatus");
	//LogMessage("","");
}

}
/***********************************************************************************************/
//Convert all the properties to a String with proper delimiters
/***********************************************************************************************/
public: String^ Properties2Str(array<String^>^ arr)
		{
try{
			String^ str;
			if(arr->Length%2==0)
			{
			
			for (int i=0;i<arr->Length;i+=2)
			{
			str= String::Concat(str, String::Concat(arr->GetValue(i),PROPERTYEND));
			str= String::Concat(str, String::Concat(arr->GetValue( i+1),VALUEEND));
			}
			}
			
				return str;
} catch ( Exception^ ex ) {
	ThrowError(ex, "Properties2Str");
	//LogMessage("","");
}

		}


/***********************************************************************************************/
//Read a property value from the the property string
/***********************************************************************************************/
public: String^ ReadProperty(String^ Property, String^ List)
		{
			
try{			
			array <String^>^ delimiter = {PROPERTYEND,VALUEEND};
			array <String^>^ arr = List->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			

			int index=Array::IndexOf(arr,Property);
			if(index<0)
			{
				return "";
			}
			else{
				return (String^)arr->GetValue(index+1);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "ReadProperty");
	//LogMessage("","");
}
			
		}
/***********************************************************************************************/
//Update a property value in the property string
/***********************************************************************************************/
public: String^ UpdateProperty(String^ Property,String^ Value, String^ List)
		{
			
try{			
			array <String^>^ delimiter = {PROPERTYEND,VALUEEND};
			array <String^>^ arr = List->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			

			int index=Array::IndexOf(arr,Property);
			if(index<0)
			{
				return List;
			}
			else{

				 arr->SetValue(Value,index+1); 
				return Properties2Str(arr);
			}
} catch ( Exception^ ex ) {
	ThrowError(ex, "UpdateProperty");
	//LogMessage("","");
}
			
		}

/***********************************************************************************************/
//Converty property string to List view item array
/***********************************************************************************************/
public: array<ListViewItem^>^ PropertyStr2List(array<ListViewItem^>^ List, String^ Str)
		{
try{			
			for(int i=0; i< List->Length;i++)
			{
				List[i]->SubItems[1]->Text=ReadProperty(List[i]->SubItems[0]->Text,Str);
				//ListViewItem^ Item =List->GetValue(i);
			}
			return List;
} catch ( Exception^ ex ) {
	ThrowError(ex, "PropertyStr2List");
	//LogMessage("","");
}

		}
/***********************************************************************************************/
//return length of the stack filled
/***********************************************************************************************/

int StackLength(){
	try{
	return ((StackElements->Length-1)/2);
	} catch ( Exception^ ex ) {
	ThrowError(ex, "StackLength");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Read a perticular stack id from the given position
/***********************************************************************************************/
Int32 ReadStackID(int num){
try{
	 Int32::TryParse(StackElements[(num*2)+1],num);
	 return num;
} catch ( Exception^ ex ) {
	ThrowError(ex, "LogStatus");
	//LogMessage("","");
}
}

};

