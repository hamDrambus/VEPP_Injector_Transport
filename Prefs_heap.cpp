#include "Prefs_heap.h"

template <typename T>
value_wv<T>::value_wv (T v, int(*f) (T))
{
	val = v;
	validator = f;
}

template <typename T>
int value_wv<T>::is_ok(T v)
{
	if (validator == NULL) return 1;
	else return validator(v);
}

prefs::prefs()
{
	add_obj_command = "add";
	object_pars_keys.insert(std::pair<std::string, set_wv>("s", set_wv(0,&(corr_object::set_S), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("type", set_wv(1,&(corr_object::set_type), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("L", set_wv(0, &(corr_object::set_length), is_positive)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("pers_name", set_wv(2, &(corr_object::set_pers_name), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("type_name", set_wv(2, &(corr_object::set_type_name), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_x", set_wv(0, &(corr_object::set_coef_x), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_y", set_wv(0, &(corr_object::set_coef_y), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_x_min", set_wv(0, &(corr_object::set_coef_x_min), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_x_max", set_wv(0, &(corr_object::set_coef_x_max), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_y_min", set_wv(0, &(corr_object::set_coef_y_min), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("coef_y_max", set_wv(0, &(corr_object::set_coef_y_max), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("th_i", set_wv(0, &(corr_object::set_th_i), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("I", set_wv(0, &(corr_object::set_current), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("max_curr", set_wv(0, &(corr_object::set_max_current), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("min_curr", set_wv(0, &(corr_object::set_min_current), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("max_curr_abs_fluct", set_wv(0,&(corr_object::set_max_abs_curr_fluct), NULL)));
	object_pars_keys.insert(std::pair<std::string, set_wv>("max_curr_rel_fluct", set_wv(0, &(corr_object::set_max_rel_curr_fluct),is_relative)));

	object_global_defaults.insert(std::pair<std::string, std::string>("g_th_i", "th_i"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_current", "I"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_x", "coef_x"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_y", "coef_y"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_x_min", "coef_x_min"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_x_max", "coef_x_max"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_y_min", "coef_y_min"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_coef_y_max", "coef_y_max"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_current_min", "min_curr"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_current_max", "max_curr"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_current_max_abs_fluct", "max_curr_abs_fluct"));
	object_global_defaults.insert(std::pair<std::string, std::string>("g_current_max_rel_fluct", "max_curr_rel_fluct"));
	
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_th_i", value_wv<double>(0, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current", value_wv<double>(2, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current_min", value_wv<double>(0.1, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current_max", value_wv<double>(650, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current_max_abs_fluct", value_wv<double>(0.5, is_positive)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current_max_rel_fluct", value_wv<double>(5, is_relative))); 
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_x", value_wv<double>(0.001, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_y", value_wv<double>(0.001, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_x_min", value_wv<double>(0.00001, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_x_max", value_wv<double>(0.01, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_y_min", value_wv<double>(0.00001, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_coef_y_max", value_wv<double>(0.01, NULL)));
	//^related to local parameters via object_global_defaults. That is obj. created with this values and overridden from file
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_num_of_measurements", value_wv<double>(10, is_more_one)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_sigma_rejectoin_criterion", value_wv<double>(3, is_ok_sigma_criterion)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_current_set_time_in_seconds", value_wv<double>(3, is_positive)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_using_log", value_wv<double>(0, NULL)));
	d_simple_pars.insert(std::pair<std::string, value_wv<double>>("g_initial_s", value_wv<double>(0, NULL))); //beam initial position

	//below are used in all_data for setting default limits
	//no current because local override is used
#define beg d_simple_pars.insert(std::pair<std::string, value_wv<double>>
	beg("g_th_i_max", value_wv<double>(std::_Pi / 2, NULL)));
	beg("g_th_i_min", value_wv<double>(-std::_Pi/2, NULL)));
	beg("g_coef_x_max",	 value_wv<double>(1, NULL)));
	beg("g_coef_x_min",	 value_wv<double>(0.0001, NULL)));
	beg("g_coef_y_max",	 value_wv<double>(0.1, NULL)));
	beg("g_coef_y_min",  value_wv<double>(0.00001, NULL)));
	beg("g_coef_len_max",	value_wv<double>(0.2, NULL)));
	beg("g_coef_len_min",	value_wv<double>(0.001, NULL)));
	beg("g_x_max",	value_wv<double>(0.02, NULL)));
	beg("g_x_min",	value_wv<double>(-0.02, NULL)));
	beg("g_x'_max", value_wv<double>(0.0015, NULL)));
	beg("g_x'_min",	value_wv<double>(0, NULL)));
	beg("g_y_max",	value_wv<double>(0.02, NULL)));
	beg("g_y_min",	value_wv<double>(-0.02, NULL)));
	beg("g_y'_max", value_wv<double>(0.000005, NULL)));
	beg("g_y'_min", value_wv<double>(-0.000005, NULL)));
	beg("local_x_max", value_wv<double>(0, NULL))); //used for bulding value_wn_r for matrix building? 
	beg("local_x_min", value_wv<double>(0, NULL)));
	beg("local_y_max", value_wv<double>(0, NULL)));
	beg("local_y_min", value_wv<double>(0, NULL)));
