% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 604.475420978447120 ; 603.449221726734210 ];

%-- Principal point:
cc = [ 330.749061564144540 ; 250.460182089916490 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.025628749370739 ; -0.090712419711026 ; 0.001064682153952 ; -0.001202427947731 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 2.795063958685557 ; 2.719349619178391 ];

%-- Principal point uncertainty:
cc_error = [ 1.420358510099936 ; 1.461661560817795 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.006041504015226 ; 0.024550693265915 ; 0.000600099400763 ; 0.000741685363487 ; 0.000000000000000 ];

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
omc_1 = [ 2.025692e+00 ; 2.101027e+00 ; -2.029811e-01 ];
Tc_1  = [ -9.465459e-01 ; -9.536165e-01 ; 4.068355e+00 ];
omc_error_1 = [ 1.940157e-03 ; 2.221538e-03 ; 3.920090e-03 ];
Tc_error_1  = [ 9.567112e-03 ; 9.723524e-03 ; 1.910831e-02 ];

%-- Image #2:
omc_2 = [ 2.031323e+00 ; 2.031636e+00 ; -2.148128e-01 ];
Tc_2  = [ -1.042367e+00 ; -9.203256e-01 ; 5.027726e+00 ];
omc_error_2 = [ 2.271110e-03 ; 2.564778e-03 ; 4.550099e-03 ];
Tc_error_2  = [ 1.181486e-02 ; 1.206263e-02 ; 2.362515e-02 ];

%-- Image #3:
omc_3 = [ 2.206044e+00 ; 2.083600e+00 ; -3.574914e-02 ];
Tc_3  = [ -1.927493e+00 ; -8.301167e-01 ; 4.762122e+00 ];
omc_error_3 = [ 2.599387e-03 ; 3.012325e-03 ; 5.942662e-03 ];
Tc_error_3  = [ 1.128916e-02 ; 1.170566e-02 ; 2.352431e-02 ];

%-- Image #4:
omc_4 = [ 2.175131e+00 ; 2.068267e+00 ; -1.280640e-01 ];
Tc_4  = [ -1.376042e+00 ; -8.384087e-01 ; 4.179081e+00 ];
omc_error_4 = [ 2.142737e-03 ; 2.339126e-03 ; 4.611343e-03 ];
Tc_error_4  = [ 9.862983e-03 ; 1.011040e-02 ; 2.014735e-02 ];

%-- Image #5:
omc_5 = [ -2.033975e+00 ; -2.042071e+00 ; 5.312638e-01 ];
Tc_5  = [ -7.728728e-01 ; -9.064148e-01 ; 4.570378e+00 ];
omc_error_5 = [ 2.128393e-03 ; 1.825618e-03 ; 4.325335e-03 ];
Tc_error_5  = [ 1.071601e-02 ; 1.093777e-02 ; 1.976866e-02 ];

%-- Image #6:
omc_6 = [ 2.149529e+00 ; 2.095053e+00 ; -7.033852e-02 ];
Tc_6  = [ -1.691473e+00 ; -8.834153e-01 ; 3.825700e+00 ];
omc_error_6 = [ 1.897435e-03 ; 2.281155e-03 ; 4.356927e-03 ];
Tc_error_6  = [ 9.087299e-03 ; 9.388626e-03 ; 1.906408e-02 ];

%-- Image #7:
omc_7 = [ 2.218017e+00 ; 2.154757e+00 ; -2.510660e-01 ];
Tc_7  = [ -1.275308e+00 ; -8.633265e-01 ; 3.494034e+00 ];
omc_error_7 = [ 1.590075e-03 ; 1.867282e-03 ; 3.878681e-03 ];
Tc_error_7  = [ 8.206282e-03 ; 8.425104e-03 ; 1.685920e-02 ];

%-- Image #8:
omc_8 = [ 2.175719e+00 ; 2.107523e+00 ; -2.237001e-01 ];
Tc_8  = [ -1.239853e+00 ; -8.586885e-01 ; 4.538311e+00 ];
omc_error_8 = [ 2.236060e-03 ; 2.441346e-03 ; 4.921571e-03 ];
Tc_error_8  = [ 1.065892e-02 ; 1.092030e-02 ; 2.157981e-02 ];

%-- Image #9:
omc_9 = [ 2.162139e+00 ; 2.118107e+00 ; -2.509059e-01 ];
Tc_9  = [ -1.268268e+00 ; -8.618768e-01 ; 5.252751e+00 ];
omc_error_9 = [ 2.614118e-03 ; 2.857429e-03 ; 5.756634e-03 ];
Tc_error_9  = [ 1.232670e-02 ; 1.264887e-02 ; 2.484178e-02 ];

%-- Image #10:
omc_10 = [ -2.083713e+00 ; -2.064681e+00 ; 5.946979e-01 ];
Tc_10  = [ -5.423423e-01 ; -8.327248e-01 ; 5.701954e+00 ];
omc_error_10 = [ 2.557047e-03 ; 2.250432e-03 ; 5.237475e-03 ];
Tc_error_10  = [ 1.340007e-02 ; 1.369974e-02 ; 2.458346e-02 ];

%-- Image #11:
omc_11 = [ 2.117013e+00 ; 1.998689e+00 ; 2.019709e-02 ];
Tc_11  = [ -2.020259e+00 ; -8.186759e-01 ; 4.685861e+00 ];
omc_error_11 = [ 2.612563e-03 ; 3.072747e-03 ; 5.533701e-03 ];
Tc_error_11  = [ 1.120030e-02 ; 1.154926e-02 ; 2.325944e-02 ];

