function plotAcquiredData(src, ~, arduino, axisHandle)

% src is the app object

%fprintf('Got it!!\n');

chanToPlot = src.getChannelsToPlot();

if any(chanToPlot)
    plot(axisHandle, arduino.UserData.Data(:,chanToPlot))
end

end