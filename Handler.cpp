/* main */
std::string CatchScriptError(std::string script) /* get the script */
{
	int len = script.length(); /* length of script */
	std::string newString; /* dont replace old script with new script */
	for (int i = 0; i < len; i += 2) /* convert into partially readable format */
	{
		std::string byte = script.substr(i, 2);
		char chr = (char)(int)strtol(byte.c_str(), NULL, 16);
		newString.push_back(chr); /* insert new data */
	}

	std::string str(newString);
	/* list of errors, dont change anything */
	std::string error1("Incomplete statement");
	std::string error2("Attempt");
	std::string error3("available");
	std::string error4("nil")
        std::string result;

	if (str.find(error1) != std::string::npos) {
		result = "Incomplete statement: expected assignment or a function call";
	}
	else if (str.find(error2) != std::string::npos) {
		result = "Attempted to perform something we don't know lmao";
	}
        else if (str.find(error3) != std::string::npos) {
		result = "The function you executed isn't available";
	}
	else if (str.find(error3) != std::string::npos) {
	        result = "Unknown error in " + script;
	}
	else{result = "Script contains no error!";}
	return result;
}
