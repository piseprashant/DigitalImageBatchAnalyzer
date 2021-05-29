#pragma once

#include "SettingFiles.h"
//#include "ImageShow.h"
#include "ParameterObject.h"


#define DummyExt ".txt"
#define QualityControllDir "QualityControl"
#define DatabaseCSVName "Restlus.csv"
#define FILENAME_DATETIME	2
#define FILENAME_COUNTRY	1
#define FILENAME_IDNUM		0

#define DATABASE_NAME "digitalbatchimageanalyzer"
#define GetDBFieldName(Obj) String::Format("{0}-{1}",Obj->ShowProperty->Text,GetObjCnt(Obj->UniqueID)) 

using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	using namespace System::Drawing::Imaging;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Globalization;
	using namespace MySql::Data::MySqlClient;
	

ref class IPOHandling
{
public: 


	String^			VideoFilePath;
	String^			InputDirPath;
	String^			QualityControlDir;
	bool			CaptureFromCam;
	System::String^	OutputDirPath;
	bool			QualityControl;
	int				SamplePer100;
	Point			CornerA;
	Point			CornerB;
	Point			CornerC;
	Point			CornerD;	
	bool			ImageWhole;
	bool			ImageTopThird;
	bool			ImageBottomTwoThird;
	bool			ImageCustom;
	bool			BatchProcess;
	bool			DinamicBatchMonitor;
	bool			LoadTimeBasedSettings;
	bool			LoadImageSpecificSettings;	
	bool			ImagesDisplay;
	array			<System::String^>^ TimeSpecificSettingFiles;
	array			<System::String^>^ ImageSpecificSettingFiles;
	Bitmap^			Image;

	
	DWORD			m_dwFlags;
	BOOL			m_bChildren;
	LPCTSTR			m_wstrDirectory;
	char*			pBase ;
	 // Result of calling CreateFile().
	static HANDLE	m_hDirectory;
	static bool		Stop_BatchProcessing=false;
	static bool		Stop_CamCapture=false;
	static bool		Stop_DinamicMonitor=false;
	System::String^ CurrentImgName;
	Int32			QualityControlCounter;
	array			<System::String^>^ ImageBatch;
	static bool		BatchProcessorEndMutex=false;
	String^			CurrentCSVName;
	Int32			ResultIndex;
	Int32			DBResultIndex;
	String^			CurrentDatabaseTableName;

	

	
	//ImageShow^ ImShow;//Coming from parent from
private:
	

public:
	IPOHandling(void);

/***********************************************************************************************/
//Function to start quality counter 
/***********************************************************************************************/
	void StartQualityControlCounter(){
		QualityControlCounter=0;
	}
/***********************************************************************************************/
//Function to have image from any selected input option (for processing)
/**********************************************************************************************/
	Bitmap^ Input(){
try{
		//read bitmap from the input path
		// or read frame from the video file
		// or capture image from camera

		//Bitmap^ image1;
		

		if(BatchProcess){
				Image =ImageBatchProcess();
		}
		
	//	if(!Image&&DinamicBatchMonitor){
		if((!BatchProcess||!Image)&& DinamicBatchMonitor){
		Image=ImageDinamicMonitor();
		}

		

		if(!Image){//Do all closing proceedures
			m_hDirectory=NULL;//closing the directory handler
			LoadBatchProcessDir();//realoading dir for next run
		}
		
	return Image;
} catch ( Exception^ ex ) {
	ThrowError(ex, "Input");
	//LogMessage("","");
}
	}


/***********************************************************************************************/
//Function to Have image from selected input options for displaying need
/***********************************************************************************************/
Bitmap^ SampleInput(bool start){
try{		
	//read bitmap from the input path
	// or read frame from the video file
	// or capture image from camera

		Stop_BatchProcessing=false;
		Stop_CamCapture=false;
		Stop_DinamicMonitor=false;

		if(start)
		LoadBatchProcessDir();
		
		
		int RepeatLoad=0;
		Bitmap^ image1;
		while(!image1&&RepeatLoad<2){

		if(BatchProcess){
		
		image1 =ImageBatchProcess();
		
		}


		if(!image1)
		LoadBatchProcessDir();
		RepeatLoad++;
		}
	
		if(ImageWhole);
		else if(ImageTopThird)
			image1=TopThird(image1);
		else if (ImageBottomTwoThird)
			image1=BottomTwoThird(image1);
		else if (ImageCustom)
			image1=ShowCustomPortion(image1);
		//if(image1)
		//SelectRegion();
		
	return image1;
} catch ( Exception^ ex ) {
	ThrowError(ex, "SampleInput");
	//LogMessage("","");
}
	}

/***********************************************************************************************/
//Function to load the dir components of input path
/***********************************************************************************************/
	bool LoadBatchProcessDir(){
try{
		
		if(InputDirPath&&InputDirPath!=""){
			ImageBatch=Directory::GetFiles(InputDirPath);
		    if(ImageBatch&&ImageBatch->Length)
				return true;
			else
				return false;
		}
		return false;
} catch ( Exception^ ex ) {
	ThrowError(ex, "LoadBatchProcessDir");
	//LogMessage("","");
}
			
	}
/***********************************************************************************************/
//Function to have input if Image batch processing is clicked
/***********************************************************************************************/
	Bitmap^ ImageBatchProcess(){
try{
	Bitmap^ image1;

	if(!Stop_BatchProcessing){	
		

		if(ImageBatch&&ImageBatch->Length&&File::Exists(ImageBatch[ImageBatch->Length-1])){
			image1=gcnew Bitmap(ImageBatch[ImageBatch->Length-1],true);
			CurrentImgName=ImageBatch[ImageBatch->Length-1];
		}
		else
			BatchProcessorEndMutex=false;
		
		if(ImageBatch&&ImageBatch->Length)	
		Array::Resize(ImageBatch,ImageBatch->Length-1);
	}
	return image1;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageBatchProcess");
	//LogMessage("","");
}
	}
/***********************************************************************************************/
//Function to capture image if Dinamic monitor is clicked
/***********************************************************************************************/

Bitmap^ ImageDinamicMonitor(){
try{
		Bitmap^ image1;
		if(!Stop_DinamicMonitor){

			if(!m_hDirectory){

			DetectDirChange();
			}

		if(m_hDirectory){

		if(isFileRemaining()){
			CurrentImgName=GetRemainingFile();
			if(CurrentImgName!="")
			image1= gcnew Bitmap( CurrentImgName,true );
			return image1;
		}

		CurrentImgName= GetNewFile(m_hDirectory);
		if(CurrentImgName!=""){
		Sleep(100);
		System::String^ ext =Path::GetExtension(CurrentImgName);
		if(ext!=DummyExt)
		image1=gcnew Bitmap( CurrentImgName,true );
		}
		return image1;
		}

	}

	return image1;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ImageDinamicMonitor");
	//LogMessage("","");
}
	}
/***********************************************************************************************/
//Function to save the final output image
/***********************************************************************************************/
	IPOErrors OutputResultImg(Bitmap^ img){
try{
		System::String^ Name= Path::GetFileName(CurrentImgName);
		System::String^ outputfile=Path::Combine(OutputDirPath,Name);
		img->Save(outputfile);
		File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),"\r\n");

		QualityControlCounter++;
		return Success;
} catch ( Exception^ ex ) {
	ThrowError(ex, "OutputResultImg");
	//LogMessage("","");
}
	}
