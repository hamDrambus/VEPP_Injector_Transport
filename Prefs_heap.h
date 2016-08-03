#include <fstream>
#include <iostream>
#include "Object.h"

#ifndef PREFS_HEAP
#define PREFS_HEAP

class set_wv
{
public:
	set_wv(int t, set_pars set_f, int(*valr)(void* v) = NULL)
	{
		type = t;
		set_func = set_f;
		validator = valr;
	};
	int is_ok(void* v) //safe wrapper for validator call
	{
		if (NULL == validator) return 1;
		else return validator(v);
	};
	int type;
	//0 - double, 1 - int, 2 - string
	//used in map
	set_pars set_func;
	int(*validator) (void* v);
};
int validate_path(std::string v);

int validate_filename(std::string v);

int is_positive(void* d);
int is_relative(void* d);
int is_ok_sigma_criterion(void* d);

int is_positive(double d);
int is_relative(double d);
int is_ok_sigma_criterion(double d);
int is_more_one(double d);

template <typename T> 
class value_wv
{
public:
	value_wv(T val, int(*validator) (T));
	int is_ok(T val); //safe wrapper for validator call
	T val;
	int(*validator) (T v);
};

class prefs
{
public:
	std::map <std::string, set_wv> object_pars_keys;
protected:
	std::map <std::string, std::string> object_global_defaults; 
	//map from d_simple_pars' keys to object_pars_keys' keys
	//used in construction of default corr_object instead of constructor
	std::string add_obj_command;
	std::vector <std::string> list_of_not_defualts;
	//for later export of prefs, to _not_ to write defaults in files;
	//Defaults 'll be written in full data export though

	int check_str_clauses(std::string &str);
	//0 - all's ok, no quotes; 1 - all's ok, open-close quotes; 
	//PARCER_WRONG_STRING_FORMAT - syntax error; PARCER_EMPTY_STRING - string is empty space
	//also cuts empty space in the end and beginning
	int extract_first_word(std::string from, std::string &exract_to);
	int extract_value(std::string from, double &to);
	int extract_value(std::string from, std::string &to);
	int check_syntax(std::string str,std::string &command);
	int is_not_default(std::string);
	int print_val_warning(int res, int line, std::ostream &str);
	//returns -1 - error; -2 - valid command, no value; -3 - valid, num value result;
	//-4 - valid, string result; -5 - valid, object command, num value; -6 -valid, object command, string value;  
	//>=0 - commets since returned symbol. Comment - # (except bla = "bla-bla#-bla")
	//PARCER_EMPTY_STRING - empty line
	//command - written first word, that is command, later searched in map's keys
public:
	std::map<std::string, value_wv<double>> d_simple_pars;
	std::map<std::string, value_wv <std::string>> s_simple_pars;
	std::vector<corr_object> sequence;
	prefs();
	int read_from_file(void);
	int write(std::ofstream &str);
};

#endif
