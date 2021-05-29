#include "StdAfx.h"
#include "IPOHandling.h"

// Required parameter for ReadDirectoryChangesW().
	 OVERLAPPED	m_Overlapped;

// Data buffer for the request.
	// Since the memory is allocated by malloc, it will always
	// be aligned as required by ReadDirectoryChangesW().
	 vector<BYTE> m_Buffer;

	// Double buffer strategy so that we can issue a new read
	// request before we process the current buffer.
	 vector<BYTE> m_BackupBuffer;


IPOHandling::IPOHandling(void)
{
}
/***********************************************************************************************/
//Function to Detect a Directory change
/***********************************************************************************************/

HANDLE IPOHandling::DetectDirChange()
{								
	String^ FolderPath=InputDirPath;
	IntPtr ptr = Marshal::StringToHGlobalAnsi(FolderPath);
	this->initMonitor(LPCTSTR(ptr.ToPointer()),false,16384);
	HANDLE _hDirectory =OpenDirectory(LPCTSTR(ptr.ToPointer()));
	Marshal::FreeHGlobal(ptr);
	return _hDirectory;
}


/***********************************************************************************************/
//Function to init dinamic batch monitor
/***********************************************************************************************/

void IPOHandling::initMonitor(LPCTSTR sz,BOOL b, DWORD size)
{
	//m_pServer		= pServer;
	
	m_bChildren		= b;
	m_wstrDirectory	= sz;
	m_hDirectory	= 0;

	::ZeroMemory((void*)&m_Overlapped, sizeof(OVERLAPPED));
	m_Buffer.resize(size);
	m_BackupBuffer.resize(size);
}
/***********************************************************************************************/
//Function to OpenDirectory  for dinamic batch monitoring
/***********************************************************************************************/