/***********************************************************************************************/
//Function to output the Image input name
/***********************************************************************************************/
	IPOErrors OutputInputName(){

try{	
	String^ ID= IDfromImage(CurrentImgName);
	DateTime Datetime=DateTimeFromFile(CurrentImgName);
	//String^ Country = CountryfromImage(Name);
	String^ Time=Datetime.ToString("HH:mm:ss");
	String^ Date=Datetime.ToString("dd/MM/yyyy");
	//finding index

	DBResultIndex=FindNextOfDatabase();
	String^ Index = String::Format("{0}",DBResultIndex);//String::Format("{0}",ResultIndex++);

	File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),Index+","+ID+","+Date+","+Time);
//	command->CommandText= "INSERT INTO `"+SchemaName+"`.`"+CurrentTableName+"` (`Index`, `ID`,`Date`,`Time`) VALUES ("+Index+","`+ID+"`,`"+Date+"`,`"+Time+"`); ";
	String^ Database= "(`INDEX_NUM`, `SOURCE_CODE`,`DATE`,`TIME`) VALUES ("+Index+",'"+ID+"','"+Date+"','"+Time+"')";
	InserttoDatabase(Database);
	return Success;

} catch ( Exception^ ex ) {
	ThrowError(ex, "OutputInputName");
	//LogMessage("","");
}
	}


