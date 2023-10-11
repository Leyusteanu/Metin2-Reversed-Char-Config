///Add
#if defined(__BL_CHAR_CONFIG__)
PyObject* systemSaveCharConfig(PyObject* poSelf, PyObject* poArgs)
{
	CPythonSystem::Instance().SaveCharConfig();
	return Py_BuildNone();
}
#endif

///Add in void initsystem()
#if defined(__BL_CHAR_CONFIG__)
		{ "SaveCharConfig",				systemSaveCharConfig,			METH_VARARGS },
#endif