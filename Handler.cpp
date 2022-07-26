/* main bytecode error catcher - only use if your script converts into bytecode */
std::string CatchScriptError(std::string script) /* get the script */
{
	bool failure;
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
		failure = true;
	}
	else if (str.find(error2) != std::string::npos) {
		result = "Attempted to perform something we don't know lmao";
		failure = true;
	}
        else if (str.find(error3) != std::string::npos) {
		result = "The function you executed isn't available";
		failure = true;
	}
	else if (str.find(error4) != std::string::npos) {
	        result = "Unknown error in " + script;
		failure = true;
	}
	else{result = "Script contains no error!\nOr we failed to found an error!"; failure = false;}
	return result;
}

/* no bytecode main - use only if not converting script to bytecode */
std::string CatchScriptError(std::string script) /* get the script */
{
	bool failure;
	std::string str = script;
	/* list of errors, dont change anything */
	std::string error1("Incomplete statement");
	std::string error2("Attempt");
	std::string error3("available");
	std::string error4("not")
        std::string result;

	if (str.find(error1) != std::string::npos) {
		result = "Incomplete statement: expected assignment or a function call";
		failure = true;
	}
	else if (str.find(error2) != std::string::npos) {
		result = "Attempted to perform something we don't know lmao";
		failure = true;
	}
        else if (str.find(error3) != std::string::npos) {
		result = "The function you executed isn't available";
		failure = true;
	}
	else if (str.find(error4) != std::string::npos) {
	        result = "Unknown error in " + script;
		failure = true;
	}
	else{result = "Script contains no error!\nOr we failed to found an error!"; failure = false;}
	return result;
}
