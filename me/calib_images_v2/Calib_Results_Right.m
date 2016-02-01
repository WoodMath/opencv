% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 602.560011661085130 ; 601.321624925053920 ];

%-- Principal point:
cc = [ 302.167364652795300 ; 296.873390034785420 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.032561963784326 ; -0.111447712715459 ; -0.001198524806076 ; -0.000883697354772 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 2.789769207302778 ; 2.775800231187169 ];

%-- Principal point uncertainty:
cc_error = [ 1.746446815487294 ; 1.200640431438152 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.005595646781630 ; 0.021007051590386 ; 0.000647184365043 ; 0.000745131503627 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 480;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 25;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.113371e+00 ; 2.237085e+00 ; -2.800432e-01 ];
Tc_1  = [ -8.973115e-01 ; -1.310317e+00 ; 4.101427e+00 ];
omc_error_1 = [ 1.753904e-03 ; 2.216164e-03 ; 4.208780e-03 ];
Tc_error_1  = [ 1.185436e-02 ; 8.119670e-03 ; 1.932751e-02 ];

%-- Image #2:
omc_2 = [ 2.119036e+00 ; 2.167699e+00 ; -2.935601e-01 ];
Tc_2  = [ -8.498864e-01 ; -1.358948e+00 ; 5.061074e+00 ];
omc_error_2 = [ 2.150075e-03 ; 2.587225e-03 ; 4.909772e-03 ];
Tc_error_2  = [ 1.464802e-02 ; 1.001823e-02 ; 2.377435e-02 ];

%-- Image #3:
omc_3 = [ -2.235225e+00 ; -2.127258e+00 ; 1.145534e-01 ];
Tc_3  = [ -1.763912e+00 ; -1.253788e+00 ; 4.935895e+00 ];
omc_error_3 = [ 2.909037e-03 ; 2.200683e-03 ; 5.594473e-03 ];
Tc_error_3  = [ 1.425451e-02 ; 1.004678e-02 ; 2.386940e-02 ];

%-- Image #4:
omc_4 = [ -2.240936e+00 ; -2.161410e+00 ; 2.139283e-01 ];
Tc_4  = [ -1.304178e+00 ; -1.208479e+00 ; 4.283466e+00 ];
omc_error_4 = [ 2.401128e-03 ; 1.844011e-03 ; 4.687226e-03 ];
Tc_error_4  = [ 1.235266e-02 ; 8.591421e-03 ; 2.050647e-02 ];

%-- Image #5:
omc_5 = [ -1.884115e+00 ; -1.947966e+00 ; 5.668369e-01 ];
Tc_5  = [ -6.501298e-01 ; -1.303181e+00 ; 4.574448e+00 ];
omc_error_5 = [ 2.314607e-03 ; 1.868268e-03 ; 3.600372e-03 ];
Tc_error_5  = [ 1.325547e-02 ; 9.105471e-03 ; 1.963381e-02 ];

%-- Image #6:
omc_6 = [ -2.220578e+00 ; -2.186708e+00 ; 1.487652e-01 ];
Tc_6  = [ -1.668950e+00 ; -1.225968e+00 ; 3.975946e+00 ];
omc_error_6 = [ 2.382856e-03 ; 1.734022e-03 ; 4.548214e-03 ];
Tc_error_6  = [ 1.151058e-02 ; 8.137937e-03 ; 1.962201e-02 ];

%-- Image #7:
omc_7 = [ -2.135269e+00 ; -2.111546e+00 ; 3.173289e-01 ];
Tc_7  = [ -1.306341e+00 ; -1.174089e+00 ; 3.590337e+00 ];
omc_error_7 = [ 2.099064e-03 ; 1.508187e-03 ; 3.737990e-03 ];
Tc_error_7  = [ 1.030764e-02 ; 7.234655e-03 ; 1.720524e-02 ];

