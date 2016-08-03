#include "Data_heap.h"
//XXX means depricated comment
//P.S. means nothing

//P.S. (almost) all this is so ugly

int value_wn_r::get_type(std::vector<set_pars>::iterator func)
{
	int dist = std::distance(set_func.begin(),func);
	return type[dist+set_global_func.size()];
}

int value_wn_r::par_size(void)
{
	return set_global_func.size() + obj.size()*set_func.size();
}

all_data::all_data()
{
	matrix_exp = NULL;
	matrix_uncert_exp = NULL;
	n_col = 0;
	n_row = 0;
	//validator are not used here
	//P.S. everything looks so clumsy, cumbersome and crazy
#define something pars_names.insert(std::pair<std::string, value_wn_r>(std::string
	something("s"),value_wn_r(std::vector<set_pars>(1,&(corr_object::set_S)))));
	something("type"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_type)), std::vector<corr_object*>(), std::vector<int>(1,1))));
	something("type_name"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_type_name)), std::vector<corr_object*>(), std::vector<int>(1, 2))));
	something("coef_x"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_coef_x)))));
	something("coef_y"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_coef_y)))));
	something("I"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_current)))));
	something("L"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_length)))));
	something("th_i"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_th_i)))));
	something("pers_name"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_pers_name)), std::vector<corr_object*>(), std::vector<int>(1, 2))));
	something("coef_x_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_x_min)))));
	something("coef_x_max"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_x_max)))));
	something("coef_y_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_y_min)))));
	something("coef_y_max"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_y_max)))));
	something("min_I"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_min_current)))));
	something("max_I"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_max_current)))));
	something("max_dI"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_max_abs_curr_fluct)))));
	something("max_dI/I"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_max_rel_curr_fluct)))));
	something("exp_I"), value_wn_r(std::vector<set_pars>(1,&(corr_object::set_e_current)))));
	something("X"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_beam_x))))); //these 2 are for martix bulding
	something("Y"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_beam_y)))));
	something("eX"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_e_beam_x))))); //these 2 are for experimental martix bulding
	something("eY"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_e_beam_y)))));

	something("x_in"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_x))));
	something("x'_in"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dx))));
	something("y_in"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_y))));
	something("y'_in"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dy))));
	something("p_in"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_p))));
	std::vector < set_global_pars > temp;
	temp.push_back(&all_data::set_b_x);
	temp.push_back(&all_data::set_b_dx);
	something("xx'_in"), value_wn_r(temp)));
	temp.pop_back();
	temp.pop_back();
	temp.push_back(&all_data::set_b_y);
	temp.push_back(&all_data::set_b_dy);
	something("yy'_in"), value_wn_r(temp)));
	temp.pop_back();
	temp.pop_back();
	temp.push_back(&all_data::set_b_x);
	temp.push_back(&all_data::set_b_dx);
	temp.push_back(&all_data::set_b_y);
	temp.push_back(&all_data::set_b_dy);
	something("all_in"), value_wn_r(temp)));