/***********************************************************************************************/
//Function to output the entire image results and Quality control processing
/***********************************************************************************************/
	IPOErrors Output(ParameterObject^ Obj,bool QualityCheck){

try{		
		if( QualityControl&&!(QualityControlCounter%SamplePer100)){
        
		if(QualityCheck){
		String^ path=	 Path::Combine(OutputDirPath,QualityControllDir);
			if (!Directory::Exists(path)) {
				Directory::CreateDirectory(path);
			}
		String^ Name= Obj->ShowProperty->Text+"_"+Path::GetFileName(CurrentImgName);
		Obj->Result->Save(Path::Combine(path,Name));
		}

		}
		

	//	String^ CSVTxt= Path::GetFileName(CurrentImgName) +","+Obj->ShowProperty->Text + ",Parameters,,"+ ToCSVFormat(Obj->Properties)+"\r\n";
	//	File::AppendAllText(Path::Combine(OutputDirPath,DatabaseCSVName),CSVTxt);
		String ^ strParameters;
		


		strParameters = Obj->ConvertionLayer2(GetObjCnt(Obj->UniqueID));

		if( Obj->ObjectKind==PreProcessing){
		if( Obj->Properties&& Obj->Properties->Length>0)
		{
		String^ CSVTxt2= "," + ToCSVFormat( Obj->Properties);
		File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),CSVTxt2);
		//String^ Database = "`"+Obj->ShowProperty->Text+"`="+ToDatabaseFormat( Obj->Properties)+" WHERE `INDEX_NUM`='"+(ResultIndex-1)+"'";
	    
		
		String^ Database = strParameters+" WHERE `INDEX_NUM`='"+(DBResultIndex)+"'";
	    
		
		UpdatetoDatabase(Database,Obj);
		}
		}
		else if( Obj->ExtraResults&& Obj->ExtraResults->Length>0)
		{
		String^ CSVTxt2= "," + ToCSVFormat( GetDBFieldName(Obj));
		File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),CSVTxt2);
		//String^ Database = "`"+Obj->ShowProperty->Text+"`="+ToDatabaseFormat( Obj->ExtraResults)+" WHERE `INDEX_NUM`='"+(ResultIndex-1)+"'";
		String^ Database = strParameters+" WHERE `INDEX_NUM`='"+(DBResultIndex)+"'";
		UpdatetoDatabase(Database,Obj);
		}

		
		
		//Saving to CSV file

		
		

		//Save result to the output location OR Database
		//Save to quality controll dir if sampleper100 counter rollover
		//Extract the extraresults and save it to the csv file with filename or
		//frame number same to the database

	return Success;
}	catch ( Exception^ ex ) {
	ThrowError(ex, "Output");
	//LogMessage("","");
}
	}