#undef beg
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_last_prefs_import_dir", value_wv<std::string>(std::string(), validate_path))); 
	//read from g_home_prefs_dir/tr.pref; Set by user
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_last_prefs_export_dir", value_wv<std::string>(std::string(), validate_path))); 
	//read from g_home_prefs_dir/tr.pref; Set by user
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_last_data_import_dir", value_wv<std::string>(std::string(), validate_path)));
	//read from g_home_prefs_dir/tr.pref; Set by user
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_last_data_export_dir", value_wv<std::string>(std::string(), validate_path)));
	//read from g_home_prefs_dir/tr.pref; Set by user
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_home_prefs_dir", value_wv<std::string>(std::string(), validate_path))); 
	//empty string means current directory; Fixed (for loading preferences' preferanses)
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_home_prefs_file", value_wv<std::string>(std::string("tr.txt"), validate_filename)));
	//maybe should be tr_pre on unix; read always; Fixed (for loading preferences' preferanses)
	s_simple_pars.insert(std::pair<std::string, value_wv<std::string>>("g_last_prefs_import_file", value_wv<std::string>(std::string(), validate_filename)));
	//loaded from and after tr.pre. Set by user.
}

int prefs::extract_first_word(std::string from, std::string &extract_to)
{
	extract_to.erase();
	if (from.size() == 0) return PARCER_EMPTY_STRING;
	int character = 0;
	while (((from[character] == ' ') || (from[character] == '\t')))//ignore empty space before value key
	{
		character++;
		if (character >= from.size()) return PARCER_EMPTY_STRING;
	}
	while ((from[character] != ' ')&& (from[character] != '\t')&& (from[character] != '='))
	{
		extract_to.push_back(from[character]);
		character++;
		if (character >= from.size()) return character;
	}
	return character;
}

int prefs::extract_value(std::string from, double &to)
{
	int character = extract_first_word(from, std::string());
	if (character >= from.size()) return PARCER_WRONG_STRING_FORMAT;
	while (((from[character] == ' ') || (from[character] == '\t')))
	{
		character++;
		if (character >= from.size()) return PARCER_EMPTY_VALUE;
	}
	if (from[character] != '=') return PARCER_NO_EQUAL_CHARACTER;
	character++;
	while (((from[character] == ' ') || (from[character] == '\t')))
	{
		character++;
		if (character >= from.size()) return PARCER_EMPTY_VALUE;
	}
	std::string end;
	for (int f = character; f < from.size(); f++)
	{
		end.push_back(from[f]==','?'.':from[f]); //so you can write 0,26 instead of 0.26
	}
	char* p;
	p = NULL;
	to = strtod(end.c_str(),&p);
	if (p == end.c_str())
	{
		return PARCER_WRONG_DOUBLE_FORMAT;
	}
	//now check if the rest of string is empty
	//if not - count as read error
	int j = 0;
	while ((*(p + j) == ' ') || (*(p + j) == '\t')) j++;
	if (*(p + j) != '\0') return PARCER_WRONG_DOUBLE_FORMAT;
	return 0;
}