#undef something
#define some max_par_def_limits_map.insert(std::pair<std::string, value_wn_r>(std::string
	some("g_x_max"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_x))));
	some("g_y_max"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_y))));
	some("g_x'_max"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dx))));
	some("g_y'_max"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dy))));
	some("g_th_i_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::set_th_i))));
	some("g_coef_x_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::set_coef_x))));
	some("g_coef_y_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::set_coef_y))));
	some("g_coef_len_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::set_length))));
	some("local_x_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::read_beam_x))));
	some("local_y_max"), value_wn_r(std::vector<set_pars>(1, &corr_object::read_beam_y))));
	//the last two are actually required for compatiblity with par_map manipulation (to fill value max(min) with 0s to succesfully create matrix maps)
#undef some
#define some min_par_def_limits_map.insert(std::pair<std::string, value_wn_r>(std::string
	some("g_x_min"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_x))));
	some("g_y_min"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_y))));
	some("g_x'_min"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dx))));
	some("g_y'_min"), value_wn_r(std::vector<set_global_pars>(1, &all_data::set_b_dy))));
	some("g_th_i_min"), value_wn_r(std::vector<set_pars>(1, &corr_object::set_th_i))));
	some("g_coef_x_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_x)))));
	some("g_coef_y_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_coef_y)))));
	some("g_coef_len_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::set_length)))));
	some("local_x_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_beam_x)))));
	some("local_y_min"), value_wn_r(std::vector<set_pars>(1, &(corr_object::read_beam_y)))));
	//the last two are actually required for compatiblity with par_map manipulation (to fill value max(min) with 0s to succesfully create matrix maps)
#undef some
	//doneXXXnew problem arises: if "all_in" set on, how to make sure "x_in" can's be set again? FFfffffffffff.
	//doneXXXmake pars, that point to array of value_wn_r; make value_wn_r list? Make array of fuctions instead of funtion with several pars!?
	empty_space_tranport = tr_empty_space;
	//length not needed at the moment
	if (0 != preferences.read_from_file()) {}
	else
	{
		sequence = preferences.sequence;
		sort_sequence("s", 1);
	}
	global_funcs_num.insert(std::pair<int, set_global_pars>(0, &all_data::set_b_x));
	global_funcs_num.insert(std::pair<int, set_global_pars>(1, &all_data::set_b_dx));
	global_funcs_num.insert(std::pair<int, set_global_pars>(2, &all_data::set_b_y));
	global_funcs_num.insert(std::pair<int, set_global_pars>(3, &all_data::set_b_dy));
	global_funcs_num.insert(std::pair<int, set_global_pars>(4, &all_data::set_b_p));
	//P.S. well, not so mush of initializtion really.
	//? below? for test at the moment
	beam_initial[0] = -0.005;
	beam_initial[1] = 0.000001;
	beam_initial[2] = 0.01;
	beam_initial[3] = 0.000005;
	beam_initial[4] = 0.39; //p == 390 MeV
}
all_data::~all_data()
{
	if (NULL != matrix_exp)
	{
		for (int g = 0; g < n_col; g++)
			delete matrix_exp[g];
		delete matrix_exp;
	}
	matrix_exp = NULL;
	if (NULL != matrix_uncert_exp)
	{
		for (int g = 0; g < n_col; g++)
			delete matrix_uncert_exp[g];
		delete matrix_uncert_exp;
	}
	matrix_uncert_exp = NULL;
}

//void** must be valid (array of void* with size of number of obj's methods in search_name. Each void* == (type*)search_value,
//where type corresponds to 'search_name''s method)
//map must contain min/max values of proper size (everything else of proper size ofc.)
//map should not contain the same parameters mapped several times, but it's not important for this function.
//valid types must be specified in search_name
//(that'll be crucial when used in fitting because only last reference to parameter will be used (cycle), so first copyes won't used
//(will be overridden) in actual fitting thus confusing Minuit)
//objects (and min/max) in to_fix_name are ignored (!at the moment at least!)
//XXXTODO: would be nice to make account for objs in to_fix_name as extra selection criteria
//XXXTODO: rewrite in better style
int v_map::fix_coef_for_all(value_wn_r corresp, value_wn_r search_, void** with_value)
{
	//P.S. oh, this is hard one. Not as hard as free_coef though (or maybe not)
	std::map<int, value_wn_r>::iterator next = map.end();
	int norm = 1;
	for (std::map <int, value_wn_r>::iterator i = map.begin(); i != map.end(); norm ? i++:i=next)
	{
		value_wn_r reduced = i->second;
		int *indexes_to_remove = new int[reduced.set_global_func.size()];
		for (int abc = 0; abc < reduced.set_global_func.size(); abc++) indexes_to_remove[abc] = 0; //0 - not remove. 1 - to remove
		//because I can't just erase elems from vector cause of subsequent problems with iterators

		for (std::vector<set_global_pars>::iterator f_i = reduced.set_global_func.begin(); f_i != reduced.set_global_func.end(); f_i++)
			//search is not used here, because search is used for object-associated pars, not global ones
			for (std::vector<set_global_pars>::iterator j = corresp.set_global_func.begin(); j != corresp.set_global_func.end(); j++)
				if (*f_i == *j) //found fucntions match - delete them from vec<set_global_pars>, vec type, vec min(max)_val. No search applyed   
					indexes_to_remove[std::distance(reduced.set_global_func.begin(), f_i)] = 1;

		for (int jjj = reduced.set_global_func.size() - 1; jjj > -1; jjj--)
			if (indexes_to_remove[jjj])
			{
				reduced.set_global_func.erase(reduced.set_global_func.begin() + jjj);
				reduced.type.erase(reduced.type.begin() + jjj);
				reduced.max_val.erase(reduced.max_val.begin() + jjj);
				reduced.min_val.erase(reduced.min_val.begin() + jjj);
			}
		delete[]indexes_to_remove;
		////////////////REMOVED GLOBAL PARAMETRERS ASSOCIATION, NOW OBJ AND THEIR PARS///////////////////
		indexes_to_remove = new int[reduced.obj.size()];
		for (int abc = 0; abc < reduced.obj.size(); abc++) indexes_to_remove[abc] = 0;
		int *method_indexes_to_remove = new int[reduced.set_func.size()];
		for (int abc = 0; abc < reduced.set_func.size(); abc++) method_indexes_to_remove[abc] = 0;
		//reduced only those with both 1; Here is regrouping of val_wn_r needed in order to 
		//achieve obj[1].meth1, obj[1].meth2, obj[2].meth1, obj[3].meth1, obj[3].meth2 ...
		//	0	1	0	0	1	1
		//	0	1	0	0	1	1 
		//not possible!!!:
		//	0	1	0	0	1	0
		//	0	0	0	1	1	1 - methods are the same for all objects (obv.)
		int something = 0;
		int are_th_methods_to_exlude = 0;
		for (int ob = 0; ob < reduced.obj.size(); ob++)
		{
			int is_search_satisfy = search_.is_satisfy_search(reduced.obj[ob], with_value);
			if (is_search_satisfy)
			{
				something = 1;
				indexes_to_remove[ob] = 1;
			}
		}
		for (std::vector<set_pars>::iterator to_rem = reduced.set_func.begin(); to_rem != reduced.set_func.end(); to_rem++)
			for (std::vector<set_pars>::iterator mems = corresp.set_func.begin(); mems != corresp.set_func.end(); mems++)
				//search what methods to exclude
				if (*mems == *to_rem)
				{
					method_indexes_to_remove[std::distance(reduced.set_func.begin(), to_rem)] = 1;
					are_th_methods_to_exlude = 1;
				}
		//Now it's known what to remove
		//All objects, not satifying search crit. - in 'reduced'; if empty (only if no global pars remains) - deleted form map and 
		//deleted *double associated with new map elem (see below); if both elems are empty - map elem. deleted
		//Others objects with remaining methods - in new map element (only if at least one method is exluded, otherwise they remain in reduced); if empty - not added; No global pars;
		if ((are_th_methods_to_exlude) && (something))
		{
			std::vector<int> se_type;
			std::vector<double> se_mins;
			std::vector<double> se_maxs;
			std::vector<corr_object*> se_objs;
			std::vector<set_pars> se_set_pars;
			for (int co = 0; co < reduced.obj.size(); co++)
				if (indexes_to_remove[co])
					se_objs.push_back(reduced.obj[co]);
			for (int co = 0; co < reduced.set_func.size(); co++)
				if (!method_indexes_to_remove[co])
				{
					se_set_pars.push_back(reduced.set_func[co]);
					se_type.push_back(reduced.type[reduced.set_global_func.size() + co]);
				}
			for (int co = 0; co < reduced.set_func.size()*reduced.obj.size(); co++)
			{
				int method_index = co % reduced.set_func.size();
				int obj_index = co / reduced.set_func.size(); //seems all right
				if (indexes_to_remove[obj_index] && !method_indexes_to_remove[method_index])
				{
					se_maxs.push_back(reduced.max_val[reduced.set_global_func.size() + co]);
					se_mins.push_back(reduced.min_val[reduced.set_global_func.size() + co]);
				}
			}
			value_wn_r second(se_set_pars, se_objs, se_type, se_maxs, se_mins);
			for (int co = reduced.obj.size() - 1; co > -1; co--)
			{
				if (indexes_to_remove[co])
				{
					reduced.obj.erase(reduced.obj.begin() + co);
					for (int meth = reduced.set_func.size() - 1; meth > -1; meth--)
					{
						reduced.max_val.erase(reduced.max_val.begin() + reduced.set_global_func.size() + co*reduced.set_func.size() + meth);
						reduced.min_val.erase(reduced.min_val.begin() + reduced.set_global_func.size() + co*reduced.set_func.size() + meth);
					}
				}
			}
			if ((reduced.set_global_func.size() == 0) && (reduced.obj.size() == 0))
			{
				if ((second.obj.size() == 0) || (second.set_func.size() == 0))
				{
					next = i;
					next++;
					norm = 0;
					map.erase(i); //need realloc
				}
				else
					i->second = second;
			}
			else
			{
				i->second = reduced;
				if ((second.obj.size() != 0) && (second.set_func.size() != 0))
					map.insert(std::pair<int, value_wn_r>(i->first + reduced.par_size(), second));
				//there is empty space of double* after second, need to realloc tail of map
			}
		}
		else
			if ((reduced.set_global_func.size() == 0) && (reduced.obj.size() == 0))
				i->second = reduced; //change map's element; only globals may have changed in this scenario
		delete[] indexes_to_remove;
		delete[] method_indexes_to_remove;
	}
	realloc();
	return 0;
}

int value_wn_r::is_satisfy_search(corr_object* obj, void** with_value)
{
	int is_satisfying = 1;
	int par_counter = 0;
	for (int meth = 0; meth < this->set_func.size(); meth++)
	{
		switch (this->type[this->set_global_func.size() + meth])
		{
		case 0:
		{
			is_satisfying = is_satisfying && (*(double*)(*obj.*this->set_func[meth])(NULL) == *(double*)*(with_value + par_counter));
			break;
		}
		case 1:
		{
			is_satisfying = is_satisfying && (*(int*)(*obj.*this->set_func[meth])(NULL) == *(int*)*(with_value + par_counter));
			break;
		}
		case 2:
		{
			is_satisfying = is_satisfying && (*(std::string*)(*obj.*this->set_func[meth])(NULL) == *(std::string*)*(with_value + par_counter));
			break;
		}
		}
		par_counter++;
	}
	return is_satisfying;
}

//void** must be valid (array of void* with size of number of obj's methods in search_name. Each void* == (type*)search_value,
//where type corresponds to 'search_name''s method)
//map must contain min/max values of proper size (everything else of proper size ofc.)
//map must not contain the same parameters mapped several times.
//valid types must be specified in search_name
//(that'll be crucial when used in fitting because only last reference to parameter will be used (cycle), so first copyes won't used
//(will be overridden) in actual fitting thus confusing Minuit)
//search comes for all objects in all_data->sequence; 
//XXXTODO: would be nice to make account for objs in to_fix_name as extra selection criteria
//doneXXXTODO: figure out what to do with min/max values. They should be set here, otherwise this functoin set par_map into invalid state
int v_map::free_coef_for_all(value_wn_r to_free, std::vector<corr_object>*sequence, value_wn_r search_, void** with_value)
{
	std::vector<set_global_pars> to_add_g = to_free.set_global_func;
	std::vector<int> global_types = to_free.type;
	global_types.erase(global_types.begin() + to_add_g.size(), global_types.end());
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
		for (int k = 0; k < i->second.set_global_func.size(); k++)
			for (int t = 0; t < to_add_g.size(); t++)
				if (to_add_g[t] == i->second.set_global_func[k])
				{
					to_add_g.erase(to_add_g.begin() + t);
					global_types.erase(global_types.begin() + t);
					break;
				}
	//found global pars to add
	std::vector<corr_object*> sat_obj;
	for (int f = 0; f < sequence->size(); f++)
	{
		int is_satisfying = search_.is_satisfy_search(&(*sequence)[f], with_value);
		if (is_satisfying)
			sat_obj.push_back(&(*sequence)[f]);
	}
	//found which objects and methods are to be added. Need exlude existing and add to map;
	int ** ind_to_add = new int*[sat_obj.size()];
	for (int j = 0; j < sat_obj.size(); j++)
	{
		ind_to_add[j] = new int[to_free.set_func.size()];
		for (int k = 0; k < to_free.set_func.size(); k++) (ind_to_add[j])[k] = 1;
	}
	int max_mapped = 0;
	std::map<int, value_wn_r>::iterator max_i = map.end();
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		for (int ex_ob = 0; ex_ob < i->second.obj.size(); ex_ob++)
		{
			for (int ob = 0; ob < sat_obj.size(); ob++)
				if (sat_obj[ob] == i->second.obj[ex_ob])
				{
					for (int ex_meth = 0; ex_meth < i->second.set_func.size(); ex_meth++)
					{
						for (int meth = 0; meth < to_free.set_func.size(); meth++)
							if (to_free.set_func[meth] == i->second.set_func[ex_meth])
							{
								ind_to_add[ob][meth] = 0;
								goto br1; //if found method in to_free to add, no point in further searching (no same methods allowed)
							}
					br1:;
					}
					goto br2; //same as with br1: no similar pointers for different 'ob' indexes possible - if found one match - break; 
				}
		br2:;
		}
		if ((i->first)>=max_mapped) { max_mapped = i->first; max_i = i; }
	}
	//now it is known what to add (It was possible though to modify existing map elements, which would decrease the number of them, 
	//but would require more code (probably delete all existing elems and create set of new rectagles in space of (obj*,set_pars))
	//the key question - how to create this set of rectangles, with nearly minimum amount of them 
	//XXX and more sophisticated algorithms).

	//!!!!!! min(max) values!!//probably get value_wn_r array from add_to_par_map nad set min/max here.
	std::vector<value_wn_r> to_add;
	add_to_par_map(to_free, sat_obj, ind_to_add, to_add);
	for (int j = 0; j < sat_obj.size(); j++)
		delete[] ind_to_add[j];
	delete ind_to_add;
	if (to_add.size() != 0)
	{
		to_add.begin()->set_global_func = to_add_g; //attach globals to first elem to add (and change ->type accordingly)
		to_add.begin()->type.insert(to_add.begin()->type.begin(), global_types.begin(), global_types.end());
	}
	else
		if (to_add_g.size()!=0)
			to_add.push_back(value_wn_r(to_add_g, global_types));
	max_mapped += (max_i == map.end()) ? 0 : max_i->second.par_size();
	//int res = set_def_limits(to_add);	//min/max required here. At least some defaults. Or from 'to_free'
	//if (res != 0) return res;
	//defualt min/max set must be done in all_data (because this class does not contain info about preferences)
	//all it knows about all_data is that it contains void*(*methods)(void*)

	std::pair <std::map<int, value_wn_r>::iterator, bool> result;
	for (int j = 0; j < to_add.size(); j++)
	{//XXXno bool check cause there can't be key max_mapped in map (cause max_mapped = max key + par_size!=0);
		result = map.insert(std::pair<int, value_wn_r>(max_mapped, to_add[j]));
		if (result.second == false) return D_MAP_KEY_ALREADY_EXISTS;
		max_mapped += result.first->second.par_size();
	}
	//realloc(); - not required - all written to end
	return 0;
}