/***********************************************************************************************/
//Function to find next enty for inserting in mysql database
/***********************************************************************************************/
int FindNextOfDatabase(){

	try
{

	String^ serverlogin="Server=localhost;Uid=root;pwd=root;database="+DATABASE_NAME+";";

	MySql::Data::MySqlClient::MySqlConnection ^ conn=gcnew MySqlConnection(serverlogin);
	MySqlCommand^ command = conn->CreateCommand();

	conn->Open();

	//Updating if column doesnt exists
	String^ str="SELECT `INDEX_NUM`  FROM `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"`;";
	
	command->CommandText=str;
	MySqlDataAdapter^ Adpt = gcnew MySqlDataAdapter();

	Adpt->SelectCommand = command;

	DataSet ^ myData = gcnew DataSet();
	Adpt->Fill(myData);
	int k = myData->Tables->Count;
	if(k){
	k=myData->Tables[0]->Rows->Count;

	return k;
	}
	else
		return 0;



	conn->Close();
}
catch (MySql::Data::MySqlClient::MySqlException ^ ex)
{
    ThrowError(ex, "FindNextOfDatabase");
	switch (ex->Number)
    {
		case 0:
            LogMessage("Cannot connect to server.  Contact administrator", "HandleDatabase");
        case 1045:
           LogMessage("Invalid username/password, please try again", "HandleDatabase");
	}
}
return 0;
}

/***********************************************************************************************/
//Function to output to the MySqlDatabase
/***********************************************************************************************/
bool UpdatetoDatabase(String^ Values, ParameterObject^ Obj){

	try
{
	String^ field = GetDBFieldName(Obj);
	String^ serverlogin="Server=localhost;Uid=root;pwd=root;database="+DATABASE_NAME+";";

	MySql::Data::MySqlClient::MySqlConnection ^ conn=gcnew MySqlConnection(serverlogin);
	MySqlCommand^ command = conn->CreateCommand();

	

	//Updating if column doesnt exists
	String^ str="SHOW COLUMNS FROM `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` LIKE '"+field +"%';";
	

	command->CommandText="SHOW COLUMNS FROM `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` LIKE '"+field +"%';";
	
	MySqlDataAdapter^ Adpt = gcnew MySqlDataAdapter();

	Adpt->SelectCommand = command;

	DataSet ^ myData = gcnew DataSet();
	Adpt->Fill(myData);
	int k = myData->Tables->Count;
	if(k){
	k=myData->Tables[0]->Rows->Count;

	if(!k){
	String^ str1="ALTER TABLE `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` INSERT_METHOD = FIRST , ADD COLUMN "+Obj->GenerateFields(GetObjCnt(Obj->UniqueID)) +";";
	command->CommandText=  "ALTER TABLE `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` INSERT_METHOD = FIRST , ADD ( "+Obj->GenerateFields(GetObjCnt(Obj->UniqueID)) +");";
	conn->Open();
 	command->ExecuteNonQuery();
	conn->Close();

	}
	}


//	UPDATE `digitalbatchimageanalyzer`.`01-11-2011-22-03-31-` SET `Binary Threshold`='oierjgsdklfnglsdmgklksmfl' WHERE `INDEX_NUM`='12';
		
	String^ ex="UPDATE `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` SET "+Values+";";
    command->CommandText= "UPDATE `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"` SET "+Values+";";
  //  conn->ConnectionString = ;
    conn->Open();
	command->ExecuteNonQuery();
	

	conn->Close();
}
catch (MySql::Data::MySqlClient::MySqlException ^ ex)
{
    ThrowError(ex, "UpdataDatabase");
	switch (ex->Number)
    {
		case 0:
            LogMessage("Cannot connect to server.  Contact administrator", "HandleDatabase");
        case 1045:
           LogMessage("Invalid username/password, please try again", "HandleDatabase");
	}
}
return true;
}

