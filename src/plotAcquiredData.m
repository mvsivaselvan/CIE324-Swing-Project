function plotAcquiredData(~, ~, arduino, axisHandle)

%fprintf('Got it!!\n');

plot(axisHandle, arduino.UserData.Data(:,1:2))

end