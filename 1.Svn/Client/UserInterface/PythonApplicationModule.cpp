///Add
#if defined(__BL_CHAR_CONFIG__)
	PyModule_AddIntConstant(poModule, "__BL_CHAR_CONFIG__", true);
#else
	PyModule_AddIntConstant(poModule, "__BL_CHAR_CONFIG__", false);
#endif