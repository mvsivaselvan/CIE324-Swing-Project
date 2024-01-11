% Follows example in 
% https://www.mathworks.com/help/instrument/read-streaming-data-from-arduino.html
serialportlist("available")

numSamples = 100;

myArduino = serialport("COM5",57600);

configureTerminator(myArduino,"CR/LF");

myArduino.UserData = struct("Data",[],"Count",0);

configureCallback(myArduino,"terminator",...
                 @(src,evt)(readArduino(src,evt,numSamples)));

waitfor(myArduino, "BytesAvailableFcnMode", "off");

% Wait for acquistion to complete
% while (true)
%     % problem with putting this in the while clause is it uses the value at
%     % the time the look starts
%     n = myArduino.UserData.Count;
%     if (n > numSamples) 
%         break
%     else
%         fprintf('%s\n',myArduino.BytesAvailableFcnMode);
%     end
% end
% pause(numSamples*0.1+5);

acquiredData = myArduino.UserData.Data;
myArduino.delete