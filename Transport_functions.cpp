#include "Transport_functions.h"
//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
int tr_dipole_magnet(double *pars, double* beam_pars) //with parallel edge - it's corrector
{
	//at the moments coef_y shows whether it is X or Y corrector (<0 and >0 resp.)
	//TODO: make coefs_x and y arbitrary (transfer matrix rotation will be required);
	//problem - input angle reference.
	double R = 3.3 *beam_pars[4] / (pars[1] * pars[0]);
	//\/_o for _out
	double sin_o = pars[3]/R - sin(pars[4]);
	double cos_o = sqrt(1-sin_o*sin_o);
	double th_o = asin(sin_o);
	double th_i = pars[4];
	double x = beam_pars[0];
	double xx = beam_pars[1];
	double y = beam_pars[2];
	double yy = beam_pars[3];
	if (pars[2] > 0)
	{
		beam_pars[0] = x*cos_o/cos(th_i) + xx*R*sin(th_i+th_o);
		beam_pars[1] = xx*cos(th_i) / cos_o;
		beam_pars[2] = y*(1 - (th_i + th_o)*tan(th_i)) + yy*R*(th_i + th_o);
		beam_pars[3] = y*((th_i+th_o)*sin(th_i)*sin_o-sin(th_o+th_i))/(R*cos(th_i)*cos_o) + yy*(1- sin_o/cos_o);
	}
	else
	{
		beam_pars[0] = x*(1 - (th_i + th_o)*tan(th_i)) + xx*R*(th_i + th_o);
		beam_pars[1] = x*((th_i + th_o)*sin(th_i)*sin_o - sin(th_o + th_i)) / (R*cos(th_i)*cos_o) + xx*(1 - sin_o / cos_o);
		beam_pars[2] = y*cos_o / cos(th_i) + yy*R*sin(th_i + th_o);
		beam_pars[3] = yy*cos(th_i) / cos_o;
	}
	return 0;
}

//beam_pars must be size of 5 (x, x', y, y', p)
//this version is NOT MATRIX MODEL - because correctors aren't in main optical system, they correct beam, different from project,
//but for every trajectory corrector paremeters are diffrent (so matrix model is not acceptable - this is not circular machine after all).
//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
int tr_dipole_magnet_v2(double *pars, double* beam_pars) //with parallel edge - it's corrector
{
	//at the moments coef_y shows whether it is X or Y corrector (<0 and >0 resp.)
	//TODO: make coefs_x and y arbitrary (transfer matrix rotation will be required);
	//problem - input angle reference.
	if (pars[1] * pars[0] == 0) //need better condition? e.g. abs()<1e-10??
		return tr_empty_space(pars + 3, beam_pars);
	double R = 3.3 *beam_pars[4] / (pars[1] * pars[0]); //R>0 - X decrease == x focusing !!!
	//\/_o for _out
	double x = beam_pars[0];
	double xx = beam_pars[1];
	double y = beam_pars[2];
	double yy = beam_pars[3];
	if (pars[2] > 0)
	{
		beam_pars[0] = x+pars[3]*xx - pars[3]*pars[3]/(2*R);
		beam_pars[1] = xx - pars[3] / R;
	}
	else
	{
		beam_pars[2] = y + pars[3] * yy - pars[3] * pars[3] / (2 * R);
		beam_pars[3] = xx - pars[3] / R;
	}
	return 0;
}

//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
//pars [1] must not be 0!
int tr_quadrupole_magnet(double *pars, double* beam_pars) //is this right???
{
	double kappa = pars[0] * pars[1]/(3.3*beam_pars[4]);
	kappa = abs(kappa);
	double arg = sqrt(kappa)*pars[3];
	double x = beam_pars[0];
	double xx = beam_pars[1];
	double y = beam_pars[2];
	double yy = beam_pars[3];
	if (kappa <1e-12) kappa = 1e-12; //not nice
	if (pars[1] < 0) //x focusing
	{
		beam_pars[0] = x*cos(arg) + xx*sin(arg) / sqrt(kappa);
		beam_pars[1] = -x*sqrt(kappa)*sin(arg) + xx*cos(arg);
		beam_pars[2] = y*cosh(arg) + yy*sinh(arg) / sqrt(kappa);
		beam_pars[3] = y*sqrt(kappa)*sinh(arg) + yy*cosh(arg);
	}
	else //y focusing
	{
		beam_pars[0] = x*cosh(arg) + xx*sinh(arg) / sqrt(kappa);
		beam_pars[1] = x*sqrt(kappa)*sinh(arg) + xx*cosh(arg);
		beam_pars[2] = y*cos(arg) + yy*sin(arg) / sqrt(kappa);
		beam_pars[3] = -y*sqrt(kappa)*sin(arg) + yy*cos(arg);
	}
	return 0;
}

//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
//pars [1] and pars [0] must not be 0!
int tr_sector_magnet(double *pars, double* beam_pars)
{
	double R = 3.3*beam_pars[4] / (pars[1]*pars[0]);
	double kappa = 1 / (R*R) - pars[2] * pars[0] / (3.3*beam_pars[4]); //>0???
	if (kappa < 0.000001) kappa = 0.000001; //can't be less then or equal to 0 //TODO: make sure >0
	double arg = sqrt(kappa)*pars[3];
	double x = beam_pars[0];
	double xx = beam_pars[1];
	double y = beam_pars[2];
	double yy = beam_pars[3];
	beam_pars[0] = x*cos(arg) + xx*sin(arg) / sqrt(kappa);
	beam_pars[1] = -x*sqrt(kappa)*sin(arg) + xx*cos(arg);
	kappa = pars[2] * pars[0] / (3.3*beam_pars[4]);
	if (kappa > 0)
	{
		if (kappa < 0.000001) kappa = 0.000001; //0 check
		arg = sqrt(kappa)*pars[3];
		beam_pars[2] = y*cosh(arg) + yy*sinh(arg) / sqrt(kappa);
		beam_pars[3] = y*sqrt(kappa)*sinh(arg) + yy*cosh(arg);
	}
	else
	{
		if (kappa > -0.000001) kappa = -0.000001; //0 check
		arg = sqrt(kappa)*pars[3];
		beam_pars[2] = y*cos(arg) + yy*sin(arg) / sqrt(kappa);
		beam_pars[3] = -y*sqrt(kappa)*sin(arg) + yy*cos(arg);
	}
	return 0;
}

//pars[0] - delta s, and nothing more, see all_data::calculate_beam
int tr_empty_space(double *pars, double* beam_pars)
{
	double x = beam_pars[0];
	double xx = beam_pars[1];
	double y = beam_pars[2];
	double yy = beam_pars[3];
	beam_pars[0] = x + pars[0] * xx;
	beam_pars[2] = y + yy*pars[0];
	return 0;
}
