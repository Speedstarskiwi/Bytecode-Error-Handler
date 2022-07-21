/* main */
std::string CatchScriptError(std::string script)
{
	int len = script.length();
	std::string newString;
	for (int i = 0; i < len; i += 2)
	{
		std::string byte = script.substr(i, 2);
		char chr = (char)(int)strtol(byte.c_str(), NULL, 16);
		newString.push_back(chr);
	}

	std::string str(newString);
	std::string error1("Incomplete statement");
	std::string result;

	if (str.find(error1) != std::string::npos) {
		result = "Incomplete statement: expected assignment or a function call";
	}
	else
	{
		result = "all good";
		//no error, continue
	}
	return result;
}
