#include "Object.h"

corr_object::corr_object()
{
	transport_function = NULL;
	type = 1;
	S = 0;
	set_beam = 0;
	current = 0.3;
	length = 0;
	focus_coef_x = 0.01;
	focus_coef_y = 0.01;
	max_current = 0;
	min_current = 0;
	max_rel_curr_fluct = 0;
	max_abs_curr_fluct = 0;
	type_name = std::string();
	pers_name = std::string();
	//local_lims.insert(std::pair<set_pars, local_limits>(&corr_object::set_current, &corr_object::curr_lims)); //called form all_data::set_default_limits
	lim_num.insert(std::pair<int, local_limits>(4, &corr_object::curr_lims));
	//lim_num.insert(std::pair<int, local_limits>(6, &corr_object::coef_x_lims));
	//lim_num.insert(std::pair<int, local_limits>(7, &corr_object::coef_y_lims));

	set_num.insert(std::pair<int, set_pars>(4, &corr_object::set_current)); //keys must be !=-1.//also requred for file input/output

	set_num.insert(std::pair<int, set_pars>(0, &corr_object::set_type));
	set_num.insert(std::pair<int, set_pars>(1, &corr_object::set_type_name));
	set_num.insert(std::pair<int, set_pars>(2, &corr_object::set_pers_name));
	set_num.insert(std::pair<int, set_pars>(3, &corr_object::set_S));
	//set_num.insert(std::pair<int, set_pars>(5, &corr_object::set_function));
	//can'r be read or wirtten from/to file
	set_num.insert(std::pair<int, set_pars>(6, &corr_object::set_coef_x));
	set_num.insert(std::pair<int, set_pars>(7, &corr_object::set_coef_y));
	set_num.insert(std::pair<int, set_pars>(8, &corr_object::set_length));
	set_num.insert(std::pair<int, set_pars>(9, &corr_object::set_e_current));
	set_num.insert(std::pair<int, set_pars>(10, &corr_object::read_beam_x));
	set_num.insert(std::pair<int, set_pars>(11, &corr_object::read_beam_y));
	set_num.insert(std::pair<int, set_pars>(12, &corr_object::set_max_current));
	set_num.insert(std::pair<int, set_pars>(13, &corr_object::set_min_current));
	set_num.insert(std::pair<int, set_pars>(14, &corr_object::set_max_rel_curr_fluct));
	set_num.insert(std::pair<int, set_pars>(15, &corr_object::set_max_abs_curr_fluct));
	set_num.insert(std::pair<int, set_pars>(16, &corr_object::read_beam_x_out));
	set_num.insert(std::pair<int, set_pars>(17, &corr_object::read_beam_y_out));
	set_num.insert(std::pair<int, set_pars>(18, &corr_object::read_e_beam_x));
	set_num.insert(std::pair<int, set_pars>(19, &corr_object::read_e_beam_y));
	set_num.insert(std::pair<int, set_pars>(20, &corr_object::set_th_i));
	set_num.insert(std::pair<int, set_pars>(21, &corr_object::set_coef_x_min));
	set_num.insert(std::pair<int, set_pars>(22, &corr_object::set_coef_x_max));
	set_num.insert(std::pair<int, set_pars>(23, &corr_object::set_coef_y_min));
	set_num.insert(std::pair<int, set_pars>(24, &corr_object::set_coef_y_max));
}

int corr_object::find_meth(set_pars meth)
{
	for (std::map<int, set_pars>::iterator i = set_num.begin(); i != set_num.end(); i++)
		if (i->second == meth)
			return  i->first;
	return -1;
}

int corr_object::find_limits(set_pars _for, local_limits &out)
{
	int key = find_meth(_for);
	if (key == -1) return key;
	if (lim_num.find(key) != lim_num.end())
		out = lim_num.find(key)->second;
	else return -1;
	return 0;
}

int corr_object::find_limits(set_pars _for, double* min, double *max)
{
	local_limits l_l;
	if (-1 == find_limits(_for, l_l))
		return NO_LOCAL_OVERRIDE;
	return ((*this).*l_l)(min, max);
}

//TODO: decide whether two functions below are required (that is to decide whether coefs mins/maxs will be set via file)
//probably will have to add is_override to objects' locals with subsequent methods
int corr_object::coef_x_lims(double* min, double* max)
{
	//if (this->is_override)???
	if (*min == *max) //used locals, this happens when global defaults for limits arent'used
	{
		*min = coef_x_min;
		*max = coef_x_max;
	}
	return 0;
}

int corr_object::coef_y_lims(double* min, double* max)
{
	if (*min == *max) //used locals, this happens when global defaults for limits arent'used
	{
		*min = coef_x_min;
		*max = coef_x_max;
	}
	return 0;
}