/***********************************************************************************************/
//Function to output to the MySqlDatabase
/***********************************************************************************************/
bool InserttoDatabase(String^ Values){

	try
{

	String^ serverlogin="Server=localhost;Uid=root;pwd=root;database="+DATABASE_NAME+";";

	MySql::Data::MySqlClient::MySqlConnection ^ conn=gcnew MySqlConnection(serverlogin);
	MySqlCommand^ command = conn->CreateCommand();
	String^ str="INSERT INTO `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"`"+Values+"; ";
    command->CommandText= "INSERT INTO `"+DATABASE_NAME+"`.`"+CurrentDatabaseTableName+"`"+Values+"; ";
  //  conn->ConnectionString = ;
    conn->Open();
	command->ExecuteNonQuery();
	

	conn->Close();
}
catch (MySql::Data::MySqlClient::MySqlException ^ ex)
{
    ThrowError(ex, "HandleDatabase");
	switch (ex->Number)
    {
		case 0:
            LogMessage("Cannot connect to server.  Contact administrator", "HandleDatabase");
        case 1045:
           LogMessage("Invalid username/password, please try again", "HandleDatabase");
	}
}
return true;
}

bool CreateTable(String^ name, String^ entries){

	try
{

	//String^ serverlogin="Server=localhost;Uid=root;pwd=root;database="+DATABASE_NAME+";";
	String^ serverlogin="Server=localhost;Uid=root;pwd=root;database=test;";

	MySql::Data::MySqlClient::MySqlConnection ^ conn=gcnew MySqlConnection(serverlogin);
	MySqlCommand^ command = conn->CreateCommand();

	command->CommandText= "CREATE DATABASE IF NOT EXISTS`"+DATABASE_NAME+"`;";

	conn->Open();
	command->ExecuteNonQuery();
	//command->CommandText= "CREATE SCHEMA `DigitaBatchImageAnalyzer`
	//CREATE TABLE IF NOT EXISTS (def)
	String^ str="CREATE TABLE IF NOT EXISTS `"+DATABASE_NAME+"`.`"+name+"`"+entries+";"; 
	command->CommandText= "CREATE TABLE IF NOT EXISTS `"+DATABASE_NAME+"`.`"+name+"`"+entries+";"; 
    //command->CommandText= "CREATE  TABLE `"+DATABASE_NAME+"`.`"+name+"`"+entries+";"; 
  //  conn->ConnectionString = ;
    //conn->Open();
	command->ExecuteNonQuery();
	
	
	conn->Close();
}
catch (MySql::Data::MySqlClient::MySqlException ^ ex)
{
    ThrowError(ex, "HandleDatabase");
	switch (ex->Number)
    {
		case 0:
            LogMessage("Cannot connect to server.  Contact administrator", "HandleDatabase");
        case 1045:
           LogMessage("Invalid username/password, please try again", "HandleDatabase");
	}
}
return true;
}

/***********************************************************************************************/
//Function to create new settings file
/***********************************************************************************************/
String^ CreateResultCSV(array <ParameterObject^>^ IPO_List){
try{
DateTime value= DateTime::Now;
ResultIndex=0;
String^ DateTimeStr=value.ToString("dd-MM-yyyy-HH-mm-ss-");
CurrentCSVName= DateTimeStr+DatabaseCSVName;
String^ Database = "(`INDEX_NUM` INT NOT NULL ,`SOURCE_CODE` VARCHAR(50) NULL , `DATE` VARCHAR(50) NULL , `TIME` VARCHAR(50) NULL";//,PRIMARY KEY (`id`) )";
String^ CSVTStart="INDEX_NUM,SOURCE_CODE,DATE,TIME";
File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),CSVTStart);
for(int i=0;i<IPO_List->Length;i++){
	File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),","+IPO_List[i]->ShowProperty->Text);
	Database=Database+","+IPO_List[i]->GenerateFields(GetObjCnt(IPO_List[i]->UniqueID)); //GetDBFieldName(IPO_List[i])+"`  VARCHAR(200) NULL";
}
Database=Database+",PRIMARY KEY (`INDEX_NUM`) )";
File::AppendAllText(Path::Combine(OutputDirPath,CurrentCSVName),"\r\n");
CurrentDatabaseTableName="DigitalBatchImageAnalyzerTable";//DateTimeStr;
CreateTable(CurrentDatabaseTableName,Database);

return CurrentCSVName;

}catch ( Exception^ ex ) {
ThrowError(ex, "CreateResultCSV");
	//LogMessage("","");
}
}
/***********************************************************************************************/
//Function to convert property string to csv format
/***********************************************************************************************/
public: String^ ToCSVFormat(String^ Property){
try{

			array <String^>^ delimiter = {VALUEEND};
			array <String^>^ arr = Property->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			String^ dummy=String::Join("\n",arr);

			array <String^>^ delimiter2 = {PROPERTYEND};
			array <String^>^ arr2 = dummy->Split(delimiter2, StringSplitOptions::RemoveEmptyEntries);
			 dummy=String::Join(":",arr2);
			 dummy="\""+dummy+"\"";
			return dummy;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ToCSVFormat");
	//LogMessage("","");
}
		}
		

/***********************************************************************************************/
//Function to convert property string to database format
/***********************************************************************************************/
public: String^ ToDatabaseFormat(String^ Property){
try{

			array <String^>^ delimiter = {VALUEEND};
			array <String^>^ arr = Property->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
			String^ dummy=String::Join("\n",arr);

			array <String^>^ delimiter2 = {PROPERTYEND};
			array <String^>^ arr2 = dummy->Split(delimiter2, StringSplitOptions::RemoveEmptyEntries);
			 dummy=String::Join(":",arr2);
			 dummy="'"+dummy+"'";
			return dummy;
} catch ( Exception^ ex ) {
	ThrowError(ex, "ToDatabaseFormat");
	//LogMessage("","");
}
		}

/***********************************************************************************************/
//Function to Get TimeID from filename

		//Filename	:	IDNUM.ext
		//# can be included in the filename instead of *
		
/***********************************************************************************************/


String^ IDfromSettings(String^ filename){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
//	name->Replace("#","*");
	
	return name;
} catch ( Exception^ ex ) {
	ThrowError(ex, "IDfromSettings");
	//LogMessage("","");
}
}
/***********************************************************************************************/
//Function to Get TimeID from filename

		//Filename	:	IDNUM_COUNTRY_DATETIME.ext
		//ID		:	IDNUM_COUNTRY
		//Format : 1234567890_FRANCE_03-05-2011-02-34-36-+00,00.jpg
