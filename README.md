# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Describe the effect each of the P, I, D components had in your implementation.
'P' stands for the proportional gain. It tells how strong we are steering proportional to the CTE (cross track error).
'D' stands for the differential gain. It allows the car to counter steer if the CTE is getting smaller (i.e. it uses the temporal derivative of the crosstrack error) and allows to approach the target trajectory more smoothly.
And finally the 'I' stands for the integral term. It is used to adjust to a possible systematic bias (like front wheels not exactly at 0° angle).

## Describe how the final hyperparameters were chosen.
The 'I' parameter was set to 0 because the car in the simulation has no systematic bias. The other parameters where chosen by hand, which led to a fast satisfying result.
Otherwise a method like the "Twiddle Algorithm" could be used to tweak the parameters!

The hyperparameters I decided to use in the project are:
P = 0.2
I = 0.0
D = 7