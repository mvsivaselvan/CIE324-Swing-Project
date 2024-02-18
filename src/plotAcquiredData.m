function plotAcquiredData(src, ~, arduino, axisHandle)

% src is the app object

%fprintf('Got it!!\n');

chanToPlot = src.getChannelsToPlot();

processedData = arduino.UserData.Data;
% clean up spikes and calibrate load cell channels
for n = 11:16 % columns of the loadcell channels
    processedData(:,n) = removespikes(processedData(:,n))/1000;
end

if any(chanToPlot)
    plot(axisHandle, processedData(:,chanToPlot))
end

end