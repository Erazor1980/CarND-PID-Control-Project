#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init( double Kp, double Ki, double Kd )
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;

	cte_prev = 0;
	cte_sum = 0;
}

void PID::UpdateError( double cte )
{
	//steer = -tau_p * cte - tau_d * ( cte - prevCTE ) - tau_i * cteSum
	cte_sum += cte;

	p_error = -Kp * cte;
	i_error = -Ki * cte_sum;
	d_error = -Kd * ( cte - cte_prev );
	
	cte_prev = cte;
}

double PID::TotalError()
{
	const double s = p_error + d_error + i_error;;

	if( s < -1 )
	{
		return -1;
	}
	else if( s > 1 )
	{
		return 1;
	}

	return s;
}