int corr_object::curr_lims(double* min, double* max)
{
	//limits set from all_data can't exceed local limitations 
	double local_max = (max_rel_curr_fluct == 0) ? max_current : //if ==0 - means not fluctuatio allowed but that it is not a limitation
		(max_current < current*(1 + max_rel_curr_fluct / 100.0) ? max_current : current*(1 + max_rel_curr_fluct / 100.0));
	local_max = (max_abs_curr_fluct == 0) ? local_max : (local_max < current + max_abs_curr_fluct) ? local_max : current + max_abs_curr_fluct;
	local_max = local_max>min_current ? local_max : min_current; //just in case. 
	double local_min = (max_rel_curr_fluct == 0) ? min_current :
		(min_current > current*(1 - max_rel_curr_fluct / 100.0) ? min_current : current*(1 - max_rel_curr_fluct / 100.0));
	local_min = (max_abs_curr_fluct == 0) ? local_min : (local_min > current - max_abs_curr_fluct) ? local_min : current - max_abs_curr_fluct;
	local_min = local_min<max_current ? local_min : max_current; //just in case.
	if (*min == *max)//means no external limits are set, local used; currently used for current parameter min/max set 
	{
		*min = local_min;
		*max = local_max;
		return 0;
	}
	*min = (*min > local_min) ? *min : local_min;
	*min = (*min < local_max) ? *min : local_max;
	*max = (*max < local_max) ? *max : local_max;
	*max = (*max > local_min) ? *max : local_min;
	if (*min>*max) return TR_WRONG_LOCAL_LIMITS;
	return 0;
}

void* corr_object::set_e_current(void* data) //not defined yet
{
	return data;
}

void* corr_object::read_e_beam_x(void* data)
{
	if (!set_beam) return NULL;
	std::normal_distribution <double> dist(beam_x, UNCERT_SIM_);
	beam_x_exp = dist(*gener); //call of global var
	return &beam_x_exp;
}

void* corr_object::read_e_beam_y(void* data)
{
	if (!set_beam) return NULL;
	std::normal_distribution <double> dist(beam_y, UNCERT_SIM_);
	beam_y_exp = dist(*gener); //call of global var
	return &beam_y_exp;
}

void* corr_object::set_set_beam(void* t) { if (NULL != t){ set_beam = *(double*)t; } return &(this->set_beam); }
void* corr_object::set_coef_x(void* coef) { if (NULL != coef){ focus_coef_x = *(double*)coef; } return &(this->focus_coef_x); }
void* corr_object::set_coef_y(void* coef) { if (NULL != coef){ focus_coef_y = *(double*)coef; } return &(this->focus_coef_y); }
void* corr_object::set_length(void* len) { if (NULL != len){ length = *(double*)len; } return &(this->length); }
void* corr_object::set_current(void* curr) { if (NULL != curr){ current = *(double*)curr; } return &(this->current); }
void* corr_object::set_th_i(void* data) { if (NULL != data){ th_input = *(double*)data; } return &(this->th_input); }
void* corr_object::set_function(void* f) { if (NULL != f){ transport_function = (int(*)(double*, double*))f; } return &(this->transport_function); }
void* corr_object::set_S(void* SS) { if (NULL != SS){ S = *(double*)SS; } return &(this->S); }
void* corr_object::set_max_current(void* val) { if (NULL != val){ max_current = *(double*)val; } return &(this->max_current); }
void* corr_object::set_min_current(void* val) { if (NULL != val){ min_current = *(double*)val; }  return &(this->min_current); }
void* corr_object::set_max_rel_curr_fluct(void* val) { if (NULL != val){ max_rel_curr_fluct = *(double*)val; }  return &(this->max_rel_curr_fluct); }
void* corr_object::set_max_abs_curr_fluct(void* val) { if (NULL != val){ max_abs_curr_fluct = *(double*)val; }  return &(this->max_abs_curr_fluct); }
void* corr_object::set_type_name(void* tn) { if (NULL != tn){ type_name = *(std::string*)tn; }  return &(this->type_name); }
void* corr_object::set_pers_name(void* tn) { if (NULL != tn){ pers_name = *(std::string*)tn; }  return &(this->pers_name); }
void* corr_object::read_beam_x(void* data) { if (NULL != data) beam_x = *(double*)data; return set_beam ? &beam_x : NULL; } //not NULL should be called in loading from file only
void* corr_object::read_beam_y(void* data) { if (NULL != data) beam_y = *(double*)data; return set_beam ? &beam_y : NULL; }
void* corr_object::read_beam_x_out(void* data) { if (NULL != data) beam_x_out = *(double*)data; return set_beam ? &beam_x_out : NULL; } //not NULL should be called in loading from file only
void* corr_object::read_beam_y_out(void* data) { if (NULL != data) beam_y_out = *(double*)data; return set_beam ? &beam_y_out : NULL; }
void* corr_object::set_coef_x_min(void* d){ if (NULL != d){ coef_x_min = *(double*)d; } return &(this->coef_x_min); }
void* corr_object::set_coef_x_max(void* d){ if (NULL != d){ coef_x_max = *(double*)d; } return &(this->coef_x_max); }
void* corr_object::set_coef_y_min(void* d){ if (NULL != d){ coef_y_min = *(double*)d; } return &(this->coef_y_min); }
void* corr_object::set_coef_y_max(void* d){ if (NULL != d){ coef_y_max = *(double*)d; } return &(this->coef_y_max); }
void* corr_object::set_type(void* t)
{
	if (NULL != t)
	{
		type = (int)(*(double*)t);
		switch ((int)type)
		{
		case 1:
		{
			set_type_name(&std::string("dipole"));
			set_function((void*)tr_dipole_magnet_v2);
			break;
		}
		case 2:
		{
			set_type_name(&std::string("quadrupole"));
			set_function((void*)tr_quadrupole_magnet);
			break;
		}
		case 3:
		{
			set_type_name(&std::string("pickup"));
			set_function(NULL);
			break;
		}
		case 4:
		{
			set_type_name(&std::string("sector"));
			set_function(tr_sector_magnet);
			break;
		}
		}
	}
	return (void*)&(this->type);
}