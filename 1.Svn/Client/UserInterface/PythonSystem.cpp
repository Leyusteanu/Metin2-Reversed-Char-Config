///Add
#if defined(__BL_CHAR_CONFIG__)
void CPythonSystem::CreateCharConfigPath()
{
	std::string path = ".\\UserData\\";
	if (GetFileAttributes(path.c_str()) == INVALID_FILE_ATTRIBUTES)
		CreateDirectory(path.c_str(), NULL);

	path += "config\\";
	if (GetFileAttributes(path.c_str()) == INVALID_FILE_ATTRIBUTES)
		CreateDirectory(path.c_str(), NULL);
}

void CPythonSystem::LoadCharConfig()
{
	CInstanceBase* mainInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
	if (!mainInstance)
		return;

	CreateCharConfigPath();
	
	const std::string fileName = ".\\UserData\\config\\" + std::string(mainInstance->GetNameString());
	FILE* fp = fopen(fileName.c_str(), "rt");
	if (!fp)
		return;

	char buf[256]{};
	char command[256]{};
	char value[256]{};

	while (fgets(buf, 256, fp))
	{
		if (sscanf(buf, " %s %s\n", command, value) == EOF)
			break;
	}

	fclose(fp);
}

void CPythonSystem::SaveCharConfig()
{
	CInstanceBase* mainInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
	if (!mainInstance)
		return;

	CreateCharConfigPath();

	const std::string fileName = ".\\UserData\\config\\" + std::string(mainInstance->GetNameString());
	FILE* fp = fopen(fileName.c_str(), "wt");
	if (!fp)
		return;

	fprintf(fp, "\n");
	fclose(fp);
}
#endif