int all_data::set_def_limits(v_map& mmap) //sets undefined limits to default. Map's elements may contains not fully filled mins/maxs,
//it's supposed that what is presented correspond to begining of min/max. 
//(e.g. if max contain 2 elements but should 5, new 3 defaults are written to the end)
{
	std::string max;
	std::string min;
	for (std::map<int, value_wn_r>::iterator i = mmap.map.begin(); i != mmap.map.end(); i++)
	{
		if ((i->second.max_val.size() != i->second.par_size()) || (i->second.min_val.size() != i->second.par_size()))
		{
			int g_st_x = i->second.max_val.size();
			int g_st_i = i->second.max_val.size();
			for (int co = g_st_x<g_st_i?g_st_x:g_st_i; co < i->second.set_global_func.size(); co++)
			{
				int res = find_coresp_meth(min, max, i->second.set_global_func[co]);
				if (0 != res) return res;
				if (g_st_i <= co)
					if (preferences.d_simple_pars.find(min) == preferences.d_simple_pars.end()) return D_MAP_NOT_FOUND_DEFAULT_LIMIT_PREFS_KEY;
					else i->second.min_val.push_back(preferences.d_simple_pars.find(min)->second.val);
				if (g_st_x <= co)
					if (preferences.d_simple_pars.find(max) == preferences.d_simple_pars.end()) return D_MAP_NOT_FOUND_DEFAULT_LIMIT_PREFS_KEY;
					else i->second.max_val.push_back(preferences.d_simple_pars.find(max)->second.val);
			}
			g_st_i = i->second.min_val.size() - i->second.set_global_func.size();
			g_st_x = i->second.max_val.size() - i->second.set_global_func.size();
			int par_counter = 0;
			for (int ob = 0; ob < i->second.obj.size(); ob++)
			{
				for (int meth = 0; meth < i->second.set_func.size(); meth++)
				{
					double loc_min = 0;
					double loc_max = 0;
					if ((g_st_i > par_counter) && (g_st_x > par_counter))
					{
						par_counter++;
						continue;
					}
					int res = find_coresp_meth(min, max, i->second.set_func[meth]);
					if (0 != res)
					{
						int ret = i->second.obj[ob]->find_limits(i->second.set_func[meth], &loc_min, &loc_max);
						if ((0 != ret)&&(NO_LOCAL_OVERRIDE!=ret)) return ret;
						if (g_st_i <= par_counter)
							i->second.min_val.push_back(loc_min);
						if (g_st_x <= par_counter)
							i->second.max_val.push_back(loc_max);
						par_counter++;
						continue;
					}
					if (g_st_i <= par_counter)
					{
						if (preferences.d_simple_pars.find(min) == preferences.d_simple_pars.end())
							return D_MAP_NOT_FOUND_DEFAULT_LIMIT_PREFS_KEY;
						else loc_min = preferences.d_simple_pars.find(min)->second.val;
					}
					if (g_st_x <= par_counter)
					{
						if (preferences.d_simple_pars.find(max) == preferences.d_simple_pars.end())
							return D_MAP_NOT_FOUND_DEFAULT_LIMIT_PREFS_KEY;
						else loc_max = preferences.d_simple_pars.find(max)->second.val;
					}
					int ret = i->second.obj[ob]->find_limits(i->second.set_func[meth], &loc_min, &loc_max);
					if ((0 != ret) && (NO_LOCAL_OVERRIDE != ret)) return ret;
					if (g_st_i <= par_counter)
						i->second.min_val.push_back(loc_min);
					if (g_st_x <= par_counter)
						i->second.max_val.push_back(loc_max);
					par_counter++;
				}
			}
			if ((i->second.par_size() != i->second.max_val.size()) || (i->second.par_size() != i->second.min_val.size())) return D_MAP_NOT_LIMIT_SIZE_MISMATCH;
		}
	}
	return 0;
}

int all_data::find_coresp_meth(std::string &out_min,std::string& out_max, set_pars what) //search in min(max)_par_def_limits_map
{
	out_min.erase();
	out_max.erase();
	for (std::map<std::string, value_wn_r>::iterator k = min_par_def_limits_map.begin(); k != min_par_def_limits_map.end(); k++)
		for (int j = 0; j < k->second.set_func.size();j++)
			if (k->second.set_func[j] == what)
			{
				out_min = k->first;
				goto fir;
			}
fir:
	for (std::map<std::string, value_wn_r>::iterator k = max_par_def_limits_map.begin(); k != max_par_def_limits_map.end(); k++)
		for (int j = 0; j < k->second.set_func.size(); j++)
			if (k->second.set_func[j] == what)
			{
				out_max = k->first;
				goto sec;
			}
sec:
	if ((out_min.size() == 0) || (0 == out_max.size())) return D_MAP_NOT_FOUND_DEFAULT_LIMIT;
	return 0;
}
int all_data::find_coresp_meth(std::string &out_min, std::string& out_max, set_global_pars what)
{
	out_min.erase();
	out_max.erase();
	for (std::map<std::string, value_wn_r>::iterator k = min_par_def_limits_map.begin(); k != min_par_def_limits_map.end(); k++)
		for (int j = 0; j < k->second.set_global_func.size(); j++)
			if (k->second.set_global_func[j] == what)
			{
				out_min = k->first;
				goto fir;
			}
fir:
	for (std::map<std::string, value_wn_r>::iterator k = max_par_def_limits_map.begin(); k != max_par_def_limits_map.end(); k++)
		for (int j = 0; j < k->second.set_global_func.size(); j++)
			if (k->second.set_global_func[j] == what)
			{
				out_max = k->first;
				goto sec;
			}
sec:
	if ((out_min.size() == 0) || (0 == out_max.size())) return D_MAP_NOT_FOUND_DEFAULT_LIMIT;
	return 0;
}

//XXXTODO: This may be very slow function in some cases. Need some limitations for combinatons.
int v_map::add_to_par_map(value_wn_r to_free, std::vector<corr_object*> sat_obj, int** ind_matrix,std::vector<value_wn_r> &out)
{
	class associated_matrix
	{
	private:
		class col_s //only for sorting using std::sort 
		{
			associated_matrix* par;
		public:
			col_s(associated_matrix* p = NULL) : par(p) {};
			bool operator ()(int col1, int col2)
			{
				if (par == NULL) return 1;
				return par->col_size(col1) > par->col_size(col2);
			}
		} col_sort_obj;
		class row_s //only for sorting using std::sort 
		{
			associated_matrix* par;
		public:
			row_s(associated_matrix* p = NULL) : par(p) {};
			bool operator ()(int row1, int row2)
			{
				if (par == NULL) return 1;
				return par->row_size(row1) > par->row_size(row2);
			}
		} row_sort_obj;
	public:
		std::vector<corr_object*> obj; //enums coulms
		std::vector<set_pars> funcs; //enums row: matrix [obj_index][func_index]
		std::vector<int> type; //also enums row (WITHOUT OFFSET here (no +set_global_func.size()))
		
		int curr_rect_indexes[4]; //used for generating value_wn_r
		//col_left 0, row_top 1, col_right 2, row_bot 3
		int max_achieved_S;
		int max_rect_indexes[4];
		std::vector<int> mtr_cols;	//Matrix is never changed. Indexation is what is changing during work (way faster)
		std::vector<int> mtr_rows;	//this is indexes to memory

		//decided to use simplified version, seem quite ok for its purpose
		//std::vector<int> max_cols;	//XXXused in swapping equal rows and column for search of max S
		//std::vector<int> max_row;	//XXXhere is written matrix state in which maxinmum S was reached
		//XXX^these are above mrt_cols(rows).
		//std::vector<std::vector<int>> equal_cols_gr;
		//std::vector<std::vector<int>> equal_rows_gr; //gr = groups

		int **matrix;
		int col_size(int col)
		{
			int ret = 0;
			for (int h = 0; h < mtr_rows.size(); h++)
				if (matrix[col][h]) ret++;
			return ret;
		}
		int row_size(int row)
		{
			int ret = 0;
			for (int h = 0; h < mtr_cols.size(); h++)
				if (matrix[h][row]) ret++;
			return ret;
		}
		int search_max_s()
		{
			for (int j = 0; j < 4; j++) max_rect_indexes[j] = 0;
			max_achieved_S = 0;
			//if enter - matrix is not empty
			for (int j = 0; j < mtr_cols.size(); j++)
				if (matrix[j][0]) {curr_rect_indexes[0] = j; break;}
			curr_rect_indexes[1] = 0;
			curr_rect_indexes[3] = 0;
			curr_rect_indexes[2] = curr_rect_indexes[0];
			for (int cols = curr_rect_indexes[0]; cols < mtr_cols.size(); cols++)
			{
				curr_rect_indexes[2] = cols;
				if (matrix[cols][0] == 0) { curr_rect_indexes[2]--; break; }
				for (int rows = curr_rect_indexes[1]; rows < mtr_rows.size(); rows++)
				{
					curr_rect_indexes[3] = rows;
					if (matrix[cols][rows] == 0) {curr_rect_indexes[3]--; break;}
				}
				int size = (curr_rect_indexes[2] - curr_rect_indexes[0] + 1)*(curr_rect_indexes[3] - curr_rect_indexes[1] + 1);
				if (size > max_achieved_S)
				{
					max_achieved_S = size;
					for (int j = 0; j < 4; j++)
						max_rect_indexes[j] = curr_rect_indexes[j];
				}
			}
			return 0;
		}
		//XXXneed proper combinations for this shit\/
		//ok - this can easily take 4 full days// int get_max_s_comb();
		int sort()
		{
			std::sort(mtr_cols.begin(), mtr_cols.end(),col_sort_obj);
			std::sort(mtr_rows.begin(), mtr_rows.end(), row_sort_obj);
			return 0;
		}
		std::vector<value_wn_r> operator () (void)
		{
			std::vector<value_wn_r> out;
			reduce();
			while ((mtr_cols.size() != 0) && (mtr_rows.size() != 0))
			{
				sort();
				search_max_s();
				value_wn_r _add = extract();
				if (_add.par_size() != 0) //excessive?
					out.push_back(_add);
				reduce();
			}
			return out;
		}
		//P.S. how to test all this???
		value_wn_r extract(void)
		{
			value_wn_r out;
			for (int obs = curr_rect_indexes[0]; obs <= curr_rect_indexes[2]; obs++)
			{
				out.obj.push_back(obj[mtr_cols[obs]]);
			}
			for (int obs = curr_rect_indexes[1]; obs <= curr_rect_indexes[3]; obs++)
			{
				out.set_func.push_back(funcs[mtr_rows[obs]]);
				out.type.push_back(type[mtr_rows[obs]]);
			}
			//P.S. forgot to zero matrix elems
			for (int cols = curr_rect_indexes[0]; cols<= curr_rect_indexes[2]; cols++)
			{
				for (int ro = curr_rect_indexes[1]; ro <= curr_rect_indexes[3]; ro++)
				{
					matrix[mtr_cols[cols]][mtr_rows[ro]] = 0;
				}
			}			
			return out;
		}
		int reduce() //deletes 0's rows and colums from ass_matrix
		{
			for (int h = mtr_cols.size()-1; h > -1; h--)
			{
				int is_emp = 1;
				for (int b = 0; b < mtr_rows.size(); b++)
					if (matrix[mtr_cols[h]][mtr_rows[b]] != 0) {is_emp = 0; break;}
				if (is_emp) mtr_cols.erase(mtr_cols.begin() + h);
			}
			for (int h = mtr_rows.size() - 1; h > -1; h--)
			{
				int is_emp = 1;
				for (int b = 0; b < mtr_cols.size(); b++)
					if (matrix[mtr_cols[b]][mtr_rows[h]] != 0) { is_emp = 0; break; }
				if (is_emp) mtr_rows.erase(mtr_rows.begin() + h);
			}
			return 0;
		}
		associated_matrix::associated_matrix(std::vector<corr_object*> objs, std::vector<set_pars> set_fs, 
			std::vector<int> ttype, int **ind_matr) :col_sort_obj(this), row_sort_obj(this)
		{
			obj = objs;
			funcs = set_fs;
			type = ttype;
			matrix = ind_matr;
			for (int f = 0; f < obj.size();f++)
				mtr_cols.push_back(f);
			for (int g = 0; g < funcs.size(); g++)
				mtr_rows.push_back(g);
		}
	};
	associated_matrix mat(sat_obj, to_free.set_func, to_free.type, ind_matrix);
	out = mat();
	return 0;
}

