long _hread(
  HFILE hFile,      // handle to file
  LPVOID lpBuffer,  // pointer to buffer for read data
  long lBytes       // length, in bytes, of data buffer
);

long _hwrite(
  HFILE hFile,      // handle to file
  LPCSTR lpBuffer,  // pointer to buffer for data to be written
  long lBytes       // number of bytes to write
);
 
HFILE _lclose(
  HFILE hFile   // handle to file to close
);
 
HFILE _lcreat(
  LPCSTR lpPathName,  // pointer to name of file to open
  int iAttribute      // file attribute
);
 
LONG _llseek(
  HFILE hFile,  // handle to file
  LONG lOffset, // number of bytes to move
  int iOrigin   // position to move from
);
 
HFILE _lopen(
  LPCSTR lpPathName,  // pointer to name of file to open
  int iReadWrite      // file access mode
);
 
UINT _lread(
  HFILE hFile,      // handle to file
  LPVOID lpBuffer,  // pointer to buffer for read data
  UINT uBytes       // length, in bytes, of data buffer
);
 
UINT _lwrite(
  HFILE hFile,      // handle to file
  LPCSTR lpBuffer,  // pointer to buffer for data to be written
  UINT uBytes       // number of bytes to write
);
 
BOOL AbnormalTermination(VOID);

int AbortDoc(
  HDC hdc   // handle to device context
);
 
BOOL AbortPath(
  HDC hdc   // handle to device context
);

BOOL AbortPrinter(
  HANDLE hPrinter   // handle to printer object
);
 
BOOL CALLBACK AbortProc(
  HDC hdc,     // handle to device context
  int iError   // error value
);
 
BOOL AbortSystemShutdown(
  LPTSTR lpMachineName   // pointer to name of computer to stop 
                         // shutting down
);
 
BOOL AccessCheck(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,   // security descriptor
  HANDLE ClientToken,               // handle to client access token
  DWORD DesiredAccess,              // requested access rights 
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  PPRIVILEGE_SET PrivilegeSet,      // receives privileges used
  LPDWORD PrivilegeSetLength,       // size of privilege-set buffer
  LPDWORD GrantedAccess,     // retrieves mask of granted rights
  LPBOOL AccessStatus        // retrieves results of access check
);
 
BOOL AccessCheckAndAuditAlarm(
  LPCTSTR SubsystemName,     // subsystem name
  LPVOID HandleId,           // object's handle identifier
  LPTSTR ObjectTypeName,     // type of object
  LPTSTR ObjectName,         // name of object
  PSECURITY_DESCRIPTOR SecurityDescriptor,
                             // address of security descriptor
  DWORD DesiredAccess,       // mask for requested access rights
  PGENERIC_MAPPING GenericMapping,
                             // address of GENERIC_MAPPING
  BOOL ObjectCreation,       // flag is TRUE if creating an object
  LPDWORD GrantedAccess,     // retrieves mask of granted rights
  LPBOOL AccessStatus        // retrieves results of access check
  LPBOOL pfGenerateOnClose   // retrieves flag for audit generation
);
 
BOOL AccessCheckByType(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,   // security descriptor
  PSID PrincipalSelfSid,            // SID of object being checked
  HANDLE ClientToken,               // handle to client access token
  DWORD DesiredAccess,              // requested access rights 
  POBJECT_TYPE_LIST ObjectTypeList, // array of object types
  DWORD ObjectTypeListLength,       // number of object type elements
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  PPRIVILEGE_SET PrivilegeSet,      // receives privileges used
  LPDWORD PrivilegeSetLength,       // size of privilege-set buffer
  LPDWORD GrantedAccess,     // retrieves mask of granted rights
  LPBOOL AccessStatus        // retrieves results of access check
);
 
BOOL AccessCheckByTypeAndAuditAlarm(
  LPCTSTR SubsystemName,            // subsystem name
  LPVOID HandleId,                  // object's handle identifier
  LPCTSTR ObjectTypeName,           // type of object
  LPCTSTR ObjectName,               // name of object
  PSECURITY_DESCRIPTOR pSecurityDescriptor,   // security descriptor
  PSID PrincipalSelfSid,            // SID of object being checked
  DWORD DesiredAccess,              // requested access rights 
  AUDIT_EVENT_TYPE AuditType,       // type of audit 
  DWORD Flags,          // allows access check if no audit privilege
  POBJECT_TYPE_LIST ObjectTypeList, // array of object types
  DWORD ObjectTypeListLength,       // number of object type elements
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  BOOL ObjectCreation,       // flag is TRUE if creating an object
  LPDWORD GrantedAccess,     // retrieves mask of granted rights
  LPBOOL AccessStatus        // retrieves results of access check
  LPBOOL pfGenerateOnClose   // retrieves flag for audit generation
);
 
BOOL AccessCheckByTypeResultList(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,   // security descriptor
  PSID PrincipalSelfSid,            // SID of object being checked
  HANDLE ClientToken,               // handle to client access token
  DWORD DesiredAccess,              // requested access rights 
  POBJECT_TYPE_LIST ObjectTypeList, // array of object types
  DWORD ObjectTypeListLength,       // number of object type elements
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  PPRIVILEGE_SET PrivilegeSet,      // receives privileges used
  LPDWORD PrivilegeSetLength,       // size of privilege-set buffer
  LPDWORD GrantedAccessList,  // retrieves array of granted rights
  LPDWORD AccessStatusList    // retrieves array of results flags
);
 
BOOL AccessCheckByTypeResultListAndAuditAlarm(
  LPCTSTR SubsystemName,            // subsystem name
  LPVOID HandleId,                  // object's handle identifier
  LPCTSTR ObjectTypeName,           // type of object
  LPCTSTR ObjectName,               // name of object
  PSECURITY_DESCRIPTOR pSecurityDescriptor,   // security descriptor
  PSID PrincipalSelfSid,            // SID of object being checked
  DWORD DesiredAccess,              // requested access rights 
  AUDIT_EVENT_TYPE AuditType,       // type of audit 
  DWORD Flags,          // allows access check if no audit privilege
  POBJECT_TYPE_LIST ObjectTypeList, // array of object types
  DWORD ObjectTypeListLength,       // number of object type elements
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  BOOL ObjectCreation,        // flag is TRUE if creating an object
  LPDWORD GrantedAccessList,  // retrieves array of granted rights
  LPDWORD AccessStatusList,   // retrieves array of results flags
  LPBOOL pfGenerateOnClose    // retrieves flag for audit generation
);
 
ACSLAN_STATUS AcsLan(
  PLLC_CCB pCcb,       // pointer to the command control block
  PLLC_CCB *ppBadCcb   // pointer to a pointer to an invalid CCB
);
 
HKL ActivateKeyboardLayout(
  HKL hkl,     // handle to keyboard layout
  UINT Flags   // keyboard layout flags
);
 
BOOL AddAccessAllowedAce(
  PACL pAcl,            // pointer to access-control list
  DWORD dwAceRevision,  // ACL revision level
  DWORD AccessMask,     // access mask
  PSID pSid             // pointer to security identifier
);
 
BOOL AddAccessAllowedAceEx(
  PACL pAcl,            // pointer to an ACL
  DWORD dwAceRevision,  // ACL revision level
  DWORD AceFlags,       // ACE inheritance flags
  DWORD AccessMask,     // access mask for the new ACE
  PSID pSid             // SID of the trustee for the new ACE
);
 
BOOL AddAccessAllowedObjectAce(
  PACL pAcl,             // pointer to an ACL
  DWORD dwAceRevision,   // ACL revision level
  DWORD AceFlags,        // ACE inheritance flags
  DWORD AccessMask,      // access mask for the new ACE
  GUID *ObjectTypeGuid,  // type of object protected by the ACE
  GUID *InheritedObjectTypeGuid,  
                         // type of object that can inherit the ACE
  PSID pSid              // SID of the trustee for the new ACE
);
 
BOOL AddAccessDeniedAce(
  PACL pAcl,            // pointer to access-control list
  DWORD dwAceRevision,  // ACL revision level
  DWORD AccessMask,     // access mask
  PSID pSid             // pointer to security identifier
);
 
BOOL AddAccessDeniedAceEx(
  PACL pAcl,            // pointer to an ACL
  DWORD dwAceRevision,  // ACL revision level
  DWORD AceFlags,       // ACE inheritance flags
  DWORD AccessMask,     // access mask for the new ACE
  PSID pSid             // SID of the trustee for the new ACE
);
 
BOOL AddAccessDeniedObjectAce(
  PACL pAcl,             // pointer to an ACL
  DWORD dwAceRevision,   // ACL revision level
  DWORD AceFlags,        // ACE inheritance flags
  DWORD AccessMask,      // access mask for the new ACE
  GUID *ObjectTypeGuid,  // type of object protected by the ACE
  GUID *InheritedObjectTypeGuid,  
                         // type of object that can inherit the ACE
  PSID pSid              // SID of the trustee for the new ACE
);
 
BOOL AddAce(
  PACL pAcl,             // pointer to access-control list
  DWORD dwAceRevision,   // ACL revision level
  DWORD dwStartingAceIndex,  // index of ACE position in ACL
  LPVOID pAceList,       // pointer to one or more ACEs
  DWORD nAceListLength   // size of buffer for ACEs
);
 
ATOM AddAtom(
  LPCTSTR lpString   // pointer to string to add
);
 
BOOL AddAuditAccessAce(
  PACL pAcl,           // pointer to access-control list
  DWORD dwAceRevision, // ACL revision level
  DWORD dwAccessMask,  // access mask
  PSID pSid,           // pointer to security identifier
  BOOL bAuditSuccess,  // flag for auditing successful access
  BOOL bAuditFailure   // flag for auditing unsuccessful access 
                       // attempts
);
 
BOOL AddAuditAccessAceEx(
  PACL pAcl,            // pointer to an ACL
  DWORD dwAceRevision,  // ACL revision level
  DWORD AceFlags,       // flags for ACE inheritance and audit type
  DWORD dwAccessMask,   // access mask for the new ACE
  PSID pSid,            // SID of the trustee for the new ACE
  BOOL bAuditSuccess,   // audit successful access attempts
  BOOL bAuditFailure    // audit unsuccessful access attempts
);
 
BOOL AddAuditAccessObjectAce(
  PACL pAcl,             // pointer to an ACL
  DWORD dwAceRevision,   // ACL revision level
  DWORD AceFlags,        // ACE inheritance flags
  DWORD AccessMask,      // access mask for the new ACE
  GUID *ObjectTypeGuid,  // type of object protected by the ACE
  GUID *InheritedObjectTypeGuid,  
                         // type of object that can inherit the ACE
  PSID pSid,             // SID of the trustee for the new ACE
  BOOL bAuditSuccess,    // audit successful access attempts
  BOOL bAuditFailure     // audit unsuccessful access attempts
);
 
int AddFontResource(
  LPCTSTR lpszFilename   // pointer to font-resource filename
);
 
BOOL AddForm(
  HANDLE hPrinter,  // handle to printer object
  DWORD Level,      // data-structure level
  LPBYTE pForm      // pointer to form info. data structure
);
 
BOOL AddJob(
  HANDLE hPrinter,  // specifies printer for the print job
  DWORD Level,      // specifies version of print job information 
                    // data structure
  LPBYTE pData,     // pointer to buffer to receive print job 
                    // information data
  DWORD cbBuf,      // specifies size of buffer pointed to by pData
  LPDWORD pcbNeeded 
                    // pointer to variable to receive size of print 
                    // job information data
);
 
BOOL AddMonitor(
  LPTSTR pName,      // pointer to server name
  DWORD Level,       // monitor info. structure level
  LPBYTE pMonitors   // pointer to monitor info. structure
);
 
BOOL AddPort(
  LPTSTR pName,         // pointer to a server name
  HWND hWnd,            // handle to parent window
  LPTSTR pMonitorName   // pointer to a monitor name
);
 
HANDLE AddPrinter(
  LPTSTR pName,     // pointer to server name
  DWORD Level,      // printer info. structure level
  LPBYTE pPrinter   // pointer to structure
);
 
BOOL AddPrinterConnection(
  LPTSTR pName   // pointer to printer name
);
 
BOOL AddPrinterDriver(
  LPTSTR pName,        // pointer to server name
  DWORD Level,         // printer info. structure level
  LPBYTE pDriverInfo   // pointer to printer info. structure
);
 
BOOL AddPrinterDriverEx(
  LPTSTR pName,           // pointer to server name
  DWORD Level,            // printer info. structure level
  LPBYTE pDriverInfo,     // pointer to printer info. structure
  DWORD dwFileCopyFlags   // pointer to printer info. structure
);
 
BOOL AddPrintProcessor(
  LPTSTR pName,                // pointer to server name
  LPTSTR pEnvironment,         // pointer to environment name
  LPTSTR pPathName,            // pointer to path
  LPTSTR pPrintProcessorName   // pointer to print-processor name
);
 
BOOL AddPrintProvidor(
  LPTSTR pName, // reserved, must be NULL 
  DWORD Level,  // provider information structure level
  LPBYTE pProvidorInfo 
                // pointer to provider information structure
);
 
BOOL AdjustTokenGroups(
  HANDLE TokenHandle,      // handle to token that contains groups
  BOOL ResetToDefault,     // flag for default settings
  PTOKEN_GROUPS NewState,  // address of address of new group 
                           // information
  DWORD BufferLength,      // size of buffer for previous information
  PTOKEN_GROUPS PreviousState,
                           // address of previous group information
  PDWORD ReturnLength      // address of required buffer size
);
 
BOOL AdjustTokenPrivileges(
  HANDLE TokenHandle,  // handle to token that contains privileges
  BOOL DisableAllPrivileges,
                       // flag for disabling all privileges
  PTOKEN_PRIVILEGES NewState,
                       // pointer to new privilege information
  DWORD BufferLength,  // size, in bytes, of the PreviousState buffer
  PTOKEN_PRIVILEGES PreviousState,
                       // receives original state of changed 
                       // privileges
  PDWORD ReturnLength  // receives required size of the 
                       // PreviousState buffer
);
 
BOOL AdjustWindowRect(
  LPRECT lpRect,  // pointer to client-rectangle structure
  DWORD dwStyle,  // window styles
  BOOL bMenu      // menu-present flag
);
 
BOOL AdjustWindowRectEx(
  LPRECT lpRect,    // pointer to client-rectangle structure
  DWORD dwStyle,    // window styles
  BOOL bMenu,       // menu-present flag
  DWORD dwExStyle   // extended style
);
 
LONG AdvancedDocumentProperties(
  HWND hWnd,           // handle to dialog box's parent window
  HANDLE hPrinter,     // handle to printer object
  LPTSTR pDeviceName,  // pointer to driver name
  PDEVMODE pDevModeOutput,
                       // pointer to modified device mode structure
  PDEVMODE pDevModeInput   // pointer to original device mode 
                           // structure
);
 
BOOL AllocateAndInitializeSid(
  PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
                            // pointer to identifier authority
  BYTE nSubAuthorityCount,  // count of subauthorities
  DWORD dwSubAuthority0,    // subauthority 0
  DWORD dwSubAuthority1,    // subauthority 1
  DWORD dwSubAuthority2,    // subauthority 2
  DWORD dwSubAuthority3,    // subauthority 3
  DWORD dwSubAuthority4,    // subauthority 4
  DWORD dwSubAuthority5,    // subauthority 5
  DWORD dwSubAuthority6,    // subauthority 6
  DWORD dwSubAuthority7,    // subauthority 7
  PSID *pSid                // pointer to pointer to SID
);
 
BOOL AllocateLocallyUniqueId(
  PLUID Luid     // address of locally unique identifier
);
 
BOOL AllocConsole(VOID);
 
AlphaBlend(
  HDC hdcDest,
  int nXOriginDest,
  int nYOriginDest,
  int nWidthDest,
  int hHeightDest,
  HDC hdcSrc,
  int nXOriginSrc,
  int nYOriginSrc,
  int nWidthSrc,
  int nHeightSrc,
  BLENDFUNCTION blendFunction
);
 
BOOL AngleArc(
  HDC hdc,            // handle to device context
  int X,              // x-coordinate of circle's center
  int Y,              // y-coordinate of circle's center
  DWORD dwRadius,     // circle's radius
  FLOAT eStartAngle,  // arc's start angle
  FLOAT eSweepAngle   // arc's sweep angle
);
 
BOOL AnimatePalette(
  HPALETTE hpal,            // handle to logical color palette
  UINT iStartIndex,         // first entry in logical palette
  UINT cEntries,            // count of entries in logical palette
  CONST PALETTEENTRY *ppe   // pointer to first replacement
);
 
BOOL AnimateWindow(
  HWND hwnd,     // handle to the window to animate
  DWORD dwTime,  // duration of animation
  DWORD dwFlags  // animation type
);
 
BOOL AnyPopup(VOID);
 
BOOL AppendMenu(
  HMENU hMenu,      // handle to menu to be changed
  UINT uFlags,      // menu-item flags
  UINT uIDNewItem,  // menu-item identifier or handle to drop-down menu or submenu
  LPCTSTR lpNewItem // menu-item content
);
 
BOOL ApplyCallbackFunction(
  COLORMATCHSETUP *pColorMatchSetup,
  LPARAM lParam
);
 
BOOL Arc(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coord of bounding rectangle's upper-left corner
  int nTopRect,    // y-coord of bounding rectangle's upper-left corner
  int nRightRect,  // x-coord of bounding rectangle's lower-right corner
  int nBottomRect, // y-coord of bounding rectangle's lower-right corner
  int nXStartArc,  // first radial ending point
  int nYStartArc,  // first radial ending point
  int nXEndArc,    // second radial ending point
  int nYEndArc     // second radial ending point
);
 
BOOL ArcTo(
  HDC hdc,          // handle to device context
  int nLeftRect,    // x-coord of bounding rectangle's upper-left corner
  int nTopRect,     // y-coord of bounding rectangle's upper-left corner
  int nRightRect,   // x-coord of bounding rectangle's lower-right corner
  int nBottomRect,  // y-coord of bounding rectangle's lower-right corner
  int nXRadial1,    // x-coord of the first radial ending point
  int nYRadial1,    // y-coord of the first radial ending point
  int nXRadial2,    // x-coord of the second radial ending point
  int nYRadial2     // y-coord of the second radial ending point
);
 
BOOL AreAllAccessesGranted(
  DWORD GrantedAccess,  // access mask for granted access rights
  DWORD DesiredAccess   // access mask for requested access rights
);
 
BOOL AreAnyAccessesGranted(
  DWORD GrantedAccess,  // access mask for granted access rights
  DWORD DesiredAccess   // access mask for access rights requested
);
 
BOOL AreFileApisANSI(VOID);
 
UINT ArrangeIconicWindows(
  HWND hWnd   // handle to parent window
);
 
BOOL AssignProcessToJobObject(
  HANDLE hJob,
  HANDLE hProcess
);
 
BOOL WINAPI AssociateColorProfileWithDevice(
  PCTSTR pMachineName,  // reserved, must be NULL
  PCTSTR pProfileName,  // file name containing device profile
  PCTSTR pDeviceName    // name of device
);
 
BOOL AttachThreadInput(
  DWORD idAttach,    // thread to attach
  DWORD idAttachTo,  // thread to attach to
  BOOL fAttach       // attach or detach
);
 
BOOL BackupEventLog(
  HANDLE hEventLog,          // handle to event log
  LPCTSTR lpBackupFileName   // name of backup file
);
 
BOOL BackupRead(
  HANDLE hFile,                // handle to file or directory
  LPBYTE lpBuffer,             // pointer to buffer to read to
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  LPDWORD lpNumberOfBytesRead, // pointer to variable to receive 
                               // number of bytes read
  BOOL bAbort,                 // termination type
  BOOL bProcessSecurity,       // process security flag
  LPVOID *lpContext            // pointer to pointer to internal 
                               // context information
);
 
BOOL BackupSeek(
  HANDLE hFile,       // handle to open file
  DWORD dwLowBytesToSeek,
                      // low-order 32 bits of number of bytes
  DWORD dwHighBytesToSeek,
                      // high-order 32 bits of number of bytes
  LPDWORD lpdwLowByteSeeked,
                      // pointer to number of bytes function seeks
  LPDWORD lpdwHighByteSeeked,
                      // pointer to number of bytes function seeks
  LPVOID *lpContext   //pointer to internal context information
);
 
BOOL BackupWrite(
  HANDLE hFile,                 // handle to file or directory
  LPBYTE lpBuffer,              // pointer to buffer containing data 
                                // to write
  DWORD nNumberOfBytesToWrite,  // number of bytes to write
  LPDWORD lpNumberOfBytesWritten,  // pointer to variable to receive 
                                   // number of bytes written
  BOOL bAbort,                  // termination type
  BOOL bProcessSecurity,        // process security
  LPVOID *lpContext             // pointer to pointer to internal 
                                // context information
);
 
BOOL Beep(
  DWORD dwFreq,      // sound frequency, in hertz
  DWORD dwDuration   // sound duration, in milliseconds
);
 
HDWP BeginDeferWindowPos(
  int nNumWindows   // number of windows
);
 
HDC BeginPaint(
  HWND hwnd,  // handle to window
  LPPAINTSTRUCT lpPaint
              // pointer to structure for paint information
);
 
BOOL BeginPath(
  HDC hdc   // handle to device context
);
 
HANDLE BeginUpdateResource(
  LPCTSTR pFileName,             // pointer to executable file name
  BOOL bDeleteExistingResources  // deletion option
);
 
BOOL BindImage(
  IN LPSTR ImageName,  
  IN LPSTR DllPath,    
  IN LPSTR SymbolPath  
);
 
BOOL BindImageEx(
  IN DWORD Flags,                            
  IN LPSTR ImageName,                        
  IN LPSTR DllPath,                          
  IN LPSTR SymbolPath,                       
  IN PIMAGEHLP_STATUS_ROUTINE StatusRoutine  
);
 
BOOL BitBlt(
  HDC hdcDest, // handle to destination device context
  int nXDest,  // x-coordinate of destination rectangle's upper-left 
               // corner
  int nYDest,  // y-coordinate of destination rectangle's upper-left 
               // corner
  int nWidth,  // width of destination rectangle
  int nHeight, // height of destination rectangle
  HDC hdcSrc,  // handle to source device context
  int nXSrc,   // x-coordinate of source rectangle's upper-left 
               // corner
  int nYSrc,   // y-coordinate of source rectangle's upper-left 
               // corner
  DWORD dwRop  // raster operation code
);
 
BOOL BringWindowToTop(
  HWND hWnd   // handle to window
);
 
long BroadcastSystemMessage(
  DWORD dwFlags,            
  LPDWORD lpdwRecipients,   
  UINT uiMessage,           
  WPARAM wParam,            
  LPARAM lParam             
);
 
BOOL BuildCommDCB(
  LPCTSTR lpDef,  // pointer to device-control string
  LPDCB lpDCB     // pointer to device-control block
);
 
BOOL BuildCommDCBAndTimeouts(
  LPCTSTR lpDef,                  // pointer to device-control string
  LPDCB lpDCB,                    // pointer to device-control block
  LPCOMMTIMEOUTS  lpCommTimeouts  // pointer to comm time-out structure
);
 
VOID BuildExplicitAccessWithName(
  PEXPLICIT_ACCESS pExplicitAccess,
                        // pointer to the structure to initialize
  LPTSTR pTrusteeName,  // name of the trustee to put in the 
                        // structure
  DWORD AccessPermissions,  // access mask to put in the structure
  ACCESS_MODE AccessMode,  // access mode to put in the structure
  DWORD Inheritance     // inheritance type to put in the structure
);
 
DWORD BuildSecurityDescriptor(
  PTRUSTEE pOwner,  // identifies owner for new security descriptor
  PTRUSTEE pGroup,  // identifies group for new security descriptor
  ULONG cCountOfAccessEntries,
                    // number of access-control entries in the list
  PEXPLICIT_ACCESS pListOfAccessEntries,
                    // pointer to list of access-control entries for 
                    // DACL
  ULONG cCountOfAuditEntries,
                    // number of audit-control entries in the list
  PEXPLICIT_ACCESS pListOfAuditEntries,
                    // pointer to list of audit-control entries for 
                    // SACL
  PSECURITY_DESCRIPTOR pOldSD,
                    // pointer to an existing security descriptor
  PULONG pSizeNewSD,
                    // pointer to the size of the new security 
                    // descriptor
  PSECURITY_DESCRIPTOR * pNewSD
                    // pointer that receives the new security 
                    // descriptor
);
 
VOID BuildTrusteeWithName(
  PTRUSTEE pTrustee,  // pointer to the structure to initialize
  LPTSTR pName        // name of the trustee to put in the structure
);
 
VOID BuildTrusteeWithSid(
  PTRUSTEE pTrustee,  // pointer to the structure to initialize
  PSID pSid           // name of the trustee to put in the structure
);
 
BOOL CallMsgFilter(
  LPMSG lpMsg,  // pointer to structure with message data
  int nCode     // hook code
);
 
BOOL CallNamedPipe(
  LPCTSTR lpNamedPipeName,  // pointer to pipe name
  LPVOID lpInBuffer,        // pointer to write buffer
  DWORD nInBufferSize,      // size, in bytes, of write buffer
  LPVOID lpOutBuffer,       // pointer to read buffer
  DWORD nOutBufferSize,     // size, in bytes, of read buffer
  LPDWORD lpBytesRead,      // pointer to number of bytes read
  DWORD nTimeOut            // time-out value, in milliseconds
);
 
LRESULT CallNextHookEx(
  HHOOK hhk,      // handle to current hook
  int nCode,      // hook code passed to hook procedure
  WPARAM wParam,  // value passed to hook procedure
  LPARAM lParam   // value passed to hook procedure
);
 
LRESULT CallWindowProc(
  WNDPROC lpPrevWndFunc,  // pointer to previous procedure
  HWND hWnd,              // handle to window
  UINT Msg,               // message
  WPARAM wParam,          // first message parameter
  LPARAM lParam           // second message parameter
);
 
LRESULT CALLBACK CallWndProc(
  int nCode,      // hook code
  WPARAM wParam,  // current-process flag
  LPARAM lParam   // address of structure with message data
);
 
LRESULT CALLBACK CallWndRetProc(
  int nCode,     // hook code
  WPARAM wParam, // current-process flag
  LPARAM lParam  // address of structure with message data
);
 
BOOL CancelDC(
  HDC hdc   // handle to device context
);
 
BOOL CancelDeviceWakeupRequest(
  HANDLE hDevice   // handle to object or device
);
 
BOOL CancelIo(
  HANDLE hFile  // file handle for which to cancel I/O
);
 
DWORD CancelOverlappedAccess(
  PACTRL_OVERLAPPED pOverlapped  // pointer to the structure filled 
                                 // in by the asynchronous call
);
 
BOOL CancelWaitableTimer(
  HANDLE hTimer  // handle to a timer object
);
 
WORD WINAPI CascadeWindows(
  HWND hwndParent,        // handle to parent window
  UINT wHow,              // types of windows not to arrange
  CONST RECT *lpRect,     // rectangle to arrange windows in
  UINT cKids,             // number of windows to arrange
  const HWND FAR *lpKids  // array of window handles
);
 
LRESULT CALLBACK CBTProc(
  int nCode,      // hook code
  WPARAM wParam,  // depends on hook code
  LPARAM lParam   // depends on hook code
);
 
UINT CALLBACK CCHookProc(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
UINT CALLBACK CFHookProc(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL ChangeClipboardChain(
  HWND hWndRemove,  // handle to window to remove
  HWND hWndNewNext  // handle to next window
);
 
LONG ChangeDisplaySettings(
  LPDEVMODE lpDevMode,  
  DWORD dwflags         
);
 
LONG ChangeDisplaySettingsEx(
  LPCSTR lpszDeviceName,
  LPDEVMODE lpDevMode,  
  HWND     hwnd,
  DWORD dwflags         
  LPVOID lParam
);
 
BOOL ChangeServiceConfig(
  SC_HANDLE hService     // handle to service
  DWORD dwServiceType,   // type of service
  DWORD dwStartType,     // when to start service
  DWORD dwErrorControl,  // severity if service fails to start
  LPCTSTR lpBinaryPathName,  // pointer to service binary file name
  LPCTSTR lpLoadOrderGroup,  // pointer to load ordering group name
  LPDWORD lpdwTagId,     // pointer to variable to get tag identifier
  LPCTSTR lpDependencies,    // pointer to array of dependency names
  LPCTSTR lpServiceStartName,
                             // pointer to account name of service
  LPCTSTR lpPassword,   // pointer to password for service account
  LPCTSTR lpDisplayName      // pointer to display name
);
 
BOOL ChangeServiceConfig2(
  SC_HANDLE hService,
  DWORD dwInfoLevel,
  LPVOID lpInfo
);
 
LPTSTR CharLower(
  LPTSTR lpsz   // single character or pointer to string
);
 
DWORD CharLowerBuff(
  LPTSTR lpsz,      // pointer to buffer containing characters to 
                    // process
  DWORD cchLength   // number of bytes or characters to process
);
 
LPTSTR CharNext(
  LPCTSTR lpsz   // pointer to current character
);
 
LPSTR CharNextExA(
  WORD CodePage,          // identifier of the code page
  LPCSTR lpCurrentChar,   // pointer to current character
  DWORD dwFlags           // reserved; must be zero
);
 
LPTSTR CharPrev(
  LPCTSTR lpszStart,    // pointer to first character
  LPCTSTR lpszCurrent   // pointer to current character
);
 
LPSTR CharPrevExA(
  WORD CodePage,          // identifier of code page
  LPCSTR lpStart,         // pointer to first character
  LPCSTR lpCurrentChar,   // pointer to current character
  DWORD dwFlags           // reserved; must be zero
);
 
BOOL CharToOem(
  LPCTSTR lpszSrc,  // pointer to string to translate
  LPSTR lpszDst     // pointer to translated string
);
 
BOOL CharToOemBuff(
  LPCTSTR lpszSrc,    // pointer to string to translate
  LPSTR lpszDst,      // pointer to translated string
  DWORD cchDstLength  // length of string to translate, in characters
);
 
LPTSTR CharUpper(
  LPTSTR lpsz   // single character or pointer to string
);
 
DWORD CharUpperBuff(
  LPTSTR lpsz,      // pointer to buffer containing characters to process
  DWORD cchLength   // number of characters to process
);
 
BOOL WINAPI CheckBitmapBits(
  HTRANSFORM hColorTransform,
  PVOID pSrcBits,
  BMFORMAT bmInput, 
  DWORD dwWidth,
  DWORD dwHeight, 
  DWORD dwStride, 
  PBYTE paResult,
  PBMCALLBACKFN pfnCallback, 
  LPARAM lpCallbackData
);
 
BOOL WINAPI CheckColors(
  HTRANSFORM hColorTransform,
  PCOLOR paInputColors, 
  DWORD nColors,
  COLORTYPE ctInput,
  PBYTE paResult 
);
 
BOOL WINAPI CheckColorsInGamut(
  HDC hDC,              // device context handle
  LPVOID lpRGBTriples,  // array of RGB triples
  LPVOID lpBuffer,      // buffer for results
  UINT nCount           // number of triples
);
 
BOOL CheckDlgButton(
  HWND hDlg,      // handle to dialog box
  int nIDButton,  // button-control identifier
  UINT uCheck     // check state
);
 
DWORD CheckMenuItem(
  HMENU hmenu,        // handle to menu
  UINT uIDCheckItem,  // menu item to check or uncheck
  UINT uCheck         // menu item flags
);
 
BOOL CheckMenuRadioItem(
  HMENU hmenu,   
  UINT idFirst,  
  UINT idLast,   
  UINT idCheck,  
  UINT uFlags    
);
 
BOOL CheckRadioButton(
  HWND hDlg,          // handle to dialog box
  int nIDFirstButton, // identifier of first radio button in group
  int nIDLastButton,  // identifier of last radio button in group
  int nIDCheckButton  // identifier of radio button to select
);
 
PIMAGE_NT_HEADERS CheckSumMappedFile(
  IN LPVOID BaseAddress,  
  IN DWORD FileLength,    
  OUT LPDWORD HeaderSum,  
  OUT LPDWORD CheckSum    
);
 
BOOL CheckTokenMembership(
  HANDLE TokenHandle,  // handle to an access token
  PSID SidToCheck,     // SID to check for 
  PBOOL IsMember       // receives results of the check 
);
 
HWND ChildWindowFromPoint(
  HWND hWndParent,  // handle to parent window
  POINT Point       // structure with point coordinates
);
 
HWND ChildWindowFromPointEx(
  HWND hwndParent,   // handle to parent window
  POINT pt,          // structure with point coordinates
  UINT uFlags        // skipping flags
);
 
BOOL ChooseColor(
  LPCHOOSECOLOR lpcc   // pointer to structure with initialization 
                       // data
);
 
BOOL ChooseFont(
  LPCHOOSEFONT lpcf   // pointer to structure with initialization 
                      // data
);
 
BOOL Chord(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coord of the upper-left corner of bounding rectangle
  int nTopRect,    // y-coord of the upper-left corner of bounding rectangle
  int nRightRect,  // x-coord of the lower-right corner of bounding rectangle
  int nBottomRect, // y-coord of the lower-right corner of bounding rectangle
  int nXRadial1,   // x-coord of the first radial's endpoint
  int nYRadial1,   // y-coord of the first radial's endpoint
  int nXRadial2,   // x-coord of the second radial's endpoint
  int nYRadial2    // y-coord of the second radial's endpoint
);
 
BOOL ClearCommBreak(
  HANDLE hFile   // handle to communications device
);
 
BOOL ClearCommError(
  HANDLE hFile,     // handle to communications device
  LPDWORD lpErrors, // pointer to variable to receive error codes
  LPCOMSTAT lpStat  // pointer to buffer for communications status
);
 
BOOL ClearEventLog(
  HANDLE hEventLog,          // handle to event log
  LPCTSTR lpBackupFileName   // name of backup file
);
 
BOOL ClientToScreen(
  HWND hWnd,       // window handle for source coordinates
  LPPOINT lpPoint  // pointer to structure containing screen coordinates
);
 
BOOL ClipCursor(
  CONST RECT *lpRect   // pointer to structure with rectangle
);
 
BOOL CloseClipboard(VOID);
 
BOOL WINAPI CloseColorProfile(
  HPROFILE hProfile
);
 
BOOL CloseDesktop(
  HDESK hDesktop  // handle to desktop to close
);
 
HENHMETAFILE CloseEnhMetaFile(
  HDC hdc   // handle to an enhanced-metafile device context
);
 
BOOL CloseEventLog(
  HANDLE hEventLog   // handle to event log
);
 
BOOL CloseFigure(
  HDC hdc   // handle to device context
);
 
BOOL CloseHandle(
  HANDLE hObject   // handle to object to close
);
 
HMETAFILE CloseMetaFile(
  HDC hdc   // handle to metafile device context
);
 
BOOL ClosePrinter(
  HANDLE hPrinter   // handle to printer object
);
 
VOID CloseRaw(
  PVOID pvContext
);
 
BOOL CloseServiceHandle(
  SC_HANDLE hSCObject   // handle to service or service control 
                        // manager database
);
 
BOOL CloseWindow(
  HWND hWnd   // handle to window to minimize
);
 
BOOL CloseWindowStation(
  HWINSTA hWinSta  // handle to window station to close
);
 
BOOL WINAPI CMCheckColors(
  HCMTRANSFORM hcmTransform,  // transform handle
  LPCOLOR lpaInputColors,     // array of COLORs
  DWORD nColors,              // COLOR array size
  COLORTYPE ctInput,          // input color type
  LPBYTE lpaResult            // buffer for results
);
 
BOOL WINAPI CMCheckColorsInGamut(
  HCMTRANSFORM hcmTransform,  // transform handle
  RGBTRIPLE *lpaRGBTriple,    // RGB triple array
  LPBYTE lpaResult,           // buffer for results
  UINT nCount                 // result buffer size
);
 
BOOL WINAPI CMCheckRGBs(
  HCMTRANSFORM hcmTransform,
  LPVOID lpSrcBits,
  BMFORMAT bmInput, 
  DWORD dwWidth,
  DWORD dwHeight,
  DWORD dwStride, 
  LPBYTE lpaResult, 
  PBMCALLBACKFN pfnCallback,
  ULONG ulCallbackData 
);
 
BOOL WINAPI CMConvertColorNameToIndex(
  HPROFILE hProfile, 
  PCOLOR_NAME paColorName,
  PDWORD paIndex,
  DWORD dwCount
);
 
BOOL WINAPI CMConvertIndexToColorName(
  HPROFILE hProfile,
  PDWORD paIndex,
  PCOLOR_NAME paColorName,
  DWORD dwCount
);
 
BOOL WINAPI CMCreateDeviceLinkProfile(
  LPHPROFILE lpahProfiles,  // array of profiles
  DWORD nProfiles,          // profile array size
  LPBYTE *lpProfileData     // pointer to pointer to buffer
);
 
HCMTRANSFORM CMCreateMultiProfileTransform(
  LPHPROFILE lpahProfiles,  // array of profile handles
  DWORD nProfiles,          // profile handle array size
  PDWORD padwIntents,       // array of rendering intents
  DWORD nIntents,           // intent array size
  DWORD dwFlags             // transform creation flags
);
 
BOOL WINAPI CMCreateProfile(
  LPLOGCOLORSPACEA lpColorSpace,  // pointer to a color space
  LPBYTE *lpProfileData           // pointer to pointer to buffer
);
 
BOOL WINAPI CMCreateProfileW(
  LPLOGCOLORSPACEW lpColorSpace,  // pointer to a color space
  LPBYTE *lpProfileData           // pointer to pointer to buffer
);
 
HCMTRANSFORM WINAPI CMCreateTransform(
  LPLOGCOLORSPACEA lpColorSpace,       // color space pointer
  LPDEVCHARACTER lpDevCharacter,       // profile file name
  LPDEVCHARACTER lpTargetDevCharacter  // target profile file name
);
 
HCMTRANSFORM WINAPI CMCreateTransformExt(
  LPLOGCOLORSPACEA lpColorSpace,        // color space pointer
  LPDEVCHARACTER lpDevCharacter,        // profile file name
  LPDEVCHARACTER lpTargetDevCharacter,  // target profile file name
  DWORD dwFlags                         // creation flags
);
 
HCMTRANSFORM WINAPI CMCreateTransformExtW(
  LPLOGCOLORSPACEW lpColorSpace,        // color space pointer
  LPDEVCHARACTER lpDevCharacter,        // profile file name
  LPDEVCHARACTER lpTargetDevCharacter,  // target profile file name
  DWORD dwFlags                         // creation flags
);
 
HCMTRANSFORM WINAPI CMCreateTransformW(
  LPLOGCOLORSPACEW lpColorSpace,       // color space pointer
  LPDEVCHARACTER lpDevCharacter,       // profile file name
  LPDEVCHARACTER lpTargetDevCharacter  // target profile file name
);
 
BOOL WINAPI CMDeleteTransform(
  HCMTRANSFORM hcmTransform
);
 
DWORD WINAPI CMGetInfo(
  DWORD dwInfo  
);
 
BOOL WINAPI CMGetNamedProfileInfo(
  HPROFILE hProfile,
  PNAMED_PROFILE_INFO pNamedProfileInfo
);
 
BOOL WINAPI CMGetPS2ColorRenderingDictionary(
  HPROFILE hProfile, 
  DWORD dwIntent, 
  LPBYTE lpBuffer, 
  LPDWORD lpcbSize, 
  LPBOOL lpbBinary 
);
 
BOOL WINAPI CMGetPS2ColorRenderingIntent(
  HPROFILE hProfile, 
  DWORD dwIntent, 
  LPBYTE lpBuffer, 
  LPDWORD lpcbSize 
);
 
BOOL WINAPI CMGetPS2ColorSpaceArray(
  HPROFILE hProfile, 
  DWORD dwIntent, 
  DWORD dwCSAType, 
  LPBYTE lpBuffer, 
  LPDWORD lpcbSize, 
  LPBOOL lpbBinary 
);
 
BOOL WINAPI CMIsProfileValid(
  HPROFILE hProfile, 
  LPBOOL lpbValid 
);
 
BOOL WINAPI CMTranslateColors(
  HCMTRANSFORM hcmTransform, 
  LPCOLOR lpaInputColors, 
  DWORD nColors, 
  COLORTYPE ctInput, 
  LPCOLOR lpaOutputColors, 
  COLORTYPE ctOutput 
);
 
BOOL WINAPI CMTranslateRGB(
  HCMTRANSFORM hcmTransform,
  COLORREF ColorRef, 
  LPCOLORREF lpColorRef, 
  DWORD dwFlags 
);
 
BOOL WINAPI CMTranslateRGBs(
  HCMTRANSFORM hcmTransform,
  LPVOID lpSrcBits, 
  BMFORMAT bmInput, 
  DWORD dwWidth, 
  DWORD dwHeight, 
  DWORD dwStride,
  LPVOID lpDestBits, 
  BMFORMAT bmOutput, 
  DWORD dwTranslateDirection
);
 
BOOL WINAPI CMTranslateRGBsExt(
  HCMTRANSFORM hcmTransform, 
  LPVOID lpSrcBits,
  BMFORMAT bmInput,
  DWORD dwWidth, 
  DWORD dwHeight,
  DWORD dwInputStride, 
  LPVOID lpDestBits,
  BMFORMAT bmOutput, 
  DWORD dwOutputStride,
  LPBMCALLBACKFN lpfnCallback,
  ULONG ulCallbackData
);
 
BOOL WINAPI ColorCorrectPalette(
  HDC hDC,
  HPALETTE hPalette, 
  DWORD dwFirstEntry,
  DWORD dwNumOfEntries
);
 
BOOL WINAPI ColorMatchToTarget(
  HDC hDC,
  HDC hdcTarget,
  DWORD uiAction 
);
 
int CombineRgn(
  HRGN hrgnDest,      // handle to destination region
  HRGN hrgnSrc1,      // handle to source region
  HRGN hrgnSrc2,      // handle to source region
  int fnCombineMode   // region combining mode
);
 
BOOL CombineTransform(
  LPXFORM lpxformResult,  // pointer to combined transformation
  CONST XFORM *lpxform1,  // pointer to first transformation
  CONST XFORM *lpxform2   // pointer to second transformation
);
 
LPWSTR CommandLineToArgvW(
  LPCWSTR lpCmdLine,  // pointer to a command-line string
  int *pNumArgs       // pointer to a variable that receives the 
                      // argument count
);
 
BOOL CommConfigDialog(
  LPTSTR lpszName,   // pointer to device name string
  HWND hWnd,         // handle to window
  LPCOMMCONFIG lpCC  // pointer to comm configuration structure
);
 
DWORD CommDlgExtendedError(VOID);
 
LONG CompareFileTime(
  CONST FILETIME *lpFileTime1,  // pointer to first file time
  CONST FILETIME *lpFileTime2   // pointer to second file time
);
 
int CompareString(
  LCID Locale,       // locale identifier
  DWORD dwCmpFlags,  // comparison-style options
  LPCTSTR lpString1, // pointer to first string
  int cchCount1,     // size, in bytes or characters, of first string
  LPCTSTR lpString2, // pointer to second string
  int cchCount2      // size, in bytes or characters, of second string
);
 
BOOL ConfigurePort(
  LPTSTR pName,      // pointer to server name
  HWND hWnd,         // handle to parent window of the dialog box
  LPTSTR pPortName   // pointer to port name
);
 
BOOL ConnectNamedPipe(
  HANDLE hNamedPipe,          // handle to named pipe to connect
  LPOVERLAPPED lpOverlapped   // pointer to overlapped structure
);
 
HANDLE ConnectToPrinterDlg(
  HWND hwnd,    // handle to parent window of dialog box
  DWORD Flags   // reserved for future use, must be zero
);
 
BOOL ContinueDebugEvent(
  DWORD dwProcessId,       // process to continue
  DWORD dwThreadId,        // thread to continue
  DWORD dwContinueStatus   // continuation status
);
 
BOOL ControlService(
  SC_HANDLE hService,  // handle to service
  DWORD dwControl,     // control code
  LPSERVICE_STATUS lpServiceStatus 
                       // pointer to service status structure
);
 
DWORD ConvertAccessToSecurityDescriptor(
  PACTRL_ACCESS pAccessList,  
                    // pointer to the access-control information
  PACTRL_AUDIT pAuditList,
                    // pointer to the audit-control information
  LPCTSTR lpOwner,  // name of the object's owner
  LPCTSTR lpGroup,  // name of the object's primary group
  PSECURITY_DESCRIPTOR *ppSecDescriptor
                    // receives a pointer to the new security 
                    // descriptor
);
 
BOOL WINAPI ConvertColorNameToIndex(
  HPROFILE hProfile, 
  PCOLOR_NAME paColorName,
  PDWORD paIndex,
  DWORD dwCount
);
 
LCID ConvertDefaultLocale(
  LCID Locale   // default locale value to be converted
);
 
BOOL WINAPI ConvertIndexToColorName(
  HPROFILE hProfile,
  PDWORD paIndex,
  PCOLOR_NAME paColorName,
  DWORD dwCount
);
 
DWORD ConvertSecurityDescriptorToAccess(
  HANDLE hObject,             // handle to the associated object
  SE_OBJECT_TYPE ObjectType,  // type of object
  PSECURITY_DESCRIPTOR pSecDescriptor,
                              // pointer to a security descriptor
  PACTRL_ACCESS *ppAccessList,
                    // receives a pointer to access-control info
  PACTRL_AUDIT *ppAuditList,
                    // receives a pointer to audit-control info
  LPTSTR *lppOwner, // receives the name of the object's owner
  LPTSTR *lppGroup  // receives the name of the object's primary group
);
 
DWORD ConvertSecurityDescriptorToAccessNamed(
  LPCTSTR lpObject,           // name of the associated object
  SE_OBJECT_TYPE ObjectType,  // type of object
  PSECURITY_DESCRIPTOR pSecDescriptor,
                    // pointer to the object's security descriptor
  PACTRL_ACCESS *ppAccessList,
                    // receives a pointer to access-control info
  PACTRL_AUDIT *ppAuditList,
                    // receives a pointer to audit-control info
  LPTSTR *lppOwner, // receives the name of the object's owner
  LPTSTR *lppGroup  // receives the name of the object's primary group
);
 
LPVOID ConvertThreadToFiber(
  LPVOID lpParameter  // fiber data for new fiber
);
 
BOOL ConvertToAutoInheritPrivateObjectSecurity(
  PSECURITY_DESCRIPTOR ParentDescriptor, 
                            // security descriptor of parent object
  PSECURITY_DESCRIPTOR CurrentSecurityDescriptor, 
                            // current security descriptor of object
  PSECURITY_DESCRIPTOR * NewSecurityDescriptor, 
                            // receives new security descriptor
  GUID * ObjectType,        // type of object
  BOOLEAN IsDirectoryObject,       // identifies container objects
  PGENERIC_MAPPING GenericMapping  // map generic to specific rights
);
 
int CopyAcceleratorTable(
  HACCEL hAccelSrc,   // handle to accelerator table to copy
  LPACCEL lpAccelDst, // pointer to structure receiving copy
  int cAccelEntries   // number of entries in table being copied
);
 
HCURSOR CopyCursor(
  HCURSOR pcur   // handle to cursor to copy
);
 
HENHMETAFILE CopyEnhMetaFile(
  HENHMETAFILE hemfSrc,  // handle to an enhanced metafile
  LPCTSTR lpszFile       // pointer to a filename string
);
 
BOOL CopyFile(
  LPCTSTR lpExistingFileName,
                          // pointer to name of an existing file
  LPCTSTR lpNewFileName,  // pointer to filename to copy to
  BOOL bFailIfExists      // flag for operation if file exists
);
 
BOOL CopyFileEx(
  LPCWSTR lpExistingFileName,
                    // pointer to name of an existing file
  LPCWSTR lpNewFileName,
                    // pointer to filename to copy to
  LPPROGRESS_ROUTINE lpProgressRoutine,
                    // pointer to the callback function
  LPVOID lpData,    // to be passed to the callback function
  LPBOOL pbCancel,  // flag that can be used to cancel the operation
  DWORD dwCopyFlags // flags that specify how the file is copied
);
 
HICON CopyIcon(
  HICON hIcon   // handle to icon to copy
);
 
HANDLE CopyImage(
  HANDLE hImage,  // handle to the image to copy
  UINT uType,     // type of image to copy
  int cxDesired,  // desired width of new image
  int cyDesired,  // desired height of new image
  UINT fuFlags    // copy flags
);
 
VOID CopyMemory(
  PVOID Destination,  // pointer to address of copy destination
  CONST VOID *Source, // pointer to address of block to copy
  DWORD Length        // size, in bytes, of block to copy
);
 
VOID CopyMemoryVlm (
  PVOID64 Destination,  // pointer to address of copy destination
  PVOID64 Source,       // pointer to address of block to copy
  DWORD Length          // size, in bytes, of block to copy
);
 
HMETAFILE CopyMetaFile(
  HMETAFILE hmfSrc,  // handle to a Windows-format metafile
  LPCTSTR lpszFile   // pointer to a filename string
);
 
DWORD CALLBACK CopyProgressRoutine(
  LARGE_INTEGER TotalFileSize,  // total file size, in bytes
  LARGE_INTEGER TotalBytesTransferred,
                            // total number of bytes transferred
  LARGE_INTEGER StreamSize,  // total number of bytes for this stream
  LARGE_INTEGER StreamBytesTransferred,
                            // total number of bytes transferred for 
                            // this stream
  DWORD dwStreamNumber,     // the current stream
  DWORD dwCallbackReason,   // reason for callback
  HANDLE hSourceFile,       // handle to the source file
  HANDLE hDestinationFile,  // handle to the destination file
  LPVOID lpData             // passed by CopyFileEx
);
 
BOOL CopyRect(
  LPRECT lprcDst,      // pointer to structure for destination rectangle
  CONST RECT *lprcSrc  // pointer to structure for source rectangle
);
 
BOOL CopySid(
  DWORD nDestinationSidLength,  // size of buffer for copied SID
  PSID pDestinationSid,         // pointer to buffer for copied SID
  PSID pSourceSid               // pointer to source SID
);
 
int CountClipboardFormats(VOID);
 
HACCEL CreateAcceleratorTable(
  LPACCEL lpaccl,  // pointer to structure array with accelerator data
  int cEntries     // number of structures in the array
);
 
HBITMAP CreateBitmap(
  int nWidth,         // bitmap width, in pixels
  int nHeight,        // bitmap height, in pixels
  UINT cPlanes,       // number of color planes used by device
  UINT cBitsPerPel,   // number of bits required to identify a color
  CONST VOID *lpvBits // pointer to array containing color data
);
 
HBITMAP CreateBitmapIndirect(
  CONST BITMAP *lpbm    // pointer to the bitmap data
);
 
HBRUSH CreateBrushIndirect(
  CONST LOGBRUSH *lplb   // pointer to structure describing brush
);
 
BOOL CreateCaret(
  HWND hWnd,        // handle to owner window
  HBITMAP hBitmap,  // handle to bitmap for caret shape
  int nWidth,       // caret width
  int nHeight       // caret height
);
 
HCOLORSPACE WINAPI CreateColorSpace(
  LPLOGCOLORSPACE lpLogColorSpace  
);
 
HTRANSFORM WINAPI CreateColorTransform(
  LPLOGCOLORSPACE pLogColorSpace,
  HPROFILE hDestProfile,
  HPROFILE hTargetProfile,
  DWORD dwFlags
);
 
HBITMAP CreateCompatibleBitmap(
  HDC hdc,        // handle to device context
  int nWidth,     // width of bitmap, in pixels
  int nHeight     // height of bitmap, in pixels
);
 
HDC CreateCompatibleDC(
  HDC hdc   // handle to the device context
);
 
HANDLE CreateConsoleScreenBuffer(
  DWORD dwDesiredAccess,  // access flag
  DWORD dwShareMode,      // buffer share mode
  LPSECURITY_ATTRIBUTES *lpSecurityAttributes,
                          // pointer to security attributes
  DWORD dwFlags,          // type of buffer to create
  LPVOID lpScreenBufferData   // reserved
);
 
HCURSOR CreateCursor(
  HINSTANCE hInst,         // handle to application instance
  int xHotSpot,            // horizontal position of hot spot
  int yHotSpot,            // vertical position of hot spot
  int nWidth,              // cursor width
  int nHeight,             // cursor height
  CONST VOID *pvANDPlane,  // pointer to AND bitmask array
  CONST VOID *pvXORPlane   // pointer to XOR bitmask array
);
 
HDC CreateDC(
  LPCTSTR lpszDriver,  // pointer to string specifying driver name
  LPCTSTR lpszDevice,  // pointer to string specifying device name
  LPCTSTR lpszOutput,  // do not use; set to NULL
  CONST DEVMODE *lpInitData 
                       // pointer to optional printer data
);
 
HDESK CreateDesktop(
  LPCTSTR lpszDesktop,    // name of the new desktop
  LPCTSTR lpszDevice,     // reserved; must be NULL.
  LPDEVMODE pDevMode,     // reserved; must be NULL
  DWORD dwFlags,          // flags to control interaction with other 
                          // applications
  DWORD dwDesiredAccess,  // specifies access of returned handle
  LPSECURITY_ATTRIBUTES lpsa  // specifies security attributes of 
                              // the desktop
);
 
BOOL WINAPI CreateDeviceLinkProfile(
  PHPROFILE pahProfiles,
  DWORD nProfiles,
  PDWORD padwIntent,
  DWORD nIntents,
  DWORD dwFlags,
  PBYTE *pProfileData,
  DWORD indexPreferredCMM 
);
 
HWND CreateDialog(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpTemplate,   // identifies dialog box template name
  HWND hWndParent,      // handle to owner window
  DLGPROC lpDialogFunc  // pointer to dialog box procedure
);
 
HWND CreateDialogIndirect(
  HINSTANCE hInstance,        // handle to application instance
  LPCDLGTEMPLATE lpTemplate,  // pointer to dialog box template
  HWND hWndParent,            // handle to owner window
  DLGPROC lpDialogFunc        // pointer to dialog box procedure
);
 
HWND CreateDialogIndirectParam(
  HINSTANCE hInstance,        // handle to application instance
  LPCDLGTEMPLATE lpTemplate,  // pointer to dialog box template
  HWND hWndParent,            // handle to owner window
  DLGPROC lpDialogFunc,       // pointer to dialog box procedure
  LPARAM lParamInit           // initialization value
);
 
HWND CreateDialogParam(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpTemplateName,  // identifies dialog box template
  HWND hWndParent,      // handle to owner window
  DLGPROC lpDialogFunc, // pointer to dialog box procedure
  LPARAM dwInitParam    // initialization value
);
 
HBITMAP CreateDIBitmap(
  HDC hdc,                  // handle to device context
  CONST BITMAPINFOHEADER *lpbmih,  // pointer to bitmap size and
                                   // format data
  DWORD fdwInit,            // initialization flag
  CONST VOID *lpbInit,      // pointer to initialization data
  CONST BITMAPINFO *lpbmi,  // pointer to bitmap color-format data
  UINT fuUsage              // color-data usage
);
 
HBRUSH CreateDIBPatternBrush(
  HGLOBAL hglbDIBPacked,  // handle to device-independent bitmap
  UINT fuColorSpec        // color table data
);
 
HBRUSH CreateDIBPatternBrushPt(
  CONST VOID *lpPackedDIB,  // pointer to structure and bitmap bits
  UINT iUsage               // usage flags
);
 
HBITMAP CreateDIBSection(
  HDC hdc,          // handle to device context
  CONST BITMAPINFO *pbmi,
                    // pointer to structure containing bitmap size, 
                    // format, and color data
  UINT iUsage,      // color data type indicator: RGB values or 
                    // palette indexes
  VOID *ppvBits,    // pointer to variable to receive a pointer to 
                    // the bitmap's bit values
  HANDLE hSection,  // optional handle to a file mapping object
  DWORD dwOffset    // offset to the bitmap bit values within the 
                    // file mapping object
);
 
BOOL CreateDirectory(
  LPCTSTR lpPathName,                         // pointer to directory path string
  LPSECURITY_ATTRIBUTES lpSecurityAttributes  // pointer to security descriptor
);
 
BOOL CreateDirectoryEx(
  LPCTSTR lpTemplateDirectory,  // pointer to template directory path
  LPCTSTR lpNewDirectory,       // pointer to path of directory to create
  LPSECURITY_ATTRIBUTES lpSecurityAttributes  // pointer to security descriptor
);
 
HBITMAP CreateDiscardableBitmap(
  HDC hdc,     // handle to device context
  int nWidth,  // bitmap width
  int nHeight  // bitmap height
);
 
HRGN CreateEllipticRgn(
  int nLeftRect,   // x-coord of the upper-left corner of the bounding rectangle
  int nTopRect,    // y-coord of the upper-left corner of the bounding rectangle
  int nRightRect,  // x-coord of the lower-right corner of the bounding rectangle
  int nBottomRect  // y-coord of the lower-right corner of the bounding rectangle
);
 
HRGN CreateEllipticRgnIndirect(
  CONST RECT *lprc   // pointer to bounding rectangle
);
 
HDC CreateEnhMetaFile(
  HDC hdcRef,           // handle to a reference device context
  LPCTSTR lpFilename,   // pointer to a filename string
  CONST RECT *lpRect,   // pointer to a bounding rectangle
  LPCTSTR lpDescription // pointer to an optional description string
);
 
HANDLE CreateEvent(
  LPSECURITY_ATTRIBUTES lpEventAttributes,
                      // pointer to security attributes
  BOOL bManualReset,  // flag for manual-reset event
  BOOL bInitialState, // flag for initial state
  LPCTSTR lpName      // pointer to event-object name
);
 
LPVOID CreateFiber(
  DWORD dwStackSize,  // initial thread stack size, in bytes
  LPFIBER_START_ROUTINE lpStartAddress,
                      // pointer to fiber function
  LPVOID lpParameter  // argument for new fiber
);
 
HANDLE CreateFile(
  LPCTSTR lpFileName,          // pointer to name of the file
  DWORD dwDesiredAccess,       // access (read-write) mode
  DWORD dwShareMode,           // share mode
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                               // pointer to security attributes
  DWORD dwCreationDisposition,  // how to create
  DWORD dwFlagsAndAttributes,  // file attributes
  HANDLE hTemplateFile         // handle to file with attributes to 
                               // copy
);
 
HANDLE CreateFileMapping(
  HANDLE hFile,              // handle to file to map
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                             // optional security attributes
  DWORD flProtect,           // protection for mapping object
  DWORD dwMaximumSizeHigh,   // high-order 32 bits of object size
  DWORD dwMaximumSizeLow,    // low-order 32 bits of object size
  LPCTSTR lpName             // name of file-mapping object
);
 
HFONT CreateFont(
  int nHeight,             // logical height of font
  int nWidth,              // logical average character width
  int nEscapement,         // angle of escapement
  int nOrientation,        // base-line orientation angle
  int fnWeight,            // font weight
  DWORD fdwItalic,         // italic attribute flag
  DWORD fdwUnderline,      // underline attribute flag
  DWORD fdwStrikeOut,      // strikeout attribute flag
  DWORD fdwCharSet,        // character set identifier
  DWORD fdwOutputPrecision,  // output precision
  DWORD fdwClipPrecision,  // clipping precision
  DWORD fdwQuality,        // output quality
  DWORD fdwPitchAndFamily,  // pitch and family
  LPCTSTR lpszFace         // pointer to typeface name string
);
 
HFONT CreateFontIndirect(
  CONST LOGFONT *lplf   // pointer to logical font structure
);
 
HPALETTE CreateHalftonePalette(
  HDC hdc   // handle to device context
);
 
BOOL CreateHardLink(
  LPCTSTR lpFileName,
  LPCTSTR lpExistingFileName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
);
 
HBRUSH CreateHatchBrush(
  int fnStyle,      // hatch style
  COLORREF clrref   // color value
);
 
HDC CreateIC(
  LPCTSTR lpszDriver,  // pointer to string specifying driver name
  LPCTSTR lpszDevice,  // pointer to string specifying device name
  LPCTSTR lpszOutput,  // pointer to string specifying port or file 
                       // name
  CONST DEVMODE *lpdvmInit 
                       // pointer to optional initialization data
);
 
HICON CreateIcon(
  HINSTANCE hInstance,  // handle to application instance
  int nWidth,           // icon width
  int nHeight,          // icon height
  BYTE cPlanes,         // number of planes in XOR bitmask
  BYTE cBitsPixel,      // number of bits per pixel in XOR bitmask
  CONST BYTE *lpbANDbits,  // pointer to AND bitmask array
  CONST BYTE *lpbXORbits   // pointer to XOR bitmask array
);
 
HICON CreateIconFromResource(
  PBYTE presbits,  // pointer to icon or cursor bits
  DWORD dwResSize, // number of bytes in bit buffer
  BOOL fIcon,      // icon or cursor flag
  DWORD dwVer      // format version
);
 
HICON CreateIconFromResourceEx(
  PBYTE pbIconBits, // pointer to icon or cursor bits
  DWORD cbIconBits, // number of bytes in bit buffer
  BOOL fIcon,       // icon or cursor flag
  DWORD dwVersion,  // format version
  int cxDesired,    // desired width of icon or cursor
  int cyDesired,    // desired height of icon or cursor
  UINT uFlags       // load resource flags
);
 
HICON CreateIconIndirect(
  PICONINFO piconinfo   // pointer to icon information structure
);
 
HANDLE CreateIoCompletionPort (
  HANDLE FileHandle,              // file handle to associate with 
                                  // the I/O completion port
  HANDLE ExistingCompletionPort,  // handle to the I/O completion port
  DWORD CompletionKey,            // per-file completion key for I/O 
                                  // completion packets
  DWORD NumberOfConcurrentThreads // number of threads allowed to 
                                  // execute concurrently
);
 
HANDLE CreateJobObject(
  LPSECURITY_ATTRIBUTES lpJobAttributes,
  LPCTSTR lpName
);
 
HANDLE CreateMailslot(
  LPCTSTR lpName,         // pointer to string for mailslot name
  DWORD nMaxMessageSize,  // maximum message size
  DWORD lReadTimeout,     // milliseconds before read time-out
  LPSECURITY_ATTRIBUTES lpSecurityAttributes 
                          // pointer to security structure
);
 
HWND CreateMDIWindow(
  LPTSTR lpClassName,  // pointer to registered child class name
  LPTSTR lpWindowName, // pointer to window name
  DWORD dwStyle,       // window style
  int X,               // horizontal position of window
  int Y,               // vertical position of window
  int nWidth,          // width of window
  int nHeight,         // height of window
  HWND hWndParent,     // handle to parent window (MDI client)
  HINSTANCE hInstance, // handle to application instance
  LPARAM lParam        // application-defined value
);
 
HMENU CreateMenu(VOID);
 
HDC CreateMetaFile(
  LPCTSTR lpszFile   // pointer to filename string
);
 
HTRANSFORM WINAPI CreateMultiProfileTransform(
  PHPROFILE pahProfiles,
  DWORD nProfiles,
  PDWORD padwIntent,
  DWORD nIntents,
  DWORD dwFlags,
  DWORD indexPreferredCMM 
);
 
HANDLE CreateMutex(
  LPSECURITY_ATTRIBUTES lpMutexAttributes,
                       // pointer to security attributes
  BOOL bInitialOwner,  // flag for initial ownership
  LPCTSTR lpName       // pointer to mutex-object name
);
 
HANDLE CreateNamedPipe(
  LPCTSTR lpName,         // pointer to pipe name
  DWORD dwOpenMode,       // pipe open mode
  DWORD dwPipeMode,       // pipe-specific modes
  DWORD nMaxInstances,    // maximum number of instances
  DWORD nOutBufferSize,   // output buffer size, in bytes
  DWORD nInBufferSize,    // input buffer size, in bytes
  DWORD nDefaultTimeOut,  // time-out time, in milliseconds
  LPSECURITY_ATTRIBUTES lpSecurityAttributes  // pointer to security attributes
);
 
HPALETTE CreatePalette(
  CONST LOGPALETTE *lplgpl   // pointer to logical color palette
);
 
HBRUSH CreatePatternBrush(
  HBITMAP hbmp   // handle to bitmap
);
 
HPEN CreatePen(
  int fnPenStyle,    // pen style
  int nWidth,        // pen width
  COLORREF crColor   // pen color
);
 
HPEN CreatePenIndirect(
  CONST LOGPEN *lplgpn   // pointer to LOGPEN structure
);
 
BOOL CreatePipe(
  PHANDLE hReadPipe,                       // pointer to read handle
  PHANDLE hWritePipe,                      // pointer to write handle
  LPSECURITY_ATTRIBUTES lpPipeAttributes,  // pointer to security attributes
  DWORD nSize                              // pipe size
);
 
HRGN CreatePolygonRgn(
  CONST POINT *lppt,  // pointer to array of points
  int cPoints,        // number of points in array
  int fnPolyFillMode  // polygon-filling mode
);
 
HRGN CreatePolyPolygonRgn(
  CONST POINT *lppt,        // pointer to array of points
  CONST INT *lpPolyCounts,  // pointer to count of vertices
  int nCount,               // number of integers in array
  int fnPolyFillMode        // polygon fill mode
);
 
HMENU CreatePopupMenu(VOID);
 
BOOL CreatePrivateObjectSecurity(
  PSECURITY_DESCRIPTOR ParentDescriptor,
                           // pointer to parent directory SD
  PSECURITY_DESCRIPTOR CreatorDescriptor,
                           // pointer to creator SD
  PSECURITY_DESCRIPTOR *NewDescriptor,
                           // pointer to pointer to new SD
  BOOL IsDirectoryObject,  // container flag for new SD
  HANDLE Token,            // handle to client's access token
  PGENERIC_MAPPING GenericMapping 
                           // pointer to access-rights structure
);
 
BOOL CreatePrivateObjectSecurityEx(
  PSECURITY_DESCRIPTOR ParentDescriptor, 
                            // security descriptor of parent object
  PSECURITY_DESCRIPTOR CreatorDescriptor, 
                            // current security descriptor of object
  PSECURITY_DESCRIPTOR *NewDescriptor, 
                            // receives the new security descriptor
  GUID * ObjectType,        // type of object
  BOOL IsContainerObject,   // identifies container objects
  ULONG AutoInheritFlags,   // identifies container objects
  HANDLE Token,             // identifies container objects
  PGENERIC_MAPPING GenericMapping  // map generic to specific rights
);
 
BOOL CreateProcess(
  LPCTSTR lpApplicationName,
                         // pointer to name of executable module
  LPTSTR lpCommandLine,  // pointer to command line string
  LPSECURITY_ATTRIBUTES lpProcessAttributes,  // process security attributes
  LPSECURITY_ATTRIBUTES lpThreadAttributes,   // thread security attributes
  BOOL bInheritHandles,  // handle inheritance flag
  DWORD dwCreationFlags, // creation flags
  LPVOID lpEnvironment,  // pointer to new environment block
  LPCTSTR lpCurrentDirectory,   // pointer to current directory name
  LPSTARTUPINFO lpStartupInfo,  // pointer to STARTUPINFO
  LPPROCESS_INFORMATION lpProcessInformation  // pointer to PROCESS_INFORMATION
);
 
BOOL CreateProcessAsUser(
  HANDLE hToken,         // handle to a token representing the logged-on user
  LPCTSTR lpApplicationName,  // pointer to name of executable module
  LPTSTR lpCommandLine,       // pointer to command line string
  LPSECURITY_ATTRIBUTES lpProcessAttributes, // process security attributes
  LPSECURITY_ATTRIBUTES lpThreadAttributes,  // thread security attributes
  BOOL bInheritHandles,         // whether new process inherits handles
  DWORD dwCreationFlags,        // creation flags
  LPVOID lpEnvironment,         // pointer to new environment block
  LPCTSTR lpCurrentDirectory,   // pointer to current directory name
  LPSTARTUPINFO lpStartupInfo,  // pointer to STARTUPINFO
  LPPROCESS_INFORMATION lpProcessInformation  // pointer to PROCESS_INFORMATION
);
 
BOOL WINAPI CreateProfileFromLogColorSpace(
  LPLOGCOLORSPACE pLogColorSpace, 
  PBYTE *pBuffer
);
 
HRGN CreateRectRgn(
  int nLeftRect,   // x-coordinate of region's upper-left corner
  int nTopRect,    // y-coordinate of region's upper-left corner
  int nRightRect,  // x-coordinate of region's lower-right corner
  int nBottomRect  // y-coordinate of region's lower-right corner
);
 
HRGN CreateRectRgnIndirect(
  CONST RECT *lprc   // pointer to the rectangle
);
 
HANDLE CreateRemoteThread(
  HANDLE hProcess,        // handle to process to create thread in
  LPSECURITY_ATTRIBUTES lpThreadAttributes,  // pointer to security attributes
  DWORD dwStackSize,      // initial thread stack size, in bytes
  LPTHREAD_START_ROUTINE lpStartAddress, // pointer to thread function
  LPVOID lpParameter,     // argument for new thread
  DWORD dwCreationFlags,  // creation flags
  LPDWORD lpThreadId      // pointer to returned thread identifier
);
 
BOOL CreateRestrictedToken(
  HANDLE ExistingTokenHandle,   // handle to existing token
  DWORD Flags,       // flags to delete all privileges 
                     // or apply the deny-only attribute to all SIDs
  DWORD DisableSidCount,              // number of deny-only SIDs
  PSID_AND_ATTRIBUTES SidsToDisable,  // array of deny-only SIDs
  DWORD DeletePrivilegeCount,   // number of privileges to delete
  PLUID_AND_ATTRIBUTES PrivilegesToDelete,  // privileges to delete
  DWORD RestrictedSidCount,     // number of restricting SIDs
  PSID_AND_ATTRIBUTES SidsToRestrict,  // array of restricting SIDs
  PHANDLE NewTokenHandle        // receives handle to new token
);
 
HRGN CreateRoundRectRgn(
  int nLeftRect,      // x-coordinate of the region's upper-left corner
  int nTopRect,       // y-coordinate of the region's upper-left corner
  int nRightRect,     // x-coordinate of the region's lower-right corner
  int nBottomRect,    // y-coordinate of the region's lower-right corner
  int nWidthEllipse,  // height of ellipse for rounded corners
  int nHeightEllipse  // width of ellipse for rounded corners
);
 
BOOL CreateScalableFontResource(
  DWORD fdwHidden,      // flag for read-only embedded font
  LPCTSTR lpszFontRes,  // pointer to filename for font resource
  LPCTSTR lpszFontFile, // pointer to filename for scalable font
  LPCTSTR lpszCurrentPath   // pointer to path to font file
);
 
HANDLE CreateSemaphore(
  LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                       // pointer to security attributes
  LONG lInitialCount,  // initial count
  LONG lMaximumCount,  // maximum count
  LPCTSTR lpName       // pointer to semaphore-object name
);
 
SC_HANDLE CreateService(
  SC_HANDLE hSCManager,  // handle to service control manager 
                         // database
  LPCTSTR lpServiceName, // pointer to name of service to start
  LPCTSTR lpDisplayName, // pointer to display name
  DWORD dwDesiredAccess, // type of access to service
  DWORD dwServiceType,   // type of service
  DWORD dwStartType,     // when to start service
  DWORD dwErrorControl,  // severity if service fails to start
  LPCTSTR lpBinaryPathName,  // pointer to name of binary file
  LPCTSTR lpLoadOrderGroup,  // pointer to name of load ordering 
                             // group
  LPDWORD lpdwTagId,     // pointer to variable to get tag identifier
  LPCTSTR lpDependencies,  // pointer to array of dependency names
  LPCTSTR lpServiceStartName,
                           // pointer to account name of service
  LPCTSTR lpPassword       // pointer to password for service account
);
 
HBRUSH CreateSolidBrush(
  COLORREF crColor   // brush color value
);
 
DWORD CreateTapePartition(
  HANDLE hDevice,           // handle to open device
  DWORD dwPartitionMethod,  // type of new partition
  DWORD dwCount,            // number of new partitions to create
  DWORD dwSize              // size of new partition, in megabytes
);
 
HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES lpThreadAttributes,  // pointer to security attributes
  DWORD dwStackSize,                         // initial thread stack size
  LPTHREAD_START_ROUTINE lpStartAddress,     // pointer to thread function
  LPVOID lpParameter,                        // argument for new thread
  DWORD dwCreationFlags,                     // creation flags
  LPDWORD lpThreadId                         // pointer to receive thread ID
);
 
HANDLE WINAPI CreateToolhelp32Snapshot(
  DWORD dwFlags,       
  DWORD th32ProcessID  
);

HANDLE CreateWaitableTimer(
  LPSECURITY_ATTRIBUTES lpTimerAttributes,
                      // pointer to security attributes
  BOOL bManualReset,  // flag for manual reset state
  LPCTSTR lpTimerName // pointer to timer object name
);
 
HWND CreateWindow(
  LPCTSTR lpClassName,  // pointer to registered class name
  LPCTSTR lpWindowName, // pointer to window name
  DWORD dwStyle,        // window style
  int x,                // horizontal position of window
  int y,                // vertical position of window
  int nWidth,           // window width
  int nHeight,          // window height
  HWND hWndParent,      // handle to parent or owner window
  HMENU hMenu,          // handle to menu or child-window identifier
  HANDLE hInstance,     // handle to application instance
  LPVOID lpParam        // pointer to window-creation data
);
 
HWND CreateWindowEx(
  DWORD dwExStyle,      // extended window style
  LPCTSTR lpClassName,  // pointer to registered class name
  LPCTSTR lpWindowName, // pointer to window name
  DWORD dwStyle,        // window style
  int x,                // horizontal position of window
  int y,                // vertical position of window
  int nWidth,           // window width
  int nHeight,          // window height
  HWND hWndParent,      // handle to parent or owner window
  HMENU hMenu,          // handle to menu, or child-window identifier
  HINSTANCE hInstance,  // handle to application instance
  LPVOID lpParam        // pointer to window-creation data
);
 
HWINSTA CreateWindowStation(
  LPTSTR lpwinsta,        // name of the new window station
  DWORD dwReserved,       // reserved; must be NULL
  DWORD dwDesiredAccess,  // specifies access of returned handle
  LPSECURITY_ATTRIBUTES lpsa  // specifies security attributes of 
                              // the window station
);
 
BOOL DdeAbandonTransaction(
  DWORD idInst,         // instance identifier
  HCONV hConv,          // handle to conversation
  DWORD idTransaction   // transaction identifier
);
 
LPBYTE DdeAccessData(
  HDDEDATA hData,  // handle to DDE object
  LPDWORD pcbDataSize 
                   // pointer to variable that receives data length
);
 
HDDEDATA DdeAddData(
  HDDEDATA hData,  // handle to DDE data object
  LPBYTE pSrc,     // pointer to source buffer
  DWORD cb,        // length of data
  DWORD cbOff      // offset within DDE data object
);
 
HDDEDATA CALLBACK DdeCallback(
  UINT uType,     // transaction type
  UINT uFmt,      // clipboard data format
  HCONV hconv,    // handle to the conversation
  HSZ hsz1,       // handle to a string
  HSZ hsz2,       // handle to a string
  HDDEDATA hdata, // handle to a global memory object
  DWORD dwData1,  // transaction-specific data
  DWORD dwData2   // transaction-specific data
);
 
HDDEDATA DdeClientTransaction(
  LPBYTE pData,       // pointer to data to pass to server
  DWORD cbData,       // length of data
  HCONV hConv,        // handle to conversation
  HSZ hszItem,        // handle to item name string
  UINT wFmt,          // clipboard data format
  UINT wType,         // transaction type
  DWORD dwTimeout,    // time-out duration
  LPDWORD pdwResult   // pointer to transaction result
);
 
int DdeCmpStringHandles(
  HSZ hsz1,  // handle to first string
  HSZ hsz2   // handle to second string
);
 
HCONV DdeConnect(
  DWORD idInst,      // instance identifier
  HSZ hszService,    // handle to service name string
  HSZ hszTopic,      // handle to topic name string
  PCONVCONTEXT pCC   // pointer to structure with context data
);
 
HCONVLIST DdeConnectList(
  DWORD idInst,         // instance identifier
  HSZ hszService,       // handle to service name string
  HSZ hszTopic,         // handle to topic name string
  HCONVLIST hConvList,  // handle to conversation list
  PCONVCONTEXT pCC      // pointer to structure with context data
);
 
HDDEDATA DdeCreateDataHandle(
  DWORD idInst, // instance identifier
  LPBYTE pSrc,  // pointer to source buffer
  DWORD cb,     // length of DDE object
  DWORD cbOff,  // offset from beginning of source buffer
  HSZ hszItem,  // handle to item name string
  UINT wFmt,    // clipboard data format
  UINT afCmd    // creation flags
);
 
HSZ DdeCreateStringHandle(
  DWORD idInst,  // instance identifier
  LPTSTR psz,    // pointer to null-terminated string
  int iCodePage  // code page identifier
);
 
BOOL DdeDisconnect(
  HCONV hConv   // handle to conversation
);
 
BOOL DdeDisconnectList(
  HCONVLIST hConvList   // handle to conversation list
);
 
BOOL DdeEnableCallback(
  DWORD idInst, // instance identifier
  HCONV hConv,  // handle to conversation
  UINT wCmd     // enable or disable function code
);
 
BOOL DdeFreeDataHandle(
  HDDEDATA hData   // handle to DDE object
);
 
BOOL DdeFreeStringHandle(
  DWORD idInst,  // instance identifier
  HSZ hsz        // handle to string
);
 
DWORD DdeGetData(
  HDDEDATA hData,  // handle to DDE  object
  LPBYTE pDst,     // pointer to destination buffer
  DWORD cbMax,     // amount of data to copy
  DWORD cbOff      // offset to beginning of data
);
 
UINT DdeGetLastError(
  DWORD idInst   // instance identifier
);
 
BOOL DdeImpersonateClient(
  HCONV hConv   // handle to DDE conversation
);
 
UINT DdeInitialize(
  LPDWORD pidInst,          // pointer to instance identifier
  PFNCALLBACK pfnCallback,  // pointer to callback function
  DWORD afCmd,              // set of command and filter flags
  DWORD ulRes               // reserved
);
 
BOOL DdeKeepStringHandle(
  DWORD idInst,  // instance identifier
  HSZ hsz        // handle to string
);
 
HDDEDATA DdeNameService(
  DWORD idInst,  // instance identifier
  HSZ hsz1,      // handle to service name string
  HSZ hsz2,      // reserved
  UINT afCmd     // service name flags
);
 
BOOL DdePostAdvise(
  DWORD idInst, // instance identifier
  HSZ hszTopic, // handle to topic name string
  HSZ hszItem   // handle to item name string
);
 
UINT DdeQueryConvInfo(
  HCONV hConv,          // handle to conversation
  DWORD idTransaction,  // transaction identifier
  PCONVINFO pConvInfo   // pointer to structure with conversation 
                        // data
);
 
HCONV DdeQueryNextServer(
  HCONVLIST hConvList,  // handle to conversation list
  HCONV hConvPrev       // previous conversation handle
);
 
DWORD DdeQueryString(
  DWORD idInst,  // instance identifier
  HSZ hsz,       // handle to string
  LPTSTR psz,    // pointer to destination buffer
  DWORD cchMax,  // length of buffer
  int iCodePage  // code page identifier
);
 
HCONV DdeReconnect(
  HCONV hConv   // handle to conversation to reestablish
);
 
BOOL DdeSetQualityOfService(
  HWND hwndClient,  // handle to DDE client window that will start 
                    // DDE conversations
  CONST SECURITY_QUALITY_OF_SERVICE *pqosNew,
                    // desired quality of service
  PSECURITY_QUALITY_OF_SERVICE pqosPrev 
                    // prior quality of service
);
 
BOOL DdeSetUserHandle(
  HCONV hConv,  // handle to conversation
  DWORD id,     // transaction identifier
  DWORD hUser   // handle to application-defined value
);
 
BOOL DdeUnaccessData(
  HDDEDATA hData   // handle to DDE object
);
 
BOOL DdeUninitialize(
  DWORD idInst   // instance identifier
);
 
BOOL DebugActiveProcess(
  DWORD dwProcessId   // process to be debugged
);
 
VOID DebugBreak(VOID);
 
LRESULT CALLBACK DebugProc(
  int nCode,      // hook code
  WPARAM wParam,  // type of hook about to be called
  LPARAM lParam   // address of structure with debugging information
);
 
BOOL DecryptFile(
  LPCTSTR lpFileName, 
  DWORD dwReserved 
);
 
LRESULT DefDlgProc(
  HWND hDlg,      // handle to dialog box
  UINT Msg,       // message
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
HDWP DeferWindowPos(
  HDWP hWinPosInfo,      // handle to internal structure
  HWND hWnd,             // handle to window to position
  HWND hWndInsertAfter,  // placement-order handle
  int x,                 // horizontal position
  int y,                 // vertical position
  int cx,                // width
  int cy,                // height
  UINT uFlags            // window-positioning flags
);
 
LRESULT DefFrameProc(
  HWND hWnd,           // handle to MDI frame window
  HWND hWndMDIClient,  // handle to MDI client window
  UINT uMsg,           // message
  WPARAM wParam,       // first message parameter
  LPARAM lParam        // second message parameter
);
 
BOOL DefineDosDevice(
  DWORD dwFlags,        // controllable aspect flag
  LPCTSTR lpDeviceName, // pointer to an MS-DOS device name string
  LPCTSTR lpTargetPath  // pointer to an MS-DOS or Windows NT path string
);
 
LRESULT DefMDIChildProc(
  HWND hWnd,      // handle to MDI child window
  UINT uMsg,      // message
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
LRESULT DefWindowProc(
  HWND hWnd,      // handle to window
  UINT Msg,       // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
BOOL DeleteAce(
  PACL pAcl,         // pointer to access-control list
  DWORD dwAceIndex   // index of ACE position in ACL
);
 
ATOM DeleteAtom(
  ATOM nAtom   // atom to delete
);
 
BOOL WINAPI DeleteColorSpace(
  HCOLORSPACE hColorSpace
);
 
BOOL WINAPI DeleteColorTransform(
  HTRANSFORM hColorTransform  
);
 
VOID DeleteCriticalSection(
  LPCRITICAL_SECTION lpCriticalSection   // pointer to critical 
                                         // section object
);
 
BOOL DeleteDC(
  HDC hdc   // handle to device context
);
 
BOOL DeleteEnhMetaFile(
  HENHMETAFILE hemf   // handle to an enhanced metafile
);
 
VOID DeleteFiber(
  LPVOID lpFiber   // pointer to the fiber to delete
);
 
BOOL DeleteFile(
  LPCTSTR lpFileName   // pointer to name of file to delete
);
 
BOOL DeleteForm(
  HANDLE hPrinter,  // handle to printer object
  LPTSTR pFormName  // pointer to form name
);
 
BOOL DeleteMenu(
  HMENU hMenu,     // handle to menu
  UINT uPosition,  // menu item identifier or position
  UINT uFlags      // menu item flag
);
 
BOOL DeleteMetaFile(
  HMETAFILE hmf   // handle to Windows-format metafile
);
 
BOOL DeleteMonitor(
  LPTSTR pName,         // pointer to server name
  LPTSTR pEnvironment,  // pointer to environment string
  LPTSTR pMonitorName   // pointer to monitor name
);
 
BOOL DeleteObject(
  HGDIOBJ hObject   // handle to graphic object
);
 
BOOL DeletePort(
  LPTSTR pName,      // pointer to server name
  HWND hWnd,         // handle to window that displays dialog box
  LPTSTR pPortName   // pointer to port name
);
 
BOOL DeletePrinter(
  HANDLE hPrinter   // handle to printer object
);
 
BOOL DeletePrinterConnection(
  LPTSTR pName   // pointer to printer name
);
 
DWORD DeletePrinterData(
  HANDLE hPrinter,  // handle to printer of interest
  LPTSTR pValueName
                    // pointer to null-terminated value name string
);
 
DWORD DeletePrinterDataEx(
  HANDLE hPrinter,       // handle to printer object
  LPCTSTR pKeyName,      // name of the registry key
  LPCTSTR pValueName     // name of the value
);
 
BOOL DeletePrinterDriver(
  LPTSTR pName,        // pointer to server name
  LPTSTR pEnvironment, // pointer to environment
  LPTSTR pDriverName   // pointer to driver name
);
 
BOOL DeletePrinterDriverEx(
  LPTSTR pName,         // pointer to server name
  LPTSTR pEnvironment,  // pointer to environment
  LPTSTR pDriverName,   // pointer to driver name
  DWORD dwDeleteFlag,   // options for deleting files and versions
  DWORD dwVersionFlag   // version number to delete
);
 
DWORD DeletePrinterKey(
  HANDLE hPrinter,       // handle to printer object
  LPCTSTR pKeyName       // name of the registry key to delete
);
 
BOOL DeletePrintProcessor(
  LPTSTR pName,                // pointer to server name
  LPTSTR pEnvironment,         // pointer to environment string
  LPTSTR pPrintProcessorName   // pointer to processor name
);
 
BOOL DeletePrintProvidor(
  LPTSTR pName,               // reserved, must be NULL
  LPTSTR pEnvironment,        // pointer to environment string
  LPTSTR pPrintProvidorName   // pointer to provider name
);
 
BOOL DeleteService(
  SC_HANDLE hService   // handle to service
);
 
BOOL DeregisterEventSource(
  HANDLE hEventLog   // handle to event log
);
 
BOOL DestroyAcceleratorTable(
  HACCEL hAccel   // handle to accelerator table
);
 
BOOL DestroyCaret(VOID);
 
BOOL DestroyCursor(
  HCURSOR hCursor   // handle to cursor to destroy
);
 
BOOL DestroyIcon(
  HICON hIcon   // handle to icon to destroy
);
 
BOOL DestroyMenu(
  HMENU hMenu  // handle to menu to destroy
);
 
BOOL DestroyPrivateObjectSecurity(
  PSECURITY_DESCRIPTOR *ObjectDescriptor   // address of pointer to 
                                           // SECURITY_DESCRIPTOR
);
 
BOOL DestroyWindow(
  HWND hWnd   // handle to window to destroy
);
 
DWORD DeviceCapabilities(
  LPCTSTR pDevice,    // pointer to a printer-name string
  LPCTSTR pPort,      // pointer to a port-name string
  WORD fwCapability,  // device capability to query
  LPTSTR pOutput,     // pointer to the output
  CONST DEVMODE *pDevMode 
                      // pointer to structure with device data
);
 
BOOL DeviceIoControl(
  HANDLE hDevice,              // handle to device of interest
  DWORD dwIoControlCode,       // control code of operation to perform
  LPVOID lpInBuffer,           // pointer to buffer to supply input data
  DWORD nInBufferSize,         // size, in bytes, of input buffer
  LPVOID lpOutBuffer,          // pointer to buffer to receive output data
  DWORD nOutBufferSize,        // size, in bytes, of output buffer
  LPDWORD lpBytesReturned,     // pointer to variable to receive byte count
  LPOVERLAPPED lpOverlapped    // pointer to structure for asynchronous operation
);
 
int DialogBox(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpTemplate,   // identifies dialog box template
  HWND hWndParent,      // handle to owner window
  DLGPROC lpDialogFunc  // pointer to dialog box procedure
);
 
int DialogBoxIndirect(
  HINSTANCE hInstance,   // handle to application instance
  LPDLGTEMPLATE lpTemplate,  // identifies dialog box template
  HWND hWndParent,       // handle to owner window
  DLGPROC lpDialogFunc   // pointer to dialog box procedure
);
 
int DialogBoxIndirectParam(
  HINSTANCE hInstance,  // handle to application instance
  LPCDLGTEMPLATE hDialogTemplate,
                        // identifies dialog box template
  HWND hWndParent,      // handle to owner window
  DLGPROC lpDialogFunc, // pointer to dialog box procedure
  LPARAM dwInitParam    // initialization value
);
 
int DialogBoxParam(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpTemplateName,  // identifies dialog box template
  HWND hWndParent,      // handle to owner window
  DLGPROC lpDialogFunc, // pointer to dialog box procedure
  LPARAM dwInitParam    // initialization value
);
 
BOOL CALLBACK DialogProc(
  HWND hwndDlg,  // handle to dialog box
  UINT uMsg,     // message
  WPARAM wParam, // first message parameter
  LPARAM lParam  // second message parameter
);
 
BOOL DisableThreadLibraryCalls(
  HMODULE hLibModule  // dynamic-link library for which calls are to be disabled
);
 
BOOL WINAPI DisassociateColorProfileFromDevice(
  PCTSTR pMachineName,
  PCTSTR pProfileName,
  PCTSTR pDeviceName
);
 
BOOL DisconnectNamedPipe(
  HANDLE hNamedPipe   // handle to named pipe
);
 
LONG DispatchMessage(
  CONST MSG *lpmsg   // pointer to structure with message
);
 
int DlgDirList(
  HWND hDlg,          // handle to dialog box with list box
  LPTSTR lpPathSpec,  // pointer to path or filename string
  int nIDListBox,     // identifier of list box
  int nIDStaticPath,  // identifier of static control
  UINT uFileType      // file attributes to display
);
 
int DlgDirListComboBox(
  HWND hDlg,          // handle to dialog box with combo box
  LPTSTR lpPathSpec,  // pointer to path or filename string
  int nIDComboBox,    // identifier of combo box
  int nIDStaticPath,  // identifier of static control
  UINT uFiletype      // file attributes to display
);
 
BOOL DlgDirSelectComboBoxEx(
  HWND hDlg,        // handle to dialog box with list box
  LPTSTR lpString,  // pointer to buffer for path string
  int nCount,       // number of characters in path string
  int nIDComboBox   // identifier of combo box
);
 
BOOL DlgDirSelectEx(
  HWND hDlg,       // handle to dialog box with list box
  LPTSTR lpString, // pointer to buffer for path string
  int nCount,      // number of characters in path string
  int nIDListBox   // identifier of list box
);
 
BOOL WINAPI DllMain(
  HINSTANCE hinstDLL,  // handle to DLL module
  DWORD fdwReason,     // reason for calling function
  LPVOID lpvReserved   // reserved
);
 
LONG DocumentProperties(
  HWND hWnd,           // handle to window that displays dialog box
  HANDLE hPrinter,         // handle to printer object
  LPTSTR pDeviceName,      // pointer to device name
  PDEVMODE pDevModeOutput,
                       // pointer to modified device mode structure
  PDEVMODE pDevModeInput,  // pointer to original device mode 
                           // structure
  DWORD fMode              // mode flag
);
 
BOOL DosDateTimeToFileTime(
  WORD wFatDate,          // 16-bit MS-DOS date
  WORD wFatTime,          // 16-bit MS-DOS time
  LPFILETIME lpFileTime   // pointer to buffer for 64-bit file time
);
 
BOOL DPtoLP(
  HDC hdc,           // handle to device context
  LPPOINT lpPoints,  // pointer to array of points
  int nCount         // count of points
);
 
BOOL DragDetect(
  HWND hwnd,   
  POINT pt     
);
 
BOOL WINAPI DrawAnimatedRects(
  HWND hwnd,  // handle to clipping window
  int idAni,  // type of animation
  CONST RECT *lprcFrom,
              // pointer to rectangle coordinates (minimized)
  CONST RECT *lprcTo
              // pointer to rectangle coordinates (restored)
);
 
BOOL WINAPI DrawCaption(
  HWND hwnd,    // handle to window to get text and icon from
  HDC hdc,      // handle to device context to draw into
  LPCRECT lprc, // pointer to rectangle to draw into
  UINT uFlags,  // set of drawing option flags
);
 
BOOL DrawEdge(
  HDC hdc,       // handle to device context
  LPRECT qrc,    // pointer to rectangle coordinates
  UINT edge,     // type of inner and outer edge to draw
  UINT grfFlags  // type of border
);
 
int DrawEscape(
  HDC hdc,            // handle to device context
  int nEscape,        // specifies escape function
  int cbInput,        // size of structure for input
  LPCSTR lpszInData   // pointer to structure for input
);
 
BOOL DrawFocusRect(
  HDC hDC,          // handle to device context
  CONST RECT *lprc  // pointer to structure for rectangle
);
 
BOOL DrawFrameControl(
  HDC hdc,     // handle to device context
  LPRECT lprc, // pointer to bounding rectangle
  UINT uType,  // frame-control type
  UINT uState  // frame-control state
);
 
BOOL DrawIcon(
  HDC hDC,      // handle to device context
  int X,        // x-coordinate of upper-left corner
  int Y,        // y-coordinate of upper-left corner
  HICON hIcon   // handle to icon to draw
);
 
BOOL DrawIconEx(
  HDC hdc,                    // handle to device context
  int xLeft,                  // x-coordinate of upper left corner
  int yTop,                   // y-coordinate of upper left corner
  HICON hIcon,                // handle to icon to draw
  int cxWidth,                // width of the icon
  int cyWidth,                // height of the icon
  UINT istepIfAniCur,         // index of frame in animated cursor
  HBRUSH hbrFlickerFreeDraw,  // handle to background brush
  UINT diFlags                // icon-drawing flags
);
 
BOOL DrawMenuBar(
  HWND hWnd  // handle to window with menu bar to redraw
);
 
BOOL WINAPI DrawState(
  HDC hdc,                     // handle to device context
  HBRUSH hbr,                  // handle to brush
  DRAWSTATEPROC lpOutputFunc,  // pointer to callback function
  LPARAM lData,                // image information
  WPARAM wData,                // more image information
  int x,                       // horizontal location of image
  int y,                       // vertical location of image
  int cx,                      // width of image
  int cy,                      // height of image
  UINT fuFlags                 // image type and state
);
 
BOOL CALLBACK DrawStateProc(
  HDC hdc,       // handle to device context
  LPARAM lData,  // image information
  WPARAM wData,  // more image information
  int cx,        // width of image
  int cy         // height of image
);
 
int DrawText(
  HDC hDC,          // handle to device context
  LPCTSTR lpString, // pointer to string to draw
  int nCount,       // string length, in characters
  LPRECT lpRect,    // pointer to struct with formatting dimensions
  UINT uFormat      // text-drawing flags
);
 
int DrawTextEx(
  HDC hdc,                     // handle to device context
  LPTSTR lpchText,             // pointer to string to draw
  int cchText,                 // length of string to draw
  LPRECT lprc,                 // pointer to rectangle coordinates
  UINT dwDTFormat,             // formatting options
  LPDRAWTEXTPARAMS lpDTParams  // pointer to struct with options
);
 
DWORD DsGetDcName(
  LPCTSTR ComputerName,
  LPCTSTR DomainName,
  GUID *DomainGuid,
  LPCTSTR SiteName,
  ULONG Flags,
  PDOMAIN_CONTROLLER_INFO *DomainControllerInfo
);
 
DWORD DsGetSiteName(
  LPCTSTR ComputerName,
  LPTSTR *SiteName
);
 
DWORD DsValidateSubnetName(
  LPCTSTR SubnetName
);
 
BOOL DuplicateHandle(
  HANDLE hSourceProcessHandle,  // handle to the source process
  HANDLE hSourceHandle,         // handle to duplicate
  HANDLE hTargetProcessHandle,  // handle to process to duplicate to
  LPHANDLE lpTargetHandle,  // pointer to duplicate handle
  DWORD dwDesiredAccess,    // access for duplicate handle
  BOOL bInheritHandle,      // handle inheritance flag
  DWORD dwOptions           // optional actions
);
 
BOOL DuplicateToken(
  HANDLE ExistingTokenHandle,    // handle to token to duplicate
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
                                 // impersonation level
  PHANDLE DuplicateTokenHandle   // handle to duplicated token
);
 
BOOL DuplicateTokenEx(
  HANDLE hExistingToken, // handle to token to duplicate
  DWORD dwDesiredAccess, // access rights of new token
  LPSECURITY_ATTRIBUTES lpTokenAttributes,
                         // security attributes of the new token
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
                         // impersonation level of new token
  TOKEN_TYPE TokenType,  // primary or impersonation token
  PHANDLE phNewToken     // handle to duplicated token
);
 
DWORD CALLBACK EditStreamCallback(
  DWORD dwCookie, // application-defined value
  LPBYTE pbBuff,  // pointer to a buffer
  LONG cb,        // number of bytes to read or write
  LONG *pcb       // pointer to number of bytes transferred
);
 
int CALLBACK EditWordBreakProc(
  LPTSTR lpch,     // pointer to edit text
  int ichCurrent,  // index of starting point
  int cch,         // length in characters of edit text
  int code         // action to take
);
 
LONG EditWordBreakProcEx(
  char *pchText,  
  LONG cchText,   
  BYTE bCharSet,  
  INT code        
);
 
BOOL Ellipse(
  HDC hdc,        // handle to device context
  int nLeftRect,  // x-coord of bounding rectangle's upper-left corner
  int nTopRect,   // y-coord of bounding rectangle's upper-left corner
  int nRightRect, // x-coord of bounding rectangle's lower-right corner
  int nBottomRect // y-coord of bounding rectangle's lower-right corner
);
 
BOOL EmptyClipboard(VOID);
 
BOOL EnableMenuItem(
  HMENU hMenu,         // handle to menu
  UINT uIDEnableItem,  // menu item to enable, disable, or gray
  UINT uEnable         // menu item flags
);
 
BOOL EnableScrollBar(
  HWND hWnd,     // handle to window or scroll bar
  UINT wSBflags, // scroll bar type flag
  UINT wArrows   // scroll bar arrow flag
);
 
BOOL EnableWindow(
  HWND hWnd,     // handle to window
  BOOL bEnable   // flag for enabling or disabling input
);
 
BOOL EncryptFile(
  LPCTSTR lpFileName
);
 
BOOL EndDeferWindowPos(
  HDWP hWinPosInfo   // handle to internal structure
);
 
BOOL EndDialog(
  HWND hDlg,    // handle to dialog box
  int nResult   // value to return
);
 
int EndDoc(
  HDC hdc   // handle to device context
);
 
BOOL EndDocPrinter(
  HANDLE hPrinter   // handle to printer object
);
 int EndPage(
  HDC hdc   // handle to device context
);
 
BOOL EndPagePrinter(
  HANDLE hPrinter   // handle to printer object
);
 
BOOL EndPaint(
  HWND hWnd,  // handle to window
  CONST PAINTSTRUCT *lpPaint 
              // pointer to structure for paint data
);
 
BOOL EndPath(
  HDC hdc   // handle to device context
);
 
BOOL EndUpdateResource(
  HANDLE hUpdate, // update-file handle
  BOOL fDiscard   // write flag
);
 
int CALLBACK EnhMetaFileProc(
  HDC hDC,                    // handle to device context
  HANDLETABLE FAR *lpHTable,  // pointer to metafile handle table
  ENHMETARECORD FAR *lpEMFR,  // pointer to metafile record
  int nObj,                   // count of objects
  LPARAM lpData               // pointer to optional data
);
 
VOID EnterCriticalSection(
  LPCRITICAL_SECTION lpCriticalSection   // pointer to critical 
                                         // section object
);
 
BOOL EnumCalendarInfo(
  CALINFO_ENUMPROC lpCalInfoEnumProc, // pointer to enumeration callback function
  LCID Locale,                        // locale of interest
  CALID Calendar,                     // calendar whose information is of interest
  CALTYPE CalType                     // type of calendar information of interest
);
 
BOOL CALLBACK EnumCalendarInfoProc(
  LPTSTR lpCalendarInfoString   // pointer to calendar information string
);
 
BOOL CALLBACK EnumChildProc(
  HWND hwnd,      // handle to child window
  LPARAM lParam   // application-defined value
);
 
BOOL EnumChildWindows(
  HWND hWndParent,         // handle to parent window
  WNDENUMPROC lpEnumFunc,  // pointer to callback function
  LPARAM lParam            // application-defined value
);
 
UINT EnumClipboardFormats(
  UINT format   // specifies a known available clipboard format
);
 
BOOL CALLBACK EnumCodePagesProc(
  LPTSTR lpCodePageString   // pointer to code page identifier string
);
 
BOOL WINAPI EnumColorProfiles(
  PCTSTR pMachineName,
  PENUMTYPE pEnumRecord,
  PBYTE pBuffer,
  PDWORD pdwSize,
  PDWORD pnProfiles
);
 
BOOL EnumDateFormats(
  DATEFMT_ENUMPROC lpDateFmtEnumProc, // pointer to enumeration callback function
  LCID Locale,                        // locale whose date formats are of interest
  DWORD dwFlags                       // date formats to enumerate
);
 
BOOL CALLBACK EnumDateFormatsProc(
  LPTSTR lpDateFormatString   // pointer to date format string
);
 
BOOL EnumDependentServices(
  SC_HANDLE hService,      // handle to service
  DWORD dwServiceState,    // state of services to enumerate
  LPENUM_SERVICE_STATUS lpServices,
                           // pointer to service status buffer
  DWORD cbBufSize,         // size of service status buffer
  LPDWORD pcbBytesNeeded,  // pointer to variable for bytes needed
  LPDWORD lpServicesReturned 
                           // pointer to variable for number returned
);
 
BOOL CALLBACK EnumDesktopProc(
  LPTSTR lpszDesktop,  // name of a desktop
  LPARAM lParam        // value specified in EnumDesktops call
);
 
BOOL EnumDesktops(
  HWINSTA hwinsta,            // handle to window station to enumerate
  DESKTOPENUMPROC lpEnumFunc, // points to application's callback function
  LPARAM lParam               // value to pass to the callback function
);
 
BOOL EnumDesktopWindows(
  HDESK hDesktop,   // handle to desktop to enumerate
  WNDENUMPROC lpfn, // points to application's callback function
  LPARAM lParam     // 32-bit value to pass to the callback function
);
 
BOOL EnumDisplayDevices(
  PVOID Unused,       // not used; must be NULL
  DWORD iDevNum,      // specifies display device
  PDISPLAY_DEVICE lpDisplayDevice,  // pointer to structure to
                      // receive display device information
  DWORD dwFlags       // flags to condition function behavior
);
 
BOOL EnumDisplayMonitors (
  HDC hdc,                   // handle to a display device context 
  LPCRECT lprcClip,          // specifies a clipping rectangle 
  MONITORENUMPROC lpfnEnum,  // pointer to a callback function
  LPARAM dwData              // data passed to the callback function 
);
 
BOOL EnumDisplaySettings(
  LPCTSTR lpszDeviceName,  // specifies the display device
  DWORD iModeNum,          // specifies the graphics mode
  LPDEVMODE lpDevMode      // points to structure to receive settings
);
 
BOOL EnumEnhMetaFile(
  HDC hdc,                     // handle to device context
  HENHMETAFILE hemf,           // handle to enhanced metafile
  ENHMFENUMPROC lpEnhMetaFunc, // pointer to callback function
  LPVOID lpData,               // pointer to callback-function data
  CONST RECT *lpRect           // pointer to bounding rectangle
);
 
int CALLBACK EnumFontFamExProc(
  ENUMLOGFONTEX *lpelfe,    // pointer to logical-font data
  NEWTEXTMETRICEX *lpntme,  // pointer to physical-font data
  int FontType,             // type of font
  LPARAM lParam             // application-defined data
);
 
int EnumFontFamilies(
  HDC hdc,             // handle to device control
  LPCTSTR lpszFamily,  // pointer to family-name string
  FONTENUMPROC lpEnumFontFamProc,
                       // pointer to callback function
  LPARAM lParam        // pointer to application-supplied data
);
 
int EnumFontFamiliesEx(
  HDC hdc,              // handle to device context
  LPLOGFONT lpLogfont,  // pointer to logical font information
  FONTENUMPROC lpEnumFontFamExProc,
                        // pointer to callback function
  LPARAM lParam,        // application-supplied data
  DWORD dwFlags         // reserved; must be zero
);
 
int CALLBACK EnumFontFamProc(
  ENUMLOGFONT FAR *lpelf,  // pointer to logical-font data
  NEWTEXTMETRIC FAR *lpntm,  // pointer to physical-font data
  int FontType,            // type of font
  LPARAM lParam            // pointer to application-defined data
);
 
int EnumFonts(
  HDC hdc,                  // handle to device context
  LPCTSTR lpFaceName,       // pointer to font typeface name string
  FONTENUMPROC lpFontFunc,  // pointer to callback function
  LPARAM lParam             // pointer to application-supplied data
);
 
int CALLBACK EnumFontsProc(
  lplf lplf,     // pointer to logical-font data
  lptm lptm,     // pointer to physical-font data
  DWORD dwType,  // font type
  LPARAM lpData  // pointer to application-defined data
);
 
BOOL EnumForms(
  HANDLE hPrinter,    // handle to printer object
  DWORD Level,        // data-structure level
  LPBYTE pForm,       // points to buffer that receives form info. 
                      // structure array
  DWORD cbBuf,        // count of bytes in buffer
  LPDWORD pcbNeeded,  // points to variable to receive count of 
                      // bytes copied or required
  LPDWORD pcReturned  // points to variable to receive count of 
                      // structures copied
);
 
int WINAPI EnumICMProfiles(
  HDC hDC,
  ICMENUMPROC lpEnumICMProfilesFunc,
  LPARAM lParam 
);
 
int CALLBACK EnumICMProfilesProcCallback(
  LPTSTR lpszFilename,
  LPARAM lParam
);
 
BOOL EnumJobs(
  HANDLE hPrinter,    // handle to printer object
  DWORD FirstJob,     // location of first job in print queue to 
                      // enumerate
  DWORD NoJobs,       // number of jobs to enumerate
  DWORD Level,        // structure level
  LPBYTE pJob,        // pointer to structure array
  DWORD cbBuf,        // size of array, in bytes
  LPDWORD pcbNeeded,  // addr. of variable with no. of bytes copied 
                      // (or required)
  LPDWORD pcReturned  // addr. of variable with no. of job info. 
                      // structures copied
);
 
BOOL CALLBACK EnumLocalesProc(
  LPTSTR lpLocaleString   // pointer to locale identifier string
);
 
BOOL EnumMetaFile(
  HDC hdc,                // handle to device context
  HMETAFILE hmf,          // handle to Windows-format metafile
  MFENUMPROC lpMetaFunc,  // pointer to callback function
  LPARAM lParam           // address of callback function data
);
 
int CALLBACK EnumMetaFileProc(
  HDC hDC,                    // handle to device context
  HANDLETABLE FAR *lpHTable,  // pointer to metafile handle table
  METARECORD FAR *lpMFR,      // pointer to metafile record
  int nObj,                   // count of objects
  LPARAM lpClientData         // pointer to optional data
);
 
BOOL EnumMonitors(
  LPTSTR pName,       // pointer to server name
  DWORD Level,        // structure level
  LPBYTE pMonitors,   // pointer to structure array
  DWORD cbBuf,        // size, in bytes, of buffer
  LPDWORD pcbNeeded,  // addr. of variable with no. of bytes copied 
                      // (or required)
  LPDWORD pcReturned  // addr. of variable with no. of job info. 
                      // structures copied
);
 
int EnumObjects(
  HDC hdc,                    // handle to device context
  int nObjectType,            // object-type identifier
  GOBJENUMPROC lpObjectFunc,  // pointer to callback function
  LPARAM lParam               // pointer to application-supplied data
);
 
VOID CALLBACK EnumObjectsProc(
  LPVOID lpLogObject,  // pointer to graphic-object structure
  LPARAM lpData        // pointer to application-defined data
);
 
BOOL EnumPorts(
  LPTSTR pName,       // pointer to server name
  DWORD Level,        // specifies type of port info structure
  LPBYTE pPorts,      // pointer to buffer to receive array of port 
                      // info. structures
  DWORD cbBuf,        // specifies size, in bytes, of buffer
  LPDWORD pcbNeeded,  // pointer to number of bytes stored into 
                      // buffer (or required buffer size)
  LPDWORD pcReturned  // pointer to number of PORT_INFO_*. 
                      // structures stored into buffer
);
 
DWORD EnumPrinterData(
  HANDLE hPrinter,       // handle to printer of interest
  DWORD dwIndex,         // index of value to retrieve
  LPTSTR pValueName,     // pointer to buffer to receive value name
  DWORD cbValueName,     // size in bytes of value name buffer
  LPDWORD pcbValueName,  // pointer to variable to receive number of 
                         // bytes stored into value name buffer
  LPDWORD pType,         // pointer to variable to receive value 
                         // type code
  LPBYTE pData,          // pointer to buffer to receive value data
  DWORD cbData,          // size in bytes of value data buffer
  LPDWORD pcbData        // pointer to variable to receive number of 
                         // bytes stored into value data buffer
);
 
DWORD EnumPrinterDataEx(
  HANDLE hPrinter,       // handle to printer object
  LPCTSTR pKeyName,      // name of registry key
  LPBYTE pEnumValues,    // receives array of PRINTER_ENUM_VALUES 
  DWORD cbEnumValues,    // size, in bytes, of the pEnumValues buffer
  LPDWORD pcbEnumValues, // receives number of bytes of data
                         // retrieved in the pEnumValues buffer
  LPDWORD pnEnumValues   // receives number of enumerated values
);
 
BOOL EnumPrinterDrivers(
  LPTSTR pName,        // pointer to server name
  LPTSTR pEnvironment, // pointer to environment name
  DWORD Level,         // structure level
  LPBYTE pDriverInfo,  // pointer to an array of structures
  DWORD cbBuf,         // size, in bytes, of array
  LPDWORD pcbNeeded,   // pointer to number of bytes copied (or 
                       // required)
  LPDWORD pcReturned   // pointer to number of DRIVER_INFO. 
                       // structures
);
 
DWORD EnumPrinterKey(
  HANDLE hPrinter,       // handle to printer object
  LPCTSTR pKeyName,      // name of registry key
  LPTSTR pSubkey,        // receives array of subkey names
  DWORD cbSubkey,        // size, in bytes, of the pSubkey buffer
  LPDWORD pcbSubkey      // receives number of bytes of data
                         // retrieved in the pSubkey buffer
);
 
BOOL EnumPrinters(
  DWORD Flags,         // types of printer objects to enumerate
  LPTSTR Name,         // name of printer object
  DWORD Level,         // specifies type of printer info structure
  LPBYTE pPrinterEnum, // pointer to buffer to receive printer info 
                       // structures
  DWORD cbBuf,         // size, in bytes, of the buffer
  LPDWORD pcbNeeded,   // pointer to variable with no. of bytes 
                       // copied (or required)
  LPDWORD pcReturned   // pointer to variable with no. of printer 
                       // info. structures copied
);
 
BOOL EnumPrintProcessorDatatypes(
  LPTSTR pName,       // points to server name string
  LPTSTR pPrintProcessorName,
                      // points to print processor name string
  DWORD Level,        // specifies version of print processor data 
                      // type structures
  LPBYTE pDatatypes,  // points to buffer to receive print processor 
                      // data type structures
  DWORD cbBuf,        // specifies size, in bytes, of buffer
  LPDWORD pcbNeeded,  // points to number of bytes copied (or 
                      // required)
  LPDWORD pcReturned  // points to number of data structures obtained
);
 
BOOL EnumPrintProcessors(
  LPTSTR pName,                // points to server name
  LPTSTR pEnvironment,         // points to environment name
  DWORD Level,                 // structure level
  LPBYTE pPrintProcessorInfo,  // points to structure array
  DWORD cbBuf,                 // array length in bytes
  LPDWORD pcbNeeded,           // points to number of bytes copied 
                               // (or required)
  LPDWORD pcReturned           // points to number of job info. 
                               // structures copied
);
 
int EnumProps(
  HWND hWnd,               // handle to window
  PROPENUMPROC lpEnumFunc  // pointer to callback function
);
 
int EnumPropsEx(
  HWND hWnd,                  // handle to window
  PROPENUMPROCEX lpEnumFunc,  // pointer to callback function
  LPARAM lParam               // application-defined data
);
 
UINT CALLBACK EnumRegisterWordProc(
  LPCTSTR lpReading,   
  DWORD dwStyle,       
  LPCTSTR lpszString,  
  LPVOID lpData        
);
 
BOOL CALLBACK EnumResLangProc(
  HANDLE hModule,    // module handle
  LPCTSTR lpszType,  // pointer to resource type
  LPCTSTR lpszName,  // pointer to resource name
  WORD wIDLanguage,  // resource language identifier
  LONG lParam        // application-defined parameter
);
 
BOOL CALLBACK EnumResNameProc(
  HANDLE hModule,   // module handle
  LPCTSTR lpszType, // pointer to resource type
  LPTSTR lpszName,  // pointer to resource name
  LONG lParam       // application-defined parameter
);
 
BOOL EnumResourceLanguages(
  HMODULE hModule,             // resource-module handle
  LPCTSTR lpType,              // pointer to resource type
  LPCTSTR lpName,              // pointer to resource name
  ENUMRESLANGPROC lpEnumFunc,  // pointer to callback function
  LONG lParam                  // application-defined parameter
);
 
BOOL EnumResourceNames(
  HINSTANCE hModule,           // resource-module handling
  LPCTSTR lpszType,            // pointer to resource type
  ENUMRESNAMEPROC lpEnumFunc,  // pointer to callback function
  LONG lParam                  // application-defined parameter
);
 
BOOL EnumResourceTypes(
  HMODULE hModule,             // resource-module handle
  ENUMRESTYPEPROC lpEnumFunc,  // pointer to callback function
  LONG lParam                  // application-defined parameter
);
 
BOOL CALLBACK EnumResTypeProc(
  HANDLE hModule,  // resource-module handle
  LPTSTR lpszType, // pointer to resource type
  LONG lParam      // application-defined parameter
);
 
BOOL EnumServicesStatus(
  SC_HANDLE hSCManager, // handle to service control manager database
  DWORD dwServiceType,     // type of services to enumerate
  DWORD dwServiceState,    // state of services to enumerate
  LPENUM_SERVICE_STATUS lpServices,
                           // pointer to service status buffer
  DWORD cbBufSize,         // size of service status buffer
  LPDWORD pcbBytesNeeded,  // pointer to variable for bytes needed
  LPDWORD lpServicesReturned,
                           // pointer to variable for number returned
  LPDWORD lpResumeHandle   // pointer to variable for next entry
);
 
BOOL EnumSystemCodePages(
  CODEPAGE_ENUMPROC lpCodePageEnumProc,  // pointer to callback function
  DWORD dwFlags                          // indicates the code pages to enumerate
);
 
BOOL EnumSystemLocales(
  LOCALE_ENUMPROC lpLocaleEnumProc,
                  // pointer to enumeration callback function
  DWORD dwFlags   // indicates which locales to enumerate
);
 
BOOL EnumThreadWindows(
  DWORD dwThreadId,  // thread identifier
  WNDENUMPROC lpfn,  // pointer to callback function
  LPARAM lParam      // application-defined value
);
 
BOOL CALLBACK EnumThreadWndProc(
  HWND hwnd,      // handle to window
  LPARAM lParam   // application-defined value
);
 
BOOL EnumTimeFormats(
  TIMEFMT_ENUMPROC lpTimeFmtEnumProc, // pointer to callback function
  LCID Locale,                        // locale whose time formats are of interest
  DWORD dwFlags                       // currently unused
);
 
BOOL CALLBACK EnumTimeFormatsProc(
  LPTSTR lpTimeFormatString   // pointer to time format string
);
 
BOOL EnumWindows(
  WNDENUMPROC lpEnumFunc,  // pointer to callback function
  LPARAM lParam            // application-defined value
);
 
BOOL CALLBACK EnumWindowsProc(
  HWND hwnd,      // handle to parent window
  LPARAM lParam   // application-defined value
);
 
BOOL CALLBACK EnumWindowStationProc(
  LPTSTR lpszWindowStation
                 // name of a window station
  LPARAM lParam  // value specified in EnumWindowStations call
);
 
BOOL EnumWindowStations(
  WINSTAENUMPROC lpEnumFunc, // pointer to the callback function
  LPARAM lParam              // value to pass to the callback function
);
 
BOOL EqualPrefixSid(
  PSID pSid1,  // pointer to first SID to compare
  PSID pSid2   // pointer to second SID to compare
);
 
BOOL EqualRect(
  CONST RECT *lprc1,  // pointer to structure with first rectangle
  CONST RECT *lprc2   // pointer to structure with second rectangle
);
 
BOOL EqualRgn(
  HRGN hSrcRgn1,  // handle to first region
  HRGN hSrcRgn2   // handle to second region
);
 
BOOL EqualSid(
  PSID pSid1,  // pointer to first SID to compare
  PSID pSid2   // pointer to second SID to compare
);
 
DWORD EraseTape(
  HANDLE hDevice,     // handle to open device
  DWORD dwEraseType,  // type of erasure to perform
  BOOL bImmediate     // return after erase operation begins
);
 
BOOL EscapeCommFunction(
  HANDLE hFile,  // handle to communications device
  DWORD dwFunc   // extended function to perform
);
 
int ExcludeClipRect(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coordinate of upper-left corner of rectangle
  int nTopRect,    // y-coordinate of upper-left corner of rectangle
  int nRightRect,
                   // x-coordinate of lower-right corner of rectangle
  int nBottomRect 
                   // y-coordinate of lower-right corner of rectangle
);
 
int ExcludeUpdateRgn(
  HDC hDC,    // handle to device context
  HWND hWnd   // handle to window
);
 
VOID ExitProcess(
  UINT uExitCode   // exit code for all threads
);
 
VOID ExitThread(
  DWORD dwExitCode   // exit code for this thread
);
 
BOOL ExitWindows(
  DWORD dwReserved,  // reserved
  UINT uReserved     // reserved
);
 
BOOL ExitWindowsEx(
  UINT uFlags,       // shutdown operation
  DWORD dwReserved   // reserved
);
 
DWORD ExpandEnvironmentStrings(
  LPCTSTR lpSrc, // pointer to string with environment variables
  LPTSTR lpDst,  // pointer to string with expanded environment 
                 // variables
  DWORD nSize    // maximum characters in expanded string
);
 
DWORD ExportCallback(
  PBYTE pbData,
  PVOID pvCallbackContext,
  PULONG ulLength
);
 
HPEN ExtCreatePen(
  DWORD dwPenStyle,      // pen style
  DWORD dwWidth,         // pen width
  CONST LOGBRUSH *lplb,  // pointer to structure for brush attributes
  DWORD dwStyleCount,    // length of array containing custom style bits
  CONST DWORD *lpStyle   // optional array of custom style bits
);
 
HRGN ExtCreateRegion(
  CONST XFORM *lpXform,     // pointer to transformation data
  DWORD nCount,             // size of structure containing region data
  CONST RGNDATA *lpRgnData  // pointer to region data
);
 
int ExtEscape(
  HDC hdc,            // handle to device context
  int nEscape,        // escape function
  int cbInput,        // number of bytes in input structure
  LPCSTR lpszInData,  // pointer to input structure
  int cbOutput,       // number of bytes in output structure
  LPSTR lpszOutData   // pointer to output structure
);
 
BOOL ExtFloodFill(
  HDC hdc,          // handle to device context
  int nXStart,      // x-coordinate where filling begins
  int nYStart,      // y-coordinate where filling begins
  COLORREF crColor, // fill color
  UINT fuFillType   // fill type
);
 
HICON ExtractAssociatedIcon(
  HINSTANCE hInst,    // application instance handle
  LPTSTR lpIconPath,  // path and filename of file for which icon is 
                      // wanted
  LPWORD lpiIcon      // pointer to icon index
);
 
HICON ExtractIcon(
  HINSTANCE hInst,          // instance handle
  LPCTSTR lpszExeFileName,  // filename of file with icon
  UINT nIconIndex           // index of icon to extract
);
 
UINT ExtractIconEx(
  LPCTSTR lpszFile,          
  int nIconIndex,           
  HICON FAR *phiconLarge,  
  HICON FAR *phiconSmall,  
  UINT nIcons               
);
 
int ExtSelectClipRgn(
  HDC hdc,          // handle to device context
  HRGN hrgn,        // handle to region
  int fnMode        // region-selection mode
);
 
BOOL ExtTextOut(
  HDC hdc,          // handle to device context
  int X,            // x-coordinate of reference point
  int Y,            // y-coordinate of reference point
  UINT fuOptions,   // text-output options
  CONST RECT *lprc, // optional clipping and/or opaquing rectangle
  LPCTSTR lpString, // points to string
  UINT cbCount,     // number of characters in string
  CONST INT *lpDx   // pointer to array of intercharacter spacing 
                    // values
);
 
VOID FatalAppExit(
  UINT uAction,  // reserved
  LPCTSTR lpMessageText 
                 // pointer to string to display in message box
);
 
VOID FatalExit(
  int ExitCode   // error code
);
 
VOID CALLBACK FiberProc(
  PVOID lpParameter   // fiber data
);
 
VOID CALLBACK FileIOCompletionRoutine(
  DWORD dwErrorCode,                // completion code
  DWORD dwNumberOfBytesTransfered,  // number of bytes transferred
  LPOVERLAPPED lpOverlapped         // pointer to structure with I/O 
                                    // information
);
 
BOOL FileTimeToDosDateTime(
  CONST FILETIME *lpFileTime,
                     // pointer to 64-bit file time
  LPWORD lpFatDate,  // pointer to variable for MS-DOS date
  LPWORD lpFatTime   // pointer to variable for MS-DOS time
);
 
BOOL FileTimeToLocalFileTime(
  CONST FILETIME *lpFileTime,  // pointer to UTC file time to convert
  LPFILETIME lpLocalFileTime   // pointer to converted file time
);
 
BOOL FileTimeToSystemTime(
  CONST FILETIME *lpFileTime,  // pointer to file time to convert
  LPSYSTEMTIME lpSystemTime    // pointer to structure to receive 
                               // system time
);
 
BOOL FillConsoleOutputAttribute(
  HANDLE hConsoleOutput,  // handle to screen buffer
  WORD wAttribute,        // color attribute to write
  DWORD nLength,          // number of character cells to write to
  COORD dwWriteCoord,     // x- and y-coordinates of first cell
  LPDWORD lpNumberOfAttrsWritten 
                          // pointer to number of cells written to
);
 
BOOL FillConsoleOutputCharacter(
  HANDLE hConsoleOutput,  // handle to screen buffer
  TCHAR cCharacter,       // character to write
  DWORD nLength,          // number of character cells to write to
  COORD dwWriteCoord,     // x- and y-coordinates of first cell
  LPDWORD lpNumberOfCharsWritten 
                          // pointer to number of cells written to
);
 
VOID FillMemory (
  PVOID Destination,  // pointer to block to fill
  DWORD Length,       // size, in bytes, of block to fill
  BYTE Fill           // the byte value with which to fill the block
);
 
VOID FillMemoryVlm (
  PVOID64 Destination,  // pointer to block to fill
  DWORD Length,         // size, in bytes, of block to fill
  BYTE Fill             // byte value with which to fill the block
);
 
BOOL FillPath(
  HDC hdc   // handle to device context
);
 
int FillRect(
  HDC hDC,           // handle to device context
  CONST RECT *lprc,  // pointer to structure with rectangle
  HBRUSH hbr         // handle to brush
);
 
BOOL FillRgn(
  HDC hdc,    // handle to device context
  HRGN hrgn,  // handle to region to be filled
  HBRUSH hbr  // handle to brush used to fill the region
);
 
ATOM FindAtom(
  LPCTSTR lpString   // pointer to string to find
);
 
BOOL FindClose(
  HANDLE hFindFile   // file search handle
);
 
BOOL FindCloseChangeNotification(
  HANDLE hChangeHandle   // handle to change notification to close
);
 
BOOL FindClosePrinterChangeNotification(
  HANDLE hChange  // handle to change notification object to close
);
 
HANDLE FindDebugInfoFile(
  IN LPSTR FileName,    
  IN LPSTR SymbolPath,  
  OUT LPSTR DebugFilePath  
);
 
HANDLE FindExecutableImage(
  IN LPSTR FileName,    
  IN LPSTR SymbolPath,  
  OUT LPSTR ImageFilePath  
);
 
HANDLE FindFirstChangeNotification(
  LPCTSTR lpPathName,    // pointer to name of directory to watch
  BOOL bWatchSubtree,    // flag for monitoring directory or 
                         // directory tree
  DWORD dwNotifyFilter   // filter conditions to watch for
);
 
HANDLE FindFirstFile(
  LPCTSTR lpFileName,  // pointer to name of file to search for
  LPWIN32_FIND_DATA lpFindFileData 
                       // pointer to returned information
);
 
HANDLE FindFirstFileEx(
  LPCTSTR lpFileName,     // pointer to the name of the file to 
                          // search for
  FINDEX_INFO_LEVELS fInfoLevelId,
                          // information level of the returned data
  LPVOID lpFindFileData,  // pointer to the returned information
  FINDEX_SEARCH_OPS fSearchOp,
                          // type of filtering to perform
  LPVOID lpSearchFilter,  // pointer to search criteria
  DWORD dwAdditionalFlags  // additional search control flags
);
 
BOOL FindFirstFreeAce(
  PACL pAcl,     // pointer to access-control list
  LPVOID *pAce   // pointer to pointer to first free byte
);
 
HANDLE FindFirstPrinterChangeNotification(
  HANDLE hPrinter,  // handle to printer or print server to monitor 
                    // for changes
  DWORD fdwFlags,   // flags that specify the conditions to monitor
  DWORD fdwOptions, // reserved, must be zero
  LPVOID pPrinterNotifyOptions
                    // pointer to structure specifying printer 
                    // information to monitor
);
 
BOOL FindNextChangeNotification(
  HANDLE hChangeHandle   // handle to change notification to signal
);
 
BOOL FindNextFile(
  HANDLE hFindFile,  // handle to search
  LPWIN32_FIND_DATA lpFindFileData 
                     // pointer to structure for data on found file
);
 
BOOL FindNextPrinterChangeNotification(
  HANDLE hChange,              // handle to change notification 
                               // object of interest
  PDWORD pdwChange,            // pointer to a value that indicates 
                               // the condition that changed
  LPVOID pPrinterNotifyOptions,  // pointer to a structure that 
                                 // specifies a refresh flag
  LPVOID *ppPrinterNotifyInfo  // pointer to a pointer that receives 
                               // printer information buffer
);
 
HRSRC FindResource(
  HMODULE hModule, // module handle
  LPCTSTR lpName,  // pointer to resource name
  LPCTSTR lpType   // pointer to resource type
);
 
HRSRC FindResourceEx(
  HMODULE hModule, // resource-module handle
  LPCTSTR lpType,  // pointer to resource type
  LPCTSTR lpName,  // pointer to resource name
  WORD wLanguage   // resource language
);
 
HWND FindText(
  LPFINDREPLACE lpfr   // pointer to structure with initialization 
                       // data
);
 
HWND FindWindow(
  LPCTSTR lpClassName,  // pointer to class name
  LPCTSTR lpWindowName  // pointer to window name
);
 
HWND FindWindowEx(
  HWND hwndParent,      // handle to parent window
  HWND hwndChildAfter,  // handle to a child window
  LPCTSTR lpszClass,    // pointer to class name
  LPCTSTR lpszWindow    // pointer to window name
);
 
BOOL FlashWindow(
  HWND hWnd,     // handle to window to flash
  BOOL bInvert   // flash status
);
 
BOOL FlashWindowEx(
  PFLASHWINFO pfwi
);
 
BOOL FlattenPath(
  HDC hdc   // handle to device context
);
 
BOOL FloodFill(
  HDC hdc,          // handle to device context
  int nXStart,      // x-coordinate, where fill begins
  int nYStart,      // y-coordinate, where fill begins
  COLORREF crFill   // fill color
);
 
BOOL FlushConsoleInputBuffer(
  HANDLE hConsoleInput   // handle to console input buffer
);
 
BOOL FlushFileBuffers(
  HANDLE hFile   // open handle to file whose buffers are to be 
                 // flushed
);
 
BOOL FlushInstructionCache(
  HANDLE hProcess,        // handle to process with cache to flush
  LPCVOID lpBaseAddress,  // pointer to region to flush
  DWORD dwSize            // length of region to flush
);
 
BOOL FlushViewOfFile(
  LPCVOID lpBaseAddress,       // start address of byte range to flush
  DWORD dwNumberOfBytesToFlush // number of bytes in range
);
 
int FoldString(
  DWORD dwMapFlags,  // mapping transformation options
  LPCTSTR lpSrcStr,  // pointer to source string
  int cchSrc,        // size of source string, in bytes or characters
  LPTSTR lpDestStr,  // pointer to destination buffer
  int cchDest        // size of destination buffer, in bytes or characters
);
 
DWORD CALLBACK ForegroundIdleProc(
  int code,      // hook code
  DWORD wParam,  // not used
  LONG lParam    // not used
);
 
DWORD FormatMessage(
  DWORD dwFlags,      // source and processing options
  LPCVOID lpSource,   // pointer to  message source
  DWORD dwMessageId,  // requested message identifier
  DWORD dwLanguageId, // language identifier for requested message
  LPTSTR lpBuffer,    // pointer to message buffer
  DWORD nSize,        // maximum size of message buffer
  va_list *Arguments  // pointer to array of message inserts
);
 
int FrameRect(
  HDC hDC,           // handle to device context
  CONST RECT *lprc,  // pointer to rectangle coordinates
  HBRUSH hbr         // handle to brush
);
 
BOOL FrameRgn(
  HDC hdc,     // handle to device context
  HRGN hrgn,   // handle to region to be framed
  HBRUSH hbr,  // handle to brush used to draw border
  int nWidth,  // width of region frame
  int nHeight  // height of region frame
);
 
BOOL FreeConsole(VOID);
 
BOOL FreeDDElParam(
  UINT msg,     // posted DDE message
  LONG lParam   // lParam of message
);
 
BOOL FreeEnvironmentStrings(
  LPTSTR lpszEnvironmentBlock  // pointer to a block of environment 
                               // strings
);
 
BOOL FreeLibrary(
  HMODULE hLibModule   // handle to loaded library module
);
 
VOID FreeLibraryAndExitThread(
  HMODULE hLibModule,  // dynamic-link library whose reference count 
                       // is to decrement
  DWORD dwExitCode     // exit code for thread
);
 
BOOL FreePrinterNotifyInfo(
  PPRINTER_NOTIFY_INFO pPrinterNotifyInfo  // pointer to a 
                                           // PRINTER_NOTIFY_INFO buffer
);
 
PVOID FreeSid(
  PSID pSid   // pointer to SID to free
);
 
UINT CALLBACK FRHookProc(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg      // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL GdiComment(
  HDC hdc,             // handle to a device context
  UINT cbSize,         // size of text buffer
  CONST BYTE *lpData   // pointer to text buffer
);
 
BOOL GdiFlush(VOID);
 
DWORD GdiGetBatchLimit(VOID);
 
DWORD GdiSetBatchLimit(
  DWORD dwLimit   // batch limit
);
 
BOOL GenerateConsoleCtrlEvent(
  DWORD dwCtrlEvent,       // signal to generate
  DWORD dwProcessGroupId   // process group to get signal
);
 
DWORD GetAccessPermissionsForObject(
  LPCTSTR lpObject,    // name of the object
  SE_OBJECT_TYPE ObjectType,
                       // type of object
  LPCTSTR lpProvider,  // name of provider to handle request
  PULONG pcEntries,    // receives number of entries in the array
  PACTRL_ACCESS_INFO *ppAccessInfoList,
                       // receives an array of access information
  PULONG pfAccessFlags // receives access flags
);
 
BOOL GetAce(
  PACL pAcl,         // pointer to access-control list
  DWORD dwAceIndex,  // index of ACE to retrieve
  LPVOID *pAce       // pointer to pointer to ACE
);
 
BOOL GetAclInformation(
  PACL pAcl,                    // pointer to access-control list
  LPVOID pAclInformation,       // pointer to ACL information
  DWORD nAclInformationLength,  // size of ACL information
  ACL_INFORMATION_CLASS dwAclInformationClass 
                                // class of requested information
);
 
UINT GetACP(VOID);
 
HWND GetActiveWindow(VOID);
 
int GetArcDirection(
  HDC hdc   // handle to device context
);
 
BOOL GetAspectRatioFilterEx(
  HDC hdc,               // handle to device context
  LPSIZE lpAspectRatio   // pointer to aspect-ratio filter
);
 
SHORT GetAsyncKeyState(
  int vKey   // virtual-key code
);
 
UINT GetAtomName(
  ATOM nAtom,       // atom identifying character string
  LPTSTR lpBuffer,  // address of buffer for atom string
  int nSize         // size of buffer
);
 
DWORD GetAuditedPermissionsFromAcl(
  PACL pacl,  // ACL to get trustee's audited rights from
  PTRUSTEE pTrustee,
              // trustee to get rights for
  PACCESS_MASK pSuccessfulAuditedRights,
              // receives rights audited for successful access
  PACCESS_MASK pFailedAuditRights
              // receives rights audited for failed access
);
 
BOOL GetBinaryType (
  LPCTSTR lpApplicationName,  // pointer to fully qualified path of 
                              // file to test
  LPDWORD lpBinaryType        // pointer to variable to receive 
                              // binary type information
);
 
LONG GetBitmapBits(
  HBITMAP hbmp,      // handle to bitmap
  LONG cbBuffer,     // number of bytes to copy
  LPVOID lpvBits     // pointer to buffer to receive bits
);
 
BOOL GetBitmapDimensionEx(
  HBITMAP hBitmap,     // handle to bitmap
  LPSIZE lpDimension   // address of structure receiving dimensions
);
 
COLORREF GetBkColor(
  HDC hdc   // handle of device context
);
 
int GetBkMode(
  HDC hdc   // handle to device context of interest
);
 
UINT GetBoundsRect(
  HDC hdc,            // handle to device context of interest
  LPRECT lprcBounds,  // pointer to structure to receive bounding rectangle
  UINT flags          // specifies function options
);
 
BOOL GetBrushOrgEx(
  HDC hdc,       // handle of device context
  LPPOINT lppt   // address of structure of coordinates
);
 
HWND GetCapture(VOID);
 
UINT GetCaretBlinkTime(VOID);
 
BOOL GetCaretPos(
  LPPOINT lpPoint   // address of structure to receive coordinates
);
 
BOOL GetCharABCWidths(
  HDC hdc,         // handle to device context
  UINT uFirstChar, // first character in range to query
  UINT uLastChar,  // last character in range to query
  LPABC lpabc      // pointer to character-width structure
);
 
BOOL GetCharABCWidthsFloat(
  HDC hdc,            // handle to device context
  UINT iFirstChar,    // first character in range to query
  UINT iLastChar,     // last character in range to query
  LPABCFLOAT lpABCF   // pointer to character-width structure
);
 
DWORD GetCharacterPlacement(
  HDC hdc,           // handle to device context
  LPCTSTR lpString,  // pointer to string
  int nCount,        // number of characters in string
  int nMaxExtent,    // maximum extent for displayed string
  LPGCP_RESULTS lpResults,
                     // pointer to buffer for placement result
  DWORD dwFlags      // placement flags
);
 
BOOL GetCharWidth(
  HDC hdc,         // handle to device context
  UINT iFirstChar, // first character in range to query
  UINT iLastChar,  // last character in range to query
  LPINT lpBuffer   // pointer to buffer for widths
);
 
BOOL GetCharWidth32(
  HDC hdc,         // handle to device context
  UINT iFirstChar, // first character in range to query
  UINT iLastChar,  // last character in range to query
  LPINT lpBuffer   // pointer to buffer for widths
);
 
BOOL GetCharWidthFloat(
  HDC hdc,         // handle to device context
  UINT iFirstChar, // first-character code point
  UINT iLastChar,  // last-character code point
  PFLOAT pxBuffer  // pointer to buffer that receives width-values
);
 
BOOL GetClassInfo(
  HINSTANCE hInstance,    // handle of application instance
  LPCTSTR lpClassName,    // address of class name string
  LPWNDCLASS lpWndClass   // address of structure for class data
);
 
BOOL GetClassInfoEx(
  HINSTANCE hinst,    // handle of application instance
  LPCTSTR lpszClass,  // address of class name string
  LPWNDCLASSEX lpwcx  // address of structure for class data
);
 
DWORD GetClassLong(
  HWND hWnd,  // handle of window
  int nIndex  // offset of value to retrieve
);
 
int GetClassName(
  HWND hWnd,           // handle of window
  LPTSTR lpClassName,  // address of buffer for class name
  int nMaxCount        // size of buffer, in characters
);
 
WORD GetClassWord(
  HWND hWnd,  // handle of window
  int nIndex  // offset of value to retrieve
);
 
BOOL GetClientRect(
  HWND hWnd,      // handle to window
  LPRECT lpRect   // address of structure for client coordinates
);
 
HANDLE GetClipboardData(
  UINT uFormat   // clipboard format
);
 
int GetClipboardFormatName(
  UINT format,            // clipboard format to retrieve
  LPTSTR lpszFormatName,  // address of buffer for name
  int cchMaxCount         // length of name string in characters
);
 
HWND GetClipboardOwner(VOID);
 
DWORD GetClipboardSequenceNumber(VOID);
 
HWND GetClipboardViewer(VOID);
 
int GetClipBox(
  HDC hdc,      // handle of the device context
  LPRECT lprc   // address of structure with rectangle
);
 
BOOL GetClipCursor(
  LPRECT lpRect   // address of structure for rectangle
);
 
int GetClipRgn(
  HDC hdc,           // handle of device context
  HRGN hrgn          // handle of region
);
 
DWORD WINAPI GetCMMInfo(
  HTRANSFORM hColorTransform,
  DWORD dwInfo
);
 
BOOL GetColorAdjustment(
  HDC hdc,                 // handle of device context
  LPCOLORADJUSTMENT lpca   // address of COLORADJUSTMENT structure
);
 
BOOL WINAPI GetColorDirectory(
  PCTSTR pMachineName,
  PTSTR pBuffer, 
  PDWORD pdwSize 
);
 
BOOL WINAPI GetColorProfileElement(
  HPROFILE hProfile,
  TAGTYPE tag,
  DWORD dwOffset,
  PDWORD pcbSize,
  PVOID pBuffer,
  PBOOL pbReference
);
 
BOOL WINAPI GetColorProfileElementTag(
  HPROFILE hProfile,
  DWORD dwIndex,
  PTAGTYPE pTag
);
 
BOOL WINAPI GetColorProfileFromHandle(
  HPROFILE hProfile,
  PBYTE pBuffer,
  PDWORD pcbSize
);
 
BOOL WINAPI GetColorProfileHeader(
  HPROFILE hProfile,
  PPROFILEHEADER pHeader
);
 
HCOLORSPACE WINAPI GetColorSpace(
  HDC hDC 
);
 
LPTSTR GetCommandLine(VOID);
 
BOOL GetCommConfig(
  HANDLE hCommDev,    // handle to communications service
  LPCOMMCONFIG lpCC,  // pointer to comm configuration structure
  LPDWORD lpdwSize    // pointer to size of buffer
);
 
BOOL GetCommMask(
  HANDLE hFile,      // handle to communications device
  LPDWORD lpEvtMask  // pointer to variable to get event mask
);
 
BOOL GetCommModemStatus(
  HANDLE hFile,        // handle to communications device
  LPDWORD lpModemStat  // pointer to control-register values
);
 
BOOL GetCommProperties(
  HANDLE hFile,           // handle to comm device
  LPCOMMPROP lpCommProp   // pointer to comm properties structure
);
 
BOOL GetCommState(
  HANDLE hFile,  // handle to communications device
  LPDCB lpDCB    // pointer to device-control block structure
);
 
BOOL GetCommTimeouts(
  HANDLE hFile,                  // handle to comm device
  LPCOMMTIMEOUTS lpCommTimeouts  // pointer to comm time-outs structure
);
 
DWORD GetCompressedFileSize(
  LPCTSTR lpFileName,     // pointer to name of file
  LPDWORD lpFileSizeHigh  // pointer to DWORD to receive high-order 
                          // doubleword of file size
);
 
BOOL GetComputerName(
  LPTSTR lpBuffer,  // address of name buffer
  LPDWORD nSize     // address of size of name buffer
);
 
UINT GetConsoleCP(VOID);
 
BOOL GetConsoleCursorInfo(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  PCONSOLE_CURSOR_INFO lpConsoleCursorInfo 
                          // address of cursor information
);
 
BOOL GetConsoleMode(
  HANDLE hConsoleHandle,
                   // handle to console input or screen buffer
  LPDWORD lpMode   // current mode flags
);
 
UINT GetConsoleOutputCP(VOID);
 
BOOL GetConsoleScreenBufferInfo(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo 
                          // address of screen buffer info.
);
 
DWORD GetConsoleTitle(
  LPTSTR lpConsoleTitle,  // address of buffer for title
  DWORD nSize             // size of the buffer
);
 
BOOL WINAPI GetCountColorProfileElements(
  HPROFILE hProfile,
  PDWORD pnCount
);
 
BOOL GetCPInfo(
  UINT CodePage,      // code page identifier
  LPCPINFO lpCPInfo   // address of structure for information
);
 
BOOL GetCPInfoEx (
  UINT CodePage,         // code-page identifier
  DWORD dwFlags,         // flags (must be 0)
  LPCPINFOEX lpCPInfoEx  // address of structure for information
);
 
int GetCurrencyFormat(
  LCID Locale,                  // locale for which string is to be formatted
  DWORD dwFlags,                // bit flag that controls the function's operation
  LPCTSTR lpValue,              // pointer to input number string
  CONST CURRENCYFMT *lpFormat,  // pointer to a formatting information structure
  LPTSTR lpCurrencyStr,         // pointer to output buffer
  int cchCurrency               // size of output buffer
);
 
DWORD GetCurrentDirectory(
  DWORD nBufferLength,  // size, in characters, of directory buffer
  LPTSTR lpBuffer       // pointer to buffer for current directory
);
 
PVOID GetCurrentFiber(VOID);
 
BOOL GetCurrentHwProfile(
  LPHW_PROFILE_INFO lpHwProfileInfo  // receives the hardware 
                                     // profile information
);
 
HGDIOBJ GetCurrentObject(
  HDC hdc,           // handle to device context
  UINT uObjectType   // specifies the object-type
);
 
BOOL GetCurrentPositionEx(
  HDC hdc,  // handle of device context
  LPPOINT lpPoint 
            // address of structure receiving current position
);
 
HANDLE GetCurrentProcess(VOID);
 
DWORD GetCurrentProcessId(VOID);
 
HANDLE GetCurrentThread(VOID);
 
DWORD GetCurrentThreadId(VOID);
 
HCURSOR GetCursor(VOID);
 
BOOL GetCursorPos(
  LPPOINT lpPoint   // address of structure for cursor position
);
 
int GetDateFormat(
  LCID Locale,               // locale for which date is to be formatted
  DWORD dwFlags,             // flags specifying function options
  CONST SYSTEMTIME *lpDate,  // date to be formatted
  LPCTSTR lpFormat,          // date format string
  LPTSTR lpDateStr,          // buffer for storing formatted string
  int cchDate                // size of buffer
);
 
HDC GetDC(
  HWND hWnd   // handle to a window
);
 
GetDCBrushColor(
  HDC hdc
);
 
HDC GetDCEx(
  HWND hWnd,      // handle of window
  HRGN hrgnClip,  // handle of clip region
  DWORD flags     // device-context creation flags
);
 
BOOL GetDCOrgEx(
  HDC hdc,          // device-context handle
  LPPOINT lpPoint   // pointer to structure receiving the translation origin
);
 
GetDCPenColor(
  HDC hdc  // handle to the device context
);
 
BOOL GetDefaultCommConfig(
  LPCSTR lpszName,    // pointer to device name string
  LPCOMMCONFIG lpCC,  // pointer to buffer that receives structure
  LPDWORD lpdwSize    // pointer to size of buffer
);
 
HWND GetDesktopWindow(VOID);
 
int GetDeviceCaps(
  HDC hdc,     // handle to the device context
  int nIndex   // index of capability to query
);
 
BOOL WINAPI GetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
);
 
BOOL GetDevicePowerState(
  HANDLE hDevice,     // device-context handle
  BOOL pfOn           // pointer to variable receiving power state
);
 
LONG GetDialogBaseUnits(VOID);
 
UINT GetDIBColorTable(
  HDC hdc,          // handle to device context whose DIB is of 
                    // interest
  UINT uStartIndex, // color table index of first entry to retrieve
  UINT cEntries,    // number of color table entries to retrieve
  RGBQUAD *pColors  // pointer to buffer that receives color table 
                    // entries
);
 
int GetDIBits(
  HDC hdc,           // handle to device context
  HBITMAP hbmp,      // handle to bitmap
  UINT uStartScan,   // first scan line to set in destination bitmap
  UINT cScanLines,   // number of scan lines to copy
  LPVOID lpvBits,    // address of array for bitmap bits
  LPBITMAPINFO lpbi, // address of structure with bitmap data
  UINT uUsage        // RGB or palette index
);
 
BOOL GetDiskFreeSpace(
  LPCTSTR lpRootPathName,    // pointer to root path
  LPDWORD lpSectorsPerCluster,  // pointer to sectors per cluster
  LPDWORD lpBytesPerSector,  // pointer to bytes per sector
  LPDWORD lpNumberOfFreeClusters,
                             // pointer to number of free clusters
  LPDWORD lpTotalNumberOfClusters 
                             // pointer to total number of clusters
);
 
BOOL GetDiskFreeSpaceEx(
  LPCTSTR lpDirectoryName,                 // pointer to the directory name
  PULARGE_INTEGER lpFreeBytesAvailableToCaller, // receives the number of bytes on
                                                // disk available to the caller
  PULARGE_INTEGER lpTotalNumberOfBytes,    // receives the number of bytes on disk
  PULARGE_INTEGER lpTotalNumberOfFreeBytes // receives the free bytes on disk
);
 
int GetDlgCtrlID(
  HWND hwndCtl   // handle of control
);
 
HWND GetDlgItem(
  HWND hDlg,       // handle of dialog box
  int nIDDlgItem   // identifier of control
);
 
UINT GetDlgItemInt(
  HWND hDlg,       // handle to dialog box
  int nIDDlgItem,  // control identifier
  BOOL *lpTranslated,
                   // points to variable to receive success/failure 
                   // indicator
  BOOL bSigned     // specifies whether value is signed or unsigned
);
 
UINT GetDlgItemText(
  HWND hDlg,       // handle of dialog box
  int nIDDlgItem,  // identifier of control
  LPTSTR lpString, // address of buffer for text
  int nMaxCount    // maximum size of string
);
 
UINT GetDoubleClickTime(VOID);

UINT GetDriveType(
  LPCTSTR lpRootPathName   // pointer to root path
);
 
DWORD GetEffectiveRightsFromAcl(
  PACL pacl,                   // ACL to get trustee's rights from
  PTRUSTEE pTrustee,           // trustee to get rights for
  PACCESS_MASK pAccessRights  // receives trustee's access rights
);
 
HENHMETAFILE GetEnhMetaFile(
  LPCTSTR lpszMetaFile   // pointer to metafile name
);
 
UINT GetEnhMetaFileBits(
  HENHMETAFILE hemf, // handle to metafile
  UINT cbBuffer,     // size of data buffer, in bytes
  LPBYTE lpbBuffer   // pointer to data buffer
);
 
UINT GetEnhMetaFileDescription(
  HENHMETAFILE hemf,       // handle to enhanced metafile
  UINT cchBuffer,          // size of text buffer, in characters
  LPTSTR lpszDescription   // pointer to text buffer
);
 
UINT GetEnhMetaFileHeader(
  HENHMETAFILE hemf,      // handle to enhanced metafile
  UINT cbBuffer,          // size of buffer, in bytes
  LPENHMETAHEADER lpemh   // pointer to the buffer to receive data
);
 
UINT GetEnhMetaFilePaletteEntries(
  HENHMETAFILE hemf,    // handle to enhanced metafile
  UINT cEntries,        // count of palette entries
  LPPALETTEENTRY lppe   // pointer to palette-entry array
);
 
LPVOID GetEnvironmentStrings(VOID);
 
DWORD GetEnvironmentVariable(
  LPCTSTR lpName,  // address of environment variable name
  LPTSTR lpBuffer, // address of buffer for variable value
  DWORD nSize      // size of buffer, in characters
);
 
DWORD GetExceptionCode(VOID);
 
LPEXCEPTION_POINTERS GetExceptionInformation(VOID);
 
BOOL GetExitCodeProcess(
  HANDLE hProcess,     // handle to the process
  LPDWORD lpExitCode   // address to receive termination status
);
 
BOOL GetExitCodeProcess(
  HANDLE hProcess,     // handle to the process
  LPDWORD lpExitCode   // address to receive termination status
);
 
BOOL GetExitCodeThread(
  HANDLE hThread,      // handle to the thread
  LPDWORD lpExitCode   // address to receive termination status
);
 
INT GetExpandedName(
  LPTSTR lpszSource,  // address of name of compressed file
  LPTSTR lpszBuffer   // address of buffer for original filename
);
 
DWORD GetExplicitEntriesFromAcl(
  PACL pacl,  // pointer to the ACL from which to get entries
  PULONG pcCountOfExplicitEntries,
              // receives number of entries in the list
  PEXPLICIT_ACCESS *pListOfExplicitEntries
              // receives pointer to list of entries
);
 
PVOID GetFiberData(VOID);
 
DWORD GetFileAttributes(
  LPCTSTR lpFileName   // pointer to the name of a file or directory
);
 
BOOL GetFileAttributesEx(
  LPCTSTR lpFileName,        // pointer to string that specifies a 
                             // file or directory
  GET_FILEEX_INFO_LEVELS fInfoLevelId, 
                             // value that specifies the type of 
                             // attribute information to obtain
  LPVOID lpFileInformation   // pointer to buffer to receive 
                             // attribute information
);
 
BOOL GetFileInformationByHandle(
  HANDLE hFile,                                  // handle of file 
  LPBY_HANDLE_FILE_INFORMATION lpFileInformation // pointer to structure
);
 
BOOL GetFileSecurity(
  LPCTSTR lpFileName,       // address of string for file name
  SECURITY_INFORMATION RequestedInformation,
                            // requested information
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                            // address of security descriptor
  DWORD nLength,            // size of security descriptor buffer
  LPDWORD lpnLengthNeeded   // address of required size of buffer
);
 
DWORD GetFileSize(
  HANDLE hFile,  // handle of file to get size of
  LPDWORD lpFileSizeHigh 
                 // pointer to high-order word for file size
);
 
BOOL GetFileTime(
  HANDLE hFile,                 // handle to the file
  LPFILETIME lpCreationTime,    // address of creation time
  LPFILETIME lpLastAccessTime,  // address of last access time
  LPFILETIME lpLastWriteTime    // address of last write time
);
 
short GetFileTitle(
  LPCTSTR lpszFile,  // pointer to full path and filename for file
  LPTSTR lpszTitle,  // pointer to buffer that receives filename
  WORD cbBuf         // length of buffer
);
 
DWORD GetFileType(
  HANDLE hFile   // file handle
);
 
BOOL GetFileVersionInfo(
  LPTSTR lptstrFilename,  // pointer to filename string
  DWORD dwHandle,         // ignored
  DWORD dwLen,            // size of buffer
  LPVOID lpData           // pointer to buffer to receive 
                          // file-version info.
);
 
DWORD GetFileVersionInfoSize(
  LPTSTR lptstrFilename,  // pointer to filename string
  LPDWORD lpdwHandle      // pointer to variable to receive zero
);
 
HWND GetFocus(VOID);
 
DWORD GetFontData(
  HDC hdc,           // handle to device context
  DWORD dwTable,     // metric table to query
  DWORD dwOffset,    // offset into table being queried
  LPVOID lpvBuffer,  // pointer to buffer for returned data
  DWORD cbData       // length of data to query
);
 
DWORD GetFontLanguageInfo(
  HDC hdc  // handle to a device context
);
 
WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(
  HDC hdc,         // handle to the device context
  LPGLYPHSET lpgs  // pointer to the glyph set structure
);
 
HWND GetForegroundWindow(VOID);
 
BOOL GetForm(
  HANDLE hPrinter,   // handle to printer
  LPTSTR pFormName,  // address of form name
  DWORD Level,       // structure level
  LPBYTE pForm,      // address of structure array
  DWORD cbBuf,       // count of bytes in array
  LPDWORD pcbNeeded  // addr. of variable with count of bytes 
                     // retrieved (or required)
);
 
DWORD GetFullPathName(
  LPCTSTR lpFileName,  // pointer to name of file to find path for
  DWORD nBufferLength, // size, in characters, of path buffer
  LPTSTR lpBuffer,     // pointer to path buffer
  LPTSTR *lpFilePart   // pointer to filename in path
);
 
WINGDIAPI DWORD WINAPI GetGlyphIndices(
  HDC hdc,       // device context
  LPCTSTR lpstr, // string to convert
  int c,         // number of characters in string
  LPWORD pgi,    // array of glyph indices
  DWORD fl       // flags
);
 
DWORD GetGlyphOutline(
  HDC hdc,             // handle to device context
  UINT uChar,          // character to query
  UINT uFormat,        // format of data to return
  LPGLYPHMETRICS lpgm, // pointer to structure for metrics
  DWORD cbBuffer,      // size of buffer for data
  LPVOID lpvBuffer,    // pointer to buffer for data
  CONST MAT2 *lpmat2   // pointer to transformation matrix structure
);
 
int GetGraphicsMode(
  HDC hdc   // handle of device context
);
 
DWORD GetGuiResource (
  HANDLE hProcess,  // identifies the process of interest
  DWORD uiFlags     // indicates the GUI object type
);
 
BOOL GetHandleInformation(
  HANDLE hObject,    // handle to an object
  LPDWORD lpdwFlags  // points to variable to receive flags
);
 
BOOL WINAPI GetICMProfile(
  HDC hDC,
  LPDWORD lpcbName,
  LPTSTR lpszFilename
);
 
BOOL GetIconInfo(
  HICON hIcon,          // icon handle
  PICONINFO piconinfo   // address of icon structure
);
 
BOOL GetImageConfigInformation(
  IN PLOADED_IMAGE LoadedImage,                            
  OUT PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation  
);
 
DWORD GetImageUnusedHeaderBytes(
  IN PLOADED_IMAGE LoadedImage,  
  OUT LPDWORD SizeUnusedHeaderBytes  
);
 
BOOL GetInputState(VOID);
 
BOOL GetJob(
  HANDLE hPrinter,    // handle to printer
  DWORD JobId,        // job identifier value
  DWORD Level,        // data-structure level
  LPBYTE pJob,        // address of data-structure array
  DWORD cbBuf,        // count of bytes in array
  LPDWORD pcbNeeded   // address of value that contains count of 
                      // bytes retrieved (or required)
);
 
UINT GetKBCodePage(VOID);
 
BOOL GetKernelObjectSecurity(
  HANDLE Handle,  // handle of object to query
  SECURITY_INFORMATION RequestedInformation,
                  // requested information
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                  // address of security descriptor
  DWORD nLength,  // size of buffer for security descriptor
  LPDWORD lpnLengthNeeded 
                  // address of required size of buffer
);
 
DWORD GetKerningPairs(
  HDC hdc,          // handle to device context
  DWORD nNumPairs,  // number of kerning-pairs to be retrieved
  LPKERNINGPAIR lpkrnpair 
                    // pointer to kerning-pair array
);
 
HKL GetKeyboardLayout(
  DWORD dwLayout  // thread identifier
);
 
UINT GetKeyboardLayoutList(
  int nBuff,       // size of buffer in array element
  HKL FAR *lpList  // buffer for keyboard layout handles
);
 
BOOL GetKeyboardLayoutName(
  LPTSTR pwszKLID   // pointer to buffer for layout name
);
 
BOOL GetKeyboardState(
  PBYTE lpKeyState   // pointer to array to receive status data
);
 
int GetKeyboardType(
  int nTypeFlag   // type of information to retrieve
);
 
int GetKeyNameText(
  LONG lParam,      // second parameter of keyboard message
  LPTSTR lpString,  // pointer to buffer for key name
  int nSize         // maximum length of key-name string length
);
 
SHORT GetKeyState(
  int nVirtKey   // virtual-key code
);
 
COORD GetLargestConsoleWindowSize(
  HANDLE hConsoleOutput   // handle to console screen buffer
);
 
HWND GetLastActivePopup(
  HWND hWnd   // handle to owner window
);
 
DWORD GetLastError(VOID);
 
DWORD GetLengthSid(
  PSID pSid   // address of SID to query
);
 
int GetLocaleInfo(
  LCID Locale,      // locale identifier
  LCTYPE LCType,    // type of information
  LPTSTR lpLCData,  // address of buffer for information
  int cchData       // size of buffer
);
 
VOID GetLocalTime(
  LPSYSTEMTIME lpSystemTime   // address of system time structure
);
 
BOOL WINAPI GetLogColorSpace(
  HCOLORSPACE hColorSpace,
  LPLOGCOLORSPACE lpBuffer,
  DWORD nSize
);
 
DWORD GetLogicalDrives(VOID);
 
DWORD GetLogicalDriveStrings(
  DWORD nBufferLength,  // size of buffer
  LPTSTR lpBuffer       // pointer to buffer for drive strings
);
 
DWORD GetLongPathName(
  LPCTSTR lpszShortPath, 
  LPTSTR lpszLongPath, 
  DWORD cchBuffer
);
 
BOOL GetMailslotInfo(
  HANDLE hMailslot,       // mailslot handle
  LPDWORD lpMaxMessageSize,  // address of maximum message size
  LPDWORD lpNextSize,     // address of size of next message
  LPDWORD lpMessageCount,  // address of number of messages
  LPDWORD lpReadTimeout   // address of read time-out
);
 
int GetMapMode(
  HDC hdc   // handle of device context
);
 
HMENU GetMenu(
  HWND hWnd  // handle to window
);
 
UINT GetMenuDefaultItem(
  HMENU hMenu,   
  UINT fByPos,   
  UINT gmdiFlags 
);
 
int GetMenuItemCount(
  HMENU hMenu  // handle to menu
);
 
UINT GetMenuItemID(
  HMENU hMenu,  // handle to menu
  int nPos      // position of menu item
);
 
BOOL GetMenuItemInfo(
  HMENU hMenu,          
  UINT uItem,           
  BOOL fByPosition,     
  LPMENUITEMINFO lpmii  
);
 
BOOL GetMenuItemRect(
  HWND hWnd,       
  HMENU hMenu,     
  UINT uItem,      
  LPRECT lprcItem  
);
 
UINT GetMenuState(
  HMENU hMenu, // handle to menu
  UINT uId,    // menu item to query
  UINT uFlags  // menu flags
);
 
int GetMenuString(
  HMENU hMenu,      // handle to the menu
  UINT uIDItem,     // menu item identifier
  LPTSTR lpString,  // pointer to the buffer for the string
  int nMaxCount,    // maximum length of the string
  UINT uFlag        // menu flags
);
 
BOOL GetMessage(
  LPMSG lpMsg,         // address of structure with message
  HWND hWnd,           // handle of window
  UINT wMsgFilterMin,  // first message
  UINT wMsgFilterMax   // last message
);
 
LONG GetMessageExtraInfo(VOID);
 
DWORD GetMessagePos(VOID);
 
LONG GetMessageTime(VOID);
 
UINT GetMetaFileBitsEx(
  HMETAFILE hmf,  // handle to metafile
  UINT nSize,     // size of metafile, in bytes
  LPVOID lpvData  // pointer to metafile data
);
 
int GetMetaRgn(
  HDC hdc,    // handle of device context
  HRGN hrgn   // handle of region
);
 
BOOL GetMiterLimit(
  HDC hdc,         // handle to device context
  PFLOAT peLimit   // pointer to variable receiving miter limit
);
 
DWORD GetModuleFileName(
  HMODULE hModule,    // handle to module to find filename for
  LPTSTR lpFilename,  // pointer to buffer to receive module path
  DWORD nSize         // size of buffer, in characters
);
 
HMODULE GetModuleHandle(
  LPCTSTR lpModuleName   // address of module name to return handle 
                         // for
);
 
BOOL GetMonitorInfo(
  HMONITOR hMonitor,  // handle to display monitor
  LPMONITORINFO lpmi  // pointer to display monitor information 
);
 
int GetMouseMovePoints(
  UINT cbSize                // size of the MOUSEMOVEPOINT struct
  LPMOUSEMOVEPOINT lppt,     // pointer to current mouse move point
  LPMOUSEMOVEPOINT lpptBuf,  // buffer to store the points
  int nBufPoints,            // how many points the buffer can store
  DWORD resolution           // resolution of the points
);
 
LRESULT CALLBACK GetMsgProc(
  int code,       // hook code
  WPARAM wParam,  // removal flag
  LPARAM lParam   // address of structure with message
);
 
BOOL GetNamedPipeHandleState(
  HANDLE hNamedPipe,             // handle to named pipe
  LPDWORD lpState,               // pointer to pipe state flags state
  LPDWORD lpCurInstances,        // pointer to number of current pipe instances
  LPDWORD lpMaxCollectionCount,  // pointer to maximum collection count 
  LPDWORD lpCollectDataTimeout,  // pointer to time before remote transmission
  LPTSTR lpUserName,             // pointer to user name of client process
  DWORD nMaxUserNameSize         // size, in characters, of user name buffer
);
 
BOOL GetNamedPipeInfo(
  HANDLE hNamedPipe,        // handle to named pipe
  LPDWORD lpFlags,          // pointer to flags indicating the pipe type 
  LPDWORD lpOutBufferSize,  // pointer to size of pipe's output buffer
  LPDWORD lpInBufferSize,   // pointer to size of pipe's input buffer
  LPDWORD lpMaxInstances    // pointer to the maximum number of pipe instances
);
 
BOOL WINAPI GetNamedProfileInfo(
  HPROFILE hProfile,
  PNAMED_PROFILE_INFO pNamedProfileInfo
);
 
DWORD GetNamedSecurityInfo(
  LPTSTR pObjectName,
                     // name of the object
  SE_OBJECT_TYPE ObjectType,
                     // type of object
  SECURITY_INFORMATION SecurityInfo, 
                     // type of security information to retrieve
  PSID *ppsidOwner,  // receives a pointer to the owner SID
  PSID *ppsidGroup,  // receives a pointer to the primary group SID
  PACL *ppDacl,      // receives a pointer to the DACL
  PACL *ppSacl,      // receives a pointer to the SACL
  PSECURITY_DESCRIPTOR *ppSecurityDescriptor
                     // receives a pointer to the security descriptor
);
 
DWORD GetNamedSecurityInfoEx(
  LPCTSTR lpObject,    // name of the object
  SE_OBJECT_TYPE ObjectType,
                       // type of object
  SECURITY_INFORMATION SecurityInfo,
                       // type of security information to retrieve
  LPCTSTR lpProvider,  // name of provider to handle request
  LPCTSTR lpProperty,  // identifies a property, property set, or 
                       // child object
  PACTRL_ACCESS *ppAccessList,
                       // receives a pointer to access-control info
  PACTRL_AUDIT *ppAuditList,
                       // receives a pointer to audit-control info
  LPTSTR *lppOwner,    // receives the name of the object's owner
  LPTSTR *lppGroup     // receives the name of the object's primary 
                       // group
);

COLORREF GetNearestColor(
  HDC hdc,           // handle of device context
  COLORREF crColor   // color to be matched
);
 
UINT GetNearestPaletteIndex(
  HPALETTE hpal,     // handle of logical color palette
  COLORREF crColor   // color to be matched
);
 
HWND GetNextDlgGroupItem(
  HWND hDlg,       // handle of dialog box
  HWND hCtl,       // handle of control
  BOOL bPrevious   // direction flag
);
 
HWND GetNextDlgTabItem(
  HWND hDlg,       // handle of dialog box
  HWND hCtl,       // handle of known control
  BOOL bPrevious   // direction flag
);
 
HWND GetNextWindow(
  HWND hWnd,  // handle to current window
  UINT wCmd   // direction flag
);
 
int GetNumberFormat(
  LCID Locale,                // locale for which string is to be formatted
  DWORD dwFlags,              // bit flag that controls the function's operation
  LPCTSTR lpValue,            // pointer to input number string
  CONST NUMBERFMT *lpFormat,  // pointer to a formatting information structure
  LPTSTR lpNumberStr,         // pointer to output buffer
  int cchNumber               // size of output buffer
);
 
BOOL GetNumberOfConsoleInputEvents(
  HANDLE hConsoleInput,       // handle to console input buffer
  LPDWORD lpcNumberOfEvents   // address for number of events
);
 
BOOL GetNumberOfConsoleMouseButtons(
  LPDWORD lpNumberOfMouseButtons   // address of number of buttons
);
 
BOOL GetNumberOfEventLogRecords(
  HANDLE hEventLog,        // handle to event log
  PDWORD NumberOfRecords   // buffer for number of records
);
 
int GetObject(
  HGDIOBJ hgdiobj,  // handle to graphics object of interest
  int cbBuffer,     // size of buffer for object information
  LPVOID lpvObject  // pointer to buffer for object information
);
 
DWORD GetObjectType(
  HGDIOBJ h   // handle to graphics object
);
 
UINT GetOEMCP(VOID);
 
BOOL GetOldestEventLogRecord(
  HANDLE hEventLog,     // handle to event log
  PDWORD OldestRecord   // buffer for number of oldest record
);
 
HWND GetOpenClipboardWindow(VOID);
 
BOOL GetOpenFileName(
  LPOPENFILENAME lpofn   // address of structure with initialization 
                         // data
);
 
UINT GetOutlineTextMetrics(
  HDC hdc,                    // handle to device context
  UINT cbData,                // size of metric data array
  LPOUTLINETEXTMETRIC lpOTM   // pointer to metric data array
);
 
DWORD GetOverlappedAccessResults(
  PACTRL_OVERLAPPED pOverlapped,
                   // pointer to the structure filled in by the 
                   // asynchronous call
  BOOL fWaitForCompletion,
                   // TRUE indicates to wait for completion
  PDWORD pResult,  // receives the result of the asynchronous 
                   // operation
  PULONG pcItemsProcessed
                   // receives the number of objects processed
);
 
BOOL GetOverlappedResult(
  HANDLE hFile,                       // handle to file, pipe, or comm device
  LPOVERLAPPED lpOverlapped,          // pointer to overlapped structure
  LPDWORD lpNumberOfBytesTransferred, // pointer to actual bytes count
  BOOL bWait                          // wait flag
);
 
UINT GetPaletteEntries(
  HPALETTE hpal,        // handle of logical color palette
  UINT iStartIndex,     // first entry to retrieve
  UINT nEntries,        // number of entries to retrieve
  LPPALETTEENTRY lppe   // address of array receiving entries
);
 
HWND GetParent(
  HWND hWnd   // handle to child window
);
 
int GetPath(
  HDC hdc,           // handle to device context
  LPPOINT lpPoints,  // pointer to array receiving path vertices
  LPBYTE lpTypes,    // pointer to array of path vertex types
  int nSize          // count of points defining path
);
 
COLORREF GetPixel(
  HDC hdc,   // handle to device context
  int XPos,  // x-coordinate of pixel
  int nYPos  // y-coordinate of pixel
);
 
int GetPolyFillMode(
  HDC hdc   // handle to device context
);
 
BOOL GetPrinter(
  HANDLE hPrinter,    // handle to printer of interest
  DWORD Level,        // version of printer info data structure
  LPBYTE pPrinter,    // pointer to array of bytes that receives 
                      // printer info structure
  DWORD cbBuf,        // size, in bytes, of the pPrinter buffer
  LPDWORD pcbNeeded   // pointer to variable with count of bytes 
                      // retrieved (or required)
);
 
DWORD GetPrinterData(
  HANDLE hPrinter,    // handle to a printer or print server
  LPTSTR pValueName,  // string that identifies the data to retrieve
  LPDWORD pType,      // variable that receives the type of data
  LPBYTE pData,       // buffer that receives the configuration data
  DWORD nSize,        // size, in bytes, of buffer
  LPDWORD pcbNeeded   // receives the required buffer size, in bytes 
);
 
DWORD GetPrinterDataEx(
  HANDLE hPrinter,     // handle to printer or print server
  LPCTSTR pKeyName,    // name of registry key
  LPCTSTR pValueName,  // name of registry value
  LPDWORD pType,       // receives type of data stored in value
  LPBYTE pData,        // buffer that receives configuration data
  DWORD nSize,         // size, in bytes, of the buffer
  LPDWORD pcbNeeded    // receives the required buffer size, in bytes 
);
 
BOOL GetPrinterDriver(
  HANDLE hPrinter,     // printer object
  LPTSTR pEnvironment, // address of environment
  DWORD Level,         // structure level
  LPBYTE pDriverInfo,  // address of structure array
  DWORD cbBuf,         // size, in bytes, of array
  LPDWORD pcbNeeded    // address of variable with number of bytes 
                       // retrieved (or required)
);
 
BOOL GetPrinterDriverDirectory(
  LPTSTR pName,         // address of server name
  LPTSTR pEnvironment,  // address of environment
  DWORD Level,          // address of structure
  LPBYTE pDriverDirectory,  // address of structure array that 
                            // receives path
  DWORD cbBuf,          // size, in bytes, of array
  LPDWORD pcbNeeded     // address of variable with number of bytes 
                        // retrieved (or required)
);
 
BOOL GetPrintProcessorDirectory(
  LPTSTR pName,                // address of server name
  LPTSTR pEnvironment,         // address of environment
  DWORD Level,                 // structure level
  LPBYTE pPrintProcessorInfo,  // address of structure array
  DWORD cbBuf,                 // size, in bytes, of array
  LPDWORD pcbNeeded            // address of variable with number of 
                               // bytes retrieved (or required)
);
 
DWORD GetPriorityClass(
  HANDLE hProcess   // handle to the process
);
 
int GetPriorityClipboardFormat(
  UINT *paFormatPriorityList,  // address of priority list
  int cFormats                 // number of entries in list
);
 
BOOL GetPrivateObjectSecurity(
  PSECURITY_DESCRIPTOR ObjectDescriptor,
                        // address of SD to query
  SECURITY_INFORMATION SecurityInformation,
                        // requested information
  PSECURITY_DESCRIPTOR ResultantDescriptor,
                        // address of retrieved SD
  DWORD DescriptorLength,  // size of buffer for retrieved SD
  PDWORD ReturnLength   // address of buffer size required for SD
);
 
UINT GetPrivateProfileInt(
  LPCTSTR lpAppName,  // address of section name
  LPCTSTR lpKeyName,  // address of key name
  INT nDefault,       // return value if key name is not found
  LPCTSTR lpFileName  // address of initialization filename
);
 
DWORD GetPrivateProfileSection(
  LPCTSTR lpAppName,        // address of section name
  LPTSTR lpReturnedString,  // address of return buffer
  DWORD nSize,              // size of return buffer
  LPCTSTR lpFileName        // address of initialization filename
);
 
DWORD GetPrivateProfileSectionNames(
  LPTSTR lpszReturnBuffer,  // address of return buffer
  DWORD nSize,              // size of return buffer
  LPCTSTR lpFileName        // address of initialization filename
);
 
DWORD GetPrivateProfileString(
  LPCTSTR lpAppName,        // points to section name
  LPCTSTR lpKeyName,        // points to key name
  LPCTSTR lpDefault,        // points to default string
  LPTSTR lpReturnedString,  // points to destination buffer
  DWORD nSize,              // size of destination buffer
  LPCTSTR lpFileName        // points to initialization filename
);
 
BOOL GetPrivateProfileStruct(
  LPCTSTR lpszSection,  // address of section name
  LPCTSTR lpszKey,      // address of key name
  LPVOID lpStruct,      // address of return buffer
  UINT uSizeStruct,     // size of return buffer
  LPCTSTR szFile        // address of initialization filename
);
 
FARPROC GetProcAddress(
  HMODULE hModule,    // handle to DLL module
  LPCSTR lpProcName   // name of function
);
 
BOOL GetProcessAffinityMask(
  HANDLE hProcess,              // handle to the process of interest
  LPDWORD lpProcessAffinityMask,  // pointer to structure to receive 
                                  // process affinity mask
  LPDWORD lpSystemAffinityMask    // pointer to structure to receive 
                                  // system affinity mask
);
 
HANDLE GetProcessHeap(VOID);
 
DWORD GetProcessHeaps(
  DWORD NumberOfHeaps,  // maximum number of heap handles buffer can 
                        // receive
  PHANDLE ProcessHeaps  // pointer to buffer to receive heap handles
);
 
BOOL GetProcessPriorityBoost(
  HANDLE hProcess,  // handle to process
  PBOOL pDisablePriorityBoost
                    // indicates priority boost control state
);
 
BOOL GetProcessShutdownParameters(
  LPDWORD lpdwLevel, // shutdown priority
  LPDWORD lpdwFlags  // shutdown flag
);
 
BOOL GetProcessTimes(
  HANDLE hProcess,           // specifies the process of interest
  LPFILETIME lpCreationTime, // when the process was created
  LPFILETIME lpExitTime,     // when the process exited
  LPFILETIME lpKernelTime,   // time the process has spent in kernel
                             // mode
  LPFILETIME lpUserTime      // time the process has spent in user mode
);
 
DWORD GetProcessVersion(
  DWORD ProcessId  // identifier specifying the process of interest
);
 
HWINSTA GetProcessWindowStation(VOID);
 
BOOL GetProcessWorkingSetSize(
  HANDLE hProcess,  // open handle to the process of interest
  LPDWORD lpMinimumWorkingSetSize,
                    // points to variable to receive minimum working 
                    // set size
  LPDWORD lpMaximumWorkingSetSize 
                    // points to variable to receive maximum working 
                    // set size
);
 
UINT GetProfileInt(
  LPCTSTR lpAppName,  // address of section name
  LPCTSTR lpKeyName,  // address of key name
  INT nDefault        // default value if key name is not found
);
 
DWORD GetProfileSection(
  LPCTSTR lpAppName,        // address of section name
  LPTSTR lpReturnedString,  // address of return buffer
  DWORD nSize               // size of return buffer
);
 
DWORD GetProfileString(
  LPCTSTR lpAppName,        // address of section name
  LPCTSTR lpKeyName,        // address of key name
  LPCTSTR lpDefault,        // address of default string
  LPTSTR lpReturnedString,  // address of destination buffer
  DWORD nSize               // size of destination buffer
);
 
HANDLE GetProp(
  HWND hWnd,         // handle of window
  LPCTSTR lpString   // atom or address of string
);
 
BOOL WINAPI GetPS2ColorRenderingDictionary(
  HPROFILE hProfile,
  DWORD dwIntent,
  PBYTE pBuffer,
  PDWORD pcbSize,
  PBOOL pbBinary
);
 
BOOL WINAPI GetPS2ColorRenderingIntent(
  HPROFILE hProfile,
  DWORD dwIntent,
  PBYTE pBuffer,
  PDWORD pcbSize
);
 
BOOL WINAPI GetPS2ColorSpaceArray(
  HPROFILE hProfile,
  DWORD dwIntent,
  DWORD dwCSAType,
  PBYTE pBuffer,
  PDWORD pcbSize,
  PBOOL pbBinary
);
 
BOOL GetQueuedCompletionStatus(
  HANDLE CompletionPort,       // the I/O completion port of interest
  LPDWORD lpNumberOfBytesTransferred,
                               // to receive number of bytes 
                               // transferred during I/O
  LPDWORD lpCompletionKey,     // to receive file's completion key
  LPOVERLAPPED *lpOverlapped,  // to receive pointer to OVERLAPPED 
                               // structure
  DWORD dwMilliseconds         // optional timeout value
);
 
DWORD GetQueueStatus(
  UINT flags   // queue-status flags
);
 
BOOL GetRasterizerCaps(
  LPRASTERIZER_STATUS lprs,
            // pointer to rasterizer information structure
  UINT cb   // number of bytes in structure
);
 
DWORD GetRegionData(
  HRGN hRgn,            // handle to region
  DWORD dwCount,        // size of buffer containing region data
  LPRGNDATA lpRgnData   // pointer to region data
);
 
int GetRgnBox(
  HRGN hrgn,   // handle to a region
  LPRECT lprc  // pointer that receives bounding rectangle
);
 
int GetROP2(
  HDC hdc   // handle of device context
);
 
BOOL GetSaveFileName(
  LPOPENFILENAME lpofn   // address of structure with initialization 
                         // data
);
 
BOOL GetScrollInfo(
  HWND hwnd,         // handle to window with scroll bar
  int fnBar,         // scroll bar flag
  LPSCROLLINFO lpsi  // pointer to structure for scroll parameters
);
 
int GetScrollPos(
  HWND hWnd, // handle to window with scroll bar
  int nBar   // scroll bar flags
);
 
BOOL GetScrollRange(
  HWND hWnd, // handle to window with scroll bar
  int nBar,  // scroll bar flags
  LPINT lpMinPos,
             // address of variable that receives minimum position
  LPINT lpMaxPos 
             // address of variable that receives maximum position
);
 
BOOL GetSecurityDescriptorControl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                         // address of security descriptor
  PSECURITY_DESCRIPTOR_CONTROL pControl,
                         // address of  control structure
  LPDWORD lpdwRevision   // address of revision value
);
 
BOOL GetSecurityDescriptorDacl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                // address of security descriptor
  LPBOOL lpbDaclPresent,
                // address of flag for presence of disc. ACL
  PACL *pDacl,  // address of pointer to ACL
  LPBOOL lpbDaclDefaulted 
                // address of flag for default disc. ACL
);
 
BOOL GetSecurityDescriptorGroup(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                             // address of security descriptor
  PSID *pGroup,              // address of pointer to group security 
                             // identifier (SID)
  LPBOOL lpbGroupDefaulted   // address of flag for default
);
 
DWORD GetSecurityDescriptorLength(
  PSECURITY_DESCRIPTOR pSecurityDescriptor   // address of security 
                                             // descriptor
);
 
BOOL GetSecurityDescriptorOwner(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                             // address of security descriptor
  PSID *pOwner,              // address of pointer to owner security 
                             // identifier (SID)
  LPBOOL lpbOwnerDefaulted   // address of flag for default
);
 
BOOL GetSecurityDescriptorSacl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                // address of security descriptor
  LPBOOL lpbSaclPresent,
                // address of flag for presence of system ACL
  PACL *pSacl,  // address of pointer to ACL
  LPBOOL lpbSaclDefaulted 
                // address of flag for default system ACL
);
 
DWORD GetSecurityInfo(
  HANDLE handle,     // handle to the object
  SE_OBJECT_TYPE ObjectType,
                     // type of object
  SECURITY_INFORMATION SecurityInfo, 
                     // type of security information to retrieve
  PSID *ppsidOwner,  // receives a pointer to the owner SID
  PSID *ppsidGroup,  // receives a pointer to the primary group SID
  PACL *ppDacl,      // receives a pointer to the DACL
  PACL *ppSacl,      // receives a pointer to the SACL
  PSECURITY_DESCRIPTOR *ppSecurityDescriptor
                     // receives a pointer to the security descriptor
);
 
DWORD GetSecurityInfoEx(
  HANDLE hObject,      // handle to the object
  SE_OBJECT_TYPE ObjectType,
                       // type of object
  SECURITY_INFORMATION SecurityInfo,
                       // type of security information to retrieve
  LPCTSTR lpProvider,  // name of provider to handle request
  LPCTSTR lpProperty,  // identifies a property, property set, or 
                       // child object
  PACTRL_ACCESS *ppAccessList,
                       // receives a pointer to access-control info
  PACTRL_AUDIT *ppAuditList,
                       // receives a pointer to audit-control info
  LPTSTR *lppOwner,    // receives the name of the object's owner
  LPTSTR *lppGroup     // receives the name of the object's primary 
                       // group
);
 
BOOL GetServiceDisplayName(
  SC_HANDLE hSCManager,  // handle to a service control manager 
                         // database
  LPCTSTR lpServiceName, // the service name
  LPTSTR lpDisplayName,  // buffer to receive the service's display 
                         // name
  LPDWORD lpcchBuffer    // size of display name buffer and display 
                         // name
);
 
BOOL GetServiceKeyName(
  SC_HANDLE hSCManager,  // handle to a service control manager 
                         // database
  LPCTSTR lpDisplayName, // the service's display name
  LPTSTR lpServiceName,  // buffer to receive the service name
  LPDWORD lpcchBuffer    // size of service name buffer and service 
                         // name
);
 
DWORD GetShortPathName(
  LPCTSTR lpszLongPath,  // pointer to a null-terminated path string
  LPTSTR lpszShortPath,  // pointer to a buffer to receive the 
                         // null-terminated short form of the path
  DWORD cchBuffer        // specifies the size of the buffer pointed 
                         // to by lpszShortPath
);
 
PSID_IDENTIFIER_AUTHORITY GetSidIdentifierAuthority(
  PSID pSid   // address of SID to query
);
 
DWORD GetSidLengthRequired(
  UCHAR nSubAuthorityCount   // count of subauthorities
);
 
PDWORD GetSidSubAuthority(
  PSID pSid,            // address of security identifier to query
  DWORD nSubAuthority   // index of subauthority to retrieve
);
 
PUCHAR GetSidSubAuthorityCount(
  PSID pSid   // address of security identifier to query
);
 
BOOL WINAPI GetStandardColorSpaceProfile(
  PCTSTR pMachineName,
  DWORD dwProfileID,
  PTSTR pProfileName,
  PDWORD pdwSize
);
 
VOID GetStartupInfo(
  LPSTARTUPINFO lpStartupInfo   // address of STARTUPINFO structure
);
 
HANDLE GetStdHandle(
  DWORD nStdHandle   // input, output, or error device
);
 
HGDIOBJ GetStockObject(
  int fnObject   // type of stock object
);
 
int GetStretchBltMode(
  HDC hdc   // handle to device context
);
 
BOOL GetStringTypeA(
  LCID Locale,       // locale identifer
  DWORD dwInfoType,  // information-type options
  LPCSTR lpSrcStr,   // pointer to the source string
  int cchSrc,        // size, in bytes, of the source string
  LPWORD lpCharType  // pointer to the buffer for output
);
 
BOOL GetStringTypeEx(
  LCID Locale,       // locale identifer
  DWORD dwInfoType,  // information-type options
  LPCTSTR lpSrcStr,  // pointer to source string
  int cchSrc,        // size, in bytes or characters, of source string
  LPWORD lpCharType  // pointer to buffer for output
);
 
BOOL GetStringTypeW(
  DWORD dwInfoType,  // information-type options
  LPCWSTR lpSrcStr,  // pointer to source string
  int cchSrc,        // number of characters in string
  LPWORD lpCharType  // pointer to buffer for output
);
 
HMENU GetSubMenu(
  HMENU hMenu,  // handle to menu
  int nPos      // menu item position
);
 
DWORD GetSysColor(
  int nIndex   // display element
);
 
HBRUSH GetSysColorBrush(
  int nIndex  // system color index
);
 
LANGID GetSystemDefaultLangID(VOID);
 
LCID GetSystemDefaultLCID(VOID);
 
UINT GetSystemDirectory(
  LPTSTR lpBuffer,  // address of buffer for system directory
  UINT uSize        // size of directory buffer
);
 
VOID GetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo   // address of system information 
                               // structure
);
 
HMENU GetSystemMenu(
  HWND hWnd,    // handle to window to own window menu
  BOOL bRevert  // reset flag
);
 
int GetSystemMetrics(
  int nIndex   // system metric or configuration setting to retrieve
);
 
UINT GetSystemPaletteEntries(
  HDC hdc,              // handle of device context
  UINT iStartIndex,     // index of first entry to be retrieved
  UINT nEntries,        // number of entries to be retrieved
  LPPALETTEENTRY lppe   // array receiving system-palette entries
);
 
UINT GetSystemPaletteUse(
  HDC hdc   // handle of device context
);
 
BOOL GetSystemPowerStatus(
  LPSYSTEM_POWER_STATUS lpSystemPowerStatus  
);
 
VOID GetSystemTime(
  LPSYSTEMTIME lpSystemTime   // address of system time structure
);
 
BOOL GetSystemTimeAdjustment(
  PDWORD lpTimeAdjustment,  // size, in 100-nanosecond units, of a 
                            // periodic time adjustment
  PDWORD lpTimeIncrement,   // time, in 100-nanosecond units, between 
                            // periodic time adjustments
  PBOOL lpTimeAdjustmentDisabled
                            // whether periodic time adjustment is 
                            // disabled or enabled
);
 
VOID GetSystemTimeAsFileTime(
  LPFILETIME lpSystemTimeAsFileTime   // pointer to a file time 
                                      // structure
);
 
DWORD GetTabbedTextExtent(
  HDC hDC,                    // handle to device context
  LPCTSTR lpString,           // pointer to character string
  int nCount,                 // number of characters in string
  int nTabPositions,          // number of tab positions
  LPINT lpnTabStopPositions   // pointer to array of tab positions
);
 
DWORD GetTapeParameters(
  HANDLE hDevice,            // handle of open device
  DWORD dwOperation,         // type of information requested
  LPDWORD lpdwSize,          // address of returned information
  LPVOID lpTapeInformation   // tape media or drive information
);
 
DWORD GetTapePosition(
  HANDLE hDevice,          // handle of open device
  DWORD dwPositionType,    // type of address to obtain
  LPDWORD lpdwPartition,   // address of current tape partition
  LPDWORD lpdwOffsetLow,   // address of low-order 32 bits of tape 
                           // position
  LPDWORD lpdwOffsetHigh   // address of high-order 32 bits of tape 
                           // position
);
 
DWORD GetTapeStatus(
  HANDLE hDevice   // handle of open device
);
 
UINT GetTempFileName(
  LPCTSTR lpPathName,  // pointer to directory name for temporary 
                       // file
  LPCTSTR lpPrefixString,  // pointer to filename prefix
  UINT uUnique,        // number used to create temporary filename
  LPTSTR lpTempFileName 
                       // pointer to buffer that receives the new 
                       // filename
);
 
DWORD GetTempPath(
  DWORD nBufferLength,  // size, in characters, of the buffer
  LPTSTR lpBuffer       // pointer to buffer for temp. path
);
 
UINT GetTextAlign(
  HDC hdc   // handle to device context
);
 
int GetTextCharacterExtra(
  HDC hdc   // handle to device context
);
 
UINT GetTextCharsetInfo(
  HDC hdc,  // handle to device context
);
 
UINT GetTextCharsetInfo(
  HDC hdc,                // handle to device context
  LPFONTSIGNATURE lpSig,  // pointer to structure to receive data
  DWORD dwFlags           // reserved; must be zero
);
 
COLORREF GetTextColor(
  HDC hdc   // handle to device context
);
 
BOOL GetTextExtentExPoint(
  HDC hdc,         // handle to device context
  LPCTSTR lpszStr, // pointer to character string
  int cchString,   // number of characters in string
  int nMaxExtent,  // maximum width for formatted string
  LPINT lpnFit,    // pointer to value specifying max. number of 
                   // chars.
  LPINT alpDx,     // pointer to array for partial string widths
  LPSIZE lpSize    // pointer to structure with string dimensions
);
 
BOOL GetTextExtentPoint(
  HDC hdc,           // handle to device context
  LPCTSTR lpString,  // pointer to text string
  int cbString,      // number of characters in string
  LPSIZE lpSize      // pointer to structure for string size
);
 
BOOL GetTextExtentPoint32(
  HDC hdc,           // handle to device context
  LPCTSTR lpString,  // pointer to text string
  int cbString,      // number of characters in string
  LPSIZE lpSize      // pointer to structure for string size
);
 
int GetTextFace(
  HDC hdc,            // handle to device context
  int nCount,         // length of buffer receiving typeface name
  LPTSTR lpFaceName   // pointer to buffer receiving typeface name
);
 
BOOL GetTextMetrics(
  HDC hdc,            // handle to device context
  LPTEXTMETRIC lptm   // pointer to text metrics structure
);
 
BOOL GetThreadContext(
  HANDLE hThread,       // handle to thread with context
  LPCONTEXT lpContext   // address of context structure
);
 
HDESK GetThreadDesktop(
  DWORD dwThreadId   // thread identifier
);
 
LCID GetThreadLocale(VOID);
 
int GetThreadPriority(
  HANDLE hThread   // handle to thread
);
 
BOOL GetThreadPriorityBoost(
  HANDLE hThread,  // handle to thread
  PBOOL pDisablePriorityBoost
                   // indicates priority boost control state
);
 
BOOL GetThreadSelectorEntry(
  HANDLE hThread,    // handle to thread that contains selector
  DWORD dwSelector,  // number of selector value to look up
  LPLDT_ENTRY lpSelectorEntry 
                     // address of selector entry structure
);
 
BOOL GetThreadTimes(
  HANDLE hThread,             // specifies the thread of interest
  LPFILETIME lpCreationTime,  // when the thread was created
  LPFILETIME lpExitTime,      // when the thread was destroyed
  LPFILETIME lpKernelTime,    // time the thread has spent in kernel
                              // mode
  LPFILETIME lpUserTime       // time the thread has spent in user mode
);
 
DWORD GetTickCount(void); 

int GetTimeFormat(
  LCID Locale,       // locale for which time is to be formatted
  DWORD dwFlags,             // flags specifying function options
  CONST SYSTEMTIME *lpTime,  // time to be formatted
  LPCTSTR lpFormat,          // time format string
  LPTSTR lpTimeStr,          // buffer for storing formatted string
  int cchTime                // size, in bytes or characters, of the buffer
);
 
DWORD GetTimestampForLoadedLibrary(
  IN LPVOID ImageBase  
);
 
DWORD GetTimeZoneInformation(
  LPTIME_ZONE_INFORMATION lpTimeZoneInformation   // address of 
                                                  // time-zone settings
);
 
BOOL GetTokenInformation(
  HANDLE TokenHandle,       // handle of access token
  TOKEN_INFORMATION_CLASS TokenInformationClass,
                            // type of information to retrieve
  LPVOID TokenInformation,  // address of retrieved information
  DWORD TokenInformationLength,
                            // size of information buffer
  PDWORD ReturnLength       // address of required buffer size
);
 
HWND GetTopWindow(
  HWND hWnd   // handle to parent window
);
 
TRUSTEE_FORM GetTrusteeForm(
  PTRUSTEE pTrustee  // pointer to a TRUSTEE structure
);
 
LPTSTR GetTrusteeName(
  PTRUSTEE pTrustee  // pointer to a TRUSTEE structure
);
 
TRUSTEE_TYPE GetTrusteeType(
  PTRUSTEE pTrustee  // pointer to the TRUSTEE structure
);
 
BOOL GetUpdateRect(
  HWND hWnd,       // handle of window
  LPRECT lpRect,   // address of update rectangle coordinates
  BOOL bErase      // erase flag
);
 
int GetUpdateRgn(
  HWND hWnd,    // handle of window
  HRGN hRgn,    // handle of region
  BOOL bErase   // erase background flag
);
 
LANGID GetUserDefaultLangID(VOID);

LCID GetUserDefaultLCID(VOID);

BOOL GetUserName(
  LPTSTR lpBuffer,  // address of name buffer
  LPDWORD nSize     // address of size of name buffer
);
 
BOOL GetUserObjectInformation(
  HANDLE hObj,            // handle to object to get information for
  int nIndex,             // type of information to retrieve
  PVOID pvInfo,           // points to buffer that receives the information
  DWORD nLength,          // size of the pvInfo buffer
  LPDWORD lpnLengthNeeded // receives required size of the pvInfo buffer
);
 
BOOL GetUserObjectSecurity(
  HANDLE hObj,    // handle of user object
  PSECURITY_INFORMATION pSIRequested,
                  // address of requested security information
  PSECURITY_DESCRIPTOR pSD,
                  // address of security descriptor
  DWORD nLength,  // size of buffer for security descriptor
  LPDWORD lpnLengthNeeded 
                  // address of required size of buffer
);
 
DWORD GetVersion(VOID);
 
BOOL GetVersionEx(
  LPOSVERSIONINFO lpVersionInformation   // pointer to version 
                                         // information structure
);
 
BOOL GetViewportExtEx(
  HDC hdc,  // handle of device context
  LPSIZE lpSize 
            // address of structure receiving viewport dimensions
);
 
BOOL GetViewportOrgEx(
  HDC hdc,  // handle of device context
  LPPOINT lpPoint 
            // address of structure receiving the viewport origin
);
 
BOOL GetVolumeInformation(
  LPCTSTR lpRootPathName,        // address of root directory of the 
                                 // file system
  LPTSTR lpVolumeNameBuffer,     // address of name of the volume
  DWORD nVolumeNameSize,         // length of lpVolumeNameBuffer
  LPDWORD lpVolumeSerialNumber,  // address of volume serial number
  LPDWORD lpMaximumComponentLength,
                                 // address of system's maximum 
                                 // filename length
  LPDWORD lpFileSystemFlags,     // address of file system flags
  LPTSTR lpFileSystemNameBuffer, // address of name of file system
  DWORD nFileSystemNameSize      // length of lpFileSystemNameBuffer
);
 
HWND GetWindow(
  HWND hWnd,  // handle to original window
  UINT uCmd   // relationship flag
);
 
HDC GetWindowDC(
  HWND hWnd   // handle of window
);
 
BOOL GetWindowExtEx(
  HDC hdc,        // handle of device context
  LPSIZE lpSize   // address of structure receiving window extents
);
 
LONG GetWindowLong(
  HWND hWnd,  // handle of window
  int nIndex  // offset of value to retrieve
);
 
BOOL GetWindowOrgEx(
  HDC hdc,  // handle of device context
  LPPOINT lpPoint 
            // address of structure receiving the window origin
);
 
BOOL GetWindowPlacement(
  HWND hWnd,               // handle to window
  WINDOWPLACEMENT *lpwndpl // address of structure for position data
);
 
BOOL GetWindowRect(
  HWND hWnd,      // handle to window
  LPRECT lpRect   // address of structure for window coordinates
);
 
int GetWindowRgn(
  HWND hWnd, // handle to window whose window region is to be 
             // obtained
  HRGN hRgn  // handle to region that receives a copy of the window 
             // region
);
 
UINT GetWindowsDirectory(
  LPTSTR lpBuffer,  // address of buffer for Windows directory
  UINT uSize        // size of directory buffer
);
 
int GetWindowText(
  HWND hWnd,        // handle to window or control with text
  LPTSTR lpString,  // address of buffer for text
  int nMaxCount     // maximum number of characters to copy
);
 
int GetWindowTextLength(
  HWND hWnd   // handle to window or control with text
);
 
DWORD GetWindowThreadProcessId(
  HWND hWnd,             // handle to window
  LPDWORD lpdwProcessId  // address of variable for process identifier
);
 
UINT GetWinMetaFileBits(
  HENHMETAFILE hemf, // handle to the enhanced metafile
  UINT cbBuffer,     // buffer size
  LPBYTE lpbBuffer,  // pointer to buffer
  INT fnMapMode,     // mapping mode
  HDC hdcRef         // handle to reference device context
);
 
BOOL GetWorldTransform(
  HDC hdc,  // handle to the device context
  LPXFORM lpXform 
            // pointer to the structure receiving transformation
);
 
ATOM GlobalAddAtom(
  LPCTSTR lpString   // pointer to the string to add
);
 
HGLOBAL GlobalAlloc(
  UINT uFlags,    // allocation attributes
  DWORD dwBytes   // number of bytes to allocate
);
 
ATOM GlobalDeleteAtom(
  ATOM nAtom   // atom to delete
);
 
HGLOBAL GlobalDiscard(
  HGLOBAL hglbMem  // handle to the global memory object
);
 
ATOM GlobalFindAtom(
  LPCTSTR lpString   // pointer to the string to find
);
 
UINT GlobalFlags(
  HGLOBAL hMem   // handle to the global memory object
);
 
HGLOBAL GlobalFree(
  HGLOBAL hMem   // handle to the global memory object
);
 
UINT GlobalGetAtomName(
  ATOM nAtom,       // atom identifier
  LPTSTR lpBuffer,  // pointer to the buffer for the atom string
  int nSize         // size of the buffer
);
 
HGLOBAL GlobalHandle(
  LPCVOID pMem   // pointer to the global memory block
);
 
LPVOID GlobalLock(
  HGLOBAL hMem   // handle to the global memory object
);
 
VOID GlobalMemoryStatus(
  LPMEMORYSTATUS lpBuffer   // pointer to the memory status structure
);
 
VOID GlobalMemoryStatusVlm(
  LPMEMORYSTATUSVLM lpBuffer   // pointer to a memory status structure
);
 
HGLOBAL GlobalReAlloc(
  HGLOBAL hMem,  // handle to the global memory object
  DWORD dwBytes, // new size of the block
  UINT uFlags    // how to reallocate object
);
 
DWORD GlobalSize(
  HGLOBAL hMem   // handle to the global memory object
);
 
BOOL GlobalUnlock(
  HGLOBAL hMem   // handle to the global memory object
);
 
BOOL GradientFill(
  HDC hdc,
  CONST PTRIVERTEX pVertex,
  DWORD dwNumVertex,
  CONST PVOID pMesh,
  DWORD dwNumMesh,
  DWORD dwMode
); 
 
BOOL GrayString(
  HDC hDC,        // handle to the device context
  HBRUSH hBrush,  // handle to the brush for graying
  GRAYSTRINGPROC lpOutputFunc,
                  // pointer to the callback function
  LPARAM lpData,  // pointer to application-defined data
  int nCount,     // number of characters to output
  int X,          // horizontal position
  int Y,          // vertical position
  int nWidth,     // width
  int nHeight     // height
);
 
VOID WINAPI Handler(
  DWORD fdwControl   // requested control code
);
 
BOOL WINAPI HandlerRoutine(
  DWORD dwCtrlType   //  control signal type
);
 
BOOL WINAPI Heap32First(
  LPHEAPENTRY32 lphe,  
  DWORD th32ProcessID, 
  DWORD th32HeapID     
);

BOOL WINAPI Heap32ListFirst(
  HANDLE hSnapshot,  
  LPHEAPLIST32 lphl  
);

BOOL WINAPI Heap32ListNext(
  HANDLE hSnapshot,  
  LPHEAPLIST32 lphl  
);

BOOL WINAPI Heap32Next(
  LPHEAPENTRY32 lphe  
);
 
LPVOID HeapAlloc(
  HANDLE hHeap,  // handle to the private heap block
  DWORD dwFlags, // heap allocation control flags
  DWORD dwBytes  // number of bytes to allocate
);
 
UINT HeapCompact(
  HANDLE hHeap,  // handle to the heap to compact
  DWORD dwFlags  // bit-flags that control heap access during 
                 // function operation
);
 
HANDLE HeapCreate(
  DWORD flOptions,      // heap allocation flag
  DWORD dwInitialSize,  // initial heap size
  DWORD dwMaximumSize   // maximum heap size
);
 
BOOL HeapDestroy(
  HANDLE hHeap   // handle to the heap
);
 
BOOL HeapFree(
  HANDLE hHeap,  // handle to the heap
  DWORD dwFlags, // heap freeing flags
  LPVOID lpMem   // pointer to the memory to free
);
 
BOOL HeapLock(
  HANDLE hHeap   // handle to the heap to lock for exclusive thread 
                 // access
);
 
LPVOID HeapReAlloc(
  HANDLE hHeap,  // handle to a heap block
  DWORD dwFlags, // heap reallocation flags
  LPVOID lpMem,  // pointer to the memory to reallocate
  DWORD dwBytes  // number of bytes to reallocate
);
 
DWORD HeapSize(
  HANDLE hHeap,  // handle to the heap
  DWORD dwFlags, // heap size control flags
  LPCVOID lpMem  // pointer to memory to return size for
);
 
BOOL HeapUnlock(
  HANDLE hHeap   // handle to the heap to unlock
);
 
BOOL HeapValidate(
  HANDLE hHeap,  // handle to the heap of interest
  DWORD dwFlags, // bit flags that control heap access during 
                 // function operation
  LPCVOID lpMem  // optional pointer to individual memory block to 
                 // validate
);
 
BOOL HeapWalk(
  HANDLE hHeap,  // handle to the heap to enumerate
  LPPROCESS_HEAP_ENTRY lpEntry 
                 // points to structure that maintains enumeration 
                 // state information
);
 
BOOL HideCaret(
  HWND hWnd   // handle to the window with the caret
);
 
BOOL HiliteMenuItem(
  HWND hwnd,         // handle to the window with the menu
  HMENU hmenu,       // handle to the menu
  UINT uItemHilite,  // menu item to highlight or unhighlight
  UINT uHilite       // highlight flags
);
 
BOOL WINAPI ICMProgressProcCallback(
  ULONG ulMax,
  ULONG ulCurrent,
  ULONG ulCallbackData
);
 
BOOL ImageAddCertificate(
  IN HANDLE FileHandle,              
  IN PDICE_CERTIFICATE Certificate,  
  OUT PDWORD Index                   
);
 
PVOID ImageDirectoryEntryToData(
  IN LPVOID Base,            
  IN BOOLEAN MappedAsImage,  
  IN USHORT DirectoryEntry,  
  OUT PULONG Size            
);
 
BOOL ImageEnumerateCertificates(
  IN HANDLE FileHandle,         
  IN DWORD TypeFilter,          
  OUT PDWORD CertificateCount,  
  IN OUT PDWORD Indices OPTIONAL,  
  IN OUT DWORD IndexCount OPTIONAL  
);
 
BOOL ImageGetCertificateData(
  IN HANDLE FileHandle,               
  IN DWORD CertificateIndex,          
  OUT PDICE_CERTIFICATE Certificate,  
  IN OUT PDWORD RequiredLength        
);
 
BOOL ImageGetCertificateHeader(
  IN HANDLE FileHandle,                    
  IN DWORD CertificateIndex,               
  OUT PDICE_CERTIFICATE CertificateHeader  
);
 
BOOL ImageGetDigestStream(
  IN HANDLE FileHandle,        
  IN DWORD DigestLevel,        
  IN PVOID Buffer,             
  IN OUT PDWORD BufferLength,  
  IN OUT PDWORD Context        
);
 
LPAPI_VERSION ImagehlpApiVersion(VOID);

LPAPI_VERSION ImagehlpApiVersionEx(
  IN OUT LPAPI_VERSION AppVersion  
);
 
PLOADED_IMAGE ImageLoad(
  IN LPSTR DllName, 
  IN LPSTR DllPath  
);
 
PIMAGE_NT_HEADERS ImageNtHeader(
  IN LPVOID ImageBase  
);
 
BOOL ImageRemoveCertificate(
  IN HANDLE FileHandle,  
  IN DWORD Index         
);
 
PIMAGE_SECTION_HEADER ImageRvaToSection(
  IN PIMAGE_NT_HEADERS NtHeaders,  
  IN LPVOID Base,                  
  IN DWORD Rva                     
);
 
LPVOID ImageRvaToVa(
  IN PIMAGE_NT_HEADERS NtHeaders,               
  IN LPVOID Base,                               
  IN DWORD Rva,                                 
  IN OUT PIMAGE_SECTION_HEADER *LastRvaSection  
);
 
BOOL ImageUnload(
  IN PLOADED_IMAGE LoadedImage  
);
 
HIMC ImmAssociateContext(
  HWND hWnd,   
  HIMC hIMC    
);
 
BOOL ImmAssociateContextEx(
  HWND hWnd,    // handle to window 
  HINC hIMC,    // handle to input method context
  DWORD dwFlags // flag
);
 
BOOL ImmConfigureIME(
  HKL hKL,       
  HWND hWnd,     
  DWORD dwMode,  
  LPVOID lpdata  
);
 
HIMC ImmCreateContext(void);

BOOL ImmDestroyContext(
  HIMC hIMC  
);
 
BOOL ImmDisableIME(
  DWORD idThread   // thread to disable IME
);
 
UINT ImmEnumRegisterWord(
  HKL hKL,                             
  REGISTERWORDENUMPROC lpfnEnumProc,   
  LPCTSTR lpszReading,                 
  DWORD dwStyle,                       
  LPCTSTR lpszRegister,                
  LPVOID lpData                        
);
 
LRESULT ImmEscape(
  HKL hKL,       
  HIMC hIMC,     
  UINT uEscape,  
  LPVOID lpData  
);
 
DWORD ImmGetCandidateList(
  HIMC hIMC,                    
  DWORD deIndex,                
  LPCANDIDATELIST lpCandList,   
  DWORD dwBufLen                
);
 
DWORD ImeGetCandidateListCount(
  HIMC hIMC,             
  LPDWORD lpdwListCount  
);
 
BOOL ImmGetCandidateWindow(
  HIMC hIMC,                   
  DWORD dwBufLen,              
  LPCANDIDATEFORM lpCandidate  
);
 
BOOL ImmGetCompositionFont(
  HIMC hIMC,      
  LPLOGFONT lplf  
);
 
LONG ImmGetCompositionString(
  HIMC hIMC,      
  DWORD dwIndex,  
  LPVOID lpBuf,   
  DWORD dwBufLen  
);
 
BOOL ImmGetCompositionWindow(
  HIMC hIMC,                    
  LPCOMPOSITIONFORM lpCompForm  
);
 
HIMC ImmGetContext(
  HWND hWnd  
);
 
UINT ImmGetConversionList(
  HKL hKL,                 
  HIMC hIMC,               
  LPCTSTR lpSrc,           
  LPCANDIDATELIST lpDst,   
  DWORD dwBufLen,          
  UINT uFlag               
);
 
BOOL ImmGetConversionStatus(
  HIMC hIMC,             
  LPDWORD lpfdwConversion,   
  LPDWORD lpfdwSentence  
);
 
HWND ImmGetDefaultIMEWnd(
  HWND hWnd  
);
 
UINT ImmGetDescription(
  HKL hKL,                  
  LPTSTR lpszDescription,   
  UINT uBufLen              
);
 
DWORD ImmGetGuideLine(
  HIMC hIMC,      
  DWORD dwIndex,  
  LPTSTR lpBuf,   
  DWORD dwBufLen  
);
 
BOOL ImmGetIMEFileName(
  HKL hKL,               
  LPTSTR lpszFileName,   
  UINT uBufLen           
);
 
DWORD WINAPI ImmGetImeMenuItems(
   HIMC                hIMC,
   DWORD               dwFlags,
   DWORD               dwType,
   LPIMEMENUITEMINFO   lpImeParentMenu,
   LPIMEMENUITEMINFO   lpImeMenu,
   DWORD               dwSize
);
 
BOOL WINAPI ImmGetOpenStatus(
  HIMC hIMC  
);
 
BOOL ImmGetProperty(
  HKL hKL,        
  DWORD fdwIndex  
);
 
UINT ImmGetRegisterWordStyle(
  HKL hKL,               
  UINT nItem,            
  LPSTYLEBUF lpStyleBuf  
);
 
BOOL ImmGetStatusWindowPos(
  HIMC hIMC,       
  LPPOINT lpptPos  
);
 
UINT ImmGetVirtualKey(
  HWND hWnd  
);
 
HKL ImmInstallIME(
  LPCTSTR lpszIMEFileName,   
  LPCTSTR lpszLayoutText  
);
 
BOOL ImmIsIME(
  HKL hKL  
);
 
BOOL ImmIsUIMessage(
  HWND hWndIME,   
  UINT msg,       
  WPARAM wParam,  
  LPARAM lParam   
);
 
BOOL ImmNotifyIME(
  HIMC hIMC,       
  DWORD dwAction,  
  DWORD dwIndex,   
  DWORD dwValue    
);
 
BOOL ImmRegisterWord(
  HKL hKL,              
  LPCTSR lpszReading,   
  DWORD dwStyle,        
  LPCTSTR lpszRegister  
);
 
BOOL ImmReleaseContext(
  HWND hWnd,   
  HIMC hIMC    
);
 
BOOL ImmSetCandidateWindow(
  HIMC hIMC,                   
  LPCANDIDATEFORM lpCandidate  
);
 
BOOL ImmSetCompositionFont(
  HIMC hIMC,      
  LPLOGFONT lplf  
);
 
BOOL ImmSetCompositionString(
  HIMC hIMC,        
  DWORD dwIndex,    
  LPCVOID lpComp,   
  DWORD dwCompLen,  
  LPCVOID lpRead,   
  DWORD dwReadLen   
);
 
BOOL ImmSetCompositionWindow(
  HIMC hIMC,                    
  LPCOMPOSITIONFORM lpCompForm  
);
 
BOOL ImmSetConversionStatus(
  HIMC hIMC,             
  DWORD fdwConversion,   
  DWORD fdwSentence      
);
 
BOOL ImmSetOpenStatus(
  HIMC hIMC,  
  BOOL fOpen  
);
 
BOOL ImmSetStatusWindowPos(
  HIMC hIMC,       
  LPPOINT lpptPos  
);
 
BOOL ImmSimulateHotKey(
  HWND hWnd,        
  DWORD dwHotKeyID  
);
 
BOOL ImmUnregisterWord(
  HKL hKL,               
  LPCTSTR lpszReading,   
  DWORD dwStyle,         
  LPCTSTR lpszUnregister 
);
 
BOOL ImpersonateDdeClientWindow(
  HWND hWndClient,  // handle of DDE client window
  HWND hWndServer   // handle of DDE server window
);
 
BOOL ImpersonateLoggedOnUser(
  HANDLE hToken  // handle to a token that represents a logged-on 
                 // user
);
 
BOOL ImpersonateNamedPipeClient(
  HANDLE hNamedPipe   // handle of a named pipe
);
 
BOOL ImpersonateSelf(
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel  // impersonation 
                                                   // level
);
 
DWORD ImportCallback(
  PBYTE pbData,
  PVOID pvCallbackContext,
  ULONG ulLength
);
 
BOOL InflateRect(
  LPRECT lprc,  // pointer to rectangle
  int dx,       // amount to increase or decrease width
  int dy        // amount to increase or decrease height
);
 
BOOL InitAtomTable(
  DWORD nSize   // size of atom table
);
 
BOOL InitializeAcl(
  PACL pAcl,            // address of access-control list
  DWORD nAclLength,     // size of access-control list
  DWORD dwAclRevision   // revision level of access-control list
);
 
VOID InitializeCriticalSection(
  LPCRITICAL_SECTION lpCriticalSection   // address of critical 
                                         // section object
);
 
BOOL InitializeCriticalSectionAndSpinCount(
  LPCRITICAL_SECTION lpCriticalSection,
                      // pointer to critical section
  DWORD dwSpinCount   // spin count for critical section
);
 
BOOL InitializeSecurityDescriptor(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                     // address of security descriptor
  DWORD dwRevision   // revision level
);
 
BOOL InitializeSid(
  PSID Sid,                 // address of SID to initialize
  PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
                            // address of identifier authority
  BYTE nSubAuthorityCount   // count of subauthorities
);
 
BOOL InitiateSystemShutdown(
  LPTSTR lpMachineName,   // pointer to name of computer to shut down
  LPTSTR lpMessage,          // pointer to message to display in 
                             // dialog box
  DWORD dwTimeout,           // time to display dialog box
  BOOL bForceAppsClosed,     // force applications closed flag
  BOOL bRebootAfterShutdown  // reboot flag
);
 
BOOL InSendMessage(VOID);
 
DWORD InSendMessageEx(
  LPVOID lpReserved      // must be NULL
);
 
BOOL InsertMenu(
  HMENU hMenu,      // handle to menu
  UINT uPosition,   // menu item that new menu item precedes
  UINT uFlags,      // menu item flags
  UINT uIDNewItem,  // menu item identifier or handle to drop-down 
                    // menu or submenu
  LPCTSTR lpNewItem // menu item content
);
 
BOOL WINAPI InsertMenuItem(
  HMENU hMenu,          
  UINT uItem,           
  BOOL fByPosition,     
  LPMENUITEMINFO lpmii  
);
 
BOOL WINAPI InstallColorProfile(
  PCTSTR pMachineName,
  PCTSTR pProfileName
);
 
LONGLONG Int32x32To64(
  LONG Multiplier,    // the first signed 32-bit integer
  LONG Multiplicand   // the second signed 32-bit integer
);
 
ULONGLONG Int64ShllMod32(
  ULONGLONG Value,  // the unsigned 64-bit integer to shift left logically
  DWORD ShiftCount  // a shift count in the range 0 - 31
);
 
LONGLONG Int64ShraMod32(
  LONGLONG Value,    // signed 64-bit integer to shift right arithmetically
  DWORD ShiftCount   // a shift count in the range 0 – 31
);
 
ULONGLONG Int64ShrlMod32(
  ULONGLONG Value,  // unsigned 64-bit integer to shift right logically
  DWORD ShiftCount  // a shift count in the range 0 – 31
);
 
PVOID InterlockedCompareExchange( 
  PVOID *Destination,  // pointer to the destination pointer
  PVOID Exchange,      // the exchange value
  PVOID Comperand      // the value to compare
);
 
LONG InterlockedDecrement(
  LPLONG lpAddend   // address of the variable to decrement
);
 
LONG InterlockedExchange(
  LPLONG Target,
               // pointer to the 32-bit value to exchange
  LONG Value   // new value for the LONG value pointed to by Target
);
 
LONG InterlockedExchangeAdd (
  PLONG Addend,  // pointer to the addend
  LONG Increment // increment value
);
 
LONG InterlockedIncrement(
  LPLONG lpAddend   // pointer to the variable to increment
);
 
int IntersectClipRect(
  HDC hdc,       // handle of device context
  int nLeftRect, // x-coordinate of upper-left corner of rectangle
  int nTopRect,  // y-coordinate of upper-left corner of rectangle
  int nRightRect,
                 // x-coordinate of lower-right corner of rectangle
  int nBottomRect 
                 // y-coordinate of lower-right corner of rectangle
);
 
BOOL IntersectRect(
  LPRECT lprcDst,        // pointer to structure for intersection
  CONST RECT *lprcSrc1,  // pointer to structure with first rectangle
  CONST RECT *lprcSrc2   // pointer to structure with second rectangle
);
 
BOOL InvalidateRect(
  HWND hWnd,  // handle of window with changed update region
  CONST RECT *lpRect,
              // address of rectangle coordinates
  BOOL bErase // erase-background flag
);
 
BOOL InvalidateRgn(
  HWND hWnd,    // handle of window with changed update region
  HRGN hRgn,    // handle of region to add
  BOOL bErase   // erase-background flag
);
 
BOOL InvertRect(
  HDC hDC,           // handle to device context
  CONST RECT *lprc   // pointer to structure with rectangle
);
 
BOOL InvertRgn(
  HDC hdc,    // handle to device context
  HRGN hrgn   // handle to region to be inverted
);
 
BOOL IsBadCodePtr(
  FARPROC lpfn   // address of function
);
 
BOOL IsBadReadPtr(
  CONST VOID *lp,  // address of memory block
  UINT ucb         // size of block
);
 
BOOL IsBadStringPtr(
  LPCTSTR lpsz,  // address of string
  UINT ucchMax   // maximum size of string
);
 
BOOL IsBadWritePtr(
  LPVOID lp, // address of memory block
  UINT ucb   // size of block
);
 
BOOL IsCharAlpha(
  TCHAR ch   // character to test
);
 
BOOL IsCharAlphaNumeric(
  TCHAR ch   // character to test
);
 
BOOL IsCharLower(
  TCHAR ch   // character to test
);
 
BOOL IsCharUpper(
  TCHAR ch   // character to test
);
 
BOOL IsChild(
  HWND hWndParent,  // handle to parent window
  HWND hWnd         // handle to window to test
);
 
BOOL IsClipboardFormatAvailable(
  UINT format   // clipboard format
);
 
BOOL WINAPI IsColorProfileTagPresent(
  HPROFILE hProfile,
  TAGTYPE tag,
  PBOOL pbPresent
);
 
BOOL WINAPI IsColorProfileValid(
  HPROFILE hProfile,
  PBOOL pbValid
);
 
BOOL IsDBCSLeadByte(
  BYTE TestChar   // character to test
);
 
BOOL IsDBCSLeadByteEx(
  UINT CodePage,   // identifier of code page
  BYTE TestChar    // character to test
);
 
BOOL IsDebuggerPresent(VOID);
 
BOOL IsDialogMessage(
  HWND hDlg,  // handle of dialog box
  LPMSG lpMsg // address of structure with message
);
 
UINT IsDlgButtonChecked(
  HWND hDlg,     // handle to dialog box
  int nIDButton  // button identifier
);
 
BOOL IsIconic(
  HWND hWnd   // handle to window
);
 
BOOL IsMenu(
  HMENU hMenu  // handle to test
);
 
BOOL IsProcessorFeaturePresent(
  DWORD ProcessorFeature  // specifies the processor feature
); 
 
BOOL IsRectEmpty(
  CONST RECT *lprc   // pointer to structure with rectangle
);
 
BOOL IsSystemResumeAutomatic(VOID);
 
DWORD IsTextUnicode(
  CONST LPVOID lpBuffer, // pointer to an input buffer to be examined
  int cb,                // the size of the input buffer
  LPINT lpi              // flags that condition examination and receive results
);
 
BOOL IsTokenRestricted(
  HANDLE TokenHandle         // handle to an access token to test
);
 
BOOL IsValidAcl(
  PACL pAcl   // address of access-control list
);
 
BOOL IsValidCodePage(
  UINT CodePage   // specifies the code page to check
);
 
BOOL IsValidLocale(
  LCID Locale,    // locale identifier to validate
  DWORD dwFlags   // specifies validity test
);
 
BOOL IsValidSecurityDescriptor(
  PSECURITY_DESCRIPTOR pSecurityDescriptor   // address of security 
                                             // descriptor
);
 
BOOL IsValidSid(
  PSID pSid   // address of SID to query
);
 
BOOL IsWindow(
  HWND hWnd   // handle to window
);
 
BOOL IsWindowEnabled(
  HWND hWnd   // handle to window to test
);
 
BOOL IsWindowUnicode(
  HWND hWnd   // handle to window
);
 
BOOL IsWindowVisible(
  HWND hWnd   // handle to window
);
 
BOOL IsZoomed(
  HWND hWnd   // handle to window
);
 
LRESULT CALLBACK JournalPlaybackProc(
  int code,       // hook code
  WPARAM wParam,  // undefined
  LPARAM lParam   // address of message being processed
);
 
LRESULT CALLBACK JournalRecordProc(
  int code,       // hook code
  WPARAM wParam,  // undefined
  LPARAM lParam   // address of message being processed
);
 
VOID keybd_event(
  BYTE bVk,           // virtual-key code
  BYTE bScan,         // hardware scan code
  DWORD dwFlags,      // flags specifying various function options
  DWORD dwExtraInfo   // additional data associated with keystroke
);
 
LRESULT CALLBACK KeyboardProc(
  int code,       // hook code
  WPARAM wParam,  // virtual-key code
  LPARAM lParam   // keystroke-message information
);
 
BOOL KillTimer(
  HWND hWnd,      // handle of window that installed timer
  UINT uIDEvent   // timer identifier
);
 
int LCMapString(
  LCID Locale,       // locale identifier
  DWORD dwMapFlags,  // mapping transformation type
  LPCTSTR lpSrcStr,  // address of source string
  int cchSrc,        // number of characters in source string
  LPTSTR lpDestStr,  // address of destination buffer
  int cchDest        // size of destination buffer
);
 
VOID LeaveCriticalSection(
  LPCRITICAL_SECTION lpCriticalSection   // address of critical 
                                         // section object
);
 
BOOL LineDDA(
  int nXStart,             // x-coordinate of line's starting point
  int nYStart,             // y-coordinate of line's starting point
  int nXEnd,               // x-coordinate of line's ending point
  int nYEnd,               // y-coordinate of line's ending point
  LINEDDAPROC lpLineFunc,  // pointer to callback function
  LPARAM lpData            // pointer to application-defined data
);
 
VOID CALLBACK LineDDAProc(
  int X,          // x-coordinate of point being evaluated
  int Y,          // y-coordinate of point being evaluated
  LPARAM lpData   // pointer to application-defined data
);
 
BOOL LineTo(
  HDC hdc,    // device context handle
  int nXEnd,  // x-coordinate of line's ending point
  int nYEnd   // y-coordinate of line's ending point
);
 
HACCEL LoadAccelerators(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpTableName   // address of table-name string
);
 
HBITMAP LoadBitmap(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpBitmapName  // address of bitmap resource name
);
 
HCURSOR LoadCursor(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpCursorName  // name string or cursor resource identifier
);
 
HCURSOR LoadCursorFromFile(
  LPCTSTR lpFileName  // pointer to name of cursor file, or system 
                      // cursor identifier
);
 
HICON LoadIcon(
  HINSTANCE hInstance, // handle to application instance
  LPCTSTR lpIconName   // icon-name string or icon resource 
                       // identifier
);
 
HANDLE LoadImage(
  HINSTANCE hinst,   // handle of the instance containing the image
  LPCTSTR lpszName,  // name or identifier of image
  UINT uType,        // type of image
  int cxDesired,     // desired width
  int cyDesired,     // desired height
  UINT fuLoad        // load flags
);
 
HKL LoadKeyboardLayout(
  LPCTSTR pwszKLID,  // name of layout to load
  UINT Flags         // keyboard layout flags
);
 
HINSTANCE LoadLibrary(
  LPCTSTR lpLibFileName   // address of filename of executable module
);
 
HINSTANCE LoadLibraryEx(
  LPCTSTR lpLibFileName,  // points to name of executable module
  HANDLE hFile,           // reserved, must be NULL
  DWORD dwFlags           // entry-point execution flag
);
 
HMENU LoadMenu(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpMenuName    // menu name string or menu-resource 
                        // identifier
);
 
HMENU LoadMenuIndirect(
  CONST MENUTEMPLATE *lpMenuTemplate  // address of menu template
);
 
DWORD LoadModule(
  LPCSTR lpModuleName,  // address of filename to load
  LPVOID lpParameterBlock   // address of parameter block for new 
                            // module
);
 
HGLOBAL LoadResource(
  HMODULE hModule, // resource-module handle
  HRSRC hResInfo   // resource handle
);
 
int LoadString(
  HINSTANCE hInstance,  // handle to module containing string resource
  UINT uID,             // resource identifier
  LPTSTR lpBuffer,      // pointer to buffer for resource
  int nBufferMax        // size of buffer
);
 
HLOCAL LocalAlloc(
  UINT uFlags,  // allocation attributes
  UINT uBytes   // number of bytes to allocate
);
 
HLOCAL LocalDiscard(
  HLOCAL hlocMem   // handle to local memory object
);
 
BOOL LocalFileTimeToFileTime(
  CONST FILETIME *lpLocalFileTime,
                          // address of local file time to convert
  LPFILETIME lpFileTime   // address of converted file time
);
 
UINT LocalFlags(
  HLOCAL hMem   // handle to local memory object
);
 
HLOCAL LocalFree(
  HLOCAL hMem   // handle to local memory object
);
 
HLOCAL LocalHandle(
  LPCVOID pMem   // pointer to the local memory object
);
 
LPVOID LocalLock(
  HLOCAL hMem   // handle to the local memory object
);
 
HLOCAL LocalReAlloc(
  HLOCAL hMem,  // handle to the local memory object
  UINT uBytes,  // new size of block
  UINT uFlags   // how to reallocate object
);
 
UINT LocalSize(
  HLOCAL  hMem   // handle to the local memory object
);
 
BOOL LocalUnlock(
  HLOCAL hMem   // handle to the local memory object
);
 
BOOL LockFile(
  HANDLE hFile,           // handle of file to lock
  DWORD dwFileOffsetLow,  // low-order word of lock region offset
  DWORD dwFileOffsetHigh,  // high-order word of lock region offset
  DWORD nNumberOfBytesToLockLow,
                          // low-order word of length to lock
  DWORD nNumberOfBytesToLockHigh 
                          // high-order word of length to lock
);
 
BOOL LockFileEx(
  HANDLE hFile,      // handle of file to lock
  DWORD dwFlags,     // functional behavior modification flags
  DWORD dwReserved,  // reserved, must be set to zero
  DWORD nNumberOfBytesToLockLow,
                     // low-order 32 bits of length to lock
  DWORD nNumberOfBytesToLockHigh,
                     // high-order 32 bits of length to lock
  LPOVERLAPPED lpOverlapped 
                     // addr. of structure with lock region start 
                     // offset
);
 
LPVOID LockResource(
  HGLOBAL hResData   // handle to resource to lock
);
 
SC_LOCK LockServiceDatabase(
  SC_HANDLE hSCManager   // handle of service control manager 
                         // database
);
 
BOOL LockWindowUpdate(
  HWND hWndLock   // handle of window to lock
);
 
BOOL LockWorkStation(VOID);
 
BOOL LogonUser(
  LPTSTR lpszUsername,    // string that specifies the user name
  LPTSTR lpszDomain,      // string that specifies the domain or 
                          // server
  LPTSTR lpszPassword,    // string that specifies the password
  DWORD dwLogonType,      // specifies the type of logon operation
  DWORD dwLogonProvider,  // specifies the logon provider
  PHANDLE phToken         // pointer to variable to receive token 
                          // handle
);
 
BOOL LookupAccountName(
  LPCTSTR lpSystemName,  // address of string for system name
  LPCTSTR lpAccountName, // address of string for account name
  PSID Sid,              // address of security identifier
  LPDWORD cbSid,         // address of size of security identifier
  LPTSTR ReferencedDomainName,
                         // address of string for referenced domain
  LPDWORD cbReferencedDomainName,
                         // address of size of domain string
  PSID_NAME_USE peUse    // address of SID-type indicator
);
 
BOOL LookupAccountSid(
  LPCTSTR lpSystemName, // address of string for system name
  PSID Sid,             // address of security identifier
  LPTSTR Name,          // address of string for account name
  LPDWORD cbName,       // address of size account string
  LPTSTR ReferencedDomainName,
                        // address of string for referenced domain
  LPDWORD cbReferencedDomainName,
                        // address of size domain string
  PSID_NAME_USE peUse   // address of structure for SID type
);
 
int LookupIconIdFromDirectory(
  PBYTE presbits,  // address of resource data
  BOOL fIcon       // look for icon or cursor
);
 
int LookupIconIdFromDirectoryEx(
  PBYTE presbits, // address of resource data
  BOOL fIcon,     // icon or cursor flag
  int cxDesired,  // desired width of icon or cursor
  int cyDesired,  // desired height of icon or cursor
  UINT Flags      // resource flags
);
 
BOOL LookupPrivilegeDisplayName(
  LPCTSTR lpSystemName,  // pointer to string specifying the system
  LPCTSTR lpName,        // pointer to string specifying the 
                         // privilege
  LPTSTR lpDisplayName,  // pointer to string receiving the 
                         // displayable name
  LPDWORD cbDisplayName, // pointer to size of string for 
                         // displayable name
  LPDWORD lpLanguageId   // pointer to language identifier
);
 
BOOL LookupPrivilegeName(
  LPCTSTR lpSystemName,
                  // address of string specifying the system
  PLUID lpLuid,   // address of locally unique identifier
  LPTSTR lpName,  // address of string specifying the privilege
  LPDWORD cbName  // address of size of string for displayable name
);
 
BOOL LookupPrivilegeValue(
  LPCTSTR lpSystemName,
                   // address of string specifying the system
  LPCTSTR lpName,  // address of string specifying the privilege
  PLUID lpLuid     // address of locally unique identifier
);
 
DWORD LookupSecurityDescriptorParts(
  PTRUSTEE *pOwner,  // receives the owner SID from the security 
                     // descriptor
  PTRUSTEE *pGroup,  // receives the group SID from the security 
                     // descriptor
  PULONG cCountOfAccessEntries,
                     // receives number of access-control entries
  PEXPLICIT_ACCESS *pListOfAccessEntries,
                     // receives an array of DACL access-control 
                     // entries
  PULONG cCountOfAuditEntries,
                     // receives number of audit-control entries
  PEXPLICIT_ACCESS *pListOfAuditEntries,
                     // receives an array of SACL audit-control 
                     // entries
  PSECURITY_DESCRIPTOR pSD
                     // pointer to the security descriptor
);
 
LRESULT CALLBACK LowLevelKeyboardProc(
  int nCode,     // hook code
  WPARAM wParam, // message identifier
  LPARAM lParam  // pointer to structure with message data
);
 
LRESULT CALLBACK LowLevelMouseProc(
  int nCode,     // hook code
  WPARAM wParam, // message identifier
  LPARAM lParam  // pointer to structure with message data
);
 
BOOL LPtoDP(
  HDC hdc,           // handle of device context
  LPPOINT lpPoints,  // array of points
  int nCount         // count of points
);
 
LS_STATUS_CODE LS_API_ENTRY LSEnumProviders(
  LS_ULONG Index, // index of the service provider
  LS_STR *Buffer  // pointer to string identifying the service 
                  // provider
);
 
LS_VOID LS_API_ENTRY LSFreeHandle(
  LS_HANDLE  LicenseHandle  // handle to the license context
);
 
LS_STATUS_CODE LS_API_ENTRY LSGetMessage(
  LS_HANDLE LicenseHandle,  // handle to the license context
  LS_STATUS_CODE Value,  // any status code returned by a license 
                         // service function
  LS_STR *Buffer,        // pointer to buffer returning error 
                         // message string
  LS_ULONG BufferSize    // maximum size of buffer string
);
 
LS_STATUS_CODE LS_API_ENTRY LSQuery(
  LS_HANDLE LicenseHandle,  // handle to the license context
  LS_ULONG Information,     // index that identifies the license 
                            // information
  LS_VOID *InfoBuffer,      // pointer to buffer for returning 
                            // license information
  LS_ULONG BufferSize,      // maximum size of buffer
  LS_ULONG *ActualBufferSize  // pointer to actual count of 
                              // characters returned in buffer
);
 
LS_STATUS_CODE LS_API_ENTRY LSRelease(
  LS_HANDLE LicenseHandle,  // handle to the license context
  LS_ULONG TotUnitsConsumed,  // units consumed in this handle 
                              // context
  LS_STR *LogComment        // pointer to optional comment 
                            // associated with the request
);
 
LS_STATUS_CODE LS_API_ENTRY LSRequest(
  LS_STR *LicenseSystem,  // pointer to string identifying the 
                          // license system
  LS_STR *PublisherName,  // pointer to publisher of product 
                          // requesting licensing resources
  LS_STR *ProductName,    // pointer to name of product requesting 
                          // licensing resources
  LS_STR *Version,        // pointer to version number of product 
                          // requesting licensing resources
  LS_ULONG TotUnitsReserved,  // units required to run the 
                              // application
  LS_STR *LogComment,     // pointer to optional comment associated 
                          // with the request
  LS_CHALLENGE *Challenge,  // pointer to a challenge structure
  LS_ULONG *TotUnitsGranted,  // pointer to total number of units 
                              // granted
  LS_HANDLE *LicenseHandle  // pointer to handle to the license 
                            // context
);
 
LPTSTR lstrcat(
  LPTSTR lpString1,  // pointer to buffer for concatenated strings
  LPCTSTR lpString2  // pointer to string to add to string1
);
 
int lstrcmp(
  LPCTSTR lpString1,  // pointer to first string
  LPCTSTR lpString2   // pointer to second string
);
 
int lstrcmpi(
  LPCTSTR lpString1,  // pointer to first string
  LPCTSTR lpString2   // pointer to second string
);
 
LPTSTR lstrcpy(
  LPTSTR lpString1,  // pointer to buffer
  LPCTSTR lpString2  // pointer to string to copy
);
 
LPTSTR lstrcpyn(
  LPTSTR lpString1,  // pointer to target buffer
  LPCTSTR lpString2, // pointer to source string
  int iMaxLength     // number of bytes or characters to copy
);
 
int lstrlen(
  LPCTSTR lpString   // pointer to string to count
);
 
LS_STATUS_CODE LS_API_ENTRY LSUpdate(
  LS_HANDLE LicenseHandle,    // handle to the license context
  LS_ULONG TotUnitsConsumed,  // units consumed in this handle 
                              // context
  LS_ULONG TotUnitsReserved,  // units required to run the 
                              // application
  LS_STR *LogComment,         // pointer to optional comment 
                              // associated with the request
  LS_CHALLENGE *Challenge,    // pointer to a challenge structure
  LS_ULONG *TotUnitsGranted   // pointer to total number of units 
                              // granted
);
 
VOID LZClose(
  INT hFile   // LZ file handle identifying file to be closed
);
 
LONG LZCopy(
  INT hfSource,  // LZ file handle identifying source file
  INT hfDest     // LZ file handle identifying destination file
);
 
INT LZInit(
  INT hfSource   // handle to source file
);
 
INT LZOpenFile(
  LPTSTR lpFileName,       // address of name of file to be opened
  LPOFSTRUCT lpReOpenBuf,  // address of open file structure
  WORD wStyle              // action to take
);
 
INT LZRead(
  INT hFile,       // LZ file handle to file
  LPSTR lpBuffer,  // address of buffer for bytes
  INT cbRead       // count of bytes
);
 
LONG LZSeek(
  INT hFile,     // handle to source file
  LONG lOffset,  // number of bytes to move
  INT iOrigin    // starting position
);
 
BOOL MakeAbsoluteSD(
  PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
                                // address of self-relative SD
  PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,  
                                // address of absolute SD
  LPDWORD lpdwAbsoluteSecurityDescriptorSize,  
                                // address of size of absolute SD
  PACL pDacl,                   // address of discretionary ACL
  LPDWORD lpdwDaclSize,         // address of size of discretionary ACL
  PACL pSacl,                   // address of system ACL
  LPDWORD lpdwSaclSize,         // address of size of system ACL
  PSID pOwner,                  // address of owner SID
  LPDWORD lpdwOwnerSize,        // address of size of owner SID
  PSID pPrimaryGroup,           // address of primary-group SID
  LPDWORD lpdwPrimaryGroupSize  // address of size of group SID
);
 
BOOL MakeSelfRelativeSD(
  PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,  
                             // address of absolute SD
  PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,  
                             // address self-relative SD
  LPDWORD lpdwBufferLength   // address of SD size
);
 
BOOL MakeSureDirectoryPathExists(
  IN LPSTR DirPath  
);
 
BOOL MapAndLoad(
  IN LPSTR ImageName,             
  IN LPSTR DllPath,               
  OUT PLOADED_IMAGE LoadedImage,  
  IN BOOL DotDll,                 
  IN BOOL ReadOnly                
);
 
PIMAGE_DEBUG_INFORMATION MapDebugInformation(
  IN HANDLE FileHandle, 
  IN LPSTR FileName,    
  IN LPSTR SymbolPath,  
  IN DWORD ImageBase    
);
 
BOOL MapDialogRect(
  HWND hDlg,      // handle of dialog box
  LPRECT lpRect   // address of structure with rectangle
);
 
ULONG MapFileAndCheckSum(
  IN LPTSTR Filename,      
  OUT LPDWORD HeaderSum,  
  OUT LPDWORD CheckSum    
);
 
VOID MapGenericMask(
  PDWORD AccessMask,  // address of access mask
  PGENERIC_MAPPING GenericMapping 
                      // address of GENERIC_MAPPING structure
);
 
LPVOID MapViewOfFile(
  HANDLE hFileMappingObject,  // file-mapping object to map into 
                              // address space
  DWORD dwDesiredAccess,      // access mode
  DWORD dwFileOffsetHigh,     // high-order 32 bits of file offset
  DWORD dwFileOffsetLow,      // low-order 32 bits of file offset
  DWORD dwNumberOfBytesToMap  // number of bytes to map
);
 
LPVOID MapViewOfFileEx(
  HANDLE hFileMappingObject,  // file-mapping object to map into 
                              // address space
  DWORD dwDesiredAccess,      // access mode
  DWORD dwFileOffsetHigh,     // high-order 32 bits of file offset
  DWORD dwFileOffsetLow,      // low-order 32 bits of file offset
  DWORD dwNumberOfBytesToMap, // number of bytes to map
  LPVOID lpBaseAddress        // suggested starting address for mapped 
                              // view
);
 
LPVOID MapViewOfFileVlm(
  HANDLE hFileMappingObject,  // file-mapping object to map into 
                              // address space
  DWORD dwDesiredAccess,      // desired access mode
  DWORDLONG ulOffset,         // offset into mapping region
  DWORDLONG ulNumberOfBytesToMap,  // size of mapping in bytes
  PVOID64 lpBaseAddress       // address of region of shared memory
);
 
UINT MapVirtualKey(
  UINT uCode,     // virtual-key code or scan code
  UINT uMapType   // translation to perform
);
 
UINT MapVirtualKeyEx(
  UINT uCode,     // virtual-key code or scan code
  UINT uMapType,  // translation to perform
  HKL dwhkl       // keyboard layout handle
);
 
int MapWindowPoints(
  HWND hWndFrom, // handle of window to be mapped from
  HWND hWndTo,       // handle to window to be mapped to
  LPPOINT lpPoints,  // pointer to array with points to map
  UINT cPoints       // number of structures in array
);
 
BOOL MaskBlt(
  HDC hdcDest,     // handle to destination device context
  int nXDest,      // x-coord. of upper-left corner of 
                   // destination rectangle
  int nYDest,      // y-coord. of upper-left corner of
                   // destination rectangle
  int nWidth,      // width of source and destination rectangles
  int nHeight,     // height of source and destination rectangles
  HDC hdcSrc,      // handle to source device context
  int nXSrc,   // x-coord. of upper-left corner of source rectangle
  int nYSrc,   // y-coord. of upper-left corner of source rectangle
  HBITMAP hbmMask, // handle to monochrome bit mask
  int xMask,       // horizontal pixel offset into the mask bitmap
  int yMask,       // vertical pixel offset into the mask bitmap
  DWORD dwRop      // raster operation code
);
 
UINT WINAPI MenuItemFromPoint(
  HWND hWnd,     
  HMENU hMenu,   
  POINT ptScreen 
);
 
BOOL MessageBeep(
  UINT uType   // sound type
);
 
int MessageBox(
  HWND hWnd,          // handle of owner window
  LPCTSTR lpText,     // address of text in message box
  LPCTSTR lpCaption,  // address of title of message box
  UINT uType          // style of message box
);
 
int MessageBoxEx(
  HWND hWnd,         // handle of owner window
  LPCTSTR lpText,    // address of text in message box
  LPCTSTR lpCaption, // address of title of message box
  UINT uType,        // style of message box
  WORD wLanguageId   // language identifier
);
 
int MessageBoxIndirect(
  LPMSGBOXPARAMS lpMsgBoxParams  // address of structure for message 
                                 // box parameters
);
 
LRESULT CALLBACK MessageProc(
  int code,       // hook code
  WPARAM wParam,  // undefined
  LPARAM lParam   // address of structure with message data
);
 
BOOL ModifyMenu(
  HMENU hMnu,       // handle to menu
  UINT uPosition,   // menu item to modify
  UINT uFlags,      // menu item flags
  UINT uIDNewItem,  // menu item identifier or handle to drop-down 
                    // menu or submenu
  LPCTSTR lpNewItem // menu item content
);
 
BOOL ModifyWorldTransform(
  HDC hdc,               // handle of device context
  CONST XFORM *lpXform,  // address of transformation data
  DWORD iMode            // modification mode
);
 
BOOL WINAPI Module32First(
  HANDLE hSnapshot,     
  LPMODULEENTRY32 lpme  
);
 
BOOL WINAPI Module32Next(
  HANDLE hSnapshot,     
  LPMODULEENTRY32 lpme  
);
 
BOOL CALLBACK MonitorEnumProc(
  HMONITOR hMonitor,  // handle to display monitor
  HDC hdcMonitor,     // handle to monitor-appropriate device context
  LPRECT lprcMonitor, // pointer to monitor intersection rectangle
  LPARAM dwData       // data passed from EnumDisplayMonitors
);
 
HMONITOR MonitorFromPoint(
  POINT pt,      // a specified point 
  DWORD dwFlags  // flags if no monitor contains specified point 
);
 
HMONITOR MonitorFromRect(
  LPCRECT lprc,    // pointer to a RECT structure 
  DWORD dwFlags    // flags if no monitor intersects the rectangle 
);
 
HMONITOR MonitorFromWindow(
  HWND hwnd,       // handle to a window 
  DWORD dwFlags    // flags if no monitor intersects the window 
);
 
VOID mouse_event(
  DWORD dwFlags, // flags specifying various motion/click variants
  DWORD dx,      // horizontal mouse position or position change
  DWORD dy,      // vertical mouse position or position change
  DWORD dwData,  // amount of wheel movement
  DWORD dwExtraInfo 
                 // 32 bits of application-defined information
);
 
LRESULT CALLBACK MouseProc(
  int nCode,      // hook code
  WPARAM wParam,  // message identifier
  LPARAM lParam   // mouse coordinates
);
 
BOOL MoveFile(
  LPCTSTR lpExistingFileName, // pointer to the name of the existing file
  LPCTSTR lpNewFileName       // pointer to the new name for the file
);
 
BOOL MoveFileEx(
  LPCTSTR lpExistingFileName,  // pointer to the name of the existing file
  LPCTSTR lpNewFileName,       // pointer to the new name for the file
  DWORD dwFlags                // flag that specifies how to move file
);
 
VOID MoveMemory (
  PVOID Destination,  // address of move destination
  CONST VOID *Source, // address of block to move
  DWORD Length        // size, in bytes, of block to move
);
 
VOID MoveMemoryVlm (
  PVOID64 Destination,  // address of move destination
  PVOID64 Source, // address of block to move
  DWORD Length        // size, in bytes, of block to move
);
 
BOOL MoveToEx(
  HDC hdc,          // handle to device context
  int X,            // x-coordinate of new current position
  int Y,            // y-coordinate of new current position
  LPPOINT lpPoint   // pointer to old current position
);
 
BOOL MoveWindow(
  HWND hWnd,      // handle to window
  int X,          // horizontal position
  int Y,          // vertical position
  int nWidth,     // width
  int nHeight,    // height
  BOOL bRepaint   // repaint flag
);
 
DWORD MsgWaitForMultipleObjects(
  DWORD nCount,          // number of handles in the handle array
  LPHANDLE pHandles,     // pointer to the object-handle array
  BOOL fWaitAll,         // wait for all or wait for one
  DWORD dwMilliseconds,  // time-out interval in milliseconds
  DWORD dwWakeMask       // type of input events to wait for
);
 
DWORD MsgWaitForMultipleObjectsEx(
  DWORD nCount,          // number of handles in handle array
  LPHANDLE pHandles,     // pointer to an object-handle array
  DWORD dwMilliseconds,  // time-out interval in milliseconds
  DWORD dwWakeMask,      // type of input events to wait for
  DWORD dwFlags          // wait flags
);
 
int MulDiv(
  int nNumber,       // 32-bit signed multiplicand
  int nNumerator,    // 32-bit signed multiplier
  int nDenominator   // 32-bit signed divisor
);
 
int MultiByteToWideChar(
  UINT CodePage,         // code page
  DWORD dwFlags,         // character-type options
  LPCSTR lpMultiByteStr, // address of string to map
  int cchMultiByte,      // number of bytes in string
  LPWSTR lpWideCharStr,  // address of wide-character buffer
  int cchWideChar        // size of buffer
);
 
MultinetGetConnectionPerformance(
  LPNETRESOURCE lpNetResource,                    
  LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct,  
);
 
NET_API_STATUS NetAlertRaise(
  LPWSTR AlertEventName,  
  LPVOID Buffer,          
  DWORD BufferSize        
);
 
NET_API_STATUS NetAlertRaiseEx(
  LPWSTR AlertEventName,  
  LPVOID VariableInfo,    
  DWORD VariableInfoSize,  
  LPWSTR ServiceName      
);
 
NET_API_STATUS NetApiBufferAllocate(
  DWORD ByteCount,  
  LPVOID *Buffer    
);
 
NET_API_STATUS NetApiBufferFree(
  LPVOID Buffer  
);
 
NET_API_STATUS NetApiBufferReallocate(
  LPVOID OldBuffer,    
  DWORD NewByteCount,  
  LPVOID NewBuffer     
);
 
NET_API_STATUS NetApiBufferSize(
  LPVOID buffer,  
  DWORD ByteCount 
);
 
UCHAR Netbios(
  PNCB pncb   // pointer to the network control block
);
 
NET_API_STATUS NetConnectionEnum(
  LPWSTR servername,     
  LPWSTR qualifier,      
  DWORD level,           
  LPTBYTE *bufptr,       
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle, 
);
 
NET_API_STATUS NET_API_FUNCTION NetDfsAdd(
  LPWSTR DfsEntryPath,   // Dfs entry path for the added junction 
                         // point
  LPWSTR ServerName,     // name of server exporting the storage
  LPWSTR ShareName,      // existing share name for the storage
  LPWSTR Comment,        // optional comment for the junction point
  DWORD Flags            // zero for no flags
);
 
NET_API_STATUS NET_API_FUNCTION NetDfsEnum(
  LPWSTR DfsName,        // name of the Dfs for enumeration
  DWORD Level,           // level of information requested
  DWORD PrefMaxLen,      // advisory, but -1 means return all
                         // information
  LPBYTE *Buffer,        // function allocates and returns buffer
                         // with requested info
  LPDWORD EntriesRead,   // number of entries returned
  LPDWORD ResumeHandle   // must be 0 on first call, reused on 
                         // subsequent calls
);
 
NET_API_STATUS NET_API_FUNCTION NetDfsGetInfo(
  LPWSTR DfsEntryPath,        // Dfs entry path for the junction point
  LPWSTR ServerName OPTIONAL, // name of server exporting the storage
  LPWSTR ShareName OPTIONAL,  // name of share exporting the storage
  DWORD Level,                // level of information requested
  LPBYTE* Buffer              // function allocates and returns 
                              // buffer with requested info
);
 
NET_API_STATUS NET_API_FUNCTION NetDfsRemove(
  LPWSTR DfsEntryPath,   // Dfs entry path for the junction point
  LPWSTR ServerName,     // name of server exporting the storage
  LPWSTR ShareName       // name of share exporting the storage
);
 
NET_API_STATUS NET_API_FUNCTION NetDfsSetInfo(
  LPWSTR DfsEntryPath,        // Dfs entry path for the junction point
  LPWSTR ServerName OPTIONAL, // name of server exporting the storage
  LPWSTR ShareName OPTIONAL,  // name of share exporting the storage
  DWORD Level,                // level of information to be set
  LPBYTE Buffer               // buffer holding information
);
 
NET_API_STATUS NetFileEnum(
  LPWSTR servername,     
  LPWSTR basepath,       
  LPWSTR username,       
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetFileGetInfo(
  LPWSTR servername,  
  DWORD fileid,       
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetGetDCName(
  LPWSTR servername,  
  LPWSTR domainname,  
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetGetDisplayInformationIndex(
  LPWSTR ServerName,  // pointer to server to get information from
  DWORD Level,        // level of information to retrieve
  LPWSTR Prefix,      // pointer to prefix string
  LPDWORD Index       // receives index of entry
);
 
NET_API_STATUS NetGroupAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetGroupAddUser(
  LPWSTR servername, 
  LPWSTR GroupName,  
  LPWSTR username    
);
 
NET_API_STATUS NetGroupDel(
  LPWSTR servername,  
  LPWSTR groupname    
);
 
NET_API_STATUS NetGroupDelUser(
  LPWSTR servername, 
  LPWSTR GroupName,  
  LPWSTR Username    
);
 
NET_API_STATUS NetGroupEnum(
  LPWSTR servername,     
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetGroupGetInfo(
  LPWSTR servername, 
  LPWSTR groupname,  
  DWORD level,       
  LPBYTE *bufptr     
);
 
NET_API_STATUS NetGroupGetUsers(
  LPWSTR servername,    
  LPWSTR groupname,     
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumeHandle  
);
 
NET_API_STATUS NetGroupSetInfo(
  LPWSTR servername, 
  LPWSTR groupname,  
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetGroupSetUsers(
  LPWSTR servername,    
  LPWSTR groupname,     
  DWORD level,          
  LPBYTE buf,           
  DWORD NewMemberCount  
);
 
NET_API_STATUS NetHandleGetInfo(
  UNSIGNED SHORT hHandle,             
  SHORT sLevel,                       
  CHAR FAR *pbBuffer,                 
  UNSIGNED SHORT cbBuffer,            
  UNSIGNED SHORT FAR *pcbTotalAvail   
);
 
NET_API_STATUS NetHandleSetInfo(
  UNSIGNED SHORT hHandle,        
  SHORT sLevel,                  
  CHAR FAR *pbBuffer,            
  UNSIGNED SHORT cbBuffer,       
  UNSIGNED SHORT FAR *sParmNum   
);
 
NET_API_STATUS NetLocalGroupAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetLocalGroupAddMembers(
  LPWSTR servername,      
  LPWSTR LocalGroupName,  
  DWORD level,            
  LPBYTE buf,             
  DWORD membercount       
);
 
NET_API_STATUS NetLocalGroupDel(
  LPWSTR servername,     
  LPWSTR LocalGroupName  
);
 
NET_API_STATUS NetLocalGroupDelMembers(
  LPWSTR servername,      
  LPWSTR LocalGroupName,  
  DWORD level,            
  LPBYTE buf,             
  DWORD membercount       
);
 
NET_API_STATUS NetLocalGroupEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetLocalGroupGetInfo(
  LPWSTR servername,      
  LPWSTR LocalGroupName,  
  DWORD level,            
  LPBYTE *bufptr          
);
 
NET_API_STATUS NetLocalGroupGetMembers(
  LPWSTR servername,     
  LPWSTR localgroupname, 
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resumehandle   
);
 
NET_API_STATUS NetLocalGroupSetInfo(
  LPWSTR servername,      
  LPWSTR LocalGroupName,  
  DWORD level,            
  LPBYTE buf,             
  LPDWORD parm_err        
);
 
NET_API_STATUS NetLocalGroupSetMembers(
  LPWSTR servername,      
  LPWSTR LocalGroupName,  
  DWORD level,            
  LPBYTE buf,             
  DWORD totalentries      
);
 
NET_API_STATUS NetMessageBufferSend(
  LPWSTR servername,  
  LPWSTR msgname,     
  LPWSTR fromname,    
  LPBYTE buf,         
  DWORD buflen        
);
 
NET_API_STATUS NetMessageNameAdd(
  LPWSTR servername,  
  LPWSTR msgname      
);
 
NET_API_STATUS NetMessageNameDel(
  LPWSTR servername,  
  LPWSTR msgname      
);
 
NET_API_STATUS NetMessageNameEnum(
  LPWSTR servername,     
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetMessageNameGetInfo(
  LPWSTR servername,  
  LPWSTR msgname,     
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetQueryDisplayInformation(
  LPWSTR ServerName,           
  DWORD Level,                 
  DWORD Index,                 
  DWORD EntriesRequested,      
  DWORD PreferredMaximumLength,  
  LPDWORD ReturnedEntryCount,  
  PVOID *SortedBuffer          
);
 
NET_API_STATUS NetRemoteTOD(
  LPWSTR UncServerName,  
  LPBYTE *BufferPtr      
);
 
NET_API_STATUS NetReplExportDirAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetReplExportDirDel(
  LPWSTR servername,  
  LPWSTR dirname      
);
 
NET_API_STATUS NetReplExportDirEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetReplExportDirGetInfo(
  LPWSTR servername,  
  LPWSTR dirname,     
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetReplExportDirLock(
  LPWSTR servername,  
  LPWSTR dirname      
);
 
NET_API_STATUS NetReplExportDirSetInfo(
  LPWSTR servername, 
  LPWSTR dirname,    
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetReplExportDirUnlock(
  LPWSTR servername, 
  LPWSTR dirname,    
  DWORD unlockforce  
);
 
NET_API_STATUS NetReplGetInfo(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetReplImportDirAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetReplImportDirDel(
  LPWSTR servername,  
  LPWSTR dirname      
);
 
NET_API_STATUS NetReplImportDirEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetReplImportDirGetInfo(
  LPWSTR servername,  
  LPWSTR dirname,     
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetReplImportDirLock(
  LPWSTR servername,  
  LPWSTR dirname      
);
 
NET_API_STATUS NetReplImportDirUnlock(
  LPWSTR servername, 
  LPWSTR dirname,    
  DWORD unlockforce  
);
 
NET_API_STATUS NetReplSetInfo(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetScheduleJobAdd(
  LPWSTR Servername,  
  LPBYTE Buffer,      
  LPDWORD JobId       
);
 
NET_API_STATUS NetScheduleJobDel(
  LPWSTR Servername,  
  DWORD MinJobId,     
  DWORD MaxJobId      
);
 
NET_API_STATUS NetScheduleJobEnum(
  LPWSTR Servername,             
  LPBYTE *PointerToBuffer,       
  DWORD PreferredMaximumLength,  
  LPDWORD EntriesRead,           
  LPDWORD TotalEntries,          
  LPDWORD ResumeHandle           
);
 
NET_API_STATUS NetScheduleJobGetInfo(
  LPWSTR Servername,       
  DWORD JobId,             
  LPBYTE *PointerToBuffer  
);
 
NET_API_STATUS NetServerDiskEnum(
  LPWSTR servername,     
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetServerEnum(
  LPWSTR servername,     
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  DWORD servertype,      
  LPWSTR domain,         
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetServerGetInfo(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetServerSetInfo(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD ParmError  
);
 
NET_API_STATUS NetServerTransportAdd(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE bufptr       
);
 
NET_API_STATUS NetServerTransportDel(
  LPWSTR servername,    
  LPWSTR transportname  
);
 
NET_API_STATUS NetServerTransportEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetSessionDel(
  LPWSTR servername,     
  LPWSTR UncClientName,  
  LPWSTR username        
);
 
NET_API_STATUS NetSessionEnum(
  LPWSTR servername,     
  LPWSTR UncClientName,  
  LPWSTR username,       
  DWORD level,           
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetSessionGetInfo(
  LPWSTR servername,     
  LPWSTR UncClientName,  
  LPWSTR username,       
  DWORD level,           
  LPBYTE *bufptr         
);
 
NET_API_STATUS NetShareAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetShareCheck(
  LPWSTR servername,  
  LPWSTR device,      
  LPDWORD type        
);
 
NET_API_STATUS NetShareDel(
  LPWSTR servername,  
  LPWSTR netname,     
  DWORD reserved      
);
 
NET_API_STATUS NetShareEnum(
  LPWSTR servername,     
  DWORD level,           
  LPTBYTE * bufptr,      
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle, 
);
 
NET_API_STATUS NetShareGetInfo(
  LPWSTR servername,  
  LPWSTR netname,     
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetShareSetInfo(
  LPWSTR servername, 
  LPWSTR netname,    
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetStatisticsGet2(
  LPWSTR server,  
  LPWSTR service, 
  DWORD level,    
  DWORD options,  
  LPBYTE *bufptr  
);
 
NET_API_STATUS NetUseAdd (
  LPWSTR UncServerName,  
  DWORD Level,           
  LPBYTE Buf,            
  LPDWORD ParmError      
);
 
NET_API_STATUS NetUserAdd(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetUserChangePassword(
  LPWSTR domainname,  
  LPWSTR username,    
  LPWSTR oldpassword, 
  LPWSTR newpassword  
);
 
NET_API_STATUS NetUserDel(
  LPWSTR servername,  
  LPWSTR username     
);
 
NET_API_STATUS NetUserEnum(
  LPWSTR servername,     
  DWORD level,           
  DWORD filter,          
  LPBYTE *bufptr,        
  DWORD prefmaxlen,      
  LPDWORD entriesread,   
  LPDWORD totalentries,  
  LPDWORD resume_handle  
);
 
NET_API_STATUS NetUserGetGroups(
  LPWSTR servername,    
  LPWSTR username,      
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries  
);
 
NET_API_STATUS NetUserGetInfo(
  LPWSTR servername,  
  LPWSTR username,    
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetUserGetLocalGroups(
  LPWSTR servername,    
  LPWSTR username,      
  DWORD level,          
  DWORD flags,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries  
);
 
NET_API_STATUS NetUserModalsGet(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetUserModalsSet(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetUserSetGroups(
  LPWSTR servername, 
  LPWSTR username,   
  DWORD level,       
  LPBYTE buf,        
  DWORD num_entries  
);
 
NET_API_STATUS NetUserSetInfo(
  LPWSTR servername, 
  LPWSTR username,   
  DWORD level,       
  LPBYTE buf,        
  LPDWORD parm_err   
);
 
NET_API_STATUS NetWkstaGetInfo(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE *bufptr      
);
 
NET_API_STATUS NetWkstaSetInfo(
  LPWSTR servername, 
  DWORD level,       
  LPBYTE buffer,     
  LPDWORD parm_err   
);
 
NET_API_STATUS NetWkstaTransportAdd(
  LPWSTR servername,  
  DWORD level,        
  LPBYTE buf          
);
 
NET_API_STATUS NetWkstaTransportDel(
  LPWSTR servername,     
  LPWSTR transportname,  
  DWORD ucond            
);
 
NET_API_STATUS NetWkstaTransportEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetWkstaUserEnum(
  LPWSTR servername,    
  DWORD level,          
  LPBYTE *bufptr,       
  DWORD prefmaxlen,     
  LPDWORD entriesread,  
  LPDWORD totalentries, 
  LPDWORD resumehandle  
);
 
NET_API_STATUS NetWkstaUserGetInfo(
  LPWSTR reserved,  
  DWORD level,      
  LPBYTE *bufptr    
);
 
NET_API_STATUS NetWkstaUserSetInfo(
  LPWSTR reserved,  
  DWORD level,      
  LPBYTE buf,       
  LPDWORD parm_err  
);
 
BOOL NotifyBootConfigStatus(
  BOOL BootAcceptable   // indicates acceptability of boot 
                        // configuration
);
 
BOOL NotifyChangeEventLog(
  HANDLE hEventLog,  // handle to an event log
  HANDLE hEvent      // handle to an event object
);
 
BOOL ObjectCloseAuditAlarm(
  LPCTSTR SubsystemName, // address of string for subsystem name
  LPVOID HandleId,       // address of handle identifier
  BOOL GenerateOnClose   // flag for audit generation
);
 
BOOL ObjectDeleteAuditAlarm(
  LPCTSTR SubsystemName, // pointer to string for subsystem name
  LPVOID HandleId,       // handle to the object
  BOOL GenerateOnClose   // flag for audit generation
);
 
BOOL ObjectOpenAuditAlarm(
  LPCTSTR SubsystemName,  // address of string for subsystem name
  LPVOID HandleId,        // address of handle identifier
  LPTSTR ObjectTypeName,  // address of string for object type
  LPTSTR ObjectName,      // address of string for object name
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                          // address of security descriptor
  HANDLE ClientToken,     // handle of client's access token
  DWORD DesiredAccess,    // mask for desired access rights
  DWORD GrantedAccess,    // mask for granted access rights
  PPRIVILEGE_SET Privileges,  // address of privileges
  BOOL ObjectCreation,    // flag for object creation
  BOOL AccessGranted,     // flag for results
  LPBOOL GenerateOnClose   // address of flag for audit generation
);
 
BOOL ObjectPrivilegeAuditAlarm(
  LPCTSTR SubsystemName,      // pointer to string for subsystem name
  LPVOID HandleId,            // pointer to handle identifier
  HANDLE ClientToken,         // handle to client's access token
  DWORD DesiredAccess,        // mask for desired access rights
  PPRIVILEGE_SET Privileges,  // pointer to privileges
  BOOL AccessGranted          // flag for results
);
 
DWORD OemKeyScan(
  WORD wOemChar   // ASCII value of OEM character
);
 
BOOL OemToChar(
  LPCSTR lpszSrc,  // pointer to string to translate
  LPTSTR lpszDst   // pointer to buffer for translated string
);
 
BOOL OemToCharBuff(
  LPCSTR lpszSrc,      // pointer to string to translate
  LPTSTR lpszDst,      // pointer to buffer for translated string
  DWORD cchDstLength   // size of buffer
);
 
int OffsetClipRgn(
  HDC hdc,       // handle to device context
  int nXOffset,  // offset along x-axis
  int nYOffset   // offset along y-axis
);
 
BOOL OffsetRect(
  LPRECT lprc,  // pointer to structure with rectangle
  int dx,       // horizontal offset
  int dy        // vertical offset
);
 
int OffsetRgn(
  HRGN hrgn,     // handle to region
  int nXOffset,  // offset along x-axis
  int nYOffset   // offset along y-axis
);
 
BOOL OffsetViewportOrgEx(
  HDC hdc,       // handle to device context
  int nXOffset,  // horizontal offset
  int nYOffset,  // vertical offset
  LPPOINT lpPoint 
                 // pointer to structure receiving original origin
);
 
BOOL OffsetWindowOrgEx(
  HDC hdc,          // handle to device context
  int nXOffset,     // horizontal offset
  int nYOffset,     // vertical offset
  LPPOINT lpPoint   // pointer to structure receiving the original 
                    // origin
);
 
UINT CALLBACK OFNHookProc(
  HWND hdlg,      // handle to child dialog window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
UINT CALLBACK OFNHookProcOldStyle(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg      // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
HANDLE OpenBackupEventLog(
  LPCTSTR lpUNCServerName,  // backup file server name
  LPCTSTR lpFileName        // backup filename
);
 
BOOL OpenClipboard(
  HWND hWndNewOwner   // handle to window opening clipboard
);
 
HPROFILE WINAPI OpenColorProfile(
  PPROFILE pProfile,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  DWORD dwCreationMode
);
 
HDESK OpenDesktop(
  LPTSTR lpszDesktop,    // name of the desktop to open
  DWORD dwFlags,         // flags to control interaction with other applications
  BOOL fInherit,         // specifies whether returned handle is inheritable
  DWORD dwDesiredAccess  // specifies access of returned handle
);
 
HANDLE OpenEvent(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // inherit flag
  LPCTSTR lpName          // pointer to event-object name
);
 
HANDLE OpenEventLog(
  LPCTSTR lpUNCServerName,  // pointer to server name
  LPCTSTR lpSourceName   // pointer to source name
);
 
HFILE OpenFile(
  LPCSTR lpFileName,        // pointer to the filename
  LPOFSTRUCT lpReOpenBuff,  // pointer to the file information struct
  UINT uStyle               // specifies the action and attributes
);
 
HANDLE OpenFileMapping(
  DWORD dwDesiredAccess,  // access mode
  BOOL bInheritHandle,    // inherit flag
  LPCTSTR lpName          // pointer to name of file-mapping object
);
 
BOOL OpenIcon(
  HWND hWnd   // handle to window
);
 
HDESK OpenInputDesktop(
  DWORD dwFlags,         // flags to control interaction with other applications
  BOOL fInherit,         // specifies whether returned handle is inheritable
  DWORD dwDesiredAccess  // specifies access of returned handle
);
 
HANDLE OpenJobObject(
  DWORD dwDesiredAccess,
  BOOL bInheritHandles,
  LPCTSTR lpName
);

BOOL OpenJobObjectToken(
  HANDLE hJob,
  ACCESS_MASK DesiredAccess,
  HANDLE *phToken
);
 
HANDLE OpenMutex(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // inherit flag
  LPCTSTR lpName          // pointer to mutex-object name
);
 
BOOL OpenPrinter(
  LPTSTR pPrinterName, // pointer to printer or server name
  LPHANDLE phPrinter,  // pointer to printer or server handle
  LPPRINTER_DEFAULTS pDefault 
                       // pointer to printer defaults structure
);
 
HANDLE OpenProcess(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // handle inheritance flag
  DWORD dwProcessId       // process identifier
);
 
BOOL OpenProcessToken(
  HANDLE ProcessHandle, // handle to process
  DWORD DesiredAccess,  // desired access to process
  PHANDLE TokenHandle   // pointer to handle of open access token
);
 
DWORD OpenRaw(
  LPCTSTR lpFileName,
  ULONG ulFlags,
  PVOID *pvContext
);
 
SC_HANDLE OpenSCManager(
  LPCTSTR lpMachineName,  // pointer to machine name string
  LPCTSTR lpDatabaseName,  // pointer to database name string
  DWORD dwDesiredAccess   // type of access
);
 
HANDLE OpenSemaphore(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // inherit flag
  LPCTSTR lpName          // pointer to semaphore-object name
);
 
SC_HANDLE OpenService(
  SC_HANDLE hSCManager,  // handle to service control manager 
                         // database
  LPCTSTR lpServiceName, // pointer to name of service to start
  DWORD dwDesiredAccess  // type of access to service
);
 
BOOL OpenThreadToken(
  HANDLE ThreadHandle,  // handle to thread
  DWORD DesiredAccess,  // access to process
  BOOL OpenAsSelf,      // flag for process or thread security
  PHANDLE TokenHandle   // pointer to handle to open access token
);
 
HANDLE OpenWaitableTimer(
  DWORD dwDesiredAccess,  // access flag
  BOOL bInheritHandle,    // inherit flag
  LPCTSTR lpTimerName     // pointer to timer object name
);
 
HWINSTA OpenWindowStation(
  LPTSTR lpszWinSta,     // name of the window station to open
  BOOL fInherit,         // specifies whether returned handle is inheritable
  DWORD dwDesiredAccess  // specifies access of returned handle
);
 
BOOL WINAPI ORASADFunc(
  HWND hwndOwner,  // handle of an owner window
  LPSTR lpszEntry, // pointer to a phone-book entry
  DWORD dwFlags,   // reserved; must be zero
  LPDWORD lpdwRetCode
                   // receives the results of a dialing operation
);
 
VOID OutputDebugString(
  LPCTSTR lpOutputString   // pointer to string to be displayed
);
 
BOOL CALLBACK OutputProc(
  HDC hdc,        // handle to device context
  LPARAM lpData,  // pointer to string to be drawn
  int cchData     // length of string to be drawn
);
 
LONG PackDDElParam(
  UINT msg,  // DDE message to be posted
  UINT uiLo, // low-order word of lParam of message
  UINT uiHi  // high-order word of lParam of message
);
 
UINT CALLBACK PagePaintHook(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL PageSetupDlg(
  LPPAGESETUPDLG lppsd  pointer to a structure
);
 
UINT CALLBACK PageSetupHook(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL WINAPI PaintDesktop(
  HDC hdc  
);
 
BOOL PaintRgn(
  HDC hdc,    // handle to device context
  HRGN hrgn   // handle to region to be painted
);
 
BOOL PatBlt(
  HDC hdc,     // handle to device context
  int nXLeft,  // x-coord. of upper-left corner of rect. to be filled
  int nYLeft,  // y-coord. of upper-left corner of rect. to be filled
  int nWidth,  // width of rectangle to be filled
  int nHeight, // height of rectangle to be filled
  DWORD dwRop  // raster operation code
);
 
HRGN PathToRegion(
  HDC hdc   // handle to device context
);
 
BOOL PeekConsoleInput(
  HANDLE hConsoleInput,  // handle to a console input buffer
  PINPUT_RECORD lpBuffer,  // pointer to the buffer for peek data
  DWORD nLength,         // number of records to read
  LPDWORD lpNumberOfEventsRead 
                         // pointer to number of records read
);
 
BOOL PeekMessage(
  LPMSG lpMsg,         // pointer to structure for message
  HWND hWnd,           // handle to window
  UINT wMsgFilterMin,  // first message
  UINT wMsgFilterMax,  // last message
  UINT wRemoveMsg      // removal flags
);
 
BOOL PeekNamedPipe(
  HANDLE hNamedPipe,             // handle to pipe to copy from
  LPVOID lpBuffer,               // pointer to data buffer
  DWORD nBufferSize,             // size, in bytes, of data buffer
  LPDWORD lpBytesRead,           // pointer to number of bytes read
  LPDWORD lpTotalBytesAvail,     // pointer to total number of bytes available
  LPDWORD lpBytesLeftThisMessage // pointer to unread bytes in this message
);
 
BOOL Pie(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coord of bounding rectangle's upper-left corner
  int nTopRect,    // y-coord of bounding rectangle's upper-left corner
  int nRightRect,  // x-coord of bounding rectangle's lower-right corner
  int nBottomRect, // y-coord of bounding rectangle's lower-right corner
  int nXRadial1,   // x-coord of first radial's endpoint
  int nYRadial1,   // y-coord of first radial's endpoint
  int nXRadial2,   // x-coord of second radial's endpoint
  int nYRadial2    // y-coord of second radial's endpoint
);
 
typedef BOOL (CALLBACK *PIMAGEHLP_STATUS_ROUTINE)(
  IMAGEHLP_STATUS_REASON Reason,
  LPSTR ImageName,
  LPSTR DllName,
  ULONG Va,
  ULONG Parameter
);
 
BOOL PlayEnhMetaFile(
  HDC hdc,            // handle to a device context
  HENHMETAFILE hemf,  // handle to an enhanced metafile
  CONST RECT *lpRect  // pointer to bounding rectangle
);
 
BOOL PlayEnhMetaFileRecord(
  HDC hdc,                              // handle to device context
  LPHANDLETABLE lpHandletable,          // pointer to metafile handle table
  CONST ENHMETARECORD *lpEnhMetaRecord, // pointer to metafile record
  UINT nHandles                         // count of handles
);
 
BOOL PlayMetaFile(
  HDC hdc,        // handle to the device context
  HMETAFILE hmf   // handle to the metafile
);
 
BOOL PlayMetaFileRecord(
  HDC hdc,                      // handle to device context
  LPHANDLETABLE lpHandletable,  // pointer to metafile handle table
  LPMETARECORD lpMetaRecord,    // pointer to metafile record
  UINT nHandles                 // count of handles
);
 
BOOL PlgBlt(
  HDC hdcDest,     // handle to destination device context
  CONST POINT *lpPoint,
                   // vertices of destination parallelogram
  HDC hdcSrc,      // handle to source device context
  int nXSrc,       // x-coord. of upper-left corner of source rect.
  int nYSrc,       // y-coord. of upper-left corner of source rect.
  int nWidth,      // width of source rectangle
  int nHeight,     // height of source rectangle
  HBITMAP hbmMask, // handle to bitmask
  int xMask,       // x-coord. of upper-left corner of bitmask rect.
  int yMask        // y-coord. of upper-left corner of bitmask rect.
);
 
BOOL PolyBezier(
  HDC hdc,            // handle to device context
  CONST POINT *lppt,  // pointer to endpoints and control points
  DWORD cPoints       // count of endpoints and control points
);
 
BOOL PolyBezierTo(
  HDC hdc,            // handle to device context
  CONST POINT *lppt,  // pointer to endpoints and control points
  DWORD cCount        // count of endpoints and control points
);
 
BOOL PolyDraw(
  HDC hdc,               // handle to a device context
  CONST POINT *lppt,     // pointer to array of points
  CONST BYTE *lpbTypes,  // pointer to line and curve identifiers
  int cCount             // count of points
);
 
BOOL Polygon(
  HDC hdc,                // handle to device context
  CONST POINT *lpPoints,  // pointer to polygon's vertices
  int nCount              // count of polygon's vertices
);
 
BOOL Polyline(
  HDC hdc,            // handle to device context
  CONST POINT *lppt,  // pointer to array containing endpoints
  int cPoints         // number of points in the array
);
 
BOOL PolylineTo(
  HDC hdc,            // handle to device context
  CONST POINT *lppt,  // pointer to array of points
  DWORD cCount        // number of points in array
);
 
BOOL PolyPolygon(
  HDC hdc,                  // handle to device context
  CONST POINT *lpPoints,    // pointer to array of vertices for polygons
  CONST INT *lpPolyCounts,  // pointer to array with count of vertices
  int nCount                // count of polygons
);
 
BOOL PolyPolyline(
  HDC hdc,                      // handle to a device context
  CONST POINT *lppt,            // pointer to an array of points
  CONST DWORD *lpdwPolyPoints,  // pointer to an array of values
  DWORD cCount                  // count of entries in the second array
);
 
BOOL PolyTextOut(
  HDC hdc,                // handle to device context
  CONST POLYTEXT *pptxt,  // pointer to array of structures that 
                          // identify strings
  int cStrings            // number of structures in array
);
 
BOOL PostMessage(
  HWND hWnd,      // handle of destination window
  UINT Msg,       // message to post
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
BOOL PostQueuedCompletionStatus(
  HANDLE CompletionPort,  // handle to an I/O completion port
  DWORD dwNumberOfBytesTransferred,  // value to return via 
                          // GetQueuedCompletionStatus' 
                          // lpNumberOfBytesTranferred
  DWORD dwCompletionKey,  // value to return via 
                          // GetQueuedCompletionStatus' 
                          // lpCompletionKey
  LPOVERLAPPED lpOverlapped  // value to return via 
                             // GetQueuedCompletionStatus' lpOverlapped
);
 
VOID PostQuitMessage(
  int nExitCode   // exit code
);
 
BOOL PostThreadMessage(
  DWORD idThread, // thread identifier
  UINT Msg,       // message to post
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
DWORD PrepareTape(
  HANDLE hDevice,     // handle of open device
  DWORD dwOperation,  // preparation method
  BOOL bImmediate     // return after operation begins
);
 
BOOL PrintDlg(
  LPPRINTDLG lppd   // pointer to structure with initialization data
);
 
HRESULT PrintDlgEx(
  LPPRINTDLGEX lppd   // pointer to structure with initialization data
);
 
HPRINTER PrinterMessageBox(
  HANDLE hPrinter,  // handle to printer
  DWORD Error,      // error identifier
  HWND hWnd,        // handle to owner window
  LPTSTR pText,     // pointer to message box text
  LPTSTR pCaption,  // pointer to message box title
  DWORD dwType      // style of message box
);
 
BOOL PrinterProperties(
  HWND hWnd,        // handle to parent window
  HANDLE hPrinter   // handle to printer object
);
 
UINT CALLBACK PrintHookProc(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL PrivilegeCheck(
  HANDLE ClientToken,              // handle of client's access token
  PPRIVILEGE_SET RequiredPrivileges,  // address of privileges
  LPBOOL pfResult                     // address of flag for result
);
 
BOOL PrivilegedServiceAuditAlarm(
  LPCTSTR SubsystemName,      // address of string for subsystem name
  LPCTSTR ServiceName,        // address of string for service name
  HANDLE ClientToken,         // handle of access token
  PPRIVILEGE_SET Privileges,  // address of privileges
  BOOL AccessGranted          // flag for granted access rights
);
 
BOOL WINAPI Process32First(
  HANDLE hSnapshot,      
  LPPROCESSENTRY32 lppe  
);
 
BOOL WINAPI Process32Next(
  HANDLE hSnapshot,      
  LPPROCESSENTRY32 lppe  
);
 
BOOL PASCAL ProcessPolicies(
  HWND hwndOwner,              // handle to the parent window
  LPCTSTR lpszPolicyFilePath,  // path to the policy file
  LPCTSTR lpszUserName,        // name of the logged on user
  LPCTSTR lpszComputerName,    // name of the local computer
  DWORD dwFlags                // error handling flag
);
 
BOOL CALLBACK PropEnumProc(
  HWND hwnd,           // handle to window whose property list is 
                       // being enumerated
  LPCTSTR lpszString,  // string component of property
  HANDLE hData         // data handle component of property
);
 
BOOL CALLBACK PropEnumProcEx(
  HWND hwnd,          // handle of window with property
  LPTSTR lpszString,  // string component of property
  HANDLE hData,       // data handle component of property
  DWORD dwData        // application-defined data
);
 
BOOL PtInRect(
  CONST RECT *lprc,  // pointer to structure with rectangle
  POINT pt           // structure with point
);
 
BOOL PtInRegion(
  HRGN hrgn,  // handle to region
  int X,      // x-coordinate of point
  int Y       // y-coordinate of point
);
 
BOOL PtVisible(
  HDC hdc,  // handle of device context
  int X,    // x-coordinate of point
  int Y     // y-coordinate of point
);
 
BOOL PulseEvent(
  HANDLE hEvent   // handle to event object
);
 
BOOL PurgeComm(
  HANDLE hFile,  // handle to communications resource
  DWORD dwFlags  // action to perform
);

DWORD QueryDosDevice(
  LPCTSTR lpDeviceName, // pointer to MS-DOS device name string
  LPTSTR lpTargetPath,  // pointer to buffer for storing query results
  DWORD ucchMax         // maximum storage capacity of buffer
);
 
BOOL QueryInformationJobObject(
  HANDLE hJob,
  JOBOBJECTINFOCLASS JobObjectInformationClass,
  LPVOID lpJobObjectInformation,
  DWORD cbJobObjectInformationLength,
  LPDWORD lpReturnLength
);
 
BOOL QueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount   // pointer to counter value
);
 
BOOL QueryPerformanceFrequency(
  LARGE_INTEGER *lpFrequency   // address of current frequency
);
 
BOOL QueryServiceConfig(
  SC_HANDLE hService,  // handle of service
  LPQUERY_SERVICE_CONFIG lpServiceConfig,
                       // address of service config. structure
  DWORD cbBufSize,     // size of service configuration buffer
  LPDWORD pcbBytesNeeded   // address of variable for bytes needed
);
 
BOOL QueryServiceConfig2(
  SC_HANDLE hService,
  DWORD dwInfoLevel,
  LPBYTE lpBuffer,
  DWORD cbBufSize,
  LPDWORD pcbBytesNeeded
);
 
BOOL QueryServiceLockStatus(
  SC_HANDLE hSCManager,    // handle of svc. ctrl. mgr. database
  LPQUERY_SERVICE_LOCK_STATUS lpLockStatus,
                           // address of lock status structure
  DWORD cbBufSize,         // size of service configuration buffer
  LPDWORD pcbBytesNeeded   // address of variable for bytes needed
);
 
BOOL QueryServiceObjectSecurity(
  SC_HANDLE hService,  // handle of service
  SECURITY_INFORMATION dwSecurityInformation,
                       // type of security information requested
  PSECURITY_DESCRIPTOR lpSecurityDescriptor,
                       // address of security descriptor
  DWORD cbBufSize,     // size of security descriptor buffer
  LPDWORD pcbBytesNeeded   // address of variable for bytes needed
);
 
BOOL QueryServiceStatus(
  SC_HANDLE hService,  // handle of service
  LPSERVICE_STATUS lpServiceStatus 
                       // address of service status structure
);
 
DWORD QueueUserAPC(
  PAPCFUNC pfnAPC, // pointer to APC function
  HANDLE hThread,  // handle to the thread
  DWORD dwData     // argument for the APC function
);
 
VOID RaiseException(
  DWORD dwExceptionCode,  // exception code
  DWORD dwExceptionFlags,  // continuable exception flag
  DWORD nNumberOfArguments,  // number of arguments in array
  CONST DWORD *lpArguments   // address of array of arguments
);
 
BOOL WINAPI RASADFunc(
  LPTSTR lpszPhonebook,  // pointer to full path and filename of 
                         // phone-book file
  LPTSTR lpszEntry,      // pointer to the entry name to validate
  LPRASADPARAMS lpAutodialParams,
                         // pointer to a RASADPARAMS structure
  LPDWORD lpdwRetCode    // receives results of dialing operation
);
 
BOOL RasAdminAcceptNewConnection(
  RAS_PORT_1 *pRasPort1,  // pointer to information about the 
                          // connection
  RAS_PORT_STATISTICS *pRasStats,
                          // pointer to statistics about the port
  RAS_PARAMETERS *pRasParams  // pointer to an array of 
                              // media-specific parameters and values
);
 
VOID RasAdminConnectionHangupNotification(
  RAS_PORT_1 *pRasPort1,  // pointer to information about the 
                          // connection
  RAS_PORT_STATISTICS *pRasStats,
                          // pointer to statistics about the port
  RAS_PARAMETERS *pRasParams  // pointer to an array of 
                              // media-specific parameters and values
);
 
DWORD RasAdminFreeBuffer(
  PVOID Pointer  // pointer to the buffer to free
);
 
DWORD RasAdminGetErrorString (
  UINT ResourceId,    // error code to get message for
  WCHAR *lpszString,  // pointer to a buffer that receives the error 
                      // string
  DWORD InBufSize     // size, in characters, of the buffer
);
 
DWORD RasAdminGetIpAddressForUser(
  WCHAR *lpszUserName, // pointer to the name of the remote user
  WCHAR *lpszPortName, // pointer to the name of the port
  IPADDR *pipAddress,  // pointer to the IP address
  BOOL *bNotifyRelease // indicates whether RAS should call 
                       // RasAdminReleaseIpAddress
);
 
DWORD RasAdminGetUserAccountServer(
  const WCHAR *lpszDomain,  // pointer to the name of the Windows NT 
                            // domain
  const WCHAR *lpszServer,  // pointer to the name of the RAS server
  LPWSTR lpszUserAccountServer  // receives the name of the user 
                                // account server
);
 
DWORD RasAdminPortClearStatistics(
  const WCHAR *lpszServer,  // pointer to the server name
  const WCHAR *lpszPort  // pointer to the name of port on the server
);
 
DWORD RasAdminPortDisconnect(
  const WCHAR *lpszServer,  // pointer to the server name
  const WCHAR *lpszPort  // pointer to the name of port on the server
);
 
DWORD RasAdminPortEnum(
  const WCHAR *lpszServer,  // pointer to the server name
  PRAS_PORT_0 *ppRasPort0,  // receives a pointer to an array of 
                            // port information
  WORD *pcEntriesRead       // receives the number of ports 
                            // enumerated
);
 
DWORD RasAdminPortGetInfo(
  const WCHAR *lpszServer,  // pointer to the server name
  const WCHAR *lpszPort,  // pointer to the name of port on the 
                          // server
  RAS_PORT_1 *pRasPort1,  // receives the state of the port
  RAS_PORT_STATISTICS *pRasStats,
                          // receives statistics about the port
  RAS_PARAMETERS **ppRasParams
                          // receives an array of media-specific 
                          // parameters and values
);
 
VOID RasAdminReleaseIpAddress(
  WCHAR *lpszUserName,  // pointer to the name of the remote user
  WCHAR *lpszPortName,  // pointer to the name of the port
  IPADDR *pipAddress    // pointer to the IP address
);
 
DWORD RasAdminServerGetInfo(
  const WCHAR *lpszServer,  // pointer to the name of the RAS server
  PRAS_SERVER_0 pRasServer0  // pointer to server information
);
 
DWORD RasAdminUserGetInfo(
  const WCHAR *lpszUserAccountServer,
                         // pointer to the name of the user account 
                         // server
  const WCHAR *lpszUser, // pointer to the name of the user
  PRAS_USER_0 pRasUser0  // receives the user's RAS information
);
 
DWORD RasAdminUserSetInfo(
  const WCHAR *lpszUserAccountServer,
                               // pointer to the name of the user 
                               // account server
  const WCHAR *lpszUser,       // pointer to the name of the user
  const PRAS_USER_0 pRasUser0  // pointer to the new RAS information 
                               // for this user
);
 
DWORD RasConnectionNotification(
  HRASCONN hrasconn,  // handle to a RAS connection
  HANDLE hEvent,      // handle to an event object
  DWORD dwFlags       // type of event to receive notifications for
);
 
DWORD RasCreatePhonebookEntry(
  HWND hwnd,  // handle to the parent window of the dialog box
  LPCTSTR lpszPhonebook
              // pointer to the full path and filename of the 
              // phone-book file
);
 
DWORD RasDeleteEntry(
  LPCTSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPCTSTR lpszEntry       // pointer to an entry name to delete
);
 
DWORD RasDial(
  LPRASDIALEXTENSIONS lpRasDialExtensions,
                          // pointer to function extensions data
  LPCTSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPRASDIALPARAMS lpRasDialParams,
                          // pointer to calling parameters data
  DWORD dwNotifierType,   // specifies type of RasDial event handler
  LPVOID lpvNotifier,     // specifies a handler for RasDial events
  LPHRASCONN lphRasConn   // pointer to variable to receive 
                          // connection handle
);
 
BOOL RasDialDlg(
  LPTSTR lpszPhonebook,   // pointer to the full path and filename of
                          // the phone-book file
  LPTSTR lpszEntry,       // pointer to the name of the phone-book 
                          // entry to dial
  LPTSTR lpszPhoneNumber, // pointer to replacement phone number to 
                          // dial
  LPRASDIALDLG lpInfo     // pointer to a structure that contains 
                          // additional parameters
);
 
VOID WINAPI RasDialFunc(
  UINT unMsg,    // type of event that has occurred
  RASCONNSTATE rasconnstate,
                 // connection state about to be entered
  DWORD dwError  // error that may have occurred
);
 
VOID WINAPI RasDialFunc1(
  HRASCONN hrasconn,  // handle to RAS connection
  UINT unMsg,         // type of event that has occurred
  RASCONNSTATE rascs, // connection state about to be entered
  DWORD dwError,      // error that may have occurred
  DWORD dwExtendedError
                      // extended error information for some errors
);
 
DWORD WINAPI RasDialFunc2(
  DWORD dwCallbackId,    // user-defined value specified in RasDial 
                         // call
  DWORD dwSubEntry,      // subentry index in multilink connection
  HRASCONN hrasconn,     // handle to RAS connection
  UINT unMsg,            // type of event that has occurred
  RASCONNSTATE rascs,    // connection state about to be entered
  DWORD dwError,         // error that may have occurred
  DWORD dwExtendedError  // extended error information for some 
                         // errors
);
 
DWORD RasEditPhonebookEntry(
  HWND hwnd,             // handle to the parent window of the dialog
                         // box
  LPCTSTR lpszPhonebook, // pointer to the full path and filename of
                         // the phone-book file
  LPCTSTR lpszEntryName  // pointer to the phone-book entry name
);
 
BOOL RasEntryDlg(
  LPTSTR lpszPhonebook, // pointer to the full path and filename of 
                        // the phone-book file
  LPTSTR lpszEntry,     // pointer to the name of the phone-book 
                        // entry to edit, copy, or create
  LPRASENTRYDLG lpInfo  // pointer to a structure that contains 
                        // additional parameters
);
 
DWORD RasEnumAutodialAddresses(
  LPTSTR *lppAddresses,  // pointer to buffer that receives network 
                         // address strings
  LPDWORD lpdwcbAddresses,  // pointer to size, in bytes, of the 
                            // buffer
  LPDWORD lpdwcAddresses // pointer to number of strings returned
);
 
DWORD RasEnumConnections(
  LPRASCONN lprasconn,  // buffer to receive connections data
  LPDWORD lpcb,         // size in bytes of buffer
  LPDWORD lpcConnections
                        // number of connections written to buffer
);
 
DWORD RasEnumDevices(
  LPRASDEVINFO lpRasDevInfo,  // buffer to receive information about 
                              // RAS devices
  LPDWORD lpcb,               // size, in bytes, of the buffer
  LPDWORD lpcDevices          // receives the number of entries 
                              // written to the buffer
);
 
DWORD RasEnumEntries (
  LPCTSTR reserved,       // reserved, must be NULL
  LPTCSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPRASENTRYNAME lprasentryname,
                          // buffer to receive phone-book entries
  LPDWORD lpcb,           // size in bytes of buffer
  LPDWORD lpcEntries      // number of entries written to buffer
);
 
DWORD RasGetAutodialAddress(
  LPCTSTR lpszAddress,   // pointer to a network address string
  LPDWORD lpdwReserved,  // reserved; must be NULL
  LPRASAUTODIALENTRY lpAutoDialEntries,
                       // pointer to buffer for AutoDial entry data
  LPDWORD lpdwcbAutoDialEntries,
                       // pointer to size, in bytes, of buffer
  LPDWORD lpdwcAutoDialEntries
                       // pointer to number of entries returned
);
 
DWORD RasGetAutodialEnable(
  DWORD dwDialingLocation,
                     // identifier of the TAPI dialing location
  LPBOOL lpfEnabled  // pointer to variable that receives AutoDial 
                     // state for this location
);
 
DWORD RasGetAutodialParam(
  DWORD dwKey,      // indicates the parameter to retrieve
  LPVOID lpvValue,  // pointer to a buffer that receives the value
  LPDWORD lpdwcbValue
                    // size, in bytes, of the buffer
);
 
DWORD RasGetConnectStatus(
  HRASCONN hrasconn,  // handle to RAS connection of interest
  LPRASCONNSTATUS lprasconnstatus
                      // buffer to receive status data
);
 
DWORD RasGetCountryInfo(
  LPRASCTRYINFO lpRasCtryInfo,
                    // buffer that receives country information
  LPDWORD lpdwSize  // size, in bytes, of the buffer
);
 
DWORD RasGetCredentials(
  LPCTSTR lpszPhonebook,            // pointer to the full path and
                                    // filename of a phone-book file
  LPCTSTR lpszEntry,                // pointer to the name of a
                                    // phone-book entry
  LPRASCREDENTIALS lpCredentials    // pointer to structure that
                                    // receives credentials
);
 
DWORD RasGetEntryDialParams(
  LPCTSTR lpszPhonebook,  // pointer to the full path and filename
                          // of the phone-book file
  LPRASDIALPARAMS lprasdialparams,
                          // pointer to a structure that receives
                          // the connection parameters
  LPBOOL lpfPassword      // indicates whether the user's password
                          // was retrieved
);
 
DWORD RasGetEntryProperties(
  LPCTSTR lpszPhonebook,   // pointer to full path and filename of 
                           // phone-book file
  LPCTSTR lpszEntry,       // pointer to an entry name
  LPRASENTRY lpRasEntry,   // buffer that receives entry information
  LPDWORD lpdwEntryInfoSize,  // size, in bytes, of the lpRasEntry 
                              // buffer
  LPBYTE lpbDeviceInfo,    // buffer that receives device-specific 
                           // configuration information
  LPDWORD lpdwDeviceInfoSize  // size, in bytes, of the 
                              // lpbDeviceInfo buffer
);
 
DWORD RasGetErrorString(
  UINT uErrorValue,        // error to get string for
  LPTSTR lpszErrorString,  // buffer to hold error string
  DWORD cBufSize           // size, in characters, of buffer
);
 
DWORD RasGetProjectionInfo(
  HRASCONN hrasconn,            // handle that specifies remote 
                                // access connection of interest
  RASPROJECTION rasprojection,  // specifies type of projection 
                                // information to obtain
  LPVOID lpprojection,          // points to buffer that receives 
                                // projection information
  LPDWORD lpcb                  // points to variable that specifies 
                                // buffer size
);
 
DWORD RasGetSubEntryHandle(
  HRASCONN hrasconn,     
  DWORD dwSubEntry,      
  LPHRASCONN lphrasconn  
);
 
DWORD RasGetSubEntryProperties(
  LPCTSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPCTSTR lpszEntry,      // pointer to an entry name
  DWORD dwSubEntry,       // index of the subentry
  LPRASSUBENTRY lpRasSubEntry,
                          // pointer to structure that receives 
                          // information about subentry
  LPDWORD lpdwcb,          // size, in bytes, of the structure
  LPBYTE  lpbDeviceConfig, // pointer to TAPI device configuration 
  LPDWORD lpcbDeviceConfig // pointer to size of device configuration
);
 
DWORD RasHangUp(
  HRASCONN hrasconn   // handle to the RAS connection to hang up
);
 
BOOL RasMonitorDlg(
  LPTSTR lpszDeviceName,  // pointer to the name of the device to 
                          // display initially
  LPRASMONITORDLG lpInfo  // pointer to structure that contains 
                          // input and output parameters
);
 
VOID WINAPI RasPBDlgFunc(
  DWORD dwCallbackId,  // an application-defined value
  DWORD dwEvent,       // indicates the event that occurred
  LPTSTR pszText,      // pointer to an additional string argument
  LPVOID pData         // pointer to an additional buffer argument
);
 
BOOL RasPhonebookDlg(
  LPTSTR lpszPhonebook,  // pointer to the full path and filename of 
                         // the phone-book file
  LPTSTR lpszEntry,      // pointer to the name of the phone-book 
                         // entry to highlight
  LPRASPBDLG lpInfo      // pointer to a structure that contains 
                         // additional parameters
);
 
DWORD RasRenameEntry(
  LPCTSTR lpszPhonebook, // pointer to full path and filename of 
                         // phone-book file
  LPCTSTR lpszOldEntry,  // pointer to the old entry name
  LPCTSTR lpszNewEntry   // pointer to the new entry name
);
 
DWORD WINAPI RasSecurityDialogBegin(
  HPORT hPort,        // RAS handle to the port
  PBYTE pSendBuf,     // pointer to buffer for sending data
  DWORD SendBufSize,  // size, in bytes, of the send buffer
  PBYTE pRecvBuf,     // pointer to buffer for receiving data
  DWORD RecvBufSize,  // size, in bytes, of the receive buffer
  VOID (WINAPI * RasSecurityDialogComplete)
                      // pointer to the completion function
);
 
VOID RasSecurityDialogComplete(
  SECURITY_MESSAGE *pSecMsg  // pointer to the security message 
                             // structure
);
 
DWORD WINAPI RasSecurityDialogEnd(
  HPORT hPort  // RAS handle to the port
);
 
DWORD RasSecurityDialogGetInfo(
  HPORT hPort,  // RAS handle to port
  RAS_SECURITY_INFO *pBuffer
                // pointer to structure that gets port information
);
 
DWORD WINAPI RasSecurityDialogReceive(
  HPORT hPort,   // RAS handle to the port
  PBYTE pBuffer, // pointer to buffer that receives the user's 
                 // response
  PWORD pBufferLength,
                 // returns size, in bytes, of the data received
  DWORD Timeout, // time-out period, in seconds
  HANDLE hEvent  // event that is signaled when operation is finished
);
 
DWORD RasSecurityDialogSend(
  HPORT hPort,       // RAS handle to the port
  PBYTE pBuffer,     // pointer to buffer containing data to send
  WORD BufferLength  // size, in bytes, of the data being sent
);
 
DWORD RasSetAutodialAddress(
  LPCTSTR lpszAddress,        // pointer to a network address string
  DWORD dwReserved,           // reserved; must be zero
  LPRASAUTODIALENTRY lpAutoDialEntries,
                              // pointer to buffer containing
                              // AutoDial entry data
  DWORD dwcbAutoDialEntries,  // size, in bytes, of the buffer
  DWORD dwcAutoDialEntries    // number of entries in the buffer
);
 
DWORD RasSetAutodialEnable(
  DWORD dwDialingLocation,
                 // identifier of the TAPI dialing location
  BOOL fEnabled  // AutoDial state for this location
);
 
DWORD RasSetAutodialParam(
  DWORD dwKey,     // indicates the parameter to set
  LPVOID lpvValue, // pointer to a buffer that specifies the value
  DWORD dwcbValue  // size, in bytes, of the buffer
);
 
DWORD RasSetCredentials(
  LPCTSTR lpszPhonebook,   // pointer to the full path and filename
                           // of a phone-book file
  LPCTSTR lpszEntry,       // pointer to the name of a phone-book
                           // entry
  LPRASCREDENTIALS lpCredentials, 
                           // pointer to structure that specifies the
                           // credentials
  BOOL fClearCredentials   // if true, credentials are cleared
                           // if false, credentials are set
);
 
DWORD RasSetEntryDialParams(
  LPCTSTR lpszPhonebook, // pointer to the full path and filename of
                         // the phonebook file
  LPRASDIALPARAMS lprasdialparams,
                         // pointer to a structure with the new 
                         // connection parameters
  BOOL fRemovePassword   // indicates whether to remove password
                         // from entry's parameters
);
 
DWORD RasSetEntryProperties(
  LPCTSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPCTSTR lpszEntry,      // pointer to an entry name
  LPRASENTRY lpRasEntry,  // buffer that contains entry information
  DWORD dwEntryInfoSize,  // size, in bytes, of the lpRasEntry
                          // buffer
  LPBYTE lpbDeviceInfo,   // buffer that contains device-specific 
                          // configuration information
  DWORD dwDeviceInfoSize  // size, in bytes, of the lpbDeviceInfo 
                          // buffer
); 
 
DWORD RasSetSubEntryProperties(
  LPCTSTR lpszPhonebook,    // pointer to full path and filename of 
                            // the phone-book file
  LPCTSTR lpszEntry,        // pointer to an entry name
  DWORD dwSubEntry,         // index of the subentry
  LPRASSUBENTRY lpRasSubEntry,
                            // pointer to structure containing 
                            // information about subentry
  DWORD dwcbRasSubEntry     // size, in bytes, of the structure
  LPBYTE lpbDeviceConfig,   // pointer to TAPI device configuration 
  DWORD dwcbDeviceConfig    // size of TAPI device configuration 
); 
 
DWORD RasValidateEntryName(
  LPCTSTR lpszPhonebook,  // pointer to full path and filename of 
                          // phone-book file
  LPCTSTR lpszEntry       // pointer to the entry name to validate
);
 
BOOL ReadConsole(
  HANDLE hConsoleInput,        // handle to a console input buffer
  LPVOID lpBuffer,             // address of buffer to receive data
  DWORD nNumberOfCharsToRead,  // number of characters to read
  LPDWORD lpNumberOfCharsRead,  // address of number of characters 
                                // read
  LPVOID lpReserved            // reserved
);
 
BOOL ReadConsoleInput(
  HANDLE hConsoleInput,  // handle to a console input buffer
  PINPUT_RECORD lpBuffer,  // address of the buffer for read data
  DWORD nLength,         // number of records to read
  LPDWORD lpNumberOfEventsRead 
                         // address of number of records read
);
 
BOOL ReadConsoleOutput(
  HANDLE hConsoleOutput,  // handle to a console screen buffer
  PCHAR_INFO lpBuffer,    // address of buffer that receives data
  COORD dwBufferSize,     // column-row size of destination buffer
  COORD dwBufferCoord,    // upper-left cell to write to
  PSMALL_RECT lpReadRegion   // address of rectangle to read from
);
 
BOOL ReadConsoleOutputAttribute(
  HANDLE hConsoleOutput,
                      // handle to a console screen buffer
  LPWORD lpAttribute, // address of buffer to receive attributes
  DWORD nLength,      // number of character cells to read from
  COORD dwReadCoord,  // coordinates of first cell to read from
  LPDWORD lpNumberOfAttrsRead 
                      // address of number of cells read from
);
 
BOOL ReadConsoleOutputCharacter(
  HANDLE hConsoleOutput,
                      // handle to a console screen buffer
  LPTSTR lpCharacter, // address of buffer to receive characters
  DWORD nLength,      // number of character cells to read from
  COORD dwReadCoord,  // coordinates of first cell to read from
  LPDWORD lpNumberOfCharsRead 
                      // address of number of cells read from
);
 
BOOL ReadDirectoryChangesW(
  HANDLE hDirectory,    // handle to the directory to be watched
  LPVOID lpBuffer,      // pointer to the buffer to receive the read 
                        // results
  DWORD nBufferLength,  // length of lpBuffer
  BOOL bWatchSubtree,   // flag for monitoring directory or 
                        // directory tree
  DWORD dwNotifyFilter, // filter conditions to watch for
  LPDWORD lpBytesReturned,  // number of bytes returned
  LPOVERLAPPED lpOverlapped,
                        // pointer to structure needed for 
                        // overlapped I/O
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
                        // pointer to completion routine
);
 
BOOL ReadEventLog(
  HANDLE hEventLog,            // handle to event log
  DWORD dwReadFlags,           // specifies how to read log
  DWORD dwRecordOffset,        // number of first record
  LPVOID lpBuffer,             // address of buffer for read data
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  DWORD *pnBytesRead,          // number of bytes read
  DWORD *pnMinNumberOfBytesNeeded 
                               // number of bytes required for next 
                               // record
);
 
BOOL ReadFile(
  HANDLE hFile,                // handle of file to read
  LPVOID lpBuffer,             // pointer to buffer that receives data
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  LPDWORD lpNumberOfBytesRead, // pointer to number of bytes read
  LPOVERLAPPED lpOverlapped    // pointer to structure for data
);

BOOL ReadFileEx(
  HANDLE hFile,                // handle of file to read 
  LPVOID lpBuffer,             // pointer to buffer 
  DWORD nNumberOfBytesToRead,  // number of bytes to read 
  LPOVERLAPPED lpOverlapped,   // pointer to offset 
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine 
                               // pointer to completion routine 
);
 
BOOL ReadFileScatter(
  HANDLE hFile,              // handle to a file to read data from
  FILE_SEGMENT_ELEMENT aSegmentArray [],
                             // pointer to an array of buffer 
                             // pointers
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  LPDWORD lpReserved,        // reserved; must be NULL
  LPOVERLAPPED lpOverlapped  // pointer to an asynchronous I/O data 
                             // structure
);
 
BOOL ReadFileVlm(
  HANDLE hFile,                // handle of file to read 
  PVOID64 lpBuffer,            // pointer to buffer 
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  LPDWORD lpReserved,          // reserved; must be NULL
  LPOVERLAPPED lpOverlapped    // pointer to offset 
);
 
BOOL ReadPrinter(
  HANDLE hPrinter,  // handle to printer object
  LPVOID pBuf,      // address of array of bytes that receives data
  DWORD cbBuf,      // size, in bytes, of array
  LPDWORD pNoBytesRead 
                    // address of variable with number of bytes 
                    // retrieved
);
 
BOOL ReadProcessMemory(
  HANDLE hProcess,  // handle to the process whose memory is read
  LPCVOID lpBaseAddress,
                    // address to start reading
  LPVOID lpBuffer,  // address of buffer to place read data
  DWORD nSize,      // number of bytes to read
  LPDWORD lpNumberOfBytesRead 
                    // address of number of bytes read
);
 
BOOL ReadProcessMemoryVlm(
  HANDLE hProcess,  // handle to the process whose memory is read
  PVOID64 lpBaseAddress,
                    // address to start reading
  PVOID64 lpBuffer, // address of buffer to place read data
  DWORD nSize,      // number of bytes to read
  LPDWORD lpNumberOfBytesRead 
                    // address of number of bytes read
);
 
DWORD ReadRaw(
  PFE_EXPORT_FUNC pfExportCallback,
  PVOID pvCallbackContext,
  PVOID pvContext 
);
 
UINT RealizePalette(
  HDC hdc   // handle of device context
);
 
BOOL ReBaseImage(
  IN LPSTR CurrentImageName,  
  IN LPSTR SymbolPath,      
  IN BOOL fReBase,          
  IN BOOL fRebaseSysfileOk,  
  IN BOOL fGoingDown,       
  IN DWORD CheckImageSize,  
  OUT LPDWORD OldImageSize,  
  OUT LPDWORD OldImageBase,  
  OUT LPDWORD NewImageSize,  
  IN OUT LPDWORD NewImageBase,  
  IN DWORD TimeStamp        
);
 
BOOL Rectangle(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coord of bounding rectangle's upper-left corner
  int nTopRect,    // y-coord of bounding rectangle's upper-left corner
  int nRightRect,  // x-coord of bounding rectangle's lower-right corner
  int nBottomRect  // y-coord of bounding rectangle's lower-right corner
);
 
BOOL RectInRegion(
  HRGN hrgn,         // handle to region
  CONST RECT *lprc   // pointer to rectangle
);
 
BOOL RectVisible(
  HDC hdc,           // handle of the device context
  CONST RECT *lprc   // address of rectangle structure
);
 
BOOL RedrawWindow(
  HWND hWnd,        // handle of window
  CONST RECT *lprcUpdate,
                    // address of structure with update rectangle
  HRGN hrgnUpdate,  // handle of update region
  UINT flags        // array of redraw flags
);
 
LONG RegCloseKey(
  HKEY hKey   // handle to key to close
);
 
LONG RegConnectRegistry(
  LPTSTR lpMachineName,
                    // address of name of remote computer
  HKEY hKey,        // predefined registry handle
  PHKEY phkResult   // address of buffer for remote registry handle
);
 
LONG RegCreateKey(
  HKEY hKey,        // handle to an open key
  LPCTSTR lpSubKey, // address of name of subkey to open
  PHKEY phkResult   // address of buffer for opened handle
);
 
LONG RegCreateKeyEx(
  HKEY hKey,                // handle to an open key
  LPCTSTR lpSubKey,         // address of subkey name
  DWORD Reserved,           // reserved
  LPTSTR lpClass,           // address of class string
  DWORD dwOptions,          // special options flag
  REGSAM samDesired,        // desired security access
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                            // address of key security structure
  PHKEY phkResult,          // address of buffer for opened handle
  LPDWORD lpdwDisposition   // address of disposition value buffer
);
 
LONG RegDeleteKey(
  HKEY hKey,         // handle to open key
  LPCTSTR lpSubKey   // address of name of subkey to delete
);
 
LONG RegDeleteValue(
  HKEY hKey,            // handle to key
  LPCTSTR lpValueName   // address of value name
);
 
LONG RegEnumKey(
  HKEY hKey,     // handle to key to query
  DWORD dwIndex, // index of subkey to query
  LPTSTR lpName, // address of buffer for subkey name
  DWORD cbName   // size of subkey buffer
);
 
LONG RegEnumKeyEx(
  HKEY hKey,          // handle to key to enumerate
  DWORD dwIndex,      // index of subkey to enumerate
  LPTSTR lpName,      // address of buffer for subkey name
  LPDWORD lpcbName,   // address for size of subkey buffer
  LPDWORD lpReserved, // reserved
  LPTSTR lpClass,     // address of buffer for class string
  LPDWORD lpcbClass,  // address for size of class buffer
  PFILETIME lpftLastWriteTime 
                      // address for time key last written to
);
 
LONG RegEnumValue(
  HKEY hKey,              // handle to key to query
  DWORD dwIndex,          // index of value to query
  LPTSTR lpValueName,     // address of buffer for value string
  LPDWORD lpcbValueName,  // address for size of value buffer
  LPDWORD lpReserved,     // reserved
  LPDWORD lpType,         // address of buffer for type code
  LPBYTE lpData,          // address of buffer for value data
  LPDWORD lpcbData        // address for size of data buffer
);
 
LONG RegFlushKey(
  HKEY hKey   // handle to key to write
);
 
LONG RegGetKeySecurity(
  HKEY hKey,  // open handle of key to set
  SECURITY_INFORMATION SecurityInformation,
              // descriptor contents
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
              // address of descriptor for key
  LPDWORD lpcbSecurityDescriptor 
              // address of size of buffer and descriptor
);
 
ATOM RegisterClass(
  CONST WNDCLASS *lpWndClass   // address of structure with class 
                               // data
);
 
ATOM RegisterClassEx(
  CONST WNDCLASSEX *lpwcx  // address of structure with class data
);
 
UINT RegisterClipboardFormat(
  LPCTSTR lpszFormat   // address of name string
);
 
BOOL WINAPI RegisterCMM(
  PCTSTR pMachineName,
  DWORD cmmID,
  PCTSTR pCMMdll
);
 
HANDLE RegisterEventSource(
  LPCTSTR lpUNCServerName,  // server name for source
  LPCTSTR lpSourceName   // source name for registered handle
);
 
BOOL RegisterHotKey(
  HWND hWnd,         // window to receive hot-key notification
  int id,            // identifier of hot key
  UINT fsModifiers,  // key-modifier flags
  UINT vk            // virtual-key code
);
 
SERVICE_STATUS_HANDLE RegisterServiceCtrlHandler(
  LPCTSTR lpServiceName,             // address of name of service
  LPHANDLER_FUNCTION lpHandlerProc   // address of handler function
);
 
UINT RegisterWindowMessage(
  LPCTSTR lpString   // address of message string
);
 
LONG RegLoadKey(
  HKEY hKey,       // handle to open key
  LPCTSTR lpSubKey,
                   // address of name of subkey
  LPCTSTR lpFile   // address of filename for registry information
);
 
LONG RegNotifyChangeKeyValue(
  HKEY hKey,             // handle to key to watch
  BOOL bWatchSubtree,    // flag for subkey notification
  DWORD dwNotifyFilter,  // changes to be reported
  HANDLE hEvent,         // handle to signaled event
  BOOL fAsynchronous     // flag for asynchronous reporting
);
 
LONG RegOpenKey(
  HKEY hKey,        // handle to open key
  LPCTSTR lpSubKey, // address of name of subkey to open
  PHKEY phkResult   // address of handle to open key
);
 
LONG RegOpenKeyEx(
  HKEY hKey,         // handle to open key
  LPCTSTR lpSubKey,  // address of name of subkey to open
  DWORD ulOptions,   // reserved
  REGSAM samDesired, // security access mask
  PHKEY phkResult    // address of handle to open key
);
 
LONG RegQueryInfoKey(
  HKEY hKey,                // handle to key to query
  LPTSTR lpClass,           // address of buffer for class string
  LPDWORD lpcbClass,        // address of size of class string buffer
  LPDWORD lpReserved,       // reserved
  LPDWORD lpcSubKeys,       // address of buffer for number of 
                            // subkeys
  LPDWORD lpcbMaxSubKeyLen,  // address of buffer for longest subkey 
                             // name length
  LPDWORD lpcbMaxClassLen,  // address of buffer for longest class 
                            // string length
  LPDWORD lpcValues,        // address of buffer for number of value 
                            // entries
  LPDWORD lpcbMaxValueNameLen,  // address of buffer for longest 
                                // value name length
  LPDWORD lpcbMaxValueLen,  // address of buffer for longest value 
                            // data length
  LPDWORD lpcbSecurityDescriptor,
                            // address of buffer for security 
                            // descriptor length
  PFILETIME lpftLastWriteTime   // address of buffer for last write 
                                // time
);
 
LONG RegQueryMultipleValues(
  HKEY hKey,         // handle to key to query
  PVALENT val_list,  // pointer to array of value entry structures
  DWORD num_vals,    // size of array of value entry structures
  LPTSTR lpValueBuf, // pointer to buffer for value information
  LPDWORD ldwTotsize // pointer to size of value buffer
);
 
LONG RegQueryValue(
  HKEY hKey,       // handle to key to query
  LPCTSTR lpSubKey,
                   // name of subkey to query
  LPTSTR lpValue,  // buffer for returned string
  PLONG lpcbValue  // receives size of returned string
);
 
LONG RegQueryValueEx(
  HKEY hKey,           // handle to key to query
  LPTSTR lpValueName,  // address of name of value to query
  LPDWORD lpReserved,  // reserved
  LPDWORD lpType,      // address of buffer for value type
  LPBYTE lpData,       // address of data buffer
  LPDWORD lpcbData     // address of data buffer size
);
 
LONG RegReplaceKey(
  HKEY hKey,         // handle to open key
  LPCTSTR lpSubKey,  // address of name of subkey
  LPCTSTR lpNewFile, // address of filename for file with new data
  LPCTSTR lpOldFile  // address of filename for backup file
);
 
LONG RegRestoreKey(
  HKEY hKey,      // handle to key where restore begins
  LPCTSTR lpFile, // address of filename containing saved tree
  DWORD dwFlags   // optional flags
);
 
LONG RegSaveKey(
  HKEY hKey,       // handle to key where save begins
  LPCTSTR lpFile,  // address of filename to save to
  LPSECURITY_ATTRIBUTES lpSecurityAttributes 
                   // address of security structure
);
 
LONG RegSetKeySecurity(
  HKEY hKey,  // open handle of key to set
  SECURITY_INFORMATION SecurityInformation,
              // descriptor contents
  PSECURITY_DESCRIPTOR pSecurityDescriptor 
              // address of descriptor for key
);
 
LONG RegSetValue(
  HKEY hKey,         // handle to key to set value for
  LPCTSTR lpSubKey,  // address of subkey name
  DWORD dwType,      // type of value
  LPCTSTR lpData,    // address of value data
  DWORD cbData       // size of value data
);
 
LONG RegSetValueEx(
  HKEY hKey,           // handle to key to set value for
  LPCTSTR lpValueName, // name of the value to set
  DWORD Reserved,      // reserved
  DWORD dwType,        // flag for value type
  CONST BYTE *lpData,  // address of value data
  DWORD cbData         // size of value data
);
 
LONG RegUnLoadKey(
  HKEY hKey,         // handle to open key
  LPCTSTR lpSubKey   // address of name of subkey to unload
);
 
BOOL ReleaseCapture(VOID);
 
int ReleaseDC(
  HWND hWnd,  // handle to window
  HDC hDC     // handle to device context
);
 
BOOL ReleaseMutex(
  HANDLE hMutex   // handle to mutex object
);
 
BOOL ReleaseSemaphore(
  HANDLE hSemaphore,   // handle to the semaphore object
  LONG lReleaseCount,  // amount to add to current count
  LPLONG lpPreviousCount   // address of previous count
);
 
BOOL RemoveDirectory(
  LPCTSTR lpPathName   // pointer to directory to remove
);
 
BOOL RemoveFontResource(
  LPCTSTR lpFileName   // pointer to font-resource filename
);
 
BOOL RemoveMenu(
  HMENU hMenu,     // handle to menu
  UINT uPosition,  // menu item identifier or position
  UINT uFlags      // menu item flag
);
 
BOOL RemovePrivateCvSymbolic(
  IN PCHAR DebugData,       
  OUT PCHAR *NewDebugData,  
  OUT LPDWORD NewDebugSize  
);
 
HANDLE RemoveProp(
  HWND hWnd,         // handle to window
  LPCTSTR lpString   // atom or address of string
);
 
VOID RemoveRelocations(
  IN LPSTR ImageName  
);
 
HWND ReplaceText(
  LPFINDREPLACE lpfr   // pointer to structure with initialization 
                       // data
);
 
BOOL ReplyMessage(
  LRESULT lResult   // message-specific reply
);
 
BOOL ReportEvent(
  HANDLE hEventLog,    // handle returned by RegisterEventSource
  WORD wType,          // event type to log
  WORD wCategory,      // event category
  DWORD dwEventID,     // event identifier
  PSID lpUserSid,      // user security identifier (optional)
  WORD wNumStrings,    // number of strings to merge with message
  DWORD dwDataSize,    // size of binary data, in bytes
  LPCTSTR *lpStrings,  // array of strings to merge with message
  LPVOID lpRawData     // address of binary data
);
 
BOOL RequestDeviceWakeup(
  HANDLE hDevice      // handle to object or device
);
 
BOOL RequestWakeupLatency(
  LATENCY_TIME latency      // latency requirement
);
 
HDC ResetDC(
  HDC hdc,                   // handle to device context
  CONST DEVMODE *lpInitData  // pointer to device context information
);
 
BOOL ResetEvent(
  HANDLE hEvent   // handle to event object
);
 
BOOL ResetPrinter(
  HANDLE hPrinter,  // printer handle
  LPPRINTER_DEFAULTS pDefault 
                    // address of printer defaults structure
);
 
BOOL ResizePalette(
  HPALETTE hpal, // handle of logical palette
  UINT nEntries  // number of entries in logical palette
);
 
BOOL RestoreDC(
  HDC hdc,       // handle to device context
  int nSavedDC   // specifies state to be restored
);
 
DWORD ResumeThread(
  HANDLE hThread   // identifies thread to restart
);
 
LONG ReuseDDElParam(
  LONG lParam, // posted lParam to be reused
  UINT msgIn,  // identifier of received message
  UINT msgOut, // identifier of posted message
  UINT uiLo,   // low-order word of new lParam
  UINT uiHi    // high-order word of new lParam
);
 
BOOL RevertToSelf(VOID);
 
BOOL RoundRect(
  HDC hdc,         // handle to device context
  int nLeftRect,   // x-coord of bounding rectangle's upper-left corner
  int nTopRect,    // y-coord of bounding rectangle's upper-left corner
  int nRightRect,  // x-coord of bounding rectangle's lower-right corner
  int nBottomRect, // y-coord of bounding rectangle's lower-right corner
  int nWidth,      // width of ellipse used to draw rounded corners
  int nHeight      // height of ellipse used to draw rounded corners
);
 
int SaveDC(
  HDC hdc   // handle to device context
);
 
BOOL ScaleViewportExtEx(
  HDC hdc,        // handle of device context
  int Xnum,       // horizontal multiplicand
  int Xdenom,     // horizontal divisor
  int Ynum,       // vertical multiplicand
  int Ydenom,     // vertical divisor
  LPSIZE lpSize   // address of previous viewport extents
);
 
BOOL ScaleWindowExtEx(
  HDC hdc,        // handle of device context
  int Xnum,       // horizontal multiplicand
  int Xdenom,     // horizontal divisor
  int Ynum,       // vertical multiplicand
  int Ydenom,     // vertical divisor
  LPSIZE lpSize   // address of previous window extents
);
 
BOOL ScheduleJob(
  HANDLE hPrinter,  // specifies printer for the print job
  DWORD dwJobID     // print job identifier
);
 
BOOL ScreenToClient(
  HWND hWnd,        // window handle for source coordinates
  LPPOINT lpPoint   // address of structure containing coordinates
);
 
BOOL ScrollConsoleScreenBuffer(
  HANDLE hConsoleOutput,  // handle to a console screen buffer
  CONST SMALL_RECT *lpScrollRectangle,
                          // address of screen buffer rect. to move
  CONST SMALL_RECT *lpClipRectangle,
                          // address of affected screen buffer rect.
  COORD dwDestinationOrigin,  // new location of screen buffer rect.
  CONST CHAR_INFO *lpFill   // address of fill character and color
);
 
BOOL ScrollDC(
  HDC hDC,          // handle to device context
  int dx,           // horizontal scroll units
  int dy,           // vertical scroll units
  CONST RECT *lprcScroll,
                    // address of structure for scrolling rectangle
  CONST RECT *lprcClip,
                    // address of structure for clipping rectangle
  HRGN hrgnUpdate,  // handle to scrolling region
  LPRECT lprcUpdate 
                    // address of structure for update rectangle
);
 
BOOL ScrollWindow(
  HWND hWnd,    // handle to window to scroll
  int XAmount,  // amount of horizontal scrolling
  int YAmount,  // amount of vertical scrolling
  CONST RECT *lpRect,
                // address of structure with scroll rectangle
  CONST RECT *lpClipRect 
                // address of structure with clip rectangle
);
 
int ScrollWindowEx(
  HWND hWnd,        // handle to window to scroll
  int dx,           // amount of horizontal scrolling
  int dy,           // amount of vertical scrolling
  CONST RECT *prcScroll,
                    // address of structure with scroll rectangle
  CONST RECT *prcClip,
                    // address of structure with clip rectangle
  HRGN hrgnUpdate,  // handle to update region
  LPRECT prcUpdate, // address of structure for update rectangle
  UINT flags        // scrolling flags
);
 
DWORD SearchPath(
  LPCTSTR lpPath,      // pointer to search path
  LPCTSTR lpFileName,  // pointer to filename
  LPCTSTR lpExtension, // pointer to extension
  DWORD nBufferLength, // size, in characters, of buffer
  LPTSTR lpBuffer,     // pointer to buffer for found filename
  LPTSTR *lpFilePart   // pointer to pointer to file component
);
 
BOOL SearchTreeForFile(
  IN LPSTR RootPath,       
  IN LPSTR InputPathName,  
  OUT LPSTR OutputPathBuffer  
);
 
BOOL SelectClipPath(
  HDC hdc,    // handle of device context
  int iMode   // clipping mode
);
 
int SelectClipRgn(
  HDC hdc,    // handle of device context
  HRGN hrgn   // handle of region to be selected
);
 
BOOL WINAPI SelectCMM(
  DWORD cmmID
);
 
HGDIOBJ SelectObject(
  HDC hdc,          // handle to device context
  HGDIOBJ hgdiobj   // handle to object
);
 
HPALETTE SelectPalette(
  HDC hdc,                // handle of device context
  HPALETTE hpal,          // handle of logical color palette
  BOOL bForceBackground   // foreground/background mode
);
 
VOID CALLBACK SendAsyncProc(
  HWND hwnd,        // handle of destination window
  UINT uMsg,        // message
  DWORD dwData,     // application-defined value
  LRESULT lResult   // result of message processing
);
 
LONG SendDlgItemMessage(
  HWND hDlg,      // handle of dialog box
  int nIDDlgItem, // identifier of control
  UINT Msg,       // message to send
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
UINT SendInput(
  UINT nInputs,     // count of input events
  LPINPUT pInputs,  // array of input events to insert
  int cbSize        // size of an INPUT structure
);
 
LRESULT SendMessage(
  HWND hWnd,      // handle of destination window
  UINT Msg,       // message to send
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
BOOL SendMessageCallback(
  HWND hWnd,     // handle of destination window
  UINT Msg,      // message to send
  WPARAM wParam, // first message parameter
  LPARAM lParam, // second message parameter
  SENDASYNCPROC lpResultCallBack,
                 // function to receive message value
  DWORD dwData   // value to pass to callback function
);
 
LRESULT SendMessageTimeout(
  HWND hWnd,           // handle of destination window
  UINT Msg,            // message to send
  WPARAM wParam,       // first message parameter
  LPARAM lParam,       // second message parameter
  UINT fuFlags,        // how to send the message
  UINT uTimeout,       // time-out duration
  LPDWORD lpdwResult   // return value for synchronous call
);
 
BOOL SendNotifyMessage(
  HWND hWnd,      // handle of destination window
  UINT Msg,       // message to send
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
VOID WINAPI ServiceMain(
  DWORD dwArgc,     // number of arguments
  LPTSTR *lpszArgv  //  array of argument string pointers
);
 
int SetAbortProc(
  HDC hdc,                // handle to device context
  ABORTPROC lpAbortProc   // address of abort function
);
 
BOOL SetAclInformation(
  PACL pAcl,               // address of access-control list
  LPVOID pAclInformation,  // address of ACL information
  DWORD nAclInformationLength,
                           // size of ACL information
  ACL_INFORMATION_CLASS dwAclInformationClass 
                           // specifies class of requested info
);
 
HWND SetActiveWindow(
  HWND hWnd   // handle to window to activate
);
 
int SetArcDirection(
  HDC hdc,           // handle to the device context
  int ArcDirection   // specifies the new arc direction
);
 
LONG SetBitmapBits(
  HBITMAP hbmp,        // handle to bitmap
  DWORD cBytes,        // number of bytes in bitmap array
  CONST VOID *lpBits   // address of array with bitmap bits
);
 
BOOL SetBitmapDimensionEx(
  HBITMAP hBitmap,  // handle to bitmap
  int nWidth,       // bitmap width in .01-mm units
  int nHeight,      // bitmap height in .01-mm units
  LPSIZE lpSize     // address of structure for original dimensions
);
 
COLORREF SetBkColor(
  HDC hdc,           // handle of device context
  COLORREF crColor   // background color value
);
 
int SetBkMode(
  HDC hdc,      // handle of device context
  int iBkMode   // flag specifying background mode
);
 
UINT SetBoundsRect(
  HDC hdc,                 // handle of device context
  CONST RECT *lprcBounds,  // address of rectangle coordinates
  UINT flags               // controls rectangle combination
);
 
BOOL SetBrushOrgEx(
  HDC hdc,       // handle of device context
  int nXOrg,     // x-coordinate of new origin
  int nYOrg,     // y-coordinate of new origin
  LPPOINT lppt   // points to previous brush origin
);
 
HWND SetCapture(
  HWND hWnd   // handle of window to receive mouse capture
);
 
BOOL SetCaretBlinkTime(
  UINT uMSeconds   // blink time, in milliseconds
);
 
BOOL SetCaretPos(
  int X,  // horizontal position
  int Y   // vertical position
);
 
DWORD SetClassLong(
  HWND hWnd,       // handle of window
  int nIndex,      // index of value to change
  LONG dwNewLong   // new value
);
 
WORD SetClassWord(
  HWND hWnd,      // handle of window
  int nIndex,     // index of value to change
  WORD wNewWord   // new value
);
 
HANDLE SetClipboardData(
  UINT uFormat, // clipboard format
  HANDLE hMem   // data handle
);
 
HWND SetClipboardViewer(
  HWND hWndNewViewer   // handle to clipboard viewer window
);
 
BOOL SetColorAdjustment(
  HDC hdc,  // handle to device context
  CONST COLORADJUSTMENT *lpca 
            // pointer to COLORADJUSTMENT structure
);
 
BOOL WINAPI SetColorProfileElement(
  HPROFILE hProfile,
  TAGTYPE tag,
  DWORD dwOffset, 
  PDWORD pcbSize,
  PVOID pBuffer
);
 
BOOL WINAPI SetColorProfileElementReference(
  HPROFILE hProfile,
  TAGTYPE newTag,
  TAGTYPE refTag
);
 
BOOL WINAPI SetColorProfileElementSize(
  HPROFILE hProfile,
  TAGTYPE tag,
  DWORD cbSize
);
 
BOOL WINAPI SetColorProfileHeader(
  HPROFILE hProfile,  
  PPROFILEHEADER pHeader  
);
 
HCOLORSPACE WINAPI SetColorSpace(
  HCD hDC,
  HCOLORSPACE hColorSpace
);
 
BOOL SetCommBreak(
  HANDLE hFile   // handle to communications device
);
 
BOOL SetCommConfig(
  HANDLE hCommDev,    // handle to comm device
  LPCOMMCONFIG lpCC,  // pointer to comm configuration services
  DWORD dwSize        // size of structure
);
 
BOOL SetCommMask(
  HANDLE hFile,    // handle to communications device
  DWORD dwEvtMask  // mask that identifies enabled events
);
 
BOOL SetCommState(
  HANDLE hFile,  // handle to communications device
  LPDCB lpDCB    // pointer to device-control block structure
);
 
BOOL SetCommTimeouts(
  HANDLE hFile,                  // handle to comm device
  LPCOMMTIMEOUTS lpCommTimeouts  // pointer to comm time-out structure
);
 
BOOL SetComputerName(
  LPCTSTR lpComputerName   // address of new computer name
);
 
BOOL SetConsoleActiveScreenBuffer(
  HANDLE hConsoleOutput   // handle to console screen buffer
);
 
BOOL SetConsoleCP(
  UINT wCodePageID   // code page to set
);
 
BOOL SetConsoleCtrlHandler(
  PHANDLER_ROUTINE HandlerRoutine,  // address of handler function
  BOOL Add                          // handler to add or remove
);
 
BOOL SetConsoleCursorInfo(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo 
                          // address of cursor information
);
 
BOOL SetConsoleCursorPosition(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  COORD dwCursorPosition   // new cursor position coordinates
);
 
BOOL SetConsoleMode(
  HANDLE hConsoleHandle,
                 // handle to console input or screen buffer
  DWORD dwMode   // input or output mode to set
);
 
BOOL SetConsoleOutputCP(
  UINT wCodePageID   // code page to set
);
 
BOOL SetConsoleScreenBufferSize(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  COORD dwSize            // new size in character rows and cols.
);
 
BOOL SetConsoleTextAttribute(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  WORD wAttributes        // text and background colors
);
 
BOOL SetConsoleTitle(
  LPCTSTR lpConsoleTitle   // address of new title
);
 
BOOL SetConsoleWindowInfo(
  HANDLE hConsoleOutput,  // handle to console screen buffer
  BOOL bAbsolute,         // coordinate type flag
  CONST SMALL_RECT *lpConsoleWindow 
                          // address of new window rectangle
);
 
DWORD SetCriticalSectionSpinCount(
  LPCRITICAL_SECTION lpCriticalSection, 
                      // pointer to critical section
  DWORD dwSpinCount   // spin count for critical section
);
 
BOOL SetCurrentDirectory(
  LPCTSTR lpPathName   // pointer to name of new current directory
);
 
HCURSOR SetCursor(
  HCURSOR hCursor   // handle to cursor
);
 
BOOL SetCursorPos(
  int X,  // horizontal position
  int Y   // vertical position
);
 
COLORREF SetDCBrushColor(
  HDC hdc,          // Handle to device context
  COLORREF crColor  // Specifies new brush color
);
 
COLORREF SetDCPenColor(
  HDC hdc,          // Handle to device context
  COLORREF crColor  // Specifies new pen color
);
 
VOID SetDebugErrorLevel(
  DWORD dwLevel   // debugging error level
);
 
BOOL SetDefaultCommConfig(
  LPCSTR lpszName,    // pointer to device name string
  LPCOMMCONFIG lpCC,  // pointer to structure
  DWORD dwSize        // size of structure
);
 
BOOL WINAPI SetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
);
 
UINT SetDIBColorTable(
  HDC hdc,                // handle to device context whose DIB is of
                          // interest
  UINT uStartIndex,       // color table index of first entry to set
  UINT cEntries,          // number of color table entries to set
  CONST RGBQUAD *pColors  // pointer to array of color table entries
);
 
int SetDIBits(
  HDC hdc,                  // handle to device context
  HBITMAP hbmp,             // handle to bitmap
  UINT uStartScan,          // starting scan line
  UINT cScanLines,          // number of scan lines
  CONST VOID *lpvBits,      // array of bitmap bits
  CONST BITMAPINFO *lpbmi,  // address of structure with bitmap data
  UINT fuColorUse           // type of color indexes to use
);
 
int SetDIBitsToDevice(
  HDC hdc,              // handle to device context
  int XDest,            // x-coordinate of upper-left corner of 
                        // dest. rect.
  int YDest,            // y-coordinate of upper-left corner of 
                        // dest. rect.
  DWORD dwWidth,        // source rectangle width
  DWORD dwHeight,       // source rectangle height
  int XSrc,             // x-coordinate of lower-left corner of 
                        // source rect.
  int YSrc,             // y-coordinate of lower-left corner of 
                        // source rect.
  UINT uStartScan,      // first scan line in array
  UINT cScanLines,      // number of scan lines
  CONST VOID *lpvBits,  // address of array with DIB bits
  CONST BITMAPINFO *lpbmi,  // address of structure with bitmap info.
  UINT fuColorUse       // RGB or palette indexes
);
 
BOOL SetDlgItemInt(
  HWND hDlg,       // handle of dialog box
  int nIDDlgItem,  // identifier of control
  UINT uValue,     // value to set
  BOOL bSigned     // signed or unsigned indicator
);
 
BOOL SetDlgItemText(
  HWND hDlg,         // handle of dialog box
  int nIDDlgItem,    // identifier of control
  LPCTSTR lpString   // text to set
);
 
BOOL SetDoubleClickTime(
  UINT uInterval   // double-click interval
);
 
BOOL SetEndOfFile(
  HANDLE hFile   // handle of file whose EOF is to be set
);
 
HENHMETAFILE SetEnhMetaFileBits(
  UINT cbBuffer,      // buffer size
  CONST BYTE *lpData  // buffer that contains enhanced metafile data
);
 
DWORD SetEntriesInAccessList(
  ULONG cEntries,      // Number of entries in the entry list
  PACTRL_ACCESS_ENTRY pAccessEntryList,
                       // array of access-control entry information
  ACCESS_MODE AccessMode,  // merge, replace, or revoke trustee 
                           // access
  LPCTSTR lpProperty,  // GUID string of a property
  PACTRL_ACCESS pOldList,  // pointer to the old access-control list
  PACTRL_ACCESS *ppNewList
                       // receives a pointer to the new list
);
 
DWORD SetEntriesInAcl(
  ULONG cCountOfExplicitEntries,
                 // number of entries in the list
  PEXPLICIT_ACCESS pListOfExplicitEntries,
                 // pointer to list of entries with new access data
  PACL OldAcl,   // pointer to the original ACL
  PACL *NewAcl   // receives a pointer to the new ACL
);
 
DWORD SetEntriesInAuditList(
  ULONG cEntries,      // Number of entries in the entry list
  PACTRL_ACCESS_ENTRY pAccessEntryList,
                       // array of audit-control entry information
  ACCESS_MODE AccessMode,  //
  LPCTSTR lpProperty,  // GUID string of a property
  PACTRL_AUDIT pOldList,
                       // pointer to the old audit-control list
  PACTRL_AUDIT *ppNewList  // receives a pointer to the new list
);
 
BOOL SetEnvironmentVariable(
  LPCTSTR lpName,  // address of environment variable name
  LPCTSTR lpValue  // address of new value for variable
);
 
UINT SetErrorMode(
  UINT uMode   // bit flags specifying the process error mode
);
 
BOOL SetEvent(
  HANDLE hEvent   // handle to event object
);
 
VOID SetFileApisToANSI(VOID);
 
VOID SetFileApisToOEM(VOID);
 
BOOL SetFileAttributes(
  LPCTSTR lpFileName,  // pointer to filename
  DWORD dwFileAttributes   // attributes to set
);
 
DWORD SetFilePointer(
  HANDLE hFile,          // handle of file
  LONG lDistanceToMove,  // number of bytes to move file pointer
  PLONG lpDistanceToMoveHigh,
                         // pointer to high-order DWORD of 
                         // distance to move
  DWORD dwMoveMethod     // how to move
);
 
BOOL SetFileSecurity(
  LPCTSTR lpFileName,  // address of string for filename
  SECURITY_INFORMATION SecurityInformation,
                       // type of information to set
  PSECURITY_DESCRIPTOR pSecurityDescriptor 
                       // address of security descriptor
);
 
BOOL SetFileTime(
  HANDLE hFile,                      // handle to the file
  CONST FILETIME *lpCreationTime,    // time the file was created
  CONST FILETIME *lpLastAccessTime,  // time the file was last 
                                     // accessed
  CONST FILETIME *lpLastWriteTime    // time the file was last written
);
 
HWND SetFocus(
  HWND hWnd   // handle to window to receive focus
);
 
BOOL SetForegroundWindow(
  HWND hWnd   // handle to window to bring to foreground
);
 
BOOL SetForm(
  HANDLE hPrinter,  // handle to printer object
  LPTSTR pFormName, // address of form name
  DWORD Level,      // structure level
  LPBYTE pForm      // address of structure array
);
 
int SetGraphicsMode(
  HDC hdc,    // handle of the device context
  int iMode   // graphics mode
);
 
UINT SetHandleCount(
  UINT uNumber   // number of file handles needed
);
 
BOOL SetHandleInformation(
  HANDLE hObject,  // handle to an object
  DWORD dwMask,    // specifies flags to change
  DWORD dwFlags    // specifies new values for flags
);
 
int WINAPI SetICMMode(
  HDC hDC,
  int iEnableICM
);
 
BOOL WINAPI SetICMProfile(
  HDC hDC, 
  LPTSTR lpFileName
);
 
BOOL SetImageConfigInformation(
  IN PLOADED_IMAGE LoadedImage,                               
  IN OUT PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation  
);
 
BOOL SetInformationJobObject(
  HANDLE hJob,
  JOBOBJECTINFOCLASS JobObjectInformationClass,
  LPVOID lpJobObjectInformation,
  DWORD cbJobObjectInformationLength
);
 
BOOL SetJob(
  HANDLE hPrinter,  // handle to printer object
  DWORD JobId,      // print job identifier
  DWORD Level,      // specifies type of job information structure
  LPBYTE  pJob,     // pointer to job information structure
  DWORD Command     // job command value
);
 
BOOL SetKernelObjectSecurity(
  HANDLE Handle,  // handle of object
  SECURITY_INFORMATION SecurityInformation,
                  // type of information to set
  PSECURITY_DESCRIPTOR SecurityDescriptor 
                  // address of security descriptor
);
 
BOOL SetKeyboardState(
  LPBYTE lpKeyState   // array with virtual-key codes
);
 
VOID SetLastError(
  DWORD dwErrCode   // per-thread error code
);
 
VOID SetLastErrorEx(
  DWORD dwErrCode,  // per-thread error code
  DWORD dwType      // error type
);
 
BOOL SetLocaleInfo(
  LCID Locale,       // locale identifier
  LCTYPE LCType,     // type of information to set
  LPCTSTR lpLCData   // pointer to information to set
);
 
BOOL SetLocalTime(
  CONST SYSTEMTIME *lpSystemTime   // address of local time to set
);
 
BOOL SetMailslotInfo(
  HANDLE hMailslot,    // mailslot handle
  DWORD lReadTimeout   // read time-out
);
 
int SetMapMode(
  HDC hdc,        // handle of device context
  int fnMapMode   // new mapping mode
);
 
DWORD SetMapperFlags(
  HDC hdc,       // handle to device context
  DWORD dwFlag   // font-mapper flag
);
 
BOOL SetMenu(
  HWND hWnd,  // handle to window
  HMENU hMenu // handle to menu
);
 
BOOL SetMenuDefaultItem(
  HMENU hMenu,  
  UINT uItem,   
  UINT fByPos   
);
 
BOOL SetMenuItemBitmaps(
  HMENU hMenu,            // handle to menu
  UINT uPosition,         // menu item to receive new bitmaps
  UINT uFlags,            // menu item flags
  HBITMAP hBitmapUnchecked,  // handle to unchecked bitmap
  HBITMAP hBitmapChecked  // handle to checked bitmap
);
 
BOOL SetMenuItemInfo(
  HMENU hMenu,          
  UINT uItem,           
  BOOL fByPosition,     
  LPMENUITEMINFO lpmii  
);
 
LPARAM SetMessageExtraInfo(
  LPARAM lParam  // application-defined 32-bit value
);
 
BOOL SetMessageWaitingIndicator(
  HANDLE hIndicator,  // application-defined 32-bit value
  ULONG cmsg          // number of messages waiting
);
 
HMETAFILE SetMetaFileBitsEx(
  UINT nSize,          // size of Windows-format metafile
  CONST BYTE *lpData   // pointer to metafile data
);
 
int SetMetaRgn(
  HDC hdc   // handle of device context
);
 
BOOL SetMiterLimit(
  HDC hdc,            // handle to device context
  FLOAT eNewLimit,    // new miter limit
  PFLOAT peOldLimit   // previous miter limit
);
 
BOOL SetNamedPipeHandleState(
  HANDLE hNamedPipe,             // handle to named pipe
  LPDWORD lpMode,                // pointer to new pipe mode
  LPDWORD lpMaxCollectionCount,  // pointer to maximum collection count
  LPDWORD lpCollectDataTimeout   // pointer to time-out value
);
 
DWORD SetNamedSecurityInfo(
  LPTSTR pObjectName,  // name of the object
  SE_OBJECT_TYPE ObjectType,
                       // type of object
  SECURITY_INFORMATION SecurityInfo, 
                       // type of security information to set
  PSID psidOwner,      // pointer to the new owner SID
  PSID psidGroup,      // pointer to the new primary group SID
  PACL pDacl,          // pointer to the new DACL
  PACL pSacl           // pointer to the new SACL
);
 
DWORD SetNamedSecurityInfoEx(
  LPCTSTR lpObject,           // name of the object
  SE_OBJECT_TYPE ObjectType,  // type of object
  SECURITY_INFORMATION SecurityInfo,
                             // type of security information to set
  LPCTSTR lpProvider,        // name of provider to handle request
  PACTRL_ACCESS pAccessList,  // pointer to the DACL information
  PACTRL_AUDIT pAuditList,  // pointer to the SACL information
  LPTSTR lpOwner,           // name of the object's owner
  LPTSTR lpGroup,           // name of the object's primary group
  PACTRL_OVERLAPPED pOverlapped
                            // pointer to a structure for 
                            // asynchronous operation
);
 
UINT SetPaletteEntries(
  HPALETTE hpal,             // handle of logical palette
  UINT iStart,               // index of first entry to set
  UINT cEntries,             // number of entries to set
  CONST PALETTEENTRY *lppe   // address of array of structures
);
 
HWND SetParent(
  HWND hWndChild,      // handle to window whose parent is changing
  HWND hWndNewParent   // handle to new parent window
);
 
COLORREF SetPixel(
  HDC hdc,           // handle to device context
  int X,             // x-coordinate of pixel
  int Y,             // y-coordinate of pixel
  COLORREF crColor   // pixel color
);
 
BOOL SetPixelV(
  HDC hdc,           // handle to device context
  int X,             // x-coordinate of pixel
  int Y,             // y-coordinate of pixel
  COLORREF crColor   // new pixel color
);
 
int SetPolyFillMode(
  HDC hdc,            // handle to device context
  int iPolyFillMode   // polygon fill mode
);
 
BOOL SetPort(
  LPTSTR pName,      // pointer to a printer server name
  LPTSTR pPortName,  // pointer to a printer port name
  DWORD dwLevel,     // version of PORT_INFO_* structure
  LPBYTE pPortInfo   // pointer to a PORT_INFO_* structure
);
 
BOOL SetPrinter(
  HANDLE hPrinter,  // handle to printer object
  DWORD Level,      // structure level
  LPBYTE pPrinter,  // pointer to array containing printer data
  DWORD Command     // printer-state command
);
 
DWORD SetPrinterData(
  HANDLE hPrinter,    // handle to a printer or print server
  LPTSTR pValueName,  // string that identifies the data to set
  DWORD Type,         // specifies the type of data
  LPBYTE pData,       // pointer to the configuration data buffer
  DWORD cbData        // size, in bytes, of buffer
);
 
DWORD SetPrinterDataEx(
  HANDLE hPrinter,     // handle to printer or print server
  LPCTSTR pKeyName,    // name of registry key
  LPCTSTR pValueName,  // name of registry value
  DWORD Type,          // type of data stored in registry value
  LPBYTE pData,        // pointer to configuration data
  DWORD cbData         // size, in bytes, of configuration data
);
 
BOOL SetPriorityClass(
  HANDLE hProcess,        // handle to the process
  DWORD dwPriorityClass   // priority class value
);
 
BOOL SetPrivateObjectSecurity(
  SECURITY_INFORMATION SecurityInformation,     // type of security
                                                // information
  PSECURITY_DESCRIPTOR ModificationDescriptor,  // address of SD to 
                                                // apply to object
  PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,  
                                        // address of object's SD
  PGENERIC_MAPPING GenericMapping,      // address of access-mapping 
                                        // structure 
  HANDLE Token                          // handle of client access token
);
 
BOOL SetPrivateObjectSecurityEx (
  SECURITY_INFORMATION SecurityInformation, 
                            // type of security information
  PSECURITY_DESCRIPTOR ModificationDescriptor, 
                            // security descriptor with new information
  PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor, 
                            // object's security descriptor
  ULONG AutoInheritFlags,   // flags that control inheritance of ACEs
  PGENERIC_MAPPING GenericMapping,  // map generic to specific rights
  HANDLE Token                      // handle of client access token
);
 
BOOL SetProcessAffinityMask(
  HANDLE hProcess,             // handle to process
  DWORD dwProcessAffinityMask  // process affinity mask
);
 
BOOL SetProcessPriorityBoost(
  HANDLE hProcess,           // handle to process
  BOOL DisablePriorityBoost  // priority boost control state
);
 
BOOL SetProcessShutdownParameters(
  DWORD dwLevel,  // shutdown priority
  DWORD dwFlags   // shutdown flags
);
 
BOOL SetProcessWindowStation(
  HWINSTA hWinSta  // handle to window station to assign to this process
);
 
BOOL SetProcessWorkingSetSize(
  HANDLE hProcess,                // handle to the process of interest
  DWORD dwMinimumWorkingSetSize,  // specifies minimum working set size
  DWORD dwMaximumWorkingSetSize   // specifies maximum working set size
);
 
BOOL SetProp(
  HWND hWnd,         // handle of window
  LPCTSTR lpString,  // atom or address of string
  HANDLE hData       // handle of data
);
 
BOOL SetRect(
  LPRECT lprc, // pointer to structure with rectangle to set
  int xLeft,   // left side
  int yTop,    // top side
  int xRight,  // right side
  int yBottom  // bottom side
);
 
BOOL SetRectEmpty(
  LPRECT lprc   // pointer to structure with rectangle set to empty
);
 
BOOL SetRectRgn(
  HRGN hrgn,       // handle to region
  int nLeftRect,   // x-coordinate of upper-left corner of rectangle
  int nTopRect,    // y-coordinate of upper-left corner of rectangle
  int nRightRect,  // x-coordinate of lower-right corner of rectangle
  int nBottomRect  // y-coordinate of lower-right corner of rectangle
);
 
int SetROP2(
  HDC hdc,         // handle of device context
  int fnDrawMode   // drawing mode
);
 
int SetScrollInfo(
  HWND hwnd,    // handle to window with scroll bar
  int fnBar,    // scroll bar flag
  LPSCROLLINFO lpsi,
                // pointer to structure with scroll parameters
  BOOL fRedraw  // redraw flag
);
 
int SetScrollPos(
  HWND hWnd,     // handle to window with scroll bar
  int nBar,      // scroll bar flag
  int nPos,      // new position of scroll box
  BOOL bRedraw   // redraw flag
);
 
BOOL SetScrollRange(
  HWND hWnd,    // handle to window with scroll bar
  int nBar,     // scroll bar flag
  int nMinPos,  // minimum scrolling position
  int nMaxPos,  // maximum scrolling position
  BOOL bRedraw  // redraw flag
);
 
BOOL SetSecurityDescriptorControl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,    // security descriptor
  SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,  // bits to set
  SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet // new control bits 
);
 
BOOL SetSecurityDescriptorDacl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                        // address of security descriptor
  BOOL bDaclPresent,    // flag for presence of discretionary ACL
  PACL pDacl,           // address of discretionary ACL
  BOOL bDaclDefaulted   // flag for default discretionary ACL
);
 
BOOL SetSecurityDescriptorGroup(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                         // address of security descriptor
  PSID pGroup,           // address of SID for group
  BOOL bGroupDefaulted   // flag for default
);
 
BOOL SetSecurityDescriptorOwner(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                         // address of security descriptor
  PSID pOwner,           // address of SID for owner
  BOOL bOwnerDefaulted   // flag for default
);
 
BOOL SetSecurityDescriptorSacl(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
                        // address of security descriptor
  BOOL bSaclPresent,    // flag for presence of system ACL
  PACL pSacl,           // address of system ACL
  BOOL bSaclDefaulted   // flag for default system ACL
);
 
DWORD SetSecurityInfo(
  HANDLE handle,  // handle to the object
  SE_OBJECT_TYPE ObjectType,
                  // type of object
  SECURITY_INFORMATION SecurityInfo, 
                  // type of security information to set
  PSID psidOwner, // pointer to the new owner SID
  PSID psidGroup, // pointer to the new primary group SID
  PACL pDacl,     // pointer to the new DACL
  PACL pSacl      // pointer to the new SACL
);
 
DWORD SetSecurityInfoEx(
  HANDLE hObject,           // handle to the object
  SE_OBJECT_TYPE ObjectType,  // type of object
  SECURITY_INFORMATION SecurityInfo,
                            // type of security information to set
  LPCTSTR lpProvider,       // name of provider to handle request
  PACTRL_ACCESS pAccessList,  // pointer to access-control 
                              // information
  PACTRL_AUDIT pAuditList,  // pointer to audit-control information
  LPTSTR lpOwner,           // name of the object's owner
  LPTSTR lpGroup,           // name of the object's primary group
  PACTRL_OVERLAPPED pOverlapped
                            // pointer to a structure for 
                            // asynchronous operation
);
 
BOOL SetServiceBits(
  SERVICE_STATUS_HANDLE hServiceStatus,
                    // service status handle
  DWORD dwServiceBits,
                    // service type bits to set or clear
  BOOL bSetBitsOn,  // flag to set or clear the service type bits
  BOOL bUpdateImmediately
                    // flag to announce server type immediately
);
 
BOOL SetServiceObjectSecurity(
  SC_HANDLE hService,  // handle of service
  SECURITY_INFORMATION dwSecurityInformation,
                       // type of security information requested
  PSECURITY_DESCRIPTOR lpSecurityDescriptor 
                       // address of security descriptor
);
 
BOOL SetServiceStatus(
  SERVICE_STATUS_HANDLE hServiceStatus~,
                                     // service status handle
  LPSERVICE_STATUS lpServiceStatus   // address of status structure
);
 
BOOL WINAPI SetStandardColorSpaceProfile(
  PCTSTR pMachineName,
  DWORD dwProfileID,
  PCSTR pProfilename
);
 
BOOL SetStdHandle(
  DWORD nStdHandle,  // input, output, or error device
  HANDLE hHandle     // handle to be a standard handle
);
 
int SetStretchBltMode(
  HDC hdc,           // handle to device context
  int iStretchMode   // bitmap stretching mode
);
 
BOOL WINAPI SetSysColors(
  int cElements,                 // number of elements to change
  CONST INT *lpaElements,        // address of array of elements
  CONST COLORREF *lpaRgbValues   // address of array of RGB values
);
 
BOOL SetSystemCursor (
  HCURSOR hcur,  // cursor to be set as a system cursor
  DWORD id       // identifier of the system cursor to replace
);
 
UINT SetSystemPaletteUse(
  HDC hdc,      // handle of device context
  UINT uUsage   // palette-usage flag
);
 
BOOL SetSystemPowerState(
  BOOL fSuspend,  
  BOOL fForce     
);
 
BOOL SetSystemTime(
  CONST SYSTEMTIME *lpSystemTime   // address of system time to set
);
 
BOOL SetSystemTimeAdjustment(
  DWORD dwTimeAdjustment,  // size, in 100-nanosecond units, of a 
                           // periodic time adjustment
  BOOL bTimeAdjustmentDisabled
                           // whether periodic time adjustment is to 
                           // be disabled or enabled
);
 
DWORD SetTapeParameters(
  HANDLE hDevice,     // handle of open device
  DWORD dwOperation,  // type of information to set
  LPVOID lpTapeInformation 
                      // address of buffer with information to set
);
 
DWORD SetTapePosition(
  HANDLE hDevice,          // handle of open device
  DWORD dwPositionMethod,  // type of positioning to perform
  DWORD dwPartition,       // new tape partition
  DWORD dwOffsetLow,       // low-order 32 bits of tape position
  DWORD dwOffsetHigh,      // high-order 32 bits of tape position
  BOOL bImmediate          // return after operation begins
);
 
UINT SetTextAlign(
  HDC hdc,     // handle to device context
  UINT fMode   // text-alignment flag
);
 
int SetTextCharacterExtra(
  HDC hdc,         // handle to device context
  int nCharExtra   // extra-space value
);
 
COLORREF SetTextColor(
  HDC hdc,           // handle to device context
  COLORREF crColor   // text color
);
 
BOOL SetTextJustification(
  HDC hdc,          // handle to device context
  int nBreakExtra,  // length of extra space, in logical units
  int nBreakCount   // count of space characters in line of text
);
 
DWORD SetThreadAffinityMask (
  HANDLE hThread,             // handle to the thread of interest
  DWORD dwThreadAffinityMask  // a thread affinity mask
);
 
BOOL SetThreadContext(
  HANDLE hThread,            // handle to thread with context
  CONST CONTEXT *lpContext   // address of context structure
);
 
BOOL SetThreadDesktop(
  HDESK hDesktop  // handle to the desktop to assign to this thread
);
 
EXECUTION_STATE SetThreadExecutionState(
  EXECUTION_STATE esFlags  // execution requirements
);
 
DWORD SetThreadIdealProcessor(
  HANDLE hThread,         // handle to the thread
  DWORD dwIdealProcessor  // ideal processor number
);
 
BOOL SetThreadLocale (
  LCID Locale   // locale identifier
);
 
BOOL SetThreadPriority(
  HANDLE hThread, // handle to the thread
  int nPriority   // thread priority level
);
 
BOOL SetThreadPriorityBoost(
  HANDLE hThread,            // handle to thread
  BOOL DisablePriorityBoost  // priority boost control state
);
 
BOOL SetThreadToken(
  PHANDLE Thread,  // points to a handle to the thread
  HANDLE Token     // handle to the impersonation token
);
 
UINT SetTimer(
  HWND hWnd,              // handle of window for timer messages
  UINT nIDEvent,          // timer identifier
  UINT uElapse,           // time-out value
  TIMERPROC lpTimerFunc   // address of timer procedure
);
 
BOOL SetTimeZoneInformation(
  CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation   // address of 
                                                       // time-zone 
                                                       // settings
);
 
BOOL SetTokenInformation(
  HANDLE TokenHandle,            // handle of access token
  TOKEN_INFORMATION_CLASS TokenInformationClass,
                                 // type of information to set
  LPVOID TokenInformation,       // address of information to set
  DWORD TokenInformationLength   // size of information buffer
);
 
LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(
  LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter 
                                   // exception filter function  
);
 
BOOL WINAPI SetupColorMatching(
  PCOLORMATCHSETUP pcms
);
 
BOOL SetupComm(
  HANDLE hFile,     // handle to communications device
  DWORD dwInQueue,  // size of input buffer
  DWORD dwOutQueue  // size of output buffer
);
 
UINT CALLBACK SetupHookProc(
  HWND hdlg,      // handle to the dialog box window
  UINT uiMsg,     // message identifier
  WPARAM wParam,  // message parameter
  LPARAM lParam   // message parameter
);
 
BOOL SetUserObjectInformation(
  HANDLE hObj,  // handle to the object for which to set information
  int nIndex,   // type of information to set
  PVOID pvInfo, // pointer to a buffer that contains the information
  DWORD nLength // size, in bytes, of pvInfo buffer
);
 
BOOL SetUserObjectSecurity(
  HANDLE hObj,                // handle of user object
  PSECURITY_INFORMATION pSIRequested,
                              // address of security information
  PSECURITY_DESCRIPTOR pSD    // address of security descriptor
);
 
BOOL SetViewportExtEx(
  HDC hdc,       // handle of device context
  int nXExtent,  // new horizontal viewport extent
  int nYExtent,  // new vertical viewport extent
  LPSIZE lpSize  // original viewport extent
);
 
BOOL SetViewportOrgEx(
  HDC hdc,  // handle of device context
  int X,    // new x-coordinate of viewport origin
  int Y,    // new y-coordinate of viewport origin
  LPPOINT lpPoint 
            // address of structure receiving original origin
);
 
BOOL SetVolumeLabel(
  LPCTSTR lpRootPathName,  // pointer to name of root directory for 
                           // volume
  LPCTSTR lpVolumeName   // name for the volume
);
 
BOOL SetWaitableTimer(
  HANDLE hTimer,                          // handle to a timer object
  const LARGE_INTEGER *pDueTime,          // when timer will become signaled
  LONG lPeriod,                           // periodic timer interval
  PTIMERAPCROUTINE pfnCompletionRoutine,  // completion routine
  LPVOID lpArgToCompletionRoutine,        // data for completion routine
  BOOL fResume                            // flag for resume state
);
 
BOOL SetWindowExtEx(
  HDC hdc,       // handle of device context
  int nXExtent,  // new horizontal window extent
  int nYExtent,  // new vertical window extent
  LPSIZE lpSize  // original window extent
);
 
LONG SetWindowLong(
  HWND hWnd,       // handle of window
  int nIndex,      // offset of value to set
  LONG dwNewLong   // new value
);
 
BOOL SetWindowOrgEx(
  HDC hdc,  // handle of device context
  int X,    // new x-coordinate of window origin
  int Y,    // new y-coordinate of window origin
  LPPOINT lpPoint 
            // address of structure receiving original origin
);
 
BOOL SetWindowPlacement(
  HWND hWnd,                      // handle to window
  CONST WINDOWPLACEMENT *lpwndpl  // address of structure with position data
);
 
BOOL SetWindowPos(
  HWND hWnd,             // handle to window
  HWND hWndInsertAfter,  // placement-order handle
  int X,                 // horizontal position
  int Y,                 // vertical position
  int cx,                // width
  int cy,                // height
  UINT uFlags            // window-positioning flags
);
 
int SetWindowRgn(
  HWND hWnd,     // handle to window whose window region is to be set
  HRGN hRgn,     // handle to region
  BOOL bRedraw   // window redraw flag
);
 
HHOOK SetWindowsHookEx(
  int idHook,        // type of hook to install
  HOOKPROC lpfn,     // address of hook procedure
  HINSTANCE hMod,    // handle to application instance
  DWORD dwThreadId   // identity of thread to install hook for
);
 
BOOL SetWindowText(
  HWND hWnd,         // handle to window or control
  LPCTSTR lpString   // address of string
);
 
HENHMETAFILE SetWinMetaFileBits(
  UINT cbBuffer,              // size of buffer
  CONST BYTE *lpbBuffer,      // pointer to metafile data
  HDC hdcRef,                 // handle to reference device context
  CONST METAFILEPICT *lpmfp   // suggested size of metafile picture
);
 
BOOL SetWorldTransform(
  HDC hdc,               // handle of device context
  CONST XFORM *lpXform   // address of transformation data
);
 
LRESULT CALLBACK ShellProc(
  int nCode,      // hook code
  WPARAM wParam,  // event-specific information
  LPARAM lParam   // event-specific information
);
 
BOOL ShowCaret(
  HWND hWnd   // handle of window with caret
);
 
int ShowCursor(
  BOOL bShow   // cursor visibility flag
);
 
BOOL ShowOwnedPopups(
  HWND hWnd,  // handle to window
  BOOL fShow  // window visibility flag
);
 
BOOL ShowScrollBar(
  HWND hWnd,  // handle to window with scroll bar
  int wBar,   // scroll bar flag
  BOOL bShow  // scroll bar visibility flag
);
 
BOOL ShowWindow(
  HWND hWnd,     // handle to window
  int nCmdShow   // show state of window
);
 
BOOL ShowWindowAsync(
  HWND hWnd,    // handle to window
  int nCmdShow  // show state of window
);
 
DWORD SignalObjectAndWait(
  HANDLE hObjectToSignal,  // handle to object to signal
  HANDLE hObjectToWaitOn,  // handle to object to wait for
  DWORD dwMilliseconds,    // time-out interval in milliseconds
  BOOL bAlertable          // alertable flag
);
 
DWORD SizeofResource(
  HMODULE hModule, // resource-module handle
  HRSRC hResInfo   // resource handle
);
 
VOID Sleep(
  DWORD dwMilliseconds   // sleep time in milliseconds
);
 
DWORD SleepEx(
  DWORD dwMilliseconds,  // time-out interval in milliseconds
  BOOL bAlertable        // early completion flag
);
 
SNMPAPI_STATUS CALLBACK SNMPAPI_CALLBACK(
  HSNMP_SESSION hSession,  // handle to the WinSNMP session
  HWND hWnd,               // handle to the notification window
  UINT wMsg,               // window notification message number
  WPARAM wParam,           // type of notification
  LPARAM lParam,           // request identifier of PDU
  LPVOID lpClientData      // optional application-defined data
);
 
SNMPAPI_STATUS SnmpCleanup(VOID);
 
SNMPAPI_STATUS SnmpClose(
  HSNMP_SESSION session    // handle to the session to close 
);
 
SNMPAPI_STATUS SnmpContextToStr(
  HSNMP_CONTEXT context,  // handle to the context 
  smiLPOCTETS string      // pointer to a structure to receive the
                          // context string 
);
 
SNMPAPI_STATUS SnmpCountVbl(
  HSNMP_VBL vbl   // handle to the variable bindings list 
);
 
HSNMP_PDU SnmpCreatePdu(
  HSNMP_SESSION session, // handle to the WinSNMP session 
  smiINT PDU_type,       // PDU type 
  smiINT32 request_id,   // PDU request identifier 
  smiINT error_status,   // valid only for SNMP_PDU_GETBULK requests
  smiINT error_index,    // valid only for SNMP_PDU_GETBULK requests
  HSNMP_VBL varbindlist  // handle to the variable bindings list 
);
 
HSNMP_SESSION SnmpCreateSession(
  HWND hWnd,                    // handle to the notification window
  UINT wMsg,                    // window notification message number
  SNMPAPI_CALLBACK pfnCallBack, // notification callback function
  LPVOID lpClientData           // pointer to callback function data
);
 
HSNMP_VBL SnmpCreateVbl(
  HSNMP_SESSION session,  // handle to the WinSNMP session 
  smiLPCOID name,         // pointer to the variable name 
  smiLPCVALUE value       // pointer to the value to associate
                          // with the variable 
);
 
SNMPAPI_STATUS SnmpDecodeMsg(
  HSNMP_SESSION session,     // handle to the WinSNMP session 
  LPHSNMP_ENTITY srcEntity,  // handle to the source entity 
  LPHSNMP_ENTITY dstEntity,  // handle to the target entity 
  LPHSNMP_CONTEXT context,   // handle to the context 
  LPHSNMP_PDU pdu,           // handle to the PDU 
  smiLPCOCTETS msgBufDesc    // pointer to the message buffer 
);
 
SNMPAPI_STATUS SnmpDeleteVb(
  HSNMP_VBL vbl,   // handle to the variable bindings list 
  smiUINT32 index  // position of the variable binding entry
                   // in the list 
);
 
HSNMP_PDU SnmpDuplicatePdu(
  HSNMP_SESSION session,      // handle to the WinSNMP session 
  HSNMP_PDU PDU               // handle to the PDU to duplicate 
);
 
HSNMP_VBL SnmpDuplicateVbl(
  HSNMP_SESSION session,  // handle to the WinSNMP session 
  HSNMP_VBL vbl           // handle to the variable bindings
                          // list to duplicate 
);
 
SNMPAPI_STATUS SnmpEncodeMsg(
  HSNMP_SESSION session,     // handle to the WinSNMP session 
  HSNMP_ENTITY srcEntity,    // handle to the source entity 
  HSNMP_ENTITY dstEntity,    // handle to the target entity 
  HSNMP_CONTEXT context,     // handle to the context 
  HSNMP_PDU pdu,             // handle to the PDU 
  smiLPOCTETS msgBufDesc     // pointer to the message buffer 
);
 
SNMPAPI_STATUS SnmpEntityToStr(
  HSNMP_ENTITY entity, // handle to the entity 
  smiUINT32 size,      // buffer size, in bytes, for output string 
  LPSTR string         // pointer to the buffer to receive the 
                       // output string 
);
 
VOID SnmpExtensionClose(VOID);
 
BOOL SnmpExtensionInit(
  DWORD dwUptimeReference,                    // see NOTE below
  HANDLE *phSubagentTrapEvent,                // trap event handle
  AsnObjectIdentifier *pFirstSupportedRegion  // first MIB subtree
);
 
BOOL SnmpExtensionInitEx(
  AsnObjectIdentifier *pNextSupportedRegion  // next MIB subtree
);
 
BOOL  SnmpExtensionQuery(
  BYTE bPduType,                  // SNMPv1 PDU request type
  SnmpVarBindList *pVarBindList,  // pointer to variable bindings
  AsnInteger32 *pErrorStatus,     // pointer to SNMPv1 error status
  AsnInteger32 *pErrorIndex       // pointer to the error index
);
 
BOOL SnmpExtensionQueryEx(
  DWORD dwRequestType,           // extension agent request type
  DWORD dwTransactionId,         // identifier of the incoming PDU
  SnmpVarBindList *pVarBindList, // pointer to variable binding list
  AsnOctetString *pContextInfo,  // pointer to context information
  AsnInteger32 *pErrorStatus,    // pointer to SNMPv2 error status
  AsnInteger32 *pErrorIndex      // pointer to the error index
);
 
BOOL SnmpExtensionTrap(
  AsnObjectIdentifier *pEnterpriseOid,  // generating enterprise
  AsnInteger32 *pGenericTrapId,         // generating trap type
  AsnInteger32 *pSpecificTrapId,        // enterprise-specific type
  AsnTimeticks *pTimeStamp,             // time stamp
  SnmpVarBindList *pVarBindList         // variable bindings
);
 
SNMPAPI_STATUS SnmpFreeContext(
  HSNMP_CONTEXT context    // handle to the context to release 
);
 
SNMPAPI_STATUS SnmpFreeDescriptor(
  smiUINT32 syntax,       // data type of target descriptor object
  smiLPOPAQUE descriptor  // pointer to the target descriptor object
);
 
SNMPAPI_STATUS SnmpFreeEntity(
  HSNMP_ENTITY entity   // handle to the entity to release 
);
 
SNMPAPI_STATUS SnmpFreePdu(
  HSNMP_PDU PDU     // handle to the PDU to free 
);
 
SNMPAPI_STATUS SnmpFreeVbl(
  HSNMP_VBL vbl       // handle to the variable bindings list 
);
 
SNMPAPI_STATUS SnmpGetLastError(
  HSNMP_SESSION session     // handle to the WinSNMP session 
);
 
SNMPAPI_STATUS SnmpGetPduData(
  HSNMP_PDU PDU,            // handle to the PDU 
  smiLPINT PDU_type,        // PDU_type field of the PDU 
  smiLPINT32 request_id,    // request_id field of the PDU 
  smiLPINT error_status,    // error_status field of the PDU 
  smiLPINT error_index,     // error_index field of the PDU 
  LPHSNMP_VBL varbindlist   // handle to the variable bindings list 
);
 
SNMPAPI_STATUS SnmpGetRetransmitMode(
  smiLPUINT32 nRetransmitMode  // current retransmission mode 
);
 
SNMPAPI_STATUS SnmpGetRetry(
  HSNMP_ENTITY hEntity,      // destination management entity 
  smiLPUINT32 nPolicyRetry,  // retry count value from the database 
  smiLPUINT32 nActualRetry   // last actual or estimated response
                             // retry count 
);
 
SNMPAPI_STATUS SnmpGetTimeout(
  HSNMP_ENTITY hEntity,          // destination management entity 
  smiLPTIMETICKS nPolicyTimeout, // time-out value from the database
  smiLPTIMETICKS nActualTimeout  // last actual or estimated
                                 // response time 
);
 
SNMPAPI_STATUS SnmpGetTranslateMode(
  smiLPUINT32 nTranslateMode  // current entity/context translation
                              // mode 
);
 
SNMPAPI_STATUS SnmpGetVb(
  HSNMP_VBL vbl,    // handle to the variable bindings list 
  smiUINT32 index,  // position of the variable binding entry
                    // in the list 
  smiLPOID name,    // pointer to the structure to receive the
                    // variable name 
  smiLPVALUE value  // pointer to the structure to receive the
                    // associated value 
);
 
BOOL SnmpMgrClose(
  LPSNMP_MGR_SESSION session  // SNMP session pointer
);
 
BOOL SnmpMgrGetTrap(
  AsnObjectIdentifier *enterprise,   // generating enterprise
  AsnNetworkAddress *IPAddress,      // generating IP address
  AsnInteger *genericTrap,           // generic trap type
  AsnInteger *specificTrap,          // enterprise-specific type
  AsnTimeticks *timeStamp,           // time stamp
  SnmpVarBindList *variableBindings  // variable bindings
);
 
BOOL SnmpMgrOidToStr(
  AsnObjectIdentifier *oid,
                  // object identifier to convert
  LPSTR *string   // string object identifier representation
);
 
LPSNMP_MGR_SESSION SnmpMgrOpen(
  LPSTR lpAgentAddress,    // name and address of target SNMP agent
  LPSTR lpAgentCommunity,  // community for target SNMP agent
  INT nTimeOut,            // communication time-out in milliseconds
  INT nRetries             // communication time-out or retry count
);

SNMPAPI SnmpMgrRequest(
  LPSNMP_MGR_SESSION session,         // SNMP session pointer
  BYTE requestType,                   // Get, GetNext, or Set
  SnmpVarBindList *variableBindings,  // variable bindings
  AsnInteger *errorStatus,            // SNMPv1 error status
  AsnInteger *errorIndex              // error index
);
 
BOOL SnmpMgrStrToOid(
  LPSTR string,             // string to convert
  AsnObjectIdentifier *oid  // object identifier representation
);
 
BOOL SnmpMgrTrapListen(
  HANDLE *phTrapAvailable  // event handle indicating a trap 
                           // is available
);
 
SNMPAPI_STATUS SnmpOidCompare(
  smiLPCOID xOID,      // first object identifier to compare 
  smiLPCOID yOID,      // second object identifier to compare 
  smiUINT32 maxlen,    // maximum length to compare 
  smiLPINT result      // result of comparison 
);
 
SNMPAPI_STATUS SnmpOidCopy(
  smiLPCOID srcOID,      // source object identifier 
  smiLPOID dstOID        // destination object identifier 
);
 
SNMPAPI_STATUS SnmpOidToStr(
  smiLPCOID srcOID,  // object identifier to convert 
  smiUINT32 size,    // buffer size for string 
  LPSTR string       // pointer to buffer for converted string 
                     // object identifier 
);
 
HSNMP_SESSION SnmpOpen(
  HWND hWnd,      // handle to the notification window 
  UINT wMsg       // window notification message number 
);
 
SNMPAPI_STATUS SnmpRecvMsg(
  HSNMP_SESSION session,      // handle to the WinSNMP session 
  LPHSNMP_ENTITY srcEntity,   // handle to the source entity 
  LPHSNMP_ENTITY dstEntity,   // handle to the target entity 
  LPHSNMP_CONTEXT context,    // handle to the context 
  LPHSNMP_PDU PDU             // handle to the PDU 
);
 
SNMPAPI_STATUS SnmpRegister(
  HSNMP_SESSION session,   // handle to the WinSNMP session 
  HSNMP_ENTITY srcEntity,  // handle to the entity that will
                           // receive traps 
  HSNMP_ENTITY dstEntity,  // handle to the entity that will
                           // send traps 
  HSNMP_CONTEXT context,   // handle to the context 
  smiLPCOID notification,  // trap-matching sequence 
  smiUINT32 state          // flag for trap reception 
);
 
SNMPAPI_STATUS SnmpSendMsg(
  HSNMP_SESSION session,      // handle to the WinSNMP session 
  HSNMP_ENTITY srcEntity,     // handle to the source entity 
  HSNMP_ENTITY dstEntity,     // handle to the target entity 
  HSNMP_CONTEXT context,      // handle to the context 
  HSNMP_PDU PDU               // handle to the PDU 
);
 
SNMPAPI_STATUS SnmpSetPduData(
  HSNMP_PDU PDU,                 // handle to the PDU 
  const smiINT *PDU_type,        // pointer to the PDU type 
  const smiINT32 *request_id,    // pointer to the PDU request
                                 // identifier 
  const smiINT *non_repeaters,   // valid only for an
                                 // SNMP_PDU_GETBULK request 
  const smiINT *max_repetitions, // valid only for an
                                 // SNMP_PDU_GETBULK request 
  const HSNMP_VBL *varbindlist   // handle to variable bindings list
);
 
SNMPAPI_STATUS SnmpSetRetransmitMode(
  smiUINT32 nRetransmitMode  // new retransmission mode 
);
 
SNMPAPI_STATUS SnmpSetRetry(
  HSNMP_ENTITY hEntity,    // destination management entity 
  smiUINT32 nPolicyRetry   // new retry count value for database 
);
 
SNMPAPI_STATUS SnmpSetTimeout(
  HSNMP_ENTITY hEntity,        // destination management entity 
  smiTIMETICKS nPolicyTimeout  // new time-out value for database 
);
 
SNMPAPI_STATUS SnmpSetTranslateMode(
  smiUINT32 nTranslateMode  // new entity/context translation mode 
);
 
SNMPAPI_STATUS SnmpSetVb(
  HSNMP_VBL vbl,     // handle to the variable bindings list 
  smiUINT32 index,   // position of the variable binding entry
                     // in the list 
  smiLPCOID name,    // pointer to the variable name portion
                     // of the entry 
  smiLPCVALUE value  // pointer to the variable value portion
                     // of the entry 
);
 
SNMPAPI_STATUS SnmpStartup(
  smiLPUINT32 nMajorVersion,   // major version number of the
                               // WinSNMP API
  smiLPUINT32 nMinorVersion,   // minor version number of the
                               // WinSNMP API
  smiLPUINT32 nLevel,          // level of SNMP the implementation
                               // supports
  smiLPUINT32 nTranslateMode,  // default entity/context translation
                               // mode 
  smiLPUINT32 nRetransmitMode  // default retransmission mode 
);
 
HSNMP_CONTEXT SnmpStrToContext(
  HSNMP_SESSION session,  // handle to the WinSNMP session 
  smiLPCOCTETS string     // pointer to a string structure 
);
 
HSNMP_ENTITY SnmpStrToEntity(
  HSNMP_SESSION session,  // handle to the WinSNMP session 
  LPCSTR string           // pointer to a string that identifies
                          // the entity 
);

SNMPAPI_STATUS SnmpStrToOid(
  LPCSTR string,      // string object identifier to convert 
  smiLPOID dstOID     // object identifier internal representation 
);
 
DWORD SnmpSvcGetUptime(VOID);

VOID SnmpSvcSetLogLevel(
  INT nLogLevel  // level of severity of the event
);
 
VOID SnmpSvcSetLogType(
  INT nLogType  // destination for debug output
);
 
SNMPAPI SnmpUtilAsnAnyCpy(
  AsnAny *pAnyDst,  // destination structure
  AsnAny *pAnySrc   // source structure
);
 
VOID SnmpUtilAsnAnyFree(
  AsnAny *pAny  // pointer to structure to free
);
 
VOID SnmpUtilDbgPrint(
  INT nLogLevel,  // level of severity of event 
  LPSTR szFormat  // pointer to a format string 
);
 
LPVOID SnmpUtilMemAlloc(
  UINT nBytes  // bytes to allocate for object
);
 
VOID SnmpUtilMemFree(
  LPVOID pMem  // pointer to memory object to release
);
 
LPVOID SnmpUtilMemReAlloc(
  LPVOID pMem,  // pointer to memory object
  UINT nBytes   // bytes to allocate
);
 
SNMPAPI SnmpUtilOctetsCmp(
  AsnOctetString *pOctets1,  // first octet string
  AsnOctetString *pOctets2   // second octet string
);
 
SNMPAPI SnmpUtilOctetsCpy(
  AsnOctetString *pOctetsDst,  // destination octet string
  AsnOctetString *pOctetsSrc   // source octet string
);
 
VOID SnmpUtilOctetsFree(
  AsnOctetString *pOctets  // octet string to free
);
 
SNMPAPI SnmpUtilOctetsNCmp(
  AsnOctetString *pOctets1,  // first octet string
  AsnOctetString *pOctets2,  // second octet string
  UINT nChars                // maximum length to compare
);
 
SNMPAPI SnmpUtilOidAppend(
  AsnObjectIdentifier *pOidDst,  // destination object identifier
  AsnObjectIdentifier *pOidSrc   // source object identifier
);
 
SNMPAPI SnmpUtilOidCmp(
  AsnObjectIdentifier *pOid1,  // first object identifier
  AsnObjectIdentifier *pOid2   // second object identifier
);
 
SNMPAPI SnmpUtilOidCpy(
  AsnObjectIdentifier *pOidDst,  // destination object identifier
  AsnObjectIdentifier *pOidSrc   // source object identifier
);
 
VOID SnmpUtilOidFree(
  AsnObjectIdentifier *pOid  // object identifier to free
);
 
SNMPAPI SnmpUtilOidNCmp(
  AsnObjectIdentifier *pOid1,  // first object identifier
  AsnObjectIdentifier *pOid2,  // second object identifier
  UINT nSubIds                 // maximum length to compare
);
 
VOID SnmpUtilPrintAsnAny(
  AsnAny *pAny  // pointer to value to print
);
 
SNMPAPI SnmpUtilVarBindCpy(
  SnmpVarBind *pVbDst,  // destination variable bindings
  SnmpVarBind *pVbSrc   // source variable bindings
);
 
VOID SnmpUtilVarBindFree(
  SnmpVarBind *pVb  // variable binding to free
);
 
SNMPAPI SnmpUtilVarBindListCpy(
  SnmpVarBindList *pVblDst,  // destination variable bindings list
  SnmpVarBindList *pVblSrc   // source variable bindings list
);
 
VOID SnmpUtilVarBindListFree(
  SnmpVarBindList *pVbl  // variable bindings list to free
);
 
LRESULT CALLBACK SoundSentryProc(
  DWORD dwMillisec,  // duration of visual signal
  DWORD fdwEffect    // effect-type flag
);
 
BOOL SplitSymbols(
  IN LPSTR ImageName,    
  IN LPSTR SymbolsPath,  
  OUT LPSTR SymbolFilePath,  
  IN DWORD Flags         
);
 
BOOL StackWalk(
  IN DWORD MachineType,                                          
  IN HANDLE hProcess,                                            
  IN HANDLE hThread,                                             
  IN OUT LPSTACKFRAME StackFrame,                                
  IN OUT LPVOID ContextRecord,                                   
  IN PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine,             
  IN PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,  
  IN PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine,              
  IN PTRANSLATE_ADDRESS_ROUTINE TranslateAddress                 
);
 
int StartDoc(
  HDC hdc,              // handle to device context
  CONST DOCINFO *lpdi   // address of structure with file names
);
 
DWORD StartDocPrinter(
  HANDLE hPrinter,  // handle to printer object
  DWORD Level,      // structure level
  LPBYTE pDocInfo   // address of structure
);
 
int StartPage(
  HDC hDC   // handle to device context
);
 
BOOL StartPagePrinter(
  HANDLE hPrinter   // handle to printer object
);
 
BOOL StartService(
  SC_HANDLE hService,            // handle of service
  DWORD dwNumServiceArgs,        // number of arguments
  LPCTSTR *lpServiceArgVectors   // array of argument strings 
                                 // string pointers
);
 
BOOL StartServiceCtrlDispatcher(
  LPSERVICE_TABLE_ENTRY lpServiceStartTable   // address of service 
                                              // table
);
 
HRESULT StiCreateInstance(
  HINSTANCE hinst,
  DWORD dwVer,
  PSTI *ppSti,
  LPUNKNOWN punkOuter
);
 
BOOL StretchBlt(
  HDC hdcDest,      // handle to destination device context
  int nXOriginDest, // x-coordinate of upper-left corner of dest. rectangle
  int nYOriginDest, // y-coordinate of upper-left corner of dest. rectangle
  int nWidthDest,   // width of destination rectangle
  int nHeightDest,  // height of destination rectangle
  HDC hdcSrc,       // handle to source device context
  int nXOriginSrc,  // x-coordinate of upper-left corner of source rectangle
  int nYOriginSrc,  // y-coordinate of upper-left corner of source rectangle
  int nWidthSrc,    // width of source rectangle
  int nHeightSrc,   // height of source rectangle
  DWORD dwRop       // raster operation code
);
 
int StretchDIBits(
  HDC hdc,                // handle to device context
  int XDest,              // x-coordinate of upper-left corner of dest. rectangle
  int YDest,              // y-coordinate of upper-left corner of dest. rectangle
  int nDestWidth,         // width of destination rectangle
  int nDestHeight,        // height of destination rectangle
  int XSrc,               // x-coordinate of upper-left corner of source rectangle
  int YSrc,               // y-coordinate of upper-left corner of source rectangle
  int nSrcWidth,          // width of source rectangle
  int nSrcHeight,         // height of source rectangle
  CONST VOID *lpBits,            // address of bitmap bits
  CONST BITMAPINFO *lpBitsInfo,  // address of bitmap data
  UINT iUsage,                   // usage flags
  DWORD dwRop                    // raster operation code
);
 
BOOL StrokeAndFillPath(
  HDC hdc   // handle to device context
);
 
BOOL StrokePath(
  HDC hdc   // handle to device context
);
 
BOOL SubtractRect(
  LPRECT lprcDst,        // pointer to destination rectangle
  CONST RECT *lprcSrc1,  // pointer to rectangle to subtract from
  CONST RECT *lprcSrc2   // pointer to rectangle to subtract
);
 
DWORD SuspendThread(
  HANDLE hThread   // handle to the thread
);
 
BOOL SwapMouseButton(
  BOOL fSwap   // reverse or restore buttons
);
 
BOOL SwitchDesktop(
  HDESK hDesktop  // handle to desktop to activate
);
 
VOID SwitchToFiber(
  LPVOID lpFiber  // pointer to fiber to switch to
);
 
BOOL SwitchToThread(VOID);
 
BOOL CALLBACK SymbolRegisteredCallback(
  HANDLE hProcess,     
  ULONG ActionCode,    
  PVOID CallbackData,  
  PVOID UserContext    
);
 
BOOL SymCleanup(
  IN HANDLE hProcess  
);
 
BOOL SymEnumerateModules(
  IN HANDLE hProcess,                                
  IN PSYM_ENUMMODULES_CALLBACK EnumModulesCallback,  
  IN PVOID UserContext                               
);
 
BOOL SymEnumerateSymbols(
  IN HANDLE hProcess,                                
  IN DWORD BaseOfDll,                                
  IN PSYM_ENUMSYMBOLS_CALLBACK EnumSymbolsCallback,  
  IN PVOID UserContext                               
);
 
BOOL CALLBACK SymEnumModulesCallback(
  LPSTR ModuleName, 
  ULONG BaseOfDll,  
  PVOID UserContext 
);
 
BOOL CALLBACK SymEnumSymbolsCallback(
  LPSTR SymbolName,     
  ULONG SymbolAddress,  
  ULONG SymbolSize,     
  PVOID UserContext     
);
 
LPVOID SymFunctionTableAccess(
  IN HANDLE hProcess,  
  IN DWORD AddrBase    
);
 
DWORD SymGetModuleBase(
  IN HANDLE hProcess,  
  IN DWORD dwAddr      
);
 
BOOL SymGetModuleInfo(
  IN HANDLE hProcess,              
  IN DWORD dwAddr,                 
  OUT PIMAGEHLP_MODULE ModuleInfo  
);
 
DWORD SymGetOptions(VOID);

BOOL SymGetSearchPath(
  IN HANDLE hProcess,    
  OUT LPSTR SearchPath,  
  IN DWORD SearchPathLength  
);
 
BOOL SymGetSymFromAddr(
  IN HANDLE hProcess,             
  IN DWORD Address,               
  OUT LPDWORD Displacement,       
  IN OUT PIMAGEHLP_SYMBOL Symbol  
);
 
BOOL SymGetSymFromName(
  IN HANDLE hProcess,          
  IN LPSTR Name,               
  OUT PIMAGEHLP_SYMBOL Symbol  
);
 
BOOL SymGetSymNext(
  IN HANDLE hProcess,             
  IN OUT PIMAGEHLP_SYMBOL Symbol  
);
 
BOOL SymGetSymPrev(
  IN HANDLE hProcess,             
  IN OUT PIMAGEHLP_SYMBOL Symbol  
);
 
BOOL SymInitialize(
  IN HANDLE hProcess,     
  IN LPSTR UserSearchPath,  
  IN BOOL fInvadeProcess  
);
 
BOOL SymLoadModule(
  IN HANDLE hProcess,  
  IN HANDLE hFile,     
  IN LPSTR ImageName,  
  IN LPSTR ModuleName, 
  IN DWORD BaseOfDll,  
  IN DWORD SizeOfDll   
);
 
BOOL SymRegisterCallback(
  IN HANDLE hProcess,                               
  IN PSYMBOL_REGISTERED_CALLBACK CallbackFunction,  
  IN PVOID UserContext                              
);
 
DWORD SymSetOptions(
  IN DWORD SymOptions  
);
 
BOOL SymSetSearchPath(
  IN HANDLE hProcess,  
  IN LPSTR SearchPath  
);
 
BOOL SymUnDName(
  IN PIMAGEHLP_SYMBOL Symbol,  
  IN LPSTR UnDecName,       
  IN DWORD UnDecNameLength  
);
 
BOOL SymUnloadModule(
  IN HANDLE hProcess, 
  IN DWORD BaseOfDll  
);
 
LRESULT CALLBACK SysMsgProc(
  int nCode,      // message flag
  WPARAM wParam,  // undefined
  LPARAM lParam   // address of structure with message data
);
 
BOOL SystemParametersInfo(
  UINT uiAction, // system parameter to query or set
  UINT uiParam,  // depends on action to be taken
  PVOID pvParam, // depends on action to be taken
  UINT fWinIni   // user profile update flag
);
 
BOOL SystemTimeToFileTime(
  CONST SYSTEMTIME *lpSystemTime,
                          // address of system time to convert
  LPFILETIME lpFileTime   // address of buffer for converted file 
                          // time
);
 
BOOL SystemTimeToTzSpecificLocalTime(
  LPTIME_ZONE_INFORMATION lpTimeZoneInformation,
                            // pointer to time zone of interest
  LPSYSTEMTIME lpUniversalTime,
                            // pointer to universal time of interest
  LPSYSTEMTIME lpLocalTime  // pointer to structure to receive local 
                            // time
);
 
LONG TabbedTextOut(
  HDC hDC,                    // handle to device context
  int X,                      // x-coordinate of starting position
  int Y,                      // y-coordinate of starting position
  LPCTSTR lpString,           // pointer to string
  int nCount,                 // number of characters in string
  int nTabPositions,          // number of tabs in array
  LPINT lpnTabStopPositions,  // pointer to array for tab positions
  int nTabOrigin              // x-coordinate for tab expansion
);
 
BOOL TerminateJobObject(
  HANDLE hJob,
  UINT uExitCode
);
 
BOOL TerminateProcess(
  HANDLE hProcess, // handle to the process
  UINT uExitCode   // exit code for the process
);
 
BOOL TerminateThread(
  HANDLE hThread,    // handle to the thread
  DWORD dwExitCode   // exit code for the thread
);
 
BOOL TextOut(
  HDC hdc,           // handle to device context
  int nXStart,       // x-coordinate of starting position
  int nYStart,       // y-coordinate of starting position
  LPCTSTR lpString,  // pointer to string
  int cbString       // number of characters in string
);
 
BOOL WINAPI Thread32First(
  HANDLE hSnapshot,     
  LPTHREADENTRY32 lpte  
);
 
BOOL WINAPI Thread32Next(
  HANDLE hSnapshot,     
  LPTHREADENTRY32 lpte  
);
 
DWORD WINAPI ThreadProc(
  LPVOID lpParameter   // thread data
);
 
WORD WINAPI TileWindows(
  HWND hwndParent,        // handle to parent window
  UINT wHow,              // types of windows not to arrange
  CONST RECT *lpRect,     // rectangle to arrange windows in
  UINT cKids,             // number of windows to arrange
  const HWND FAR *lpKids  // array of window handles
);
 
VOID CALLBACK TimerAPCProc(
  LPVOID lpArgToCompletionRoutine   // data value
  DWORD dwTimerLowValue             // timer low value
  DWORD dwTimerHighValue            // timer high value
);
 
VOID CALLBACK TimerProc(
  HWND hwnd,     // handle of window for timer messages
  UINT uMsg,     // WM_TIMER message
  UINT idEvent,  // timer identifier
  DWORD dwTime   // current system time
);
 
DWORD TlsAlloc(VOID);
 
BOOL TlsFree(
  DWORD dwTlsIndex   // TLS index to free
);
 
LPVOID TlsGetValue(
  DWORD dwTlsIndex   // TLS index to retrieve value for
);
 
BOOL TlsSetValue(
  DWORD dwTlsIndex,  // TLS index to set value for
  LPVOID lpTlsValue  // value to be stored
);
 
int ToAscii(
  UINT uVirtKey,     // virtual-key code
  UINT uScanCode,    // scan code
  PBYTE lpKeyState,  // key-state array
  LPWORD lpChar,     // buffer for translated key
  UINT uFlags        // active-menu flag
);
 
int ToAsciiEx(
  UINT uVirtKey,     // virtual-key code
  UINT uScanCode,    // scan code
  PBYTE lpKeyState,  // key-state array
  LPWORD lpChar,     // buffer for translated key
  UINT uFlags,       // active-menu flag
  HKL dwhkl          // keyboard layout handle
);
 
BOOL WINAPI Toolhelp32ReadProcessMemory(
  DWORD th32ProcessID,         
  LPCVOID lpBaseAddress,       
  LPVOID lpBuffer,             
  DWORD cbRead,                
  LPDWORD lpNumberOfBytesRead  
);
 
int ToUnicode(
  UINT wVirtKey,    // virtual-key code
  UINT wScanCode,   // scan code
  PBYTE lpKeyState, // address of key-state array
  LPWSTR pwszBuff,  // buffer for translated key
  int cchBuff,      // size of translated key buffer
  UINT wFlags       // set of function-conditioning flags
);
 
int ToUnicodeEx(
  UINT wVirtKey,    // virtual-key code
  UINT wScanCode,   // scan code
  PBYTE lpKeyState, // key-state array
  LPWSTR pwszBuff,  // buffer for translated key
  int cchBuff,      // size of translated key buffer
  UINT wFlags,      // set of function-conditioning flags
  HKL dwhkl         // keyboard layout handle
);
 
BOOL TrackMouseEvent(
  LPTRACKMOUSEEVENT lpEventTrack  // pointer to a TRACKMOUSEEVENT 
                                  // structure
);
 
BOOL TrackPopupMenu(
  HMENU hMenu,         // handle to shortcut menu
  UINT uFlags,         // screen-position and mouse-button flags
  int x,               // horizontal position, in screen coordinates
  int y,               // vertical position, in screen coordinates
  int nReserved,       // reserved, must be zero
  HWND hWnd,           // handle to owner window
  CONST RECT *prcRect  // ignored
);
 
BOOL TrackPopupMenuEx(
  HMENU hmenu,       
  UINT fuFlags,      
  int x,             
  int y,             
  HWND hwnd,         
  LPTPMPARAMS lptpm  
);
 
BOOL TransactNamedPipe(
  HANDLE hNamedPipe,          // handle to named pipe
  LPVOID lpInBuffer,          // pointer to write buffer
  DWORD nInBufferSize,        // size of the write buffer, in bytes
  LPVOID lpOutBuffer,         // pointer to read buffer
  DWORD nOutBufferSize,       // size of read buffer, in bytes
  LPDWORD lpBytesRead,        // pointer to variable for bytes read
  LPOVERLAPPED lpOverlapped   // pointer to overlapped structure
);
 
int TranslateAccelerator(
  HWND hWnd,         // handle to destination window
  HACCEL hAccTable,  // handle to accelerator table
  LPMSG lpMsg        // address of structure with message
);
 
BOOL WINAPI TranslateBitmapBits(
  HTRANSFORM hColorTransform,
  PVOID pSrcBits,
  BMFORMAT bmInput,
  DWORD dwWidth,
  DWORD dwHeight,
  DWORD dwInputStride,
  PVOID pDestBits,
  BMFORMAT bmOutput,
  DWORD dwOutputStride,
  PBMCALLBACKFN pfnCallback,
  ULONG ulCallbackData
);
 
UINT TranslateCharsetInfo(
  DWORD FAR *lpSrc,     
  LPCHARSETINFO lpCs,   
  DWORD dwFlags         
);
 
BOOL WINAPI TranslateColors(
  HTRANSFORM hColorTransform,
  PCOLOR paInputColors,
  DWORD nColors, 
  COLORTYPE ctInput,
  PCOLOR paOutputColors,
  COLORTYPE ctOutput
);
 
BOOL TranslateMDISysAccel(
  HWND hWndClient,  // handle to MDI client window
  LPMSG lpMsg       // address of structure with message data
);
 
BOOL TranslateMessage(
  CONST MSG *lpMsg   // address of structure with message
);
 
BOOL TransmitCommChar(
  HANDLE hFile,  // handle to communications device
  char cChar     // character to transmit
);
 
BOOL TransparentBlt(
  HDC hdcDest,
  int nXOriginDest,
  int nYOriginDest,
  int nWidthDest,
  int hHeightDest,
  HDC hdcSrc,
  int nXOriginSrc,
  int nYOriginSrc,
  int nWidthSrc,
  int nHeightSrc,
  UINT crTransparent
);
 
DWORD TrusteeAccessToObject(
  LPCTSTR lpObject,   // name of the object
  SE_OBJECT_TYPE ObjectType,
                      // type of object
  LPCTSTR lpProvider, // name of provider to handle request
  PTRUSTEE pTrustee,  // pointer to trustee information
  ULONG cEntries,     // number of entries in trustee access list
  PTRUSTEE_ACCESS pTrusteeAccess
                      // pointer to a trustee access list
);
 
BOOL TryEnterCriticalSection(
  LPCRITICAL_SECTION lpCriticalSection  // pointer to critical 
                                        // section object
);
 
ULONGLONG UInt32x32To64(
  DWORD Multiplier,    // the first unsigned 32-bit integer 
  DWORD Multiplicand   // the second unsigned 32-bit integer 
);
 
DWORD UnDecorateSymbolName(
  IN LPSTR DecoratedName,  
  OUT LPSTR UnDecoratedName,  
  IN DWORD UndecoratedLength,  
  IN DWORD Flags           
);
 
LONG UnhandledExceptionFilter(
  STRUCT _EXCEPTION_POINTERS *ExceptionInfo   // address of 
                                              // exception info
);
 
BOOL UnhookWindowsHookEx(
  HHOOK hhk   // handle to hook procedure to remove
);
 
BOOL WINAPI UninstallColorProfile(
  PCTSTR pMachineName,
  PCTSTR  pProfileName,
  BOOL bDelete
);
 
BOOL UnionRect(
  LPRECT lprcDst,        // pointer to structure for union
  CONST RECT *lprcSrc1,  // pointer to structure with first rectangle
  CONST RECT *lprcSrc2   // pointer to structure with second rectangle
);
 
BOOL UnloadKeyboardLayout(
  HKL hkl   // handle to keyboard layout
);
 
BOOL UnlockFile(
  HANDLE hFile,           // handle of file to unlock
  DWORD dwFileOffsetLow,  // low-order word of lock region offset
  DWORD dwFileOffsetHigh,  // high-order word of lock region offset
  DWORD nNumberOfBytesToUnlockLow,
                          // low-order word of length to unlock
  DWORD nNumberOfBytesToUnlockHigh 
                          // high-order word of length to unlock
);
 
BOOL UnlockFileEx(
  HANDLE hFile,      // handle of file to unlock
  DWORD dwReserved,  // reserved, must be set to zero
  DWORD nNumberOfBytesToUnlockLow,
                     // low order 32-bits of length to unlock
  DWORD nNumberOfBytesToUnlockHigh,
                     // high order 32-bits of length to unlock
  LPOVERLAPPED lpOverlapped 
                     // addr. of struct. with unlock region start 
                     // offset
);
 
BOOL UnlockServiceDatabase(
  SC_LOCK ScLock   // service control manager database lock to be 
                   // released
);
 
BOOL UnMapAndLoad(
  IN PLOADED_IMAGE LoadedImage  
);
 
BOOL UnmapDebugInformation(
  IN PIMAGE_DEBUG_INFORMATION DebugInfo  
);
 
BOOL UnmapViewOfFile(
  LPCVOID lpBaseAddress   // address where mapped view begins
);
 
BOOL UnmapViewOfFileVlm(
  PVOID64 lpBaseAddress   // address of region to be unmapped 
);
 
BOOL UnpackDDElParam(
  UINT msg,     // posted DDE message
  LONG lParam,  // lParam of posted DDE message
  PUINT puiLo,  // address of low-order word of lParam
  PUINT puiHi   // address of high-order word of lParam
);
 
BOOL UnrealizeObject(
  HGDIOBJ hgdiobj   // logical palette handle
);
 
BOOL UnregisterClass(
  LPCTSTR lpClassName,  // address of class name string
  HINSTANCE hInstance   // handle of application instance
);
 
BOOL WINAPI UnregisterCMM(
  PCTSTR pMachineName,
  DWORD cmmID
);
 
BOOL UnregisterHotKey(
  HWND hWnd,  // window associated with hot key
  int id      // identifier of hot key
);
 
BOOL UpdateColors(
  HDC hdc   // handle of device context
);
 
BOOL UpdateDebugInfoFile(
  IN LPSTR ImageFileName,             
  IN LPSTR SymbolPath,                
  OUT LPSTR DebugFilePath,            
  IN OUT PIMAGE_NT_HEADERS NtHeaders  
);
 
BOOL UpdateDebugInfoFileEx(
  IN LPSTR ImageFileName,              
  IN LPSTR SymbolPath,                 
  OUT LPSTR DebugFilePath,             
  IN OUT PIMAGE_NT_HEADERS NtHeaders,  
  IN DWORD OldChecksum                 
);
 
BOOL UpdateResource(
  HANDLE hUpdate, // update-file handle
  LPCTSTR lpType, // address of resource type to update
  LPCTSTR lpName, // address of resource name to update
  WORD wLanguage, // language identifier of resource
  LPVOID lpData,  // address of resource data
  DWORD cbData    // length of resource data, in bytes
);
 
BOOL UpdateWindow(
  HWND hWnd   // handle of window
);
 
BOOL UserHandleGrantAccess(
  HANDLE hUserHandle,
  HANDLE hJob, 
  BOOL bGrant
);
 
BOOL ValidateRect(
  HWND hWnd,  // handle of window
  CONST RECT *lpRect
              // address of validation rectangle coordinates
);
 
BOOL ValidateRgn(
  HWND hWnd,  // handle of window
  HRGN hRgn   // handle of valid region
);
 
DWORD VerFindFile(
  DWORD dwFlags,      // bit flags that condition function behavior
  LPTSTR szFileName,  // file to be installed
  LPTSTR szWinDir,    // Windows directory
  LPTSTR szAppDir,    // directory where related files are being 
                      // installed
  LPTSTR szCurDir,    // receives path of directory where file is 
                      // currently installed
  PUINT lpuCurDirLen, // size of string in szCurDir
  LPTSTR szDestDir,   // receives path of recommended destination 
                      // directory
  PUINT lpuDestDirLen 
                      // size of string in szDestDir
);
 
DWORD VerInstallFile(
  DWORD uFlags,          // bit flags that condition function 
                         // behavior
  LPTSTR szSrcFileName,  // file to install
  LPTSTR szDestFileName, // new name of file to install
  LPTSTR szSrcDir,       // source directory of file to install
  LPTSTR szDestDir,      // directory in which to install file
  LPTSTR szCurDir,       // directory where file is currently 
                         // installed
  LPTSTR szTmpFile,      // receives name of temporary copy of file 
                         // used during installation
  PUINT lpuTmpFileLen    // size of string in szTmpFile
);
 
DWORD VerLanguageName(
  DWORD wLang,    // Microsoft language identifier
  LPTSTR szLang,  // pointer to buffer for language description 
                  // string
  DWORD nSize     // size of buffer
);
 
BOOL VerQueryValue(
  const LPVOID pBlock, // address of buffer for version resource
  LPTSTR lpSubBlock,   // address of value to retrieve
  LPVOID *lplpBuffer,  // address of buffer for version value pointer
  PUINT puLen          // address of length buffer
);
 
LPVOID VirtualAlloc(
  LPVOID lpAddress, // address of region to reserve or commit
  DWORD dwSize,     // size of region
  DWORD flAllocationType,
                    // type of allocation
  DWORD flProtect   // type of access protection
);
 
LPVOID VirtualAllocEx(
  HANDLE hProcess,  // process within which to allocate memory
  LPVOID lpAddress, // desired starting address of allocation
  DWORD dwSize,     // size, in bytes, of region to allocate
  DWORD flAllocationType,
                    // type of allocation
  DWORD flProtect   // type of access protection
);
 
PVOID64 VirtualAllocVlm(
  HANDLE hProcess,   // process within which to allocate memory
  PVOID64 lpAddress, // address of region to reserve or commit
  DWORDLONG ullSize, // size of region
  DWORD flAllocationType,
                     // type of allocation
  DWORD flProtect    // type of access protection
);
 
BOOL VirtualFree(
  LPVOID lpAddress,  // address of region of committed pages
  DWORD dwSize,      // size of region
  DWORD dwFreeType   // type of free operation
);
 
BOOL VirtualFreeEx(
  HANDLE hProcess,  // process within which to free memory
  LPVOID lpAddress, // starting address of memory region to free
  DWORD dwSize,     // size, in bytes, of memory region to free
  DWORD dwFreeType  // type of free operation
);
 
BOOL VirtualFreeVlm(
  HANDLE hProcess,   // process within which to free memory
  PVOID64 lpAddress, // address of region of pages to free
  DWORDLONG ullSize, // size in bytes of region
  DWORD dwFreeType   // type of free operation
);
 
BOOL VirtualLock(
  LPVOID lpAddress,  // address of first byte of range to lock
  DWORD dwSize       // number of bytes in range to lock
);
 
BOOL VirtualProtect(
  LPVOID lpAddress,    // address of region of committed pages
  DWORD dwSize,        // size of the region
  DWORD flNewProtect,  // desired access protection
  PDWORD lpflOldProtect 
                       // address of variable to get old protection
);
 
BOOL VirtualProtectEx(
  HANDLE hProcess,     // handle to process
  LPVOID lpAddress,    // address of region of committed pages
  DWORD dwSize,        // size of region
  DWORD flNewProtect,  // desired access protection
  PDWORD lpflOldProtect 
                       // address of variable to get old protection
);
 
BOOL VirtualProtectVlm(
  HANDLE hProcess,     // process within which to protect memory
  PVOID64 lpAddress,   // address of region of committed pages
  DWORDLONG ullSize,   // size of the region
  DWORD flNewProtect,  // desired access protection
  PDWORD lpflOldProtect 
                       // address of variable to get old protection
);

DWORD VirtualQuery(
  LPCVOID lpAddress,                   // address of region
  PMEMORY_BASIC_INFORMATION lpBuffer,  // address of information buffer
  DWORD dwLength                       // size of buffer
);
 
DWORD VirtualQueryEx(
  HANDLE hProcess,    // handle to process
  LPCVOID lpAddress,  // address of region
  PMEMORY_BASIC_INFORMATION lpBuffer,
                      // address of information buffer
  DWORD dwLength      // size of buffer
);
 
DWORD VirtualQueryVlm(
  HANDLE hProcess,    // handle of process
  PVOID64 lpAddress,  // address of region
  PMEMORY_BASIC_INFORMATION_VLM lpBuffer,
                      // address of information buffer
  DWORD dwLength      // size of buffer
);
 
BOOL VirtualUnlock(
  LPVOID lpAddress,  // address of first byte of range
  DWORD dwSize       // number of bytes in range
);
 
SHORT VkKeyScan(
  TCHAR ch   // character to translate
);
 
SHORT VkKeyScanEx(
  TCHAR ch,  // character to translate
  HKL dwhkl  // keyboard layout handle
);
 
BOOL WaitCommEvent(
  HANDLE hFile,                // handle to communications device
  LPDWORD lpEvtMask,           // pointer to variable to receive event
  LPOVERLAPPED lpOverlapped,   // pointer to overlapped structure
);
 
BOOL WaitForDebugEvent(
  LPDEBUG_EVENT lpDebugEvent,  // pointer to debug event structure
  DWORD dwMilliseconds         // milliseconds to wait for event
);
 
DWORD WaitForInputIdle(
  HANDLE hProcess,       // handle to process
  DWORD dwMilliseconds   // time-out interval in milliseconds
);
 
DWORD WaitForMultipleObjects(
  DWORD nCount,             // number of handles in the handle array
  CONST HANDLE *lpHandles,  // pointer to the object-handle array
  BOOL fWaitAll,            // wait flag
  DWORD dwMilliseconds      // time-out interval in milliseconds
);
 
DWORD WaitForMultipleObjectsEx(
  DWORD nCount,             // number of handles in handle array
  CONST HANDLE *lpHandles,  // points to the object-handle array
  BOOL fWaitAll,            // wait flag
  DWORD dwMilliseconds,     // time-out interval in milliseconds
  BOOL bAlertable           // alertable wait flag
);
 
DWORD WaitForSingleObject(
  HANDLE hHandle,        // handle to object to wait for
  DWORD dwMilliseconds   // time-out interval in milliseconds
);
 
DWORD WaitForSingleObjectEx(
  HANDLE hHandle,        // handle to object to wait for
  DWORD dwMilliseconds,  // time-out interval, in milliseconds
  BOOL bAlertable        // return to execute I/O completion routine if TRUE
);
 
BOOL WaitMessage(VOID);
 
BOOL WaitNamedPipe(
  LPCTSTR lpNamedPipeName,  // pointer to name of pipe for which to wait 
  DWORD nTimeOut            // time-out interval, in milliseconds
);
 
int WideCharToMultiByte(
  UINT CodePage,         // code page
  DWORD dwFlags,         // performance and mapping flags
  LPCWSTR lpWideCharStr, // address of wide-character string
  int cchWideChar,       // number of characters in string
  LPSTR lpMultiByteStr,  // address of buffer for new string
  int cchMultiByte,      // size of buffer
  LPCSTR lpDefaultChar,  // address of default for unmappable 
                         // characters
  LPBOOL lpUsedDefaultChar   // address of flag set when default 
                             // char. used
);
 
BOOL WidenPath(
  HDC hdc   // handle to device context
);
 
HWND WindowFromDC(
  HDC hDC   // handle of window
);
 
HWND WindowFromPoint(
  POINT Point   // structure with point
);
 
LRESULT CALLBACK WindowProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);
 
UINT WinExec(
  LPCSTR lpCmdLine,  // address of command line
  UINT uCmdShow      // window style for new application
);
 
int WINAPI WinMain(
  HINSTANCE hInstance,  // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,      // pointer to command line
  int nCmdShow          // show state of window
);
 
LONG WinVerifyTrust(
  HWND hwnd,        // handle to a window for interacting with the user
  GUID *ActionID,   // pointer to a trust provider action identifier
  LPVOID ActionData // pointer to a buffer containing action-specific data
);
 
BOOL WriteConsole(
  HANDLE hConsoleOutput, // handle to a console screen buffer
  CONST VOID *lpBuffer,  // pointer to buffer to write from
  DWORD nNumberOfCharsToWrite,
                         // number of characters to write
  LPDWORD lpNumberOfCharsWritten,
                         // pointer to number of characters written
  LPVOID lpReserved      // reserved
);
 
BOOL WriteConsoleInput(
  HANDLE hConsoleInput,  // handle to a console input buffer
  CONST INPUT_RECORD *lpBuffer,
                         // pointer to the buffer for write data
  DWORD nLength,         // number of records to write
  LPDWORD lpNumberOfEventsWritten 
                         // pointer to number of records written
);
 
BOOL WriteConsoleOutput(
  HANDLE hConsoleOutput,  // handle to a console screen buffer
  CONST CHAR_INFO *lpBuffer,  // pointer to buffer with data to write
  COORD dwBufferSize,     // column-row size of source buffer
  COORD dwBufferCoord,    // upper-left cell to write from
  PSMALL_RECT lpWriteRegion   // pointer to rectangle to write to
);
 
BOOL WriteConsoleOutputAttribute(
  HANDLE hConsoleOutput,  // handle to a console screen buffer
  CONST WORD *lpAttribute,  // pointer to buffer to write attributes 
                            // from
  DWORD nLength,          // number of character cells to write to
  COORD wWriteCoord,      // coordinates of first cell to write to
  LPDWORD lpNumberOfAttrsWritten 
                          // pointer to number of cells written to
);
 
BOOL WriteConsoleOutputCharacter(
  HANDLE hConsoleOutput,  // handle to a console screen buffer
  LPCTSTR lpCharacter,    // pointer to buffer to write characters 
                          // from
  DWORD nLength,          // number of character cells to write to
  COORD dwWriteCoord,     // coordinates of first cell to write to
  LPDWORD lpNumberOfCharsWritten 
                          // pointer to number of cells written to
);
 
BOOL WriteFile(
  HANDLE hFile,                    // handle to file to write to
  LPCVOID lpBuffer,                // pointer to data to write to file
  DWORD nNumberOfBytesToWrite,     // number of bytes to write
  LPDWORD lpNumberOfBytesWritten,  // pointer to number of bytes written
  LPOVERLAPPED lpOverlapped        // pointer to structure for overlapped I/O
);
 
BOOL WriteFileEx(
  HANDLE hFile,                 // handle to output file
  LPCVOID lpBuffer,             // pointer to input buffer
  DWORD nNumberOfBytesToWrite,  // number of bytes to write
  LPOVERLAPPED lpOverlapped,    // pointer to async. i/o data
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine  
                                // pointer to completion routine
);
 
BOOL WriteFileGather(
  HANDLE hFile,              // handle to a file to write data to
  FILE_SEGMENT_ELEMENT aSegmentArray [],
                             // pointer to an array of buffer 
                             // pointers
  DWORD nNumberOfBytesToWrite,  // number of bytes to write
  LPDWORD lpReserved,        // reserved; must be NULL
  LPOVERLAPPED lpOverlapped  // pointer to an asynchronous I/O data 
                             // structure
);
 
BOOL WriteFileVlm(
  HANDLE hFile,                 // handle to output file
  PVOID64 lpBuffer,             // pointer to input buffer
  DWORD nNumberOfBytesToWrite,  // number of bytes to write
  LPDWORD lpReserved,           // reserved, must be NULL
  LPOVERLAPPED lpOverlapped     // pointer to async. i/o data
);
 
BOOL WritePrinter(
  HANDLE hPrinter,
                // handle to printer object
  LPVOID pBuf,  // pointer to array that contains printer data
  DWORD cbBuf,  // size, in bytes, of array
  LPDWORD pcWritten 
                // addr. of variable with count of bytes written
);
 
BOOL WritePrivateProfileSection(
  LPCTSTR lpAppName,  // pointer to string with section name
  LPCTSTR lpString,   // pointer to string with data
  LPCTSTR lpFileName  // pointer to string with filename
);
 
BOOL WritePrivateProfileString(
  LPCTSTR lpAppName,  // pointer to section name
  LPCTSTR lpKeyName,  // pointer to key name
  LPCTSTR lpString,   // pointer to string to add
  LPCTSTR lpFileName  // pointer to initialization filename
);
 
BOOL WritePrivateProfileStruct(
  LPCTSTR lpszSection,
                    // pointer to section name
  LPCTSTR lpszKey,  // pointer to key name
  LPVOID lpStruct,  // pointer to buffer that contains data to add
  UINT uSizeStruct, // size, in bytes, of the buffer
  LPCTSTR szFile    // pointer to initialization filename
);
 
BOOL WriteProcessMemory(
  HANDLE hProcess,  // handle to process whose memory is written to
  LPVOID lpBaseAddress,
                    // address to start writing to
  LPVOID lpBuffer,  // pointer to buffer to write data to
  DWORD nSize,      // number of bytes to write
  LPDWORD lpNumberOfBytesWritten 
                    // actual number of bytes written
);
 
BOOL WriteProcessMemoryVlm(
  HANDLE hProcess,  // handle to process whose memory is written to
  PVOID64 lpBaseAddress,
                    // address to start writing to
  PVOID64 lpBuffer,  // pointer to buffer to write data to
  DWORD nSize,      // number of bytes to write
  LPDWORD lpNumberOfBytesWritten 
                    // actual number of bytes written
);
 
BOOL WriteProfileSection(
  LPCTSTR lpAppName, // pointer to section name
  LPCTSTR lpString   // pointer to buffer with data
);
 
BOOL WriteProfileString(
  LPCTSTR lpAppName, // pointer to section name
  LPCTSTR lpKeyName, // pointer to key name
  LPCTSTR lpString   // pointer to string to write
);
 
DWORD WriteRaw(
  PFE_IMPORT_FUNC pfImportCallback,
  PVOID pvCallbackContext,
  PVOID pvContext
);
 
DWORD WriteTapemark(
  HANDLE hDevice,        // handle to open device
  DWORD dwTapemarkType,  // type of tapemarks to write
  DWORD dwTapemarkCount, // number of tapemarks to write
  BOOL bImmediate        // return after write begins
);
 
int wsprintf(
  LPTSTR lpOut,    // pointer to buffer for output
  LPCTSTR lpFmt,   // pointer to format-control string
  ...              // optional arguments
);
 
int wvsprintf(
  LPTSTR lpOutput,  // pointer to buffer for output
  LPCTSTR lpFormat, // pointer to format-control string
  va_list arglist   // variable list of format-control arguments
);
 
VOID ZeroMemory(
  PVOID Destination, 
                 // address of block to fill with zeros
  DWORD Length   // size, in bytes, of block to fill with zeros
);
 
VOID ZeroMemoryVlm(
  PVOID64 Destination, 
                 // address of block to fill with zeros
  DWORD Length   // size, in bytes, of block to fill with zeros
);