int prefs::print_val_warning(int res,int line, std::ostream &str)
{
	switch (res)
	{
	case 0:
	{
		break;
	}
	case (PARCER_WRONG_DOUBLE_FORMAT) :
	{
		str << "WARNING: line " << line << " wrong double format" << std::endl;
		break;
	}
	case (PARCER_EMPTY_VALUE) :
	{
		str << "WARNING: line " << line << " no value" << std::endl;
		break;
	}
	case (PARCER_WRONG_STRING_FORMAT):
	{
		str << "WARNING: line " << line << " no value" << std::endl;
		break;
	}
	case (PARCER_NO_EQUAL_CHARACTER) :
	{
		str << "WARNING: line " << line << " '=' expected" << std::endl;
		break;
	}
	case (PARCER_HOME_DIR_ERROR) :
	{
		str << "ERROR:  prefs parameter initializtion error: program data directory is missing" << std::endl;
		break;
	}
	case (PARCER_HOME_FILE_ERROR) :
	{
		str << "ERROR:  prefs parameter initializtion error: program file name is missing"  << std::endl;
		break;
	}
	case (PARCER_NO_HOME_FILE_EXIST) :
	{
		str << "ERROR: program data file is missing, failed to load preferecnces, using defaults" << std::endl;
		break;
	}							  
	}
	return res;
}

int prefs::check_str_clauses(std::string &in)
{
	if (in.size() == 0) return PARCER_EMPTY_STRING;
	while ((*in.begin() == '\t') || (*in.begin() == ' '))
	{
		in.erase(in.begin());
		if (in.size() == 0) return PARCER_EMPTY_STRING;
	}
	while ((*(in.end()-1) == '\t') || (*(in.end()-1)== ' '))
	{
		in.erase(in.end()-1);
		if (in.size() == 0) return PARCER_EMPTY_STRING;
	}
	if (in.end() == in.begin()) return PARCER_WRONG_STRING_FORMAT;
	if ((*in.begin() == '"') && (*(in.end()-1) == '"'))
	{
		for (std::string::iterator iter = in.begin() + 1; iter != in.end() - 1; iter++)
		{
			if (*iter == '"') return PARCER_WRONG_STRING_FORMAT; 
			//sring '"text""more text"' not allowed as input. Either '"some text"' or 'some text'. 
		}
		return 1;
	}
	for (std::string::iterator iter = in.begin(); iter != in.end(); iter++)
	{
		if (*iter == '"') return PARCER_WRONG_STRING_FORMAT;
		//not allowed "text""more text" sring as input. Either "some text" or some text. 
	}
	return 0;
}

int prefs::extract_value(std::string from, std::string &to)
{
	to.erase();
	int character = extract_first_word(from, std::string());
	if (character >= from.size()) return PARCER_WRONG_STRING_FORMAT;
	while (((from[character] == ' ') || (from[character] == '\t')))
	{
		character++;
		if (character >= from.size()) return PARCER_EMPTY_VALUE;
	}
	if (from[character] != '=') return PARCER_NO_EQUAL_CHARACTER;
	character++;
	while (((from[character] == ' ') || (from[character] == '\t')))
	{
		character++;
		if (character >= from.size()) return PARCER_EMPTY_VALUE;
	}
	for (int f = character; f < from.size(); f++)
	{
		to.push_back(from[f]);
	}
	int res = check_str_clauses(to);
	if (res < 0) return res;
	if (res == 0) return 0;
	if (res == 1)
	{
		to.erase(to.begin());
		to.erase(to.end()-1);
		return 0; //empty string as input is allowed in general (only as "", not as plain empty space)
	}
}

int prefs::check_syntax(std::string str, std::string &command)
{
	for (int j = 0; j<str.size();j++)
	{
		if (str[j] == '#')
		{
			int odd_quote = 0;
			for (int k = j; k > -1; k--) odd_quote = (str[k] == '"') ? (odd_quote ? 0 : 1 ): odd_quote;
			if (!odd_quote) return j; //comment starts since str[j]	
		}
	}
	int res = extract_first_word(str, command);
	if (res < 0) return res; //empty string
	if (command == add_obj_command) return -2;
	std::map<std::string, value_wv<double>>::iterator d_par;
	d_par = d_simple_pars.find(command);
	if (d_par != d_simple_pars.end()) return -3;
	std::map<std::string, value_wv <std::string>>::iterator s_par;
	s_par = s_simple_pars.find(command);
	if (s_par != s_simple_pars.end()) return -4;
	std::map<std::string, set_wv>::iterator o_par;
	o_par = object_pars_keys.find(command);
	if (o_par != object_pars_keys.end()) return (object_pars_keys.find(command)->second.type==2) ? -6:-5;
	return -1;
}