/***********************************************************************************************/


String^ IDfromImage(String^ filename){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
	array <String^>^ delimiter = {"_"};
	array<String^>^ FileElements=name->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	
	return FileElements[FILENAME_IDNUM];
} catch ( Exception^ ex ) {
	ThrowError(ex, "IDfromSettings");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to Get Country from filename

		//Filename	:	IDNUM_COUNTRY_DATETIME.ext
		//ID		:	IDNUM_COUNTRY
		//Format : 1234567890_FRANCE_03-05-2011-02-34-36-+00,00.jpg
/***********************************************************************************************/


String^ CountryfromImage(String^ filename){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
	array <String^>^ delimiter = {"_"};
	array<String^>^ FileElements=name->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	
	return FileElements[FILENAME_COUNTRY];
} catch ( Exception^ ex ) {
	ThrowError(ex, "IDfromSettings");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to Get DateTimeID from filename

		//Filename	:	IDNUM_COUNTRY_DATETIME.ext
		//ID		:	IDNUM_COUNTRY
		//Format :1234567890_FRANCE_03-05-2011-02-34-36-+00,00.jpg
/***********************************************************************************************/


DateTime DateTimeFromFile(String^ filename){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
	DateTime value;
	array <String^>^ delimiter = {"_"};
	array<String^>^ FileElements=name->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	if(FileElements->Length>1){
	FileElements[2]=FileElements[2]->Replace(',',':');
	CultureInfo^ enUS=gcnew CultureInfo("en-US"); 
	//FileElements[2]= "03-05-2011-09-34-36-+00:00";
	//DateTime value=DateTime::ParseExact(FileElements[2], "MM-dd-yyyy-HH-mm-ss-zzz", enUS,  DateTimeStyles::AdjustToUniversal);
	value=DateTime::ParseExact(FileElements[2], "MM-dd-yyyy-HH-mm-ss-zzz", enUS, 
                            DateTimeStyles::AdjustToUniversal);
	
	}

	return value;
	
} catch ( Exception^ ex ) {
	ThrowError(ex, "DateTimeFromFile");
	//LogMessage("","");
}
}

/***********************************************************************************************/
//Function to Get TimeID from filename

		//Filename	:	IDNUM_COUNTRY_DATETIME.ext
		//ID		:	IDNUM_COUNTRY
		//Format :1234567890_FRANCE_03-05-2011-02-34-36-+00,00.jpg
/***********************************************************************************************/


DateTime TimeFromFile(String^ filename){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
	DateTime value;
	array <String^>^ delimiter = {"_"};
	array<String^>^ FileElements=name->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);
	if(FileElements->Length>1){
	FileElements[2]=FileElements[2]->Replace(',',':');
	CultureInfo^ enUS=gcnew CultureInfo("en-US"); 
	//FileElements[2]= "03-05-2011-09-34-36-+00:00";
	//DateTime value=DateTime::ParseExact(FileElements[2], "MM-dd-yyyy-HH-mm-ss-zzz", enUS,  DateTimeStyles::AdjustToUniversal);
	value=DateTime::ParseExact(FileElements[2], "MM-dd-yyyy-HH-mm-ss-zzz", enUS, 
                            DateTimeStyles::AdjustToUniversal);
	String^ OnlyTimeStr=value.ToString("HH:mm:ss");
	value=DateTime::ParseExact(OnlyTimeStr, "HH:mm:ss", enUS, DateTimeStyles::None);
	}

	return value;
	
} catch ( Exception^ ex ) {
	ThrowError(ex, "TimeFromFile");
	//LogMessage("","");
}
}


/***********************************************************************************************/
//Function to Get Start and End TimeIDs from Settings filename

		//Filename	:	STARTTIME_ENDTIME.ext
	
/***********************************************************************************************/
void TimeFromSettingFile(String^ filename, DateTime &Start, DateTime &End){
try{
	String^ name=Path::GetFileNameWithoutExtension(filename);
		array <String^>^ delimiter = {"_"};
	array<String^>^ FileElements=name->Split(delimiter,StringSplitOptions::RemoveEmptyEntries);

	CultureInfo^ enUS =  gcnew CultureInfo("en-US"); 
	Start =DateTime::ParseExact(FileElements[0], "HH-mm-ss", enUS, DateTimeStyles::None);
	End =DateTime::ParseExact(FileElements[1], "HH-mm-ss", enUS, DateTimeStyles::None);
} catch ( Exception^ ex ) {
	ThrowError(ex, "TimeFromSettingFile");
	//LogMessage("","");
}	
}


