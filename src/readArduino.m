function readArduino(src, ~, app)

% Read the ASCII data from the serialport object.
data = readline(src);

% Convert the string data to numeric type and save it in the UserData
% property of the serialport object.
src.UserData.Data(end+1,:) = str2num(data); %#ok<ST2NM>

% Update the Count value of the serialport object.
src.UserData.Count = src.UserData.Count + 1;

% Notify everytime a block of data has been acquired
if (mod(src.UserData.Count, app.plotBlockSize) == 0)
    notify(app, 'AcquiredDataBlock');
end

end