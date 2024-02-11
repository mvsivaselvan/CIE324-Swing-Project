%% Load data
load BNO055data.txt;
BNO055data = array2table(BNO055data, ...
                         'VariableNames', ...
                         {'millis', 'accelX', 'accelY', 'accelZ', ...
                                    'omegaX', 'omegaY', 'omegaZ', ...
                                    'orientX', 'orientY', 'orientZ'});
tBNO055 = (BNO055data.millis - BNO055data.millis(1))/1000;

load iphonedata.mat;
tIphone = second(Acceleration.Timestamp, 'secondofday');
tIphone = tIphone - tIphone(1);
toffset = 3.565;

%% Plot
figure(101), 
    plot(tBNO055, BNO055data.accelZ, tIphone+toffset, Acceleration.Z);
    title('Z acceleration'),
    xlabel('time (s)')
    ylabel('accleration (m/s^2)')

figure(102), % NOTE: in iphone, Y orientation shows up as Z
    plot(tBNO055, BNO055data.orientY, tIphone+toffset, Orientation.Z);
    title('Y Orientation'),
    xlabel('time (s)')
    ylabel('orientation (degrees)')

figure(103), % NOTE: BNO055 angular velocity is in deg/s and has a - sign
    plot(tBNO055, -BNO055data.omegaY*pi/180, ...
         tIphone+toffset, AngularVelocity.Y);
    title('Y angular velocity'),
    xlabel('time (s)')
    ylabel('angular velocity (rad/s)')
    