/***********************************************************************************************/
//Function to Get new stack setting file
/***********************************************************************************************/
	
	String^ GetNewSettingsPath(String^ filename){
try{
		String^ Settingspath="";
		if(LoadTimeBasedSettings){
			
			
				DateTime FileTime=TimeFromFile(filename);
				Settingspath=GetTimeSettingfile(FileTime);
			
		}

		if(LoadImageSpecificSettings){
			String^ ID=IDfromImage(filename);
			String^ Result=GetImageSettingfile(ID);
			if(Result!=""){
			Settingspath=Result;
			}
		}
			

		return Settingspath;
		//if image specific settings on
		//if image name matches, upload Corresponding SettingFilePath
		//if Time based settings, if time matches return setting file path

} catch ( Exception^ ex ) {
	ThrowError(ex, "GetNewSettingsPath");
	//LogMessage("","");
}
	
	}

/***********************************************************************************************/
//Function to get Time setting file according to file time
/***********************************************************************************************/
String^ GetTimeSettingfile(DateTime time)
{
try{
for(int i=0;i<TimeSpecificSettingFiles->Length; i++){
	DateTime StartMonitor, EndMonitor;
	TimeFromSettingFile(TimeSpecificSettingFiles[i],StartMonitor,EndMonitor);
	

	if((DateTime::Compare(time,StartMonitor)>=0)&&(DateTime::Compare(time,EndMonitor)<=0)){
		return TimeSpecificSettingFiles[i];
	}
 
}

return "";
} catch ( Exception^ ex ) {
	ThrowError(ex, "GetTimeSettingfile");
	//LogMessage("","");
}
}
/***********************************************************************************************/
//Function to get Image ID settings file
/***********************************************************************************************/
String^ GetImageSettingfile(String^ ID)
{
try{
for(int i=0;i<ImageSpecificSettingFiles->Length; i++){

	if(ID->Contains(IDfromSettings(ImageSpecificSettingFiles[i]))==true){
		
	return ImageSpecificSettingFiles[i];
	}
}
return "";
} catch ( Exception^ ex ) {
	ThrowError(ex, "GetImageSettingfile");
	//LogMessage("","");
}
}


private:
/***********************************************************************************************/
//Function to select desired region of an image
/***********************************************************************************************/
void SelectRegion();
/***********************************************************************************************/
//Function to Detect a Dir change
/***********************************************************************************************/
HANDLE DetectDirChange();
/***********************************************************************************************/
//Function to initialize directory monitoring for dinamic batch processing
/***********************************************************************************************/
void initMonitor(LPCTSTR sz,BOOL b, DWORD size);
/***********************************************************************************************/
//Function to open a dir for dinamic batch monitoring
/***********************************************************************************************/
HANDLE OpenDirectory(LPCTSTR sz);
/***********************************************************************************************/
//Function use a backup buffer for dinamic batch monitoring
/***********************************************************************************************/
void BackupBuffer(DWORD dwSize);
/***********************************************************************************************/
//Function to Get newly added files for dinamic batch monitoring
/***********************************************************************************************/
String^ GetNewFile(HANDLE _hDirectory );
/***********************************************************************************************/
//Function to identify if there is any file remaining for processing in dinamic batch processing
/***********************************************************************************************/
bool isFileRemaining();
/***********************************************************************************************/
//Function to Get the remaining files for processing
/***********************************************************************************************/
String^ GetRemainingFile();
/***********************************************************************************************/
//Function to stop the dinamic batch monitoring
/***********************************************************************************************/
public:void StopDinamicMonitor(Thread ^trd);
/***********************************************************************************************/
//Function to Get left half of the image
/***********************************************************************************************/
public:Bitmap^ TopThird(Bitmap^ image);
/***********************************************************************************************/
//Function to Get right half of the image
/***********************************************************************************************/
public:Bitmap^ BottomTwoThird(Bitmap^ image);
/***********************************************************************************************/
//Function to Get custom portion of an image
/***********************************************************************************************/
public:Bitmap^ CustomPortion(Bitmap^ image);
/***********************************************************************************************/
//Function to show custom portion of an image
/***********************************************************************************************/
Bitmap^ ShowCustomPortion(Bitmap^ image);

	   
};