%-- Image #8:
omc_8 = [ -2.184545e+00 ; -2.156121e+00 ; 3.020113e-01 ];
Tc_8  = [ -1.115726e+00 ; -1.257653e+00 ; 4.614687e+00 ];
omc_error_8 = [ 2.467489e-03 ; 1.950112e-03 ; 4.746811e-03 ];
Tc_error_8  = [ 1.328236e-02 ; 9.197573e-03 ; 2.179226e-02 ];

%-- Image #9:
omc_9 = [ -2.171770e+00 ; -2.168039e+00 ; 3.248381e-01 ];
Tc_9  = [ -1.036346e+00 ; -1.320029e+00 ; 5.321769e+00 ];
omc_error_9 = [ 2.802761e-03 ; 2.303062e-03 ; 5.458056e-03 ];
Tc_error_9  = [ 1.533950e-02 ; 1.059304e-02 ; 2.499752e-02 ];

%-- Image #10:
omc_10 = [ -1.927574e+00 ; -1.975933e+00 ; 6.267052e-01 ];
Tc_10  = [ -2.530569e-01 ; -1.323503e+00 ; 5.662743e+00 ];
omc_error_10 = [ 2.587620e-03 ; 2.140954e-03 ; 4.253232e-03 ];
Tc_error_10  = [ 1.645879e-02 ; 1.126520e-02 ; 2.442304e-02 ];

%-- Image #11:
omc_11 = [ 2.223744e+00 ; 2.115497e+00 ; -6.124899e-02 ];
Tc_11  = [ -1.866494e+00 ; -1.236489e+00 ; 4.876505e+00 ];
omc_error_11 = [ 2.420199e-03 ; 3.020352e-03 ; 5.831023e-03 ];
Tc_error_11  = [ 1.421307e-02 ; 9.948203e-03 ; 2.368582e-02 ];

%-- Image #12:
omc_12 = [ 2.204635e+00 ; 2.162224e+00 ; -7.720351e-02 ];
Tc_12  = [ -1.968592e+00 ; -1.250880e+00 ; 5.012595e+00 ];
omc_error_12 = [ 2.397960e-03 ; 3.111793e-03 ; 5.904928e-03 ];
Tc_error_12  = [ 1.457939e-02 ; 1.025846e-02 ; 2.440508e-02 ];

%-- Image #13:
omc_13 = [ -2.172047e+00 ; -2.128371e+00 ; 1.731402e-01 ];
Tc_13  = [ -1.165643e+00 ; -1.135857e+00 ; 4.123277e+00 ];
omc_error_13 = [ 2.285848e-03 ; 1.998027e-03 ; 4.519001e-03 ];
Tc_error_13  = [ 1.187025e-02 ; 8.262707e-03 ; 1.973628e-02 ];

%-- Image #14:
omc_14 = [ -2.164341e+00 ; -2.123672e+00 ; 1.689610e-01 ];
Tc_14  = [ -1.172137e+00 ; -1.133176e+00 ; 4.115869e+00 ];
omc_error_14 = [ 2.279614e-03 ; 2.006649e-03 ; 4.493108e-03 ];
Tc_error_14  = [ 1.184556e-02 ; 8.252304e-03 ; 1.971057e-02 ];

%-- Image #15:
omc_15 = [ -2.163751e+00 ; -2.108656e+00 ; 1.794674e-01 ];
Tc_15  = [ -1.189591e+00 ; -1.119814e+00 ; 4.114535e+00 ];
omc_error_15 = [ 2.269283e-03 ; 1.978788e-03 ; 4.429959e-03 ];
Tc_error_15  = [ 1.182676e-02 ; 8.250625e-03 ; 1.969830e-02 ];

%-- Image #16:
omc_16 = [ -2.057555e+00 ; -2.093790e+00 ; 3.252063e-01 ];
Tc_16  = [ -1.429016e+00 ; -1.123893e+00 ; 3.663005e+00 ];
omc_error_16 = [ 2.159083e-03 ; 1.668839e-03 ; 3.656284e-03 ];
Tc_error_16  = [ 1.049295e-02 ; 7.435537e-03 ; 1.745734e-02 ];

