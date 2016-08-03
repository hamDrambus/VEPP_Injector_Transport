//all programm's data lays here
//TODO: after all finished, add intructions for adding pars, changing things, etc.
//XXX means depricated comment
//P.S. means nothing
#ifndef DATA_HEAP_H
#define DATA_HEAP_H
#include "Prefs_heap.h"
#include <iomanip>	//for debuging (setprecision())
#include <algorithm> //for sorting
//typedef void* (corr_object::*set_pars)(void*);

class all_data;
typedef void* (all_data::*set_global_pars) (void*);

//value with name and restricted
//for access to parameters for fitting
//Vectors're used so several values could be grouped under 1 name; then mapped to double* of minimizatoin parameters, 
//so as two same fuctions (+objects) never used
//P.S. This escalates quickly
class value_wn_r //should inherit from set_wv?
{
	//NO SIZE CHECKS!!!!
	//XXX means depricated comment
public:
	value_wn_r(void)
		: set_func(std::vector<set_pars>()), obj(std::vector<corr_object*>()), type(std::vector<int>()), 
		set_global_func(std::vector<set_global_pars>()), max_val(std::vector<double>()), min_val(std::vector<double>()) {};
	
	value_wn_r(std::vector<set_pars> f, std::vector<corr_object*> p_obj = std::vector<corr_object*>(), std::vector<int> typ = std::vector<int>(),
		std::vector<double> max = std::vector <double>(), std::vector<double> min = std::vector <double>())
		: set_func(f), obj(p_obj), 
		type((typ.size()==0)?std::vector<int>(f.size(),0):typ), //if set by user, init with user. Else set type = 0 (default - double) for all <set_pars> funcs
		set_global_func(std::vector<set_global_pars>()),max_val(max),min_val(min) {};

	value_wn_r(std::vector<set_global_pars> p_global_func, std::vector<int> typ = std::vector<int>(),
		std::vector<double> max = std::vector <double>(), std::vector<double> min = std::vector <double>()) 
		: set_func(std::vector<set_pars>()), obj(std::vector<corr_object*>()), 
		type((typ.size() == 0) ? std::vector<int>(p_global_func.size(), 0) : typ),//
		set_global_func(p_global_func), max_val(max), min_val(min) {};
	
	value_wn_r(std::vector<set_global_pars> p_global_func, std::vector<set_pars> f, std::vector<corr_object*> p_obj = std::vector<corr_object*>(),
		std::vector<int> typ = std::vector<int>(), std::vector<double> max = std::vector <double>(),
		std::vector<double> min = std::vector <double>())
		: set_func(f), obj(p_obj),
		type((typ.size() == 0) ? std::vector<int>(p_global_func.size() + f.size() , 0) : typ),//
		set_global_func(p_global_func), max_val(max), min_val(min) {};
	
	//dat's some constructors
	//value_wn_r(value_wn_r & in); //XXXcopy contructor
	//value_wn_r& value_wn_r::operator = (const value_wn_r& in); //XXXthat's class with arrays for you
	//XXXint size(void);
	//double* set_max(double* x); //XXXno size checks, returns max_value  
	//double* set_min(double* n); //XXX^...^

	std::vector <int> type; //0 - double, 1 - int, 2 - string; only values of type 0 used in fittings and etc. 
	//SIZEOF(type) ==  size_of(set_global_func)+size_of(set_fucn)
	//others needed for search by pars names implementation
	std::vector<corr_object*> obj; //array in case of set_func is array
	std::vector<set_pars> set_func; //must be only double pars
	std::vector<set_global_pars> set_global_func; // used for global parameters, not bound to objects, such as initial beam's pars
	//SIZEOF corresp. double* pars (and max(min)_val) = size_of(set_global_func) [FIRST!!!, EVERYWHERE FIRST] + size_of (obj)*size_of(set_fucn) [second]
	//posible double* map: x, x', y'...other globals..., obj[1].coef1, obj[1].coef2, obj[2].coef1, obj[2].coef2 .....
	std::vector <double> max_val; //used in minuit; [folowing is wrong:]//XXXfor current used for fluctuation at the moment;
	std::vector <double> min_val; //used in m ^..^;

	//doneXXXTODO: it seems though additional two maps are needed for (arbitrary) matrix bulding.
	//Problem - beam location at corr_objets not stored in them, so what method is to be associated?
	//solution 1?: add method to read beam theor location but without corresp local variable.
	//this method will have to call all_data calculate beam which is not good (I'd prefer keep corr_object unaware of all_data).
	//and its unclear how to call so that same calculatoin aren't made several times
	//solution 2?: add array of locations in all_data, but then it's not clear how to make this work with value_wn_r, 
	//cause this array won't be associated with objects
	//solution 3?: add both method and local variables of beam pars to corr_object, but locals set in operator(), when d* beam_pars are passed.
	//so all_data is kept hidden from corr_objects and association of method with object in value_wn_r is possible 
	//I choosed 3;
	
