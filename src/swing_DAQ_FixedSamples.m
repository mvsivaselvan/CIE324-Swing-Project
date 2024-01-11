% Follows example in 
% https://www.mathworks.com/help/instrument/read-streaming-data-from-arduino.html
serialportlist("available")

numSamples = 100;

myArduino = serialport("COM5",57600);

configureTerminator(myArduino,"CR/LF");

myArduino.UserData = struct("Data",[],"Count",0);

configureCallback(myArduino,"terminator",...
                 @(src,evt)(readArduinoFixedSamples(src,evt,numSamples)));

waitfor(myArduino, "BytesAvailableFcnMode", "off");

acquiredData = myArduino.UserData.Data;
myArduino.delete

figure, plot(acquiredData)