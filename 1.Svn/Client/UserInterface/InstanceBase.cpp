///Add
#if defined(__BL_CHAR_CONFIG__)
#include "PythonSystem.h"
#endif

//Find
	if (c_rkCreateData.m_isMain)
		SetMainInstance();

///Change
#if defined(__BL_CHAR_CONFIG__)
	__Create_SetName(c_rkCreateData);

	if (c_rkCreateData.m_isMain)
	{
		SetMainInstance();
		CPythonSystem::Instance().LoadCharConfig();
	}
#else
	if (c_rkCreateData.m_isMain)
		SetMainInstance();
#endif

//Find
	__Create_SetName(c_rkCreateData);
	
	m_dwLevel = c_rkCreateData.m_dwLevel;

///Change
#if !defined(__BL_CHAR_CONFIG__)
	__Create_SetName(c_rkCreateData);
#endif

	m_dwLevel = c_rkCreateData.m_dwLevel;