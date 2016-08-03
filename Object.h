#include <vector>
#include <map>
#include <string>
#include <random> //delete after removing simulation
#include <chrono>

#include "Transport_functions.h"
#include "ErrorCodes.h"

#ifndef OBJECT_H
#define OBJECT_H
extern std::default_random_engine *gener; //used for randomiztion - for debug only

class corr_object;
typedef void* (corr_object::*set_pars)(void*); //misleading name - this also used for reading, including exprerimental
typedef int (corr_object::*local_limits)(double *min, double* max);

//corretion object - dipole/quadropole lens, etc. (zero s' size) 
//default copy constructor, should be ok, cause pointers to static fuctions, not deleted/created
//parameters are hard-codes so far. Parsing (reading from file) in prefs.
class corr_object //may be pickup as well
	//TODO: add exp. reading method
	//TODO: make limits with priorities and values in obj which may not exist (see 'To do' in 'transport_notes.kra')
	//TODO2: make it async
	//TODO3: make this with inheritance
{
public:
	int type; //type 0 reserved for empty space (all int) (if will be added)
	//1 - dipole magnet; 2 - quadrapole magnet; 3 - pickup, 4 - sector magnet (turning)
	double S;
	double current;
	double th_input; //used for dipoles, input angle of basic track
	double focus_coef_x;
	double focus_coef_y; //not used for now, = ..._x

	double coef_x_min;
	double coef_x_max;
	double coef_y_min;
	double coef_y_max;

	double length;

	double beam_x_exp; //these two are only for storage for read_beam_x/y, not written in files or etc.
	double beam_y_exp; //^
	double beam_x; //theor input
	double beam_y;
	double beam_x_out; //theor input
	double beam_y_out;
	int set_beam; //if beam pars aren't calculated yet it is set to 0;
	//also set to 0 when parameters changed

	std::string type_name;
	std::string pers_name; //may be not unique in sequence
	//set with global defaults, overridden with specific settings from .pre files
	double max_current;
	double min_current;
	double max_rel_curr_fluct;
	double max_abs_curr_fluct;

	int(*transport_function) (double *pars, double *beam_pars);
	//beam_pars must be size of 5 (x, x', y, y', p) //may be added more global parameters
	int operator () (double *beam_pars_in)
	{
		double *temp = new double[7];
		temp[0] = current;
		temp[1] = focus_coef_x;
		temp[2] = focus_coef_y; //used in quadrupoles and correctors
		temp[3] = length;
		temp[4] = th_input; //not used
		temp[5] = S;	//not used
		temp[6] = type;	//not used
		set_beam = 1;
		beam_x = beam_pars_in[0];
		beam_y = beam_pars_in[2];
		int ret = (transport_function != NULL) ? (transport_function(temp, beam_pars_in)) : NOT_INIT_OBJECT_TRANPORT_FUNCTION;
		delete[] temp;
		beam_x_out = beam_pars_in[0];
		beam_y_out = beam_pars_in[2];
		return ret;
	}
	corr_object();
	//turns out can't create map with set_pars key, because there are no comparisson available
	std::map < int, local_limits > lim_num;
	std::map < int, set_pars > set_num;
	//XXXstd::map <set_pars, local_limits > local_lims; //this is top-level priority limits (called last). That is if try to set limits not 
	//within locals from all_data, then within locals will be set anyway
	int find_limits(set_pars _for, local_limits &out); //-1 if not found
	int find_limits(set_pars _for, double* min, double *max); //-1 if not found //only this shuold be visible to all_data 
	int find_meth(set_pars f);

	int curr_lims(double* min, double* max);
	int coef_x_lims(double* min, double* max);
	int coef_y_lims(double* min, double* max);
	//number - enumeration for writing/reading value_wn_r
	//P - read/written in preferences
	//A - read/written in all_data
	void* set_type(void* type);			//0 P A
	void* set_type_name(void* tn);		//1 P A
	void* set_pers_name(void* pn);		//2 P A
	void* set_S(void* S);				//3 P A
	void* set_current(void* current);	//4 A
	void* set_th_i(void* data);			//20 P A
	void* set_function(void* func);		//5 
	void* set_coef_x(void* coef_x);		//6 A
	void* set_coef_y(void* coef_y);		//7 A
	void* set_length(void* len);		//8 P A
	void* set_e_current(void* data); //not defined yet		//9
	void* read_beam_x(void* data);	//only read, set in operator//10 A //set_exp_beam_x should be added
	void* read_beam_y(void* data);	//only read, set in operator//11 A
	void* read_e_beam_x(void* data);	//at the moment it is simulation //18
	void* read_e_beam_y(void* data);	//at the moment it is simulation //19
	void* read_beam_x_out(void* data);	//only read, set in operator//16 A //set_exp_beam_x should be added
	void* read_beam_y_out(void* data);	//only read, set in operator//17 A
	void* set_max_current(void* max_current);		//12 P A
	void* set_min_current(void* min_current);		//13 P A
	void* set_max_rel_curr_fluct(void* max_rel_curr_fluct);	//14 P A
	void* set_max_abs_curr_fluct(void* max_abs_curr_fluct);	//15 P A
	void* set_set_beam(void* t);
	void* set_coef_x_min(void* d);	//21 P A
	void* set_coef_x_max(void* d);	//22 P A
	void* set_coef_y_min(void* d);	//23 P A
	void* set_coef_y_max(void* d);	//24 P A
};
#endif