%-- Image #12:
omc_12 = [ 2.100215e+00 ; 2.043383e+00 ; -1.115184e-03 ];
Tc_12  = [ -2.141958e+00 ; -8.217311e-01 ; 4.807196e+00 ];
omc_error_12 = [ 2.620849e-03 ; 3.223854e-03 ; 5.760905e-03 ];
Tc_error_12  = [ 1.147202e-02 ; 1.188018e-02 ; 2.397226e-02 ];

%-- Image #13:
omc_13 = [ 2.208720e+00 ; 2.141103e+00 ; -9.647463e-02 ];
Tc_13  = [ -1.215135e+00 ; -7.790708e-01 ; 4.033523e+00 ];
omc_error_13 = [ 2.222920e-03 ; 2.272515e-03 ; 4.756247e-03 ];
Tc_error_13  = [ 9.518835e-03 ; 9.775516e-03 ; 1.935431e-02 ];

%-- Image #14:
omc_14 = [ 2.214231e+00 ; 2.149976e+00 ; -9.221242e-02 ];
Tc_14  = [ -1.220490e+00 ; -7.768861e-01 ; 4.024329e+00 ];
omc_error_14 = [ 2.226585e-03 ; 2.270545e-03 ; 4.778437e-03 ];
Tc_error_14  = [ 9.497664e-03 ; 9.761274e-03 ; 1.932493e-02 ];

%-- Image #15:
omc_15 = [ 2.228242e+00 ; 2.148686e+00 ; -1.064872e-01 ];
Tc_15  = [ -1.237476e+00 ; -7.640923e-01 ; 4.023509e+00 ];
omc_error_15 = [ 2.211548e-03 ; 2.245624e-03 ; 4.767640e-03 ];
Tc_error_15  = [ 9.485753e-03 ; 9.757512e-03 ; 1.933236e-02 ];

%-- Image #16:
omc_16 = [ -2.194816e+00 ; -2.195395e+00 ; 2.741798e-01 ];
Tc_16  = [ -1.406219e+00 ; -8.076271e-01 ; 3.545251e+00 ];
omc_error_16 = [ 1.920074e-03 ; 1.605539e-03 ; 3.935268e-03 ];
Tc_error_16  = [ 8.289177e-03 ; 8.605780e-03 ; 1.710559e-02 ];

%-- Image #17:
omc_17 = [ -2.212354e+00 ; -2.172774e+00 ; 2.598875e-01 ];
Tc_17  = [ -1.418035e+00 ; -7.872115e-01 ; 3.524702e+00 ];
omc_error_17 = [ 1.919765e-03 ; 1.595176e-03 ; 3.923529e-03 ];
Tc_error_17  = [ 8.243066e-03 ; 8.562038e-03 ; 1.704041e-02 ];

%-- Image #18:
omc_18 = [ 2.239910e+00 ; 2.152105e+00 ; -2.229616e-01 ];
Tc_18  = [ -9.145310e-01 ; -7.567211e-01 ; 3.875904e+00 ];
omc_error_18 = [ 2.077769e-03 ; 2.005057e-03 ; 4.459055e-03 ];
Tc_error_18  = [ 9.105531e-03 ; 9.289177e-03 ; 1.826294e-02 ];

%-- Image #19:
omc_19 = [ -2.179479e+00 ; -2.204319e+00 ; 3.008313e-01 ];
Tc_19  = [ -8.425987e-01 ; -8.038347e-01 ; 4.523308e+00 ];
omc_error_19 = [ 2.339271e-03 ; 2.358681e-03 ; 5.274823e-03 ];
Tc_error_19  = [ 1.059224e-02 ; 1.082710e-02 ; 2.116958e-02 ];

%-- Image #20:
omc_20 = [ 2.188231e+00 ; 2.235219e+00 ; -2.858805e-01 ];
Tc_20  = [ -7.209841e-01 ; -8.014022e-01 ; 5.420377e+00 ];
omc_error_20 = [ 3.291867e-03 ; 3.134475e-03 ; 6.937252e-03 ];
Tc_error_20  = [ 1.271264e-02 ; 1.299690e-02 ; 2.548356e-02 ];

%-- Image #21:
omc_21 = [ 2.172318e+00 ; 2.198712e+00 ; -2.641364e-01 ];
Tc_21  = [ -7.235724e-01 ; -8.058585e-01 ; 5.856330e+00 ];
omc_error_21 = [ 3.622752e-03 ; 3.488152e-03 ; 7.570723e-03 ];
Tc_error_21  = [ 1.374504e-02 ; 1.405429e-02 ; 2.762973e-02 ];

%-- Image #22:
omc_22 = [ 2.001381e+00 ; 1.888291e+00 ; 2.862115e-01 ];
Tc_22  = [ -2.376947e+00 ; -7.634252e-01 ; 5.271135e+00 ];
omc_error_22 = [ 3.189328e-03 ; 3.603267e-03 ; 6.075445e-03 ];
Tc_error_22  = [ 1.296051e-02 ; 1.315222e-02 ; 2.695041e-02 ];

%-- Image #23:
omc_23 = [ 1.986458e+00 ; 1.958511e+00 ; 2.837304e-01 ];
Tc_23  = [ -2.124217e+00 ; -7.977676e-01 ; 4.583037e+00 ];
omc_error_23 = [ 2.856492e-03 ; 3.240084e-03 ; 5.389241e-03 ];
Tc_error_23  = [ 1.128606e-02 ; 1.145920e-02 ; 2.335657e-02 ];

%-- Image #24:
omc_24 = [ -1.882997e+00 ; -1.967993e+00 ; 4.881730e-01 ];
Tc_24  = [ -1.267459e-01 ; -7.621349e-01 ; 5.487747e+00 ];
omc_error_24 = [ 2.279880e-03 ; 2.502426e-03 ; 4.695590e-03 ];
Tc_error_24  = [ 1.290823e-02 ; 1.309305e-02 ; 2.349128e-02 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