	//done: added limits method in corr_onjects which overrides external limits and ^^^
	/*XXXTODO: Problem arises. There are two ways of setting parameters - via double* map (all_data::par_map) or set_pars.
	//XXXThe first is used in minuit. The second is used in fluctuation for matrix building (along with read_pars).
	//XXXBy default for this two purposes diffrent parameters are used (coefs+length and current respectfully)
	//XXXhowever since all_data:: is somewhat flexible and general object it is desirable to make 
	//XXXthings work when parameters for fit are also used for matrix build (for example if current will be added to fit pars list)
	//XXXThe only actual problem is that 'shared' parameter will have two boundaries - one for minuit (par range) - and one for fluctuation (delta).
	//XXXWell, for read_pars par_map in not used, used "par_name" with no boundaries... There are boundaries for current in corr_object though.
	//Architecture is definetly lacking elegance. This shall be figured out.*/

	//XXXsize and functions better to be fixed after construction
	int get_type(std::vector<set_pars>::iterator func);
	int par_size(void);
	int is_satisfy_search(corr_object* obj, void** with_value);
};


class v_map
{
public:
	std::map<int, value_wn_r> map;
	v_map() {};
	v_map(std::map<int, value_wn_r> m) :map(m) {};
	int fix_coef_for_all(value_wn_r to_fix_, value_wn_r search_, void** with_value); //changes map;
	int free_coef_for_all(value_wn_r to_free_, std::vector<corr_object> *sequence, value_wn_r search_, void** with_value);
	//^changes map; //XXXTODO: add search for all_data (global) pars
	//int is_satisfy_search(corr_object* obj, value_wn_r search_f, void** with_value);
	int add_to_par_map(value_wn_r to_free, std::vector<corr_object*> obj, int** to_add_matrix, std::vector<value_wn_r> &out);
	
	int realloc(); //makes double*'s come in turn
	int move_above(int above_val, int p_offset);
	int size();
	int write(std::ofstream &str, all_data *sdpsd);

	//these are for applying value_wn_r map to real parameters. double* arrays must be of appropriate size
	int read_parameters(double * to, all_data* g_obj);
	int set_parameters(double * out, all_data* g_obj);
	int read_with_criterion(double* dep, all_data* g_obj, double* sig, int size, int num_of_measurements, double rejection_cr);

	double get_min_by_num(int par_number);
	double get_max_by_num(int par_number);
	double get_par_by_num(int par_number, all_data* tt);

	int get_obj(int par_number, corr_object* &out_num); //returns -1 if parameter has no object (global)
	int get_method(int par_number, value_wn_r &out_num);
	//^output value_wn_r contains only one all_data method or one corr_object method 

	int assign(int v_m_m, all_data* g_obj, value_wn_r &to, double *value, int meth);
	int assign(int v_m_m, value_wn_r &to, double *value, int meth, int ob);

	int set_coef_lims(value_wn_r to_fix, double* max, double* min, value_wn_r search_, void** with_value, all_data* g_obj=NULL); 
	//^changes map data, not structure. Excessive?
	
	//size of vals must be >= parameter.set_global_func.size()_size+parameter.set_pars.size()
	int set_parameters_vals(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj=NULL);
	int set_parameters_vals(double* coef_arr, value_wn_r parameter, double* vals,value_wn_r search, void** search_data);
	int set_parameters_mins(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj= NULL);
	int set_parameters_mins(double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data);
	int set_parameters_maxs(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj=NULL);
	int set_parameters_maxs(double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data);
	//^these are wrappers for functions below
	int set_parameters_(int v_m_m, value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj = NULL);
	int set_parameters_(int v_m_m, double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data);
};

