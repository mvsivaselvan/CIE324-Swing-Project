%% Load cell calibration

% For setup, see image LoadCellCalibrationSetup.jpg. Two load cells are
% hung in series and weights are applied (then eventually removed) at
% 10-lb increments.

% THIS DATA IS FROM THE SETUP IN SEESL WITH THE BREADBOARD DAQ
% % load acquiredData; acquiredData has 5 columns. The first 3 are
% % accelerations, and can be ignored. The last 2 channels are the load cells
% load loadCellCalData.mat
% 
% % Also remove offsets
% loadCellDat = acquiredData(:,4:5) - acquiredData(1,4:5);

% THIS DATA IS FROM THE SETUP IN KETTER 133A WITH THE FINALIZED DAQ
% Data acquired through CoolTerm
% There are 16 columns: time, 9 IMU channels, 6 load cell channels
% Load the first two load cell channels to which the calibration load cells
% are connected
load LoadCellCalibrationData.txt;

% Also remove offsets
loadCellDat = LoadCellCalibrationData(:,11:12) ...
                   - LoadCellCalibrationData(1,11:12);

figure(101), 
    plot(loadCellDat),
    grid on
% The two lines overlap, indicating that the calibration factor is the same
% for both load cells tested

% Now plot 10-lb grid lines (using a calibration factor 1lb/1000units)
figure(101), hold on
x = (0:length(loadCellDat)-1);
plot(x, ones(length(x),1)*[0 1 2 3 4]*10000,'k--');
hold off