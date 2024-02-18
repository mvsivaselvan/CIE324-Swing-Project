function cleanData = removespikes(spikesData)

% remove spikes from data; replace spikes with average of neighboring data
% points; intended to remove spikes from load cell data from HX711

[~,ind] = rmoutliers(spikesData);
ind = find(ind);
ind = ind(ind>1);
cleanData = spikesData;
%cleanData(ind) = (cleanData(ind-1)+cleanData(ind+1))/2;
if (~isempty(ind))
    cleanData(ind) = cleanData(ind-1);
end