//size of min(max) must be size of to_fix_name set_funcs + set_global_funcs 
//XXXTODO?: add account for obj in to_fix_name
int v_map::set_coef_lims(value_wn_r to_fix, double* max, double* min, value_wn_r search_, void** with_value, all_data* g_obj) //changes map data, not structure
{
	/*if (pars_names.find(to_fix_name) == pars_names.end()) return D_MAP_NO_SUCH_PARAMETERS;
	else to_fix = pars_names.find(to_fix_name)->second;
	*/
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		for (int meth = 0; meth < i->second.set_global_func.size(); meth++)
			for (int y = 0; y < to_fix.set_global_func.size();y++)
				if (to_fix.set_global_func[y] == i->second.set_global_func[meth])
				{
					double* min_max = new double[2];
					min_max[0] = min[y];
					min_max[1] = max[y];
					int ret = assign(3, g_obj, i->second, min_max, meth);
					if (0 != ret)
						return ret;
					delete[] min_max;
					break;
				}
		for (int ob = 0; ob < i->second.obj.size(); ob++)
			if (search_.is_satisfy_search(i->second.obj[ob], with_value))
				for (int meth = 0; meth < i->second.set_func.size(); meth++)
					for (int g = 0; g < to_fix.set_func.size(); g++)
						if (to_fix.set_func[g] == i->second.set_func[meth])
						{
							double* min_max = new double[2];
							min_max[0] = min[to_fix.set_global_func.size() + g];
							min_max[1] = max[to_fix.set_global_func.size() + g];
							int ret = assign(3, i->second, min_max, meth, ob);
							if (0 != ret)
								return ret;
							delete[] min_max;
							break; //found one mathch no point in further searching of the same method
						}
	}
	return 0;
}

int v_map::move_above(int above_val, int p_offset)
{
	std::map<int, value_wn_r> temp_copy;
	for (std::map <int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (i->first <= above_val)
			temp_copy.insert(*i);
		else
			temp_copy.insert(std::pair<int, value_wn_r>(i->first + p_offset, i->second));
	}
	map = temp_copy;
	return 0;
}

//TODO: optimize
int v_map::realloc() //makes double*'s come in turn //XXXthen sort by value_wn_r: first global pars, then coef for for 1st obj, then for 1nd;
//Is sorting needed? Always can find name, etc.. The main thing - one double* - one set. And get par name by set. 
{
	beg:
	for (std::map <int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		int next = i->first + i->second.par_size();
		int real_next = i->first;
		for (std::map <int, value_wn_r>::iterator s = map.begin(); s != map.end(); s++)
			if (real_next > i->first) 
			{
				if ((s->first < real_next) && (s->first>i->first)) 
					real_next = s->first;
			}
			else 
				real_next = s->first > i->first? s->first :i->first;
		if (real_next > next)
		{
			move_above(i->first, next - real_next);
			goto beg; //iterators are invalid now
		}
	}
	return 0;
}

int v_map::size()
{
	std::map <int, value_wn_r>::iterator max_elem = map.begin();
	if (max_elem == map.end()) return 0;
	for (std::map <int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (i->first > max_elem->first)
			max_elem = i;
	}
	return (max_elem->first +max_elem->second.par_size());
}


/*doneXXXTODO: add prevention from calling sequence[]() twice when called exteranally e.g.:
/XXXcalculate_beam(0.5, 1, b);
/XXXcalculate_baem(1, 2, b);
XXXwith sequnce[h0].s == 1;*/
//sequence must be sorted
//if object is located on from_s its method is not called.
int all_data::calculate_beam(double from_s, double to_s, double* beam_pars) //sizeof (beam_pars) == 4
{
	if (to_s < from_s) return TR_WRONG_S_PARAMETER;
	double curr_s = from_s;
	for (int h = 0; h < sequence.size(); h++)
	{
		double obj_s = *(double*)sequence[h].set_S(NULL);
		double obj_l = *(double*)sequence[h].set_length(NULL);
		//curr_s should be outside ( obj_s - obj_l/2, obj_s + obj_l/2) //note - not [,]
		if (obj_s-obj_l/2  < curr_s) //if curr_s ==obj_s for example, then obj is ignored
			continue;
		if (obj_s-obj_l/2 == curr_s)
		{
			if (from_s!=obj_s-obj_l/2) 
				sequence[h](beam_pars);
			continue;
		}
		if (obj_s-obj_l/2 > curr_s)
		{
			if (obj_s+obj_l/2 > to_s)
			{
				double dt = to_s - curr_s;
				empty_space_tranport(&dt, beam_pars);
				return 0;
			}
			double dt = obj_s-obj_l/2-curr_s;
			empty_space_tranport(&dt, beam_pars);
			sequence[h](beam_pars);
			curr_s = obj_s+obj_l/2;
		}
	}
	return 0;
}

int all_data::calculate_beam()
{
	double s_;
	int ret = get_start_s(&s_);
	if (0 != ret)
		return ret;
	double to_s = *(double*)sequence[sequence.size() - 1].set_S(NULL); //not nessesary add length/2, see calculate_beam(...)
	double beam_i[5];
	for (int h = 0; h < 5; h++)
	{
		beam_i [h]= beam_initial[h];
	}
	ret = calculate_beam(s_, to_s, beam_i);
	return ret;
}

int all_data::sort_sequence(set_wv order, int increase)
{
	class for_sort_inc
	{
		set_wv* ord;
		int is_inc;
	public:
		for_sort_inc(set_wv* o,int is_inc_) :ord(o), is_inc(is_inc_) {};
		bool operator ()(corr_object a, corr_object b)
		{
			int ret;
			switch (ord->type)
			{
			case 0:
			{ret = *(double*)(a.*(ord->set_func))(NULL) < *(double*)(b.*(ord->set_func))(NULL); break; }
			case 1:
			{ret = *(int*)(a.*(ord->set_func))(NULL)<*(int*)(b.*(ord->set_func))(NULL); break; }
			case 2:
			{ret = *(std::string*)(a.*(ord->set_func))(NULL)<*(std::string*)(b.*(ord->set_func))(NULL); break; }
			}
			return is_inc ? ret : !ret;
		}
	} __s (&order,increase);
	std::sort(sequence.begin(), sequence.end(), __s);
	return 0;
}

int all_data::sort_sequence(std::string par_n, int increase)
{
	value_wn_r corr = (pars_names.find(par_n) == pars_names.end()) ? value_wn_r() : pars_names.find(par_n)->second;
	if (corr.set_func.size() == 0) return TR_WRONG_SORT_PARAMETER_NAME;
	class for_sort
	{
		value_wn_r* ord;
		int is_inc; //1- inc, 0 -dec
	public:
		for_sort(value_wn_r* o, int is_inc_) :ord(o),is_inc(is_inc_) {};
		bool operator ()(corr_object a, corr_object b)
		{
			int is_more = -1; //-1 - equal, 1 - less, 0 - more 
			//this complicated because it is sorting by several methods simultaneously: if equal for 1st method, 2nd used and so on.
			for (int h = 0; (h < ord->set_func.size())&&(-1==is_more); h++)
			{
				switch (ord->type[ord->set_global_func.size() + h])
				{
					case 0:
					{
						double aa, bb;
						aa = *(double*)(a.*(ord->set_func[h]))(NULL);
						bb = *(double*)(b.*(ord->set_func[h]))(NULL);
						if (aa == bb)
							break;
						is_more = aa < bb ? 1 : 0;
						break;
					}
					case 1:
					{
						int aa, bb;
						aa = *(int*)(a.*(ord->set_func[h]))(NULL);
						bb = *(int*)(b.*(ord->set_func[h]))(NULL);
						if (aa == bb)
							break;
						is_more = aa < bb ? 1 : 0;
						break;
					}
					case 2:
					{
						std::string aa, bb;
						aa = *(std::string*)(a.*(ord->set_func[h]))(NULL);
						bb = *(std::string*)(b.*(ord->set_func[h]))(NULL);
						if (aa == bb)
							break;
						is_more = aa < bb ? 1 : 0;
						break;
					}
				}
			}			
			return is_inc? is_more:!is_more;
		}
	} __s(&corr, increase);
	std::sort(sequence.begin(),sequence.end(), __s);
	return 0;
}

int v_map::read_parameters(double * to, all_data* g_obj) //may be exper. and theoretical;
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		int par_counter = 0;
		for (int j = 0; j < i->second.set_global_func.size(); j++)
		{
			if (i->second.type[j] != 0) return TR_NOT_DOUBLE_PAR_IN_MATRIX_BUILD;
			*(to + par_counter + i->first) = *(double*)(g_obj->*i->second.set_global_func[j])(NULL);
			par_counter++;
		}
		for (int ob = 0; ob < i->second.obj.size(); ob++)
			for (int me = 0; me < i->second.set_func.size(); me++)
			{
				if (i->second.type[i->second.set_global_func.size()+me] != 0) return TR_NOT_DOUBLE_PAR_IN_MATRIX_BUILD;
				*(to + par_counter + i->first) = *(double*)(*i->second.obj[ob].*i->second.set_func[me])(NULL);
				par_counter++;
			}
	}
	return 0;
}
//size of out == size of map
//TODO: add search?
int v_map::set_parameters(double * out, all_data *g_obj)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		int par_counter = 0;
		for (int j = 0; j < i->second.set_global_func.size(); j++)
		{
			if (i->second.type[j] != 0) return TR_NOT_DOUBLE_PAR_IN_MATRIX_BUILD;
			*(double*)(g_obj->*i->second.set_global_func[j])(out+i->first+par_counter);
			par_counter++;
		}
		for (int ob = 0; ob < i->second.obj.size(); ob++)
			for (int me = 0; me < i->second.set_func.size(); me++)
			{
				if (i->second.type[i->second.set_global_func.size() + me] != 0) return TR_NOT_DOUBLE_PAR_IN_MATRIX_BUILD;
				*(double*)(*i->second.obj[ob].*i->second.set_func[me])(out + i->first +par_counter);
				par_counter++;
			}
	}
	return 0;
}

double v_map::get_min_by_num(int par_number)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (!((i->first <= par_number) && (par_number < i->first + i->second.par_size())))
			continue; //this number is not this element
		int par_counter = par_number - i->first;
		return i->second.min_val[par_counter];
	}
	return 0;
}
double v_map::get_max_by_num(int par_number)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (!((i->first <= par_number) && (par_number < i->first + i->second.par_size())))
			continue; //this number is not this element
		int par_counter = par_number - i->first;
		return i->second.max_val[par_counter];
	}
	return 0;
}