%-- Image #17:
omc_17 = [ -2.076100e+00 ; -2.072219e+00 ; 3.131823e-01 ];
Tc_17  = [ -1.443322e+00 ; -1.101735e+00 ; 3.645816e+00 ];
omc_error_17 = [ 2.156779e-03 ; 1.657606e-03 ; 3.656069e-03 ];
Tc_error_17  = [ 1.043741e-02 ; 7.403200e-03 ; 1.741619e-02 ];

%-- Image #18:
omc_18 = [ -2.142365e+00 ; -2.092910e+00 ; 2.903463e-01 ];
Tc_18  = [ -8.916713e-01 ; -1.096950e+00 ; 3.923321e+00 ];
omc_error_18 = [ 2.107106e-03 ; 1.828206e-03 ; 4.059480e-03 ];
Tc_error_18  = [ 1.127264e-02 ; 7.778808e-03 ; 1.852154e-02 ];

%-- Image #19:
omc_19 = [ -2.041745e+00 ; -2.105303e+00 ; 3.503132e-01 ];
Tc_19  = [ -7.246919e-01 ; -1.196920e+00 ; 4.545063e+00 ];
omc_error_19 = [ 2.319493e-03 ; 2.171130e-03 ; 4.491604e-03 ];
Tc_error_19  = [ 1.309165e-02 ; 9.001382e-03 ; 2.116328e-02 ];

%-- Image #20:
omc_20 = [ -2.052115e+00 ; -2.137318e+00 ; 3.368622e-01 ];
Tc_20  = [ -4.705487e-01 ; -1.268423e+00 ; 5.412905e+00 ];
omc_error_20 = [ 2.849302e-03 ; 2.888661e-03 ; 5.961460e-03 ];
Tc_error_20  = [ 1.567826e-02 ; 1.071525e-02 ; 2.538335e-02 ];

%-- Image #21:
omc_21 = [ -2.090433e+00 ; -2.155738e+00 ; 3.223274e-01 ];
Tc_21  = [ -4.087401e-01 ; -1.309259e+00 ; 5.843101e+00 ];
omc_error_21 = [ 3.223310e-03 ; 3.247465e-03 ; 6.872453e-03 ];
Tc_error_21  = [ 1.695471e-02 ; 1.156729e-02 ; 2.755029e-02 ];

%-- Image #22:
omc_22 = [ 2.128429e+00 ; 2.001717e+00 ; 2.207731e-01 ];
Tc_22  = [ -2.132139e+00 ; -1.234550e+00 ; 5.513017e+00 ];
omc_error_22 = [ 3.443174e-03 ; 4.259588e-03 ; 7.920660e-03 ];
Tc_error_22  = [ 1.635121e-02 ; 1.136324e-02 ; 2.718163e-02 ];

%-- Image #23:
omc_23 = [ 2.113525e+00 ; 2.073231e+00 ; 2.227474e-01 ];
Tc_23  = [ -1.985917e+00 ; -1.207725e+00 ; 4.795421e+00 ];
omc_error_23 = [ 3.000379e-03 ; 3.786123e-03 ; 6.904773e-03 ];
Tc_error_23  = [ 1.430824e-02 ; 9.943178e-03 ; 2.361057e-02 ];

%-- Image #24:
omc_24 = [ -1.737406e+00 ; -1.863682e+00 ; 5.211822e-01 ];
Tc_24  = [ 1.275720e-01 ; -1.228739e+00 ; 5.397612e+00 ];
omc_error_24 = [ 2.284437e-03 ; 2.395754e-03 ; 3.752143e-03 ];
Tc_error_24  = [ 1.574003e-02 ; 1.070848e-02 ; 2.313147e-02 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