class all_data 
//doneXXXTODO: ofc, parameters methods (set_global_pars) must be implemented
//TODO: make map<> class with own methods (this class will have to be aware of all_data though)
//TODO: make protected what should be protected 
//doneXXXTODO: would be nice to add bulding matrix using global pars as well, not only form objects.
//TODO: add debug methods, read/write to file
//TODO: probably need to write some common parcer for both preferences and all_data
//however extra objects could be created for this very purpose
//TODO: add async calls of minimiztion and exprerimental matrix calculations
{
public:
	all_data();
	~all_data();
	prefs preferences;
	//1)====num_of_controlled\
	//	|	|				 ||
	//	|	|		2) num_of_pickups
	//	|	|				\||/
	//					     \/
	//decided not to make x and y explicitly.
	//this is general class and methods after all
	double ** matrix_exp;
	//double ** Y_matrix_exp;
	double ** matrix_uncert_exp;
	//double ** Y_matrix_uncert_exp;

	double beam_initial[5];//XXXmake dynamic???
	//x, x', y, y', p [momentum, in GeV]
	//this must not be passed to calculate_beam, because input is changed in process
	//copy must be passed

	int n_row; //pickups
	int n_col; //fluctuated pars
	std::vector<corr_object> sequence; //copy of ones in prefs, only sorted by S
	std::map <std::string, value_wn_r> min_par_def_limits_map; //map of d_simple_pars in prefereces to methods
	std::map <std::string, value_wn_r> max_par_def_limits_map; //value_wn_r must contain only 1 method, and type of double
	v_map par_map; //this is fitting parameters
	//doneXXXTODO: rewrite all this maps to <int, value_wn_r>
	v_map mtr_exp_set;
	v_map mtr_exp_read;
	v_map mtr_th_set;
	v_map mtr_th_read;

	std::map <int, set_global_pars> global_funcs_num; //for reading/writing files
	//diffrent maps because diffrent methods are used - real pars set and read vs theretical calculations
	
	int (*empty_space_tranport) (double* pars, double* beam);
	
	std::map <std::string, value_wn_r> pars_names; //set_pars <-> set_wv <-> value_wn_r???
	value_wn_r get_by_name(std::string name); //if not found returns empty value_wn_r

	int set_def_limits(v_map& map); //set only empty min/max, no overwrite if existing
	int find_coresp_meth(std::string &out_min, std::string& out_max, set_pars what);		//used in set_def_meth
	int find_coresp_meth(std::string &out_min, std::string& out_max, set_global_pars what);	//search in min(max)_par_def_limits_map
	//int find_coresp_meth(value_wn_r &out, value_wn_r what);
	
	int get_start_s(double *S_);
	int calculate_beam(double from_s, double s, double* beam_pars); //sizeof (beam_pars) == 5
	int calculate_beam(); //used from_s - from prefs, to s = last obj (+length/2) and beam_pars = copy of initial
	int sort_sequence(set_wv order, int increase = 1);
	int sort_sequence(std::string par_name, int increase = 1);

	int build_theor_matrix(double *** p_matrix, int& cols, int& rows); //what over what defined in mtr_th_read and mtr_th_set
	//matrix may be of any pars over any; pars set with search: if par with name "seatch_name1" and value "with_value1"
	//then it's included in matrix contruction
	//should this be made more general like pars_map?? - yes
	int build_exp_matrix();//what over what defined in mtr_exp_read and mtr_exp_set
	int read_with_criterion(double* dep,double* sig, int size, std::map<int, value_wn_r> map, int num_of_measurements, double rejection_cr);

	double operator () (const std::vector <double> &pars);
	//meaning of pars may change; operator returns value to be minimized, this is laster used in minuit objects
	int operator () (std::vector <double> &x, std::vector <double> &y, std::vector <double> &s); 
	//must be called after parameters set and beam calculated
	//this operator returns x and y of theoretical beam over s. vector of s - positions of corr_objects
	//for each s there are two x and y - input and output


	//now - global parameters set fuctions - pretty much like in corr_object
	void* set_b_x(void* v); //y
	void* set_b_dx(void* v); //x'
	void* set_b_y(void* v); //y
	void* set_b_dy(void* v); //y'
	void* set_b_p(void* v); //p
	
	int write_global_pars(std::ofstream &str);//martixes, prefs?, beam initials, sequence (!cause in prefs lays copy without any fit parameters set)
	int write_map(v_map map, std::ofstream &str);
	int write_map_elem(value_wn_r, std::ofstream &str);

	double min_(int par_number);	//used for mintit parameter set
	double max_(int par_number);	//^..
	int num_of_pars();				//^..
	//int set_untoggled();//corr_object.set_beam=0; is_required???
	//int scan_positions(double** x_y, int &size); //sizeof(x_y)==2*size, because x1,y1,x2,y2...

	int get_num_of_global(set_global_pars f);
	int get_num_of_object(corr_object* ob);
	int get_num_of_obj(v_map map, int par_number, int &out_num); //returns -1 if parameter has no object (global)

	//XXXmake all_data::sequence pointers to prefs'??
	int test_f(int par);
	int write_beam(std::ofstream &str);

	//direct change of objects parameters
	//size of vals mast be number of paraamter methods. void** - see similar above
	int set_parameters_values(value_wn_r parameter, double* vals, value_wn_r search, void** search_data);
};
#endif
//P.S. WTF???