HANDLE IPOHandling::OpenDirectory(LPCTSTR sz)
{
	// Allow this routine to be called redundantly.
	//if (m_hDirectory)
	//	return m_hDirectory;

	m_hDirectory = ::CreateFile(
		sz,//m_wstrDirectory,					// pointer to the file name
		FILE_LIST_DIRECTORY,                // access (read/write) mode
		FILE_SHARE_READ						// share mode
		 | FILE_SHARE_WRITE
		 | FILE_SHARE_DELETE,
		NULL,                               // security descriptor
		OPEN_EXISTING,                      // how to create
		FILE_FLAG_BACKUP_SEMANTICS			// file attributes
		 | FILE_FLAG_OVERLAPPED,
		NULL);                              // file with attributes to copy

	if (m_hDirectory == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	return m_hDirectory;
}

/***********************************************************************************************/
//Function to make a backup buffer
/***********************************************************************************************/

void  IPOHandling::BackupBuffer(DWORD dwSize)
{
		// We could just swap back and forth between the two
		// buffers, but this code is easier to understand and debug.
		memcpy(&m_BackupBuffer[0], &m_Buffer[0], dwSize);
}
/***********************************************************************************************/
//Function to Get a newly added file
/***********************************************************************************************/

String^ IPOHandling::GetNewFile(HANDLE _hDirectory )
{	
	for (;;)
	{
	DWORD dwBytes=0;	// This call needs to be reissued after every APC.
	BOOL success = ::ReadDirectoryChangesW(
	_hDirectory,						// handle to directory
	&m_Buffer[0],                       // read results buffer
	m_Buffer.size(),					// length of buffer
	m_bChildren,                        // monitoring option
	FILE_NOTIFY_CHANGE_LAST_WRITE|FILE_NOTIFY_CHANGE_CREATION|FILE_NOTIFY_CHANGE_FILE_NAME,        // filter conditions
	&dwBytes,                           // bytes returned
	NULL,                      // overlapped buffer
	NULL);
	const int max_path=200;
	pBase = (char*)&m_Buffer[0];
	String^ FolderPath=InputDirPath;
	//FILE_NOTIFY_INFORMATION fni;
	
	
	//fni1=
	for(;;){
	FILE_NOTIFY_INFORMATION& fni= (FILE_NOTIFY_INFORMATION&)*pBase;
	if(fni.Action==FILE_ACTION_ADDED){
		char filename[MAX_PATH]={0};
		memcpy(filename,fni.FileName,fni.FileNameLength) ;
		String ^ wstrFilename=gcnew String(filename,0,fni.FileNameLength, Encoding::Unicode);
		String ^ OnlyName =gcnew String(wstrFilename);
		// Handle a trailing backslash, such as for a root directory.
		if (filename[0] != '\\')
			wstrFilename = FolderPath + L"\\" + wstrFilename;
		else
			wstrFilename = FolderPath + wstrFilename;	
		// If it could be a short filename, expand it.
		IntPtr ptr = Marshal::StringToHGlobalUni(wstrFilename);
		LPCWSTR wszFilename =(LPCWSTR)filename ;//PathFindFileNameW((LPCWSTR)ptr.ToPointer());
		
		int len = lstrlenW(wszFilename);
		// The maximum length of an 8.3 filename is twelve, including the dot.
		if (len <= 12 && wcschr(wszFilename, L'~'))
		{
			// Convert to the long filename form. Unfortunately, this
			// does not work for deletions, so it's an imperfect fix.
			char wbuf[MAX_PATH];
			if (::GetLongPathName((LPCSTR)ptr.ToPointer(),(LPSTR) wbuf, _countof (wbuf)) > 0)
				{String^ newfilename=gcnew String(wbuf);
			wstrFilename=newfilename;}
			Marshal::FreeHGlobal(ptr);
		}
		
		//m_pSONerver->m_pBase->Push(fni.Action, wstrFilename);
		//The image processing code should go here
		if(fni.Action==FILE_ACTION_ADDED)
		//ProcessImage(wstrFilename,OnlyName);
		return wstrFilename;
		}
	
	
	if (!fni.NextEntryOffset)
			break;
	pBase += fni.NextEntryOffset;
	}
	
	}
		return "";

}

/***********************************************************************************************/
//Function to check if any newly added file remaining for processing
/***********************************************************************************************/

bool IPOHandling::isFileRemaining(){
	FILE_NOTIFY_INFORMATION& fni = (FILE_NOTIFY_INFORMATION&)*pBase;
	if(!pBase) return false;
	
	for(;;){

	if (!fni.NextEntryOffset)
		return false;

	pBase += fni.NextEntryOffset;
	fni = (FILE_NOTIFY_INFORMATION&)*pBase;
	
	if (fni.Action==FILE_ACTION_ADDED)
		return true;
	
	
	}
	
}
/***********************************************************************************************/
//Function get the remaining files in dinamic batch processing
/***********************************************************************************************/

String^ IPOHandling::GetRemainingFile(){

	String^ FolderPath=InputDirPath;
	FILE_NOTIFY_INFORMATION& fni = (FILE_NOTIFY_INFORMATION&)*pBase;
	
    fni = (FILE_NOTIFY_INFORMATION&)*pBase;
	if(fni.Action==FILE_ACTION_ADDED)
		{
		char filename[MAX_PATH]={0};
		memcpy(filename,fni.FileName,fni.FileNameLength) ;
		
		String ^ wstrFilename=gcnew String(filename,0,fni.FileNameLength, Encoding::Unicode);
		String ^ OnlyName =gcnew String(wstrFilename);
		// Handle a trailing backslash, such as for a root directory.
		if (filename[0] != '\\')
			wstrFilename = FolderPath + L"\\" + wstrFilename;
		else
		wstrFilename = FolderPath + wstrFilename;	
		// If it could be a short filename, expand it.
		IntPtr ptr = Marshal::StringToHGlobalUni(wstrFilename);
		LPCWSTR wszFilename =(LPCWSTR)filename ;//PathFindFileNameW((LPCWSTR)ptr.ToPointer());
		
		int len = lstrlenW(wszFilename);
		// The maximum length of an 8.3 filename is twelve, including the dot.
		if (len <= 12 && wcschr(wszFilename, L'~'))
		{
			// Convert to the long filename form. Unfortunately, this
			// does not work for deletions, so it's an imperfect fix.
			char wbuf[MAX_PATH];
			if (::GetLongPathName((LPCSTR)ptr.ToPointer(),(LPSTR) wbuf, _countof (wbuf)) > 0)
				{String^ newfilename=gcnew String(wbuf);
			wstrFilename=newfilename;}
			Marshal::FreeHGlobal(ptr);
		}
		
		//m_pSONerver->m_pBase->Push(fni.Action, wstrFilename);
		//The image processing code should go here
		if(fni.Action==FILE_ACTION_ADDED)
		//ProcessImage(wstrFilename,OnlyName);
		return wstrFilename;
		}

	return "";
}

/***********************************************************************************************/
//Function to Detect a Dir change
/***********************************************************************************************/

void IPOHandling::StopDinamicMonitor(Thread ^trd){

	if(InputDirPath!=""){
		FileStream^ fs =File::Create(InputDirPath+ L"\\" +"dummy.txt");
	if ( fs )
		delete (IDisposable^)fs;

	if(trd&&trd->IsAlive)
		trd->Join(2000);

	File::Delete(InputDirPath+ L"\\" +"dummy.txt");
	}
}


#include "OpenCV.h"


/***********************************************************************************************/
//Function to crop left half portion of imgae
/***********************************************************************************************/

Bitmap^ IPOHandling::TopThird(Bitmap^ image){
	OpenCV CV;
	return CV.TopThird(image);
	
}
/***********************************************************************************************/
//Function to get right portion of image
/***********************************************************************************************/

Bitmap^ IPOHandling::BottomTwoThird(Bitmap^ image){
	OpenCV CV;
	return CV.BottomTwoThird(image);
	
}
/***********************************************************************************************/
//Function to get right portion of image
/***********************************************************************************************/

Bitmap^ IPOHandling::CustomPortion(Bitmap^ image){
	OpenCV CV;
	return CV.SliceCustomPortion(image,this->CornerA,this->CornerB,this->CornerC,this->CornerD);
	
}
/***********************************************************************************************/
//Function to draw custom portion of image
/***********************************************************************************************/

Bitmap^ IPOHandling::ShowCustomPortion(Bitmap^ image){
	OpenCV CV;
	return CV.DrawCustomPortion(image,this->CornerA,this->CornerB,this->CornerC,this->CornerD);
	
}
/***********************************************************************************************/
//Function to slice custom portion of image
/***********************************************************************************************/

void IPOHandling::SelectRegion(){
	/*
		if(Image){
		if(this->ImageTopThird)
			Image=TopThird(this->Image);
		else if (this->ImageBottomTwoThird)
			Image=TopThird(this->Image);
		else if (this->ImageWhole)
			Image=CustomPortion(this->Image);
		else if (this->ImageCustom)
			Image=CustomPortion(Image);
		}
		*/
}
	