int prefs::is_not_default(std::string st)
{
	for (int j = 0; j < list_of_not_defualts.size(); j++)
	{
		if (st == list_of_not_defualts[j]) return 1;
	}
	return 0;
}

int prefs::read_from_file(void) //first read is fixed 
{
	std::cout << "reading" << std::endl;
	int numline = 1;
	std::ifstream file;
	std::string filename;
	if (s_simple_pars.find(("g_home_prefs_dir")) != s_simple_pars.end())
	{
		if (!s_simple_pars.find("g_home_prefs_dir")->second.is_ok(s_simple_pars.find("g_home_prefs_dir")->second.val))
			return print_val_warning(PARCER_HOME_DIR_ERROR, 0, std::cout);
		if (s_simple_pars.find("g_home_prefs_dir")->second.val.size()!=0)
			filename += s_simple_pars.find("g_home_prefs_dir")->second.val + "\\";
	}
	else return print_val_warning(PARCER_HOME_DIR_ERROR, 0, std::cout);
	if (s_simple_pars.find(("g_home_prefs_file")) != s_simple_pars.end())
	{
		if (!s_simple_pars.find("g_home_prefs_file")->second.is_ok(s_simple_pars.find("g_home_prefs_file")->second.val))
			return print_val_warning(PARCER_HOME_FILE_ERROR, 0, std::cout);
		filename += s_simple_pars.find("g_home_prefs_file")->second.val;
	}
	else return print_val_warning(PARCER_HOME_FILE_ERROR, 0, std::cout);;
	file.open(filename);
	if (!file.is_open())
		return print_val_warning(PARCER_NO_HOME_FILE_EXIST, 0, std::cout);
	std::string str_line;
	do
	{
		if (is_not_default("g_last_prefs_import_dir") && is_not_default("g_last_prefs_import_file")) break;
		std::getline(file,str_line);
		std::string command;
		int res = check_syntax(str_line, command);
		if (res >= 0)//commented
		{
			str_line.erase(res);
			res = check_syntax(str_line, command);
		}
		switch (res)
		{
		case -4:
		{
			std::string val = 0;
			int is_ok = extract_value(str_line, val);
			print_val_warning(is_ok, numline, std::cout);
			if (0 == is_ok)
			{
				if ((command != "g_home_prefs_dir") && (command != "g_home_prefs_file")) //these are fixed (hardcoded, see prefs contructor) prefs, not changed
				{
					if ((command == "g_last_prefs_import_dir") || (command == "g_last_prefs_import_file"))
					{
						if (s_simple_pars.find(command)->second.is_ok(val))
						{
							s_simple_pars.find(command)->second.val = val;
							//Prior check guaranteed that find() returns not end()
							if (!is_not_default(command)) list_of_not_defualts.push_back(command);
						}
						else
							std::cout << "WARNING: line " << numline << " not valid string value" << std::endl;
					}
				}
			}
			break;
		}
		case -1:
		{
			std::cout << "WARNING: line " << numline << " ignored" << std::endl;
			break;
		}
		case PARCER_EMPTY_STRING:
		{break; }
		}
		numline++;
	} while (!file.eof()); 
	file.close();
	numline = 1;
	if (is_not_default("g_last_prefs_import_dir") && is_not_default("g_last_prefs_import_file"))
	{
		filename.erase();
		if (s_simple_pars.find("g_last_prefs_import_dir")->second.val.size()!=0)
			filename += s_simple_pars.find("g_last_prefs_import_dir")->second.val + "\\";
		filename += s_simple_pars.find("g_last_prefs_import_file")->second.val;
		//no need in checks, done when reading home prefs
		file.open(filename);
	}
	if (!file.is_open()) //home prefs used
	{
		filename.erase();
		if (s_simple_pars.find("g_home_prefs_dir")->second.val.size() != 0)
			filename += s_simple_pars.find("g_home_prefs_dir")->second.val + "\\";
		filename += s_simple_pars.find("g_home_prefs_file")->second.val;
		//no need in checks, done in the beginning
		file.open(filename);
	}
	do
	{
		std::getline(file, str_line);
		std::string command;
		int res = check_syntax(str_line, command);
		if (res >= 0)//commented
		{
			str_line.erase(res);
			res = check_syntax(str_line, command);
		}
		switch (res)
		{
		case -2: //at the moment only 'add'
		{
			sequence.push_back(corr_object());
			for (std::map<std::string, std::string>::iterator j = object_global_defaults.begin(); j != object_global_defaults.end(); j++)
			{
				if ((d_simple_pars.find(j->first) == d_simple_pars.end()) || (object_pars_keys.find(j->second) == object_pars_keys.end())) {}
				else
				{
					if (((object_pars_keys.find(j->second))->second.is_ok)(&(d_simple_pars.find(j->first)->second.val))) //excessive check???
					{
						((*(sequence.end()-1)).*(object_pars_keys.find(j->second)->second.set_func))((void*)&(d_simple_pars.find(j->first)->second.val));
					}
				}
			}
			break;
		}
		case -3:
		{
			double val = 0;
			int is_ok = extract_value(str_line, val);
			print_val_warning(is_ok, numline, std::cout);
			if (0 == is_ok)
			{
				if (d_simple_pars.find(command)->second.is_ok(val))
				{
					d_simple_pars.find(command)->second.val = val;
					//Prior check guaranteed that find() returns not end()
					if (!is_not_default(command))
						list_of_not_defualts.push_back(command);
				}
				else
					std::cout << "WARNING: line " << numline << " not valid value" << std::endl;
			}
			break;
		}
		case -4:
			{
				std::string val = 0;
				int is_ok = extract_value(str_line, val);
				print_val_warning(is_ok, numline, std::cout);
				if (0==is_ok)
				{
					if ((command != "g_home_prefs_dir") && (command != "g_home_prefs_file")) //these are fixed (hardcoded, see prefs contructor) prefs, not changed
					{
						if (s_simple_pars.find(command)->second.is_ok(val))
						{
							s_simple_pars.find(command)->second.val = val;
							//Prior check guaranteed that find() returns not end()
							if (!is_not_default(command)) list_of_not_defualts.push_back(command);
						}
						else
							std::cout << "WARNING: line " << numline << " not valid string value" << std::endl;
					}
				}
				break;
			}
		case -5:
			{
				double val = 0;
				int is_ok = extract_value(str_line, val);
				print_val_warning(is_ok, numline, std::cout);
				if (0 == is_ok)
				{
					if (0 == sequence.size())
						std::cout << "WARNING: line " << numline << " " << add_obj_command << " expected" << std::endl;
					else
					{
						if (object_pars_keys.find(command)->second.is_ok(&val))
							(*(sequence.end()-1).*(object_pars_keys.find(command)->second.set_func))((void*)&val); 
							//call of pointer to member function. Prior check guaranteed that find() returns not end()
						else
							std::cout << "WARNING: line " << numline << " not valid value" << std::endl;
					}
				}
				break;
			}
		case -6:
		{
			std::string val;
			int is_ok = extract_value(str_line, val);
			print_val_warning(is_ok, numline, std::cout);
			if (0 == is_ok)
			{
				if (0 == sequence.size())
					std::cout << "WARNING: line " << numline << " " << add_obj_command << " expected" << std::endl;
				else
				{
					if (object_pars_keys.find(command)->second.is_ok(&val))
						(*(sequence.end() - 1).*(object_pars_keys.find(command)->second.set_func))((void*)&val);
					//call of pointer to member function. Prior check guaranteed that find() returns not end()
					else
						std::cout << "WARNING: line " << numline << " not valid value" << std::endl;
				}
			}
			break;
		}
		case -1:
			{
				std::cout << "WARNING: line " << numline << " ignored" << std::endl;
				break;
			}
		case PARCER_EMPTY_STRING:
			{break;}
		}
		numline++;
	} while (!file.eof());

	file.close();
	return 0;
}