double v_map::get_par_by_num(int h, all_data* tt)
{
	value_wn_r t;
	if (0 != get_method(h, t)) return 0; //actually some kind of error
	corr_object* f;
	if (0 == get_obj(h, f))
		return *(double*)(*f.*t.set_func[0])(NULL);
	else
		return *(double*)(*tt.*t.set_global_func[0])(NULL);
}

int v_map::write(std::ofstream &str, all_data *g_obj) //if map is not form doubles - serious error occurs
{
	//this is more for test purposes
	for (int h = 0; h < size(); h++)
	{
		value_wn_r t;
		if (0!=get_method(h, t)) continue; //actually some kind of error
		corr_object* f;
		if (0 == get_obj(h, f))
			str << *(double*)(*f.*t.set_func[0])(NULL);
		else
			str << *(double*)(*g_obj.*t.set_global_func[0])(NULL);
		if (h == size() - 1) str << std::endl;
		else str << "\t";
	}
	for (int h = 0; h < size(); h++)
	{
		str << get_min_by_num(h);
		if (h == size() - 1) str << std::endl;
		else str << "\t";
	}
	for (int h = 0; h < size(); h++)
	{
		str << get_max_by_num(h);
		if (h == size() - 1) str << std::endl;
		else str << "\t";
	}
	return 0;
}

int all_data::get_start_s(double *S_)
{
	if (preferences.d_simple_pars.find("g_initial_s") == preferences.d_simple_pars.end())
		return TR_BEAM_INITIAL_POS_MISSING;
	else
		*S_ = preferences.d_simple_pars.find("g_initial_s")->second.val;
	return 0;
}
//p_matrix must be size of cols X rows, deleted and changed with new one
int all_data::build_theor_matrix(double *** p_matrix, int& cols, int& rows)
{
	int result = 0;
	for (int j = 0; j < cols; j++)
		delete[](*p_matrix)[j];
	if (cols>0) delete *p_matrix;
	cols = mtr_th_set.size();
	rows = mtr_th_read.size();
	if ((cols == 0) || (rows == 0)) return TR_EMPTY_MTR_MAPS;
	*p_matrix = new double*[cols];
	for (int j = 0; j < cols; j++)
	{
		(*p_matrix)[j] = new double[rows];
		for (int h = 0; h < rows; h++)
			(*p_matrix)[j][h] = 0;
	}
	double *def_fluct = new double[cols];
	double *_fluct = new double[cols];
	double *def_dependent = new double[rows];
	double *_dependent = new double[rows];
	result = mtr_th_set.read_parameters(def_fluct,this); //initial parameter must be already set
	if (0 != result) goto Tend;
	//beam calculation happend for the first time here? Or before?
	result =calculate_beam();//calculated from s_ to last object
	if (0 != result) goto Tend;
	result = mtr_th_read.read_parameters(def_dependent,this); //must be called after calculation
	if (0 != result) goto Tend;
	
	for (int c = 0; c < cols; c++)
	{
		double delta_fluct=0;
		for (int _c = 0; _c < cols; _c++)
		{
			double max_, min_;
			_fluct[_c] = def_fluct[_c] /*+ (_c == c) ?
				(max_ = mtr_th_set.get_max_by_num(_c), min_ = mtr_th_set.get_min_by_num(_c),
				max_ - def_fluct[_c] > def_fluct[_c] - min_ ? delta_fluct = max_ - def_fluct[_c] : delta_fluct = min_ - def_fluct[_c]) : 0*/;
			if (_c == c)
			{
				max_ = mtr_th_set.get_max_by_num(_c);
				min_ = mtr_th_set.get_min_by_num(_c);
				if (max_ - def_fluct[_c] > def_fluct[_c] - min_)
					delta_fluct = max_ - def_fluct[_c];
				else
					delta_fluct = min_ - def_fluct[_c];
				_fluct[_c] += delta_fluct;
			}
			//choose maximal fluctuation (min/max value - from map) and set to delta_fluct
		}
		if (delta_fluct == 0) {result = TR_MTR_WRONG_MIN_MAX_VALUES; goto Tend;}
		result = mtr_th_set.set_parameters(_fluct,this);
		result = calculate_beam();//calculated from s_ to last object
		if (0 != result) goto Tend;
		result = mtr_th_read.read_parameters(_dependent,this);
		if (0 != result) goto Tend;
		for (int r = 0; r < rows; r++)
		{
			(*p_matrix)[c][r] = (_dependent[r]-def_dependent[r]) / delta_fluct;
		}
	}

Tend:
	mtr_th_set.set_parameters(def_fluct, this);
	result = calculate_beam();
	//^setting initial pars, so after this function system's parameters haven't changed. And calculate them (forgot at first)
	delete[] def_fluct;
	delete[] def_dependent;
	delete[] _fluct;
	delete[] _dependent;
	return result;
}

//doneXXXTODO: add correct behavior when num_of_measur == 1 
int v_map::read_with_criterion(double* dep, all_data* g_obj, double* sig, int size, int num_of_measur, double rejection_cr)
{
	int result = 0;
	int measured = 0;
	double **_dependent;
	_dependent = new double*[num_of_measur];
	for (int h = 0; h < num_of_measur; h++)
		_dependent[h] = new double[size];
	while (measured < num_of_measur)
	{
		while (measured < num_of_measur)
		{
			result = read_parameters(_dependent[measured], g_obj);//there are many questions about this bit
			if (0 != result) goto Tend;
			measured++;
		}
		double* sum_rel_diff = new double[num_of_measur];
		double* average = new double[size];
		double* sigma = new double[size];
		for (int h = 0; h < num_of_measur; h++)
			sum_rel_diff[h] = 0;
		for (int l = 0; l < size; l++)
		{
			sigma[l] = 0;
			average[l] = 0;
			for (int k = 0; k < num_of_measur; k++)
				average[l] += _dependent[k][l];
			average[l] = average[l] / num_of_measur;
			for (int k = 0; k < num_of_measur; k++)
				sigma[l] += (_dependent[k][l] - average[l])*(_dependent[k][l] - average[l]);
			sigma[l] = sqrt(sigma[l] / (num_of_measur - 1));
			for (int k = 0; k < num_of_measur; k++)
				sum_rel_diff[k] += abs(_dependent[k][l] - average[l]) / sigma[l];
		}
		//std::ofstream deb("_dep.txt");
		//for (int l = 0; l < size; l++)
		//{
		//	deb << average[l];  (l == size - 1) ? deb << std::endl : deb << "\t";
		//}
		//for (int l = 0; l < size; l++)
		//{
		//	deb << sigma[l];  (l == size - 1) ? deb << std::endl : deb << "\t";
		//}
		//deb << std::endl;
		//for (int k = 0; k < num_of_measur; k++)
		//{
		//	for (int l = 0; l < size; l++)
		//	{
		//		deb << _dependent[k][l]; (l == size - 1) ? deb <<std::endl : deb << "\t";
		//	}
		//}
		//deb.close();
		for (int k = 0; k < num_of_measur; k++)
		{
			if (sum_rel_diff[k]>rejection_cr*size)//XXXdone-maybe chage algorithm - consider all rows (l).
			{//found too strong flutuation
				for (int y = 0; y < size; y++)
					_dependent[k][y] = _dependent[num_of_measur - 1][y]; //free last column copy
				measured--;
				goto Found;
			}
			else
				for (int l = 0; l < size; l++)
				{
					dep[l] = average[l];
					sig[l] = sigma[l]/sqrt(num_of_measur); //sigma above - estimate of x,y sigmas, here and further is - statistical
				}
		}
	Found:;
	}
Tend:
	for (int h = 0; h < num_of_measur; h++)
		delete [] _dependent[h];
	delete[] _dependent;
	return result;
}

int all_data::build_exp_matrix() //quite defferent because also sets error matrix and reads values several times 
{
	int result = 0;
	int num_of_measur; //from prefs
	double reject_criteria; //from prefs
	if (matrix_exp)
	{
		for (int j = 0; j < n_col; j++)
			delete[] matrix_exp[j];
		delete matrix_exp;
	}
	if (matrix_uncert_exp)
	{
		for (int j = 0; j < n_col; j++)
			delete[] matrix_uncert_exp[j];
		delete matrix_uncert_exp;
	}
	matrix_exp = NULL;
	matrix_uncert_exp = NULL;
	n_col = mtr_exp_set.size();
	n_row = mtr_exp_read.size();
	if ((n_col == 0) || (n_row == 0)) return TR_EMPTY_MTR_MAPS;
	matrix_exp = new double*[n_col];
	for (int j = 0; j < n_col; j++)
	{
		matrix_exp[j] = new double[n_row];
		for (int h = 0; h < n_row; h++)
			matrix_exp[j][h] = 0; //is required?
	}
	matrix_uncert_exp = new double*[n_col];
	for (int j = 0; j < n_col; j++)
	{
		matrix_uncert_exp[j] = new double[n_row];
		for (int h = 0; h < n_row; h++)
			matrix_uncert_exp[j][h] = 0; //is required?
	}
	double *def_fluct = new double[n_col];
	double *_fluct = new double[n_col];
	double *def_dependent = new double[n_row];
	double *def_sigma = new double[n_row];
	double *sigma = new double[n_row];
	double *dependent = new double[n_row];
	result = mtr_exp_set.read_parameters(def_fluct, this); //initial parameter must be already set
	if (0 != result) goto Tend;
	if (preferences.d_simple_pars.find("g_num_of_measurements") == preferences.d_simple_pars.end())
	{result = TR_NUM_OF_MESUREMENTS_PAR_MISSING; goto Tend;}
	else num_of_measur = preferences.d_simple_pars.find("g_num_of_measurements")->second.val;
	if (preferences.d_simple_pars.find("g_sigma_rejectoin_criterion") == preferences.d_simple_pars.end())
	{result = TR_REJECTION_CRITERION_PAR_MISSING; goto Tend;}
	else reject_criteria = preferences.d_simple_pars.find("g_sigma_rejectoin_criterion")->second.val;
	//\/this is for simulation
	result = calculate_beam();//calculated from s_ to last object
	if (0 != result) goto Tend;
	//^this is for simulation
	//delete below - for test!
	//num_of_measur = 1;
	if (num_of_measur==1)
		result = mtr_exp_read.read_parameters(def_dependent, this);
	else
		result = mtr_exp_read.read_with_criterion(def_dependent,this, def_sigma, n_row, num_of_measur, reject_criteria); //must be called after calculation
	if (0 != result) goto Tend;

	for (int c = 0; c < n_col; c++)
	{
		double delta_fluct;
		for (int _c = 0; _c < n_col; _c++)
		{
			double max_, min_;
			_fluct[_c] = def_fluct[_c] /*+ (_c == c) ?
				(max_ = mtr_exp_set.get_max_by_num(_c), min_ = mtr_exp_set.get_min_by_num(_c),
				max_ - def_fluct[_c] > def_fluct[_c] - min_ ? delta_fluct = max_ - def_fluct[_c] : delta_fluct = min_ - def_fluct[_c]) : 0*/;
			if (_c == c)
			{
				max_ = mtr_th_set.get_max_by_num(_c);
				min_ = mtr_th_set.get_min_by_num(_c);
				if (max_ - def_fluct[_c] > def_fluct[_c] - min_)
					delta_fluct = max_ - def_fluct[_c];
				else
					delta_fluct = min_ - def_fluct[_c];
				_fluct[_c] += delta_fluct;
			}
			//choose maximal fluctuation (min/max value - from map) and set to delta_fluct
		}
		if (delta_fluct == 0) { result = TR_MTR_WRONG_MIN_MAX_VALUES; goto Tend; }
		result = mtr_exp_set.set_parameters(_fluct,this);
		if (0 != result) goto Tend;
		//\/this is simulation bit
		result = calculate_beam();//calculated from s_ to last object
		//^this is simulation bit 
		if (0 != result) goto Tend;
		if (num_of_measur == 1)
			result = mtr_exp_read.read_parameters(dependent,this);
		else
			result = mtr_exp_read.read_with_criterion(dependent,this, sigma, n_row, num_of_measur, reject_criteria);
		for (int r = 0; r < n_row; r++)
		{
			matrix_exp[c][r] = (dependent[r] - def_dependent[r]) / delta_fluct;
			if (num_of_measur>1) 
				matrix_uncert_exp[c][r] = sqrt(sigma[r] * sigma[r] + def_sigma[r] * def_sigma[r])/(abs(delta_fluct));
		}
	}
Tend:
	mtr_exp_set.set_parameters(def_fluct, this); 
	calculate_beam();
	//^setting initial pars, so after this function system's parameters haven't changed 
	if (num_of_measur == 1)
	{
		for (int col = 0; col < n_col; col++)
			delete[] matrix_uncert_exp[col];
		delete[] matrix_uncert_exp;
		matrix_uncert_exp = NULL;
	}
	delete[] def_fluct;
	delete[] def_dependent;
	delete[] def_sigma;
	delete[] sigma;
	delete[] dependent;
	delete[] _fluct;
	return result;
}

