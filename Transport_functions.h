#include <math.h>
//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
//pars [1] and pars[0] must not be 0!
//same as corrector
int tr_dipole_magnet(double *pars, double* beam_pars);


//beam_pars must be size of 5 (x, x', y, y', p)
//this version is NOT MATRIX MODEL - because correctors aren't in main optical system, they correct beam, different from project,
//but for every trajectory corrector paremeters are diffrent (so matrix model is not acceptable - this is not circular machine after all).
//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
int tr_dipole_magnet_v2(double *pars, double* beam_pars); //with parallel edge - it's corrector

//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
//pars [1] must not be 0!
int tr_quadrupole_magnet(double *pars, double* beam_pars);

//pars[0] - current, pars[1] - focus_coef_x, pars[2] = focus_coef_y, pars[3] - length, pars[4] - th_input, pars[5] - S, pars[6] = type
//beam_pars must be size of 5 (x, x', y, y', p)
//turn magnet
int tr_sector_magnet(double *pars, double* beam_pars); 

//pars[0] - s, rest ignored
int tr_empty_space(double *pars, double* beam_pars);