int prefs::write(std::ofstream &file)
{
	file << "# this is autogenerated preferences" << std::endl;
	for (std::map<std::string, value_wv<std::string>>::iterator j = s_simple_pars.begin(); j != s_simple_pars.end(); j++)
	{
		if (is_not_default(j->first))
			file << j->first << " = " << "\"" << j->second.val << "\"" << std::endl;
	}
	for (std::map<std::string, value_wv<double>>::iterator j = d_simple_pars.begin(); j != d_simple_pars.end(); j++)
	{
		if (is_not_default(j->first))
			file << j->first << " = " <<j->second.val << std::endl;
	}
	for (int hh = 0; hh < sequence.size(); hh++)
	{
		file << std::endl;
		file << add_obj_command <<std::endl;
		for (std::map<std::string, set_wv>::iterator j = object_pars_keys.begin(); j != object_pars_keys.end(); j++)
		{
			switch (j->second.type)
			{
			case 0:
			{	
				for (std::map<std::string, std::string>::iterator s_g = object_global_defaults.begin(); s_g != object_global_defaults.end(); s_g++)
				{
					if (s_g->second == j->first)//found corrensponding global paramrter
					{
						if (d_simple_pars.find(s_g->first) != d_simple_pars.end())
						{
							if (d_simple_pars.find(s_g->first)->second.val == *(double*)(sequence[hh].*(j->second.set_func))(NULL))
							continue; //object parameter is the same as default (global), no point in writing
						}
					}
				}
				file << j->first << " = " << *(double*)(sequence[hh].*(j->second.set_func))(NULL) << std::endl;
				break;
			}
			case 1:
			{
				for (std::map<std::string, std::string>::iterator s_g = object_global_defaults.begin(); s_g != object_global_defaults.end(); s_g++)
				{
					if (s_g->second == j->first)//found corrensponding global paramrter
					{
						if (d_simple_pars.find(s_g->first) != d_simple_pars.end())
						{
							if (d_simple_pars.find(s_g->first)->second.val == *(int*)(sequence[hh].*(j->second.set_func))(NULL))
							continue;
						}
					}
				}
				file << j->first << " = " << *(int*)(sequence[hh].*(j->second.set_func))(NULL) << std::endl;
				break;
			}
			case 2:
			{
				for (std::map<std::string, std::string>::iterator s_g = object_global_defaults.begin(); s_g != object_global_defaults.end(); s_g++)
				{
					if (s_g->second == j->first)//found corrensponding global paramrter
					{
						if (s_simple_pars.find(s_g->first) != s_simple_pars.end())
						{
							if (s_simple_pars.find(s_g->first)->second.val == *(std::string*)(sequence[hh].*(j->second.set_func))(NULL))
							continue;
						}
					}
				}
				file << j->first << " = " << "\""+*(std::string*)(sequence[hh].*(j->second.set_func))(NULL)+"\"" << std::endl;
				break;
			}
			}
		}
	}
	return 0;
}


int validate_path(std::string v)
{
	std::cout << "validate path input: " << v << std::endl;
	std::ifstream test; 
	if (v.size() == 0)
		test.open("a");
	else
		test.open(v + "\\a");
	if (!test)
	{
		std::ofstream ttest;
		if (v.size() == 0)
			ttest.open("a");
		else
			ttest.open(v + "\\a");
		if (!ttest) { return 0; }
		ttest.close();
		std::remove((v + "\\a").c_str());
	}
	test.close();
	return 1;
}

int validate_filename(std::string v)
{
	std::ifstream test(v);
	if (!test.is_open())
	{
		std::ofstream ttest(v);
		if (!ttest) { return 0; }
		ttest.close();
		std::remove(v.c_str());
	}
	test.close();
	return 1;
}

int is_positive(void* d){ return *(double*)d >= 0; }
int is_relative(void* d){ return (*(double*)d >= 0) && (*(double*)d < 100); }
int is_ok_sigma_criterion(void* d) { return *(double*)d > 2; }

int is_positive(double d){ return d >= 0; }
int is_relative(double d){ return (d >= 0) && (d < 100); }
int is_ok_sigma_criterion(double d) { return d > 2; }
int is_more_one(double d) { return (int)d > 1; }