double all_data::operator () (const std::vector <double> &pars)
//meaning of pars may change; operator returns value to be minimized, this is later used in minuit objects
//size of pars shold be right, its made sure with right setting of minuit
//experimental matrix must be built before call of this function 
{
	if (pars.size() == 0) return - 2;
	double chi = 0;
	double *parameters;
	parameters = new double[pars.size()];
	//std::cout << "IN pars: ";
	//std::cout << std::fixed;
	for(int h = 0; h < pars.size(); h++)
	{
		parameters[h] = pars[h];
		//std::cout<< std::setprecision(6)<< parameters[h] << " | ";
	}

	par_map.set_parameters(parameters,this);
	double **matr;
	int col_ = 0;
	int row_ = 0;
	//build_exp_matrix(); //wrong: XXXTODO: uncomment this (done for testing)
	build_theor_matrix(&matr, col_, row_);
	if ((col_ != n_col) || (row_ != n_row))
	{
		for (int t = 0; t < col_; t++)
			delete[] matr[t];
		delete[] matr;
		return -1;//wrong maps, must be of same size
	}
	for (int c = 0; c < n_col; c++)
		for (int r = 0; r < n_row; r++)
			chi += (matrix_exp[c][r] - matr[c][r])*(matrix_exp[c][r] - matr[c][r]) / 
			(matrix_uncert_exp == NULL ? 1 : matrix_uncert_exp[c][r] * matrix_uncert_exp[c][r]);
	if (matrix_uncert_exp != NULL)
	{
		double fas = 0;
		for (int c = 0; c < n_col; c++)
			for (int r = 0; r < n_row; r++)
				fas += 1/(matrix_uncert_exp[c][r] * matrix_uncert_exp[c][r]);
		chi = chi/fas;
	}
	delete[] parameters;
	for (int t = 0; t < col_; t++)
		delete[] matr[t];
	delete[] matr;
	//std::cout <<std::setprecision(10)<<chi<< std::endl;
	//std::cout.unsetf(std::ios_base::fixed);
	return chi;
}

int all_data::operator () (std::vector <double> &x, std::vector <double> &y, std::vector <double> &s)
{
	x.clear();
	y.clear();
	s.clear();
	std::map<int, value_wn_r> location_pars;
	std::vector < set_pars > s_pars;
	s_pars.push_back(&corr_object::read_beam_x);
	s_pars.push_back(&corr_object::read_beam_y);
	s_pars.push_back(&corr_object::read_beam_x_out);
	s_pars.push_back(&corr_object::read_beam_y_out);
	s_pars.push_back(&corr_object::set_S);

	v_map lfdsfqsd(location_pars);
	lfdsfqsd.free_coef_for_all(value_wn_r(s_pars),&sequence, get_by_name(""), NULL);
	int size = lfdsfqsd.size();
	double* pars = new double[size];
	lfdsfqsd.read_parameters(pars, this);
	//TODO: modify interface: Code below should be done via interface. (structure is hidden).
	for (int h = 0; h < size; h++)
	{
		switch (h % 5)
		{
		case 0:
		{
			x.push_back(pars[h]);
			break;
		}
		case 1:
		{
			y.push_back(pars[h]);
			break;
		}
		case 2:
		{
			x.push_back(pars[h]);
			break;
		}
		case 3:
		{
			y.push_back(pars[h]);
			break;
		}
		case 4:
		{
			s.push_back(pars[h]);
			s.push_back(pars[h]);
			break;
		}
		}
	}
	delete[]pars;
	return 0;
}

double all_data::min_(int par_number)
{
	return par_map.get_min_by_num(par_number);
}
double all_data::max_(int par_number)
{
	return par_map.get_max_by_num(par_number);
}
int all_data::num_of_pars()
{
	return par_map.size();
}

void* all_data::set_b_x(void* v)
{
	if (v != NULL)
		beam_initial[0]=*(double*)v;
	return beam_initial;
}
void* all_data::set_b_dx(void* v)
{
	if (v != NULL)
		beam_initial[1] = *(double*)v;
	return beam_initial+1;
}

void* all_data::set_b_y(void* v)
{
	if (v != NULL)
		beam_initial[2] = *(double*)v;
	return beam_initial+2;
}
void* all_data::set_b_dy(void* v)
{
	if (v != NULL)
		beam_initial[3] = *(double*)v;
	return beam_initial+3;
}

void* all_data::set_b_p(void* v)
{
	if (v != NULL)
		beam_initial[4] = *(double*)v;
	return beam_initial + 4;
}

int all_data::write_global_pars(std::ofstream &str)//martixes, prefs?, beam initials, sequence (!cause in prefs lays copy without any fit parameters set)
{
	str << "matrix_exp" << std::endl;
	if (matrix_exp != NULL)
		for (int h = 0; h < n_row; h++)
			for (int j = 0; j < n_col; j++)
			{str << matrix_exp[j][h]; (j == (n_col - 1)) ? str << "\n" : str << "\t";}
	str << "matrix_uncert_exp" << std::endl;
	if (matrix_uncert_exp!=NULL)
		for (int h = 0; h < n_row; h++)
			for (int j = 0; j < n_col; j++)
			{str << matrix_uncert_exp[j][h]; (j == (n_col - 1)) ? str<<"\n" : str<<"\t";}
	str << "beam_initial  = ";
	int num_of_beam_pars = 5;
	for (int e = 0; e < num_of_beam_pars; e++)
	{str << beam_initial[e]; (e == num_of_beam_pars - 1) ? str<<"\n" : str<<"\t";}
	std::map <std::string, set_wv> obj_pars_keys;
	obj_pars_keys = preferences.object_pars_keys;
	obj_pars_keys.insert(std::pair<std::string, set_wv>("current", set_wv(0, &(corr_object::set_current), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("coef_x", set_wv(0, &(corr_object::set_coef_x), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("coef_y", set_wv(0, &(corr_object::set_coef_y), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("beam_x", set_wv(0, &(corr_object::read_beam_x), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("beam_y", set_wv(0, &(corr_object::read_beam_y), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("beam_x_out", set_wv(0, &(corr_object::read_beam_x_out), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("beam_y_out", set_wv(0, &(corr_object::read_beam_y_out), NULL)));
	obj_pars_keys.insert(std::pair<std::string, set_wv>("set_beam", set_wv(1, &(corr_object::set_set_beam), NULL)));
	for (int hh = 0; hh < sequence.size(); hh++)
	{
		str << "next_obj"<< std::endl;
		for (std::map<std::string, set_wv>::iterator j = obj_pars_keys.begin(); j != obj_pars_keys.end(); j++)
		{
			switch (j->second.type)
			{
			case 0:
			{
				void* val = (sequence[hh].*(j->second.set_func))(NULL);
				if (val!=NULL)
					str<<j->first << " = " << *(double*)val << std::endl;
				break;
			}
			case 1:
			{
				void* val = (sequence[hh].*(j->second.set_func))(NULL);
				if (val != NULL)
					str << j->first << " = " << *(int*)val<< std::endl;
				break;
			}
			case 2:
			{
				void* val = (sequence[hh].*(j->second.set_func))(NULL);
				if (val != NULL)
					str << j->first << " = " << "\"" + *(std::string*)val+"\"" << std::endl;
				break;
			}
			}
		}
	}
	return 0;
}
int all_data::write_map(v_map map, std::ofstream &str)
{
	for (std::map<int, value_wn_r>::iterator i = map.map.begin(); i != map.map.end(); i++)
	{
		str << "next_elem " << std::endl;
		str << "first = " << i->first<<std::endl;
		write_map_elem(i->second, str);
	}
	return 0;
}

int all_data::get_num_of_global(set_global_pars f)
{
	for (std::map<int, set_global_pars>::iterator i = global_funcs_num.begin(); i != global_funcs_num.end(); i++)
		if (i->second == f)
			return i->first;
	return -1;
}

int all_data::write_map_elem(value_wn_r el, std::ofstream &str)
{
	str << "global_metods = ";
	for (int h = 0; h < el.set_global_func.size(); h++)
	{
		int num = get_num_of_global(el.set_global_func[h]);
		if (num == -1) return A_PARCER_NO_G_METHOD_NUM;
		str << num;
		(h == el.set_global_func.size() - 1) ? str << std::endl : str<<" ";
	}
	(el.set_global_func.size() == 0) ? str << std::endl : str;
	str << "objects = ";
	for (int h = 0; h < el.obj.size(); h++)
	{
		int num = get_num_of_object(el.obj[h]);
		if (num == -1) return A_PARCER_NO_OBJECT_NUM;
		str << num;
		(h == el.obj.size() - 1) ? str<<std::endl : str<<" ";
	}
	(el.obj.size() == 0) ? str << std::endl : str;
	str << "methods = ";
	for (int h = 0; h < el.set_func.size(); h++)
	{
		int num = sequence[0].find_meth(el.set_func[h]); //don't like this. TODO: make protectioin from sequnce to be empty
		if (num == -1) return A_PARCER_NO_METHOD_NUM;
		str << num;
		(h == el.set_func.size() - 1) ? str<<std::endl : str<<" ";
	}
	(el.set_func.size() == 0) ? str << std::endl : str;
	str << "g_maxs = ";
	for (int g = 0; g < el.set_global_func.size(); g++)
	{
		str << el.max_val[g];
		(g == el.set_global_func.size() - 1) ? str<<std::endl : str<<" ";
	}
	(el.set_global_func.size() == 0) ? str << std::endl : str;
	str << "maxs = ";
	for (int m = 0; m < el.set_func.size(); m++)
		for (int ob = 0; ob < el.obj.size(); ob++)
		{
			str << el.max_val[el.set_global_func.size() + m + ob*el.set_func.size()];
			(ob == el.obj.size() - 1) ? str<<std::endl: str<<" ";
		}
	((el.set_func.size() == 0)||(el.obj.size()==0)) ? str << std::endl : str;
	str << "g_mins = ";
	for (int g = 0; g < el.set_global_func.size(); g++)
	{
		str << el.min_val[g];
		(g == el.set_global_func.size() - 1) ? str << std::endl : str << " ";
	}
	(el.set_global_func.size() == 0) ? str << std::endl : str;
	str << "mins = ";
	for (int m = 0; m < el.set_func.size(); m++)
		for (int ob = 0; ob < el.obj.size(); ob++)
		{
			str << el.min_val[el.set_global_func.size() + m + ob*el.set_func.size()];
			(ob == el.obj.size() - 1) ? str << std::endl : str << " ";
		}
	((el.set_func.size() == 0) || (el.obj.size() == 0)) ? str << std::endl : str;
	return 0;
}

value_wn_r all_data::get_by_name(std::string name)
{
	return (pars_names.find(name) == pars_names.end()) ? value_wn_r() : pars_names.find(name)->second;
}

int all_data::get_num_of_obj(v_map map, int par_number, int &out_num) //returns -1 if parameter has no object (global) or not found
{
	corr_object *p;
	int res = map.get_obj(par_number, p);
	if (res < 0) return res;
	out_num = get_num_of_object(p);
	if (out_num < 0) return -1;
	return 0;
}

int all_data::get_num_of_object(corr_object* ob) //returns -1 if parameter has no object (global) or not found
{
	for (int h = 0; h < sequence.size(); h++)
		if (&(sequence[h]) == ob)
			return h;
	return -1;
}

int v_map::get_obj(int par_number, corr_object* &out_num) //returns -1 if parameter has no object (global)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (!((i->first <= par_number) && (par_number < i->first + i->second.par_size())))
			continue; //this number is not this element
		int par_counter = par_number - i->first;
		par_counter -= i->second.set_global_func.size();
		if (par_counter < 0) return -1;
		else
		{
			out_num = i->second.obj[par_counter/i->second.set_func.size()];
			return 0;
		}
	}
	return -1;
}
int v_map::get_method(int par_number, value_wn_r &out_num)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (!((i->first <= par_number) && (par_number < i->first + i->second.par_size())))
			continue; //this number is not this element
		int par_counter = par_number - i->first;
		if (par_counter < i->second.set_global_func.size())
			out_num = value_wn_r(std::vector<set_global_pars>(1,i->second.set_global_func[par_counter])); 
			//map can contain only double methods, so default type is used
		else
		{
			par_counter -= i->second.set_global_func.size();
			out_num = value_wn_r(std::vector<set_pars>(1, i->second.set_func[par_counter%i->second.set_func.size()]));
			//map can contain only double methods, so default type is used
		}
		return 0;
	}
	return -1;
}

int v_map::set_parameters_vals(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj)
{return set_parameters_(0, parameter, vals, search, search_data, g_obj);}
int v_map::set_parameters_vals(double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data)
{return set_parameters_(0, coef_arr,parameter, vals, search, search_data);}
int v_map::set_parameters_mins(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj)
{return set_parameters_(1, parameter, vals, search, search_data, g_obj); }
int v_map::set_parameters_mins(double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data)
{return set_parameters_(1, coef_arr, parameter, vals, search, search_data);}
int v_map::set_parameters_maxs(value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj)
{return set_parameters_(2, parameter, vals, search, search_data, g_obj); }
int v_map::set_parameters_maxs(double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data)
{return set_parameters_(2, coef_arr, parameter, vals, search, search_data);}
//^these are wrappers for functions below

//if v_m_m == 3 value must be size of 2
int v_map::assign(int v_m_m, all_data* g_obj, value_wn_r &to, double *value, int meth)
{
	switch (v_m_m)
	{
	case 0:
	{
		if (NULL!=g_obj)
			((*g_obj).*(to.set_global_func[meth]))(value);
		break;
	}
	case 1:
	{
		to.min_val[meth] = *value;
		break;
	}
	case 2:
	{
		to.max_val[meth] = *value;
		break;
	}
	case 3:
	{
		to.max_val[meth] = *(value+1);
		to.min_val[meth] = *(value);
		break;
	}
	}
	return 0;
}

//if v_m_m == 3 value must be size of 2
int v_map::assign(int v_m_m, value_wn_r &to, double *value, int meth, int ob)
{ 
	switch (v_m_m)
	{
	case 0:
	{
		((*to.obj[ob]).*(to.set_func[meth]))(value);
		break;
	}
	case 1:
	{
		double min_ = *value;
		double max_ = to.max_val[to.set_global_func.size() + ob*to.set_func.size() + meth]; //take old
		int ret = to.obj[ob]->find_limits(to.set_func[meth], &min_, &max_);
		/*override limits with local values. Only for current at the moment.
		this is done because current (I[A]) limits are related to real limitation of equipment and thus should be defined 
		in corr_objects as its personal characteristics, whereas
		others limitation are set quite arbitrary - only for minuit to approximate correctly - and better be 
		defined outside corr_object*/
		if ((0 != ret) && (NO_LOCAL_OVERRIDE != ret)) 
			return ret; 
		to.min_val[to.set_global_func.size() + ob*to.set_func.size() + meth] = min_;
		break;
	}
	case 2:
	{
		double min_ = to.min_val[to.set_global_func.size() + ob*to.set_func.size() + meth]; //take old
		double max_ = *value;
		int ret = to.obj[ob]->find_limits(to.set_func[meth], &min_, &max_);
		if ((0 != ret) && (NO_LOCAL_OVERRIDE != ret))
			return ret;
		to.max_val[to.set_global_func.size() + ob*to.set_func.size() + meth] = max_;
		break;
	}
	case 3:
	{
		double min_ = *(value);
		double max_ = *(value+1);
		int ret = to.obj[ob]->find_limits(to.set_func[meth], &min_, &max_);
		if ((0 != ret) && (NO_LOCAL_OVERRIDE != ret))
			return ret;
		to.max_val[to.set_global_func.size() + ob*to.set_func.size() + meth] = max_;
		to.min_val[to.set_global_func.size() + ob*to.set_func.size() + meth] = min_;
		break;
	}
	}
	return 0;
}

int v_map::set_parameters_(int v_m_m, value_wn_r parameter, double* vals, value_wn_r search, void** search_data, all_data* g_obj)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		for (int h = 0; h < i->second.set_global_func.size(); h++)
			for (int g = 0; g < parameter.set_global_func.size(); g++)
				if (i->second.set_global_func[h] == parameter.set_global_func[g])
				{
					int ret = assign(v_m_m, g_obj, i->second, vals + g, h);
					if (0 != ret)
						return ret;
					break;
				}
		for (int ob = 0; ob < i->second.obj.size(); ob++)
			if (search.is_satisfy_search(i->second.obj[ob], search_data))
				for (int meth = 0; meth < i->second.set_func.size(); meth++)
					for (int ext_m = 0; ext_m < parameter.set_func.size(); ext_m++)
						if (i->second.set_func[meth] == parameter.set_func[ext_m])
						{
							int ret = assign(v_m_m, i->second, vals + parameter.set_global_func.size() + ext_m, meth, ob);
							if (0 != ret)
								return ret;
							break;
						}
	}
	return 0;
}
int v_map::set_parameters_(int v_m_m, double* coef_arr, value_wn_r parameter, double* vals, value_wn_r search, void** search_data)
{
	for (std::map<int, value_wn_r>::iterator i = map.begin(); i != map.end(); i++)
	{
		for (int h = 0; h < i->second.set_global_func.size(); h++)
			for (int g = 0; g < parameter.set_global_func.size(); g++)
				if (i->second.set_global_func[h] == parameter.set_global_func[g])
				{
					coef_arr[i->first + h] = *(vals + g);
					break;
				}
		for (int ob = 0; ob < i->second.obj.size(); ob++)
			if (search.is_satisfy_search(i->second.obj[ob], search_data))
				for (int meth = 0; meth < i->second.set_func.size(); meth++)
					for (int ext_m = 0; ext_m < parameter.set_func.size(); ext_m++)
						if (i->second.set_func[meth] == parameter.set_func[ext_m])
						{
							coef_arr[i->first + ob*i->second.set_func.size() + meth] = *(vals + parameter.set_global_func.size() + ext_m);
							break;
						}
	}
	return 0;
}

int all_data::set_parameters_values(value_wn_r parameter, double* vals, value_wn_r search, void** search_data)
{
	for (int g = 0; g < parameter.set_global_func.size(); g++)
		((*this).*(parameter.set_global_func[g]))(vals + g);
	for (int ob = 0; ob < sequence.size(); ob++)
		if (search.is_satisfy_search(&sequence[ob], search_data))
			for (int meth = 0; meth < parameter.set_func.size(); meth++)
				(sequence[ob].*(parameter.set_func[meth]))(vals+parameter.set_global_func.size()+meth);
	return 0;
}

int all_data::test_f(int par)
{
	int res = 0;
	//value_wn_r search = value_wn_r(std::vector<set_pars>(1, &corr_object::set_type_name),std::vector<corr_object*>(),std::vector<int>(1,2));
	std::string search_data("dipole_d");
	//std::string* p_data = &search_data;
	void** pointer = new void*[1];
	pointer[0] = &search_data;
	search_data = "quadrupole";
	par_map.free_coef_for_all(get_by_name("coef_x"), &sequence, get_by_name("type_name"), pointer);
	//par_map.free_coef_for_all(get_by_name("coef_y"), &sequence, get_by_name("type_name"), pointer);
	par_map.free_coef_for_all(get_by_name("x'_in"), &sequence, get_by_name(""), pointer);
	set_def_limits(par_map);
	
	search_data = "pickup";
	mtr_th_read.free_coef_for_all(get_by_name("X"), &sequence, get_by_name("type_name"), pointer);
	//mtr_th_read.free_coef_for_all(get_by_name("Y"), &sequence, get_by_name("type_name"), pointer);
	set_def_limits(mtr_th_read);
	search_data = "p0";
	mtr_th_read.fix_coef_for_all(get_by_name("X"), get_by_name("pers_name"), pointer);
	//mtr_th_read.fix_coef_for_all(get_by_name("Y"),get_by_name("pers_name"), pointer);

	search_data = "dipole";
	mtr_th_set.free_coef_for_all(get_by_name("I"), &sequence, get_by_name("type_name"), pointer);
	/*search_data = "quadrupole";
	mtr_th_set.free_coef_for_all(get_by_name("I"), &sequence, get_by_name("type_name"), pointer);*/
	res = set_def_limits(mtr_th_set);

	search_data = "dipole";
	mtr_exp_set.free_coef_for_all(get_by_name("I"), &sequence, get_by_name("type_name"), pointer);
	/*search_data = "quadrupole";
	mtr_exp_set.free_coef_for_all(get_by_name("I"), &sequence, get_by_name("type_name"), pointer);*/
	set_def_limits(mtr_exp_set);
	search_data = "pickup";
	mtr_exp_read.free_coef_for_all(get_by_name("eX"), &sequence, get_by_name("type_name"), pointer);
	//mtr_exp_read.free_coef_for_all(get_by_name("eY"), &sequence, get_by_name("type_name"), pointer);
	set_def_limits(mtr_exp_read);
	search_data = "p0";
	mtr_exp_read.fix_coef_for_all(get_by_name("eX"), get_by_name("pers_name"), pointer);
	//mtr_th_read.fix_coef_for_all(get_by_name("eY"), get_by_name("pers_name"), pointer);

	std::ofstream map_file;
	map_file.open("gl_test1.txt");
	write_global_pars(map_file);
	map_file.close();

	map_file.open("map_test_I_before.txt");
	write_map(mtr_th_set, map_file);
	map_file.close();

	double *vals = new double[1];
	*vals = 0.2; //corrector length
	search_data = "dipole";
	set_parameters_values(get_by_name("L"), vals, get_by_name("type_name"), pointer);
	*vals = 0;//3;
	search_data = "dipole";
	set_parameters_values(get_by_name("I"), vals, get_by_name("type_name"), pointer);
	*vals = 0.003;//now all are the same (report3);
	search_data = "dipole";
	set_parameters_values(get_by_name("coef_x"), vals, get_by_name("type_name"), pointer);

	*vals = 0.15;
	search_data = "quadrupole";
	set_parameters_values(get_by_name("L"), vals, get_by_name("type_name"), pointer);
	*vals = 10;
	set_parameters_values(get_by_name("I"), vals, get_by_name("type_name"), pointer);
	
	double* min_lims_arr = new double[1];
	double* max_lims_arr = new double[1];
	//TUNING I LIMITS
	*vals = 2.5;//2.5
	search_data = "c1";
	min_lims_arr[0] = 2.36;	//d=0.14
	max_lims_arr[0] = 2.61;
	mtr_th_set.set_coef_lims(get_by_name("I"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = 0.5;//0.5
	search_data = "c2";
	min_lims_arr[0] = 0.43;	//d=0.09
	max_lims_arr[0] = 0.59;
	mtr_th_set.set_coef_lims(get_by_name("I"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = -5; //-5
	search_data = "c3";
	min_lims_arr[0] = -5.13;//d=0.18
	max_lims_arr[0] = -4.82;
	mtr_th_set.set_coef_lims(get_by_name("I"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = -10; //-10
	search_data = "c4";
	min_lims_arr[0] = -11.8;//d=2.4
	max_lims_arr[0] = -7.6;
	mtr_th_set.set_coef_lims(get_by_name("I"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = 10;
	search_data = "q3";
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = 10;
	search_data = "q4";
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);

	*vals = -0.5; //-0.5
	search_data = "c5";
	min_lims_arr[0] = -1.2;//d=1
	max_lims_arr[0] = 0.5;
	mtr_th_set.set_coef_lims(get_by_name("I"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);

	*vals = 10;
	search_data = "q5";
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	*vals = 10;
	search_data = "q6";
	set_parameters_values(get_by_name("I"), vals, get_by_name("pers_name"), pointer);
	//END TUNING I LIMITS

	map_file.open("gl_test2.txt");
	write_global_pars(map_file);
	map_file.close();
	map_file.open("map_test_Fit0.txt");
	par_map.write(map_file,this);
	map_file.close();


	min_lims_arr[0] = 0.122; //+- 40% of 0.32 (3 quadrupoles) and +-32% of 0.4 (also 3 quadrupoles). Expected fluct: 10-20%
	max_lims_arr[0] = 0.448;
	search_data = "quadrupole";
	par_map.set_coef_lims(get_by_name("coef_x"), max_lims_arr, min_lims_arr, get_by_name("type_name"), pointer);
	min_lims_arr[0] = -0.448;
	max_lims_arr[0] = -0.122;
	search_data = "q1";
	par_map.set_coef_lims(get_by_name("coef_x"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	search_data = "q3";
	par_map.set_coef_lims(get_by_name("coef_x"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	search_data = "q5";
	par_map.set_coef_lims(get_by_name("coef_x"), max_lims_arr, min_lims_arr, get_by_name("pers_name"), pointer);
	//min_lims_arr[0] = 0.003;
	//max_lims_arr[0] = 0.008;
	//par_map.set_coef_lims(get_by_name("x_in"), max_lims_arr, min_lims_arr, get_by_name(""), pointer);

	map_file.open("map_test_Fit1.txt");
	write_map(par_map, map_file);
	map_file.close();

	beam_initial[0] = 0.005;
	beam_initial[1] = 0.0012; //only this has changed, so fit only with x
	beam_initial[2] = 0.01;
	beam_initial[3] = 0.000005;

	map_file.open("pars_true.txt");
	par_map.write(map_file, this);
	map_file.close();

	res = calculate_beam();

	map_file.open("C:\\Users\\Bitch\\Desktop\\Top\\Global\\gnuplot\\bin\\beam0.txt");
	write_beam(map_file);
	map_file.close();

	build_theor_matrix(&matrix_exp, n_col, n_row);
	map_file.open("Mtrue.txt");
	write_global_pars(map_file);
	map_file.close();

	
	/*res = calculate_beam();

	map_file.open("C:\\Users\\Bitch\\Desktop\\Top\\Global\\gnuplot\\bin\\beamt.txt");
	write_beam(map_file);
	map_file.close();*/ //for I limits tuning

	build_exp_matrix();
	map_file.open("Mexper.txt");
	write_global_pars(map_file);
	map_file.close();

	//now change parameters and see what happens to matrix
	//The main question - is method valid and consistent at all
	//below are initial defaults
	beam_initial[0] = 0.005;
	beam_initial[1] = 0.0008;
	beam_initial[2] = 0.01;
	beam_initial[3] = 0.000005;

	double *coefs = new double[par_map.size()];
	par_map.read_parameters(coefs, this);
	//SETTING PROJECT QUADRUPOLE PARAMETERS
	vals[0] = -0.32;
	search_data = "q1";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);
	vals[0] = 0.32;
	search_data = "q2";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);
	vals[0] = -0.4;
	search_data = "q3";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);
	vals[0] = 0.4;
	search_data = "q4";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);
	vals[0] = -0.4;
	search_data = "q5";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);
	vals[0] = 0.32;
	search_data = "q6";
	par_map.set_parameters_vals(coefs, get_by_name("coef_x"), vals, get_by_name("pers_name"), pointer);

	par_map.set_parameters(coefs, this); //want to see sensivity to .coef change
	calculate_beam();
	
	//also forming this fit will be done
	double**temp; //for writing in file and saving old matrix exp
	temp = new double*[n_col];
	for (int c = 0; c < n_col;c++)
	{
		temp[c] = new double[n_row];
		for (int r = 0; r < n_row; r++)
			temp[c][r] = matrix_exp[c][r];
	}

	build_theor_matrix(&matrix_exp, n_col, n_row);
	map_file.open("Mfrom.txt");
	write_global_pars(map_file);
	map_file.close();
	for (int c = 0; c < n_col; c++)
	{
		for (int r = 0; r < n_row; r++)
			matrix_exp[c][r] = temp[c][r];
		delete temp[c];
	}
	delete temp;

	map_file.open("C:\\Users\\Bitch\\Desktop\\Top\\Global\\gnuplot\\bin\\beam1.txt"); //see coef change effect
	write_beam(map_file);
	map_file.close();

	map_file.open("pars_from.txt");
	par_map.write(map_file, this);
	map_file.close();

	map_file.open("map_test_Fit2.txt");
	write_map(par_map, map_file);
	map_file.close();

	map_file.open("map_test_I.txt");
	write_map(mtr_th_set, map_file);
	map_file.close();

	delete[] min_lims_arr;
	delete[] max_lims_arr;
	delete[] pointer;
	delete[] coefs;
	delete[] vals;
	return res;
}

int all_data::write_beam(std::ofstream &str)
{
	int res = 0;
	std::vector<double> xs;
	std::vector<double> ys;
	std::vector<double> Ss;
	res = (*this)(xs, ys, Ss);
	str << "X\tY\tS" << std::endl;
	int max_size = xs.size();
	max_size = max_size > ys.size() ? max_size : ys.size();
	max_size = max_size > Ss.size() ? max_size : Ss.size();
	for (int e = 0; e < max_size; e++)
	{
		((e < xs.size()) ? str<< xs[e] : str<< "\t") << "\t";
		((e < ys.size()) ? str<< ys[e] : str<< "\t") << "\t";
		((e < Ss.size()) ? str<< Ss[e] : str<< "\t") << "\n";
	}
	return 0;
}
